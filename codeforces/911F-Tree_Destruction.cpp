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
    vector<pair<long, long> > arr;
    vector<long > tarr;
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
    	// cout<<n<<" "<<dest<<" "<<curval<<" are written\n";
    	gnodes[n].dleft = curval;
    	vis[n] = true;
    	if(n == dest) {
        	ans += gnodes[n].dleft;
        	// cout<<left<<" "<<n<<" "<<n+1<<" this is what you got"<<endl;
        	arr.pb(mp(left, n));
        	tarr.pb(n+1);
    		gnodes[n].dright = 0;
    		return 1;
    	}
    	vector<long>::iterator it;
        for(it = gnodes[n].children.begin();it!=gnodes[n].children.end();it++)
            if(!vis[*it]){
            	// cout<<*it<<" this is val being visited"<<endl;
                long t = dfs(*it, dest, curval+1);
                // cout<<"value of t at *it = "<<*it<<" is "<<t<<endl;
                if(t != -1) {
                	if(gnodes[n].dleft != 0){
	                	ans += gnodes[n].dleft;
	                	arr.pb(mp(left, n));
	                	tarr.pb(n+1);
	                }
                	gnodes[n].dright = t;
                	return t+1;
                }
            }
        return -1;
    }
    void process(){
    	fill(vis.begin(), vis.end(), false);
    	for(long i=0; i<gnodes.size();i++){
    		if(gnodes[i].dright != -1){
    			vis[i] = true;
    		} else {
    			gnodes[i].dleft = -1;
    		}
    	}
    	for(long i=0;i<gnodes.size();i++){
    		if(gnodes[i].dright != -1){
    			if(gnodes[i].dright > gnodes[i].dleft)
    				dfs_val(i, 0, gnodes[i].dright, right);
    			else
    				dfs_val(i, 0, gnodes[i].dleft, left);
    		}
    	}
    }
    void dfs_val(long n, long curval, long fixed_val, long xy){
        if(curval != 0){
        	ans += curval + fixed_val;
        	arr.pb(mp(n, xy));	
        	tarr.pb(n+1);
        }
    	vector<long>::iterator it;
    	for(it = gnodes[n].children.begin();it!=gnodes[n].children.end();it++)
            if(!vis[*it]){
                vis[*it] = true;
                dfs_val(*it, curval+1, fixed_val, xy);
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
    g.left = g.bfs(0);
    g.right = g.bfs(g.left);
    fill(vis.begin(), vis.end(), false);
    g.dfs(g.left, g.right, 0);
    reverse(g.arr.begin(),g.arr.end());
    reverse(g.tarr.begin(),g.tarr.end());
    g.process();
    reverse(g.arr.begin(),g.arr.end());
    reverse(g.tarr.begin(),g.tarr.end());
    printf("%lld\n", g.ans);
    for(long i=0;i<g.arr.size();i++){
    	printf("%ld %ld %ld\n", g.arr[i].first+1, g.arr[i].second+1, g.tarr[i]);
    }
    return 0;
}
