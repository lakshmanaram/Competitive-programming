#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair
using namespace std;
vector<bool> vis;
struct gnode{
    vector<long> children;
};
class graph{
    public:
    long nodes;
    vector<gnode> gnodes;
    graph(long k){
        nodes = k;
        gnodes.resize(k);
        vis.resize(k);
        fill(vis.begin(),vis.end(),false);
    }
    void dfs_recurse(long n){
        vector<long>::iterator it;
        for(it = gnodes[n].children.begin();it!=gnodes[n].children.end();it++){
            if(vis[*it]==false){
                vis[*it] = true;
                dfs_recurse(*it);
            }
        }
    }
    void add_node(long c, long k){
        gnodes[c].children.push_back(k);
        gnodes[k].children.push_back(c);
    }
    long get_conn_comps(){
        vis.resize(nodes,false);
        fill(vis.begin(),vis.end(),false);
        long ans = 0;
        for(long i=0;i<nodes;i++){
            if(!vis[i]){
                vis[i] = true;
                dfs_recurse(i);
                ans++;
            }
        }
        return ans;
    }
};
int main() {
    long n;
    cin>>n;
    graph g(n);
    for(long i=0;i<n;i++){
        long a;
        cin>>a;
        g.add_node(i,a-1);
    }
    long ans = g.get_conn_comps();
    if(ans == 1)
        ans = 0;
    long none = 0;
    for(long i=0;i<n;i++){
        long a;
        cin>>a;
        if(a) none++;
    }
    ans += 1 - (none&1);
    cout<<ans;
 	return 0;
}