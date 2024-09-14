STACK SEGMENT STACK
    DW 512(?)
STACK ENDS
DATA SEGMENT
    STR    DW L0,L1,L2,L3,L4,L5,L6,L7    ;地址表
    S0    DB 'The 0 Bit is 0$'
    S1    DB 'The 1 Bit is 0$'
    S2    DB 'The 2 Bit is 0$'
    S3    DB 'The 3 Bit is 0$'
    S4    DB 'The 4 Bit is 0$'
    S5    DB 'The 5 Bit is 0$'
    S6    DB 'The 6 Bit is 0$'
    S7    DB 'The 7 Bit is 0$'
DATA ENDS
CODE SEGMENT
    ASSUME CS:CODE,DS:DATA,SS:STACK
START:
    MOV AX,DATA
    MOV DS,AX
    MOV BL,11111110B    ;待测试的数据，从左往右第7位是0
    MOV CX,8
    MOV AL,BL
    MOV BX,0
AGAIN:
    SHL AL,1
    JNC GET        ;当cf = 0,就是找到了唯一的0位，跳出循环
    INC BX
    LOOP AGAIN
    JMP DOWN    ;如果程序到这里说明没有找到0位，程序直接结束
 
GET:
    SHL BX,1
    JMP STR[BX]
L0:    MOV DX,OFFSET S0
    JMP SHOW
L1:    MOV DX,OFFSET S1
    JMP SHOW
L2:    MOV DX,OFFSET S2
    JMP SHOW
L3:    MOV DX,OFFSET S3
    JMP SHOW
L4:    MOV DX,OFFSET S4
    JMP SHOW
L5:    MOV DX,OFFSET S5
    JMP SHOW
L6:    MOV DX,OFFSET S6
    JMP SHOW
L7:    MOV DX,OFFSET S7
    JMP SHOW
SHOW:
    MOV AH,09H
    INT 21H
 
DOWN:
    MOV AX,4C00H
    INT 21H
CODE ENDS
    END START