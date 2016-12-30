#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool mycomp(pair<pair<ll, ll>, ll>a, pair<pair<ll, ll>, ll> b){
	if(a.first.first*a.first.second > b.first.first*b.first.second)
		return true;
	// if(a.first.first*a.first.second < b.first.first*b.first.second)
	// 	return false;
	// if(a.first.first > b.first.first)
	// 	return true;
	// if(a.first.first < b.first.first)
	// 	return false;
	// if(a.first.second > b.first.second)
	// 	return true;
	// if(a.first.second < b.first.second)
	// 	return false;
	// if(a.second > b.second)
	// 	return true;
	return false;
}
int main() {
	ll n;
	cin>>n;
	vector<pair<pair<ll, ll>, ll> > arr;
	for(ll i=0;i<n;i++){
		ll x,y,z;
		cin>>x>>y>>z;
		pair<pair<ll, ll>, ll> x1,y1,z1;
		x1 = make_pair(make_pair(min(x,y),max(x,y)),z);
		arr.push_back(x1);
		// arr.push_back(make_pair(make_pair(x,z),y));
		// arr.push_back(make_pair(make_pair(y,x),z));
		y1 = make_pair(make_pair(min(y,z),max(y,z)),x);
		if(y1 != x1)
			arr.push_back(y1);
		z1 = make_pair(make_pair(min(z,x),max(z,x)),y);
		if(x1 != y1 && y1 != z1)
		arr.push_back(z1);
		// arr.push_back(make_pair(make_pair(z,y),x));
	}
	sort(arr.begin(),arr.end(),mycomp);
	vector<ll> ans(arr.size());
	ll ulans = 0;
	for(ll i=0;i<arr.size();i++){
		ll maxv = 0;
		for(ll j=0;j<i;j++) {
			if((arr[i].first.first < arr[j].first.first) && (arr[i].first.second < arr[j].first.second))
				maxv = max(maxv,ans[j]);
		}
		ans[i] = maxv+arr[i].second;
		// cout<<arr[i].first.first<<" "<<arr[i].first.second<<" "<<arr[i].second<<" "<<ans[i]<<endl;
	}
	sort(ans.begin(),ans.end());
	map<ll,ll> hash;
	for(ll i=0;i<ans.size();i++)
		hash[ans[i]]++;
	map<ll,ll>::iterator it;
	bool flag = false;
	ll ansv = 0;
	for(it = hash.begin();it!=hash.end();it++) {
		if(it->second == 1 && it->first > ansv){
			ansv = it->first;
			flag = true;
		}
	}
	if(!flag){
		ans.clear();
		flag = false;
		for(ll i=0;i<arr.size();i++){
			ans.push_back(arr[i].second);
		}
		sort(ans.begin(),ans.end());
		hash.clear();
		for(ll i=0;i<ans.size();i++)
			hash[ans[i]]++;
		ansv = 0;
		for(it = hash.begin();it!=hash.end();it++) {
			if(it->second == 1 && it->first > ansv){
				ansv = it->first;
				flag = true;
			}
		}
		if(!flag)
			cout<<0;
		else
			cout<<ansv;
	}
	else
		cout<<ansv;
	return 0;
}