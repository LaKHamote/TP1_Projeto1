all:
	del .\bin\*.o .\bin\*.exe
	+$(MAKE) -C bin
	del .\bin\*.o .\bin\*.exe

clean:
	del .\bin\*.o .\bin\*.exe

run:
	+$(MAKE) -C bin

linux:
	rm -rf ./bin/*.o ./bin/*.exe
	+$(MAKE) -C bin
	rm -rf ./bin/*.o ./bin/*.exe
	
