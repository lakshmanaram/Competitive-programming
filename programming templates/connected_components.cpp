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
    vector<pair<long,long> > conn_comps;
    graph(long k){
    	nodes = k;
        gnodes.resize(k);
        vis.resize(k);
        fill(vis.begin(),vis.end(),false);
    }
    void dfs_recurse(long n, long &con_nodes, long &con_edges){
        vector<long>::iterator it;
        for(it = gnodes[n].children.begin();it!=gnodes[n].children.end();it++){
            if(vis[*it]==false){
                vis[*it] = true;
                con_nodes++;
                dfs_recurse(*it,con_nodes,con_edges);
            }
            con_edges++;
        }
    }
    void add_node(long c, long k){
        gnodes[c].children.push_back(k);
        gnodes[k].children.push_back(c);
    }
    void display_values() {
        cout<<"The values stored in graph are : "<<endl;
        for(long i = 0; i < gnodes.size() ; i++){
            for(long j = 0; j < gnodes[i].children.size() ; j++){
                cout<<gnodes[i].children[j]<<" ";
            }
            cout<<endl;
        }
    }
    void get_conn_comps(){
        vis.resize(nodes,false);
        fill(vis.begin(),vis.end(),false);
        for(long i=0;i<nodes;i++){
            if(!vis[i]){
                vis[i] = true;
                long con_nodes = 1, con_edges = 0;
                dfs_recurse(i,con_nodes,con_edges);
                con_edges /= 2;
                conn_comps.pb(mp(con_nodes,con_edges));
            }
        }
    }
    void display_conn_comps() {
        for(long i=0;i<conn_comps.size();i++) {
            cout<<"nodes = "<<conn_comps[i].first<<" ";
            cout<<"edges = "<<conn_comps[i].second<<endl;
        }
    }
};
int main(){
    long n,e;
    cin>>n;
    cin>>e;
    graph g(n);
    for(long i=0;i<e;i++){
        long a,b;
        cin>>a>>b;
        g.add_node(a,b);
    }
    g.get_conn_comps();
    g.display_conn_comps();
    return 0;
}
