%include	'io.asm'

section	.bss
	continuer	dd 0		 ; declaration de variable
sinput:	resb	255	;reserve a 255 byte space in memory for the users input string

section	.text
global _start
	_max:		 ; declaration de fonction
	push	ebp		 ; empiler ebp
	mov	ebp, esp		 ; mov ebp, esp
	mov	eax, [ebp+12]		 ; mov eax, 0
Erreur : la condition doit être un booléen
