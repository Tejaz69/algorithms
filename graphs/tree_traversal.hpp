// adj is adjacency matrix
// u is root
// visited array marks which have already been visited
void dfs(vector<vector<int>> & adj,int u,vector<bool> & visited,vector<int>& tt,vector<int>& sub){
    visited[u]=true;
    tt.pb(u);
    sub[u]=1;
    for(auto x:adj[u]){
        if(!visited[x]){
            dfs(adj,x,visited,tt,sub);
            sub[u]+=sub[x];
        }
    }
}
