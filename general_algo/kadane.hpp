    // always check case of whether or not possible to take no element
    int kadane(vector<int> & a,int n){
        int best=a[0],curr=a[0];
        for(int i=1;i<n;i++){
            curr=max(a[i],a[i]+curr);
            best=max(best,curr);
        }
    }
