%include	'io.asm'

section	.bss
	a	dd 0		 ; declaration de variable
	b	dd 0		 ; declaration de variable
sinput:	resb	255	;reserve a 255 byte space in memory for the users input string

section	.text
global _start
_start:
	cmp	eax, 0
	je	loop1
	pop	eax
	call	iprintLF
	jmp	endloop1
	loop1 :
	pop	eax
	call	iprintLF
	endloop1 :
	mov	eax, 1		 ; 1 est le code de SYS_EXIT
	mov	ebx, 0
	int	0x80		 ; exit
