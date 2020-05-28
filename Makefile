IDIR = ../include
CC=clang
CFLAGS=-I$(IDIR) -Wall -Iinclude -Wextra -Wpedantic -Werror -pedantic -std=c17 -O2 -fno-stack-protector

OBJS = ./src/main.c ./src/menu.c ./src/crud.c ./src/info.c 
OBJ_NAME = main

all: $(OBJS) 
	 $(CC) $(OBJS) $(CFLAGS) -o $(OBJ_NAME)
