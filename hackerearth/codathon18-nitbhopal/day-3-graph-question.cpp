// dfs template - everything is 0 indexed
#include<bits/stdc++.h>
#define mp make_pair
#define ll long long
using namespace std;
vector<bool> vis;
struct gnode{
	ll ans;
    vector<pair<long, ll> > children;
};
class graph{
    public:
    long nodes;
    vector<gnode> gnodes;
    set<pair<ll, long> > s;
    graph(long k){
    	nodes = k;
    	gnode temp;
    	temp.ans = -1;
        gnodes.resize(k, temp);
    }
    void add_node(long c, long k, long val){
        gnodes[c].children.push_back(mp(k, val));
        gnodes[k].children.push_back(mp(c, val));
    }
    void mbfs(){
    	while(!s.empty()){
	    	ll val = s.begin()->first;
	    	long ind = s.begin()->second;
	    	s.erase(s.begin());
	    	if(gnodes[ind].ans == -1 || gnodes[ind].ans > val){
	    		gnodes[ind].ans = val;
	    		for(auto it = gnodes[ind].children.begin(); it != gnodes[ind].children.end(); it++) {
	    			s.insert(mp(val + it->second, it->first));
	    		}
	    	}
	    }
    }
};
int main(){
    long n, e, q, k;
    cin>>n;
    cin>>e>>k>>q;
    graph g(n);
    for(long i=0;i<e;i++){
        long a, b, c;
        cin>>a>>b>>c;
        g.add_node(a-1, b-1, c);
    }
    while(k--){
    	long x;
    	scanf("%ld", &x);
    	g.s.insert(mp(0, x-1));
    }
    g.mbfs();
    while(q--){
    	long x;
    	scanf("%ld", &x);
    	printf("%lld\n", g.gnodes[x-1].ans);
    }
    // g.display_values();
    return 0;
}
