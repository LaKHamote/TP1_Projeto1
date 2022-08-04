all:	domain.o domainTest.o entity.o entityTest.o libraryTest.exe
	+$(MAKE) -C ../

domain.o:	../../Library/Domains/domain.cpp ../../Library/Domains/domain.hpp
	g++ -std=c++17 -Wall -c ../../Library/Domains/domain.cpp

domainTest.o:	../../Library/Tests/domainTest.cpp ../../Library/Tests/domainTest.hpp
	g++ -std=c++17 -Wall -c ../../Library/Tests/domainTest.cpp

entity.o:	../../Library/Entities/entity.cpp ../../Library/Entities/entity.hpp
	g++ -std=c++17 -Wall -c ../../Library/Entities/entity.cpp

entityTest.o:	../../Library/Tests/entityTest.cpp ../../Library/Tests/entityTest.hpp
	g++ -std=c++17 -Wall -c ../../Library/Tests/entityTest.cpp

libraryTest.exe:	../../Library/Tests/run.cpp domain.o domainTest.o entity.o entityTest.o
	g++ -std=c++17 -Wall ./*.o ../../Library/Tests/run.cpp -o libraryTest.exe

test:	libraryTest.exe
	libraryTest.exe