// dfs template - everything is 0 indexed
#include<bits/stdc++.h>
using namespace std;
vector<bool> vis;
struct gnode{
    vector<pair<long, long long> > children;
};
class graph{
    public:
    long nodes;
    vector<gnode> gnodes;
    graph(long k){
    	nodes = k;
        gnodes.resize(k);
        vis.resize(k);
    }
    long long dfs_recurse(long n, long x, long long val, long long ref){
    	if(n == x)
    		return val;
    	long long ans = 0;
        vector<pair<long, long long> >::iterator it;
        for(it = gnodes[n].children.begin();it!=gnodes[n].children.end();it++)
            if(!vis[it->first]){
                vis[it->first] = true;
                if(it->second <= ref)
                	ans = ans ^ dfs_recurse(it->first, x, val^it->second, ref);
            	else
            		ans = ans ^ dfs_recurse(it->first, x, val, ref);
            }
        return ans;
    }
    long long dfs(long n, long x, long long val){
        fill(vis.begin(),vis.end(),false);
        vis[n] = true;
        return dfs_recurse(n, x, 0, val);
    }
    void add_node(long c, long k, long long val){
        gnodes[c].children.push_back(make_pair(k, val));
        gnodes[k].children.push_back(make_pair(c, val));
    }
};
int main(){
	long t;
	cin>>t;
	while(t--){
	    long n,m;
	    cin>>n;
	    graph g(n);
	    for(long i=0;i<n-1;i++){
	        long a,b;
	        long long c;
	        cin>>a>>b>>c;
	        g.add_node(a-1,b-1,c);
	    }
	    cin>>m;
	    while(m--){
	    	long u,v;
	    	long long x;
	    	cin>>u>>v>>x;
	    	cout<<g.dfs(u-1,v-1,x)<<endl;
	    }
	}
    return 0;
}
