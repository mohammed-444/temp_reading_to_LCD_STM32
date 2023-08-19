/*
 * keypad.h
 *
 *  Created on: May 18, 2022
 *      Author: hp
 */

#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_

void KeyPad_INIT(void);
void KeyPad_MANAGE(void);
char KeyPad_GET_VALUE(void);
void KeypadCallouts_KeyPressNotificaton(void);


#endif /* INC_KEYPAD_H_ */
