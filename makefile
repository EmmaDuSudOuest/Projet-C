all : COMPIL EXECUTION


modeFacile.o : modeFacile.c fonctions.h
	gcc -c -Wall modeFacile.c -std=c99

obusAtom.o : obus.c fonctions.h
	gcc -c -Wall obus.c -std=c99

matrices.o : matrices.c fonctions.h
	gcc -c -Wall matrices.c -std=c99

menuAtom.o : menu.c fonctions.h
	gcc -c -Wall menu.c -std=c99

tankAtom.o : tank.c fonctions.h
	gcc -c -Wall tank.c -std=c99

mainAtom.o : main.c fonctions.h
	gcc -c -Wall main.c -std=c99


COMPIL : modeFacile.o mainAtom.o obusAtom.o matricesAtom.o menuAtom.o tankAtom.o
	gcc -o COMPIL modeFacile.o mainAtom.o obusAtom.o matricesAtom.o menuAtom.o tankAtom.o

EXECUTION :
	./COMPIL
