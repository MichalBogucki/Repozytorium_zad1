__start__: main.exe

main.exe : main.o 
	g++ main.o -o main.exe

main.o : main.cpp list.h List.cpp
	g++ -c main.cpp

release: main.cpp
	g++ main.cpp
	
debug: main.cpp
	g++ -g main.cpp
	
clean: 
	rm *.o main.exe
