#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
bool min_comp(const ll a,const ll b){
    if(a == -1) return false;
    if(b == -1) return true;
    if (min(a,b) == a) return true;
    return false;
}
struct gnode{
    vector<pair<long, ll> > children;
};
class graph{
    public:
    long k;
    long long value;
    vector<gnode> gnodes;
    set<pair<ll, pair<long, long> > > heap;
    vector<ll> dist_array;
    set<long> vis;
    graph(long n, long kv, ll x){
        k = kv;
        value = x;
        gnodes.resize(n);
        dist_array.resize(n,-1);
    }
    void dijkstra(long s){
        dist_array[s] = 0;
    	for(long j=0;j<gnodes[s].children.size();j++) {
    		pair<long, ll> x = gnodes[s].children[j];
    		heap.insert(mp(x.second,mp(s,x.first)));
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
        ll minval = *min_element(dist_array.begin(),dist_array.begin()+k,min_comp);
        for(long i=0;i<k;i++)
            if(dist_array[i] == -1 || value + minval < dist_array[i]) {
                dist_array[i] = value+minval;
                heap.insert(mp(dist_array[i],mp(s,i)));
                for(long j=0;j<gnodes[i].children.size();j++) {
                    pair<long, ll> y = gnodes[i].children[j];
                    heap.insert(mp(y.second + dist_array[i],mp(i,y.first)));
                }
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
            } else if(x.first < dist_array[x.second.second]){
                dist_array[x.second.second] = x.first;
                long i = x.second.second;
                // cout<<i<<" "<<dist_array[x.second.second]<<endl;
                for(long j=0;j<gnodes[i].children.size();j++) {
                    pair<long, ll> y = gnodes[i].children[j];
                    heap.insert(mp(y.second + dist_array[i],mp(i,y.first)));
                }
            }
        }
    }
    void add_node(long c, long k, ll val){
        gnodes[c].children.push_back(make_pair(k,val));
        gnodes[k].children.push_back(make_pair(c,val));
    }
    void display() {
    	for(long i=0; i<dist_array.size();i++)
    		cout<<dist_array[i]<<" ";
        cout<<endl;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--) {
    	long n,k,s,e;
        ll x;
    	cin>>n>>k>>x>>e>>s;
    	graph g(n,k,x);
    	ll tsum = 0;
    	while(e--) {
    		long l,r;
    		ll val;
    		cin>>l>>r>>val;
    		g.add_node(l-1,r-1,val);
    	}
    	g.dijkstra(s-1);
        g.display();
    }
	return 0;
}