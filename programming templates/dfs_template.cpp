// dfs template - everything is 0 indexed
#include<bits/stdc++.h>
using namespace std;
vector<bool> vis;
struct gnode{
    long long key;
    vector<int> children;
};
class graph{
    public:
    int nodes;
    vector<gnode> gnodes;
    graph(int k){
    	nodes = k;
        gnodes.resize(k);
        vis.resize(k);
        fill(vis.begin(),vis.end(),false);
        for(int i=0;i<nodes;i++){
        	cin>>gnodes[i].key;
        }
    }
    void dfs_recurse(int n){
        vector<int>::iterator it;
        for(it = gnodes[n].children.begin();it!=gnodes[n].children.end();it++)
            if(vis[*it]==false){
                vis[*it] = true;
                dfs_recurse(*it);
            }
    }
    void dfs(int n){
        vis.resize(nodes,false);
        fill(vis.begin(),vis.end(),false);
        vis[n] = true;
        dfs_recurse(n);
    }
    void add_node(int c, int k){
        gnodes[c].children.push_back(k);
        gnodes[k].children.push_back(c);
    }
    void display_values(){
        cout<<"The values stored in graph are : "<<endl;
        for(int i = 0; i < gnodes.size() ; i++){
            for(int j = 0; j < gnodes[i].children.size() ; j++){
                cout<<gnodes[i].children[j]<<" ";
            }
            cout<<endl;
        }
    }
};
int main(){
    int n,e;
    cin>>n;
    cin>>e;
    graph g(n);
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        g.add_node(a,b);
    }
    g.dfs(0);
    // g.display_values();
    return 0;
}
