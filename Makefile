SRC=read.s\
		strcmp.s\
		strcpy.s\
		strdup.s\
		strlen.s\
		write.s

OBJ= $(SRC:%.s=obj/%.o)

OBJDIR = obj

CSRC = main.c

ASMT=nasm

ASMFLAGS=-f elf64

NAME = libasm.a

EXE = my_exec

LIB = ar rcs

all: lib $(EXE)

lib: $(OBJDIR) $(NAME)

$(EXE): $(CSRC) $(NAME)
	gcc -Wall -Wextra -Werror $(CSRC) $(NAME) -o $(EXE)

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)

$(OBJDIR)/%.o: %.s
	$(ASMT) $(ASMFLAGS) -o $@ $<

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm -f $(NAME)
	rm -fr $(OBJDIR)

fclean: clean
	rm -f $(EXE)

re : fclean
	make all
