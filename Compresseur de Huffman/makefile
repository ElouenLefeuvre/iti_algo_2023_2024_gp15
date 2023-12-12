SRCDIR=src
LIBDIR=lib
BINDIR=bin
INCLUDEDIR=include
TESTDIR=tests
CC = gcc
AR = ar
CFLAGS=-Wall -pedantic -g -std=c99  -I$(INCLUDEDIR)  
LDFLAGS=-lm -lcurses 
EXEC=compresseurHuffman

all :  $(BINDIR)/$(EXEC)

tests : $(TESTDIR)/%.o : $(TESTDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(BINDIR)/$(EXEC) : $(SRCDIR)/main.o $(SRCDIR)/ArbreHuffman.o $(SRCDIR)/CodeBinaire.o $(SRCDIR)/FileDePriorite.o $(SRCDIR)/Octet.o $(SRCDIR)/Statistiques.o $(SRCDIR)/TableDeCodage.o
	$(CC)  -o $@ $< $(LDFLAGS)

$(SRCDIR)/%.o : $(SRCDIR)/%.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean :
	rm -rf $(BINDIR)/*
	rm -rf $(SRCDIR)/*.o
	rm -rf $(TESTDIR)/*