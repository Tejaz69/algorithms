struct sqrt_deco{
    int n,s;
    vector<int> a,b,c;
    sqrt_deco(vector<int>& arr){
        n=arr.size();
        s=(int)sqrt(n+.0)+1;
        a.assign(n,0);
        b.assign(s,0);
        c.assign(s,0);  
        for(int i=0;i<n;i++){
            a[i]=arr[i];
            b[i/s]+=arr[i];
        }
    }
    void range_add(int l,int r,int delta){
        int cl=l/s,cr=r/s;
        if(cl==cr){
            for(int i=l;i<=r;i++) a[i]+=delta;
            b[cl]+=delta*(r-l+1);
        }
        else{
            for(int i=l;i<(cl+1)*s;i++) a[i]+=delta;
            b[cl]+=delta*((cl+1)*s-l);
            for(int i=cl+1;i<cr;i++){
                c[i]+=delta;
                b[i]+=delta*s;
            }
            for(int i=cr*s;i<=r;i++) a[i]+=delta;
            b[cr]+=delta*(r-cr*s+1);
        }
    }
    int range_sum(int l,int r){
        int sum=0;
        int cl=l/s,cr=r/s;
        if(cl==cr){
            for(int i=l;i<=r;i++) sum+=a[i]+c[cl];
        }
        else{
            for(int i=l;i<(cl+1)*s;i++) sum+=a[i]+c[cl];
            for(int i=cl+1;i<cr;i++) sum+=b[i];
            for(int i=cr*s;i<=r;i++) sum+=a[i]+c[cr];
        }
        return sum;
    }
};
