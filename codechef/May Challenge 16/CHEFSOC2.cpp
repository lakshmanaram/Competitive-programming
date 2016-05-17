#include<bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,s;
		cin>>n>>m>>s;
		vector<int> a(m);
		for(int i=0;i<m;i++)
			cin>>a[i];
		vector<long long> ans(n,0);
		ans[s-1] = 1;
		for(int i=0;i<m;i++){
			vector<long long> temp(n,0);
			for(int j=0;j<n;j++){
				if(j-a[i] >= 0){
					temp[j] += ans[j-a[i]];
					temp[j] %= mod;
				}
				if(j+a[i]<n){
					temp[j] += ans[j+a[i]];
					temp[j] %= mod;
				}
			}
			ans = temp;
		}
		for(int i=0;i<n;i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}
