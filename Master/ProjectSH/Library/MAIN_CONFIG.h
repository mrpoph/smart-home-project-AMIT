/*
 * MAIN_CONFIG.h
 *
 * Created: 12/15/2022 1:16:42 PM
 *  Author: Ahmed Dia
 */ 


#ifndef MAIN_CONFIG_H_
#define MAIN_CONFIG_H_

#define CHARACTER_PREVIEW_TIME 300
#define PASS_SIZE      4
#define TRIES_ALLOWED   3
#define PASSWORD_SYMBOL '*'
#define ARROW_DOWN '+'

#define Match 1
#define PASS_NOT_SET 0xFF
#define PASS_SET     0x01
#define Password_Tries_count 3
#define Bluetooth_press 55

#define ADMIN_PASS_STATUS_ADDRESS 0X100
#define GUEST_PASS_STATUS_ADDRESS 0X101
#define EEPROM_ADMIN_ADDRESS      0X102
#define EEPROM_GUEST_ADDRESS      0X106

#define NO_MODE 0
#define ADMIN_MODE   1
#define GUEST_MODE   2

#define FALSE   0
#define TRUE    1

#define CHECK_ADMIN_MODE        '0'
#define CHECK_GUEST_MODE        '1'

#define Guest_access_False '0'
#define Guest_access_True '1'

#define ROOM1 '1'
#define ROOM2 '2'
#define ROOM3 '3'
#define ROOM4 '4'
#define ROOM5 '5'
#define Dimmer '6'
#define AC '7'
#define DOOR '8'
#define Access '9'
#define Logout 'C'

#endif /* MAIN_CONFIG_H_ */