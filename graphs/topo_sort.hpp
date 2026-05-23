vector<int> topo_sort(vector<vector<int>>& adj,int n){
    vector<int> in_deg(n);
    for(int i=0;i<n;i++){
        for(auto x:adj[i]) in_deg[x]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++) if(in_deg[i]==0) q.push(i);
    vector<int> topo;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        topo.pb(u);
        for(auto x:adj[u]){
            in_deg[x]--;
            if(in_deg[x]==0) q.push(x);
        }
    }
    if(topo.size()<n) {
        return {};
    }
    return topo;
}
