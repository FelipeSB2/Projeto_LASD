/**
 * \file
 *
 * \brief USART related functionality implementation.
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
 */

/**
 * \addtogroup doc_driver_exint
 *
 * \section doc_driver_exint_rev Revision History
 * - v0.0.0.1 Initial Commit
 *
 *@{
 */
#include <exint.h>

/**
 * \brief Initialize EXTERNAL_IRQ_0 interface
 *
 * \return Initialization status.
 */
int8_t EXTERNAL_IRQ_0_init()
{

	PCICR = (1 << PCIE0) | // Enable pin change interrupt 0
	        (1 << PCIE2) | // Enable pin change interrupt 2
	        (1 << PCIE2) | // Enable pin change interrupt 2
	        (1 << PCIE2);  // Enable pin change interrupt 2

	PCMSK2 = (1 << PCINT18) | // Pin change enable mask 18
	         (1 << PCINT19) | // Pin change enable mask 19
	         (1 << PCINT20);  // Pin change enable mask 20

	PCMSK0 = (1 << PCINT6); // Pin change enable mask 6

	return 0;
}
