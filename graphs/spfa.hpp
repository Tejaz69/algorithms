// bool is false if negative cycle is found
pair<vector<int>,bool> spfa(vector<vector<pair<int,int>>>& adj,int n,int src){
    vector<int> d(n,inf),cnt(n);
    vector<bool> inQ(n);
    queue<int> q;
    d[src]=0;
    inQ[src]=true;
    q.push(src);
    cnt[src]++; 
    while(not q.empty()){
        int u=q.front();
        q.pop();
        inQ[u]=false;
        for(auto [w,v]:adj[u]){
            if(d[u]!=inf and d[u]+w<d[v]){
                d[v]=d[u]+w;
                cnt[v]++;
                if(cnt[v]>n){
                    return {d,false};
                }
                if(!inQ[v]) {
                    q.push(v);
                    inQ[v]=true;
                }
            }
        }
    }
    return {d,true};
}
