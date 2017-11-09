.386
.186
DATA1 SEGMENT PARA
	B1 DB 10011b
	W1 DW 256
	D1 DD 5A6FH
	D2 DD 2048
	
	W2 DW 300
	D3 DD 5A6FH
	B3 DB '1235'
	dvalue db 30 dup ('0',0fh) ;������������� 30 ���������� ������� ����� dvalue
	
	len dw 5
	row dw 3
	col dw 7

	valadd db 1 ;��������, ��� �������� �� dvalue

	cont db 0ffh ;������ ����������� ������
DATA1 ENDS

STACK1 SEGMENT STACK
	DB 256 DUP ('?')
STACK1 ENDS

CODE1 SEGMENT
	ASSUME CS:CODE1, DS:DATA1

MAIN PROC FAR
	mov ax,Data1            
    mov ds,ax
	;������������� �������� ����
	MOV AX, 00H ;������������ ������� ����
	INT 33H

	MOV AX, 0CH; ���������� �������-����������
	MOV CX, 1010b; ������� - ������� �.����. ��� ��. ����.

	push ES ;�������� ���� ����������� �������
	push CS
	pop ES ; ������, �� ��������� �����������
	lea dx, MOUSE_HANDLER; ���������� ������� ���������
	INT 33H

	mov ah, 00H  ;��������� ������������
	mov al, 03H  ;������� ��������� �����
	INT 10H	

	MOV AX, 01H ;�������� ���������
	INT 33H
@write: ; ����������� dvalue
	MOV BX, 0b800h ;��������� ����� �����������
	MOV ES, BX
	�li ; �������� ����������, ��� ����� "�� �����"
	mov si,offset dvalue
	mov al, 0; byte ptr row ; ���������� Nrow ?80?2 + Ncolumn ? 2
	mov ah,0
	MOV BX, 160
	MOV CX, 1
	start_loop:
		CMP CX, BX
		jg end_loop
		add ax, byte ptr row
		add CX, 1
		jmp start_loop
	end_loop:
	add ax,col
	add ax,col ; ���������� ����������
	mov di,ax
	mov cx,len
	cld
	rep movsw ;��������� �� �����
	sti ;����������� ������������
@9: ; ��������� ��������� �������� :
	mov si,len
	shl si,1
	sub si,2 ;���������� ������ ������� ����� dvalue
	mov ah,0 ;��������� �������� ����������� � �������
			;���������� ������
	mov al, dvalue[si]
	add al,valadd
	aaa ;�������� ��� �������� ������������
			;�������-���������� �����
	or al,30h ;���������� ���� ASCII ��������� �����
	mov dvalue[si],al
@10:
	dec si
	dec si
	mov al,ah
	mov ah,0
	add al,dvalue[si] ;��������� �����������
	aaa
	or al,30h
	mov dvalue[si],al
	cmp si,0
	jnz @10
	mov al,cont ;����� ������ ����������� ������ ��������
	cmp al,0ffh
	je @write
	CALL EXIT
MAIN ENDP 

MOUSE_HANDLER PROC FAR
	MOV AX, 03H ; �������� ������� ��������� ���������
	INT 33H
	MOV AX, BX ; �������� � �����������
	
	CHECK_LEFT: AND BX, 11 ; �������� ������� ����� �������
				CMP BX, 01
				jne CHECK_RIGHT
				CMP len, 2
				je R
				sub len, 1
				jmp R
	CHECK_RIGHT: ;������ ������ �������
	CALL EXIT
R:
mov ax, 03 ;������� ������
int 10h
RET
MOUSE_HANDLER ENDP

CLEAR PROC NEAR
	PUSHA
	MOV AX, 0600H
	MOV BH, 07
	MOV CX, 0000
	MOV DX, 184FH
	INT 10H
	POPA
	RET
CLEAR ENDP

EXIT PROC NEAR
	xor cx,cx ;cx=0
	mov ax,0ch
	int 33h ;��������� prmaus ��� ����������� �� ����

	mov ax, 03 ;������� ������
	int 10h

	POP ES

	MOV AX, 4C00H
	INT 21H
EXIT ENDP

CODE1 ENDS
END MAIN