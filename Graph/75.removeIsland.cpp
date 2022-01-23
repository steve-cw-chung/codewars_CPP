#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<int>> input,vector<vector<bool>> &visited, vector<vector<int>> &continents,int x, int y){
    visited[y][x] = true;
    continents[y][x]=1;
    //check 4 directions [0,1],[0,-1],[1,0],[-1,0]
    // left check
    if(x-1>=0 && input[y][x-1]==1&&visited[y][x-1]==false){
        DFS(input,visited,continents,x-1,y);
    }
    // right check
    if(x+1<input[y].size()&&input[y][x+1]==1&&visited[y][x+1]==false){
        DFS(input,visited,continents,x+1,y);
    }
    // up check
    cout << " x : "<< x << " y: " << y << "check for going up once" <<endl;
    cout << "input[y][x] should equal 1 : " << input[y][x] << " " <<endl;
    cout << "visited[y][x] should equal 0 : " << visited[y][x] <<endl;
    if(y-1>=0 && input[y-1][x]==1&&visited[y-1][x]==false){
        cout << " x : "<< x << " y: " << y << "going up once" <<endl;
        DFS(input,visited,continents,x,y-1);
    }
    if(y+1<input.size() && input[y+1][x]==1 && visited[y+1][x]==false){
        DFS(input,visited,continents,x,y+1);
    }
    // down check

}

vector<vector<int>> removeIsland (vector<vector<int>> input){
    vector<vector<int>> continents;
    vector<vector<bool>> visited;
    //cout << "input.size() : " << input.size() <<endl;
    //cout << "input[0].size() : " << input[0].size() << endl;
   
    // Create the Continents(continent table) which the lands are touching the edges
    for(int y =0; y<input.size();y++){
        //cout << "in input y= " << y << endl;
        vector<bool> temp ;
        vector<int> temp2;
        for(int x=0; x<input[y].size();x++){
            //cout << "in input[y] x= "<< x <<endl;
            temp2.push_back(0);
            temp.push_back(false);
            //cout <<"in here"<< endl;
        }
        visited.push_back(temp);
        continents.push_back(temp2);
        temp2.clear();
        temp.clear();
    }
/*     for(int y = 0; y<visited.size();y++){
        for(int x= 0; x<visited[y].size();x++){
            cout << "visited[y][x] : " << visited[y][x] << " ";
        }
        cout <<endl;
    } */
    //cout <<"visited[0][0] : "<< visited[0][0];
    for(int y =0; y<input.size();y++){
        for(int x=0; x<input[y].size();x++){
            //cout << "input[y][x]" << input[y][x] << " ";
            if(y==0||y==input.size()-1||x==0 || x==input[y].size()-1){
                if(input[y][x]==1)
                continents[y][x]=1;
            }
        }
        //cout <<endl;
    }
    //DFS to visit every node from the continents 
    for(int y = 0; y<input.size();y++){
        for(int x = 0; x<input[y].size();x++){
            if(continents[y][x]==1 && visited[y][x]==false){
                cout << "Entering Continent : " << x << " " << y <<endl; 
                DFS(input, visited, continents,x,y);
            }
        }
    }
    


    return continents;
}

int main (){
    vector<vector<int>> noIsland;
    vector<vector<int>> input ={{1,0,0,0,1},{1,0,1,1,0},{0,0,1,0,1},{0,1,0,0,1},{0,1,1,1,0}};

    noIsland = removeIsland(input);
    for(int i =0; i< noIsland.size();i++){
        for(int j =0; j< noIsland[i].size();j++){
            cout << noIsland[i][j] << " " ;
        }
        cout <<endl;
    }   
    return 0;
}