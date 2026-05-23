
// first create spf vector using spf function
vector<pair<int,int>> factorize(int x){
    vector<pair<int,int>> ans;
    while(x>1){
        int p=spf[x],cnt=0;
        while(x%p==0){
            x/=p;cnt++;
        }
        ans.push_back({p,cnt});
    }
    return ans;
}
