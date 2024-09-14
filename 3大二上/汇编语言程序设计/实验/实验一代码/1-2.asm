STACK SEGMENT STACK
    DW 512 DUP(?)
STACK ENDS
DATA SEGMENT
    X DW 3
    Y DW 123
    Z DW 82
    V DW 20
    SUM1 DW ?
    SUM2 DW ?
DATA ENDS
CODE SEGMENT
    ASSUME CS:CODE,DS:DATA,SS:STACK
        START:    MOV AX,DATA
            MOV DS,AX        
 
            MOV AX,X    ;将X中的数据放入AX中
            MOV BX,Y    
 
            IMUL BX        ;X*Y
 
            MOV CX,AX
            MOV BX,DX    ;保存x*y到BX:CX中
 
            MOV AX,Z
            CWD        ;拓展寄存器DX
            ADD AX,CX    ;X*Y+Z
            ADC DX,BX    ;加上进位
 
            SUB AX,720    ;X*Y+Z-720
            SBB DX,0    ;减去借位
 
            MOV CX,AX
            MOV BX,DX    ;保存X*Y+Z-720到BX:CX中
 
            MOV AX,V
            CWD
            SUB AX,CX    ;V-(X*Y+Z-720)
            SBB DX,0    ;减去借位
 
            MOV BX,X
            IDIV BX        ;V-(X*Y+Z-720)
            MOV SUM1,AX    ;商
            MOV SUM2,DX    ;余数
 
            MOV AX,4C00H
            INT 21H
        CODE ENDS
    END START