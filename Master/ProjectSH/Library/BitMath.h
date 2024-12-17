/*
 * BitMath.h
 *
 * Created: 11/11/2022 8:39:00 PM
 *  Author: Ahmed Dia
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_

#define SetBit(Reg,BitNo) (Reg |= (1<<BitNo))
#define ClearBit(Reg,BitNo) (Reg &=~ (1<<BitNo))
#define ToggleBit(Reg,BitNo) (Reg ^= (1<<BitNo))
#define GetBit(Reg,BitNo) ((Reg>>BitNo)&1)


#endif /* BITMATH_H_ */