%include	'io.asm'

section	.bss
sinput:	resb	255	;reserve a 255 byte space in memory for the users input string

section	.text
global _start
_start:
	pop	eax
	call	iprintLF
	pop	eax
	call	iprintLF
	pop	eax
	call	iprintLF
	pop	eax
	call	iprintLF
	pop	eax
	call	iprintLF
	mov	eax, 1		 ; 1 est le code de SYS_EXIT
	mov	ebx, 0
	int	0x80		 ; exit
