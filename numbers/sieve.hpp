
// always define is_prime as all true outside, size of it such that can store no till n
// n is till what no we need primes, a is array storing primes
void sieve(int n,vector<int> & a,vector<bool> & is_prime){
    is_prime[0]=is_prime[1]=false;
    for(int i=2;i<=n;i++){
        if(is_prime[i]){
            a.push_back(i);
            if(i<=n/i){
            for(int j=i*i;j<=n;j+=i){
                is_prime[j]=false;
            }
         }
    }
    }
}
