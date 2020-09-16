#include <bits/stdc++.h>


using namespace std;

// helper function to add two strings to avoid the overflow in summation of two integer numbers (4bytes) 2,147,483,647 
string doSum(string a, string b)
{
    // make string a longer than b 
    if(a.size() < b.size())
        swap(a, b);
    // j = last index of a
    int j = a.size()-1;
    // for loop last index of b to 0 and last index of a ot 0
    for(int i=b.size()-1; i>=0; i--, j--)
        // increase the a[j] by b[i] getting the actual integer value by subtracting ascii of 0  
        a[j]+=(b[i]-'0');
    // Check the carry
    for(int i=a.size()-1; i>0; i--){
        if(a[i] > '9'){
            // d is the currently greater than 10
            int d = a[i]-'0';
            // add the carry to the previous index
            a[i-1] = ((a[i-1]-'0') + 1) + '0';
            // current index gets the remainer
            a[i] = (d%10)+'0';
        }
    }
    if(a[0] > '9'){
        string k;
        k+=a[0];
        a[0] = ((a[0]-'0')%10)+'0';
        k[0] = 1+'0';
        a = k+a;
    }
    return a;
}
int main()
{
    // read the string filename
    string filename;
    int numberOfRequestThatsGreaterThanThreshold = 0;
    string TotalNumberofBytes;
    cin >> filename;
    ifstream input_logfile;
    input_logfile.open(filename);
    string output_filename = "bytes_"+filename;
    if(input_logfile.is_open()){
        string log;
        while(getline(input_logfile, log)){
            if(stoi(log.substr(log.find_last_of(" ")+1))>5000){
                numberOfRequestThatsGreaterThanThreshold++;
                TotalNumberofBytes = doSum(TotalNumberofBytes,log.substr(log.find_last_of(" ")+1));
                //you can use the line below instead if the summation does not exceed 2,147,483,647
                //TotalNumberofBytes += stoi(log.substr(log.find_last_of(" ")+1));
            }
        }
    }
    ofstream output_logfile;
    output_logfile.open(output_filename);
    output_logfile << to_string(numberOfRequestThatsGreaterThanThreshold)+'\n';
    output_logfile << TotalNumberofBytes+'\n';
    input_logfile.close();
    output_logfile.close();
    return 0;
}