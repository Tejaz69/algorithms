struct lca{
    vector<int> ht,euler,first,segtree;
    vector<bool> visited;
    lca(vector<vector<int>>& adj,int root=0){
        int n=adj.size();   
        ht.resize(n);
        visited.assign(n, false);
        first.resize(n);
        euler.reserve(2*n);
        dfs(adj,root);
        int m=euler.size();
        segtree.resize(4*m);
        build(1,0,m-1);
    }
    void dfs(vector<vector<int>>& adj,int node,int h=0){
        visited[node]=true;
        ht[node]=h;
        first[node]=euler.size();
        euler.pb(node);
        for(auto to:adj[node]){
            if(!visited[to]){
                dfs(adj,to,h+1);
                euler.pb(node);
            }
        }
    }
    void build(int node,int b,int e){
        if(b==e){
            segtree[node]=euler[b];
        }
        else{
            int mid=(b+e)/2;
            build(node<<1,b,mid);
            build((node<<1)|1,mid+1,e);
            int l=segtree[node<<1],r=segtree[(node<<1)|1];
            segtree[node]=(ht[l]<ht[r])?l:r;
        }
    }
    int query(int node,int b,int e,int l,int r){
        if(b>r||e<l){
            return -1;

        }
        if(b>=l&&e<=r){
            return segtree[node];
        }
        int mid=(b+e)>>1;
        int left=query(node<<1,b,mid,l,r);
        int right=query((node<<1)|1,mid+1,e,l,r);
        if(left==-1) return right;
        if(right==-1) return left;
        return ht[left]<ht[right]?left:right;
    }
    int lowest(int u,int v){
        int left=first[u],right=first[v];
        if(left>right) swap(left,right);
        return  query(1,0,euler.size()-1,left,right);
    }
};
