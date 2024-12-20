#include <iostream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

#ifndef Auxillary_H
#define Auxillary_H

#define BCK "\x1b[1F"  // define line clear for console print
#define CYN "\x1B[36m" // define colour yellow for console print
#define YEL "\x1B[33m" // define colour yellow for console print
#define RED "\x1B[31m" // define colour red for console print
#define GRN "\x1B[32m" // define colour green for console print
#define RST "\x1B[0m"  // define colour white for console print

const int maxStringsize = 50;

void writeFixedLengthString(char attribute[], string value)
{
    unsigned int maxLength = 50;
    unsigned int idx, length;

    length = (value.length() > maxLength) ? (maxLength - 1) : value.length();

    for (idx = 0; idx < length; idx++)
    {
        attribute[idx] = value.at(idx);
    }
    attribute[idx] = '\0';
}

void getInput(istream &stream, char uservalue[])
{

    stream >> ws; // clear whitespace characters
    stream.getline(uservalue, maxStringsize);

    if (stream.fail())
    {
        throw runtime_error("Invalid Input Please Try again");
    }
}

#endif