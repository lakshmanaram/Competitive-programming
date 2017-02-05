// dfs template - everything is 0 indexed
#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<bool> vis;
struct gnode{
    long long key;
    vector<long> children;
};
class graph{
    public:
    long nodes;
    vector<gnode> gnodes;
    vector<long> possible;
    long color;
    graph(long k){
    	nodes = k;
        gnodes.resize(k);
        vis.resize(k);
        fill(vis.begin(),vis.end(),false);
        for(long i=0;i<nodes-1;i++){
            long a,b;
            cin>>a>>b;
            add_node(a-1,b-1);
        }
        for(long i=0;i<nodes;i++){
        	cin>>gnodes[i].key;
        }
    }
    void dfs_recurse(long n){
        vector<long>::iterator it;
        for(it = gnodes[n].children.begin();it!=gnodes[n].children.end();it++){
            if(possible.size()!=0) return;
            if(vis[*it]==false){
                vis[*it] = true;
                if(color != gnodes[*it].key) {
                    possible.push_back(n);
                    possible.push_back(*it);
                    return;
                }
                dfs_recurse(*it);
            }
        }
    }
    void dfs(long n){
        fill(vis.begin(),vis.end(),false);
        vis[n] = true;
        color = gnodes[n].key;
        dfs_recurse(n);
    }
    bool dfs_recurse_bool(long n) {
        if(color != gnodes[n].key)
            return false;
        vector<long>::iterator it;
        for(it = gnodes[n].children.begin();it!=gnodes[n].children.end();it++)
            if(vis[*it]==false){
                vis[*it] = true;
                if(!dfs_recurse_bool(*it))
                    return false;
            }
        return true;
    }
    bool check(long n) {
        fill(vis.begin(),vis.end(),false);
        vis[n] = true;
        vector<long>::iterator it;
        for(it = gnodes[n].children.begin();it!=gnodes[n].children.end();it++){
            vis[*it] = true;
            color = gnodes[*it].key;
            if(!dfs_recurse_bool(*it))
                return false;
        }
        return true;
    }
    void get_ans() {
        // for(int i=0;i<possible.size();i++)
        //     cout<<possible[i]<<" ";
        // cout<<"possible ends"<<endl;
        string yes = "YES", no = "NO";
        if(possible.size()==0){
            cout<<yes<<endl<<1;
            return;
        }
        for(long i=0;i<possible.size();i++)
            if(check(possible[i])) {
                cout<<yes<<endl<<possible[i]+1;
                return;
            }
        cout<<no<<endl;
    }
    void add_node(long c, long k){
        gnodes[c].children.push_back(k);
        gnodes[k].children.push_back(c);
    }
};
int main(){
    long n;
    cin>>n;
    graph g(n);
    g.dfs(0);
    g.get_ans();
    return 0;
}
