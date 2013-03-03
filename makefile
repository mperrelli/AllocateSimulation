AllocateSim: main.o printFunctions.o sorts.o allocationAlgs.o
	cc -o AllocateSim main.o printFunctions.o sorts.o allocationAlgs.o

main.o: main.c
	cc -c main.c

printFunctions.o: printFunctions.c
	cc -c printFunctions.c

sorts.o: sorts.c
	cc -c sorts.c

allocationAlgs.o: allocationAlgs.c
	cc -c allocationAlgs.c

clean:
	rm *.o
