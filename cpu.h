#ifndef _CPU_
#define _CPU_

typedef unsigned short int reg16;

#define CPU_State_Failure 0x00
#define CPU_State_Running 0x01
#define CPU_State_SoftIRQ 0x02
#define CPU_State_HardIRQ 0x03

/* mov reg,imm */
#define OPCODE_MOV_AX 0xb8
#define OPCODE_MOV_CX 0xb9
#define OPCODE_MOV_DX 0xba
#define OPCODE_MOV_BX 0xbb
#define OPCODE_MOV_SP 0xbc
#define OPCODE_MOV_BP 0xbd
#define OPCODE_MOV_SI 0xbe
#define OPCODE_MOV_DI 0xbf

/* mov addr,reg8 */
#define OPCODE_MOV_REG8_ADDR 0x88


#endif