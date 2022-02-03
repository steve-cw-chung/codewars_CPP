//implementation of dijkstra with priority queue

#include<iostream>
#include<climits>
#include<list>
#include<queue>

using namespace std;

  
// iPair ==>  Integer Pair
typedef pair<int, int> iPair;

class Graph
{
    int V;    // No. of vertices
  
    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    list< pair<int, int> > *adj;
  
public:
    Graph(int V);  // Constructor
  
    // function to add an edge to graph
    void addEdge(int u, int v, int w);
  
    // prints shortest path from s
    void shortestPath(int s);
    void printPath(vector<int>,int);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list< pair<int,int> > [V];
}

void Graph::addEdge(int u, int v, int w){
    adj[u].push_back( pair<int,int> (v,w));
    adj[v].push_back( pair<int,int> (u,w));

}
void Graph::printPath(vector<int> prev , int dest){
    if(prev[dest]==-1) return;
    printPath(prev,prev[dest]);
    cout << dest << " " ;
}
void Graph::shortestPath(int src){
    //make priority queue
    priority_queue <iPair, vector<iPair>, greater<iPair> > pq;
    vector<int> dist (V,INT_MAX);
    vector<int> prev (V,-1);
    
    pq.push(pair<int,int>(0,src));
    dist[src]= 0;

    //loop til priority queue is empty 
    while (!pq.empty()){
        //get the first item in the queue
        int u = pq.top().second;
        pq.pop();
        list <pair<int,int> >::iterator i ;
        for(i = adj[u].begin() ; i!=adj[u].end() ; i++){
            //get vertex and weight of neighbor
            int v = i->first;
            int w = i->second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u]+w;
                prev[v] = u;
                pq.push(pair<int,int>(dist[v],v));
            }
        }
    }
    //print shortest distance stored in dist[]
    cout << "distance from source " << endl;
    for(int i =0; i <V ; i++){
        cout << (char)(65+i) << " : " << dist[i] <<endl;
        printPath(prev,i);
        cout <<endl;
    }


}

// Driver program to test methods of graph class
int main()
{
    // create the graph given in above fugure
    int V = 9;
    Graph g(V);
  
    //  making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
  
    g.shortestPath(0);
  
    return 0;
}