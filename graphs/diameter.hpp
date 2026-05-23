void bfs(vector<vector<int>>  & adj,int u,vector<int> & d){
    queue<int> q;
    q.push(u);d[u]=0;
    while(!q.empty()){
      int v=q.front();q.pop();
        for(auto x:adj[v]){
            if(d[x]==-1){
                q.push(x);
                d[x]=d[v]+1;
            }
        }
    }
}
int diameter(vector<vector<int>> & adj,int n){
    vector<int> d(n,-1);
    bfs(adj,0,d);
    int u=-1,mx=-1;
    for(int i=0;i<n;i++){
        if(d[i]>mx){
            mx=d[i],u=i;
        }
    }
    for(int i=0;i<n;i++) d[i]=-1;
    bfs(adj,u,d);
    u=-1,mx=-1;
     for(int i=0;i<n;i++){
        if(d[i]>mx){
            mx=d[i],u=i;
        }
    }
    return mx;
}
