#objects specifies which files to compile as part of the project
objects = 1 2 3 4 5 6

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
CFLAGS = -w

#This is the target that compiles our executable
all: $(objects)

$(objects): %: %.cpp
	$(CC) $(CFLAGS) -o $@ $<