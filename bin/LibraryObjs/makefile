all:	domain.o domainTest.o entity.o entityTest.o libraryTest.exe
	+$(MAKE) -C ../ControllerObjs

domain.o:	../../lib/Domains/domain.cpp ../../lib/Domains/domain.hpp
	g++ -std=c++17 -Wall -c ../../lib/Domains/domain.cpp

domainTest.o:	../../lib/Tests/domainTest.cpp ../../lib/Tests/domainTest.hpp
	g++ -std=c++17 -Wall -c ../../lib/Tests/domainTest.cpp

entity.o:	../../lib/Entities/entity.cpp ../../lib/Entities/entity.hpp
	g++ -std=c++17 -Wall -c ../../lib/Entities/entity.cpp

entityTest.o:	../../lib/Tests/entityTest.cpp ../../lib/Tests/entityTest.hpp
	g++ -std=c++17 -Wall -c ../../lib/Tests/entityTest.cpp

libraryTest.exe:	../../lib/Tests/run.cpp domain.o domainTest.o entity.o entityTest.o
	g++ -std=c++17 -Wall ./*.o ../../lib/Tests/run.cpp -o libraryTest.exe

test:	libraryTest.exe
	./libraryTest.exe