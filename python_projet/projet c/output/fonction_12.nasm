%include	'io.asm'

section	.bss
sinput:	resb	255	;reserve a 255 byte space in memory for the users input string

section	.text
global _start
	_puissance:		 ; declaration de fonction
	push	ebp		 ; empiler ebp
	mov	ebp, esp		 ; mov ebp, esp
	mov	eax, [ebp+8]		 ; mov eax, 0
	loop1 :
Erreur : les deux opérandes doivent être des entiers
