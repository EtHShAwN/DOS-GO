#ifndef _CPU_
#define _CPU_

typedef unsigned short int reg16;

#define CPU_State_Failure 0x00
#define CPU_State_Running 0x01
#define CPU_State_Halt    0x02
#define CPU_State_SoftIRQ 0x03
#define CPU_State_HardIRQ 0x04

/* mov reg,imm */
#define OPCODE_MOV_AX 0xB8
#define OPCODE_MOV_CX 0xB9
#define OPCODE_MOV_DX 0xBA
#define OPCODE_MOV_BX 0xBB
#define OPCODE_MOV_SP 0xBC
#define OPCODE_MOV_BP 0xBD
#define OPCODE_MOV_SI 0xBE
#define OPCODE_MOV_DI 0xBF

/* mov reg,[addr] */
#define OPCODE_MOV_AL_ADDR 0XA0
#define OPCODE_MOV_AX_ADDR 0XA1

/* mov [addr],reg */
#define OPCODE_MOV_ADDR_AL 0xA2
#define OPCODE_MOV_ADDR_AX 0XA3


/* mov addr,reg8 */
#define OPCODE_MOV_REG8_ADDR 0x88

#define OPCODE_NOP 0x90
#define OPCODE_HLT 0xF4

extern void nop();
extern void hlt(int* CPU_State);
extern void movReg8Addr(unsigned char* RAM,reg16* IP);
extern void movAxAddr(unsigned char* RAM,reg16* AX,reg16* IP);
extern void movAlAddr(unsigned char* RAM,reg16* AX,reg16* IP);
extern void movRegImm(reg16* reg, unsigned char* RAM,reg16* IP);

#endif