struct min_q{
    stack<pair<int,int>> st1,st2;
    void push(int x){
        if(st1.empty()) st1.push({x,x});
        else{
            int mn=st1.top().second;
            st1.push({x,min(mn,x)});
        }
    }
    int mn(){
        if(st1.empty()){
            if(st2.empty()) return -1;
            else return st2.top().second;
        }
        else{
            if(st2.empty()) return st1.top().second;
            else return min(st1.top().second,st2.top().second);
        }
    }
    int pop(){
        if(st2.empty()){
            while(!st1.empty()){
                pair<int,int> tp=st1.top();
                st1.pop();
                if(st2.empty()){
                    st2.push(tp);
                }
                else{
                    int mn=st2.top().second;
                    st2.push({tp.first,min(tp.first,mn)});
                }
            }
        }
        pair<int,int> p=st2.top();
        st2.pop();
        return p.first;
    }
    int front(){
        if(st2.empty()){
            while(!st1.empty()){
                pair<int,int> tp=st1.top();
                st1.pop();
                if(st2.empty()){
                    st2.push(tp);
                }
                else{
                    int mn=st2.top().second;
                    st2.push({tp.first,min(tp.first,mn)});
                }
            }
        }
        pair<int,int> p=st2.top();
        return p.first;
    }
};
