// dfs template - everything is 0 indexed
#include<bits/stdc++.h>
using namespace std;
vector<bool> vis;
struct gnode{                                                     
    long w;
    long b;
    vector<int> children;                                                       //children index values
};
class graph{
    public:
    int nodes;
    int h; 
    long long maxw;                                                                 //number of nodes
    long long ans;
    vector<vector<long long> > mat;
    vector<gnode> gnodes;
    graph(int k){                                                               //constructor which takes number of nodes as input
    	nodes = k;
        gnodes.resize(k);
        vis.resize(k);  
        cin>>maxw;
        fill(vis.begin(),vis.end(),false);
        for(int i=0;i<nodes;i++){                                               // gets input for the key values
        	cin>>gnodes[i].w;
        }
        for(int i=0;i<nodes;i++){                                               // gets input for the key values
            cin>>gnodes[i].b;
        }
    }
    void dfs_recurse(int n, long long &w, long long &b){
        // cout<<n<<" ";
        vector<int>::iterator it;
        for(it = gnodes[n].children.begin();it!=gnodes[n].children.end();it++)
            if(vis[*it]==false){
                vis[*it] = true;
                dfs_recurse(*it,w,b);
            }
        long weight = gnodes[n].w;
        long beauty = gnodes[n].b;
        if(h == 0) {
            for(long i=weight;i<mat[h].size();i++) {
                if(beauty > mat[h][i])
                    mat[h][i] = beauty;
            }
        } else {
            for(long i=0;(i<weight)&&(i<mat[h].size());i++){
                if (mat[h-1][i] > mat[h][i])
                    mat[h][i] = mat[h-1][i];
            }
            for(long i=weight;i<mat[h].size();i++) {
                if(mat[h][i] <mat[h-1][i])
                    mat[h][i] = mat[h-1][i];
                if(mat[h][i] < mat[h-1][i-weight]+beauty)
                    mat[h][i] = mat[h-1][i-weight]+beauty;
            }
        }
        w += weight;
        b += beauty;
    }
    void dfs(){
        ans = 0;
        vis.resize(nodes,false);
        fill(vis.begin(),vis.end(),false);
        h = 0;
        vector<long long> tm(maxw+1,0);
        for(long n=0;n<nodes;n++) {
            if(!vis[n]){
                vis[n] = true;
                mat.push_back(tm);
                long long tw = 0, tb = 0;
                dfs_recurse(n,tw,tb);
                if(h == 0) {
                    for(long i=tw;i<mat[h].size();i++) {
                        if(tb > mat[h][i])
                            mat[h][i] = tb;
                        if(ans < mat[h][i])
                            ans = mat[h][i];
                    }
                } else {
                    for(long i=0;(i<tw)&&(i<mat[h].size());i++){
                        if (mat[h-1][i] > mat[h][i])
                            mat[h][i] = mat[h-1][i];
                        if(ans < mat[h][i])
                            ans = mat[h][i];
                    }
                    for(long i=tw;i<mat[h].size();i++) {
                        if(mat[h][i] <mat[h-1][i])
                            mat[h][i] = mat[h-1][i];
                        if(mat[h][i] < mat[h-1][i-tw]+tb)
                            mat[h][i] = mat[h-1][i-tw]+tb;
                        if(ans < mat[h][i])
                            ans = mat[h][i];
                    }
                }
                h++;
            }
        }
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
    int n;
    long e;
    cin>>n;                                                                     //number of nodes
    cin>>e;                                                                     //number of edges
    graph g(n);
    for(int i=0;i<e;i++){                                                       //adding all the edges
        int a,b;
        cin>>a>>b;
        g.add_node(a-1,b-1);
    }
    g.dfs();
    cout<<g.ans;
    // g.display_values();
    return 0;
}
