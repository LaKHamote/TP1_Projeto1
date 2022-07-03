all: main.exe domain.o domainTests.o
	./main.exe

domain.o:
	g++ -std=c++17 -Wall -c ../domain.cpp

domainTests.o:
	g++ -std=c++17 -Wall -c ../domainTest.cpp

entityTests.o:
	g++ -std=c++17 -Wall -c ../entityTest.cpp

main.exe: domain.o domainTests.o entityTests.o
	g++ -std=c++17 -Wall ./*.o ../main.cpp -o ./main.exe
