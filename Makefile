SRC=read.s\
		strcmp.s\
		strcpy.s\
		strdup.s\
		strlen.s\
		write.s

OBJ= $(SRC:%.s=%.o)

CSRC = main.c

ASM=nasm

ASMFLAGS=-f elf64

NAME = libasm.a

EXE = my_exec

LIB = ar rcs

all: lib $(EXE)

lib: $(NAME)

$(EXE):
	gcc -Wall -Wextra -Werror main.c $(NAME) -o $(EXE)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)
	rm $(OBJ)
%.o: %.s
	$(ASM) $(ASMFLAGS) $^

clean:
	rm $(NAME)

fclean: clean
	rm $(EXE)

re : fclean
	make all
