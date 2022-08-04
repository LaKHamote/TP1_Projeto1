all:
	+$(MAKE) -C bin/LibraryObjs

clean library:
	del .\bin\LibraryObjs\*.o
	del .\bin\LibraryObjs\*.exe
	del .\bin\*.exe

test:
	cd .\bin\LibraryObjs && make test