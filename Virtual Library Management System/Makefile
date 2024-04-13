#makefile for testing the Book object and Queue

main:
	g++ -c -g Book.cpp
	g++ -c -g Virtual\ Library\ Management\ System.cpp
	g++ -g Book.o Virtual\ Library\ Management\ System.o -o Main
	Main


book:
	g++ -c -g Book.cpp
	g++ -c -g BookTest.cpp
	g++ -g Book.o BookTest.o -o Book
	Book

queue:
	g++ -c -g Book.cpp
	g++ -c -g QueueTest.cpp
	g++ -g Book.o QueueTest.o -o Queue
	Queue
