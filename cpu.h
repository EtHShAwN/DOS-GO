#ifndef _CPU_
#define _CPU_

typedef unsigned short int reg16;

/* MODR/M mask */
#define MODRM_MODE_MASK 0xC0
#define MODRM_REG_MASK  0x38
#define MODRM_RM_MASK   0x07

#define CPU_State_Failure 0x00
#define CPU_State_Running 0x01
#define CPU_State_Halt    0x02
#define CPU_State_SoftIRQ 0x03
#define CPU_State_HardIRQ 0x04

/* add dst,reg8 */
#define OPCODE_ADD_DST_REG8 0x00

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
extern void movAddrAl(unsigned char* RAM,reg16* AX,reg16* IP);
extern void movAddrAx(unsigned char* RAM,reg16* AX,reg16* IP);
extern void movRegImm(reg16* reg, unsigned char* RAM,reg16* IP);
extern void addReg8Reg8(unsigned char* RAM,reg16* IP,reg16* src,reg16* dst);

extern unsigned char parseModRM(unsigned char modRM, unsigned char* regIndex, unsigned char* rmIndex);

#endif