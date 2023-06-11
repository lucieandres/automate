%include	'io.asm'

section	.bss
sinput:	resb	255	;reserve a 255 byte space in memory for the users input string

section	.text
global _start
_start:
	push	1		 ; VRAI
	pop	eax
	cmp	eax, 1
	je	si1
	jmp	endsi1
	si1 :
	push	1
	pop	eax
	call	iprintLF
	endsi1 :
	push	0		 ; FAUX
	pop	eax
	cmp	eax, 1
	je	si2
	push	2
	pop	eax
	call	iprintLF
	jmp	endsi2
	si2 :
	push	0
	pop	eax
	call	iprintLF
	endsi2 :
	push	1		 ; VRAI
	pop	eax
	cmp	eax, 1
	je	si3
	push	0
	pop	eax
	call	iprintLF
	jmp	endsi3
	si3 :
	push	3
	pop	eax
	call	iprintLF
	endsi3 :
	push	0		 ; FAUX
	pop	eax
	cmp	eax, 1
	je	si4
	push	0		 ; FAUX
	pop	eax
	cmp	eax, 1
	je	si5
	jmp	endsi5
	si5 :
	push	0
	pop	eax
	call	iprintLF
	endsi5 :
	jmp	endsi4
	si4 :
	push	0
	pop	eax
	call	iprintLF
	endsi4 :
	push	0		 ; FAUX
	pop	eax
	cmp	eax, 1
	je	si6
	push	1		 ; VRAI
	pop	eax
	cmp	eax, 1
	je	si7
	jmp	endsi7
	si7 :
	push	4
	pop	eax
	call	iprintLF
	endsi7 :
	jmp	endsi6
	si6 :
	push	0
	pop	eax
	call	iprintLF
	endsi6 :
	push	1		 ; VRAI
	pop	eax
	cmp	eax, 1
	je	si8
	push	0		 ; FAUX
	pop	eax
	cmp	eax, 1
	je	si9
	jmp	endsi9
	si9 :
	push	0
	pop	eax
	call	iprintLF
	endsi9 :
	jmp	endsi8
	si8 :
	push	5
	pop	eax
	call	iprintLF
	endsi8 :
	push	1		 ; VRAI
	pop	eax
	cmp	eax, 1
	je	si10
	push	1		 ; VRAI
	pop	eax
	cmp	eax, 1
	je	si11
	jmp	endsi11
	si11 :
	push	0
	pop	eax
	call	iprintLF
	endsi11 :
	jmp	endsi10
	si10 :
	push	6
	pop	eax
	call	iprintLF
	endsi10 :
	push	0		 ; FAUX
	pop	eax
	cmp	eax, 1
	je	si12
	push	0		 ; FAUX
	pop	eax
	cmp	eax, 1
	je	si13
	push	7
	pop	eax
	call	iprintLF
	jmp	endsi13
	si13 :
	push	0
	pop	eax
	call	iprintLF
	endsi13 :
	jmp	endsi12
	si12 :
	push	0
	pop	eax
	call	iprintLF
	endsi12 :
	push	0		 ; FAUX
	pop	eax
	cmp	eax, 1
	je	si14
	push	1		 ; VRAI
	pop	eax
	cmp	eax, 1
	je	si15
	push	0
	pop	eax
	call	iprintLF
	jmp	endsi15
	si15 :
	push	8
	pop	eax
	call	iprintLF
	endsi15 :
	jmp	endsi14
	si14 :
	push	0
	pop	eax
	call	iprintLF
	endsi14 :
	push	1		 ; VRAI
	pop	eax
	cmp	eax, 1
	je	si16
	push	0		 ; FAUX
	pop	eax
	cmp	eax, 1
	je	si17
	push	0
	pop	eax
	call	iprintLF
	jmp	endsi17
	si17 :
	push	0
	pop	eax
	call	iprintLF
	endsi17 :
	jmp	endsi16
	si16 :
	push	9
	pop	eax
	call	iprintLF
	endsi16 :
	push	1		 ; VRAI
	pop	eax
	cmp	eax, 1
	je	si18
	push	1		 ; VRAI
	pop	eax
	cmp	eax, 1
	je	si19
	push	0
	pop	eax
	call	iprintLF
	jmp	endsi19
	si19 :
	push	0
	pop	eax
	call	iprintLF
	endsi19 :
	jmp	endsi18
	si18 :
	push	10
	pop	eax
	call	iprintLF
	endsi18 :
	push	1		 ; VRAI
	pop	eax
	cmp	eax, 1
	je	si20
	push	1		 ; VRAI
	pop	eax
	cmp	eax, 1
	je	si21
	push	1		 ; VRAI
	pop	eax
	cmp	eax, 1
	je	si22
	push	0
	pop	eax
	call	iprintLF
	jmp	endsi22
	si22 :
	push	0
	pop	eax
	call	iprintLF
	endsi22 :
	jmp	endsi21
	si21 :
	push	0
	pop	eax
	call	iprintLF
	endsi21 :
	jmp	endsi20
	si20 :
	push	11
	pop	eax
	call	iprintLF
	endsi20 :
	push	0		 ; FAUX
	pop	eax
	cmp	eax, 1
	je	si23
	push	1		 ; VRAI
	pop	eax
	cmp	eax, 1
	je	si24
	push	1		 ; VRAI
	pop	eax
	cmp	eax, 1
	je	si25
	push	0
	pop	eax
	call	iprintLF
	jmp	endsi25
	si25 :
	push	0
	pop	eax
	call	iprintLF
	endsi25 :
	jmp	endsi24
	si24 :
	push	12
	pop	eax
	call	iprintLF
	endsi24 :
	jmp	endsi23
	si23 :
	push	0
	pop	eax
	call	iprintLF
	endsi23 :
	push	0		 ; FAUX
	pop	eax
	cmp	eax, 1
	je	si26
	push	0		 ; FAUX
	pop	eax
	cmp	eax, 1
	je	si27
	push	1		 ; VRAI
	pop	eax
	cmp	eax, 1
	je	si28
	push	0
	pop	eax
	call	iprintLF
	jmp	endsi28
	si28 :
	push	13
	pop	eax
	call	iprintLF
	endsi28 :
	jmp	endsi27
	si27 :
	push	0
	pop	eax
	call	iprintLF
	endsi27 :
	jmp	endsi26
	si26 :
	push	0
	pop	eax
	call	iprintLF
	endsi26 :
	push	0		 ; FAUX
	pop	eax
	cmp	eax, 1
	je	si29
	push	0		 ; FAUX
	pop	eax
	cmp	eax, 1
	je	si30
	push	0		 ; FAUX
	pop	eax
	cmp	eax, 1
	je	si31
	push	14
	pop	eax
	call	iprintLF
	jmp	endsi31
	si31 :
	push	0
	pop	eax
	call	iprintLF
	endsi31 :
	jmp	endsi30
	si30 :
	push	0
	pop	eax
	call	iprintLF
	endsi30 :
	jmp	endsi29
	si29 :
	push	0
	pop	eax
	call	iprintLF
	endsi29 :
	push	0		 ; FAUX
	pop	eax
	cmp	eax, 1
	je	si32
	push	0		 ; FAUX
	pop	eax
	cmp	eax, 1
	je	si33
	push	0		 ; FAUX
	pop	eax
	cmp	eax, 1
	je	si34
	jmp	endsi34
	si34 :
	push	0
	pop	eax
	call	iprintLF
	endsi34 :
	jmp	endsi33
	si33 :
	push	0
	pop	eax
	call	iprintLF
	endsi33 :
	jmp	endsi32
	si32 :
	push	0
	pop	eax
	call	iprintLF
	endsi32 :
	mov	eax, 1		 ; 1 est le code de SYS_EXIT
	mov	ebx, 0
	int	0x80		 ; exit
