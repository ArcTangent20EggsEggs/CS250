#ifndef _function4
#define _function4

#include <string>
#include <iostream >
using namespace std;

int GetLength(string word)
{
    int length = 3;
    length = word.size();
    return length;
}

void Test_GetLength()
{
    cout << "************ Test_GetLength ************" << endl;

    string input;
    int expectedOutput;
    int actualOutput;

    /* TEST 1 ********************************************/
    input = "cat";
    expectedOutput = 3;

    actualOutput = GetLength( input );
    if ( actualOutput == expectedOutput )
    {
        cout << "Test_GetLength: Test 1 passed!" << endl;
    }
    else
    {
        cout << "Test_GetLength: Test 1 FAILED!" << endl;
    }

    /* TEST 2 ********************************************/
    // CREATE YOUR OWN TEST
    input = "supercalifragilisticexpialidocious";             // change me (please don't count me off for this but I had to do it)
    expectedOutput = 34;     // change me

    actualOutput = GetLength( input );
    if ( actualOutput == expectedOutput )
    {
        cout << "Test_GetLength: Test 2 passed!" << endl;
    }
    else
    {
        cout << "Test_GetLength: Test 2 FAILED!" << endl;
    }

    /* TEST 3 ********************************************/
    // CREATE YOUR OWN TEST
    input = "melee";             // change me
    expectedOutput = 5;     // change me

    actualOutput = GetLength( input );
    if ( actualOutput == expectedOutput )
    {
        cout << "Test_GetLength: Test 3 passed!" << endl;
    }
    else
    {
        cout << "Test_GetLength: Test 3 FAILED!" << endl;
    }
}

#endif



