// All pair Shortest Paths
#include <bits/stdc++.h>
#define INF 10000000000
#define ll long long 
using namespace std;

struct gnode{
    ll key;
};
class graph{
    public:
    long nodes;
    vector<gnode> gnodes;
    vector<vector<ll> > edges;
    graph(long k){
    	nodes = k;
        gnodes.resize(k);
        vector<ll> temp(k,INF);
        edges.resize(k,temp);
        for(int i=0;i<nodes;i++)
            edges[i][i] = 0;
        for(long i=0;i<nodes;i++){
        	cin>>gnodes[i].key;
        }
    }
    void add_node(long c, long k, ll val){
        edges[c][k] = min(edges[c][k],val);
        edges[k][c] = min(edges[k][c],val);
    }
    void display_values(){
        cout<<"The Edges in graph are : "<<endl;
        for(long i = 0; i < edges.size() ; i++){
            for(long j = 0; j < edges[i].size() ; j++){
                if(edges[i][j] == INF)
                    cout<<"INF ";
                else cout<<edges[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void floyd_warshall() {
        for(long k=0; k<nodes; k++)
            for(long i=0;i<nodes;i++)
                for(long j=0;j<nodes;j++)
                    edges[i][j] = min(edges[i][j],edges[i][k]+edges[k][j]);
    }
};
int main(){
    long n,e;
    cin>>n;
    cin>>e;
    graph g(n);
    for(long i=0;i<e;i++){
        long a,b;
        ll val;
        cin>>a>>b>>val;
        g.add_node(a-1,b-1,val);
    }
    g.floyd_warshall();
    g.display_values();
    return 0;
}
