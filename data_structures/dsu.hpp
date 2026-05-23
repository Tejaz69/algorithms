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
