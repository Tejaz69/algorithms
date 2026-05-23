int merge_count(vector<int> & a,int l, int mid,int r){
    int count=0;
    vector<int> pre,suff,b;
    for(int i=l;i<=mid;i++) pre.pb(a[i]);
    for(int i=mid+1;i<=r;i++) suff.pb(a[i]);
    int p1=0,p2=0;
    while(p1<=mid-l&&p2<=r-mid-1){
        while(p2<=r-mid-1&&pre[p1]>suff[p2]){
            p2++;b.pb(suff[p2-1]);
        }
        b.pb(pre[p1]);
        count+=p2;
        p1++;
    }
    while(p1<=mid-l) b.pb(pre[p1]),count+=p2,p1++;
    while(p2<=r-mid-1) b.pb(suff[p2]),p2++;
    for(int i=l;i<=r;i++) a[i]=b[i-l];
    return count;
}
 int inversions(vector<int>& a,int l,int r){
    if(l>=r) return 0;
    int mid=l+(r-l)/2;
    int ans=inversions(a,l,mid)+inversions(a,mid+1,r);
    ans+=merge_count(a,l,mid,r);
    return ans;
}
