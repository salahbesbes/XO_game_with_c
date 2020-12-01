# A simple Makefile for compiling small SDL projects

# set the compiler
CC := gcc

# set the compiler flags
CFLAGS := `sdl2-config --libs --cflags` -ggdb3 -O0 --std=c99  -Wall
# add header files here
HDRS := ./header.h
LIBS =  -lSDL2 -lm -lSDL2_image  -lSDL2_gfx
# add source files here
SRCS := ./main.c ./renderGame.c ./logic.c

# generate names of object files
OBJS := $(SRCS:.c=.o)

# name of executable
EXEC := ./a.out

# default recipe
all: $(EXEC)

showfont: showfont.c Makefile
	$(CC) -o $@ $@.c $(CFLAGS) $(LIBS)

glfont: glfont.c Makefile
	$(CC) -o $@ $@.c $(CFLAGS) $(LIBS)

$(EXEC): $(SRCS)
	$(CC) $(SRCS) $(CFLAGS) -o $(EXEC) $(LIBS)
# recipe for building the final executable
#$(EXEC): $(OBJS) $(HDRS) Makefile
#	$(CC) -o $@ $(OBJS) $(CFLAGS) $(LIBS)
#	rm  $(OBJS)


# recipe for building object files
#$(OBJS): $(@:.o=.c) $(HDRS) Makefile
#	$(CC) -o $@ $(@:.o=.c) -c $(CFLAGS)

# recipe to clean the workspace
clean:
	rm -f $(EXEC) $(OBJS)

.PHONY: all clean
