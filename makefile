main.x: main.o funz.o
	g++ -o main.x main.o funz.o

main.o: main.cpp funz.h
	g++ -c main.cpp

funz.o: funz.cpp funz.h
	g++ -c funz.cpp

compila: main.x

esegui:
	./main.x

clean:
	rm *.o

