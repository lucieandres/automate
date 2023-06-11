%include	'io.asm'

section	.bss
sinput:	resb	255	;reserve a 255 byte space in memory for the users input string

section	.text
global _start
	_f:		 ; declaration de fonction
	push	ebp		 ; empiler ebp
	mov	ebp, esp		 ; mov ebp, esp
	mov	eax, [ebp+16]		 ; mov eax, 0
	push	0
	pop	eax
	add	esp, 16
	mov	esp, ebp
	pop	ebp
	ret		 ; retour de fonction
_start:
	push	1		 ; empiler argument
;x	push	2		 ; empiler argument
;e	push	3		 ; empiler argument
;a	push	1		 ; empiler argument
;b	call	_f		 ; appel de fonction
	add	esp, 16		 ; dépiler argument
	push	eax
	mov	eax, 1		 ; 1 est le code de SYS_EXIT
	mov	ebx, 0
	int	0x80		 ; exit
