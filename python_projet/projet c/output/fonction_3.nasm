%include	'io.asm'

section	.bss
sinput:	resb	255	;reserve a 255 byte space in memory for the users input string

section	.text
global _start
	_g:		 ; declaration de fonction
;6
;fonction a l'index 0
;Ajout du symbole g
;Ajout du symbole h
;1
;0
;Ajout du symbole g
;Ajout du symbole h
Erreur : type de retour de fonction incorrect