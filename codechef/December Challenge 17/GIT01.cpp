#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
using namespace std;
int main(){
	int t,n,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		vector<string> arr(n);
		for(long i=0;i<arr.size();i++){
			cin>>arr[i];
		}
		char x = 'R';
		long tempans = 0, ans = 0;
		for(long i=0;i<n;i++){
			if(x == 'R') x = 'G';
			else x = 'R';
			char y = x;
			for(long j=0;j<m;j++){
				if(y == 'R') y = 'G';
				else y = 'R';
				if(arr[i][j] != y){
					if(y == 'R')
						tempans += 3;
					else tempans += 5;
				}
			}
		}
		ans = tempans;
		x = 'G';
		tempans = 0;
		for(long i=0;i<n;i++){
			if(x == 'R') x = 'G';
			else x = 'R';
			char y = x;
			for(long j=0;j<m;j++){
				if(y == 'R') y = 'G';
				else y = 'R';
				if(arr[i][j] != y){
					if(y == 'R')
						tempans += 3;
					else tempans += 5;
				}
			}
		}
		ans = min(tempans, ans);
		cout<<ans<<endl;
	}

	return 0;
}