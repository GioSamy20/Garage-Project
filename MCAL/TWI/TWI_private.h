#ifndef TWI_PRIVATE_H
#define TWI_PRIVATE_H


#define TWCR (*((volatile u8*)(0x56)))
	 #define TWCR_TWIE		0
	 #define TWCR_TWEN 		2
	 #define TWCR_TWWC  	3
	 #define TWCR_TWSTO 	4
	 #define TWCR_TWSTA 	5
	 #define TWCR_TWEA  	6
	 #define TWCR_TWINT 	7
	
#define TWDR (*((volatile u8*)(0x23)))
#define TWAR (*((volatile u8*)(0x22)))
	#define TWAR_TWGCE	0
    #define TWAR_TWA0 	1
    #define TWAR_TWA1 	2
    #define TWAR_TWA2	3 
    #define TWAR_TWA3	4
    #define TWAR_TWA4	5 
    #define TWAR_TWA5	6 
    #define TWAR_TWA6	7
#define TWSR (*((volatile u8*)(0x21)))
	#define TWSR_TWPS0	0
	#define TWSR_TWPS1	1
#define TWBR (*((volatile u8*)(0x20)))

#define START_CONDITION_CODE 0X08
#define REPEATED_START_CONDITION_CODE 0x10
#define SLAVE_ADD_WITH_WRITE_ERROR 0X18
#define SLAVE_ADD_WITH_READ_ERROR 0X40
#define MASTER_WRITE_DATA_BYTE_ERROR 0X28
#define MASTER_READ_DATA_BYTE_ERROR 0X50



#endif 