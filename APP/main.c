/************************************************************************/
/************************************************************************/
/*******************    AUTHER: Giovanni Samy         *******************/
/*******************    PROJECT:Garage System         *******************/
/*******************    DATE:   2021/09/24            *******************/
/*******************    VERSION:v0.1                  *******************/
/*******************    CRIDETS:                      *******************/
/************************************************************************/
/************************************************************************/
#include "../LIB/bitmath.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/USART/USART_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/KPD/KPD_Interface.h"
#include "../HAL/STPM/STPM_interface.h"
#include <util/delay.h>
#define SHIFT_CURSOR_LEFT 0x10



typedef struct
{
	u32 ID;
	u32 PASSWARD;
}users;

void voidDecimalToAscii(u8 number,u8 array[4])
{
	/*u8 local;
	u8 counter=0;
	local=number;*/
	u8 local;
		u8 counter=0;
		local=number;

		while (local!=0)
		{

			array[2-counter]=(local%10)+48;
			local/=10;
			counter++;
		}
		


}
u32 u32AsciiToDecimal(u8 *u8pCopy_array)  //function to convert ascii array of numbers into decimal (for 8 elements)
{
	u32 decimal_out=0;
	for(u8 asciicounter=0;asciicounter<8;asciicounter++)
	{

		decimal_out=(decimal_out*10)+(u8pCopy_array[asciicounter]-48);
	}
	return decimal_out;
}

void Copy_voidBuzzer(void)
{
	DIO_voidSetPinDirection(PORTD,PIN3,HIGH);
	DIO_voidSetPinValue(PORTD,PIN3,HIGH);
	_delay_ms(1000);
	DIO_voidSetPinValue(PORTD,PIN3,LOW);
}

void Copy_voidStepperMotor(void)
{
	u8 Local_u8Var;
	DIO_voidSetPinDirection(PORTD,PIN2,INPUT);
	DIO_voidSetPinValue(PORTD,PIN2,PULLUP);
	STPM_voidQounterClockwiseMotor(360);
	_delay_ms(3000);
	while(1)
	{
	Local_u8Var=ADC_u8StartConversionSynchronus(ADC_CHANNEL_7);

	if(Local_u8Var>190)
	{
		
		Local_u8Var=ADC_u8StartConversionSynchronus(ADC_CHANNEL_7);
	if(Local_u8Var<170);

		break;


	}
	}
	_delay_ms(150);
	STPM_voidClockwiseMotor(360);

}

void ClearButton(u8 *Copy_u8parray,u8 *Copy_u8parraycounter)
{
	LCD_voidSendCommand(SHIFT_CURSOR_LEFT);
	LCD_voidSendData(' ');
	LCD_voidSendCommand(SHIFT_CURSOR_LEFT);
	Copy_u8parray[*Copy_u8parraycounter-1]=0;
	*Copy_u8parraycounter-=2;
}
/*Function to countdown 30 seconds on LCD */
void void30SecCountdown(void)
{
	LCD_voidSendCommand(0x01);
	LCD_voidSendString("Try again in ");
	LCD_voidSendString("30");
	_delay_ms(1000);
	LCD_voidSendCommand(0x10);
	LCD_voidSendCommand(0x10);

	for (u8 tens=2;tens>=0;tens--)
	{
		LCD_voidSendData(tens+48);

		for (u8 ones=9;ones>=0;ones--)
		{
			LCD_voidSendData(ones+48);
			_delay_ms(1000);
			LCD_voidSendCommand(0x10);

			if (ones==0)
			{
				break;
			}
		}
		LCD_voidSendCommand(0x10);
		if (tens==0)
					{
						break;
					}
	}
}

void voidFreeSpotsCounter(void)
{
	static u8 FreeSpots=100;
	u8 array[3];
	voidDecimalToAscii(FreeSpots,array);
	
	LCD_voidSendCommand(0x01);
	LCD_voidSendString("Free Spots : ");
	if (FreeSpots==100)
	{
		LCD_voidSendData(array[0]);
	}
	if(FreeSpots>=10)
	{
		LCD_voidSendData(array[1]);
	}
	LCD_voidSendData(array[2]);
	FreeSpots--;
}

int main (void)
{
	//initiating drivers for each priphral
	LCD_voidInit();
	KPD_voidInit();
	STPM_voidInit();
	USART_voidInit();
	ADC_voidInit();
	DIO_voidSetPinDirection(PORTA,PIN7,INPUT);

	//declaring variables
	u8 Key_Array[9];
	u8 Pass_Array[8];

	u32 InputID;
	u32 InputPASSWARD;
	u8 local_key;
	users user[]={{32018073,12345678},{32019010,87654321},{32018138,11111111}};
	u8 wpasscounter=0;


	LCD_voidGoToXY(0,4);//first line,forth column
	LCD_voidSendString("WELCOME");
	LCD_voidGoToXY(1,1);
	LCD_voidSendString("SMART GARAGE");
	_delay_ms(2000);
	while(1){
		u8 WrongCounter=0;
		LCD_voidSendCommand(0x01); //clearing the screen
		//LCD_voidSendString(ID_Array);------> was a test line for the id array
		/*using usart protocol*/
		LCD_voidSendString("1-KEYPAD / 2-PC?");
		LCD_voidGoToXY(1,0);
		do{
		local_key=KPD_u8GetPresseedKey();
		}while(local_key==0xff);
		switch(local_key)
		{
		case 1:
			LCD_voidSendCommand(0x01);
			LCD_voidSendString("ID : ");


					for (u8 Key_Counter=0;Key_Counter<8;Key_Counter++)//input loop(takes each key press and displays it on lcd in addition to inputting numbers into array )
					{
						do
						{
							local_key=KPD_u8GetPresseedKey();
						}while (local_key==0xff);
						Key_Array[Key_Counter]=local_key+48;
						//delete button
						if (Key_Array[Key_Counter]!='S')
						{//the array that collect the user input keys
						LCD_voidSendData(local_key+48);
						}
						else if (Key_Array[Key_Counter]=='S')
						{
							ClearButton(Key_Array,&Key_Counter);

						}
						//end delete button

					}
					//LCD_voidSendCommand(0x01);
					//LCD_voidSendString(Key_Array); -----> test line for what the user has entered on the keypad

					InputID=u32AsciiToDecimal(Key_Array);  //function call to convert the ascii array input by keypad into a 8-digit decimal number


					for (u8 useridit=0;useridit<3;useridit++)
					{
						if (InputID==user[useridit].ID)  //if condition that checks if the id is correct or not
						{
							LCD_voidSendCommand(0x01);
							LCD_voidSendString("passward : ");
							LCD_voidGoToXY(1,0);

							for (u8 Pass_Counter=0;Pass_Counter<8;Pass_Counter++)//input loop(takes each key press and displays it on lcd in addition to inputting numbers into array )
							{
							do
							{
								local_key=KPD_u8GetPresseedKey();
							}while (local_key==0xff);
							Pass_Array[Pass_Counter]=local_key+48;
							if (Pass_Array[Pass_Counter]!='S')  //the array that collect the user input keys
							LCD_voidSendData('*');
							else if (Pass_Array[Pass_Counter]=='S')
							{
								ClearButton(Pass_Array,&Pass_Counter);
							}
							}
							InputPASSWARD=u32AsciiToDecimal(Pass_Array);
							if (InputPASSWARD==user[useridit].PASSWARD)
							{
								voidFreeSpotsCounter();

								Copy_voidStepperMotor();
								break;
							}
							else if(InputPASSWARD!=user[useridit].PASSWARD)
							{
								for(wpasscounter=0;wpasscounter<3;wpasscounter++)
								{
								LCD_voidSendCommand(0x01);
										LCD_voidSendString("Wrong PASSWARD!");
										_delay_ms(1000);
										LCD_voidSendCommand(0x01);
										LCD_voidSendString("passward : ");
										LCD_voidGoToXY(1,0);

										for (u8 Pass_Counter=0;Pass_Counter<8;Pass_Counter++)//input loop(takes each key press and displays it on lcd in addition to inputting numbers into array )
												{
												do
												{
													local_key=KPD_u8GetPresseedKey();
												}while (local_key==0xff);
												Pass_Array[Pass_Counter]=local_key+48;          //the array that collect the user input keys
												if (Pass_Array[Pass_Counter]!='S')  //the array that collect the user input keys
													LCD_voidSendData('*');
												else if (Pass_Array[Pass_Counter]=='S')
												{
															ClearButton(Pass_Array,&Pass_Counter);
												}

												}
												InputPASSWARD=u32AsciiToDecimal(Pass_Array);
												if (InputPASSWARD==user[useridit].PASSWARD)
												{
													voidFreeSpotsCounter();
													Copy_voidStepperMotor();
													break;
												}
												else if (InputPASSWARD!=user[useridit].PASSWARD && wpasscounter==1)   //if user entered passward for 3 times wrong it gives a Buzzer and 30 second countdown before starting again
												{
													LCD_voidSendCommand(0x01);
													LCD_voidSendString("wrong");
													LCD_voidGoToXY(1,0);
													LCD_voidSendString("password");
													Copy_voidBuzzer();
													_delay_ms(1000);
													LCD_voidSendCommand(0x01);
													LCD_voidSendString("too many");
													LCD_voidGoToXY(1,0);
													LCD_voidSendString("tries");
													Copy_voidBuzzer();
													_delay_ms(1000);
													Copy_voidBuzzer();
													void30SecCountdown();
													WrongCounter=1;

													break;

												}
								}
							}
						}

						else if (InputID!=user[useridit].ID && useridit>=2)
						{


							if (WrongCounter!=1)
							{
							LCD_voidSendCommand(0x01);
										LCD_voidSendString("Wrong ID!");     //if not correct displays wrong id
										_delay_ms(750);
										break;
							}
							}
					}

		break;
		case 2:
			LCD_voidSendCommand(0x01);
			LCD_voidSendString("ID : ");
			DIO_voidSetPinDirection(PORTD,PIN0,INPUT);
			DIO_voidSetPinDirection(PORTD,PIN1,OUTPUT);

					for (u8 Key_Counter=0;Key_Counter<8;Key_Counter++)//input loop(takes each key press and displays it on lcd in addition to inputting numbers into array )
					{
						USART_voidReceiveCharacter(&local_key);
						Key_Array[Key_Counter]=local_key;
						//delete button
						if (Key_Array[Key_Counter]!=127)
						{//the array that collect the user input keys
						LCD_voidSendData(local_key);
						}
						else if (Key_Array[Key_Counter]==127)
						{
							ClearButton(Key_Array,&Key_Counter);

						}
						//end delete button

					}
					
					InputID=u32AsciiToDecimal(Key_Array);  //function call to convert the ascii array input by keypad into a 8-digit decimal number


							for (u8 useridit=0;useridit<3;useridit++)
							{
								if (InputID==user[useridit].ID)  //if condition that checks if the id is correct or not
								{
									LCD_voidSendCommand(0x01);
									LCD_voidSendString("passward : ");
									LCD_voidGoToXY(1,0);

									for (u8 Pass_Counter=0;Pass_Counter<8;Pass_Counter++)//input loop(takes each key press and displays it on lcd in addition to inputting numbers into array )
									{
										USART_voidReceiveCharacter(&local_key);
									Pass_Array[Pass_Counter]=local_key;
									if (Pass_Array[Pass_Counter]!=127)  //the array that collect the user input keys
									LCD_voidSendData('*');
									else if (Pass_Array[Pass_Counter]==127)
									{
										ClearButton(Pass_Array,&Pass_Counter);
									}
									}
									InputPASSWARD=u32AsciiToDecimal(Pass_Array);
									if (InputPASSWARD==user[useridit].PASSWARD)
									{
										voidFreeSpotsCounter();
										Copy_voidStepperMotor();
										break;
									}
									else if(InputPASSWARD!=user[useridit].PASSWARD)
									{
										for(wpasscounter=0;wpasscounter<3;wpasscounter++)
										{
										LCD_voidSendCommand(0x01);
												LCD_voidSendString("Wrong PASSWARD!");
												_delay_ms(1000);
												LCD_voidSendCommand(0x01);
												LCD_voidSendString("passward : ");
												LCD_voidGoToXY(1,0);

												for (u8 Pass_Counter=0;Pass_Counter<8;Pass_Counter++)//input loop(takes each key press and displays it on lcd in addition to inputting numbers into array )
														{
													USART_voidReceiveCharacter(&local_key);
														Pass_Array[Pass_Counter]=local_key;          //the array that collect the user input keys
														if (Pass_Array[Pass_Counter]!=127)  //the array that collect the user input keys
															LCD_voidSendData('*');
														else if (Pass_Array[Pass_Counter]==127)
														{
																	ClearButton(Pass_Array,&Pass_Counter);
														}

														}
														InputPASSWARD=u32AsciiToDecimal(Pass_Array);
														if (InputPASSWARD==user[useridit].PASSWARD)
														{
															voidFreeSpotsCounter();
															Copy_voidStepperMotor();
															break;
														}
														else if (InputPASSWARD!=user[useridit].PASSWARD && wpasscounter==1)   //if user entered passward for 3 times wrong it gives a Buzzer and 30 second countdown before starting again
														{
															LCD_voidSendCommand(0x01);
															LCD_voidSendString("wrong");
															LCD_voidGoToXY(1,0);
															LCD_voidSendString("password");
															Copy_voidBuzzer();
															_delay_ms(1000);
															LCD_voidSendCommand(0x01);
															LCD_voidSendString("too many");
															LCD_voidGoToXY(1,0);
															LCD_voidSendString("tries");
															Copy_voidBuzzer();
															_delay_ms(1000);
															Copy_voidBuzzer();
															void30SecCountdown();
															WrongCounter=1;

															break;

														}
										}
									}
								}

								else if (InputID!=user[useridit].ID && useridit>=2)
								{


									if (WrongCounter!=1)
									{
									LCD_voidSendCommand(0x01);
												LCD_voidSendString("Wrong ID!");     //if not correct displays wrong id
												_delay_ms(750);
												break;
									}
									}
							}

		break;
		}
	}
}

