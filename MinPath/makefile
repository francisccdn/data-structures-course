MAIN = graph

SRCDIR = src
OBJDIR = obj

SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

CCFLAGS = -O3

$(MAIN): $(OBJS)
	@echo  "\033[31m \nLinking all objects files: \033[0m"
	gcc $(OBJS) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo  "\033[31m \nCompiling $<: \033[0m"
	gcc -c $< -o $@ $(CCFLAGS) -Wno-unused-result

debug: CCFLAGS = -O0 -g3
debug: $(MAIN)

clean:
	@echo "\033[31mCleaning obj directory \033[0m"
	@rm -f $(OBJDIR)/*.o
	@echo "\033[31mCleaning executable \033[0m"
	@rm $(MAIN)