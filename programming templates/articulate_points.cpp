#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;

class graph {
public:
	long nodes;
	vector< vector<long> > edges;
	vector<ll> articulatePoints;
	vector<bool> vis;
	vector<ll> depth, lowpoint;

	graph (ll n, ll e) {
		nodes = n;
		edges.resize(n);
		vis.resize(n, false);
		depth.resize(n);
		lowpoint.resize(n);
		for (long i = 0; i < e; i++) {
			ll a, b;
			cin >> a >> b;
			edges[a-1].push_back(b-1);
			edges[b-1].push_back(a-1);
		}
	}
	vector<ll> getArticulatePoints() {
		dfsArticulation(-1, 0, 0);
		return articulatePoints;
	}
	void dfsArticulation(long parent, long n, long d) {
		vis[n] = true;
		depth[n] = d;
		lowpoint[n] = d;
		long child_count = 0;
		for (long i = 0; i < edges[n].size();i++) {
			if (!vis[edges[n][i]]) {
				child_count++;
				dfsArticulation(n, edges[n][i], d+1);
				if (parent != -1 && lowpoint[edges[n][i]] >= depth[n])
					articulatePoints.push_back(n);
				else
					lowpoint[n] = min(lowpoint[n], lowpoint[edges[n][i]]);
			} else if (parent != edges[n][i]) {
				lowpoint[n] = min(lowpoint[n], lowpoint[edges[n][i]]);
			}
		}
		if (parent == -1 && child_count > 1){
			articulatePoints.push_back(n);
		}
	}

};

int main(){
	ll n, e;
	cin >> n >> e;
	graph g(n, e);
	vector<ll> articulatePoints = g.getArticulatePoints();
	for (long i = 0; i < articulatePoints.size(); i++) {
		cout << articulatePoints[i] << " ";
	}	
	cout << endl;
	return 0;
}
/*
Input:
7 9
1 2
2 3
3 4
1 4
1 3
2 6
6 7
5 6
5 7


*/