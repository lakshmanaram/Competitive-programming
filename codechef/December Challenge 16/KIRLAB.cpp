#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	vector<bool> present(10000001,false);
	vector<vector<long> > ques(t);
	for(int tk=0;tk<t;tk++){
		long n;
		scanf("%ld",&n);
		ques[tk].resize(n);
		for(long i=0;i<n;i++){
			scanf("%ld",&ques[tk][i]);
			present[ques[tk][i]] = true;
		}
	}
	vector<bool> darr(10000001,false);
	vector<vector<long> > primes(10000001);
	for(long i=3;i<primes.size();i+=2) {
		if(!darr[i]) {
			for(long j=i;j<primes.size();j+=i) {
				darr[j] = true;
				if(present[j])
					primes[j].push_back(i);
			}
		}
	}
	for(int tk=0;tk<ques.size();tk++){
		vector<long> arr = ques[tk];
		vector<long> ans(10000001,0);
		long mans = 0;
		for(long i=0;i<arr.size();i++){
			
			long maxval = 0;
			for(long j=0;j<primes[arr[i]].size();j++) {
				maxval = max(maxval,ans[primes[arr[i]][j]]);
			}
			if(arr[i]%2 == 0)
				maxval = max(maxval,ans[2]);
			maxval++;
			
			for(long j=0;j<primes[arr[i]].size();j++) {
				ans[primes[arr[i]][j]] = maxval;
			}
			if(arr[i]%2 == 0)
				ans[2] = maxval;
			mans = max(maxval,mans);
		}
		cout<<mans<<endl;
	}
	return 0;
} 

/*
#include <bits/stdc++.h>
using namespace std;
int main(){
	long maxv = floor(sqrt(10000001));
	// long maxv = 1;
	vector<bool> darr(ceil(sqrt(10000001)),false);
	vector<long> ps;
	vector<vector<long> > primes(ceil(sqrt(10000001)));
	for(long i=2;i<primes.size();i++) {
		if(!darr[i]) {
			for(long j=i;j<primes.size();j+=i) {
				darr[j] = true;
				primes[j].push_back(i);
			}
			darr[i] = false;
			ps.push_back(i);
		}
	}
	int t;
	cin>>t;
	while(t--) {
		long n;
		cin>>n;
		long mans = 0;
		vector<long long > arr(n);
		vector<long> ans(10000001,0);
		for(long i=0;i<n;i++){
			cin>>arr[i];
			if(arr[i] < maxv){
				long maxval = 0;
				for(long j=0;j<primes[arr[i]].size();j++) {
					maxval = max(maxval,ans[primes[arr[i]][j]]);
				}
				maxval++;
				for(long j=0;j<primes[arr[i]].size();j++) {
					ans[primes[arr[i]][j]] = maxval;
					// cout<<"primes[arr[i]][j] = "<<primes[arr[i]][j]<<" "<<ans[primes[arr[i]][j]]<<endl;
				}
				mans = max(maxval,mans);
			} else {
				vector<long> temp;
				long j=0;
				// cout<<arr[i]<<" divisors ";
				for(;j<ps.size() && ps[j]*ps[j] <= arr[i];j++){
					if(arr[i] % ps[j] == 0) {
						temp.push_back(ps[j]);
						while(arr[i]%ps[j] == 0)
							arr[i] /= ps[j];
					}
				}
				// if(temp.size() == 0 || arr[i]!=1)
				// 	temp.push_back(arr[i]);
				// long maxval = 0;
				// for(long j=0;j<temp.size();j++) {
				// 	maxval = max(maxval,ans[temp[j]]);
				// }
				// maxval++;
				// for(long j=0;j<temp.size();j++) {
				// 	ans[temp[j]] = maxval;
				// 	// cout<<arr[i]<<" temp[j] = "<<temp[j]<<" "<<ans[temp[j]]<<endl;
				// }
				// mans = max(maxval,mans);
			}
		}
		cout<<mans<<endl;
	}
	return 0;
} 
*/