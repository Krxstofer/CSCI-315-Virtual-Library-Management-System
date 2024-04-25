#makefile for testing the Book object and Queue

main:
	g++ -g Virtual\ Library\ Management\ System.cpp -o Main
	Main


book:
	g++ -g BookTest.cpp -o Book
	Book
menu:
	g++ -g Menu.cpp -o Menu
	Menu

queue:
	g++ -g QueueTest.cpp -o Queue
	Queue
tree:
	g++ -g TreeTest.cpp -o Tree
	Tree

test:
	g++ -c MGoogleTest.cpp
	g++ MGoogleTest.o -o Test -lgtest_main -lgtest -lpthread
	Test
