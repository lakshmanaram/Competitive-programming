// segment tree for sum of subarray lazy propogation
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
long primes[1000001];
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
            markMultiples(i, n);
        }
}
class node{
public:
	long long val;
	vector<long> lpd;
	long ind;
};
class segment_tree{
public:
	vector<node> tnodes;
	vector<node> arr;
	vector<long> lazy;
	void build_segment_tree(long index, long start, long end) {
		// cout<<index<<" range "<<start<<" -> "<<end<<endl;
		if(start == end){
			// leaf node
			if(tnodes.size() <= index)
				tnodes.resize(index+1);
			tnodes[index].val = arr[start].val;
			tnodes[index].ind = 0;
			long long temp = tnodes[index].val;
			if(tnodes[index].lpd.size()==0)
				tnodes[index].lpd.push_back(primes[temp]);
			temp /= tnodes[index].lpd[0];
			while(temp!=1){
				tnodes[index].lpd.push_back(primes[temp]);
				temp /= tnodes[index].lpd[tnodes[index].lpd.size()-1];
			}
			tnodes[index].lpd.push_back(1);
		} else {
			long mid = (start+end)/2;
			build_segment_tree(2*index+1,start,mid);
			build_segment_tree(2*index+2,mid+1,end);
			tnodes[index].ind = 0;
			vector<long> lpd1 = tnodes[2*index+1].lpd;
			vector<long> lpd2 = tnodes[2*index+2].lpd;
			int i=0, j=tnodes[2*index+1].ind, k = tnodes[2*index+2].ind;
			tnodes[index].lpd.resize(max(lpd1.size()-j,lpd2.size()-k),1);
			while(j<lpd1.size() && k<lpd2.size()){
				tnodes[index].lpd[i] = max(lpd1[j],lpd2[k]);
				i++;
				j++;
				k++;
			}
			while(j<lpd1.size()) {
				tnodes[index].lpd[i] = lpd1[j];
				i++;
				j++;
			}
			while(k<lpd2.size()) {
				tnodes[index].lpd[i] = lpd2[k];
				i++;
				k++;
			}
		}
	}
	segment_tree(long n){
		arr.resize(n);
		for(long i=0;i<n;i++)
			cin>>arr[i].val;
		build_segment_tree(0,0,n-1);
		lazy.resize(tnodes.size(),0);
	}
	long long query_range(long index, long start, long end, long l, long r, long long curmax) {
		if(start > r || end < l || start > end)
			return 1;
		if(tnodes[index].lpd[tnodes[index].ind] == 1)
			return 1;
		while(lazy[index] > 0){
			if(tnodes[index].lpd[tnodes[index].ind] != 1){
				tnodes[index].ind++;
				if(start != end){
					lazy[2*index + 1]++;
					lazy[2*index + 2]++;
				}
			}
			lazy[index]--;
		}
		if(tnodes[index].lpd[tnodes[index].ind] <= curmax)
			return 1;
		if(start >= l && end <= r){
			curmax = tnodes[index].lpd[tnodes[index].ind];
			return tnodes[index].lpd[tnodes[index].ind];
		}
		long mid = (start+end)/2;
		long long val1 = query_range(2*index+1,start,mid,l,r,curmax);
		long long val2 = query_range(2*index+2,mid+1,end,l,r,curmax);
		return max(val1,val2);
	}
	void update_range(long index, long start, long end, long l, long r){
		while(lazy[index] > 0){
			if(tnodes[index].lpd[tnodes[index].ind] != 1){
				tnodes[index].ind++;
				if(start != end){
					lazy[2*index + 1]++;
					lazy[2*index + 2]++;
				}
			}
			lazy[index]--;
		}
		if(start > end || start > r || end < l)
			return;
		if(tnodes[index].lpd[tnodes[index].ind] == 1)
			return;
		if(start >= l && r >= end){
			if(tnodes[index].lpd[tnodes[index].ind] != 1){
				tnodes[index].ind++;
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

			vector<long> lpd1 = tnodes[2*index+1].lpd;
			vector<long> lpd2 = tnodes[2*index+2].lpd;
			int i=0, j=tnodes[2*index+1].ind, k = tnodes[2*index+2].ind;
			tnodes[index].lpd.resize(max(lpd1.size()-j,lpd2.size()-k),1);
			while(j<lpd1.size() && k<lpd2.size()){
				tnodes[index].lpd[i] = max(lpd1[j],lpd2[k]);
				i++;
				j++;
				k++;
			}
			while(j<lpd1.size()) {
				tnodes[index].lpd[i] = lpd1[j];
				i++;
				j++;
			}
			while(k<lpd2.size()) {
				tnodes[index].lpd[i] = lpd2[k];
				i++;
				k++;
			}
			tnodes[index].ind = 0;
		}
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
			long l,r;
			scanf("%d %ld %ld",&choice,&l,&r);			
			if(choice == 0)
				st.update_range(0,0,n-1,l-1,r-1);
			else{
				long long ans = 1;
				printf("%lld ",st.query_range(0,0,n-1,l-1,r-1,ans));
			}
		}
		cout<<endl;
	}
	return 0;
}