    void dfs1(vector<vector<int>>& adj,int u,vector<bool>& visited,stack<int>& st){
        visited[u]=true;
        for(auto x:adj[u]){
            if(not visited[x]){
                dfs1(adj,x,visited,st);
            }
        }
        st.push(u);
    }
    void dfs2(vector<vector<int>>& rev_adj,int u,vector<bool>& visited,vector<int>& components){
        visited[u]=true;
        components.pb(u);
        for(auto x:rev_adj[u]){
            if(not visited[x]){
                dfs2(rev_adj,x,visited,components);
            }
        }
    }
    vector<vector<int>> kosaraju(vector<pair<int,int>>& edges,int n){
        vector<vector<int>> adj(n),rev_adj(n);
        for(auto& [u,v]:edges){
            adj[u].pb(v);
            rev_adj[v].pb(u);
        }
        vector<bool> visited(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            if(not visited[i]){
                dfs1(adj,i,visited,st);
            }
        }
        fill(all(visited),false);
        vector<vector<int>> scc;
        while(not st.empty()){
            int u=st.top();
            st.pop();
            if(not visited[u]){
                vector<int> component;
                dfs2(rev_adj,u,visited,component);
                scc.pb(component);
            }
        }
        return scc;
    }
