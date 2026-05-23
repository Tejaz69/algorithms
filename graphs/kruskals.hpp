struct dsu{
    vector<int> parent;
    vector<int> sz;
    int components;
    dsu(int n){
        parent.resize(n);
        sz.resize(n);
        for(int i=0;i<n;i++) sz[i]=1,parent[i]=i;
        components=n;
    }
    int find(int v){    
        if(v==parent[v]) return v;
        return parent[v]=find(parent[v]);
    }
    void unite(int a,int b){
        a=findt(a),b=find(b);
        if(a!=b){
            if(sz[a]<sz[b]){
                swap(a,b);
            }
            parent[b]=a;
            sz[a]+=sz[b];
            components--;
        }
    }
};
struct edge{
    int u,v,weight;
    bool operator<(const edge& other){
        return weight<other.weight;
    }
};
int kruskal(vector<edge> edges,int n,vector<edge> ans){
    sort(all(edges));
    dsu d(n);
    int wt=0; // of min spanning tree
    for(const auto& e:edges){
        if(d.find(e.u)!=d.find(e.v)){
            d.unite(e.u,e.v);
            wt+=e.weight;
            ans.pb(e);

        }
    }
    if(d.components>1){
        return -1;
    }
    else return wt;
}