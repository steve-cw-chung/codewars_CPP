/* You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps.

 

Example 1:

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"
Example 2:

Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"
Example 3:

Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination: 
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"
 

Constraints:

1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length
s only contains lower case English letters. */
/*class Solution {
public:
    void DFS(string s, vector<vector<int>>& pairs, int index,vector<int>& visited,vector<vector<int>>& connectedComponents, vector<int>& connectedComp){
        if(visited[index]==1){
            return;
        }
        visited[index]=1;
        connectedComp.push_back(index);
        for(int i =0; i<pairs.size();i++){
            if(pairs[i][0]==index){
                int pairIndex = pairs[i][1];
                //pairs.erase(pairs.begin()+i);
                //i--;
                DFS(s,pairs,pairIndex,visited,connectedComponents,connectedComp);
            }else if (pairs[i][1]==index){
                int pairIndex = pairs[i][0];
                //pairs.erase(pairs.begin()+i);
                //i--;
                DFS(s,pairs,pairIndex,visited,connectedComponents,connectedComp);
            }
        }
        
        
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        //get connected componets and then sort them 
        vector<vector<int>> connectedComponents;
        vector<int> connectedComp;
        vector<int> visited (s.length(),0);
        string smallestString = "";
        //DFS
        for(int i =0;i<visited.size();i++){
            if(visited[i]==0){
                DFS(s,pairs,i,visited,connectedComponents,connectedComp);
                sort(connectedComp.begin(),connectedComp.end());
                connectedComponents.push_back(connectedComp);
                connectedComp.clear();
            }
        }
        
        for(int i =0; i<connectedComponents.size();i++){
            string currString = "";
            for(int j = 0; j <connectedComponents[i].size();j++){
                //cout << connectedComponents[i][j] << " ";
                currString+=s[connectedComponents[i][j]];
            }
           // cout << endl;
            sort(currString.begin(),currString.end());
            for(int j = 0; j <connectedComponents[i].size();j++){
                s[connectedComponents[i][j]] = currString[j];
            }
        }
        
        return s;
    }
};*/
class Solution {
public:
    string ans;
    void dfs(int i, vector<int> &pos, vector<int> &vis, vector<vector<int>> &g) {   
        vis[i]++;
        pos.push_back(i);
        for(auto child: g[i]){
            if (!vis[child]) dfs(child, pos, vis, g);
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        ans = s;
        vector<vector<int>> g(n);
        for(auto i: pairs) {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++) {
            if (!vis[i]) {
                vector<int> pos;
                dfs(i, pos, vis, g);
                string tmp = "";
                for(auto c: pos) {
                    tmp += s[c];
                }
                sort(pos.begin(), pos.end());
                sort(tmp.begin(), tmp.end());
                for(int z = 0; z<pos.size(); z++) {
                    ans[pos[z]] = tmp[z];
                }
            }
        }
        return ans;
    }
};