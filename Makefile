CPPFLAGS = -g -Wall -Wextra -std=c++20
CC = g++

all: final

final: account.o crud.o menu.o task.o main.o
	@echo "Binding the <object> files and <source> into <executable>"
	@$(CC) $(CPPFLAGS) obj/account.o obj/crud.o obj/menu.o obj/task.o obj/main.o -o bin/system

main.o: src/main.cpp
	@echo "Compiling the <source>"
	@$(CC) $(CPPFLAGS) -c src/main.cpp -o obj/main.o

account.o: src/account.cpp
	@echo "Compiling the <account-class>"
	@$(CC) $(CPPFLAGS) -c src/account.cpp -o obj/account.o

crud.o: src/crud.cpp
	@echo "Compiling the <crud-module>"
	@$(CC) $(CPPFLAGS) -c src/crud.cpp -o obj/crud.o

menu.o: src/menu.cpp
	@echo "Compiling the <menu-module>"
	@$(CC) $(CPPFLAGS) -c src/menu.cpp -o obj/menu.o

task.o: src/task.cpp
	@echo "Compiling the <task-module>"
	@$(CC) $(CPPFLAGS) -c src/task.cpp -o obj/task.o

run:
	@cd bin/ && \
	./system;

clean:
	@echo "Destructing the <object> files"
	@rm obj/account.o
	@rm obj/crud.o
	@rm obj/menu.o
	@rm obj/task.o
	@rm obj/main.o
	
	@echo "Destructing the <executable>"
	@rm bin/system
	
	@echo "Destructing the <bin> file"
	@rm bin/record.bin
