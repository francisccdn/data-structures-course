#### diretorios com os source files e com os objs files
SRCDIR = src
OBJDIR = obj
#############################

#### lista de todos os srcs e todos os objs
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
#############################

linkedlist: $(OBJS)
	@echo  "\033[31m \nLinking all objects files: \033[0m"
	gcc $(OBJS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo  "\033[31m \nCompiling $<: \033[0m"
	gcc -c $< -o $@

clean:
	@echo "\033[31mCleaning obj directory \033[0m"
	@rm -f $(OBJDIR)/*.o
	@echo "\033[31mCleaning executable \033[0m"
	@rm linkedlist
