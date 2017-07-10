#include <bits/stdc++.h>
using namespace std;
struct vacation{
	long l,r;
	long long cost;
	long long minval;
};
class bigd {
public:
	vector<vacation> arr;
};
bool comp(vacation a, vacation b){
	if(a.l < b.l)
		return true;
	if(a.l > b.l)
		return false;
	if(a.cost < b.cost)
		return true;
	return false;
}
int main() {
	long n,x;
	cin>>n>>x;
	vector<bigd> dsarr(x);
	while(n--) {
		vacation v;
		cin>>v.l>>v.r>>v.cost;
		if(v.r-v.l+1 >= x) continue;
		dsarr[v.r-v.l+1].arr.push_back(v);
	}
	for(long i=0;i<dsarr.size();i++){
		if(dsarr[i].arr.size()!=0){ 
			sort(dsarr[i].arr.begin(),dsarr[i].arr.end(), comp);
			dsarr[i].arr[dsarr[i].arr.size()-1].minval = dsarr[i].arr[dsarr[i].arr.size()-1].cost;
			for(long j = dsarr[i].arr.size()-2;j >= 0; j--){
				dsarr[i].arr[j].minval = min(dsarr[i].arr[j+1].minval,dsarr[i].arr[j].cost);
			}
		}
	}
	long long ans = -1;
	for(long i=1;i<=x/2;i++){
		if(dsarr[i].arr.size()!=0 && dsarr[x-i].arr.size()!=0) {
			for(long j=0;j<dsarr[i].arr.size();j++){
				vacation v = dsarr[i].arr[j];
				vacation f;
				f.l = v.r+1;
				f.r = 0;
				f.cost = 0;
				vector<vacation>::iterator it = lower_bound(dsarr[x-i].arr.begin(),dsarr[x-i].arr.end(),f, comp);
				if( it != dsarr[x-i].arr.end()){
					if(ans == -1) ans = it->minval+v.cost;
					else ans = min(ans,it->minval+v.cost);
				}
			}
			for(long j=0;j<dsarr[x-i].arr.size();j++){
				vacation v = dsarr[x-i].arr[j];
				vacation f;
				f.l = v.r+1;
				f.r = 0;
				f.cost = 0;
				vector<vacation>::iterator it = lower_bound(dsarr[i].arr.begin(),dsarr[i].arr.end(),f, comp);
				if( it != dsarr[i].arr.end()){
					if(ans == -1) ans = it->minval+v.cost;
					else ans = min(ans,it->minval+v.cost);
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}