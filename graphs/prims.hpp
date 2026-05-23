vector<int> prims(vector<vector<pair<int,int>>>& adj,int n,int src){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> key(n,inf),parent(n,-1);
    vector<bool> inMST(n,false);
    key[src]=0;
    pq.push(mp(0,src));
    while(!pq.empty()){
        int u=pq.top().S;
        pq.pop();
        if(inMST[u])  continue;
        inMST[u]=true;
        for(auto [w,v]:adj[u]){
            if(not inMST[v] and w<key[v]){
                key[v]=w;
                parent[v]=u;
                pq.push(mp(key[v],v));
            }
        }
    }
    return parent;
}
