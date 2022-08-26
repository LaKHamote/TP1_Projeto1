all:
	+$(MAKE) -C bin/LibraryObjs

clean:
	rm -f ./bin/ControllerObjs/*.o

clean-library:
	rm -f ./bin/LibraryObjs/*.o
	rm -f ./bin/LibraryObjs/*.exe

test:
	cd ./bin/LibraryObjs && make test