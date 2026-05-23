struct lazysum{
    vector<int> v;
    int n;
    lazysum(int nn) : n(nn),v(nn,0) {}
    void add(int l,int r,int val){
        if(l>r) return;
        v[l]+=val;
        if(r<n) v[r+1]-=val;
    }
    void add_clear(vector<int>& d){
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=v[i];
            v[i]=0;
            d[i]+=sum;
        }
    }
};
