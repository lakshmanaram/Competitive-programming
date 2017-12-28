#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
using namespace std;
int main(){
	long t;
	cin>>t;
	while(t--) {
		long n;
		ll d;
		cin>>n>>d;
		vector<ll> arr(n);
		bool edge = false;
		for(long i=0;i<n;i++){
			scanf("%lld", &arr[i]);
			if(arr[i] >= d && !edge){
				printf("1\n");
				edge = true;	
			}
		}
		if(edge) continue;
		if(d <= 0) {
			printf("-1\n");
			continue;
		}
		ll sum = 0, ans = n+1;
		ll csum = 0;
	    ll i=0, j=0;
	    set<pair<ll, ll> > s;
	    ll mv = 0;
	    while (j < n) {
	        while (sum < d && j < n) {
	            if (sum <= 0){
	                i = j;
	                sum = 0;
	                csum = 0;
	                mv = 0;
	                s.clear();
	            }
	            csum += arr[j];
	            sum += arr[j++];
	            s.insert(mp(csum, j));
	        }
	        while (sum >= d && i < n) {
		        if(ans > j-i){
		        	ans = j-i;
		        }
	        	while(s.size()!=0){
		        	pair<ll, ll> x = *s.begin();
		        	s.erase(s.begin());
		        	if(x.second < i) continue;
		        	i = x.second;
		            sum -= (x.first-mv);
		            mv = x.first;
		            break;
		        }
	        }
	    }
	    if(ans == n+1) printf("-1\n");
	    else printf("%lld\n",ans);
	}
	return 0;
}
/*
1 
7 7
5 1 -4 2 3 2 -7
*/