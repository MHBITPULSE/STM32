/*
 * Alarm.h
 *
 *  Created on: Jul 12, 2022
 *      Author: SPM_Benzir
 */

#ifndef APPLICATION_USER_GUI_ALARM_H_
#define APPLICATION_USER_GUI_ALARM_H_
#include "stdint.h"

class Alarm {
public:
	Alarm();
	virtual ~Alarm();
private:
	uint8_t status;
	typedef enum
	{
	  ALARM_ON = 0U,
	  ALARM_OFF,
	  ALARM_ACK,
	  ALARM_RESET
	} AlarmStatus_TypeDef;
};

#endif /* APPLICATION_USER_GUI_ALARM_H_ */
