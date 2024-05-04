#makefile for testing the Book object and Queue

main:
	g++ -g -c Book.cpp
	g++ -g -c LoadSave.cpp
	g++ -c -g UserFun.cpp
	g++ -c -g AdminFun.cpp
	g++ -g -c GeneralFunctions.cpp
	g++ -g -c User.cpp
	g++ -g -c hash.cpp
	g++ -g -c Virtual\ Library\ Management\ System.cpp
	g++ -g Book.o LoadSave.o GeneralFunctions.o UserFun.o AdminFun.o User.o hash.o Virtual\ Library\ Management\ System.o -o Main
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

hash:
	g++ -g -c User.cpp
	g++ -g -c hash.cpp
	g++ -g -c hashMain.cpp
	g++ User.o hash.o hashMain.o -o Hash
#	g++ -g TreeTest.cpp -o Tree
	Hash

func:
	g++ -g -c Book.cpp
	g++ -g -c LoadSave.cpp
	g++ -g -c GeneralFunctions.cpp
	g++ -g -c FuncTest.cpp
	g++ -g -c AdminFun.cpp
	g++ -g -c User.cpp
	g++ -g -c hash.cpp
	g++ -g Book.o LoadSave.o GeneralFunctions.o AdminFun.o User.o hash.o FuncTest.o -o Func
	Func

uTest:
	g++ -g -c Book.cpp
	g++ -g -c UserFun.cpp
	g++ -g -c User.cpp
	g++ -g -c hash.cpp
	g++ -c UserGoogleTest.cpp
	g++ Book.o UserFun.o User.o hash.o UserGoogleTest.o -o uTest -lgtest_main -lgtest -lpthread
	uTest

mtest:
	g++ -g -c Book.cpp
	g++ -g -c LoadSave.cpp
	g++ -g -c GeneralFunctions.cpp
	g++ -g -c AdminFun.cpp
	g++ -g -c User.cpp
	g++ -g -c hash.cpp
	g++ -c MGoogleTest.cpp
	g++ Book.o LoadSave.o GeneralFunctions.o User.o AdminFun.o hash.o MGoogleTest.o -o Test -lgtest_main -lgtest -lpthread
	Test

atest:
	g++ -g -c Book.cpp
	g++ -g -c AdminFun.cpp
	g++ -g -c UserFun.cpp
	g++ -g -c User.cpp
	g++ -g -c hash.cpp
	g++ -c AdminTests.cpp
	g++ Book.o User.o AdminFun.o UserFun.o hash.o AdminTests.o -o ATest -lgtest_main -lgtest -lpthread
	ATest

ctest:
	g++ -g -c Book.cpp
	g++ -g -c LoadSave.cpp
	g++ -g -c User.cpp
	g++ -g -c hash.cpp
	g++ -c ClassTests.cpp
	g++ Book.o LoadSave.o User.o hash.o ClassTests.o -o CTest -lgtest_main -lgtest -lpthread
	CTest

gtest:
	g++ -g -c Book.cpp
	g++ -g -c LoadSave.cpp
	g++ -g -c GeneralFunctions.cpp
	g++ -g -c User.cpp
	g++ -g -c hash.cpp
	g++ -c GeneralTests.cpp
	g++ Book.o LoadSave.o GeneralFunctions.o User.o hash.o GeneralTests.o -o GTest -lgtest_main -lgtest -lpthread
	GTest

utest:
	g++ -g -c Book.cpp
	g++ -g -c UserFun.cpp
	g++ -g -c User.cpp
	g++ -g -c hash.cpp
	g++ -c UserTests.cpp
	g++ Book.o UserFun.o User.o hash.o UserTests.o -o UTest -lgtest_main -lgtest -lpthread
	UTest

itest:
	g++ -g -c Book.cpp
	g++ -g -c LoadSave.cpp
	g++ -g -c GeneralFunctions.cpp
	g++ -g -c AdminFun.cpp
	g++ -g -c UserFun.cpp
	g++ -g -c User.cpp
	g++ -g -c hash.cpp
	g++ -c integrationTest.cpp
	g++ Book.o LoadSave.o GeneralFunctions.o User.o AdminFun.o UserFun.o hash.o integrationTest.o -o Test -lgtest_main -lgtest -lpthread
	Test

.PHONY: atest ctest gtest utest itest
tests:
	make atest
	make ctest
	make gtest
	make utest
	make itest

jtest:
	g++ -g -c Book.cpp
	g++ -c GeneralFunctions.cpp
	g++ -g -c hash.cpp
	g++ -g -c User.cpp
	g++ -g -c LoadSave.cpp
	g++ -c UserTest.cpp
	g++ Book.o GeneralFunctions.o hash.o LoadSave.o User.o UserTest.o -o J1 -lgtest_main -lgtest -lpthread
	J1

	g++ -g -c Book.cpp
	g++ -c GeneralFunctions.cpp
	g++ -g -c hash.cpp
	g++ -g -c User.cpp
	g++ -g -c LoadSave.cpp
	g++ -c LoginTest.cpp
	g++ Book.o GeneralFunctions.o hash.o LoadSave.o User.o LoginTest.o -o J2 -lgtest_main -lgtest -lpthread
	J2


