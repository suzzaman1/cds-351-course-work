CC = gcc
CXX = g++
RM = rm -f
RMR = rm -rf

# Default: debug build
COPT ?= -O0
CXXFLAGS_BASE = -g -std=c++20 $(COPT) \
      -Wall \
      -Wextra \
      -Wpedantic \
      -Wformat=2 \
      -Wshadow \
      -Wwrite-strings \
      -Wconversion \
      -Werror \
      -Wredundant-decls \
      -Wmissing-include-dirs
      # -Wno-unused-parameter \

# If OPTIM=yes, override flags for optimized build
ifeq ($(OPTIM),yes)
  COPT := -O3
  CXXFLAGS_BASE := -std=c++20 $(COPT) \
      -DNDEBUG \
      -Wall \
      -Wextra \
      -Wpedantic \
      -Wformat=2 \
      -Wshadow \
      -Wwrite-strings \
      -Wconversion \
      -Werror \
      -Wredundant-decls \
      -Wmissing-include-dirs
  $(info Building with optimization flags ($(COPT)))
else
  $(info Building with debug flags ($(COPT)))
endif

ifndef ARCH
  ARCH := $(shell uname -s)
endif

ifeq ($(ARCH), Darwin)
  CXXFLAGS_BASE += -Wl,-w
endif

CXXFLAGS = $(CXXFLAGS_BASE)

ifeq ($(CXX),g++)
  CXXFLAGS += -Wlogical-op
endif

BIN_DIR = bin

EXCLUDE_SRCS := 
SRCS_ALL := $(shell find . -name '*.cpp' | sort -k 1nr | cut -f2-)
SRCS = $(filter-out $(EXCLUDE_SRCS), $(SRCS_ALL))

EXE = $(subst .cpp,.x,$(SRCS))

all: $(EXE)
	@mkdir -p $(BIN_DIR)
	@echo 'Installing...' $(EXE)
	@cp $(EXE) $(BIN_DIR)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

%.x: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS)

.PHONY: clean distclean all

clean:
	$(RM) *.o

distclean: clean
	$(RMR) $(BIN_DIR) *.dSYM *.[dox] *~
