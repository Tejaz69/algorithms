//no negative weights
//initialisze d array to infinity
void dijkstra(vector<vector<pair<int,int>>> & adj,int u,vector<int> & d){
    d[u]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0LL,u});
    while(!pq.empty()){
        pair<ll,int> v=pq.top();pq.pop();
        if(v.first>d[v.second]) continue;
        for(auto x:adj[v.second]){
            
                    if(d[x.first]>v.first+x.second){
                        d[x.first]=v.first+x.second;
                        pq.push({d[x.first],x.first});
                    }
            
        }
    }
}
