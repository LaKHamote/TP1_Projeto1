all: main.exe domain.o domainTests.o
	./main.exe

domain.o:
	g++ -std=c++17 -Wall -c ../domain.cpp

domainTests.o:
	g++ -std=c++17 -Wall -c ../domainTests.cpp

main.exe: domain.o domainTests.o
	g++ -std=c++17 -Wall ./*.o ../main.cpp -o ./main.exe
