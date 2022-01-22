/* Determine the minimum cost to provide library access to all citizens of HackerLand. There are  cities numbered from  to . Currently there are no libraries and the cities are not connected. Bidirectional roads may be built between any city pair listed in . A citizen has access to a library if:

Their city contains a library.
They can travel by road from their city to a city containing a library.
Example

The following figure is a sample map of HackerLand where the dotted lines denote possible roads:

image




The cost of building any road is , and the cost to build a library in any city is . Build  roads at a cost of  and  libraries for a cost of . One of the available roads in the cycle  is not necessary.

There are  queries, where each query consists of a map of HackerLand and value of  and . For each query, find the minimum cost to make libraries accessible to all the citizens.

Function Description

Complete the function roadsAndLibraries in the editor below.
roadsAndLibraries has the following parameters:

int n: integer, the number of cities
int c_lib: integer, the cost to build a library
int c_road: integer, the cost to repair a road
int cities[m][2]: each  contains two integers that represent cities that can be connected by a new road
Returns
- int: the minimal cost

Input Format

The first line contains a single integer , that denotes the number of queries.

The subsequent lines describe each query in the following format:
- The first line contains four space-separated integers that describe the respective values of , ,  and , the number of cities, number of roads, cost of a library and cost of a road.
- Each of the next  lines contains two space-separated integers,  and , that describe a bidirectional road that can be built to connect cities  and .

Constraints

Each road connects two distinct cities.
Sample Input

STDIN       Function
-----       --------
2           q = 2
3 3 2 1     n = 3, cities[] size m = 3, c_lib = 2, c_road = 1
1 2         cities = [[1, 2], [3, 1], [2, 3]]
3 1
2 3
6 6 2 5     n = 6, cities[] size m = 6, c_lib = 2, c_road = 5
1 3         cities = [[1, 3], [3, 4],...]
3 4
2 4
1 2
2 3
5 6
Sample Output

4
12
Explanation

Perform the following  queries:

HackerLand contains  cities and can be connected by  bidirectional roads. The price of building a library is  and the price for repairing a road is .
image

The cheapest way to make libraries accessible to all is to:

Build a library in city  at a cost of .
Build the road between cities  and  at a cost of .
Build the road between cities  and  at a cost of .
This gives a total cost of . Note that the road between cities  and  does not need to be built because each is connected to city .

In this scenario it is optimal to build a library in each city because the cost to build a library is less than the cost to build a road.
image

There are  cities, so the total cost is . */

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'roadsAndLibraries' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER c_lib
 *  3. INTEGER c_road
 *  4. 2D_INTEGER_ARRAY cities
 */

class Graph {
    public:
    map<long,vector<long>> adj;
    map<long,bool> visited;

    long components=0;
    
    void addEdge(long,long);
    void DFS(long);
   
};
    
void Graph::addEdge(long u, long v){
    
    adj[u].push_back(v); 
    adj[v].push_back(u);
  
}
void Graph::DFS(long u){
    
    visited[u]= true;
    //update this to do different actions when node is visited
    //cout << u << " " ;
    
    for(auto x : adj[u]){
        if(!visited[x]){
            DFS(x);
        }
    
    }
}


long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    // case 1: when c_lib <= c_road then n*c_lib
    // case 2: wjem c_lib > c_road then connect the cities w/o creating a cycle then add library to each                  connected graphs
    if(c_lib<c_road){
        return (long)n*c_lib;
    } 
    // Create Graph
    Graph g; 
    for(long i =0; i<cities.size();i++){
        //cout << "cities[i][0] : " <<cities[i][0]<< " cities[i][1] : " << cities[i][1] <<endl;
        g.addEdge(cities[i][0], cities[i][1]);
        g.visited[i+1]=false;
    }
    for(int i =1; i<=n;i++){
        if(g.visited[i]){
            continue;
        }
        g.components++;
        g.DFS(i);
    }
    long roads = n-g.components;
   
    //cout << "components : " << g.components<<endl;
    return long( long(roads*c_road) + long(c_lib*g.components));
    

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int c_lib = stoi(first_multiple_input[2]);

        int c_road = stoi(first_multiple_input[3]);

        vector<vector<int>> cities(m);

        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            string cities_row_temp_temp;
            getline(cin, cities_row_temp_temp);

            vector<string> cities_row_temp = split(rtrim(cities_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int cities_row_item = stoi(cities_row_temp[j]);

                cities[i][j] = cities_row_item;
            }
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
