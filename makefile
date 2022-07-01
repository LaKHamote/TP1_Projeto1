all:
	del .\bin\*.o .\bin\*.exe
	+$(MAKE) -C bin

clean:
	del .\bin\*.o .\bin\*.exe

run:
	+$(MAKE) -C bin
	
