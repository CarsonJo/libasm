SRC=read.s\
		strcmp.s\
		strcpy.s\
		strdup.s\
		strlen.s\
		write.s
OBJ= $(SRC:%.s=%.o)

ASM=nasm

ASMFLAGS=-f elf64

NAME = libasm.a

LIB = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)
	rm $(OBJ)
%.o: %.s
	$(ASM) $(ASMFLAGS) $^
clean:
	rm $(NAME)
fclean: clean
	rm $(NAME)
re : fclean
	make all
