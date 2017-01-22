#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
struct gnode{
    vector<pair<long, ll> > children;
};
class graph{
    public:
    long nodes;
    vector<gnode> gnodes;
    set<pair<ll, pair<long, long> > > heap;
    vector<ll> dist_array;
    vector<long> noa;
    bool flag;
    set<long> vis;
    graph(long k){
    	nodes = k;
        gnodes.resize(k);
        dist_array.resize(k,-1);
        dist_array[0] = 0;
        noa.resize(k,0);
        noa[0] = 1;
        flag = true;
    }
    void dijkstra(){
    	for(long j=0;j<gnodes[0].children.size();j++) {
    		pair<long, ll> x = gnodes[0].children[j];
    		heap.insert(mp(x.second,mp(0,x.first)));
    	}
    	while(heap.size()) {
    		pair<ll,pair<long,long> > x = *heap.begin();
    		heap.erase(x);
    		if(dist_array[x.second.second] == -1) {
    			dist_array[x.second.second] = x.first;
    			long i = x.second.second;
    			// cout<<i<<" "<<dist_array[x.second.second]<<endl;
    			for(long j=0;j<gnodes[i].children.size();j++) {
		    		pair<long, ll> y = gnodes[i].children[j];
		    		heap.insert(mp(y.second + dist_array[i],mp(i,y.first)));
		    	}
    		} else if(x.first < dist_array[x.second.second])
    			dist_array[x.second.second] = x.first;

    	}
    }

    ll dijkstra2(){

    	heap.clear();
    	for(long j=0;j<gnodes[0].children.size();j++) {
    		pair<long, ll> x = gnodes[0].children[j];
    		heap.insert(mp(x.second,mp(0,x.first)));
    	}
    	ll ans = 0;
    	vector<bool> vis(nodes,false);
    	vis[0] = true;
    	while(heap.size()) {
    		pair<ll,pair<long,long> > x = *heap.begin();
    		heap.erase(x);
    		// cout<<x.second.first+1<<" "<<x.second.second+1<<endl;
    		if(!vis[x.second.second]) {
    			long i = x.second.second;
    			vis[i] = true;
    			for(long j=0;j<gnodes[i].children.size();j++) {
		    		pair<long, ll> y = gnodes[i].children[j];
		    		if(!vis[y.first]){
		    			// cout<<"dunno "<<y.first<<endl;
		    			heap.insert(mp(y.second+dist_array[i],mp(i,y.first)));
		    		}
		    	}
    		}
    		ans += (x.first)-dist_array[x.second.second];
    		// cout<<ans<<endl;
    	}
    	return ans;
    }
    void add_node(long c, long k, ll val){
        gnodes[c].children.push_back(make_pair(k,val));
        gnodes[k].children.push_back(make_pair(c,val));
    }
    void display() {
    	for(long i=0; i<dist_array.size();i++) {
    		cout<<dist_array[i]<<" ";
    	}
    }
};

int main() {
	long n,e;
	cin>>n>>e;
	graph g(n);
	ll tsum = 0;
	while(e--) {
		long l,r;
		ll val;
		cin>>l>>r>>val;
		g.add_node(l-1,r-1,val);
		tsum += val;
	}
	g.dijkstra();
	cout<<tsum - g.dijkstra2()<<endl;
	return 0;
}