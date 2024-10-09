#include<stdio.h>

#include "cpu.h"

unsigned char parseModRM(unsigned char modRM, unsigned char* regIndex, unsigned char* rmIndex){
    // Extract the mode, reg, and rm values from the ModRM byte
    unsigned char mode = (modRM & MODRM_MODE_MASK) >> 6;
    *regIndex = (modRM & MODRM_REG_MASK) >> 3;
    *rmIndex = (modRM & MODRM_RM_MASK);
    return mode;
}

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

void movAddrAl(unsigned char* RAM,reg16* AX,reg16* IP){
    unsigned int address = (RAM[*IP + 2] << 8) + RAM[*IP + 1];
    RAM[address] = *AX & 0x00FF;
    printf("MOV [%04X],AL\n", address);  //debug output
}

void movAddrAx(unsigned char* RAM,reg16* AX,reg16* IP){
    unsigned int address = (RAM[*IP + 2] << 8) + RAM[*IP + 1];
    RAM[address] = *AX;
    printf("MOV [%04X],AX\n", address);  //debug output
}

void addReg8Reg8(unsigned char* RAM,reg16* IP,reg16* src,reg16* dst){

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
