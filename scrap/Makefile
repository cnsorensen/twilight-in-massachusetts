# Makefile

# C++ compiler and linker
CC := g++
LD := g++
CXXFLAGS = -Wall -O -g

# OpenGL libraries
GL_LIBS = -lglut -lGLU -lGL -lm

SRC_DIR := src
BUILD_DIR := build

#SOURCE_FILES = main.cpp globals.cpp callbacks.cpp game.cpp person.cpp persons.cpp place.cpp places.cpp plot.cpp

SRC := $(foreach sdir,$(SRC_DIR),$(wildcard $(sdir)/*.cpp))
OBJ := $(patsubst src/%.cpp,build/%.o,$(SRC))
INCLUDES := $(addprefix -I,$(SRC_DIR))

vpath %.cpp $(SRC_DIR)

define make-goal
$1/%.o: %.cpp
	$(CC) $(INCLUDES) -c $$< -o $$@ $(CXXFLAGS)
endef

.PHONY: all checkdirs clean

all: checkdirs build/cs-twilightinmass

build/cs-twilightinmass: $(OBJ)
	$(LD) $^ -o $@ $(GL_LIBS) $(CXXFLAGS)
	rm -f cs-twilightinmass
	ln -s $@ cs-twilightinmass

checkdirs: $(BUILD_DIR)

$(BUILD_DIR):
	@mkdir -p $@

clean:
	rm -rf $(BUILD_DIR) cs-twilightinmass

$(foreach bdir,$(BUILD_DIR),$(eval $(call make-goal,$(bdir))))
