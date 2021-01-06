###########################################
#function name: makefile
#description: this script compiles only the files you change since
#				the last compilation and links the files together to
#				make a running file named prog
###########################################

#compiler
CC = gcc
#Flags
CFLAGS =-g -Wall -std=c99
#Linker
CCLINK = $(CC)
#objects to link together
OBJS=ransom.o map.o
#Name of file
EXEC=prog
#The remove file command
RM=rm -rf

#linking
all: $(OBJS)
	$(CCLINK) $(OBJS) -o prog.exe

#objects connections

map.o: map.c map.h
	$(CC) $(CFLAGS) -c map.c
	
ransom.o: ransom.c map.c map.h
	 $(CC) $(CFLAGS) -c ransom.c
	 
#remove file
clean:
	$(RM) *.o *.exe
