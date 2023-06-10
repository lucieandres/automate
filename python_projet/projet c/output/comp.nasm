%include	'io.asm'

section	.bss
sinput:	resb	255	;reserve a 255 byte space in memory for the users input string

section	.text
global _start
_start:
	push	1
	push	2
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	2
	push	2
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	3
	push	2
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	1
	push	2
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	2
	push	2
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	3
	push	2
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	1
	push	2
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	2
	push	2
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	3
	push	2
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	1
	push	2
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	2
	push	2
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	3
	push	2
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	1
	push	2
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	2
	push	2
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	3
	push	2
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	1
	push	2
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	2
	push	2
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	3
	push	2
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	1
	push	2
	push	1
	push	2
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	push	eax		 ; empile le résultat
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	push	eax		 ; empile le résultat
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	1
	push	2
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	push	eax		 ; empile le résultat
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	1
	push	2
	push	2
	push	2
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	push	eax		 ; empile le résultat
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	push	eax		 ; empile le résultat
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	push	eax		 ; empile le résultat
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	28
	push	10
	push	120
	push	20
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	add	eax, ebx		 ; effectue l'opération
	push	eax		 ; empile le résultat
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	idiv	ebx		 ; effectue l'opération
	push	eax		 ; empile le résultat
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	imul	ebx		 ; effectue l'opération
	push	eax		 ; empile le résultat
	push	2
	push	3
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	imul	ebx		 ; effectue l'opération
	push	eax		 ; empile le résultat
	push	57
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	add	eax, ebx		 ; effectue l'opération
	push	eax		 ; empile le résultat
	push	24
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	sub	eax, ebx		 ; effectue l'opération
	push	eax		 ; empile le résultat
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	push	eax		 ; empile le résultat
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	mov	eax, 1		 ; 1 est le code de SYS_EXIT
	int	0x80		 ; exit
