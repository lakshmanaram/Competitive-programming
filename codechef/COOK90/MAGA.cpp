#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define all(S) S.begin(), S.end()
#define S(a) scanf("%lld", &a)
using namespace std;
int main(){
	long t;
	scanf("%ld", &t);
	while(t--) {
		long n;
		scanf("%ld", &n);
		vector<ll> arr(n);
		for(long i=0;i<n;i++){
			scanf("%lld", &arr[i]);
		}
		if(n&1){
			if(n == 1) {
				cout<<0<<endl;
				continue;
			}
			long i = n/2;
			ll mi = arr[i];
			ll mai = arr[i];
			vll temp = arr;
			i--;
			while(i >= 0){
				long tt = max(arr[i], arr[n-i-1]);
				arr[i] = min(arr[i], arr[n-i-1]);
				arr[n-i-1] = tt;
				i--;
			}
			bool flag1 = true, flag2 = true;
			bool alternate = false;
			for(long i=1;i<n;i++){
				if(alternate) {
					if(arr[i] <= arr[i-1]) {
						flag2 = false;
						// cout<<"arr[i] = "<<arr[i]<<" "<<arr[i-1]<<" arr[i] <= arr[i-1]"<<endl;
					}
				} else {
					if(arr[i] >= arr[i-1]) {
						flag2 = false;
						// cout<<"arr[i] = "<<arr[i]<<" "<<arr[i-1]<<" arr[i] >= arr[i-1]"<<endl;
					}
				}
				alternate = !alternate;
			}
			// if(flag2) cout<<"true";
			// else cout<<"false";
			flag1 = flag2;
			flag2 = true;
			alternate = true;
			for(long i=1;i<n;i++){
				if(alternate) {
					if(arr[i] <= arr[i-1]) {
						flag2 = false;
						// cout<<"arr[i] = "<<arr[i]<<" "<<arr[i-1]<<" arr[i] <= arr[i-1]"<<endl;
					}
				} else {
					if(arr[i] >= arr[i-1]) {
						flag2 = false;
					}
				}
				alternate = !alternate;
			}
			// cout<<endl;
			// if(flag2) cout<<"true";
			// else cout<<"false";
			// cout<<endl;
			if(!(flag1||flag2)){
				cout<<"-1"<<endl;
				continue;
			}
			arr = temp;
			vll ttt(n/2, -1);
			vector<vll> memo(2, ttt);
			vector<vll> vals(2, ttt);
			for(long i=0;i<n/2;i++){
				vals[0][i] = arr[i];
				vals[1][i] = arr[n-1-i];
			}
			memo[0][0] = 0;
			memo[1][0] = 1;
			alternate = false;
			for(long i=1;i<n/2;i++){
				if(!alternate){
					bool fflag = false;
					if(arr[i] > vals[0][i-1] && arr[n-1-i] > vals[1][i-1]){
						if(memo[0][i-1] != -1){
							memo[0][i] = memo[0][i-1];
							fflag = true;
						}
					}
					if(arr[i] > vals[1][i-1] && arr[n-1-i] > vals[0][i-1]){
						if(!fflag){
							if(memo[1][i-1] != -1)
								memo[0][i] = memo[1][i-1];	
						} else {
							if(memo[1][i-1] != -1)
								memo[0][i] = min(memo[1][i-1], memo[0][i]);	
						}
					}
					fflag = false;
					if(arr[n-i-1] > vals[0][i-1] && arr[i] > vals[1][i-1]){
						if(memo[0][i-1] != -1){
							memo[1][i] = 1+memo[0][i-1];
							fflag = true;
						}
					}
					if(arr[n-i-1] > vals[1][i-1] && arr[i] > vals[0][i-1]){
						if(!fflag){
							if(memo[1][i-1] != -1)
								memo[1][i] = 1+memo[1][i-1];	
						} else {
							if(memo[1][i-1] != -1)
								memo[1][i] = min(1+memo[1][i-1], memo[1][i]);	
						}
					}
				} else {
					bool fflag = false;
					if(arr[i] < vals[0][i-1] && arr[n-1-i] < vals[1][i-1]){
						if(memo[0][i-1] != -1){
							memo[0][i] = memo[0][i-1];
							fflag = true;
						}
					}
					if(arr[i] < vals[1][i-1] && arr[n-1-i] < vals[0][i-1]){
						if(!fflag){
							if(memo[1][i-1] != -1)
								memo[0][i] = memo[1][i-1];	
						} else {
							if(memo[1][i-1] != -1)
								memo[0][i] = min(memo[1][i-1], memo[0][i]);	
						}
					}
					fflag = false;
					if(arr[n-i-1] < vals[0][i-1] && arr[i] < vals[1][i-1]){
						if(memo[0][i-1] != -1){
							memo[1][i] = 1+memo[0][i-1];
							fflag = true;
						}
					}
					if(arr[n-i-1] < vals[1][i-1] && arr[i] < vals[0][i-1]){
						if(!fflag){
							if(memo[1][i-1] != -1)
								memo[1][i] = 1+memo[1][i-1];	
						} else {
								memo[1][i] = min(1+memo[1][i-1], memo[1][i]);	
						}
					}
				}
				alternate = !alternate;
			}
			ll ans = -1;
			if(alternate) {
				if(vals[0][(n/2)-1] > arr[n/2]){
					ans = min(memo[0][(n/2)-1], memo[1][(n/2)-1]);
				}
			} else {
				if(vals[0][(n/2)-1] < arr[n/2]){
					ans = min(memo[0][(n/2)-1], memo[1][(n/2)-1]);
				}
			}
			fill(all(memo[0]), -1);
			fill(all(memo[1]), -1);
			memo[0][0] = 0;
			memo[1][0] = 1;
			alternate = true;
			for(long i=1;i<n/2;i++){
				if(!alternate){
					bool fflag = false;
					if(arr[i] > vals[0][i-1] && arr[n-1-i] > vals[1][i-1]){
						if(memo[0][i-1] != -1){
							memo[0][i] = memo[0][i-1];
							fflag = true;
						}
					}
					if(arr[i] > vals[1][i-1] && arr[n-1-i] > vals[0][i-1]){
						if(!fflag){
							if(memo[1][i-1] != -1)
								memo[0][i] = memo[1][i-1];	
						} else {
							if(memo[1][i-1] != -1)
								memo[0][i] = min(memo[1][i-1], memo[0][i]);	
						}
					}
					fflag = false;
					if(arr[n-i-1] > vals[0][i-1] && arr[i] > vals[1][i-1]){
						if(memo[0][i-1] != -1){
							memo[1][i] = 1+memo[0][i-1];
							fflag = true;
						}
					}
					if(arr[n-i-1] > vals[1][i-1] && arr[i] > vals[0][i-1]){
						if(!fflag){
							if(memo[1][i-1] != -1)
								memo[1][i] = 1+memo[1][i-1];	
						} else {
							if(memo[1][i-1] != -1)
								memo[1][i] = min(1+memo[1][i-1], memo[1][i]);	
						}
					}
				} else {
					bool fflag = false;
					if(arr[i] < vals[0][i-1] && arr[n-1-i] < vals[1][i-1]){
						if(memo[0][i-1] != -1){
							memo[0][i] = memo[0][i-1];
							fflag = true;
						}
					}
					if(arr[i] < vals[1][i-1] && arr[n-1-i] < vals[0][i-1]){
						if(!fflag){
							if(memo[1][i-1] != -1)
								memo[0][i] = memo[1][i-1];	
						} else {
							if(memo[1][i-1] != -1)
								memo[0][i] = min(memo[1][i-1], memo[0][i]);	
						}
					}
					fflag = false;
					if(arr[n-i-1] < vals[0][i-1] && arr[i] < vals[1][i-1]){
						if(memo[0][i-1] != -1){
							memo[1][i] = 1+memo[0][i-1];
							fflag = true;
						}
					}
					if(arr[n-i-1] < vals[1][i-1] && arr[i] < vals[0][i-1]){
						if(!fflag){
							if(memo[1][i-1] != -1)
								memo[1][i] = 1+memo[1][i-1];	
						} else {
								memo[1][i] = min(1+memo[1][i-1], memo[1][i]);	
						}
					}
				}
				alternate = !alternate;
			}
			if(alternate) {
				if(vals[0][(n/2)-1] > arr[n/2]){
					if(ans == -1)
						ans = min(memo[0][(n/2)-1], memo[1][(n/2)-1]);
					else
						ans = min(ans, min(memo[0][(n/2)-1], memo[1][(n/2)-1]));
				}
			} else {
				if(vals[0][(n/2)-1] < arr[n/2]){
					if(ans == -1)
						ans = min(memo[0][(n/2)-1], memo[1][(n/2)-1]);
					else
						ans = min(ans, min(memo[0][(n/2)-1], memo[1][(n/2)-1]));
				}
			}
			cout<<ans<<endl;
		} else {
			long i = 0;
			long j = arr.size()-1;
			vll temp = arr;
			bool flag = true;
			bool alternate = true;
			while(i<j){
				ll mint = min(arr[i], arr[j]);
				ll maxt = max(arr[i], arr[j]);
				if(alternate){
					arr[i] = mint;
					arr[j] = maxt;
				} else {
					arr[i] = maxt;
					arr[j] = mint;
				}
				alternate = !alternate;
				i++;
				j--;
			}
			for(i = 0; i< temp.size(); i += 2){
				if(arr[i] >= arr[i+1])
					flag = false;
				if((i+2 != n) && (arr[i+1] <= arr[i+2]))
					flag = false;
			}
			if(!flag) {
				cout<<"-1"<<endl;
				continue;
			}
			arr = temp;
			vll ttt(n/2, -1);
			vector<vll> memo(2, ttt);
			vector<vll> vals(2, ttt);
			for(long i=0;i<n/2;i++){
				vals[0][i] = arr[i];
				vals[1][i] = arr[n-1-i];
			}
			memo[0][0] = 0;
			memo[1][0] = 1;
			alternate = false;
			for(long i=1;i<n/2;i++){
				if(!alternate){
					bool fflag = false;
					if(arr[i] > vals[0][i-1] && arr[n-1-i] < vals[1][i-1]){
						if(memo[0][i-1] != -1){
							memo[0][i] = memo[0][i-1];
							fflag = true;
						}
					}
					if(arr[i] > vals[1][i-1] && arr[n-1-i] < vals[0][i-1]){
						if(!fflag){
							if(memo[1][i-1] != -1)
								memo[0][i] = memo[1][i-1];	
						} else {
							if(memo[1][i-1] != -1)
								memo[0][i] = min(memo[1][i-1], memo[0][i]);	
						}
					}
					fflag = false;
					if(arr[n-i-1] > vals[0][i-1] && arr[i] < vals[1][i-1]){
						if(memo[0][i-1] != -1){
							memo[1][i] = 1+memo[0][i-1];
							fflag = true;
						}
					}
					if(arr[n-i-1] > vals[1][i-1] && arr[i] < vals[0][i-1]){
						if(!fflag){
							if(memo[1][i-1] != -1)
								memo[1][i] = 1+memo[1][i-1];	
						} else {
							if(memo[1][i-1] != -1)
								memo[1][i] = min(1+memo[1][i-1], memo[1][i]);	
						}
					}
				} else {
					bool fflag = false;
					if(arr[i] < vals[0][i-1] && arr[n-1-i] > vals[1][i-1]){
						if(memo[0][i-1] != -1){
							memo[0][i] = memo[0][i-1];
							fflag = true;
						}
					}
					if(arr[i] < vals[1][i-1] && arr[n-1-i] > vals[0][i-1]){
						if(!fflag){
							if(memo[1][i-1] != -1)
								memo[0][i] = memo[1][i-1];	
						} else {
							if(memo[1][i-1] != -1)
								memo[0][i] = min(memo[1][i-1], memo[0][i]);	
						}
					}
					fflag = false;
					if(arr[n-i-1] < vals[0][i-1] && arr[i] > vals[1][i-1]){
						if(memo[0][i-1] != -1){
							memo[1][i] = 1+memo[0][i-1];
							fflag = true;
						}
					}
					if(arr[n-i-1] < vals[1][i-1] && arr[i] > vals[0][i-1]){
						if(!fflag){
							if(memo[1][i-1] != -1)
								memo[1][i] = 1+memo[1][i-1];	
						} else {
							if(memo[1][i-1] != -1)
								memo[1][i] = min(1+memo[1][i-1], memo[1][i]);	
						}
					}
				}
				alternate = !alternate;
			}
			ll ans = -1;
			if(alternate) {
				if(vals[0][(n/2)-1] > vals[1][(n/2)-1]){
					ans = memo[0][(n/2)-1];
				} else if(vals[0][(n/2)-1] < vals[1][(n/2)-1]) {
					ans = memo[1][(n/2)-1];
				}
			} else {
				if(vals[0][(n/2)-1] < vals[1][(n/2)-1]){
					ans = memo[0][(n/2)-1];
				} else if(vals[0][(n/2)-1] > vals[1][(n/2)-1]) {
					ans = memo[1][(n/2)-1];
				}
			}
			fill(all(memo[0]), -1);
			fill(all(memo[1]), -1);
			memo[0][0] = 0;
			memo[1][0] = 1;
			alternate = true;
			for(long i=1;i<n/2;i++){
				if(!alternate){
					bool fflag = false;
					if(arr[i] > vals[0][i-1] && arr[n-1-i] < vals[1][i-1]){
						if(memo[0][i-1] != -1){
							memo[0][i] = memo[0][i-1];
							fflag = true;
						}
					}
					if(arr[i] > vals[1][i-1] && arr[n-1-i] < vals[0][i-1]){
						if(!fflag){
							if(memo[1][i-1] != -1)
								memo[0][i] = memo[1][i-1];	
						} else {
							if(memo[1][i-1] != -1)
								memo[0][i] = min(memo[1][i-1], memo[0][i]);	
						}
					}
					fflag = false;
					if(arr[n-i-1] > vals[0][i-1] && arr[i] < vals[1][i-1]){
						if(memo[0][i-1] != -1){
							memo[1][i] = 1+memo[0][i-1];
							fflag = true;
						}
					}
					if(arr[n-i-1] > vals[1][i-1] && arr[i] < vals[0][i-1]){
						if(!fflag){
							if(memo[1][i-1] != -1)
								memo[1][i] = 1+memo[1][i-1];	
						} else {
							if(memo[1][i-1] != -1)
								memo[1][i] = min(1+memo[1][i-1], memo[1][i]);	
						}
					}
				} else {
					bool fflag = false;
					if(arr[i] < vals[0][i-1] && arr[n-1-i] > vals[1][i-1]){
						if(memo[0][i-1] != -1){
							memo[0][i] = memo[0][i-1];
							fflag = true;
						}
					}
					if(arr[i] < vals[1][i-1] && arr[n-1-i] > vals[0][i-1]){
						if(!fflag){
							if(memo[1][i-1] != -1)
								memo[0][i] = memo[1][i-1];	
						} else {
							if(memo[1][i-1] != -1)
								memo[0][i] = min(memo[1][i-1], memo[0][i]);	
						}
					}
					fflag = false;
					if(arr[n-i-1] < vals[0][i-1] && arr[i] > vals[1][i-1]){
						if(memo[0][i-1] != -1){
							memo[1][i] = 1+memo[0][i-1];
							fflag = true;
						}
					}
					if(arr[n-i-1] < vals[1][i-1] && arr[i] > vals[0][i-1]){
						if(!fflag){
							if(memo[1][i-1] != -1)
								memo[1][i] = 1+memo[1][i-1];	
						} else {
							if(memo[1][i-1] != -1)
								memo[1][i] = min(1+memo[1][i-1], memo[1][i]);	
						}
					}
				}
				alternate = !alternate;
			}
			if(alternate) {
				if(vals[0][(n/2)-1] > vals[1][(n/2)-1]){
					if(ans == -1)
						ans = memo[0][(n/2)-1];
					else
						ans = min(ans, memo[0][(n/2)-1]);
				} else if(vals[0][(n/2)-1] < vals[1][(n/2)-1]) {
					if(ans == -1) ans = memo[1][(n/2)-1];
					else {
						ans = min(ans, memo[1][(n/2)-1]);
					}
				}
			} else {
				if(vals[0][(n/2)-1] < vals[1][(n/2)-1]){
					if(ans == -1) ans = memo[0][(n/2)-1];
					else {
						ans = min(ans, memo[0][(n/2)-1]);
					}
				} else if(vals[0][(n/2)-1] > vals[1][(n/2)-1]) {
					if(ans == -1) ans = memo[1][(n/2)-1];
					else {
						ans = min(ans, memo[1][(n/2)-1]);
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}