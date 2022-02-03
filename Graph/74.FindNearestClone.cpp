/* In this challenge, there is a connected undirected graph where each of the nodes is a color. Given a color, find the shortest path connecting any two nodes of that color. Each edge has a weight of . If there is not a pair or if the color is not found, print .

For example, given , and  edges  and  and colors for each node are  we can draw the following graph:

image

Each of the nodes is labeled [node]/[color] and is colored appropriately. If we want the shortest path between color , blue, we see there is a direct path between nodes  and . For green, color , we see the path length  from . There is no pair for node  having color , red.

Function Description

Complete the findShortest function in the editor below. It should return an integer representing the length of the shortest path between two nodes of the same color, or  if it is not possible.

findShortest has the following parameter(s):

g_nodes: an integer, the number of nodes
g_from: an array of integers, the start nodes for each edge
g_to: an array of integers, the end nodes for each edge
ids: an array of integers, the color id per node
val: an integer, the id of the color to match
Input Format

The first line contains two space-separated integers  and , the number of nodes and edges in the graph.
Each of the next  lines contains two space-separated integers  and , the nodes connected by an edge.
The next line contains  space-seperated integers, , representing the color id of each node from  to .
The last line contains the id of the color to analyze.

Note: The nodes are indexed from  to .

Constraints




Output Format

Print the single integer representing the smallest path length or .

Sample Input 0

4 3
1 2
1 3
4 2
1 2 1 1 
1
Sample Output 0

1 
Explanation 0

image

In the above image the distance between the closest nodes having color label  is .

Sample Input 1

4 3
1 2
1 3
4 2
1 2 3 4
2
Sample Output 1

-1 
Explanation 1

image

Sample Input 2

5 4
1 2
1 3
2 4
3 5
1 2 3 3 2
2
Sample Output 2

3
Explanation 2

image */

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the findShortest function below.

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */
 class Graph {
    public:
    int color = 0;
    int minDist = INT_MAX;
    int tempDist = INT_MAX;
    map<int,list<int>>adj;
    map<int,bool>visited;
    map<int,long>colors;
    void addEdge(int,int);
    void DFS(int);
    void BFS(int);     
 };
 
 void Graph::addEdge(int u, int v){
     adj[u].push_back(v);
     adj[v].push_back(u);
 }

 void Graph::DFS(int u){
     visited[u] = true;
     for(auto x: adj[u]){
         if(!visited[x]){
             if(tempDist==INT_MAX){
                 tempDist=1;
             }else{
                 tempDist++;
             }
             
             if(colors[x]==color){
                 
                 if(tempDist<minDist){
                     minDist = tempDist;
                     tempDist = INT_MAX;
                     break;
                 }
             } 
             DFS(x);
         }
    }
 }
 
int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {
    Graph g;
    g.color = val;
    for(int i=0; i<graph_from.size();i++){
        g.addEdge(graph_from[i], graph_to[i]);
    }
    for(int i=1; i<=ids.size(); i++){
        g.colors[i]=ids[i-1];
    }
    for(int i=0; i<ids.size();i++){
        if(ids[i]==val){
            g.DFS(i+1);
           
        }
    }
    if(g.minDist==INT_MAX){
        return -1;
    }
    return g.minDist;

}
 
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int graph_nodes;
    int graph_edges;

    cin >> graph_nodes >> graph_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int i = 0; i < graph_edges; i++) {
        cin >> graph_from[i] >> graph_to[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string ids_temp_temp;
    getline(cin, ids_temp_temp);

    vector<string> ids_temp = split_string(ids_temp_temp);

    vector<long> ids(graph_nodes);

    for (int i = 0; i < graph_nodes; i++) {
        long ids_item = stol(ids_temp[i]);

        ids[i] = ids_item;
    }

    int val;
    cin >> val;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);

    fout << ans << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
