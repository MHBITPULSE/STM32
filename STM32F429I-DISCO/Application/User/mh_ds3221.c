/*
 * mh_ds3221.c
 *
 *  Created on: May 12, 2022
 *      Author: MH
 */

#include "mh_ds3231.h"

I2C_HandleTypeDef *ds3231_i2c;
HAL_StatusTypeDef stat;

void DS3231_Init(I2C_HandleTypeDef *i2c){

	uint8_t ctrl = 0;
	DS33231_InitTypeDef ds3231;
	ds3231.Alarm1_Interrupt = DS3231_ALARM1_Disable;
	ds3231.Alarm2_Interrupt = DS3231_ALARM2_Disable;
	ds3231.BBSQW = DS3231_BBSQW_Disable;
	ds3231.Convert_Temperature = DS3231_CONV_TEMP_STOP;
	ds3231.Enable_Oscillator = DS3231_Oscillator_Enable;
	ds3231.INTCN = DS3231_INT_SQWAVE;
	ds3231.Rate_Select = DS3231_SQUARE_WAVE_RATE_8192HZ;

	ctrl = (ds3231.Alarm1_Interrupt |   \
			ds3231.Alarm2_Interrupt |   \
			ds3231.BBSQW |              \
			ds3231.Convert_Temperature |\
			ds3231.Enable_Oscillator|   \
			ds3231.INTCN |              \
			ds3231.Rate_Select);
	ds3231_i2c = i2c;
	uint8_t temp[2] = {DS3231_CONTROL_ADDR, ctrl};
	stat = HAL_I2C_Master_Transmit(ds3231_i2c, DS3231_WRITE_ADDR, &temp, 2, 100);

}

//Get Second
uint8_t DS3231_Set_Second(uint8_t sec){
	uint8_t temp[2] = { 0x00, DS3231_EncodeBCD(sec)};
	stat = HAL_I2C_Master_Transmit(ds3231_i2c, DS3231_WRITE_ADDR, &temp, 2, 100);
	if(stat == HAL_OK)
		return HAL_OK;
	else
		return HAL_ERROR;
}
//Get Minute
uint8_t DS3231_Set_Minute(uint8_t min){
	uint8_t temp[2] = { 0x01, DS3231_EncodeBCD(min)};
	stat = HAL_I2C_Master_Transmit(ds3231_i2c, DS3231_WRITE_ADDR, &temp, 2, 100);
	if(stat == HAL_OK)
		return HAL_OK;
	else
		return HAL_ERROR;
}
//Get Hour
uint8_t DS3231_Set_Hour(uint8_t hr){
	uint8_t temp[2] = { 0x02, DS3231_EncodeBCD(hr)};
	stat = HAL_I2C_Master_Transmit(ds3231_i2c, DS3231_WRITE_ADDR, &temp, 2, 100);

	if(stat == HAL_OK)
		return HAL_OK;
	else
		return HAL_ERROR;
}

//Get Second
uint8_t DS3231_Get_Second(void){
	uint8_t temp;
	stat = HAL_I2C_Master_Transmit(ds3231_i2c, DS3231_WRITE_ADDR, DS3231_SECOND_ADDR, 1, 100);
	stat = HAL_I2C_Master_Receive(ds3231_i2c, DS3231_WRITE_ADDR, &temp, 1, 100);
	return DS3231_DecodeBCD(temp);
}
//Get Minute
uint8_t DS3231_Get_Minute(void){
	uint8_t temp = 0x01;
	stat = HAL_I2C_Master_Transmit(ds3231_i2c, DS3231_WRITE_ADDR, &temp, 1, 100);
	stat = HAL_I2C_Master_Receive(ds3231_i2c, DS3231_WRITE_ADDR, &temp, 1, 100);
	return DS3231_DecodeBCD(temp);
}
//Get Hour
uint8_t DS3231_Get_Hour(void){
	uint8_t temp = 0x02;
	stat = HAL_I2C_Master_Transmit(ds3231_i2c, DS3231_WRITE_ADDR, &temp, 1, 100);
	stat = HAL_I2C_Master_Receive(ds3231_i2c, DS3231_WRITE_ADDR, &temp, 1, 100);
	return DS3231_DecodeBCD(temp);
}

//Get Temperature
uint8_t DS3231_Get_Temperature(void){
	uint8_t temp = 0x11;
	stat = HAL_I2C_Master_Transmit(ds3231_i2c, DS3231_WRITE_ADDR, &temp, 1, 100);
	stat = HAL_I2C_Master_Receive(ds3231_i2c, DS3231_WRITE_ADDR, &temp, 1, 100);
	return temp;
}

void DS3231_Set_Time(uint8_t hour, uint8_t minute, uint8_t second){
	DS3231_Set_Hour(hour);
	DS3231_Set_Minute(minute);
	DS3231_Set_Second(second);
}

//Decode BCD to Decimal

uint8_t DS3231_DecodeBCD (uint8_t bin){
	return (((bin & 0xf0) >> 4) * 10) + (bin & 0x0f);
}

//Decode  Decimal to BCD
uint8_t DS3231_EncodeBCD(uint8_t dec) {
	return (dec % 10 + ((dec / 10) << 4));
}
