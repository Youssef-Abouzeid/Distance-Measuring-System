

/*                                            COMMON MACROS USED IN ANY DRIVERS MODULE
 ************************************************************************************************************************************************************/


#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_

/*Set a certain bit in any register*/
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/*Clear a certain bit in any register*/
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))

/*Toggle a certain bit in any register*/
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/*Rotate right the register with specified number of rotates*/
#define ROR(REG,num) ( REG =  (REG>>num) | (REG<<(8-num)) )

/*Rotate left the register with specified number of rotates*/
#define ROL(REG,num) ( REG =  (REG<<num) | (REG>>(8-num)) )

/*Check if a specific bit is set in any register and return true if yes*/
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/*Check if a specific bit is cleared in any register and return true if yes*/
#define BIT_IS_CLEARED(REG,BIT) ( !(REG & (1<<BIT)) )

#define GET_BIT(REG,BIT) ( ( REG & (1<<BIT) ) >> BIT )



#endif
