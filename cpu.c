#include<stdio.h>

#include "cpu.h"

void movRegImm(reg16* reg, unsigned char* RAM,reg16* IP){
    *reg = (RAM[*IP+2] << 8) + RAM[*IP+1];
    *IP += 2;
}

void movReg8Addr(unsigned char* RAM,reg16* IP){
    unsigned char modRegRm = RAM[*(IP + 1)];
    unsigned char mod = (modRegRm >> 6) & 0x03;     // Bits 7-6
    unsigned char reg = (modRegRm >> 3) & 0x07;     // Bits 5-3
    unsigned char rm = modRegRm & 0x07;             // Bits 2-0
    printf("Mod: %u, Reg: %u, R/M: %u\n", mod, reg, rm);    //debug output
    // remain to be implemented
    *IP += 2;
}

void movAxAddr(unsigned char* RAM,reg16* AX,reg16* IP){
    *AX = RAM[ (RAM[*IP+2] *0x100 ) + RAM[*IP] ];
    printf("MOV AX,[%04X]\n",((RAM[*IP+2] *0x100 ) + RAM[*IP+1]));  //debug output
}

void movAlAddr(unsigned char* RAM,reg16* AX,reg16* IP){
    *AX = (*AX & 0xFF00) | RAM[ (RAM[*IP + 2] * 0x100) + RAM[*IP + 1] ];
    printf("MOV AL,[%04X]\n",((RAM[*IP+2] *0x100 ) + RAM[*IP+1]));  //debug output
}

void nop(){
    puts("NOP");    //debug output
    return;
}

void hlt(int* CPU_State){
    *CPU_State = CPU_State_Halt;
    puts("HLT");    //debug output
    return;
}
