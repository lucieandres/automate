%include	'io.asm'

section	.bss
sinput:	resb	255	;reserve a 255 byte space in memory for the users input string

section	.text
global _start
_start:
	mov	eax, sinput		 ; empile l'adresse de la chaine de caractère
	call	readline		 ; lire une chaine de caractère
	call	atoi		 ; converti la chaine de caractère en entier
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	mov	eax, sinput		 ; empile l'adresse de la chaine de caractère
	call	readline		 ; lire une chaine de caractère
	call	atoi		 ; converti la chaine de caractère en entier
	push	eax		 ; empile le résultat
	mov	eax, sinput		 ; empile l'adresse de la chaine de caractère
	call	readline		 ; lire une chaine de caractère
	call	atoi		 ; converti la chaine de caractère en entier
	push	eax		 ; empile le résultat
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	imul	ebx		 ; effectue l'opération *
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	mov	eax, sinput		 ; empile l'adresse de la chaine de caractère
	call	readline		 ; lire une chaine de caractère
	call	atoi		 ; converti la chaine de caractère en entier
	push	eax		 ; empile le résultat
	mov	eax, sinput		 ; empile l'adresse de la chaine de caractère
	call	readline		 ; lire une chaine de caractère
	call	atoi		 ; converti la chaine de caractère en entier
	push	eax		 ; empile le résultat
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	add	eax, ebx		 ; effectue l'opération +
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	mov	eax, sinput		 ; empile l'adresse de la chaine de caractère
	call	readline		 ; lire une chaine de caractère
	call	atoi		 ; converti la chaine de caractère en entier
	push	eax		 ; empile le résultat
	mov	eax, sinput		 ; empile l'adresse de la chaine de caractère
	call	readline		 ; lire une chaine de caractère
	call	atoi		 ; converti la chaine de caractère en entier
	push	eax		 ; empile le résultat
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	sub	eax, ebx		 ; effectue l'opération -
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	mov	eax, sinput		 ; empile l'adresse de la chaine de caractère
	call	readline		 ; lire une chaine de caractère
	call	atoi		 ; converti la chaine de caractère en entier
	push	eax		 ; empile le résultat
	push	3
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	imul	ebx		 ; effectue l'opération *
	push	eax		 ; empile le résultat
	mov	eax, sinput		 ; empile l'adresse de la chaine de caractère
	call	readline		 ; lire une chaine de caractère
	call	atoi		 ; converti la chaine de caractère en entier
	push	eax		 ; empile le résultat
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	cdq		 ; Étendre le signe du dividende à EDX
	idiv	ebx		 ; effectue l'opération /
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	mov	eax, sinput		 ; empile l'adresse de la chaine de caractère
	call	readline		 ; lire une chaine de caractère
	call	atoi		 ; converti la chaine de caractère en entier
	push	eax		 ; empile le résultat
	push	5
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	add	eax, ebx		 ; effectue l'opération +
	push	eax		 ; empile le résultat
	mov	eax, sinput		 ; empile l'adresse de la chaine de caractère
	call	readline		 ; lire une chaine de caractère
	call	atoi		 ; converti la chaine de caractère en entier
	push	eax		 ; empile le résultat
	pop	ebx		 ; depile la seconde operande dans ebx
	pop	eax		 ; depile la permière operande dans eax
	cdq		 ; Étendre le signe du dividende à EDX
	idiv	ebx		 ; effectue l'opération %
	mov	eax, edx		 ; déplace le reste dans eax
	push	eax		 ; empile le résultat
	pop	eax
	call	iprintLF
	mov	eax, 1		 ; 1 est le code de SYS_EXIT
	mov	ebx, 0
	int	0x80		 ; exit
