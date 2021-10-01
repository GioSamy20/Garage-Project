#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

#define KPD_PORT     PORTC

/*Definitions for the row pins*/
#define KPD_ROW0_PIN   PIN4
#define KPD_ROW1_PIN   PIN5
#define KPD_ROW2_PIN   PIN6
#define KPD_ROW3_PIN   PIN7

/*Definitions for the row pins*/
#define KPD_Col0_PIN   PIN3
#define KPD_Col1_PIN   PIN2
#define KPD_Col2_PIN   PIN1
#define KPD_Col3_PIN   PIN0

#define COLUMNS_NUM     4
#define ROWS_NUM        4

#define NoPreesdKey    0xff
#define KPD_Arr_Value         {{1,2,3,4},{4,5,6,7},{7,8,9,9},{12,0,14,35}}

#endif
