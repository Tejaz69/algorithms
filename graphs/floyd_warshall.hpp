// adj is adjacency matrix(all inf initially if no edge) , n is max index
// to detect negative cycles, check if d[i][j]<0 for some i,j
// initialize adj such that if no edge then inf
void floyd(vector<vector<int>> & adj,vector<vector<int>> & d,int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) d[i][j]=0;
                else if(adj[i][j]!=inf) d[i][j]=adj[i][j];
                else d[i][j]=inf;
            }
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                   if(d[i][k]<inf&&d[k][j]<inf) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                }
            }
        }
}
