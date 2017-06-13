#include <bits/stdc++.h>
using namespace std;
class d{ 
public:
	long val;
	vector<unsigned long long> vals;
	d() {
		vals.resize(40,0);
	}
};
bool comp(d a, d b) {
	if(a.val < b.val) return true;
	return false;
}
int main() {
	int t;
	cin>>t;
	unsigned long long ax = 0, temp = 1;
	while(t--) {
		long n,k;
		cin>>n>>k;
		vector<d> arr(n);
		for(long i=0;i<n;i++) {
			long m;
			scanf("%ld",&m);
			arr[i].val = m;
			set<long> x;
			while(m--) {
				long temp;
				scanf("%ld",&temp);
				x.insert(temp);
			}
			long val = 1;
			for(set<long>::iterator sit = x.begin(); sit!=x.end();sit++) {
				while(val != *sit) {
					long mul = (val-1)/64;
					long ind = (val-1)%64;
					arr[i].vals[mul] |= temp<<ind;
					val++;
				}
				val++;
			}
			while(val != k+1) {
				long mul = (val-1)/64;
				long ind = (val-1)%64;
				arr[i].vals[mul] |= temp<<ind;
				val++;
			}
		}
		sort(arr.begin(),arr.end(),comp);
		long ans = 0;
		for(long i=0;i<n;i++) {
			for(long j = n-1; j>i;j--) {
				unsigned long long c;
				for(long l=0;l<40;l++) {
					c = arr[i].vals[l] & arr[j].vals[l];
					if(c != 0)
						break;
				} 
				if(c==0) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}