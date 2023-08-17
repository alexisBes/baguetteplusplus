OUTDIR=./bin
MKDIR_P = mkdir -p
CC=g++
CFLAGS=-W -Wall -ansi -pedantic -std=c++11
OBJ= $(SRC:.c=.o)

all: directories bpp

directories: ${OUTDIR}

${OUTDIR} :	
	${MKDIR_P} ${OUTDIR}

ListUtils.cpp : ListUtils.h

bpp: ListUtils.cpp
	gcc -o ${OUTDIR}/$@ $^ $(CFLAGS)

%.o: %.cpp	
	$(CC) -o $@ -c $< $(CFLAGS)