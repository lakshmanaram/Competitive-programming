// segment tree for sum of subarray
#include <bits/stdc++.h>
using namespace std;
class node{
public:
	int no5, no2;
};
int get5(long long x) {
	int ans = 0;
	while(x%5 == 0) {
		ans++;
		x /= 5;
	}
	return ans;
}
int get2(long long x) {
	int ans = 0;
	while(x%2 == 0) {
		ans++;
		x /= 2;
	}
	return ans;
}
class segment_tree{
public:
	vector<node> tnodes;
	vector<node> arr;
	segment_tree(long n){
		arr.resize(n);
		for(long i=0;i<n;i++){
			long long x;
			cin>>x;
			arr[i].no2 = get2(x);
			arr[i].no5 = get5(x);
		}
		tnodes.resize(3*n);
	}
	void build_segment_tree(long index, long start, long end) {
		if(start == end){
			tnodes[index].no2 = arr[start].no2;
			tnodes[index].no5 = arr[start].no5;
		} else {
			long mid = (start+end)/2;
			build_segment_tree(2*index+1,start,mid);
			build_segment_tree(2*index+2,mid+1,end);
			tnodes[index].no2 = tnodes[2*index+1].no2 + tnodes[2*index+2].no2;
			tnodes[index].no5 = tnodes[2*index+1].no5 + tnodes[2*index+2].no5;
		}
	}
	long long query_2(long index, long start, long end, long l, long r) {
		if(start > r || end < l)
			return 0;
		if(start >= l && end <= r)
			return tnodes[index].no2;
		long mid = (start+end)/2;
		long long val1 = query_2(2*index+1,start,mid,l,r);
		long long val2 = query_2(2*index+2,mid+1,end,l,r);
		return val1+val2;
	}
	long long query_5(long index, long start, long end, long l, long r) {
		if(start > r || end < l)
			return 0;
		if(start >= l && end <= r)
			return tnodes[index].no5;
		long mid = (start+end)/2;
		long long val1 = query_5(2*index+1,start,mid,l,r);
		long long val2 = query_5(2*index+2,mid+1,end,l,r);
		return val1+val2;
	}
	void update_range_1(long index, long start, long end, long l, long r, int no2, int no5) {
		if(start > end || start > r || end < l)
			return;
		if(start == end){
			arr[start].no2 += no2;
			arr[start].no5 += no5;
			tnodes[index].no2 += no2;
			tnodes[index].no5 += no5;
		} else {
			long mid = (start+end)/2;
			update_range_1(2*index+1,start,mid,l,r,no2,no5);
			update_range_1(2*index+2,mid+1,end,l,r,no2,no5);
			tnodes[index].no2 = tnodes[2*index+1].no2 + tnodes[2*index+2].no2;
			tnodes[index].no5 = tnodes[2*index+1].no5 + tnodes[2*index+2].no5;
		}
	}
	void update_range_2(long index, long start, long end, long l, long r, long long y) {
		if(start > end || start > r || end < l)
			return;
		if(start == end){
			long long x = (start-l+1)*y;
			arr[start].no2 = get2(x);
			arr[start].no5 = get5(x);
			tnodes[index].no2 = get2(x);
			tnodes[index].no5 = get5(x);
		} else {
			long mid = (start+end)/2;
			update_range_2(2*index+1,start,mid,l,r,y);
			update_range_2(2*index+2,mid+1,end,l,r,y);
			tnodes[index].no2 = tnodes[2*index+1].no2 + tnodes[2*index+2].no2;
			tnodes[index].no5 = tnodes[2*index+1].no5 + tnodes[2*index+2].no5;
		}
	}
	
	void show_tnodes() {
		cout<<"tnodes"<<endl;
		for(long i=0;i<tnodes.size();i++)
			cout<<tnodes[i].no2<<" "<<tnodes[i].no5<<endl;
		cout<<endl;
	}
	void show_arr() {
		cout<<"arr"<<endl;
		for(long i=0;i<arr.size();i++)
			cout<<arr[i].no2<<" "<<arr[i].no5<<endl;
		cout<<endl;
	}
	
};
int main(){
	int t;
	cin>>t;
	while(t--) {
		long n,m;
		cin>>n>>m;
		segment_tree st(n);
		st.build_segment_tree(0,0,st.arr.size()-1);
		long long ans = 0;
		while(m--){
			int c;
			long l,r;
			cin>>c>>l>>r;
			//cout<<c<<" "<<l<<" "<<r<<endl;
			l--;
			r--;
			switch(c) {
				case 1:
				long long x;
				cin>>x;
				st.update_range_1(0,0,st.arr.size()-1,l,r,get2(x),get5(x));
				break;
				case 2:
				long long y;
				cin>>y;
				st.update_range_2(0,0,st.arr.size()-1,l,r,y);
				break;
				case 3:
				ans += min(st.query_2(0,0,st.arr.size()-1,l,r),st.query_5(0,0,st.arr.size()-1,l,r));
				//cout<<"ans = "<<ans<<endl;
				break;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}