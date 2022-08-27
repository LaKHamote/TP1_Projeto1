library= ./LibraryObjs/domain.o ./LibraryObjs/entity.o
controllers= ./ControllerObjs/cntrPresentation.o
curses= ../lib/Curses/libcurses.a ../lib/Curses/libncurses.a ../lib/Curses/libncurses++.a ../lib/Curses/libncurses++w.a ../lib/Curses/libncursesw.a ../lib/Curses/libtinfo.a

all:	main.exe
	./main.exe

main.exe:	../main.cpp $(library) $(controllers) ../stubs.cpp
	g++ -std=c++17 -Wall $(library) $(controllers) ../stubs.cpp ../main.cpp -lncurses -ltinfo -o main.exe