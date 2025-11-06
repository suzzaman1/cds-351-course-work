# Compiler setup
CC       = gcc
CXX      = g++
MPICXX   = mpicxx

RM       = rm -f
RMR      = rm -rf

# Flags
COPT     = -O2
STDCXX20 = -std=c++20
PTHREAD  = -pthread
OMP      = -fopenmp

CXXFLAGS_BASE = -g $(COPT) \
	-Wpedantic \
	-Wformat=2 \
	-Wshadow \
	-Wwrite-strings \
	-Werror \
	-Wredundant-decls \
	-Wmissing-include-dirs

MPICXXFLAGS_BASE = $(CXXFLAGS_BASE)

ifeq ($(shell uname -s), Darwin)
  CXXFLAGS_BASE += -Wl,-w
endif

CXXFLAGS    = $(STDCXX20) $(CXXFLAGS_BASE)
MPICXXFLAGS = $(STDCXX20) $(MPICXXFLAGS_BASE)

BIN_DIR = bin

# Source files (exclude Python, CSV, etc.)
SRCS := $(filter-out %.py %.csv, $(wildcard *.cpp))
EXES := $(patsubst %.cpp,%.x,$(SRCS))

# ---------------------------------------------------------------------------
# Explicit pattern rules — order matters (MPI first)
# ---------------------------------------------------------------------------

# --- MPI ---
mpi_%.x: mpi_%.cpp
	@echo "Building MPI program: $@"
	$(MPICXX) $(MPICXXFLAGS) -o $@ $<

# --- OpenMP ---
omp_%.x: omp_%.cpp
	@echo "Building OpenMP program: $@"
	$(CXX) $(CXXFLAGS_BASE) $(STDCXX20) $(OMP) -o $@ $<

# --- POSIX Threads ---
pthread_%.x: pthread_%.cpp
	@echo "Building Pthread program: $@"
	$(CXX) $(CXXFLAGS_BASE) $(STDCXX20) $(PTHREAD) -o $@ $<

# --- C++ std::thread ---
thread_%.x: thread_%.cpp
	@echo "Building std::thread program: $@"
	$(CXX) $(CXXFLAGS_BASE) $(STDCXX20) $(PTHREAD) -o $@ $<

# --- Default: plain serial C++ ---
%.x: %.cpp
	@echo "Building serial program: $@"
	$(CXX) $(CXXFLAGS) -o $@ $<

# ---------------------------------------------------------------------------
# Meta targets
# ---------------------------------------------------------------------------

all: $(EXES)
	@mkdir -p $(BIN_DIR)
	@echo "Installing executables into $(BIN_DIR)/"
	@cp $(EXES) $(BIN_DIR)

.PHONY: clean distclean all

clean:
	$(RM) *.o *.x

distclean: clean
	$(RMR) $(BIN_DIR) *.dSYM *~
