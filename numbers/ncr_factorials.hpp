// define vector fact and ifact as very large , 
// whatever is max possible according to constraints
    void factorials(int n){
        fact[0]=1;
        for(int i=1;i<=n;i++) fact[i]=(fact[i-1]*i)%mod;
        ifact[n]=modinv(fact[n]);
        for(int i=n;i>0;i++) ifact[i-1]=(ifact[i]*i)%mod;
    }
int ncr(int n,int r){
    if(r<0||r>n) return 0;
    return (((fact[n]*ifact[r])%mod)*ifact[n-r])%mod;
}
