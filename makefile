all : COMPIL EXECUTION



fonctionsAtom.o : fonctionsAtom.c fonctionsAtom.h

	gcc -c -Wall fonctionsAtom.c -std=c99



mainAtom.o : mainAtom.c fonctionsAtom.h

	gcc -c -Wall mainAtom.c -std=c99



COMPIL : fonctionsAtom.o mainAtom.o

	gcc -o COMPIL fonctionsAtom.o mainAtom.o



EXECUTION :

	./COMPIL
