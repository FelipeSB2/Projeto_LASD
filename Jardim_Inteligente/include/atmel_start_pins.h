/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef ATMEL_START_PINS_H_INCLUDED
#define ATMEL_START_PINS_H_INCLUDED

#include <port.h>

/**
 * \brief Set LCD_5 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void LCD_5_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTB_set_pin_pull_mode(1, pull_mode);
}

/**
 * \brief Set LCD_5 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void LCD_5_set_dir(const enum port_dir dir)
{
	PORTB_set_pin_dir(1, dir);
}

/**
 * \brief Set LCD_5 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void LCD_5_set_level(const bool level)
{
	PORTB_set_pin_level(1, level);
}

/**
 * \brief Toggle output level on LCD_5
 *
 * Toggle the pin level
 */
static inline void LCD_5_toggle_level()
{
	PORTB_toggle_pin_level(1);
}

/**
 * \brief Get level on LCD_5
 *
 * Reads the level on a pin
 */
static inline bool LCD_5_get_level()
{
	return PORTB_get_pin_level(1);
}

/**
 * \brief Set LCD_4 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void LCD_4_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTB_set_pin_pull_mode(2, pull_mode);
}

/**
 * \brief Set LCD_4 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void LCD_4_set_dir(const enum port_dir dir)
{
	PORTB_set_pin_dir(2, dir);
}

/**
 * \brief Set LCD_4 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void LCD_4_set_level(const bool level)
{
	PORTB_set_pin_level(2, level);
}

/**
 * \brief Toggle output level on LCD_4
 *
 * Toggle the pin level
 */
static inline void LCD_4_toggle_level()
{
	PORTB_toggle_pin_level(2);
}

/**
 * \brief Get level on LCD_4
 *
 * Reads the level on a pin
 */
static inline bool LCD_4_get_level()
{
	return PORTB_get_pin_level(2);
}

/**
 * \brief Set LCD_3 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void LCD_3_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTB_set_pin_pull_mode(3, pull_mode);
}

/**
 * \brief Set LCD_3 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void LCD_3_set_dir(const enum port_dir dir)
{
	PORTB_set_pin_dir(3, dir);
}

/**
 * \brief Set LCD_3 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void LCD_3_set_level(const bool level)
{
	PORTB_set_pin_level(3, level);
}

/**
 * \brief Toggle output level on LCD_3
 *
 * Toggle the pin level
 */
static inline void LCD_3_toggle_level()
{
	PORTB_toggle_pin_level(3);
}

/**
 * \brief Get level on LCD_3
 *
 * Reads the level on a pin
 */
static inline bool LCD_3_get_level()
{
	return PORTB_get_pin_level(3);
}

/**
 * \brief Set LCD_2 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void LCD_2_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTB_set_pin_pull_mode(4, pull_mode);
}

/**
 * \brief Set LCD_2 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void LCD_2_set_dir(const enum port_dir dir)
{
	PORTB_set_pin_dir(4, dir);
}

/**
 * \brief Set LCD_2 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void LCD_2_set_level(const bool level)
{
	PORTB_set_pin_level(4, level);
}

/**
 * \brief Toggle output level on LCD_2
 *
 * Toggle the pin level
 */
static inline void LCD_2_toggle_level()
{
	PORTB_toggle_pin_level(4);
}

/**
 * \brief Get level on LCD_2
 *
 * Reads the level on a pin
 */
static inline bool LCD_2_get_level()
{
	return PORTB_get_pin_level(4);
}

/**
 * \brief Set LCD_1 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void LCD_1_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTB_set_pin_pull_mode(5, pull_mode);
}

/**
 * \brief Set LCD_1 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void LCD_1_set_dir(const enum port_dir dir)
{
	PORTB_set_pin_dir(5, dir);
}

/**
 * \brief Set LCD_1 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void LCD_1_set_level(const bool level)
{
	PORTB_set_pin_level(5, level);
}

/**
 * \brief Toggle output level on LCD_1
 *
 * Toggle the pin level
 */
static inline void LCD_1_toggle_level()
{
	PORTB_toggle_pin_level(5);
}

/**
 * \brief Get level on LCD_1
 *
 * Reads the level on a pin
 */
static inline bool LCD_1_get_level()
{
	return PORTB_get_pin_level(5);
}

/**
 * \brief Set Interrupcao_Usuario4 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void Interrupcao_Usuario4_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTB_set_pin_pull_mode(6, pull_mode);
}

/**
 * \brief Set Interrupcao_Usuario4 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void Interrupcao_Usuario4_set_dir(const enum port_dir dir)
{
	PORTB_set_pin_dir(6, dir);
}

/**
 * \brief Set Interrupcao_Usuario4 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void Interrupcao_Usuario4_set_level(const bool level)
{
	PORTB_set_pin_level(6, level);
}

/**
 * \brief Toggle output level on Interrupcao_Usuario4
 *
 * Toggle the pin level
 */
static inline void Interrupcao_Usuario4_toggle_level()
{
	PORTB_toggle_pin_level(6);
}

/**
 * \brief Get level on Interrupcao_Usuario4
 *
 * Reads the level on a pin
 */
static inline bool Interrupcao_Usuario4_get_level()
{
	return PORTB_get_pin_level(6);
}

/**
 * \brief Set Leitura_Usuario_Potenciome pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void Leitura_Usuario_Potenciome_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTC_set_pin_pull_mode(0, pull_mode);
}

/**
 * \brief Set Leitura_Usuario_Potenciome data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void Leitura_Usuario_Potenciome_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(0, dir);
}

/**
 * \brief Set Leitura_Usuario_Potenciome level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void Leitura_Usuario_Potenciome_set_level(const bool level)
{
	PORTC_set_pin_level(0, level);
}

/**
 * \brief Toggle output level on Leitura_Usuario_Potenciome
 *
 * Toggle the pin level
 */
static inline void Leitura_Usuario_Potenciome_toggle_level()
{
	PORTC_toggle_pin_level(0);
}

/**
 * \brief Get level on Leitura_Usuario_Potenciome
 *
 * Reads the level on a pin
 */
static inline bool Leitura_Usuario_Potenciome_get_level()
{
	return PORTC_get_pin_level(0);
}

/**
 * \brief Set Leitura_Temperatura pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void Leitura_Temperatura_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTC_set_pin_pull_mode(1, pull_mode);
}

/**
 * \brief Set Leitura_Temperatura data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void Leitura_Temperatura_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(1, dir);
}

/**
 * \brief Set Leitura_Temperatura level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void Leitura_Temperatura_set_level(const bool level)
{
	PORTC_set_pin_level(1, level);
}

/**
 * \brief Toggle output level on Leitura_Temperatura
 *
 * Toggle the pin level
 */
static inline void Leitura_Temperatura_toggle_level()
{
	PORTC_toggle_pin_level(1);
}

/**
 * \brief Get level on Leitura_Temperatura
 *
 * Reads the level on a pin
 */
static inline bool Leitura_Temperatura_get_level()
{
	return PORTC_get_pin_level(1);
}

/**
 * \brief Set Leitura_Umidade pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void Leitura_Umidade_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTC_set_pin_pull_mode(2, pull_mode);
}

/**
 * \brief Set Leitura_Umidade data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void Leitura_Umidade_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(2, dir);
}

/**
 * \brief Set Leitura_Umidade level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void Leitura_Umidade_set_level(const bool level)
{
	PORTC_set_pin_level(2, level);
}

/**
 * \brief Toggle output level on Leitura_Umidade
 *
 * Toggle the pin level
 */
static inline void Leitura_Umidade_toggle_level()
{
	PORTC_toggle_pin_level(2);
}

/**
 * \brief Get level on Leitura_Umidade
 *
 * Reads the level on a pin
 */
static inline bool Leitura_Umidade_get_level()
{
	return PORTC_get_pin_level(2);
}

/**
 * \brief Set Leitura_Radiacao_Solar pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void Leitura_Radiacao_Solar_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTC_set_pin_pull_mode(3, pull_mode);
}

/**
 * \brief Set Leitura_Radiacao_Solar data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void Leitura_Radiacao_Solar_set_dir(const enum port_dir dir)
{
	PORTC_set_pin_dir(3, dir);
}

/**
 * \brief Set Leitura_Radiacao_Solar level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void Leitura_Radiacao_Solar_set_level(const bool level)
{
	PORTC_set_pin_level(3, level);
}

/**
 * \brief Toggle output level on Leitura_Radiacao_Solar
 *
 * Toggle the pin level
 */
static inline void Leitura_Radiacao_Solar_toggle_level()
{
	PORTC_toggle_pin_level(3);
}

/**
 * \brief Get level on Leitura_Radiacao_Solar
 *
 * Reads the level on a pin
 */
static inline bool Leitura_Radiacao_Solar_get_level()
{
	return PORTC_get_pin_level(3);
}

/**
 * \brief Set Interrupcao_Usuario1 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void Interrupcao_Usuario1_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTD_set_pin_pull_mode(2, pull_mode);
}

/**
 * \brief Set Interrupcao_Usuario1 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void Interrupcao_Usuario1_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(2, dir);
}

/**
 * \brief Set Interrupcao_Usuario1 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void Interrupcao_Usuario1_set_level(const bool level)
{
	PORTD_set_pin_level(2, level);
}

/**
 * \brief Toggle output level on Interrupcao_Usuario1
 *
 * Toggle the pin level
 */
static inline void Interrupcao_Usuario1_toggle_level()
{
	PORTD_toggle_pin_level(2);
}

/**
 * \brief Get level on Interrupcao_Usuario1
 *
 * Reads the level on a pin
 */
static inline bool Interrupcao_Usuario1_get_level()
{
	return PORTD_get_pin_level(2);
}

/**
 * \brief Set Interrupcao_Usuario2 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void Interrupcao_Usuario2_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTD_set_pin_pull_mode(3, pull_mode);
}

/**
 * \brief Set Interrupcao_Usuario2 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void Interrupcao_Usuario2_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(3, dir);
}

/**
 * \brief Set Interrupcao_Usuario2 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void Interrupcao_Usuario2_set_level(const bool level)
{
	PORTD_set_pin_level(3, level);
}

/**
 * \brief Toggle output level on Interrupcao_Usuario2
 *
 * Toggle the pin level
 */
static inline void Interrupcao_Usuario2_toggle_level()
{
	PORTD_toggle_pin_level(3);
}

/**
 * \brief Get level on Interrupcao_Usuario2
 *
 * Reads the level on a pin
 */
static inline bool Interrupcao_Usuario2_get_level()
{
	return PORTD_get_pin_level(3);
}

/**
 * \brief Set Interrupcao_Usuario3 pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void Interrupcao_Usuario3_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTD_set_pin_pull_mode(4, pull_mode);
}

/**
 * \brief Set Interrupcao_Usuario3 data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void Interrupcao_Usuario3_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(4, dir);
}

/**
 * \brief Set Interrupcao_Usuario3 level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void Interrupcao_Usuario3_set_level(const bool level)
{
	PORTD_set_pin_level(4, level);
}

/**
 * \brief Toggle output level on Interrupcao_Usuario3
 *
 * Toggle the pin level
 */
static inline void Interrupcao_Usuario3_toggle_level()
{
	PORTD_toggle_pin_level(4);
}

/**
 * \brief Get level on Interrupcao_Usuario3
 *
 * Reads the level on a pin
 */
static inline bool Interrupcao_Usuario3_get_level()
{
	return PORTD_get_pin_level(4);
}

/**
 * \brief Set Comparador_Pos_Bateria pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void Comparador_Pos_Bateria_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTD_set_pin_pull_mode(6, pull_mode);
}

/**
 * \brief Set Comparador_Pos_Bateria data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void Comparador_Pos_Bateria_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(6, dir);
}

/**
 * \brief Set Comparador_Pos_Bateria level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void Comparador_Pos_Bateria_set_level(const bool level)
{
	PORTD_set_pin_level(6, level);
}

/**
 * \brief Toggle output level on Comparador_Pos_Bateria
 *
 * Toggle the pin level
 */
static inline void Comparador_Pos_Bateria_toggle_level()
{
	PORTD_toggle_pin_level(6);
}

/**
 * \brief Get level on Comparador_Pos_Bateria
 *
 * Reads the level on a pin
 */
static inline bool Comparador_Pos_Bateria_get_level()
{
	return PORTD_get_pin_level(6);
}

/**
 * \brief Set Comparador_Neg_Bateria pull mode
 *
 * Configure pin to pull up, down or disable pull mode, supported pull
 * modes are defined by device used
 *
 * \param[in] pull_mode Pin pull mode
 */
static inline void Comparador_Neg_Bateria_set_pull_mode(const enum port_pull_mode pull_mode)
{
	PORTD_set_pin_pull_mode(7, pull_mode);
}

/**
 * \brief Set Comparador_Neg_Bateria data direction
 *
 * Select if the pin data direction is input, output or disabled.
 * If disabled state is not possible, this function throws an assert.
 *
 * \param[in] direction PORT_DIR_IN  = Data direction in
 *                      PORT_DIR_OUT = Data direction out
 *                      PORT_DIR_OFF = Disables the pin
 *                      (low power state)
 */
static inline void Comparador_Neg_Bateria_set_dir(const enum port_dir dir)
{
	PORTD_set_pin_dir(7, dir);
}

/**
 * \brief Set Comparador_Neg_Bateria level
 *
 * Sets output level on a pin
 *
 * \param[in] level true  = Pin level set to "high" state
 *                  false = Pin level set to "low" state
 */
static inline void Comparador_Neg_Bateria_set_level(const bool level)
{
	PORTD_set_pin_level(7, level);
}

/**
 * \brief Toggle output level on Comparador_Neg_Bateria
 *
 * Toggle the pin level
 */
static inline void Comparador_Neg_Bateria_toggle_level()
{
	PORTD_toggle_pin_level(7);
}

/**
 * \brief Get level on Comparador_Neg_Bateria
 *
 * Reads the level on a pin
 */
static inline bool Comparador_Neg_Bateria_get_level()
{
	return PORTD_get_pin_level(7);
}

#endif /* ATMEL_START_PINS_H_INCLUDED */
