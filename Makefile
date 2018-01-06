# Makefile
# Chrissy Sorensen

# C++ compiler and linker
CPP_LINK = g++
CPP_FLAGS = -Wall -O -g
CXXFLAGS = $(CPP_FLAGS)

# OpenGL libraries
GL_LIBS = -lglut -lGLU -lGL -lm

SOURCE_DIR = src
SOURCE_FILES = main.cpp globals.cpp game.cpp person.cpp persons.cpp place.cpp \
places.cpp plot.cpp


# Targets

all: cs-twilightinmass

cs-twilightinmass: $(SOURCE_FILES:.cpp=.o)
	$(CPP_LINK) $(CPP_FLAGS) -o $@ $^ $(GL_LIBS)
    
clean:
	@rm -f $(SOURCE_FILES:.cpp=.o) *~ core cs-twilightinmass
