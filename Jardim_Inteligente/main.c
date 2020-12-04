#include <atmel_start.h>
#include "logic_functions.h"

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	/* Replace with your application code */
	iniciar_sistema();
	while (1) {
		atualizar_tela();
	}
}
