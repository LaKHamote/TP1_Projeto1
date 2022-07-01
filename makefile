all: 
	rm -rf ./bin/*.o ./bin/*.exe
	+$(MAKE) -C bin

clean:
	rm -rf ./bin/*.o ./bin/*.exe

run:
	+$(MAKE) -C bin
	
