all:	domain.o domainTest.o entity.o entityTest.o
	+$(MAKE) -C ../

domain.o:
	g++ -std=c++17 -Wall -c ../../Library/Domains/domain.cpp

domainTest.o:
	g++ -std=c++17 -Wall -c ../../Library/Tests/domainTest.cpp

entity.o:
	g++ -std=c++17 -Wall -c ../../Library/Entities/entity.cpp

entityTest.o:
	g++ -std=c++17 -Wall -c ../../Library/Tests/entityTest.cpp
