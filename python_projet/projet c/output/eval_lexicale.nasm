%include	'io.asm'

section	.bss
	continuer	dd 0		 ; declaration de variable
sinput:	resb	255	;reserve a 255 byte space in memory for the users input string

section	.text
global _start
_start:
	loop1 :
	pop	eax
	cmp	eax, 0
	je	endloop1
Erreur : la condition doit être un booléen
