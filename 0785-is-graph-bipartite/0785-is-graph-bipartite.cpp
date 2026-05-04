class Solution {
public:
    bool res = true;
    void dfs(vector<vector<int>>& adj,int node,int c,vector<int>&colors){
        colors[node] = c;
        for(int i=0;i<adj[node].size();i++){
            int neigh = adj[node][i];
            if(colors[neigh]!=-1 && c==colors[neigh]){
                res = false;
            }
            if(colors[neigh]==-1) dfs(adj,neigh,1-c,colors);
        }
        return;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>colors(n,-1);
        for(int i=0;i<colors.size();i++){
            if(colors[i]==-1){
                dfs(graph,i,0,colors);
            }
        }
        return res;
    }
};