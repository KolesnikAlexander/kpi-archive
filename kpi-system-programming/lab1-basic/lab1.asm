code SEGMENT
	ASSUME cs:code

begin:
	mov dl, 10101110b
	mov dh, 0d
	
	;1.move 7th to 4th
	mov al,dl
	and al,10000000b
	mov cl,3d
	shr al,cl
	or dh,al
	
	;2.move 1st to 7th
	mov al,dl
	and al,00000010b
	mov cl,6d
	shl al,cl
	or dh,al
	
	;3.move 2nd to 1st
	mov al,dl
	and al,00000100b
	mov cl,1d
	shr al,cl
	or dh,al
	
	;4.move 2nd to 3d
	mov al,dl
	and al,00000100b
	mov cl,1d
	shl al,cl
	or dh,al

	;5.move 6th to 5th
	mov al,dl
	and al,01000000b
	mov cl,1d
	shr al,cl
	or dh,al
	
	;6.move 0th to 6th
	mov al,dl
	and al,00000001b
	mov cl,6d
	shl al,cl
	or dh,al
	
	;7.move 5th to 0th
	mov al,dl
	and al,00100000b
	mov cl,5d
	shr al,cl
	or dh,al
	
	
	mov ax, 4c00h
	int 21h
code ENDS
	end begin
	
	