#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
	return (b==0)?a:gcd(b,a%b);
}
int main() {
	long n;
	cin>>n;
	vector<long> arr(n);
	for(long i=0;i<n;i++){
		cin>>arr[i];
		arr[i]--;
	}
	vector<bool> b(n,false);
	bool exists = true;
	long long ans = 1;
	for(long i=0;i<n;i++){
		if(!b[i]){
			long node = i;
			long start = i;
			long cycle = 0;
			long prev = -1;
			while(prev!=node && (prev==-1 || node!=start) && (!b[node])) {
				prev = node;
				b[node] = true;
				node = arr[node];
				cycle++;
			}
			if(node == start){
				if(cycle%2 == 0)
					cycle /= 2;
				ans = ans*cycle/gcd(ans,cycle);
			} else {
				exists = false;
			}
		}
		if(!exists)
			break;
	}
	if(!exists){
		cout<<-1<<endl;
	} else {
		cout<<ans<<endl;
	}
	return 0;
}