all: 
	+$(MAKE) -C bin

clean:
	rm -rf ./bin/*.o ./bin/*.exe

clean-run:
	rm -rf ./bin/*.o ./bin/*.exe
	+$(MAKE) -C bin
	
