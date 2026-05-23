// keep in mind n,m,p
// also define mod in global 
// final ans in ans , initialize ans to all 0
void mult(vector<vector<int>> & a,int n,int m,vector<vector<int>> & b,int p,vector<vector<int>> & ans){
        for(int i=0;i<n;i++){
            for(int k=0;k<m;k++){
                for(int j=0;j<p;j++){
                    ans[i][j]=(ans[i][j]+a[i][k]*b[k][j])%mod;
                }
            }
    }
}
