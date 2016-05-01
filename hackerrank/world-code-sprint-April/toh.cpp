#include <bits/stdc++.h>
using namespace std;
struct tstate{
    stack<int> t[4];
    long stackst;
};
vector<int> vis(1048576,-1);
int n;
queue<long> bfsq;
tstate get_state(long a){
    tstate result;
    result.stackst = a;
    for(int i = n-1;i>=0;i--){
        result.t[a%4].push(i);
        a /= 4;
    }
    return result;
}
long fstring;
long bfsValue;
void bfs_recurse(){
    if(bfsq.empty()){
        bfsValue = -2;
        return;
    }
    long c = bfsq.front();
    bfsq.pop();
    tstate cur = get_state(c);
    if(cur.stackst == fstring){
        bfsValue = vis[c];
        return;
    }
    for(int i=0;i<4;i++){
        if(cur.t[i].empty())
            continue;
        for(int j=0;j<4;j++){
            if(i==j)
                continue;
            else if(cur.t[j].empty() || cur.t[i].top() < cur.t[j].top()){
                tstate temp = cur;
                int change = temp.t[i].top();
                long tp = j-i;
                for(int k = 0; k< n-change-1;k++){
                    tp*=4;
                }
                temp.stackst += tp;
                if(vis[temp.stackst] == -1){
                    vis[temp.stackst] = vis[c]+1;
                    bfsq.push(temp.stackst);
                }
            }
        }
    }
    return;
}
int main(){
    cin >> n;
    fstring = 0;
    bfsValue = -1;
    for(int i = 0;i < n;i++){
        int x;
        cin>>x;
        fstring *= 4;
        fstring += (x-1);
    }
    vis[0] = 0;
    bfsq.push(0);
    while(bfsValue == -1){
        bfs_recurse();
    }
    cout<<bfsValue;

    cout<<endl<<endl;
    for(int i=0;i<vis.size();i++){
        if(vis[i] == 42){
            cout<<i<<",";
        }
    }
    return 0;
}
