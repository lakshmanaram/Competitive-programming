#include<bits/stdc++.h>
using namespace std;
vector<bool> vis;
struct gnode{                                                                   //individual node element
    long long key;                                                              //key value of that particular node
    vector<int> children;                                                       //children index values
};
class graph{
    public:
    int nodes;                                                                  //number of nodes
    vector<gnode> gnodes;
    graph(int k){                                                               //constructor which takes number of nodes as input
    	nodes = k;
        gnodes.resize(k,0);
        vis.resixe(k);
        fill(vis.begin(),vis.end(),false);
        for(int i=0;i<nodes;i++){                                               //fills 'vis' array with n false values and gets input for the key values of all the n nodes
        	cin>>gnodes[i].key;
        }
    }
    void dfs(int n,long long k){
        vector<int>::iterator it;
        for(it = gnodes[n].children.begin();it!=gnodes[n].children.end();it++){
            if(vis[*it]==false){
                vis[*it] = true;
                dfs(*it,k);
            }
        }
        return;
    }
    void add_node(int c, int k){                                                //initializes graph nodes
        gnodes[c].children.push_back(k);
        gnodes[k].children.push_back(c);
    }
};
int main(){
    int n,e;
    cin>>n;                                                                     //number of nodes
    cin>>e;                                                                     //number of edges
    graph g(n);
    for(int i=0;i<e;i++){                                                       //adding all the edges
        int a,b;
        cin>>a>>b;
        g.add_node(a,b);
    }
    return 0;
}
