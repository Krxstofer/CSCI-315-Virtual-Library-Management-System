// Class that allows you to send output to null if a bool parameter is set to false. It will print if the bool is true.
// Helpful for making your funcitons google test friendly
// view searchBook() in UserFun.cpp for an example
// Simply include this file, and substitude 'cout' for 'outStream'
// Your funciton will also need to have bool parameter to replace 'my_bool'
// Code to include in your function:
/* 
NullBuffer nullBuffer;
ostream nullStream(&nullBuffer);
ostream& outStream  = my_bool ? cout : nullStream;
*/

#ifndef H_nullBuffer
#define H_nullBuffer

#include <streambuf>

class NullBuffer : public std::streambuf {
public:
    int overflow(int c) override {
        return c; // Returning the character itself indicates a successful write
    }
};

#endif