%include	'io.asm'

section	.bss
sinput:	resb	255	;reserve a 255 byte space in memory for the users input string

section	.text
global _start
	_f:		 ; declaration de fonction
	push	ebp		 ; empiler ebp
	mov	ebp, esp		 ; mov ebp, esp
	push	120
	pop	eax
	call	iprintLF
	push	0
	pop	eax
	mov	esp, ebp
	pop	ebp
	ret		 ; retour de fonction
_start:
	call	_f		 ; appel de fonction
	push	eax
	mov	eax, 1		 ; 1 est le code de SYS_EXIT
	mov	ebx, 0
	int	0x80		 ; exit
