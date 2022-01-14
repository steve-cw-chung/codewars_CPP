/*
can you see this?


1
2
3fizz
4foo
5buzz
6fizzbar
7
8foo
9fizz
10buzz
11
12fizzfoobar
13
14
15fizzbuzz
..
..

20foobuzz

30buzzbar

...
60fizzfoobuzz


n

3->fizz
4->foo
5->buzz
6->bar

*/

#include <iostream>
#include <string>

int main () {

  string retVal ;


  for (int i = 1 ; i <= n ; i++) {

  retVal = i; // reset the retVal to i every iteration


  // check if current number is multiple of 3 then add "fizz" 



  if ( i % 3 == 0 ) {

   retVal += "fizz";

  } 
  
  if ( i % 4 == 0) {
   retVal += "foo"; 
  }

  if ( i % 5 == 0) {

  // check if current number is multiple of 5 then add "buzz" 
    retVal += "buzz";
  }
  if( i % 6 == 0){
  	retVal += "bar";
  }
  // print out current string 
     std::cout << retVal << std::endl;
  // iterate 
  }
}



#include <iostream>
#include <vector>
#include <map>
// time O( n * m )
// space O(m)
int main() {
  // vector < pair<int, string> > wmap;
  // wmap[0].first
  // wmap[0].second
  string retVal ;
  vector < pair<int, string> > wmap ;  
  int multiple ;
  string word ; 
  
  std::cin >> multiple;
  std::cin >> word;
  
  for ( int i = 1 ; i <= n; i++){
    retVal = i; // set return value of each iteration set to i 
   for ( int j = 0 ; j < wmap.size() ; j++){
   	
     if (i % wmap[j].first == 0 ) {
      retVal += wmap[j].second;
   		}
  	}
    std::cout << retVal << std::endl;
  
  
}


/*

1
2
3fizz
4
5buzz
6fizz
7
8
9fizz
10buzz
11
12fizz
13
14
15fizzbuzz
16
17
18fizz
19
20buzz
21fizz
22
23
24fizz
25buzz
26
27fizz
28
29
30fizzbuzz


{
	"fizzbuzz",
  "",
  "",
  "fizz",
  "",
  "buzz",
  "fizz",
  "",
  "",
  "fizz",
  "buzz",
  "",
  "fizz",
  "",
  "",
}
vect


*/  
  
  
  
#include <iostream>
#include <vector>
#include <map>
  
// O(m + LCM(m) + n) vs O(n * m)
// LCM(m) >> m
// 3,5 lcm = 15, m = 2
// 1,2,4,8 lcm = 8, m = 4
// 1,1,1,1 lcm = 1, m = 4
int main() {
  string retVal;
  
  vector < pair<int, string> > wmap;
  // 1. vect.size O(m)
  // 2. populate vec LCM(m)
  // wmap => vect
  vector <string> vect;
  
  // time O(n)
  // space O(1)
  for ( int i = 1 ; i <= n; i++){
     retVal = i; // set return value of each iteration set to i 
   	 retVal += vect[i%vect.size()];
     std::cout << retVal << std::endl;
  }
  
  
}
  