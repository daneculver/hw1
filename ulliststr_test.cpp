/* Write your test code for the ULListStr in this file */
#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include "ulliststr.cpp"
#define ARRSIZE 10
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
  ULListStr test;
  test.push_back("baby");
  test.push_front("da");
  test.push_back("lol");
  cout << test.get(0) << " " << test.get(1) << " " << test.get(2) << endl;
  // prints: da baby lol
  cout << test.size() << endl;
  // prints 3 since there are 3 strings stored
  test.pop_back();
  test.pop_front();
  cout << test.back() <<endl;
  cout << test.front() << endl;;
  cout <<test.get(1) << endl;
  cout << test.size() << endl;  
    return 0;
}
