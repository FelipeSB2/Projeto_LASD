/*
 * logic_functions.c
 *
 * Created: 03/12/2020 14:32:38
 *  Author: savio
 */ 

#include "logic_functions.h"
#include "nokia5110.h"
#include "adc_basic.h"
#define F_CPU 16000000
#include <util/delay.h>

struct Tela TELA;
struct Edicao edicao;
struct Status_atuadores status;
struct Temp_interrupcao temp_interrupcao;
struct Medicao_ADC medicao_ADC;
struct Config_intervalo_aceitavel config_intervalo_aceitavel;
struct Faixa_de_operacao faixa_de_operacao;
struct Temp_variaveis temp;
struct Historico_da_porta historico_da_porta;
struct Valores_atuais valores_atuais;

// fim_pagina
// Função auxiliar para o display
void fim_pagina(){
	nokia_lcd_set_cursor(0, 40);
	//snprintf(buf, 15, "          %d/%d", (int) TELA.pagina_atual, (int) TELA.pagina_total);
	snprintf(temp.buf, tam_vetor, "    pagina %d/%d",
	(int) TELA.pagina_atual, (int) TELA.pagina_total);
	//int2string(TELA.pagina_atual, temp_string);
	nokia_lcd_write_string(temp.buf, 1);
	nokia_lcd_render(); //Atualiza a tela do display com o conteúdo do buffer
}

// valor_medido
// converte os digitos da leitura analógica no valor da grandeza medida pelo sensor
float valor_medido(float medicao, struct Range range){
	return (medicao/1023.0) * (range.max - range.min) + range.min;
}

// mostrar_dados_sensores
// Mostrar dados medidos dos sensores | TELA 1, 2 e 3
void mostrar_dados_sensores(uint8_t conjunto){
	switch(conjunto){
		case 1:
		temp.temperatura = valores_atuais.temperatura;
		temp.umidade = valores_atuais.umidade;
		temp.radiacao_solar = valores_atuais.radiacao_solar;
		
		snprintf(temp.buf, tam_vetor, "Dados medidos");
		break;
		
		case 2:
		temp.temperatura = config_intervalo_aceitavel.temperatura.min;
		temp.umidade = config_intervalo_aceitavel.umidade.min;
		temp.radiacao_solar = config_intervalo_aceitavel.radiacao_solar.min;
		snprintf(temp.buf, tam_vetor, "Config min");
		break;
		
		case 3:
		temp.temperatura = config_intervalo_aceitavel.temperatura.max;
		temp.umidade = config_intervalo_aceitavel.umidade.max;
		temp.radiacao_solar = config_intervalo_aceitavel.radiacao_solar.max;
		snprintf(temp.buf, tam_vetor, "Config max");
		break;
		default:
		break;
	}
	nokia_lcd_clear(); //Limpa o LCD
	nokia_lcd_write_string(temp.buf,1);
	nokia_lcd_set_cursor(0, 10);

	// Temperatura
	nokia_lcd_write_string("Temp: ", 1);
	snprintf(temp.buf, tam_vetor, "%d,%d C", (int)(temp.temperatura),
	(int)(temp.temperatura - ((int)temp.temperatura) ) * 100);
	nokia_lcd_write_string(temp.buf,1); //Escreve a leitura no buffer do LCD
	nokia_lcd_set_cursor(0, 20);

	// Umidade
	nokia_lcd_write_string("Umid: ", 1);
	snprintf(temp.buf, tam_vetor, "%d,%d %%", (int)(temp.umidade),
	(int)(temp.umidade - ((int)temp.umidade) ) * 100);
	nokia_lcd_write_string(temp.buf,1); //Escreve a leitura no buffer do LCD
	nokia_lcd_set_cursor(0, 30);

	// Radiação solar
	nokia_lcd_write_string("Rads: ", 1);
	snprintf(temp.buf, tam_vetor, "%d W/ft2", (int)(temp.radiacao_solar));
	nokia_lcd_write_string(temp.buf,1); //Escreve a leitura no buffer do LCD
	nokia_lcd_set_cursor(0, 40);
	fim_pagina();
}

// mostrar_status_atuadores
// Mostrar status dos atuadores | TELA 4
void mostrar_status_atuadores(){
	nokia_lcd_clear(); //Limpa o LCD
	
	nokia_lcd_write_string("Status atuador", 1);
	nokia_lcd_set_cursor(0, 10);
	
	// Bombda dagua
	nokia_lcd_write_string("Agua: ", 1);
	if(status.bombda_dagua == 1){
		snprintf(temp.buf, tam_vetor, "ON");
		}else{
		snprintf(temp.buf, tam_vetor, "OFF");
	}
	nokia_lcd_write_string(temp.buf, 1);
	nokia_lcd_set_cursor(0, 20);
	
	// Ar condicionado
	nokia_lcd_write_string("Ar: ", 1);
	if(status.ar_condicionado == 1){
		snprintf(temp.buf, tam_vetor, "ON");
		}else{
		snprintf(temp.buf, tam_vetor, "OFF");
	}
	nokia_lcd_write_string(temp.buf, 1);
	nokia_lcd_set_cursor(0, 30);
	
	// Bombda dagua
	nokia_lcd_write_string("LED: ", 1);
	if(status.LED == 1){
		snprintf(temp.buf, tam_vetor, "ON");
		}else{
		snprintf(temp.buf, tam_vetor, "OFF");
	}
	nokia_lcd_write_string(temp.buf, 1);
	nokia_lcd_set_cursor(0, 40);
	
	// Bombda dagua
	nokia_lcd_write_string("Teto: ", 1);
	if(status.motor_teto == 1){
		snprintf(temp.buf, tam_vetor, "ON");
		}else{
		snprintf(temp.buf, tam_vetor, "OFF");
	}
	nokia_lcd_write_string(temp.buf, 1);

	nokia_lcd_render();
}

// editar_valor
// Configurar dados de range
void editar_valor(){
	TELA.pagina_atual = 5;
	
	if (edicao.esta_editando_umidade == 1){
		snprintf(temp.buf2, tam_vetor, "Umidade");
		
		// Definição do range
		if (edicao.tela_antiga == 2) // min
		{
			temp.range.min = faixa_de_operacao.umidade.min;
			temp.range.max = config_intervalo_aceitavel.umidade.max;
			}else{
			temp.range.min = config_intervalo_aceitavel.umidade.min;
			temp.range.max = faixa_de_operacao.umidade.max;
		}
		
		// Valor medido
		edicao.valor = valor_medido(medicao_ADC.entrada_usuario.potenciometro,
		temp.range);
		snprintf(temp.buf, tam_vetor, "%d,%d %%", (int)(edicao.valor),
		(int)(edicao.valor - ((int)edicao.valor) ) * 100);
		}else if (edicao.esta_editando_temperatura == 1){
		snprintf(temp.buf2, tam_vetor, "Temperatura");
		
		// Definição do range
		if (edicao.tela_antiga == 2) // min
		{
			temp.range.min = faixa_de_operacao.temperatura.min;
			temp.range.max = config_intervalo_aceitavel.temperatura.max;
			}else{
			temp.range.min = config_intervalo_aceitavel.temperatura.min;
			temp.range.max = faixa_de_operacao.temperatura.max;
		}
		
		// Valor medido
		edicao.valor = valor_medido(medicao_ADC.entrada_usuario.potenciometro,
		temp.range);
		snprintf(temp.buf, tam_vetor, "%d,%d C", (int)(edicao.valor),
		(int)(edicao.valor - ((int)edicao.valor) ) * 100);
		}else{
		snprintf(temp.buf2, tam_vetor, "Radiacao Solar");
		
		// Definição do range
		if (edicao.tela_antiga == 2) // min
		{
			temp.range.min = faixa_de_operacao.radiacao_solar.min;
			temp.range.max = config_intervalo_aceitavel.radiacao_solar.max;
			}else{
			temp.range.min = config_intervalo_aceitavel.radiacao_solar.min;
			temp.range.max = faixa_de_operacao.radiacao_solar.max;
		}
		
		// Valor medido
		edicao.valor = valor_medido(medicao_ADC.entrada_usuario.potenciometro,
		temp.range);
		snprintf(temp.buf, tam_vetor, "%d W/ft2", (int)(edicao.valor));
	}
	
	nokia_lcd_clear(); //Limpa o LCD
	
	nokia_lcd_write_string("Modo de Edicao", 1);
	nokia_lcd_set_cursor(0, 10);
	nokia_lcd_write_string(temp.buf2, 1);
	nokia_lcd_set_cursor(0, 30);
	nokia_lcd_write_string("Valor: ", 1);
	nokia_lcd_write_string(temp.buf, 1);
	nokia_lcd_render();
}

// salvar_valor
// Atualiza os dados de configuração da faixa de operação do sistema do usuário
void salvar_valor(){
	TELA.pagina_atual = edicao.tela_antiga;
	
	if (edicao.esta_editando_umidade == 1){
		if (edicao.tela_antiga == 2) // min
		{
			config_intervalo_aceitavel.umidade.min = edicao.valor;
			}else{
			config_intervalo_aceitavel.umidade.max = edicao.valor;
		}
		}else if (edicao.esta_editando_temperatura == 1){
		if (edicao.tela_antiga == 2) // min
		{
			config_intervalo_aceitavel.temperatura.min = edicao.valor;
			}else{
			config_intervalo_aceitavel.temperatura.max = edicao.valor;
		}
		}else{
		if (edicao.tela_antiga == 2) // min
		{
			config_intervalo_aceitavel.radiacao_solar.min = edicao.valor;
			}else{
			config_intervalo_aceitavel.radiacao_solar.max = edicao.valor;
		}
	}
	reset_edicao();
}

// atualizar_tela
// Atualiza a tela
void atualizar_tela(){
	valores_atuais.temperatura = valor_medido(medicao_ADC.sensor.temperatura,
	                                          faixa_de_operacao.temperatura);
	valores_atuais.umidade = valor_medido(medicao_ADC.sensor.umidade,
										  faixa_de_operacao.umidade);
	valores_atuais.radiacao_solar = valor_medido(medicao_ADC.sensor.radiacao_solar,
												 faixa_de_operacao.radiacao_solar);
	
	controle_ar_condicionado();
	controle_motor_bomba_dagua();
	controle_motor_teto();
	
	switch(TELA.pagina_atual){
		case 1:
		mostrar_dados_sensores(1); // Valores medidos
		break;
		
		case 2:
		mostrar_dados_sensores(2); // Valores mínimos aceitáveis
		break;
		
		case 3:
		mostrar_dados_sensores(3); // Valores máximos aceitáveis
		break;
		
		case 4:
		mostrar_status_atuadores(); // Status dos atuadores
		break;
		
		case 5:
		editar_valor(); // Editar intervalo aceitável
		break;
		
		default:
		break;
	}
	_delay_ms(80);
}

// mudar_tela
// Troca de página
void mudar_tela(){
	TELA.pagina_atual += 1;
	if(TELA.pagina_atual > TELA.pagina_total)
	TELA.pagina_atual = 1;
	atualizar_tela();
}

// Funções para iniciar as estruturas de dados
void reset_edicao(){
	edicao.esta_editando = 0;
	edicao.esta_editando_temperatura = 0;
	edicao.esta_editando_umidade = 0;
	edicao.esta_editando_radiacao_solar = 0;
	edicao.tela_antiga = 1;
	edicao.valor = 0;
}

void reset_medicao_ADC(){
	medicao_ADC.entrada_usuario.potenciometro = 0;
	medicao_ADC.sensor.temperatura = 0;
	medicao_ADC.sensor.umidade = 0;
	medicao_ADC.sensor.radiacao_solar = 0;
}

void reset_valores_atuais(){
	valores_atuais.temperatura = 0;
	valores_atuais.umidade = 0;
	valores_atuais.radiacao_solar = 0;
}

void reset_config_intervalo_aceitavel(){
	config_intervalo_aceitavel.temperatura.min = 25.0;
	config_intervalo_aceitavel.temperatura.max = 40.0;

	config_intervalo_aceitavel.umidade.min = 50.0;
	config_intervalo_aceitavel.umidade.max = 80.0;

	config_intervalo_aceitavel.radiacao_solar.min = 30.0;
	config_intervalo_aceitavel.radiacao_solar.max = 80.0;
}

void reset_faixa_de_operacao(){
	faixa_de_operacao.temperatura.min = -20.0;
	faixa_de_operacao.temperatura.max = 80.0;

	faixa_de_operacao.umidade.min = 0.0;
	faixa_de_operacao.umidade.max = 100.0;

	faixa_de_operacao.radiacao_solar.min = 0.0;
	faixa_de_operacao.radiacao_solar.max = 100.0;
}

void reset_status_dos_atuadores(){
	status.bombda_dagua = 0;
	status.ar_condicionado = 0;
	status.LED = 0;
	status.motor_teto = 0;
}

void reset_flags_das_interrupcoes(){
	temp_interrupcao.b6 = 0;
	temp_interrupcao.d2 = 0;
	temp_interrupcao.d3 = 0;
	temp_interrupcao.d4 = 0;
}

void reset_historico_de_portas(){
	historico_da_porta.D = 0xFF;
	historico_da_porta.B = 0xFF;
}

void reset_LCD(){
	nokia_lcd_init();
	TELA.pagina_atual = 1;
	TELA.pagina_total = TOTAL_PAGINAS;
}

//inicializar gerador de PWM

void inicializar_PWM(){
	DDRD |= (1<<PD5) | (1<<PD6);
	PORTB &= 0x97; //Zera o estado das portas D5 e D6, e mantém o estado original das demais
	
	TCCR0A = (1<<COM0A1) | (1<<COM0B1) | (1<<WGM01) | (1<<WGM00); //Modo não invertido para A e B.
	TCCR0B = (1<<CS02); //Pre-escale de ~244hz
	
	//OCR0A = 0; //D6
	//OCR0B = 0; //D5
}


void iniciar_sistema(){
	ADC_0_start_conversion(0);
	reset_medicao_ADC();                // Iniciar estrutura de dados medicao_ADC
	reset_valores_atuais();             // Iniciar estrutura de dados valores atuais
	reset_config_intervalo_aceitavel(); // Iniciar estrutura de dados Config_intervalo_aceitavel
	reset_faixa_de_operacao();          // Iniciar estrutura de dados Faixa_de_operacao
	reset_status_dos_atuadores();       // Iniciar estrutura de dados status dos atuadores
	reset_flags_das_interrupcoes();     // Iniciar estrutura de dados flags das interrupcoes
	reset_edicao();                     // Iniciar estrutura de dados flags da edição
	reset_historico_de_portas();        // Iniciar estrutura de dados Historico das portas
	reset_LCD();                        // Iniciar estrutura de dados TELA
	//inicializar_PWM();
}



//Controle de saídas
void controle_ar_condicionado(){
	if(valores_atuais.temperatura >= config_intervalo_aceitavel.temperatura.max && status.ar_condicionado==0){
		status.ar_condicionado = 1;
		PORTB |= 1;
	}
	else if(valores_atuais.temperatura < config_intervalo_aceitavel.temperatura.min && status.ar_condicionado==1){
		status.ar_condicionado = 0;
		PORTB |= 0xFE;
	}
}



void controle_motor_teto(){
	//Fechar teto
	if(valores_atuais.radiacao_solar >= config_intervalo_aceitavel.radiacao_solar.max && status.motor_teto==1){
		status.motor_teto=1; //Teto fechado
		PORTC |= 0b1000000; //LED/Comando
		_delay_ms(20);//2 segundos fechando
		PORTC &= ~(0b1000000); //Desativa o motor
	}
	//Abrir teto
	if(valores_atuais.radiacao_solar >= config_intervalo_aceitavel.radiacao_solar.max && status.motor_teto==1){
		status.motor_teto=0; //Teto aberto
		PORTC |= 0b1000000; //LED/Comando
		_delay_ms(20);//2 segundos fechando
		PORTC &= ~(0b1000000); //Desativa o motor
	}
	
}


void controle_motor_bomba_dagua(){
	//ativar motor
	if(valores_atuais.umidade <= config_intervalo_aceitavel.umidade.min && status.bombda_dagua==0){
		status.bombda_dagua=1; //Liga a bomba dagua
		PORTC |= 0b0100000; //LED/Comando C5
		_delay_ms(20);//2 segundos fechando
		PORTC &= ~(0b0100000);   //LED/Comando C5 bomba dágua
	}
	
	//Desativar motor
	if(valores_atuais.umidade >= config_intervalo_aceitavel.umidade.max && status.bombda_dagua==1){
		status.bombda_dagua=0; //Liga a bomba dagua
		PORTC |= 0b0100000; //LED/Comando C5
		_delay_ms(20);//2 segundos fechando
		PORTC &= ~(0b0100000);   //LED/Comando C5 bomba dágua
	}	
}


