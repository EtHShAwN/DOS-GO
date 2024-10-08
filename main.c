#include<stdio.h>
#include<stdlib.h>

#include"cpu.h"

FILE* executable = NULL;

void movRegImm(reg16* reg, unsigned char* RAM,reg16* IP){
    *reg = (RAM[*IP+2] << 8) + RAM[*IP+1];
    *IP += 2;
}

void movReg8Addr(unsigned char* RAM,reg16* IP){
    RAM[*IP];
}


void parseArgument(int argc,char* argv[]){
    for (int i = 1; i < argc; i++){
        if(argv[i][0] != '-'){
            //test & open File
            if ( fopen(argv[i],"r") == NULL ){
                puts("Can't open specifide file");
            } else{
                executable = fopen(argv[i],"r");
            }
        }
    }
}

int main(int argc,char* argv[]){
    unsigned char* RAM = malloc(640 * 1024);
    unsigned char* Buf = malloc(512);
    reg16 AX = 0;
    reg16 BX = 0;
    reg16 CX = 0;
    reg16 DX = 0;
    reg16 CS = 0;
    reg16 DS = 0;
    reg16 SS = 0;
    reg16 ES = 0;
    reg16 IP = 0;
    reg16 SP = 0;
    reg16 BP = 0;
    reg16 DI = 0;
    reg16 SI = 0;
    size_t bytesRead;
    int CPU_State;

    puts("DOS-GO: a cli DOS emulator");
    parseArgument(argc,argv);

    if (RAM == NULL || Buf == NULL){
        puts("Memory allocation failed");
        return 1;
    }

    if (executable == NULL) {
        puts("No valid executable file provided.");
        free(RAM);
        free(Buf);
        return 1;
    }

    bytesRead = fread(Buf,sizeof(unsigned char),10,executable);

    //start CPU
    CPU_State = CPU_State_Running;

    if(Buf[0] != 'M'){
        IP = 0x100;
    }
    
    for (int i = 0; i < bytesRead; i++) {
        RAM[CS*0x10 + IP] = Buf[i];
        IP++;
    }
    IP -= bytesRead;


    // CPU Execution
    while(CPU_State >= CPU_State_Failure){
        
        unsigned currentIP = CS*0x10 + IP;

        // mov reg,imm
        if(RAM[currentIP] >= OPCODE_MOV_AX && RAM[currentIP] <= OPCODE_MOV_DI){
            switch (RAM[currentIP])
            {
            case OPCODE_MOV_AX:
                movRegImm(&AX,RAM,&IP);
                printf("MOV AX,0x%04x\n",AX);
                break;
            case OPCODE_MOV_BX:
                movRegImm(&BX,RAM,&IP);
                printf("MOV BX,0x%04x\n",BX);
                break;
            case OPCODE_MOV_CX:
                movRegImm(&CX,RAM,&IP);
                printf("MOV CX,0x%04x\n",CX);
                break;
            case OPCODE_MOV_DX:
                movRegImm(&DX,RAM,&IP);
                printf("MOV DX,0x%04x\n",DX);
                break;
            case OPCODE_MOV_BP:
                movRegImm(&BP,RAM,&IP);
                printf("MOV BP,0x%04x\n",BP);
                break;
            case OPCODE_MOV_SP:
                movRegImm(&SP,RAM,&IP);
                printf("MOV SP,0x%04x\n",SP);
                break;
            case OPCODE_MOV_DI:
                movRegImm(&DI,RAM,&IP);
                printf("MOV DI,0x%04x\n",DI);
                break;
            case OPCODE_MOV_SI:
                movRegImm(&SI,RAM,&IP);
                printf("MOV SI,0x%04x\n",SI);
                break;
            default:
                puts("invalid mov opcode");
                break;
            }
        }

        if(RAM[currentIP] == OPCODE_MOV_REG8_ADDR){
            movReg8Addr(RAM,&IP);
        }

        IP++;
    }


    fclose(executable);
    return 0;
}