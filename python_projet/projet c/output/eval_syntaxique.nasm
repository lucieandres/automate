%include	'io.asm'

section	.bss
	a	dd 0		 ; declaration de variable
	b	dd 0		 ; declaration de variable
sinput:	resb	255	;reserve a 255 byte space in memory for the users input string

section	.text
global _start
	_estPair:		 ; declaration de fonction
	push	ebp		 ; empiler ebp
	mov	ebp, esp		 ; mov ebp, esp
	mov	eax, [ebp+4]		 ; mov eax, 0
Erreur : type de retour de fonction incorrect