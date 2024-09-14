STACK SEGMENT STACK
    DW 512(?)
STACK ENDS
DATA SEGMENT
    SCORE DB 10 DUP(0,10,20,30,40,50,60,70,80,90)    ;为了程序方便，以十组一样的数据存在内存中代替一百个学生的成绩
DATA ENDS
CODE SEGMENT
    ASSUME CS:CODE,DS:DATA,SS:STACK
START:
    MOV AX,DATA
    MOV DS,AX
    LEA BX,SCORE    ;拿到成绩数据首地址
    MOV CX,100    ;循环100次，遍历所有学生成绩
    MOV SI,0
 
 
    MOV AH,01H    ;输入一个字符，表示十位
    INT 21H
    AND AX,000FH
    
    MOV DL,10
    MUL DL    
    MOV DL,AL    ;保存AL
 
    MOV AH,01H    ;输入一个字符，表示个位
    INT 21H        
    AND AX,000FH
    ADD AL,DL    ;将输入成绩保存在DH中
    MOV DH,AL
 
    MOV AH,2
    MOV DL,10    ;回车
    INT 21H
 
    MOV AH,2
    MOV DL,13    ;换行
    INT 21H
 
AGAIN:    
    MOV DL,[BX+SI]
    CMP DH,DL
    JE DOWN
    INC SI
    LOOP AGAIN
 
    MOV DL,'N'
    JMP SHOW    ;运行到这里说明找不到对应的学生
    
DOWN:
    MOV DL,'Y'
 
 
SHOW:    MOV AH,02
    INT 21H
 
    MOV AX,4C00H
    INT 21H
CODE ENDS
    END START