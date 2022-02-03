//shortest path Dijkstra's algorithm

#include <iostream>
#include <climits>
using namespace std;
#define V 9


int minDistance(int dist[], bool visited[]){
    int minIndex;
    int minDistance=INT_MAX;
    for(int i = 0 ; i < V; i ++){
        if(dist[i]<=minDistance&&visited[i]==false){
            minIndex=i;
            minDistance=dist[i];
        }
    }
    return minIndex;
}

void printPath(int * prev, int dest){
    //Base Case : if destination is source 
    if(prev[dest]==-1) return;
    // recursively call printPath
    printPath(prev, prev[dest]);

    cout << dest << " " ;

    
}
void printSolution(int * dist,int*prev){
    for(int i =0 ; i< V; i++){
        cout << (char)(65+i) << " : " << dist[i] << "  " << endl;
        cout << "Path : " ;
        printPath(prev,i);
        cout << endl;
    }
}
void dijkstra(int graph[V][V], int src){

    //initialization
    int * distance = new int [V];
    bool * visited = new bool [V];
    int * prev = new int[V];

 
    for(int i = 0 ; i < V ; i++){
        distance[i] = INT_MAX;
        prev[i] = -1;
        visited[i] = false;
    }
    distance[src] = 0; // setting source to source distance to 0


    
    //loop V-1 times. This can be replaced with priority queue with minDistance
    for(int i = 0; i < V-1 ; i++){
        int minIndex = minDistance(distance, visited);
        visited[minIndex]=true;
        for(int j = 0; j < V; j++){
            if(j!=src){
                int alt = distance[minIndex]+graph[minIndex][j];
                if(!visited[j]&&graph[minIndex][j]&& distance[minIndex]!=INT_MAX&&alt<distance[j]){
                    distance[j]= alt;
                    prev[j] = minIndex;
                }
            }
        }
    }
    printSolution(distance,prev);
}
// driver program to test above function
int main()
{
  
    /* Let us create the example graph discussed above */
    int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    dijkstra(graph, 0);

    return 0;
}