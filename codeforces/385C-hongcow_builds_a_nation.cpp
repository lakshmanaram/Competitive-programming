#include<bits/stdc++.h>
using namespace std;
vector<bool> vis;
struct gnode{
    bool imp;
    vector<int> children;
};
bool comp(pair<int, long> a, pair<int, long> b){
    if(a.first > b.first)
        return true;
    else if(a.first < b.first)
        return false;
    if(a.second < b.second)
        return true;
    return false;
}
class graph{
    public:
    int nodes;
    int governments;
    vector<pair<int, long> > free_nodes, government_nodes;
    vector<gnode> gnodes;
    graph(int k){
    	nodes = k;
        gnode temp;
        temp.imp = false;
        gnodes.resize(k,temp);
        vis.resize(k);
        fill(vis.begin(),vis.end(),false);
        cin>>governments;
        for(int i=0;i<governments;i++){
            int x;
            cin>>x;
            gnodes[x-1].imp = true;
        }
    }
    void dfs_recurse(int n, int &nodes, long &edges, bool &govern){
        if(gnodes[n].imp)
            govern = true;
        vector<int>::iterator it;
        nodes++;
        edges+=gnodes[n].children.size();
        for(it = gnodes[n].children.begin();it!=gnodes[n].children.end();it++)
            if(vis[*it]==false){
                vis[*it] = true;
                dfs_recurse(*it,nodes,edges,govern);
            }

    }
    pair<bool,pair<int, long> > dfs(int n){
        vis[n] = true;
        int nodes = 0;
        long edges = 0;
        bool govern = false;
        dfs_recurse(n,nodes,edges,govern);
        edges/=2;
        return make_pair(govern,make_pair(nodes,edges));
    }
    void add_node(int c, int k){                                                //initializes graph nodes 0-indexed
        gnodes[c-1].children.push_back(k-1);
        gnodes[k-1].children.push_back(c-1);
    }
    long long find_ans(){
        for(long i=0;i<gnodes.size();i++) {
            if(vis[i])
                continue;
            pair<bool,pair<int, long> > components = dfs(i);
            if(components.first == true){
                government_nodes.push_back(components.second);
            } else {
                free_nodes.push_back(components.second);
            }
        }
        sort(government_nodes.begin(),government_nodes.end(),comp);
        int fn = 0;
        long fe = 0;
        for(int i=0;i<free_nodes.size();i++){
            fn += free_nodes[i].first;
            fe += free_nodes[i].second;
        }
        long ns = fn + government_nodes[0].first;
        long long ans = ns*(ns-1)/2;
        ans -= fe+government_nodes[0].second;
        for(long i=1;i<government_nodes.size();i++){
            ans += government_nodes[i].first*(government_nodes[i].first-1)/2;
            ans -= government_nodes[i].second;
        }
        return ans;
    }
};
int main(){
    int n;
    long e;
    cin>>n;
    cin>>e;
    graph g(n);

    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        g.add_node(a,b);
    }

    cout<<g.find_ans();
    return 0;
}
