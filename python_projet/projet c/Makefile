INPUT = exemple exemple1 exemple2 arith_1 arith_2 arith_3 arith_4 arith_5 arith_6 boucle_1 boucle_2 comp eval_lexicale eval_syntaxique fibo fonction_1 fonction_2 fonction_3 fonction_4 fonction_5 fonction_6 fonction_7 fonction_8 fonction_9 fonction_10 fonction_11 fonction_12 fonction_13 lire log priorite #si #variable
#INPUT = $(basename $(notdir $(wildcard input/*.flo)))
#INPUT = log

assembleur_vers_exercutable: generation_code_nasm main
	for a in $(INPUT); do echo "Assemblage: " $${a}; nasm -f elf -g -F dwarf output/$${a}.nasm; ld -m elf_i386 -o output/$${a} output/$${a}.o; rm output/$${a}.o; done;
#for a in $(INPUT); do echo "Assemblage: " $${a}; nasm -f elf -g -F dwarf output/$${a}.nasm; ld -m elf_i386 -o output/$${a} output/$${a}.o; rm output/$${a}.o; rm output/$${a}.nasm; done;

generation_code_nasm:
	for a in $(INPUT); do echo "Generation code nasm: " $${a}; ./main -n input/$${a}.flo > output/$${a}.nasm; done;

main: analyse_lexicale analyse_syntaxique
	gcc -Wall main.c analyse_lexicale.c analyse_syntaxique.c arbre_abstrait.c generation_code.c -o main

analyse_syntaxique :
	bison analyse_syntaxique.y --defines=symboles.h -o analyse_syntaxique.c

analyse_lexicale:
	flex -o analyse_lexicale.c analyse_lexicale.l

test:
	./main -a input/exemple1.flo