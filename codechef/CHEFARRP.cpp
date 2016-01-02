#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long long  n,i,s;
		long long ans;
		cin>>n;
		vector<long long> array;
		for(i=0;i<n;i++){
			int x;
			cin>>x;
			array.push_back(x);
		}
		ans = n;
		for(s=2;s<=n;s++){
			for(i=0;i+s<=n;i++){
				long long p = 1;
				long long sum = 0;
				for(int j=i;j<i+s;j++){
					sum += array[j];
					p *= array[j];
				}
				if(p==sum){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
