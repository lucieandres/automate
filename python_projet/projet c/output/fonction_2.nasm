%include	'io.asm'

section	.bss
sinput:	resb	255	;reserve a 255 byte space in memory for the users input string

section	.text
global _start
	_f:		 ; declaration de fonction
	push	2
	pop	eax
	ret		 ; retour de fonction
	_g:		 ; declaration de fonction
	push	4
	pop	eax
	ret		 ; retour de fonction
	_h:		 ; declaration de fonction
	push	1		 ; VRAI
	pop	eax
	ret		 ; retour de fonction
_start:
	call	_f		 ; appel de fonction
	push	eax
	call	_g		 ; appel de fonction
	push	eax
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	add	eax, ebx		 ; effectue l'opération +
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	call	_h		 ; appel de fonction
	push	eax
	pop	eax
	xor	eax, 1		 ; NOT
	push	eax
	pop	eax
	call	iprintLF
	mov	eax, 1		 ; 1 est le code de SYS_EXIT
	mov	ebx, 0
	int	0x80		 ; exit
