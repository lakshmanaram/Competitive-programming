#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
	return (b == 0)?a:gcd(b,a%b);
}
int main(){
	int t;
	cin>>t;
	while(t--) {
		long n;
		cin>>n;
		vector<long long > arr(n);
		for(long i=0;i<n;i++)
			cin>>arr[i];
		vector<vector<long long> > mat(n);
		long mv = 0;
		for(long i=0;i<arr.size();i++){
			long cur = mv;
			while(cur != -1) {
				long j;
				for(j=0;j<mat[cur].size();j++) {
					if(gcd(mat[cur][j],arr[i])!=1)
						break;
				}
				if(j!=mat[cur].size())
					break;
				cur--;
			}
			cur++;
			mv = max(mv,cur);
			mat[cur].push_back(arr[i]);
		}
		cout<<mv+1<<endl;
	}
	return 0;
} 