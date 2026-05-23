
    // create check function 
        int l=-1,r=as;
        while(l+1<r){
            int mid=l+(r-l)/2;
            if(check(mid)){
                l=mid;
            }
            else{
                r=mid;
            }
        }
    

    
