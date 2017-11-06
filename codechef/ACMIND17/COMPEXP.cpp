#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		double n,k;
		cin>>n>>k;
		double ans = 2*(n-1)*(k-1);
		ans /= k;
		ans += 2;
		printf("%.8f\n",ans);
	}
	return 0;
}