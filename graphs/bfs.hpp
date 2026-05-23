// always inititalize d to all -1(distance array)
// adj is adjacency list
// u is the point from which we start bfs
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
