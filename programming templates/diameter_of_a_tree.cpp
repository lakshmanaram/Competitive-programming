#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
using namespace std;
vector<bool> vis;
struct gnode{
    vector<long> children;
    long dleft;
    long dright;
};
class graph{
    public:
    long nodes;
    long req_val;
    long left;
    long right;
    long long ans;
    vector<gnode> gnodes;
    queue<long> q;
    graph(long k){
    	ans = 0;
    	nodes = k;
    	gnode temp;
    	temp.dleft = 0;
    	temp.dright = -1;
        gnodes.resize(k, temp);
        vis.resize(k);
        fill(vis.begin(),vis.end(),false);
    }
    void bfs_recurse(){
        if(q.empty())
            return;
        long n = q.front();
        req_val = n;
        q.pop();
        vector<long>::iterator it;
        for(it = gnodes[n].children.begin();it!=gnodes[n].children.end();it++)
            if(vis[*it]==false){
                vis[*it] = true;
                q.push(*it);
            }
        bfs_recurse();
    }
    long bfs(long n){
        fill(vis.begin(),vis.end(),false);
        q.push(n);
        vis[n] = true;
        bfs_recurse();
        return req_val;
    }
    void add_node(long c, long k){                                                //initializes graph nodes 0-indexed
        gnodes[c-1].children.push_back(k-1);
        gnodes[k-1].children.push_back(c-1);
    }
    long dfs(long n, long dest, long curval){
    	gnodes[n].dleft = curval;
    	vis[n] = true;
    	if(n == dest) {
    		gnodes[n].dright = 0;
    		return 1;
    	}
    	vector<long>::iterator it;
        for(it = gnodes[n].children.begin();it!=gnodes[n].children.end();it++)
            if(!vis[*it]){
                long t = dfs(*it, dest, curval+1);
                if(t != -1) {
                	gnodes[n].dright = t;
                	return t+1;
                }
            }
        return -1;
    }
    void process(){
        left = bfs(0);
        right = bfs(left);
        fill(vis.begin(), vis.end(), false);
        dfs(left, right, 0);
    	fill(vis.begin(), vis.end(), false);
    	for(long i=0; i<gnodes.size();i++){
    		if(gnodes[i].dright != -1){
    			vis[i] = true;
    		} else {
    			gnodes[i].dleft = -1;
    		}
    	}
    }
};
int main(){
    long n;
    cin>>n;
    graph g(n);
    for(long i=0;i<n-1;i++){
        long a,b;
        scanf("%ld %ld", &a, &b);
        g.add_node(a,b);
    }
    g.process();
    cout<<g.left+1<<" "<<g.right+1<<endl;
    // All nodes with vis as true is part of the diameter
    // Distance from left and right ends can be  found from dleft and dright values of each node

    return 0;
}
