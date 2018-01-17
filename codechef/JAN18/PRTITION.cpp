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
	vector<int> arr(1000001, 0);
	while(t--) {
		ll x, n;
		scanf("%lld %lld", &x, &n);
		ll y = (n*(n+1))/2;
		y -= x;
		// cout<<x<<" "<<n<<endl;
		// cout<<y<<endl;
		if(y&1 || n < 4)
			printf("impossible\n");
		else {
			y /= 2;
			arr[x] = 2;
			ll cur = n;
			bool flag = true;
			while(y != 0){
				if(cur == 0) {
					flag = false;
					break;
				}
				if(arr[cur] != 0) {
					cur--;
					continue;
				}
				y -= cur;
				arr[cur] = 1;
				cur = min(cur-1, y);
			}
			if(!flag){
				if (x == 1) {
					for(long i=1;i<n;i++){
						if(arr[i] == 1 && arr[i+1] == 0){
							arr[i] = 0;
							arr[i+1] = 1;
							flag = true;
							break;
						} 
					}
					if (!flag) {
						if(arr[2] == 1) while(1);
						arr[2] = 1;
						for(long i=3;i<n;i++){
							if(arr[i] == 0 && arr[i+1] == 1){
								arr[i] = 1;
								arr[i+1] = 0;
								flag = true;
								break;
							} 
						}
					}
				} else {
					for(long i=1;i<n;i++){
						if(arr[i] == 1 && arr[i+1] == 0){
							arr[i] = 0;
							arr[i+1] = 1;
							flag = true;
							break;
						} 
					}
					if(!flag){
						arr[1] = 0;
						if(arr[3] == 1) while(1);
						arr[3] = 1;
						for(long i=4;i<n;i++){
							if(arr[i] == 0 && arr[i+1] == 1){
								arr[i] = 1;
								arr[i+1] = 0;
								flag = true;
								break;
							} 
						}	
					}
				}
			}
			if (flag){
				for(long i=1;i<=n;i++){
					printf("%d", arr[i]);
					arr[i] = 0;
				}
				printf("\n");
			} else {
				printf("impossible\n");
			}
		}
	}
	return 0;
}