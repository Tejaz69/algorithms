

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
    vector<vector<int>> exp(vector<vector<int>> base,int power){
        int n=base.size();
        vector<vector<int>> result(n, vector<int>(n, 0));
        for (int i=0;i<n;i++) result[i][i]=1;
        while(power>0) {
            if(power&1) {
                vector<vector<int>> vc(n,vector<int> (n));
                mult(result,n,n,base,n,vc);
                result=vc;   
            }
            vector<vector<int>> vec(n,vector<int> (n));
            mult(base,n,n,base,n,vec);
            base=vec;
            power>>=1;
        }
        return result;
    }
