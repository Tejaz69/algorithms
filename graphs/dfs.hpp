// adj is adjacency matrix
// u is root
// visited array marks which have already been visited
void dfs(vector<vector<int>> & adj,int u,vector<bool> & visited){
    visited[u]=true;
    for(auto x:adj[u]){
        if(!visited[x]){
            dfs(adj,x,visited);
        }
    }
}
