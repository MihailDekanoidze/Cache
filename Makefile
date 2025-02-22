CFLAGS = -fdiagnostics-generate-patch -fdiagnostics-path-format=inline-events  \
 -pg -ggdb -std=c++17 -Wall -Wextra -Weffc++ -Waggressive-loop-optimizations   \
-Wc++14-compat -Wuseless-cast -Wmissing-declarations -Wcast-align -Wcast-qual \
-Wchar-subscripts -Wconditionally-supported -Wconversion -Wctor-dtor-privacy  \
-Wempty-body -Wfloat-equal -Wformat-nonliteral -Wformat-security              \
-Wformat-signedness -Wformat=2 -Winline -Wlogical-op -Wnon-virtual-dtor       \
-Wopenmp-simd -Woverloaded-virtual -Wpacked -Wpointer-arith -Winit-self       \
-Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo                     \
-Wstrict-null-sentinel -Wstrict-overflow=2 -Wsuggest-attribute=noreturn       \
-Wsuggest-final-methods -Wsuggest-final-types -Wsuggest-override              \
-Wswitch-default -Wswitch-enum -Wsync-nand -Wundef -Wunreachable-code         \
-Wunused -Wvariadic-macros -Wno-literal-suffix                                \
-Wno-missing-field-initializers -Wno-narrowing -Wno-old-style-cast            \
-Wno-varargs -Wstack-protector -fcheck-new -fsized-deallocation               \
-fstack-protector -fstrict-overflow -flto-odr-type-merging                    \
-fno-omit-frame-pointer -Wstack-usage=8192                                    \
-fsanitize=address,bool,bounds,enum,float-cast-overflow,$\
float-divide-by-zero,integer-divide-by-zero,leak,nonnull-attribute,null,$\
object-size,return,returns-nonnull-attribute,shift,signed-integer-overflow,$\
undefined,unreachable,vla-bound,vptr


ifeq ($(origin CC), default)
	CC = g++
endif

CFLAGS ?= -O0 

OBJ_DIR    = Apps
SOURCE_DIR = source
EXECUTABLE = lfu
INCL_DIR   = include
SUBDIRS    = . SOURCE_DIR

MAKEFLAGS += --no-print-directory

#ALL_CPP = main.cpp source/Triangle.cpp

#.PHONY: all Triangle_Proc clean run $(OBJECTS) test
#OBJECTS := $(notdir $(patsubst %.cpp, %.o, $(ALL_CPP)))
#SOURCES = source/%.o

SOURCES := LFU.o
OBJECTS := $(SOURCES: %.cpp=%.o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	@$(CC) $^ -o $@ $(LDFLAGS)    

clean:
	@rm -rf *.o
	@rm $(EXECUTABLE)

run:
	@./$(EXECUTABLE)

NODEPS = clean