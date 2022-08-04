library= ./LibraryObjs/domain.o ./LibraryObjs/entity.o

all:	main.exe
	main.exe

main.exe:	../main.cpp $(library)
	g++ -std=c++17 -Wall $(library) ../main.cpp -o main.exe