#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
using namespace std;
long a, b, c, m;
bool coord(long x, long y, long z){
	if(x >= a || y >= b || z >= c) return false;
	if(x < 0 || y < 0 || z < 0) return false;
	return true;
}
vector<vector<vector<ll> > > arr;
vector<vector<vector<bool> > > vis;
ll find_ans(long x, long y, long z){
	if(!coord(x, y, z)) return 0;
	if(vis[x][y][z]) return arr[x][y][z];
	ll ans = 0;
	ans += find_ans(x-1, y, z);
	ans += find_ans(x, y-1, z);
	ans += find_ans(x, y, z-1);
	ans -= find_ans(x-1, y, z-1);
	ans -= find_ans(x, y-1, z-1);
	ans -= find_ans(x-1, y-1, z);
	ans += find_ans(x-1, y-1, z-1);
	ans += arr[x][y][z];
	arr[x][y][z] = ans;
	vis[x][y][z] = true;
	return arr[x][y][z];
}
int main(){
	int t;
	cin>>t;

	while(t--){
		scanf("%ld %ld %ld %ld", &a, &b, &c, &m);
		vector<ll> t1(c, 0);
		vector<vector<ll> > t2(b, t1);
		arr.clear();
		arr.resize(a, t2);
		vis.clear();
		vector<bool> t11(c, false);
		vector<vector<bool> > t22(b, t11);
		vis.resize(a, t22);
		while(m--){
			long i, j, k, l;
			ll v;
			scanf("%ld %ld %ld %lld %ld", &i, &j, &k, &v, &l);
			arr[i][j][k] += v;
			if(coord(i+l, j, k)){
				arr[i+l][j][k] -= v;
			}
			if(coord(i, j+l, k)){
				arr[i][j+l][k] -= v;
			}
			if(coord(i, j, k+l)){
				arr[i][j][k+l] -= v;
			}
			if(coord(i+l, j, k+l)){
				arr[i+l][j][k+l] += v;
			}
			if(coord(i, j+l, k+l)){
				arr[i][j+l][k+l] += v;
			}
			if(coord(i+l, j+l, k)){
				arr[i+l][j+l][k] += v;
			}
			if(coord(i+l, j+l, k+l)){
				arr[i+l][j+l][k+l] -= v;
			}
		}
		find_ans(a-1, b-1, c-1);
		// for(long i=0;i<a;i++){
		// 	for(long j=0;j<b;j++){
		// 		for(long k=0;k<c;k++){
		// 			cout<<arr[i][j][k]<<" ";
		// 		}
		// 		cout<<endl;
		// 	}
		// 	cout<<endl;
		// }
		long ans_val = 0;
		for(long i=0;i<a;i++){
			for(long j=0;j<b;j++){
				for(long k=0;k<c;k++){
					if(arr[i][j][k] == 0) ans_val++;
				}
			}
		}
		printf("%ld\n", ans_val);
	}
	return 0;
}