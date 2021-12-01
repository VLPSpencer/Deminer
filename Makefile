SRC = $(wildcard *.c) #fichiers sources
OBJ = $(SRC:.c=.o)	  #fichiers objets

exe : $(OBJ)
	@gcc -Wall $^ -o $@ -lm

.c.o : 
	gcc -Wall -c $^ -o $@ -lm

.PHONY : clean

clean :				#effacement des objets
	rm -f $(OBJ)
