%include	'io.asm'

section	.bss
sinput:	resb	255	;reserve a 255 byte space in memory for the users input string

section	.text
global _start
_start:
	loop1 :
	mov	eax, sinput		 ; empile l'adresse de la chaine de caractère
	call	readline		 ; lire une chaine de caractère
	call	atoi		 ; converti la chaine de caractère en entier
	push	eax		 ; empile le résultat
	push	2
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	cdq		 ; Étendre le signe du dividende à EDX
	idiv	ebx		 ; effectue l'opération %
	mov	eax, edx		 ; déplace le reste dans eax
	push	eax		 ; empile le résultat
	push	0
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	cmp	eax, ebx
	setne	al		 ; DIFF
	movzx	eax, al
	push	eax		 ; empile le résultat
	je	endloop1
	push	0
	pop	eax
	call	iprintLF
	jmp	loop1
	endloop1 :
	push	1
	pop	eax
	call	iprintLF
	mov	eax, 1		 ; 1 est le code de SYS_EXIT
	mov	ebx, 0
	int	0x80		 ; exit
