CC = gcc
CFLAGS = -Wall -g

all: lab2 broker worker

lab2: lab2.o
    $(CC) $(CFLAGS) -o lab2 lab2.o

broker: broker.o
    $(CC) $(CFLAGS) -o broker broker.o

worker: worker.o
    $(CC) $(CFLAGS) -o worker worker.o

lab2.o: lab2.c
    $(CC) $(CFLAGS) -c lab2.c

broker.o: broker.c
    $(CC) $(CFLAGS) -c broker.c

worker.o: worker.c
    $(CC) $(CFLAGS) -c worker.c

clean:
    rm -f *.o lab2 broker worker
