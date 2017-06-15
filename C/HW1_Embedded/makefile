myBitApp : main.o bits.o
	   gcc -o myBitApp main.o bits.o

main.o : main.c bits.h
	gcc -c main.c

bits.o : bits.c bits.h
	gcc -c bits.c

clean : 
	rm myBitApp main.o bits.o
	echo Clean done
