class Solution {
public:
    bool res = true;
    void dfs(vector<vector<int>>& adj,int node,int c,vector<int>&colors){
        if(!res) return;
        colors[node] = c;
        for(int i=0;i<adj[node].size();i++){
            int neigh = adj[node][i];
            if(colors[neigh]!=-1 && colors[neigh]==c){
                res = false;
            }
            else if(colors[neigh]==-1){
                dfs(adj,neigh,1-c,colors);
            }   
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>colors(n,-1);
        for(int i=0;i<n;i++){
            if(colors[i]==-1){
                dfs(graph,i,0,colors);
            }
        }
        return res;
    }
};