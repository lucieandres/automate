%include	'io.asm'

section	.bss
	a	dd 0		 ; declaration de variable
	b	dd 0		 ; declaration de variable
sinput:	resb	255	;reserve a 255 byte space in memory for the users input string

section	.text
global _start
	_estPair:		 ; declaration de fonction
Erreur : type de retour de fonction incorrect