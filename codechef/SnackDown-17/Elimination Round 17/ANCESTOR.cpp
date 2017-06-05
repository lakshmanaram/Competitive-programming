// Bfs template - everything is 0 indexed
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
struct gnode{
    long ans;
    long rank;
    set<long> children;
    set<long> parent;
};
class dgraph{
    public:
    long nodes;
    vector<bool> vis;
    vector<gnode> gnodes;
    vector<pair<long, long > > ans;
    dgraph(long k){
        nodes = k;
        gnodes.resize(k);
        vis.resize(k);
        fill(vis.begin(),vis.end(),false);
        for(long i=0;i<k-1;i++){
            long a,b;
            cin>>a>>b;
            add_node(a-1,b-1);
        }
        dfs(0);
     }
    void dfs_recurse(long n){
        set<long>::iterator it;
        for(it = gnodes[n].children.begin();it!=gnodes[n].children.end();it++)
            if(vis[*it]==false){
                vis[*it] = true;
                dfs_recurse(*it);
                ans.push_back(mp(n,*it));
            }
    }
    void dfs(long n){
        vis.resize(nodes,false);
        fill(vis.begin(),vis.end(),false);
        vis[n] = true;
        dfs_recurse(n);
    }
    void add_node(long c, long k){
        gnodes[c].children.insert(k);
        gnodes[k].children.insert(c);
    }
};
class graph{
    public:
    long nodes;
    vector<bool> vis;
    vector<gnode> gnodes;
    graph(long n){
        nodes = n;
        gnodes.resize(n);
        vis.resize(n);
        fill(vis.begin(),vis.end(),false);
        dgraph a(n);
        for(long i=0;i<a.ans.size();i++) {
            // cout<<a.ans[i].first<<" "<<a.ans[i].second<<endl;
            add_node(a.ans[i].first,a.ans[i].second);
        }
        dgraph b(n);
        for(long i=0;i<b.ans.size();i++) {
            // cout<<b.ans[i].first<<" "<<b.ans[i].second<<endl;
            add_node(b.ans[i].first,b.ans[i].second);
        }
    }
    queue<pair<long,long> > q;
    void bfs_recurse(){
        while(!q.empty()){
            pair<long,long> n = q.front();
            q.pop();
            set<long>::iterator it;
            for(it = gnodes[n.first].children.begin();it!=gnodes[n.first].children.end();it++)
                if(vis[*it]==false){
                    vis[*it] = true;
                    q.push(mp(*it,n.second+1));
                }

            gnodes[n.first].ans = n.second;
        }
    }
    void bfs(long n){
        vis.resize(nodes,false);
        fill(vis.begin(),vis.end(),false);
        q.push(mp(n,0));
        vis[n] = true;
        bfs_recurse();
    }
    void add_node(long c, long k){                                                //initializes graph nodes 0-indexed
        // cout<<c<<" "<<k<<endl;
        gnodes[c].children.insert(k);
        gnodes[k].parent.insert(c);
    }
    void display_values() {
        for(long i=0;i<nodes;i++) {
            cout<<gnodes[i].ans<<" ";
        }
        cout<<endl;
    }
};
int main(){
    long t;
    cin>>t;
    while(t--) {
        long n;
        cin>>n;
        graph g(n);
        g.bfs(0);
        g.display_values();
    }
    return 0;
}
