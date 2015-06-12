PROJECT = lab3
TARGET = lab3

SRC_FILES = \
  Makefile \
  README \
  lab3.cpp

OBJ_FILES = \
  lab3.o \

CC = g++
CXXFLAGS=-O3 -std=c++0x -pg -D_DEBUG -g -c -Wall

$(TARGET):  	$(OBJ_FILES)
		$(CC) $(OBJ_FILES) -o $@

clean:
		rm -f $(TARGET) *.o *~

lab3.o:		lab3.cpp

