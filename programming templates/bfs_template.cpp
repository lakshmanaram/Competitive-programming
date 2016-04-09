// Bfs template - everything is 0 indexed
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
        gnodes.resize(k);
        vis.resize(k);
        fill(vis.begin(),vis.end(),false);
        for(int i=0;i<nodes;i++){                                               //gets input for the key values
        	cin>>gnodes[i].key;
        }
    }
    void bfs_recurse(queue<int> q){
        if(q.empty())
            return;
        int n = q.front();
        // cout<<n<<" ";
        q.pop();
        vector<int>::iterator it;
        for(it = gnodes[n].children.begin();it!=gnodes[n].children.end();it++)
            if(vis[*it]==false){
                vis[*it] = true;
                q.push(*it);
            }
        bfs_recurse(q);
    }
    void bfs(int n){
        vis.resize(nodes,false);
        queue<int> q;
        fill(vis.begin(),vis.end(),false);
        q.push(n);
        vis[n] = true;
        bfs_recurse(q);
    }
    void add_node(int c, int k){                                                //initializes graph nodes 0-indexed
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
    cin>>n;                                                                     //number of nodes
    cin>>e;                                                                     //number of edges
    graph g(n);
    for(int i=0;i<e;i++){                                                       //adding all the edges
        int a,b;
        cin>>a>>b;
        g.add_node(a,b);
    }
    g.bfs(0);
    // g.display_values();
    return 0;
}
