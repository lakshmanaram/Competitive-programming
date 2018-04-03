// dfs template - everything is 0 indexed
#include<bits/stdc++.h>
using namespace std;
vector<bool> vis;
struct gnode{
    long long key;
    vector<pair<long, char> > children;
};
class graph{
    public:
    int nodes;
    vector<gnode> gnodes;
    graph(int k){
    	nodes = k;
    	gnode temp;
    	temp.key = 0;
        gnodes.resize(k, temp);
        vis.resize(k);
        fill(vis.begin(),vis.end(),false);
    }
    void dfs_recurse(int n){
        auto it = gnodes[n].children.begin();
        for(;it!=gnodes[n].children.end();it++)
            if(vis[it->first]==false){
                vis[it->first] = true;
                dfs_recurse(it->first);
            }
    }
    void dfs(long n){
        vis[n] = true;
        dfs_recurse(n);
    }
    void add_node(int c, int k, char c){
        gnodes[c].children.push_back(mp(k, c));
    }
};
int main(){
    int n,e;
    cin>>n;
    cin>>e;
    graph g(n);
    for(int i=0;i<e;i++){
        int a,b;
        char c;
        cin>>a>>b>>c;
        g.add_node(a-1, b-1, c);
    }
    for(long i=0;i<n;i++){
    	if(!vis[i]){
    		g.dfs(i);
    	}
    }
    // g.display_values();
    return 0;
}
