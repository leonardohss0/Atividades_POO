CC=g++
FILE=main.cpp
INCLUDE=./src/*
HEADERS=./include

FLAGS=
FLAGS1=

build: main 
	@echo "Compiled"

main: $(FILE)
	@$(CC) $(FLAGS) $(FLAGS1) -I $(HEADERS) $^ $(INCLUDE) -o main.out

run: 
	@./main.out

clean:
	@rm *.out
	@echo "Cleaned up successfully :)"
