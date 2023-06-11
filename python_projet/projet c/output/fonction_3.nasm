%include	'io.asm'

section	.bss
sinput:	resb	255	;reserve a 255 byte space in memory for the users input string

section	.text
global _start
	_g:		 ; declaration de fonction
	push	ebp		 ; empiler ebp
	mov	ebp, esp		 ; mov ebp, esp
	call	_h		 ; appel de fonction
	push	eax
	pop	eax
	mov	esp, ebp
	pop	ebp
	ret		 ; retour de fonction
	_h:		 ; declaration de fonction
	push	ebp		 ; empiler ebp
	mov	ebp, esp		 ; mov ebp, esp
	push	7
	pop	eax
	mov	esp, ebp
	pop	ebp
	ret		 ; retour de fonction
_start:
	call	_g		 ; appel de fonction
	push	eax
	pop	eax
	call	iprintLF
	mov	eax, 1		 ; 1 est le code de SYS_EXIT
	mov	ebx, 0
	int	0x80		 ; exit
