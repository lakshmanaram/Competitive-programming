#include <bits/stdc++.h>
using namespace std;
struct gnode{
    bool parity;
    set<pair<int, long> > children;
};
class graph{
    public:
    long nodes;
    vector<bool> vis;
    vector<gnode> gnodes;
    graph(long k){
    	nodes = k;
        gnodes.resize(k);
        vis.resize(k);
    }
    bool dfs_recurse(long n, bool p){
        gnodes[n].parity = p;
        bool curp;
        set<pair<int, long> >::iterator it;
        for(it = gnodes[n].children.begin();it!=gnodes[n].children.end();it++) {
            if(it->first == 1) curp = !p;
            else curp = p;
            if(!vis[it->second]){
                vis[it->second] = true;
                dfs_recurse(it->second, curp);
            }
            if(gnodes[it->second].parity != curp) return false;  
        }
        return true;
    }
    bool dfs(){
        fill(vis.begin(),vis.end(),false);
        for(long i=0;i<vis.size();i++) {
            if(vis[i]) continue;
            vis[i] = true;
            if(!dfs_recurse(i, true)) return false;
        }
        return true;
    }
    void add_node(long c, long k, int v){
        gnodes[c].children.insert(make_pair(v,k));
        gnodes[k].children.insert(make_pair(v,c));
    }
};
int main(){
    long t;
    cin>>t;
    while(t--){
        long n,e;
        cin>>n;
        cin>>e;
        bool ans = true;
        graph g(n);
        map<pair<long, long>, int> m;
        for(long i=0;i<e;i++){
            long a,b,v;
            cin>>a>>b>>v;
            if(m.find(make_pair(min(a,b), max(a,b))) != m.end()){
                if(v != m[make_pair(min(a,b), max(a,b))]) ans = false;
                continue;
            }
            m[make_pair(min(a,b), max(a,b))] = v;
            if(a == b){
                if(v!=0)
                    ans = false;
                continue;
            }
            else g.add_node(a-1,b-1,v);
        }
        if(!ans) cout<<"no\n";
        else if(g.dfs()) cout<<"yes\n";
        else cout<<"no\n";
    }
    // g.display_values();
    return 0;
}
