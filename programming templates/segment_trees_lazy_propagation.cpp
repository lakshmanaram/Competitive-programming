// segment tree for sum of subarray lazy propogation
#include <bits/stdc++.h>
using namespace std;
class node{
public:
	long long val;
};
class segment_tree{
public:
	vector<node> tnodes;
	vector<node> arr;
	vector<long long> lazy;
	segment_tree(long n){
		arr.resize(n);
		for(long i=0;i<n;i++)
			cin>>arr[i].val;
	}
	void build_segment_tree(long index, long start, long end) {
		// cout<<index<<" range "<<start<<" -> "<<end<<endl;
		if(start == end){
			// leaf node
			if(tnodes.size() <= index)
				tnodes.resize(index+1);
			tnodes[index].val = arr[start].val;
		} else {
			long mid = (start+end)/2;
			build_segment_tree(2*index+1,start,mid);
			build_segment_tree(2*index+2,mid+1,end);
			tnodes[index].val = tnodes[2*index+1].val + tnodes[2*index+2].val;
		}
		lazy.resize(tnodes.size(),0);
	}
	long long query_range_lazy(long index, long start, long end, long l, long r) {
		if(start > r || end < l)
			return 0;
		if(lazy[index]!=0) {
			tnodes[index].val += (end-start+1)*lazy[index];
			if(start != end){
				// not a leaf node
				lazy[2*index+1] += lazy[index];
				lazy[2*index+2] += lazy[index];
			}
			lazy[index] = 0;
		}	
		if(start >= l && end <= r)
			return tnodes[index].val;
		long mid = (start+end)/2;
		long long val1 = query_range_lazy(2*index+1,start,mid,l,r);
		long long val2 = query_range_lazy(2*index+2,mid+1,end,l,r);
		return val1+val2;
	}
	void update_range_lazy(long index, long start, long end, long l, long r, long long val){
		if(lazy[index]!=0) {
			tnodes[index].val += (end-start+1)*lazy[index];
			if(start != end){
				// not a leaf node
				lazy[2*index+1] += lazy[index];
				lazy[2*index+2] += lazy[index];
			}
			lazy[index] = 0;
		}	
		if(start > end || start > r || end < l)
			return;
		if(start >= l && end <= r){
			tnodes[index].val += (end-start+1)*val;
			if(start != end){
				lazy[2*index+1] += val;
				lazy[2*index+2] += val;
			}
		} else {
			long mid = (start+end)/2;
			update_range_lazy(2*index+1, start, mid, l, r, val);
			update_range_lazy(2*index+2, mid+1, end, l, r, val);
			tnodes[index].val = tnodes[2*index+1].val + tnodes[2*index+2].val;
		}
	}
	void update_query() {
		//update range
		long l,r;
		long long val;
		cin>>l>>r;
		cin>>val;
		update_range_lazy(0,0,arr.size()-1,l,r,val);
		show_tnodes();
		show_arr();
		show_lazy();
	}
	void show_tnodes() {
		for(long i=0;i<tnodes.size();i++)
			cout<<tnodes[i].val<<" ";
		cout<<endl;
	}
	void show_arr() {
		for(long i=0;i<arr.size();i++)
			cout<<arr[i].val<<" ";
		cout<<endl;
	}
	void show_lazy() {
		for(long i=0;i<lazy.size();i++)
			cout<<lazy[i]<<" ";
		cout<<endl;
	}
};
int main(){
	long n;
	cin>>n;
	segment_tree st(n);	
	st.build_segment_tree(0,0,st.arr.size()-1);
	st.show_arr();
	st.show_tnodes();
	st.update_query();
	while(1){
		long l,r;
		cin>>l>>r;
		cout<<st.query_range_lazy(0,0,st.arr.size()-1,l,r)<<endl;
		st.show_lazy();
	}
	return 0;
}