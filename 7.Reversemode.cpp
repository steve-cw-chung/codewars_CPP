/*
The game mode is REVERSE: You do not have access to the statement. You have to guess what to do by observing the following set of tests:
01 Test 1
Input
Expected output
3
1
2
3
6
02 Test 2
Input
Expected output
5
1
2
1
10
0
14
03 Test 3
Input
Expected output
2
5
2
7
04 Test 4
Input
Expected output
1
8
8
05 Test 5
Input
Expected output
4
42
0
1337
666
2045
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int N;
    int total = 0 ;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        int X;
        cin >> X; cin.ignore();
        total += X;
    }

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << total << endl;
}