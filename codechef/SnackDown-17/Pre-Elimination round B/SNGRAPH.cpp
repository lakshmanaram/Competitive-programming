#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
#define pb push_back
#define mp make_pair
struct node {
	long long  child;
	bool there;
	long long  parent;
	long long  sze;
};
class graph {
public:
	vector<node> nodes;
	vpll edges;
	vector<vpll> deg_edges;
	vll ans;
	void initialize(long long  i) {
		nodes[i].parent = i;
		nodes[i].there = true;
		nodes[i].sze = 1;
	}
	long long  root(long long  i) {
		if(nodes[i].parent != i) nodes[i].parent = root(nodes[i].parent);
		return nodes[i].parent;
	}
	bool find(long long  a, long long  b) {
		if(root(a) == root(b))
			return true;
		return false;
	}
	void union_op(long long  a, long long  b) {
		long long  roota = root(a);
		long long  rootb = root(b);
		if(nodes[roota].sze < nodes[rootb].sze) {
			nodes[roota].parent = rootb;
			nodes[rootb].sze += nodes[roota].sze;
		} else {
			nodes[rootb].parent = roota;
			nodes[roota].sze += nodes[rootb].sze;
		}
	}
	graph(long long  n, long long  m) {
		node temp;
		temp.child = 0;
		temp.there = false;
		nodes.resize(n,temp);
		ans.resize(n,n-1);
		deg_edges.resize(n);
		while(m--) {
			long long  a,b;
			cin>>a>>b;
			add_edge(a-1,b-1);
		}
		for(long long  i=0;i<edges.size();i++) {
			deg_edges[min(nodes[edges[i].first].child,nodes[edges[i].second].child)].pb(edges[i]);
		}
		get_ans();
		show_ans();
	}
	void add_edge(long long  x, long long  y) {
		nodes[x].child++;
		nodes[y].child++;
		edges.pb(mp(x,y));
	}
	void get_ans() {
		long long  noc = 0;
		long long  rem = ans.size();
		for(long long  i=ans.size()-1;i>=0;i--){
			for(long long  j=0;j<deg_edges[i].size();j++){
				pll edge = deg_edges[i][j];
				if(nodes[edge.first].there && nodes[edge.second].there) {
					if(!find(edge.first,edge.second)) {
						noc--;
						union_op(edge.first,edge.second);
					}
				} else if(nodes[edge.first].there) {
					initialize(edge.second);
					union_op(edge.first,edge.second);
					rem--;
				} else if(nodes[edge.second].there) {
					initialize(edge.first);
					union_op(edge.first, edge.second);
					rem--;
				} else {
					initialize(edge.first);
					initialize(edge.second);
					union_op(edge.first, edge.second);
					noc++;
					rem-=2;
				}
			}
			// cout<<i<<" noc  = "<<noc<<" rem = "<<rem<<endl;
			ans[i] = max((long long )0,noc-1) + min(rem,(long long )(ans.size()-1));
		}
	}
	void show_ans() {
		for(long long  i=1;i<ans.size();i++) 
			printf("%lld ",ans[i]);
		printf("%lld\n",(long long)ans.size()-1);
	}
};
int main(){
	int t;
	cin>>t;
	while(t--) {
		long long n,m;
		cin>>n>>m;
		graph g(n,m);
	}
  	return 0;
}