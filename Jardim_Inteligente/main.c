#include <atmel_start.h>
#include "logic_functions.h"
#include <util/delay.h>
#include "adc_basic.h"

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	sei();
	
	atmel_start_init();

	/* Replace with your application code */
	iniciar_sistema();
	while (1) {
		atualizar_tela();
	}
}
