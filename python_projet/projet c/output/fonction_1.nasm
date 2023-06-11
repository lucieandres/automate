%include	'io.asm'

section	.bss
sinput:	resb	255	;reserve a 255 byte space in memory for the users input string

section	.text
global _start
	_f:		 ; declaration de fonction
;2
;fonction a l'index 0
	push	3
	pop	eax
	ret		 ; retour de fonction
_start:
;Ajout du symbole f
	call	_f		 ; appel de fonction
	push	eax
	pop	eax
	call	iprintLF
	mov	eax, 1		 ; 1 est le code de SYS_EXIT
	mov	ebx, 0
	int	0x80		 ; exit
