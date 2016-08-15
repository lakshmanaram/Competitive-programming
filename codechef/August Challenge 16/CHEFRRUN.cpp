#include <bits/stdc++.h>
using namespace std;
vector<long long> arr; 
vector<int> vis;
vector<bool> bvis;
void util(long present, int val){
	if(val == 2 && vis[present] == 2)
		return;
	else if(val == 2) {
		vis[present] = val;
		util((present+arr[present]+1)%arr.size(), val);
	} else if(bvis[present]){
		vis[present] = 2;
		util((present+arr[present]+1)%arr.size(), 2);
	} else if(vis[present] != 0) {
		return;
	}
	else {
		bvis[present] = true;
		vis[present] = val;
		util((present+arr[present]+1)%arr.size(), val);
		bvis[present] = false;
	}
}
int main(){
	long t;
	cin>>t;
	while(t--){
		long n;
		cin>>n;
		vector<long long> a(n);
		for(long i=0;i<n;i++)
			cin>>a[i];
		arr = a;
		vector<int> v(n,0);
		vis = v;
		vector<bool> bv(n);
		bvis = bv;
		long ans = 0;
		for(long i=0;i<n;i++){
			if(vis[i] == 0){
				// fill(bvis.begin(),bvis.end(),false);
				util(i, 1);
			}
			if(vis[i] == 2)
				ans++;
		}
		cout<<ans<<endl;
	}
}