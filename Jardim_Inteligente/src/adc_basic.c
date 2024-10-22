/**
 * \file
 *
 * \brief ADC Basic driver implementation.
 *
 (c) 2020 Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms,you may use this software and
    any derivatives exclusively with Microchip products.It is your responsibility
    to comply with third party license terms applicable to your use of third party
    software (including open source software) that may accompany Microchip software.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 */

/**
 * \defgroup doc_driver_adc_basic ADC Basic Driver
 * \ingroup doc_driver_adc
 *
 * \section doc_driver_adc_rev Revision History
 * - v0.0.0.1 Initial Commit
 *
 *@{
 */
#include <adc_basic.h>
#include "logic_functions.h"

/** Function pointer to callback function called by IRQ.
    NULL=default value: No callback function is to be used.
*/

adc_irq_cb_t ADC_0_cb = NULL; /**
                               * \brief Initialize ADC interface
                               * If module is configured to disabled state, the clock to the ADC is disabled
                               * if this is supported by the device's clock system.
                               *
                               * \return Initialization status.
                               * \retval 0 the ADC init was successful
                               * \retval 1 the ADC init was not successful
                               */
int8_t ADC_0_init()
{

	/* Enable clock to write ADC registers */
	PRR &= ~(1 << PRADC);

	ADMUX = (0x01 << REFS0)   /* AVCC with external capacitor at AREF pin */
	        | (0 << ADLAR)    /* Left Adjust Result: disabled */
	        | (0x00 << MUX0); /* ADC Single Ended Input pin 0 */

	ADCSRA = (1 << ADEN)        /* ADC: enabled */
	         | (0 << ADATE)     /* Auto Trigger: disabled */
	         | (1 << ADIE)      /* ADC Interrupt: enabled */
	         | (0x04 << ADPS0); /* 16 */
	ADCSRB = (0x00 << ADTS0)    /* Free Running mode */
	         | (0 << ACME)      /* Analog Comparator Multiplexer: disabled */
	    ;

	DIDR0 = 1 << ADC0D    /* Disable digital input buffer for ADC0 */
	        | 1 << ADC1D  /* Disable digital input buffer for ADC1 */
	        | 1 << ADC2D  /* Disable digital input buffer for ADC2 */
	        | 1 << ADC3D; /* Disable digital input buffer for ADC3 */

	return 0;
}

/**
 * \brief Enable ADC_0
 * 1. If supported by the clock system, enables the clock to the ADC
 * 2. Enables the ADC module by setting the enable-bit in the ADC control register
 *
 * \return Nothing
 */
void ADC_0_enable()
{
	ADCSRA |= (1 << ADEN);
}
/**
 * \brief Disable ADC_0
 * 1. Disables the ADC module by clearing the enable-bit in the ADC control register
 * 2. If supported by the clock system, disables the clock to the ADC
 *
 * \return Nothing
 */
void ADC_0_disable()
{
	ADCSRA &= ~(1 << ADEN);
}

/**
 * \brief Start a conversion on ADC_0
 *
 * \param[in] channel The ADC channel to start conversion on
 *
 * \return Nothing
 */
void ADC_0_start_conversion(adc_0_channel_t channel)
{
	ADMUX &= ~0x0f;
	ADMUX |= channel;
	ADCSRA |= (1 << ADSC);
}

/**
 * \brief Check if the ADC conversion is done
 *
 * \return The status of ADC converison done check
 * \retval true The ADC conversion is done
 * \retval false The ADC converison is not done
 */
bool ADC_0_is_conversion_done()
{
	return ((ADCSRA & (1 << ADIF)));
}

/**
 * \brief Read a conversion result from ADC_0
 *
 * \return Conversion result read from the ADC_0 ADC module
 */
adc_result_t ADC_0_get_conversion_result(void)
{
	return (ADCL | ADCH << 8);
}

/**
 * \brief Start a conversion, wait until ready, and return the conversion result
 *
 * \return Conversion result read from the ADC_0 ADC module
 */
adc_result_t ADC_0_get_conversion(adc_0_channel_t channel)
{
	adc_result_t res;

	ADC_0_start_conversion(channel);
	while (!ADC_0_is_conversion_done())
		;
	res = ADC_0_get_conversion_result();
	ADCSRA |= (1 << ADIF);
	return res;
}

/**
 * \brief Return the number of bits in the ADC conversion result
 *
 * \return The number of bits in the ADC conversion result
 */
uint8_t ADC_0_get_resolution()
{
	return 10;
}

/**
 * \brief Register a callback function to be called at the end of the ADC ISR.
 *
 * \param[in] f Pointer to function to be called
 *
 * \return Nothing.
 */
void ADC_0_register_callback(adc_irq_cb_t f)
{
	ADC_0_cb = f;
}

ISR(ADC_vect)
{
	uint8_t theLow = ADCL;
	uint16_t theTenBitResult = ADCH<<8 | theLow;
	uint8_t admux_4bits = ADMUX & 0x0F;

	switch (admux_4bits)
	{
		//====================
		// Entrada do usu�rio
		//====================

		case 0:
		medicao_ADC.entrada_usuario.potenciometro = theTenBitResult;
		ADMUX &= 0xF0;
		ADMUX |= 0x01;
		break;

		//====================
		// Sensores
		//====================

		// Sensor de temperatura
		case 1:
		medicao_ADC.sensor.temperatura = theTenBitResult;
		ADMUX &= 0xF0;
		ADMUX |= 0x02;
		break;

		// Sensor de umidade
		case 2:
		medicao_ADC.sensor.umidade = theTenBitResult;
		ADMUX &= 0xF0;
		ADMUX |= 0x03;
		break;

		// Sensor de radia��o solar
		case 3:
		medicao_ADC.sensor.radiacao_solar = theTenBitResult;
		ADMUX &= 0xF0;
		ADMUX |= 0x00;
		break;
		default:
		//Default code
		break;
	} ADCSRA |= 1<<ADSC;
}
