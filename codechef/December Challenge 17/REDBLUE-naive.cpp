#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
using namespace std;
class pll{
public:
	pair<ll, ll> pt;
	bool color;
}
vector<pair<ll, ll> > a, b;

vector<pair<ll, ll> > point;
int get_quad(vector<pair<ll, ll> > &c){
	if(c.first-point.first >= 0){
		if(c.second - point.second >= 0) return 0;
		else return 3;
	} else {
		if(c.second - point.second >= 0) return 1;
		else return 2;
	}
}
bool my_func(pll a, pll b){
	ll x1, y1, x2, y2;
	y1 = abs(a.pt.second - point.pt.second);
	y2 = abs(b.pt.second - point.pt.second);
	x1 = abs(a.pt.first - point.pt.first);
	x2 = abs(b.pt.first - point.pt.first);
	if(y1*x2 <= y2*x1) return true;
	return false;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--) {
		long n, m;
		scanf("%ld %ld", &n, &m);
		a.clear();
		b.clear();
		for(int i=0;i<n;i++){
			ll x, y;
			scanf("%lld %lld", &x, &y);
			a.pb(mp(x, y));
		}
		for(int i=0;i<m;i++){
			ll x, y;
			scanf("%lld %lld", &x, &y);
			b.pb(mp(x, y));
		}
		if(a.size() > b.size())
			swap(a,b);
		long ans = 0;
		for(int i=0;i<a.size();i++){
			vector<pll> quad[4];
			point = a[i];
			for(int j=0;j<a.size();j++){
				if(j == i) continue;
				pll x;
				x.pt = a[j];
				x.color = true;
				quad[get_quad(a[j])].pb(x);
			}
			for(int j=0;j<b.size();j++){
				pll x;
				x.pt = b[j];
				x.color = false;
				quad[get_quad(b[j])].pb(x);
			}
			for(int i=0;i<4;i++){
				sort(quad[i].begin(), quad[i].end(), my_func);
			}
			// quad 1(0) and 3(2)
			long bleft, bright, rleft, rright;
			bleft = bright = rleft = rright = 0;
			vector<long> bquad(4, 0), rquad(4, 0);
			for(long j=0;j<quad[0].size();j++){
				if(quad[0][j].color) bquad[0]++;
				else rquad[0]++;
			}
			for(long j=0;j<quad[1].size();j++){
				if(quad[1][j].color) bquad[1]++;
				else rquad[1]++;
			}
			for(long j=0;j<quad[2].size();j++){
				if(quad[2][j].color) bquad[2]++;
				else rquad[2]++;
			}
			for(long j=0;j<quad[3].size();j++){
				if(quad[3][j].color) bquad[3]++;
				else rquad[3]++;
			}
			bleft += bquad[1] + bquad[0];
			rleft += rquad[1] + rquad[0];
			bright += bquad[2] + bquad[3];
			rright += rquad[2] + rquad[3];
			if(i == 0){
				ans = min(bleft+rright, bright+rleft);
			}
			long j,k;
			j=k=0;
			while(j < quad[0].size() && k < quad[2].size()) {
				if(my_func(quad[0][j], quad[2][k])){

				}
			}
			while(j < quad[0].size()) {

				j++;
			}
			while(k < quad[2].size()) {

				k++
			}
		}
	}
	return 0;
}