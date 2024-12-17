/*
 * APP.c
 *
 * Created: 2/21/2023 12:32:52 PM
 *  Author: Ahmed Dia
 */ 

#include "APP.h"
#include "STD_Types.h"

Uint8 menu_count = 0;
Uint8 B_Percent = 0;

Uint8 Guest_access = Guest_access_False; //No guest access default
Uint8 login_mode = NO_MODE;	//Store the current user mode admin or guest or not logged in
Uint8 key_pressed = NOT_PRESSED;
Uint8 password[PASS_SIZE];
Uint8 Cpass = 0;

Uint8 rData = NOT_PRESSED;
Uint8 BT_sv_cnt = 0;
Uint8 Bluetooth_login = NO_MODE;
Uint8 Pass_check[PASS_SIZE];
Uint8 bluetooth_pass_check[PASS_SIZE];

void APP_init(void){
	//****************** INITIALIZATIONS ****************************
		SPI_InitType options = {MASTER};
		DIO_Init();
		LCD_Init();
		SPI_Init(options);
		Bluetooth_Init();
	//***********************  **************************************
		Buz_DIR_OUT(Buzzer,Output);
		LED_DIR_OUT(ADMIN_LED_PORT,Output);
		LED_DIR_OUT(GUEST_LED_PORT,Output);
		LED_DIR_OUT(NO_MODE_PORT,Output);
		LED_DIR_OUT(Access_LED_PORT,Output);
		LED_DIR_OUT(Bluetooth_LED_PORT,Output);
	//******************** END **************************************
	LED_TurnOn(NO_MODE_PORT);
	//***************************INITIAL PRINT ****************************************
	LCD_String("Welcome to home");
	_delay_ms(1000);
	LCD_Clear();
	//*************************** INITIAL PRINT END *************************************************
}

void APP_First_start(){
	
	if ( (EEPROM_ReadByte(ADMIN_PASS_STATUS_ADDRESS) != PASS_SET) || (EEPROM_ReadByte(GUEST_PASS_STATUS_ADDRESS) != PASS_SET) ){
		LCD_String("Logging in");
		LCD_SetPos(2,0);
		LCD_String("for first time");
		_delay_ms(1000);
		LCD_Clear();
		LCD_SetPos(1,0);
		LCD_String("Set Admin pass");
		LCD_SetPos(2,0);
		LCD_String("Admin pass: ");
	
	//*********************SET ADMIN PASSWORD *****************************

		while(Cpass < PASS_SIZE){
			key_pressed = NOT_PRESSED;
			while (key_pressed == NOT_PRESSED)//repeat till the user press any key
			{
				key_pressed = GetKeyPress();//if the user pressed any button in keypad save the value in key_pressed
				//itoa(key_pressed,password,10);
			}
			password[Cpass] = key_pressed;
			LCD_Char(key_pressed);
			_delay_ms(CHARACTER_PREVIEW_TIME);
			LCD_SetPos(2,12+Cpass);
			LCD_Char(PASSWORD_SYMBOL);
			_delay_ms(100);
			Cpass++;
		}
		EEPROM_WriteBlock(EEPROM_ADMIN_ADDRESS, password, PASS_SIZE);
		EEPROM_WriteByte(ADMIN_PASS_STATUS_ADDRESS, PASS_SET);
		LCD_Clear();
		LCD_SetPos(1,0);
		LCD_String("Password saved");
		_delay_ms(500);
		LCD_Clear();
	//************************* END ****************************************
		
	//*********************SET GUEST PASSWORD *****************************
		LCD_SetPos(1,0);
		LCD_String("Set Guest pass");
		LCD_SetPos(2,0);
		LCD_String("Guest pass: ");
		Cpass = 0;
		
		while(Cpass < PASS_SIZE){
			key_pressed = NOT_PRESSED;
			while (key_pressed == NOT_PRESSED)//repeat till the user press any key
			{
				key_pressed = GetKeyPress();//if the user pressed any button in keypad save the value in key_pressed
				//itoa(key_pressed,password,10);
			}
			password[Cpass] = key_pressed;
			LCD_Char(key_pressed);
			_delay_ms(CHARACTER_PREVIEW_TIME);
			LCD_SetPos(2,12+Cpass);
			LCD_Char(PASSWORD_SYMBOL);
			_delay_ms(100);
			Cpass++;
		}
		EEPROM_WriteBlock(EEPROM_GUEST_ADDRESS, password, PASS_SIZE);
		EEPROM_WriteByte(GUEST_PASS_STATUS_ADDRESS, PASS_SET);
		LCD_Clear();
		LCD_SetPos(1,0);
		LCD_String("Password saved");
		_delay_ms(500);
		LCD_Clear();
		Cpass = 0;
	}
	//***************************************** END *****************************************************
}
void APP_Start_login(void){
	//************************** LOGIN SYSTEM *********************************
	
		Cpass = 0;	//Counter
		key_pressed = NOT_PRESSED;
		Uint8 Stored_pass[PASS_SIZE];	//Array to store the password (Will be used to compare the entered password)
		Uint8 Tries = 0;	//set the number of tries (max = 3)
		Uint8 attempt[1];
		
		while(login_mode == NO_MODE){
			
			/* Bluetooth Trasmit */
			
			Bluetooth_TransmitString("Admin mode");
			Bluetooth_New_line();
			Bluetooth_TransmitString("Enter Password: ");
			
			/* ************************************ */
		
			LCD_Clear();
			LCD_String("Select Mode: ");
			LCD_SetPos(2,0);
			LCD_String("0:Admin 1:Guest");

			while(key_pressed == NOT_PRESSED)//wait for the selection of the mode
			{
				key_pressed = GetKeyPress();
				
				// if Bluetooth is connected and message is sent 
				if(rData != NOT_PRESSED){
					if(Bluetooth_login == NO_MODE){
						
						if((BT_sv_cnt < PASS_SIZE)){
							
							Pass_check[BT_sv_cnt] = rData;
							LCD_SetPos(2,15);
							LCD_String(" ");
							LCD_String(Pass_check);
							BT_sv_cnt++;
							rData = NOT_PRESSED;
						}
						if(BT_sv_cnt == 4){

							EEPROM_ReadBlock(EEPROM_ADMIN_ADDRESS,bluetooth_pass_check,PASS_SIZE);
							
							if(Pass_Compare(Pass_check,bluetooth_pass_check, PASS_SIZE) == TRUE){
								Bluetooth_TransmitString("Logged in");
								Bluetooth_New_line();
								Bluetooth_login = ADMIN_MODE;
								LED_TurnOn(Bluetooth_LED_PORT);
								_delay_ms(200);
								Bluetooth_T_Admin_menu();
								BT_sv_cnt =0;
								rData = NOT_PRESSED;
							}
							else{
								Bluetooth_TransmitString("Wrong Password");
								BT_sv_cnt =0;
							}
						}
					}
				}
			}
		/* ****************** Check the mode and password entered *********************** */
			switch(key_pressed){
				case CHECK_ADMIN_MODE:
					while(login_mode != ADMIN_MODE){
						LCD_Clear();
						key_pressed = NOT_PRESSED;
						LCD_String("Admin Mode");
						LCD_SetPos(2,0);
						LCD_String("Enter Pass: ");
						_delay_ms(100);

						while(Cpass < PASS_SIZE){
							while (key_pressed == NOT_PRESSED)//repeat till the user press any key
							{
								key_pressed = GetKeyPress();
							}
							password[Cpass] = key_pressed;
							LCD_Char(key_pressed);
							_delay_ms(CHARACTER_PREVIEW_TIME);
							LCD_SetPos(2,12+Cpass);
							LCD_Char(PASSWORD_SYMBOL);
							_delay_ms(100);
							Cpass++;
							key_pressed = NOT_PRESSED;
						}
						Cpass = 0; // Re-initialize The counter to zero

						EEPROM_ReadBlock(EEPROM_ADMIN_ADDRESS,Stored_pass,PASS_SIZE);	//Store the password in the EEPROM on the array to used in comparing
	
	// ***************************** COMPARE PASSWORDS *****************************

						if(Pass_Compare(password,Stored_pass, PASS_SIZE) == TRUE){
							LCD_Clear();
							login_mode = ADMIN_MODE;
							Tries = 0;
							LCD_Clear();
							LCD_String("Authorized");
							LCD_SetPos(2,4);
							LCD_String("Enjoy");
							_delay_ms(500);	
							LED_TurnOn(ADMIN_LED_PORT);
							LED_TurnOff(NO_MODE_PORT);
							LED_TurnOff(GUEST_LED_PORT);
							LCD_Clear();
						}
						else{
							LCD_Clear();
							Tries++;
							login_mode = NO_MODE;
							LCD_String("Wrong Password");
							LCD_SetPos(2,0);
							LCD_String("Attempts: ");
							LCD_String(itoa(Tries,attempt,10));
							_delay_ms(500);
							LCD_Clear();
							//key_pressed = CHECK_ADMIN_MODE;
							if(Tries >= TRIES_ALLOWED){
								while(key_pressed != '/'){
									while (key_pressed == NOT_PRESSED)//repeat till the user press any key
									{
										key_pressed = GetKeyPress();
										Buz_TurnOn(Buzzer);
										_delay_ms(20);
										Buz_TurnOff(Buzzer);
										_delay_ms(20);
									}
									
								}
								
								Tries = 0;
							}
						}
					}
					break;
					
			/* *************************** CHECK GUEST MODE ************************************** */
			
				case CHECK_GUEST_MODE:
					while(login_mode != GUEST_MODE){
						LCD_Clear();
						key_pressed = NOT_PRESSED;
						LCD_String("Guest Mode");
						LCD_SetPos(2,0);
						LCD_String("Enter Pass: ");
						_delay_ms(100);
					
						while(Cpass < PASS_SIZE){
							while (key_pressed == NOT_PRESSED)//repeat till the user press any key
							{
								key_pressed = GetKeyPress();
							}
							password[Cpass] = key_pressed;
							LCD_Char(key_pressed);
							_delay_ms(CHARACTER_PREVIEW_TIME);
							LCD_SetPos(2,12+Cpass);
							LCD_Char(PASSWORD_SYMBOL);
							_delay_ms(100);
							Cpass++;
							key_pressed = NOT_PRESSED;
						}
						Cpass = 0; // Re-initialize The counter to zero
					
						EEPROM_ReadBlock(EEPROM_GUEST_ADDRESS,Stored_pass,PASS_SIZE);	//Store the password in the EEPROM on the array to used in comparing
						
						// ***************************** COMPARE PASSWORDS *****************************
						
						if(Pass_Compare(password,Stored_pass, PASS_SIZE) == TRUE){
							LCD_Clear();
							login_mode = GUEST_MODE;
							Tries = 0;
							LCD_Clear();
							LCD_String("Authorized");
							LCD_SetPos(2,4);
							LCD_String("Enjoy");
							_delay_ms(500);
							LED_TurnOn(GUEST_LED_PORT);
							LED_TurnOff(NO_MODE_PORT);
							LED_TurnOff(ADMIN_LED_PORT);
							LCD_Clear();
						}
						else{
							LCD_Clear();
							Tries++;
							login_mode = NO_MODE;
							LCD_String("Wrong Password");
							LCD_SetPos(2,0);
							LCD_String("Attempts: ");
							LCD_String(itoa(Tries,attempt,10));
							_delay_ms(1000);
							LCD_Clear();
							//key_pressed = CHECK_GUEST_MODE;
							if(Tries >= TRIES_ALLOWED){
								while(key_pressed != '/'){
									while (key_pressed == NOT_PRESSED)//repeat till the user press any key
									{
										key_pressed = GetKeyPress();
										Buz_TurnOn(Buzzer);
										_delay_ms(20);
										Buz_TurnOff(Buzzer);
										_delay_ms(20);
									}
									
								}
								
								Tries = 0;
							}
						}
					}
					break;
				default:
					login_mode = NO_MODE;
					LCD_Clear();
					LCD_SetPos(1,3);
					LCD_String("Wrong input");
					_delay_ms(1000);
					LCD_Clear();
					key_pressed = NOT_PRESSED;
			}
		}
	//************************** LOGIN SYSTEM END *********************************
}

void APP_Start_menu(){
	while(login_mode != NO_MODE){
		
		if(menu_count == 0){
			LCD_Clear();
			LCD_SetPos(1,0);
			LCD_String("1:ROOM1,2:ROOM2");
			LCD_SetPos(2,0);
			LCD_String("3:ROOM3,4:ROOM4");
		}

		while(key_pressed == NOT_PRESSED){
			key_pressed = GetKeyPress();
			
			// if Bluetooth is connected and message is sent
			if(rData != NOT_PRESSED){
				if(Bluetooth_login == NO_MODE){
					
					if((BT_sv_cnt < PASS_SIZE)){
						
						Pass_check[BT_sv_cnt] = rData;
						LCD_SetPos(2,15);
						LCD_String(" ");
						LCD_String(Pass_check);
						BT_sv_cnt++;
						rData = NOT_PRESSED;
					}
					if(BT_sv_cnt == 4){

						EEPROM_ReadBlock(EEPROM_ADMIN_ADDRESS,bluetooth_pass_check,PASS_SIZE);
						
						if(Pass_Compare(Pass_check,bluetooth_pass_check, PASS_SIZE) == TRUE){
							Bluetooth_TransmitString("Logged in");
							Bluetooth_New_line();
							Bluetooth_login = ADMIN_MODE;
							LED_TurnOn(Bluetooth_LED_PORT);
							_delay_ms(200);
							Bluetooth_T_Admin_menu();
							BT_sv_cnt =0;
							rData = NOT_PRESSED;
						}
						else{
							Bluetooth_TransmitString("Wrong Password");
							BT_sv_cnt =0;
						}
					}
				}
			}
		}

		switch(key_pressed){
			// '+' FOR ARRow Down
			case ARROW_DOWN:
			menu_count++;
			if(menu_count == 1){
				LCD_Clear();
				LCD_SetPos(1,0);
				LCD_String("5:ROOM5,6:Dim");
				LCD_SetPos(2,0);
				if(login_mode == GUEST_MODE && Guest_access == Guest_access_False){
					LCD_String("7:AC");
				}
				else{
					LCD_String("7:AC,8:DOOR");
				}
				key_pressed = NOT_PRESSED;
			}
			if(menu_count == 2){
				LCD_Clear();
				LCD_SetPos(1,0);
				if(login_mode == GUEST_MODE && Guest_access == Guest_access_False){
					LCD_String("8:Logout");
				}
				else{
					if(login_mode == ADMIN_MODE){
						LCD_String("9:Access");
					}
					LCD_String("C:Logout");
				}
				key_pressed = NOT_PRESSED;
			}
			if(menu_count > 2){
				menu_count = 0;
				key_pressed = NOT_PRESSED;
			}
			break;
			/* ******************* ROOM1 ***************** */
			case ROOM1:
			SPI_TxRx(ROOM1);
			LCD_Clear();
			_delay_ms(100);
			menu_count = 0;
			key_pressed = NOT_PRESSED;
			break;
			/* ******************* ROOM2 ***************** */
			case ROOM2:
			SPI_TxRx(ROOM2);
			LCD_Clear();
			_delay_ms(100);
			menu_count = 0;
			key_pressed = NOT_PRESSED;
			break;
			/* ******************* ROOM3 ***************** */
			case ROOM3:
			SPI_TxRx(ROOM3);
			LCD_Clear();
			_delay_ms(100);
			menu_count = 0;
			key_pressed = NOT_PRESSED;
			break;
			/* ******************* ROOM4 ***************** */
			case ROOM4:
			SPI_TxRx(ROOM4);
			LCD_Clear();
			_delay_ms(100);
			menu_count = 0;
			key_pressed = NOT_PRESSED;
			break;
			/* ******************* ROOM5 ***************** */
			case ROOM5:
			SPI_TxRx(ROOM5);
			LCD_Clear();
			_delay_ms(100);
			menu_count = 0;
			key_pressed = NOT_PRESSED;
			break;
			/* ******************* Dimmer ***************** */
			case Dimmer:
			SPI_TxRx(Dimmer);
			menu_count = 0;
			key_pressed = NOT_PRESSED;
			break;
			/* ******************* Air Conditioner ***************** */
			
			case AC:
			SPI_TxRx(AC);
			LCD_Clear();
			_delay_ms(200);
			menu_count = 0;
			key_pressed = NOT_PRESSED;
			break;
			
			/* ******************* DOOR ***************** */
			case DOOR:
			if(login_mode == ADMIN_MODE || (login_mode == GUEST_MODE && Guest_access == Guest_access_True)){
				SPI_TxRx(DOOR);
				LCD_Clear();
				_delay_ms(300);
				menu_count = 0;
				key_pressed = NOT_PRESSED;
			}
			else if(login_mode == GUEST_MODE && Guest_access == Guest_access_False){
				login_mode = NO_MODE;
				LED_TurnOff(ADMIN_LED_PORT);
				LED_TurnOn(NO_MODE_PORT);
				LED_TurnOff(GUEST_LED_PORT);
				menu_count = 0;
				key_pressed = NOT_PRESSED;
			}
			break;
			
			/* ******************* Give access to guest ***************** */
			
			case Access:
			if(login_mode == ADMIN_MODE){
				LCD_Clear();
				LCD_String("Guest Access: ");
				LCD_SetPos(2,0);
				LCD_String("Yes: 1");
				LCD_String("  ");
				LCD_String("NO: 0");
				
				key_pressed = NOT_PRESSED;
				while(key_pressed == NOT_PRESSED){
					key_pressed = GetKeyPress();
				}
				if(key_pressed == Guest_access_True){
					Guest_access = Guest_access_True;
					LED_TurnOn(Access_LED_PORT);
					menu_count = 0;
					key_pressed = NOT_PRESSED;
				}
				else if(key_pressed == Guest_access_False){
					Guest_access = Guest_access_False;
					LED_TurnOff(Access_LED_PORT);
					menu_count = 0;
					key_pressed = NOT_PRESSED;
				}
			}
			else{
				key_pressed = NOT_PRESSED;
				menu_count = 0;
				LCD_Clear();
				LCD_SetPos(1,0);
				LCD_String("Please choose");
				LCD_SetPos(2,0);
				LCD_String(" from the list");
				_delay_ms(800);
			}
			break;

			/* ******************* LOGOUT SYSTEM ***************** */

			case Logout:
			if(login_mode == ADMIN_MODE || (login_mode == GUEST_MODE && Guest_access == Guest_access_True)){
				login_mode = NO_MODE;
				LED_TurnOff(ADMIN_LED_PORT);
				LED_TurnOn(NO_MODE_PORT);
				LED_TurnOff(GUEST_LED_PORT);
				menu_count = 0;
			}
			else{
				key_pressed = NOT_PRESSED;
				menu_count = 0;
				LCD_Clear();
				LCD_SetPos(1,0);
				LCD_String("Please choose");
				LCD_SetPos(2,0);
				LCD_String(" from the list");
				_delay_ms(800);
			}
			break;

			default:
			
			break;
		}
	}
}



ISR(USART_RXC_vect){
	
	rData = UDR;
	
	/* when logged in */
	
	if(Bluetooth_login == ADMIN_MODE){
		switch(rData){
			/* ********* ROOM1 ********** */
			case ROOM1:
			SPI_TxRx(ROOM1);
			rData = 0;
			Bluetooth_TransmitString("ROOM1");
			break;
			/* ********* ROOM2 ********** */
			case ROOM2:
			SPI_TxRx(ROOM2);
			rData = 0;
			Bluetooth_TransmitString("ROOM2");
			break;
			/* ********* ROOM3 ********** */
			case ROOM3:
			SPI_TxRx(ROOM3);
			rData = 0;
			Bluetooth_TransmitString("ROOM3");
			break;
			/* ********* ROOM4 ********** */
			case ROOM4:
			SPI_TxRx(ROOM4);
			rData = 0;
			Bluetooth_TransmitString("ROOM4");
			break;
			/* ********* ROOM5 ********** */
			case ROOM5:
			SPI_TxRx(ROOM5);
			rData = 0;
			Bluetooth_TransmitString("ROOM5");
			break;
			case Dimmer:
			SPI_TxRx(Dimmer);
			rData = 0;
			Bluetooth_TransmitString("Dimmer");
			break;
			/* ********* AC ********** */
			case AC:
			SPI_TxRx(AC);
			rData = 0;
			Bluetooth_TransmitString("AC");
			break;
			/* ********* Door ********** */
			case DOOR:
			if(Bluetooth_login == ADMIN_MODE){
				SPI_TxRx(DOOR);
				Bluetooth_TransmitString("DOOR");
			}
			else{
				Bluetooth_TransmitString("Choose from the list");
			}
			break;
			/* ********* Guest Access ********** */
			case Access:
			if(Bluetooth_login == ADMIN_MODE){
				Uint8 cnt = 0;
				
				if(cnt == 0){
					LED_TurnOn(Access_LED_PORT);
					Bluetooth_TransmitString("Granted");
					cnt++;
				}
				else if(cnt == 1){
					LED_TurnOff(Access_LED_PORT);
					Bluetooth_TransmitString("Denied");
					cnt = 0;
				}
			}
			else{
				Bluetooth_TransmitString("Choose from the list");
			}
			break;
			/* ********* Logout ********** */
			case Logout:
			if(Bluetooth_login == ADMIN_MODE){
				Bluetooth_TransmitString("Logged Out");
				Bluetooth_New_line();
				Bluetooth_TransmitString("Admin mode");
				Bluetooth_New_line();
				Bluetooth_TransmitString("Enter Password: ");
				LED_TurnOff(Bluetooth_LED_PORT);
				Bluetooth_login = NO_MODE;
			}
			else{
				Bluetooth_TransmitString("Choose from the list");
			}
			break;
			/* ********* Default ********** */
			default:
			
			break;
		}
	}
}
