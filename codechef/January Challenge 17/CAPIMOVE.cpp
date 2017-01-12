// dfs template - everything is 0 indexed
#include <bits/stdc++.h>
#define mp make_pair 
using namespace std;
vector<bool> vis;
struct gnode{
    long long key;
    vector<int> children;
};
class graph{
    public:
    long nodes;
    vector<gnode> gnodes;
    vector<pair<long long, long> > keys;
    graph(long k){
    	nodes = k;
        gnodes.resize(k);
        vis.resize(k);
        fill(vis.begin(),vis.end(),false);
        for(long i=0;i<nodes;i++){
        	cin>>gnodes[i].key;
            keys.push_back(mp(gnodes[i].key,i));
        }
        sort(keys.begin(),keys.end());
        reverse(keys.begin(),keys.end());
    }
    long dfs(long n){
        vis.resize(nodes,false);
        vis[n] = true;
        vector<int>::iterator it;
        for(it = gnodes[n].children.begin();it!=gnodes[n].children.end();it++)
            vis[*it] = true;
        long ans = 0;
        for(long i=0;i<keys.size();i++) {
            if(!vis[keys[i].second]){
                ans = keys[i].second+1;
                break;
            }
        }
        vis[n] = false;
        for(it = gnodes[n].children.begin();it!=gnodes[n].children.end();it++)
            vis[*it] = false;
        return ans;
            
    }
    void add_node(int c, int k){
        gnodes[c].children.push_back(k);
        gnodes[k].children.push_back(c);
    }
};
int main(){
    int t;
    cin>>t;
    while(t--) {
        long n;
        cin>>n;
        graph g(n);
        for(long i=1;i<n;i++){
            int a,b;
            cin>>a>>b;
            g.add_node(a-1,b-1);
        }
        for(long i=0;i<n;i++){
            cout<<g.dfs(i)<<" ";
        }
        cout<<endl;
    }
    return 0;
}
