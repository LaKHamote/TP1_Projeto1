all:
	+$(MAKE) -C bin
	rm -rf ./bin/*.o ./bin/*.exe

clean:
	rm -rf ./bin/*.o ./bin/*.exe

run:
	+$(MAKE) -C bin
	
