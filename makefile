all : COMPIL EXECUTION


modeFacileAtom.o : modeFacileAtom.c fonctionsAtom.h
	gcc -c -Wall modeFacileAtom.c -std=c99

obusAtom.o : obusAtom.c fonctionsAtom.h
	gcc -c -Wall obusAtom.c -std=c99

matricesAtom.o : matricesAtom.c fonctionsAtom.h
	gcc -c -Wall matricesAtom.c -std=c99

menuAtom.o : menuAtom.c fonctionsAtom.h
	gcc -c -Wall menuAtom.c -std=c99

tankAtom.o : tankAtom.c fonctionsAtom.h
	gcc -c -Wall tankAtom.c -std=c99


mainAtom.o : mainAtom.c fonctionsAtom.h
	gcc -c -Wall mainAtom.c -std=c99


COMPIL : modeFacileAtom.o mainAtom.o obusAtom.o matricesAtom.o menuAtom.o tankAtom.o
	gcc -o COMPIL modeFacileAtom.o mainAtom.o obusAtom.o matricesAtom.o menuAtom.o tankAtom.o

EXECUTION :
	./COMPIL
