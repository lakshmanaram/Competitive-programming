// segment tree for sum of subarray lazy propogation
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
bool arr[1000001];
vector<long long> primes;
bool isprime(int a) {
    if(arr[a]==false)
        return true;
    return false;
}
void markMultiples(int a, int n) {
    int i = 2, num;
    while ( (num = i*a) <= n ) {
        arr[num] = true;
        ++i;
    }
}
void SieveOfEratosthenes(int n) {
    fill(arr,arr+1000001,false);
    for (int i=2; i<n; ++i)
        if ( arr[i] == false ){
        	primes.push_back(i);
            markMultiples(i, n);
        }
}
long long get_lpd(long long a){
	if(a==1)
		return 1;
	if(isprime(a))
		return a;
	for(long i=0;;i++){
		if(a%primes[i] == 0)
			return primes[i];
	}
}
long long get_max_lpd(long long a, long long b){
	if(a == 1)
		return b;
	if(b == 1)
		return a;
	return max(a,b);
}
class node{
public:
	long long val;
	long long lpd; // least prime divisor
};
class segment_tree{
public:
	vector<node> tnodes;
	vector<node> arr;
	void build_segment_tree(long index, long start, long end) {
		// cout<<index<<" range "<<start<<" -> "<<end<<endl;
		if(start == end){
			// leaf node
			node temp;
			temp.lpd = 1;
			if(tnodes.size() <= index)
				tnodes.resize(index+1,temp);
			tnodes[index].val = arr[start].val;
			tnodes[index].lpd = get_lpd(tnodes[index].val);
			// cout<<start<<" -> "<<tnodes[index].lpd<<" of "<<tnodes[index].val<<endl;
		} else {
			long mid = (start+end)/2;
			build_segment_tree(2*index+1,start,mid);
			build_segment_tree(2*index+2,mid+1,end);
			tnodes[index].lpd = get_max_lpd(tnodes[2*index+1].lpd,tnodes[2*index+2].lpd);
			// cout<<index<<" represents "<<start<<" -> "<<end<<" has "<<tnodes[index].lpd<<endl;
		}
	}
	segment_tree(long n){
		arr.resize(n);
		for(long i=0;i<n;i++)
			cin>>arr[i].val;
		build_segment_tree(0,0,n-1);
		// show_tnodes();
		// show_arr();
	}
	long long query_range(long index, long start, long end, long l, long r) {
		if(start > r || end < l || start > end)
			return 1;
		if(start >= l && end <= r)
			return tnodes[index].lpd;
		if(tnodes[index].lpd == 1)
			return 1;
		long mid = (start+end)/2;
		long long val1 = query_range(2*index+1,start,mid,l,r);
		long long val2 = query_range(2*index+2,mid+1,end,l,r);
		return get_max_lpd(val1,val2);
	}
	void update_range(long index, long start, long end, long l, long r){
		if(start > end || start > r || end < l)
			return;
		if(tnodes[index].lpd == 1)
			return;
		if(start == end){
			tnodes[index].val /= tnodes[index].lpd;
			tnodes[index].lpd = get_lpd(tnodes[index].val);
			return;
		} else {
			long mid = (start+end)/2;
			update_range(2*index+1, start, mid, l, r);
			update_range(2*index+2, mid+1, end, l, r);
			tnodes[index].lpd = get_max_lpd(tnodes[2*index+1].lpd,tnodes[2*index+2].lpd);
		}
	}
	void update_query() {
		//update range
		long l,r;
		cin>>l>>r;
		update_range(0,0,arr.size()-1,l-1,r-1);
		// show_tnodes();
		// show_arr();
	}
	void show_tnodes() {
		for(long i=0;i<tnodes.size();i++)
			cout<<tnodes[i].lpd<<" ";
		cout<<endl;
	}
	void show_arr() {
		for(long i=0;i<arr.size();i++)
			cout<<arr[i].val<<" ";
		cout<<endl;
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
			if(choice == 0)
				st.update_query();
			else{
				long l,r;
				cin>>l>>r;
				cout<<st.query_range(0,0,n-1,l-1,r-1)<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}