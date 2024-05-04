To run main, link the following files:
        AdminFun.cpp
        Book.cpp
        GeneralFunctions.cpp
        hash.cpp
        LoadSave.cpp
        User.cpp
        UserFun.cpp
        Virtual Library Management System.cpp [main]


There are 6 different Google Tests:
        AdminTests.cpp [tests functions in AdminFun.cpp]
        ClassTests.cpp [tests various classes including book, user, hash]
        GeneralTests.cpp [tests functions in GeneralFunctions.cpp]
        UserTests.cpp [tests functions in UserFun.cpp]
        LoginTest.cpp [tests the login function]
        UserTest.cpp [tests the User object]
They must be linked to the main that Google Test provides to run

To run AdminTests.cpp, compile and link the following files:
        AdminFun.cpp
        AdminTests.cpp [Google Test]
        Book.cpp
        Hash.cpp
        User.cpp


To run ClassTests.cpp, compile and link the following files:
        Book.cpp
        ClassTests.cpp [Google Test]
        hash.cpp
        LoadSave.cpp
        User.cpp


To run GeneralTests.cpp, compile and link the following files:
        Book.cpp
        GeneralFunctions.cpp
        GeneralTests.cpp [Google Test]
        Hash.cpp
        LoadSave.cpp
        User.cpp


To run UserTests.cpp, compile and link the following files:
        Book.cpp
        hash.cpp
        User.cpp
        UserFun.cpp
        UserTests.cpp [Google Test]

To run LoginTest.cpp, compile and link the following files:
        Book.cpp
        GeneralFunctions.cpp
        hash.cpp
        User.cpp
        LoadSave.cpp
        UserTest.cpp [Google Test]

To run UserTest.cpp, compile and link the following files:
        Book.cpp
        GeneralFunctions.cpp
        hash.cpp
        User.cpp
        LoadSave.cpp
        LoginTest.cpp [Google Test]
