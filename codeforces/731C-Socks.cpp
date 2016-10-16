// dfs template - everything is 0 indexed
#include<bits/stdc++.h>
using namespace std;
vector<bool> vis;
struct gnode{                                                                   //individual node element
    long long key;                                                              //key value of that particular node
    vector<int> children;                                                       //children index values
};
class graph{
    public:
    int nodes;     
    long long ans;
    map<long long, long long> colors;
    vector<gnode> gnodes;
    graph(int k){                                                               //constructor which takes number of nodes as input
    	nodes = k;
        gnodes.resize(k);
        vis.resize(k);
        fill(vis.begin(),vis.end(),false);
        for(int i=0;i<nodes;i++){                                               // gets input for the key values
        	cin>>gnodes[i].key;
        }
        vis.resize(nodes,false);
        fill(vis.begin(),vis.end(),false);
    }
    void dfs_recurse(int n){
        colors[gnodes[n].key]++;
        vector<int>::iterator it;
        for(it = gnodes[n].children.begin();it!=gnodes[n].children.end();it++)
            if(vis[*it]==false){
                vis[*it] = true;
                dfs_recurse(*it);
            }
    }
    long long dfs(int n){
    	colors.clear();
        vis[n] = true;
        dfs_recurse(n);
        map<long long, long long>::iterator mit;
        long long sum = 0,maxval = -1;
        for(mit = colors.begin();mit!=colors.end();mit++) {
        	if(maxval == -1 || maxval < mit -> second)
        		maxval = mit -> second;
        	sum += mit -> second;
        }
        return sum - maxval;
    }
    void add_node(int c, int k){                                                //initializes graph nodes 0-indexed
        gnodes[c].children.push_back(k);
        gnodes[k].children.push_back(c);
    }
};
int main(){
	long long n,k,m;
	cin>>n>>m>>k;
    graph g(n);
	long long ans = 0;
	for(long long i=0;i<m;i++) {
		long l,r;
		cin>>l>>r;
        g.add_node(l-1,r-1);
	}
	for(long long i=0;i<n;i++){
		if(!vis[i])
			ans += g.dfs(i);
	}
	cout<<ans<<endl;
    return 0;
}