#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		long n, m;
		cin>>n>>m;
		vector<long long> arr(n);
		long long sum =0;
		for(long i=0;i<n;i++){
			cin>>arr[i];
			sum += arr[i];
		}
		bool flag = true;
		long long ans = 0;
		long actual;
		if(sum % arr.size() == 0){
			actual = sum /arr.size();
			for(long i=0;i<m;i++){
				for(long j = i;j < n;j+=m){
					if(j+m >= n && arr[j] != actual){
						flag = false;
						break;
					}
					if(arr[j] > actual){
						ans += arr[j]-actual;
						arr[j+m] += arr[j]-actual;
						arr[j] = actual;
					} else if (arr[j] < actual){
						ans += actual-arr[j];
						arr[j+m] += arr[j]-actual;
						arr[j] = actual;
					}
				}
			}
		} else
			flag = false;
		cout<<(flag?ans:-1)<<endl;
	}
}