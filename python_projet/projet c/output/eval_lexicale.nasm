%include	'io.asm'

section	.bss
	continuer	dd 0		 ; declaration de variable
sinput:	resb	255	;reserve a 255 byte space in memory for the users input string

section	.text
global _start
_start:
	mov	eax, 1		 ; 1 est le code de SYS_EXIT
	int	0x80		 ; exit
