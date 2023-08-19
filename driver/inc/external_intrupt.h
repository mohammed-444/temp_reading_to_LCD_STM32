/*
 * external_intrupt.h
 *
 *  Created on: May 27, 2022
 *      Author: hp
 */

#ifndef INC_EXTERNAL_INTRUPT_H_
#define INC_EXTERNAL_INTRUPT_H_

extern char num;
void external_interrupt_init(char port, char pin );
void display_7seg();
#endif /* INC_EXTERNAL_INTRUPT_H_ */
