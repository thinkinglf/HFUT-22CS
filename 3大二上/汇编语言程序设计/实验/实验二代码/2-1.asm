STACK SEGMENT STACK
    DW 512(?)
STACK ENDS
DATA SEGMENT
    X DW 3                ;默认x为3，y为5，计算结果z为2035
    Y DW 5
    Z DW 0
DATA ENDS
CODE SEGMENT
    ASSUME CS:CODE,DS:DATA,SS:STACK
START:
    MOV AX,DATA
    MOV DS,AX
    
    PUSH X
    PUSH Y
    CALL COUNT    ;调用计算函数
    MOV Z,AX    ;寄存器将结果返回，保存在Z中
    CALL SHOW    ;调用显示结果函数
    
    MOV AX,4C00H
    INT 21H
 
COUNT PROC
    PUSH BP
    MOV BP,SP
    PUSH BX
    PUSH DX        ;保存现场
    
    MOV AX,[BP+4]    ;Y
    MOV BX,[BP+6]    ;X
    IMUL BX        ;AX=X*Y
    SUB AX,BX    ;AX=X*Y-X
    ADD AX,2023    ;AX=X*Y-X+2023
 
    POP DX        ;还原现场
    POP BX
    POP BP
    RET 4        ;程序返回,跳过参数X,Y
COUNT ENDP    ;程序结束
 
SHOW PROC
    PUSH BX
    PUSH DX
    
    TEST AX,AX
    JNZ SHOW1
    MOV DL,'0'    ;如果结果是0
    MOV AH,02H
    INT 21H
    JMP DOWN
 
SHOW1:    
    JNS SHOW2    ;如果是正数就转移
    MOV BX,AX    ;如果是负数，暂存AX
    MOV DL,'-'    ;输出负号
    MOV AH,2
    INT 21H
    NEG BX        ;数据求补（绝对值）
    MOV BX,AX
 
SHOW2:
    MOV BX,10    ;存入退出标志
    PUSH BX
    
AGAIN1:
    CMP AX,0
    JZ AGAIN2    ;跳到输出循环中
    MOV DX,0    ;扩展被除数    
    DIV BX        
    ADD DL,30H
    PUSH DX
    JMP AGAIN1
 
AGAIN2:
    POP DX
    CMP DL,10
    JE DOWN
    MOV AH,2
    INT 21H
    JMP AGAIN2
 
DOWN:    POP DX
    POP BX
    RET
SHOW ENDP
 
CODE ENDS
    END START