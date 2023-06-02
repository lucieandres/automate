INPUT = exemple exemple1 exemple2 arith_1 arith_2 arith_3 arith_4 arith_5 arith_6 boucle_1 boucle_2 comp eval_lexicale eval_syntaxique fibo fonction_1 fonction_2 fonction_3 fonction_4 fonction_5 fonction_6 fonction_7 fonction_8 fonction_9 fonction_10 fonction_11 fonction_12 fonction_13 lire log priorite si variable

assembleur_vers_exercutable: generation_code_nasm
	for a in $(INPUT); do echo "Assemblage: " $${a}; nasm -f elf -g -F dwarf output/$${a}.nasm; ld -m elf_i386 -o output/$${a} output/$${a}.o; rm output/$${a}.o; rm output/$${a}.nasm; done;

generation_code_nasm:
	for a in $(INPUT); do echo "Generation code nasm: " $${a}; python3 generation_code.py -nasm input/$${a}.flo > output/$${a}.nasm; done;
