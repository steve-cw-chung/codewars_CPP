/* The game mode is REVERSE: You do not have access to the statement. You have to guess what to do by observing the following set of tests:
01 Test 1
Input
Expected output
2 
4
16
02 Test 2
Input
Expected output
7 
11
539
03 Test 3
Input
Expected output
456 
54
11228544
04 Test 4
Input
Expected output
1111 
79
97511359
05 Test 5
Input
Expected output
0 
6
0 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int M;
    cin >> M; cin.ignore();
    int N;
    cin >> N; cin.ignore();

    // Write an answer using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << M*M*N << endl;
}