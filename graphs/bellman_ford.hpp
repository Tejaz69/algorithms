// to detect negative cycle, run for one more round, if some ans change that means negative cycle
void bellman_ford(vector<tuple<int,int,int>>& edges,int x,int n){
    vector<int> d(n,inf);
    d[x]=0;
    for(int i=1;i<=n-1;i++){
        for(auto& [a,b,c] :edges){
            
            if(d[a]!=inf) d[b]=min(d[b],d[a]+c);
        }
    }

}
