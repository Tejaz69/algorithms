// a is base, b is power
//  define mod as global variable
int binpow(int a,int b) {
    int res=1;
    while(b>0) {
        if(b&1)
            res=res*a;
        a=a*a;
        b>>=1;
    }
    return res;
}
int binpow(int a,int b,int mod) {
    int res=1;
    if(b==0) return 1;
    if(b==1) return a;
    int v=bipow(a,b/2);
   if(b&1) return (((v*v)%mod)*a)%mod;
   else return (v*v)%mod;
}
// only for prime numbers
int modinv(int a){
    return binpow(a,mod-2,mod);
}
