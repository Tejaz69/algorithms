// define f outside
void sparse(const vector<int>& a,int n,vector<vector<int>>& b,int lg){
    for(int i=1;i<lg;i++){
        for(int j=0;j+(1<<i)-1<n;j++){
            b[j][i]=f(b[j][i-1],b[j+(1<<(i-1))][i-1]);
        }
    }
}
int query(vector<vector<int>> &b,int l,int r){
    int i=((63-__builtin_clzll(r-l+1)));
    return f(b[l][i],b[r-(1<<i)+1][i]);
}