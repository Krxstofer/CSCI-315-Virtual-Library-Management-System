To run main, link the following files:
	AdminFun.cpp
	Book.cpp
	GeneralFunctions.cpp
	hash.cpp
	LoadSave.cpp
	User.cpp
	UserFun.cpp
	Virtual Library Management System.cpp [main]

There are 4 different Google Tests:
	AdminTests.cpp [tests functions in AdminFun.cpp]
	ClassTests.cpp [tests various classes including book, user, hash]
	GeneralTests.cpp [tests functions in GeneralFunctions.cpp]
	UserTests.cpp [tests functions in UserFun.cpp]

To run AdminTests.cpp, link the following files:
	AdminFun.cpp
	AdminTests.cpp [Google Test]
	Book.cpp
	Hash.cpp
	User.cpp

To run ClassTests.cpp, link the following files:
	Book.cpp
	ClassTests.cpp [Google Test]
	hash.cpp
	LoadSave.cpp
	User.cpp

To run GeneralTests.cpp, link the following files:
	Book.cpp
	GeneralFunctions.cpp
	GeneralTests.cpp [Google Test]
	Hash.cpp
	LoadSave.cpp
	User.cpp

To run UserTests.cpp, link the following files:
	Book.cpp
	hash.cpp
	User.cpp
	UserFun.cpp
	UserTests.cpp [Google Test]

If you would like to access our Github repository, please contact Kristofer (the owner of the repository). 
The repository is currently private, so it can only be accessed through Kristofer’s permission.

If you would like to see the commits we made in Github, please read GitLog.txt in this directory.
