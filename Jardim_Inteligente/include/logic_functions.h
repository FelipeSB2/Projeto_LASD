/*
 * logic_functions.h
 *
 * Created: 03/12/2020 14:31:25
 *  Author: savio
 */ 

#ifndef LOGIC_FUNCTIONS_H_
#define LOGIC_FUNCTIONS_H_

#include <stdint.h>
#include <stdio.h>
#include "nokia5110.h"

// <h> Configura��o do total de p�ginas
// <i> Isso define o total de p�ginas a serem mostradas
#define TOTAL_PAGINAS 4

// </h>

// <h> Configura��o do tamanho do buffer
// <i> Isso define o n�mero de caracteres do buffer
#define tam_vetor 15

// </h>

// <<< end of configuration section >>>

/*
 * Estruturas de dados para l�gica do programa
 */

// Tela
// Para armazenar a p�gina atual e o n�mero total de p�ginas
struct Tela{
	uint8_t pagina_atual;
	uint8_t pagina_total;
};

// Edicao
// Para armazenar vari�veis para configura��o de valores pelo usu�rio
struct Edicao{
	uint8_t esta_editando;
	uint8_t esta_editando_temperatura;
	uint8_t esta_editando_umidade;
	uint8_t esta_editando_radiacao_solar;
	uint8_t tela_antiga;
	float valor;
};

// Status_atuadores
// Para armazenar o status atual dos atuadores
struct Status_atuadores{
	uint8_t bombda_dagua;
	uint8_t ar_condicionado;
	uint8_t LED;
	uint8_t motor_teto;
};

// Temp_interrupcao
// Para armazenar o status de interrup��es por bot�es
struct Temp_interrupcao{
	uint8_t d2;
	uint8_t d3;
	uint8_t d4;
	uint8_t b6;
};

// Sensor
// Para armazenar dados de leitura dos sensores
struct Sensor{
	uint16_t temperatura;
	uint16_t umidade;
	uint16_t radiacao_solar;
};

// Entrada_usuario
// Para armazenar dados de leitura do potenci�metro do usu�rio
struct Entrada_usuario{
	uint16_t potenciometro;
};

// Medicao_ADC
// Para armazenar dados de leitura anal�gica
struct Medicao_ADC{
	struct Sensor sensor;
	struct Entrada_usuario entrada_usuario;
};

// Range
// Estrutura auxiliar para armazenar valores m�nimos e m�ximos de uma grandeza
struct Range{
	float min;
	float max;
};

// Config_intervalo_aceitavel
// Para armazenar a configura��o de opera��o do sistema definida pelo usu�rio
struct Config_intervalo_aceitavel{
	struct Range temperatura;
	struct Range umidade;
	struct Range radiacao_solar;
};

// Faixa_de_operacao
// Para armazenar a configura��o de opera��o dos sensores definida pelos fabricantes
struct Faixa_de_operacao{
	struct Range temperatura;
	struct Range umidade;
	struct Range radiacao_solar;
};

// Temp_variaveis
// Para armazenar valores tempor�rios
struct Temp_variaveis{
	float temperatura;
	float umidade;
	float radiacao_solar;
	char buf[tam_vetor];
	char buf2[tam_vetor];
	struct Range range;
};

// Historico_da_porta
// Para armazenar o hist�rico das portas com interrup��o externa
struct Historico_da_porta{
	volatile uint8_t D;
	volatile uint8_t B;
};

// Valores_atuais
// Para armazenar os valores medidos dos sensores a cada ciclo
struct Valores_atuais{
	float temperatura;
	float umidade;
	float radiacao_solar;
};

// Fun��es
void fim_pagina();
float valor_medido(float medicao, struct Range range);
void mostrar_dados_sensores(uint8_t conjunto);
void mostrar_status_atuadores();
void editar_valor();
void salvar_valor();
void atualizar_tela();
void mudar_tela();
void reset_edicao();
void reset_medicao_ADC();
void reset_valores_atuais();
void reset_config_intervalo_aceitavel();
void reset_faixa_de_operacao();
void reset_status_dos_atuadores();
void reset_flags_das_interrupcoes();
void reset_historico_de_portas();
void reset_LCD();
void iniciar_sistema();
void inicializar_PWM();
void controle_ar_condicionado();
void controle_motor_teto();
//void controle_motor_bomba_dagua()

// Vari�veis
extern struct Tela TELA;
extern struct Edicao edicao;
extern struct Status_atuadores status;
extern struct Temp_interrupcao temp_interrupcao;
extern struct Medicao_ADC medicao_ADC;
extern struct Config_intervalo_aceitavel config_intervalo_aceitavel;
extern struct Faixa_de_operacao faixa_de_operacao;
extern struct Temp_variaveis temp;
extern struct Historico_da_porta historico_da_porta;
extern struct Valores_atuais valores_atuais;


#endif /* LOGIC_FUNCTIONS_H_ */