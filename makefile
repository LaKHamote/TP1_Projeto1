all:
	+$(MAKE) -C bin/LibraryObjs

clean library:
	del .\bin\LibraryObjs\*.o