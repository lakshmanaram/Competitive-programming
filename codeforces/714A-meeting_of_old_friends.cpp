#include <bits/stdc++.h>
using namespace std;
int main(){
	long long l,r,q,w,p;
	cin>>l>>r>>q>>w>>p;
	long long ans = 0;
	long long start = max(l,q), end = min(r,w);
	ans = end-start+1;
	if(ans < 0)
		ans = 0;
	if(p >= start && p <= end)
		ans--;
	cout<<ans<<endl;
	return 0;
}