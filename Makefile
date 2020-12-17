# Makefiles
CC = gcc
cc_FLAGS = -g -ansi -pedantic -Wall
OUT_EXE = main
FILES = dice_A.c main.c

partA: $(FILES)
	$(CC) $(CC_FLAGS) -o $(OUT_EXE) $(FILES)

main.o : dice_A.h
main.c : dice_A.h
dice_A.c : dice_A.h