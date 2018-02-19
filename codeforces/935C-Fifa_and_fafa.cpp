#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
#define pii pair<ll, ll>
#define pdd pair<long double, long double>
using namespace std;
ll dsquare(pii a, pii b){
	return pow(a.first - b.first,2)+pow(a.second - b.second,2);
}
long double distance_pts(pii a, pii b){
	return sqrt(pow(a.first - b.first,2)+pow(a.second - b.second,2));
}
int main(){
	pii a, b;
	ll R;
	pdd ans;
	long double r;
	cin>>R>>a.first>>a.second>>b.first>>b.second;
	if(dsquare(a, b) >= R*R){
		r = R;
		ans = a;
	} else {
		if(a == b) {
			r = R;
			r /= 2;
			ans = a;
			ans.first += r;
		} else {
			// cout<<"inside"<<endl;
			double dist = distance_pts(a, b);
			r = R + dist;
			r /= 2;
			ans = b;
			pdd something = a;
			something.first -= b.first;
			something.second -= b.second;
			ans.first += (r * something.first) / dist;
			ans.second += (r * something.second) / dist;
		}
	}
	cout<<std::setprecision(13)<<ans.first<<" "<<ans.second<<" "<<r<<endl;
	return 0;
}