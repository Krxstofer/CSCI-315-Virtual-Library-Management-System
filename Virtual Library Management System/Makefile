#makefile for testing the Book object and Queue

main:
	g++ -g -c Book.cpp
	g++ -g -c LoadSave.cpp
	g++ -c -g UserFun.cpp
	g++ -c -g AdminFun.cpp
	g++ -g -c GeneralFunctions.cpp
	g++ -g -c User.cpp
	g++ -g -c Virtual\ Library\ Management\ System.cpp
	g++ -g Book.o LoadSave.o GeneralFunctions.o UserFun.o AdminFun.o User.o Virtual\ Library\ Management\ System.o -o Main
	Main


book:
	g++ -g -c Book.cpp
	g++ -g -c BookTest.cpp
	g++ -g Book.o BookTest.o -o Book
#	g++ -g BookTest.cpp -o Book
	Book
menu:
	g++ -c -g Book.cpp
#	g++ -c -g QueueTest.cpp
	g++ -c -g MenuTest.cpp
	g++ -c -g LoadSave.cpp
	g++ -c -g UserFun.cpp
	g++ -c -g AdminFun.cpp
	g++ -g Book.o MenuTest.o LoadSave.o UserFun.o AdminFun.o -o Menu
	Menu

queue:
	g++ -g -c QueueTest.cpp
	g++ -g -c LoadSave.cpp
	g++ -g -c Book.cpp
	g++ -g QueueTest.o LoadSave.o Book.o -o Queue
#	g++ -g QueueTest.cpp -o Queue
	Queue
tree:
	g++ -g -c Book.cpp
	g++ -g -c LoadSave.cpp
	g++ -g -c TreeTest.cpp
	g++ Book.o LoadSave.o TreeTest.o -o Tree
#	g++ -g TreeTest.cpp -o Tree
	Tree

func:
	g++ -g -c Book.cpp
	g++ -g -c LoadSave.cpp
	g++ -g -c GeneralFunctions.cpp
	g++ -g -c FuncTest.cpp
	g++ -g -c AdminFun.cpp
	g++ -g -c User.cpp
	#temporary
#	g++ -g -c 'hash (1).cpp'
#	g++ -g -c '(ht) admin.cpp'
#	g++ -g -c '(ht) user.cpp'
	g++ -g Book.o LoadSave.o GeneralFunctions.o AdminFun.o User.o FuncTest.o -o Func
#	g++ -g TreeTest.cpp -o Tree
	Func

test:
	g++ -g -c Book.cpp
	g++ -g -c LoadSave.cpp
	g++ -g -c GeneralFunctions.cpp
	g++ -g -c User.cpp
	g++ -c MGoogleTest.cpp
	g++ Book.o LoadSave.o GeneralFunctions.o User.o MGoogleTest.o -o Test -lgtest_main -lgtest -lpthread
	Test
