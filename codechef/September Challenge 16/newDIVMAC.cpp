// segment tree for sum of subarray lazy propogation
#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
   return (b != 0)? gcd(b, a % b): a;
}
long primes[1000001];
vector<long> iterateprimes;
long getPrimes(long long a){
	if(a >= 1000001 ){
		for(long i=0;;i++){
			if(a%iterateprimes[i] == 0)
				return iterateprimes[i];
		}
	} else 
		return primes[a];
}
void markMultiples(long a, long n) {
    long i = 2, num;
    while ( (num = i*a) <= n ) {
        if(primes[num] == 1)
			primes[num] = a;
        ++i;
    }
}
void SieveOfEratosthenes(long n) {
    fill(primes,primes+1000001,1);
    for (long i=2; i<n; ++i)
        if ( primes[i] == 1 ){
        	primes[i] = i;
        	iterateprimes.push_back(i);
            markMultiples(i, n);
        }
}
class segment_tree{
public:
	vector<long long> tnodes;
	vector<long> arr;
	vector<long> lazy;
	void build_segment_tree(long index, long start, long end) {
		// cout<<index<<" range "<<start<<" -> "<<end<<endl;
		if(start == end){
			// leaf node
			if(tnodes.size() <= index)
				tnodes.resize(index+1,1);
			tnodes[index] = arr[start];
		} else {
			long mid = (start+end)/2;
			build_segment_tree(2*index+1,start,mid);
			build_segment_tree(2*index+2,mid+1,end);

			long long lpd1 = tnodes[2*index+1];
			long long lpd2 = tnodes[2*index+2];
			long long gcd12 = gcd(lpd1,lpd2);
			tnodes[index] = gcd12;
			lpd1 /= gcd12;
			lpd2 /= gcd12;
			while(lpd1 != 1 && lpd2 != 1){
				long long val1 = getPrimes(lpd1);
				long long val2 = getPrimes(lpd2);
				tnodes[index] *= max(val1,val2);
				lpd1 /= val1;
				lpd2 /= val2;
			}
			tnodes[index] *= lpd1;
			tnodes[index] *= lpd2;
		}
	}
	segment_tree(long n){
		arr.resize(n);
		for(long i=0;i<n;i++)
			cin>>arr[i];
		build_segment_tree(0,0,n-1);
		lazy.resize(tnodes.size(),0);
	}
	long long query_range(long index, long start, long end, long l, long r, long long curmax) {
		if(start > r || end < l || start > end)
			return 1;
		while(lazy[index] > 0){
			if(tnodes[index] != 1){
				tnodes[index] /= getPrimes(tnodes[index]);
				if(start != end){
					lazy[2*index + 1]++;
					lazy[2*index + 2]++;
				}
				lazy[index]--;
			} else {
				lazy[index] = 0;
			}
		}
		if(tnodes[index] == 1)
			return 1;
		if(tnodes[index] <= curmax)
			return 1;
		if(start >= l && end <= r){
			curmax = getPrimes(tnodes[index]);
			return getPrimes(tnodes[index]);
		}
		long mid = (start+end)/2;
		long long val1 = query_range(2*index+1,start,mid,l,r,curmax);
		long long val2 = query_range(2*index+2,mid+1,end,l,r,curmax);
		return max(val1,val2);
	}
	void update_range(long index, long start, long end, long l, long r){
		while(lazy[index] > 0){
			if(tnodes[index] != 1){
				tnodes[index] /= getPrimes(tnodes[index]);
				if(start != end){
					lazy[2*index + 1]++;
					lazy[2*index + 2]++;
				}
				lazy[index]--;
			} else {
				lazy[index] = 0;
			}
		}
		if(start > end || start > r || end < l)
			return;
		if(tnodes[index] == 1)
			return;
		if(start >= l && r >= end){
			if(tnodes[index] != 1){
				tnodes[index] /= getPrimes(tnodes[index]);
				if(start != end){
					lazy[2*index + 1]++;
					lazy[2*index + 2]++;
				}
			}
			return;
		} else {
			long mid = (start+end)/2;
			update_range(2*index+1, start, mid, l, r);
			update_range(2*index+2, mid+1, end, l, r);

			long long lpd1 = tnodes[2*index+1];
			long long lpd2 = tnodes[2*index+2];
			long long gcd12 = gcd(lpd1,lpd2);
			tnodes[index] = gcd12;
			lpd1 /= gcd12;
			lpd2 /= gcd12;
			while(lpd1 != 1 && lpd2 != 1){
				long long val1 = getPrimes(lpd1);
				long long val2 = getPrimes(lpd2);
				tnodes[index] *= max(val1,val2);
				lpd1 /= val1;
				lpd2 /= val2;
			}
			tnodes[index] *= lpd1;
			tnodes[index] *= lpd2;
		}
	}
	void update_query() {
		//update range
		long l,r;
		cin>>l>>r;
		update_range(0,0,arr.size()-1,l-1,r-1);
	}
};
int main(){
	int t;
	cin>>t;
    SieveOfEratosthenes(1000001);
	while(t--) {
		long n,m;
		cin>>n>>m;
		segment_tree st(n);
		while(m--){
			int choice;
			cin>>choice;
			long l,r;
			cin>>l>>r;
			if(choice == 0)
				st.update_query();
			else{
				long long ans = 1;
				cout<<st.query_range(0,0,n-1,l-1,r-1,ans)<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}