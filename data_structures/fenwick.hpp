struct fenwick{
    int n;
    vector<int> f;
    fenwick(int n){
        this->n=n;
        f.assign(n,0);  
    }
    fenwick(const vector<int>& a):fenwick(a.size()){
        for(int i=0;i<a.size();i++){
            f[i]+=a[i];
            int r=i|(i+1);
            if(r<n) f[r]+=f[i];
        }
    }
    int sum(int r){
        int ans=0;
        while(r>=0){
            ans+=f[r];
            r=(r&(r+1))-1;
        }
        return ans;
    }
    int sum(int l,int r){
       if(l>0) return sum(r)-sum(l-1);
       else return sum(r);
    }
    void edit(int ind,int diff){
        while(ind<n){
            f[ind]+=diff;
            ind=ind|(ind+1);
        }
    }
};  
