#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#define MCUCR (*((volatile u8*)(0x55)))  //MCU  control register 
 #define MCUCR_ISC00 0					//in sense control 0 for int0
 #define MCUCR_ISC01 1                  //in sense control 1 for int0
 #define MCUCR_ISC10 2                  //in sense control 2 for int1
 #define MCUCR_ISC11 3                  //in sense control 3 for int1
                                       
#define MCUCSR (*((volatile u8*)(0x54)))  //MCU  control & status register
 #define MCUCSR_ISC2 6					//in sense control for int2
 
#define GICR  (*((volatile u8*)(0x5B)))  // GICR is considering SIE
 #define GICR_INT0	6
 #define GICR_INT1	7
 #define GICR_INT2	5

#define GIFR  (*((volatile u8*)(0x5A))) //GIFR is considering PIF
 #define GIFR_INTF0	6
 #define GIFR_INTF1	7
 #define GIFR_INTF2	5
 
 






#define NULL_POINTER (void*)0


#endif 