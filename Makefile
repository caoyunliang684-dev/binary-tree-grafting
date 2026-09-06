
CC= gcc
CFLAGS = -Wall -std=c17 -pedantic -Wfatal-errors
OBJ= arbres_binaires.o greffe.o saage.o main.o dot.o



arbres_binaires.o: arbres_binaires.c arbres_binaires.h
	$(CC) $(CFLAGS) -c arbres_binaires.c

greffe.o: greffe.c greffe.h arbres_binaires.h
	$(CC) $(CFLAGS) -c greffe.c

saage.o: saage.c saage.h arbres_binaires.h
	$(CC) $(CFLAGS) -c saage.c

dot.o : dot.c saage.h
	$(CC) $(CFLAGS) -c dot.c

main.o: main.c arbres_binaires.h greffe.h saage.h
	$(CC) $(CFLAGS) -c main.c
main: $(OBJ)
	$(CC) $(CFLAGS) -o arbre $(OBJ)
clean:
	rm -f *.o main
