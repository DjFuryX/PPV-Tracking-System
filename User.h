#include <iostream>
using namespace std;

class User
{
    string username;
    int password;
    virtual void login() = 0;
};


