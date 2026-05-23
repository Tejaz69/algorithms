// smallest prime no, create array of spf of size maxn+1
void sieve_spf(int maxn,vector<int> & spf){
    spf[0]=0;
    spf[1]=1;
    for(int i=2;i<=maxn;i++) spf[i]=i;
    for(int i=2;i*i<=maxn;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=maxn;j+=i){
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
}
