%include	'io.asm'

section	.bss
sinput:	resb	255	;reserve a 255 byte space in memory for the users input string

section	.text
global _start
_start:
	push	0		 ; FAUX
	pop	eax
	call	iprintLF
	push	1		 ; VRAI
	pop	eax
	call	iprintLF
	push	0		 ; FAUX
	pop	eax
	xor	eax, 1		 ; NOT
	push	eax
	pop	eax
	call	iprintLF
	push	1		 ; VRAI
	pop	eax
	xor	eax, 1		 ; NOT
	push	eax
	pop	eax
	call	iprintLF
	push	0		 ; FAUX
	push	0		 ; FAUX
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	or	eax, ebx		 ; OU
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	0		 ; FAUX
	push	1		 ; VRAI
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	or	eax, ebx		 ; OU
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	1		 ; VRAI
	push	0		 ; FAUX
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	or	eax, ebx		 ; OU
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	1		 ; VRAI
	push	1		 ; VRAI
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	or	eax, ebx		 ; OU
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	0		 ; FAUX
	push	0		 ; FAUX
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	and	eax, ebx		 ; ET
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	0		 ; FAUX
	push	1		 ; VRAI
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	and	eax, ebx		 ; ET
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	1		 ; VRAI
	push	0		 ; FAUX
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	and	eax, ebx		 ; ET
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	1		 ; VRAI
	push	1		 ; VRAI
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	and	eax, ebx		 ; ET
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	0		 ; FAUX
	push	0		 ; FAUX
	pop	eax
	xor	eax, 1		 ; NOT
	push	eax
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	and	eax, ebx		 ; ET
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	0		 ; FAUX
	push	1		 ; VRAI
	pop	eax
	xor	eax, 1		 ; NOT
	push	eax
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	and	eax, ebx		 ; ET
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	1		 ; VRAI
	push	0		 ; FAUX
	pop	eax
	xor	eax, 1		 ; NOT
	push	eax
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	and	eax, ebx		 ; ET
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	1		 ; VRAI
	push	1		 ; VRAI
	pop	eax
	xor	eax, 1		 ; NOT
	push	eax
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	and	eax, ebx		 ; ET
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	0		 ; FAUX
	pop	eax
	xor	eax, 1		 ; NOT
	push	eax
	push	0		 ; FAUX
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	and	eax, ebx		 ; ET
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	0		 ; FAUX
	pop	eax
	xor	eax, 1		 ; NOT
	push	eax
	push	1		 ; VRAI
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	and	eax, ebx		 ; ET
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	1		 ; VRAI
	pop	eax
	xor	eax, 1		 ; NOT
	push	eax
	push	0		 ; FAUX
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	and	eax, ebx		 ; ET
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	1		 ; VRAI
	pop	eax
	xor	eax, 1		 ; NOT
	push	eax
	push	1		 ; VRAI
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	and	eax, ebx		 ; ET
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	push	0		 ; FAUX
	push	0		 ; FAUX
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	and	eax, ebx		 ; ET
	push	eax		 ; empile le résultat
	pop	eax
	xor	eax, 1		 ; NOT
	push	eax
	pop	eax
	call	iprintLF
	push	0		 ; FAUX
	push	1		 ; VRAI
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	and	eax, ebx		 ; ET
	push	eax		 ; empile le résultat
	pop	eax
	xor	eax, 1		 ; NOT
	push	eax
	pop	eax
	call	iprintLF
	push	1		 ; VRAI
	push	0		 ; FAUX
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	and	eax, ebx		 ; ET
	push	eax		 ; empile le résultat
	pop	eax
	xor	eax, 1		 ; NOT
	push	eax
	pop	eax
	call	iprintLF
	push	1		 ; VRAI
	push	1		 ; VRAI
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	and	eax, ebx		 ; ET
	push	eax		 ; empile le résultat
	pop	eax
	xor	eax, 1		 ; NOT
	push	eax
	pop	eax
	call	iprintLF
	mov	eax, 1		 ; 1 est le code de SYS_EXIT
	mov	ebx, 0
	int	0x80		 ; exit
