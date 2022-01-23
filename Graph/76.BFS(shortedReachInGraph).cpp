/* Consider an undirected graph consisting of  nodes where each node is labeled from  to  and the edge between any two nodes is always of length . We define node  to be the starting position for a BFS. Given a graph, determine the distances from the start node to each of its descendants and return the list in node number order, ascending. If a node is disconnected, it's distance should be .

For example, there are  nodes in the graph with a starting node . The list of , and each has a weight of .

image

Starting from node  and creating a list of distances, for nodes  through  we have .

Function Description

Define a Graph class with the required methods to return a list of distances.

Input Format

The first line contains an integer, , the number of queries.

Each of the following  sets of lines is as follows:

The first line contains two space-separated integers,  and , the number of nodes and the number of edges.
Each of the next  lines contains two space-separated integers,  and , describing an edge connecting node  to node .
The last line contains a single integer, , the index of the starting node.
Constraints

Output Format

For each of the  queries, print a single line of  space-separated integers denoting the shortest distances to each of the  other nodes from starting position . These distances should be listed sequentially by node number (i.e., ), but should not include node . If some node is unreachable from , print  as the distance to that node.

Sample Input

2
4 2
1 2
1 3
1
3 1
2 3
2
Sample Output

6 6 -1
-1 6
Explanation

We perform the following two queries:

The given graph can be represented as:
image
where our start node, , is node . The shortest distances from  to the other nodes are one edge to node , one edge to node , and there is no connection to node .
The given graph can be represented as:
image
where our start node, , is node . There is only one edge here, so node  is unreachable from node  and node  has one edge connecting it to node . We then print node 's distance to nodes  and  (respectively) as a single line of space-separated integers: -1 6.

Note: Recall that the actual length of each edge is , and we print  as the distance to any node that's unreachable from . */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <list>
#include <climits>
using namespace std;
typedef pair<int,int> pi;

class Graph {
    unordered_map<long,list<long>> adj;
    unordered_map<long,bool> visited;
    unordered_map<long,long> prev;
    int nodes;
    unordered_map<long,long> m;
    public:
        Graph(int n) {
            nodes=n;
        }
    
        void add_edge(int u, int v) {
            adj[u].push_back(v);
            adj[v].push_back(u);  
            
        }
        void BFS(int start){
            priority_queue<pi,vector<pi>,greater<pi>>pq;
            pi current = {0,start};
            pq.push(current);
            
            while(!pq.empty()){
                current = pq.top();
                pq.pop();
                for(auto x : adj[current.second]){
                    
                    if(m[x]>current.first+6){
                        m[x]=current.first+6;
                        prev[x]=current.second;
                        pq.push({m[x],x});
                    }
                    
                    
                }
                //visited[current.second]=true;
            }
            
            
        }
/*         void DFS(long current,long distance){
            visited[current]=true;
            if(m[current]==0){
                m[current]=distance;
            }else if(m[current]>distance){
                m[current]=distance;
            }
            
            for(auto x: adj[current]){
                if(!visited[x]){
                    DFS(x,distance+6);
                }
            }
        } */
        void DFS(long current){
            visited[current]=true;
    
            for(auto x: adj[current]){
                if(!visited[x]){
                    if(m[x]>m[current]+6){
                        m[x]=m[current]+6;    
                    } else if (m[x]==-1){
                        m[x]=m[current]+6;
                    } else if (m[x]<=m[current]+6){
                        
                    }
                    
                    DFS(x);
                    
                }
            }
            //visited[current]=true;
        }
        vector<int> shortest_reach(int start) {
            for(int i =0; i<nodes;i++){
                m[i]=INT_MAX;
            }
            m[start]= 0;
            BFS((long)start);
            vector<int> minDist;
            for(int i =0 ; i < nodes ; i++){
                if(m[i]==INT_MAX){
                    minDist.push_back(-1);
                }else{
                    minDist.push_back(m[i]);  
                }
                 
            }
            return minDist;
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
