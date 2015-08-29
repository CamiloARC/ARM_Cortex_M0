cc = gcc
CFLAGS = -O3 -c -Wall

all:	o
	rm main.o
	$(cc) -o main.exe *.o
	rm *.o	

test:	obj
	rm main.o
	$(cc) -o test.exe *.o
	rm *.o	
	
o:
	$(cc) $(CFLAGS) *.c

clean:
	rm main.exe
