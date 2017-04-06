#include <bits/stdc++.h>
#define vvb vector<vector<bool> >
using namespace std;
vector<long> grundy;
vvb get_matrix(long x) {
	vector<bool> temp(4,false);
	vvb ans(4,temp);
	for( int i=3; i >= 0 ;i--)
		for(int j=3;j >= 0; j--){
			ans[i][j] = x&1;
			x >>= 1;
		}
	return ans;
}
long get_no(vvb x) {
	long ans = 0;
	for( int i=0; i <= 3 ;i++)
		for(int j=0;j <= 3; j++){
			ans <<= 1;
			if(x[i][j]) ans++;
		}
	return ans;
}
long get_grundy(vvb mat) {
	vvb temp = mat;
	set<long> arr;
	for(int i=0;i<4;i++) {
		for(int j=0;j<4;j++) {
			int maxj = 4;
			for(int i1=i;i1<4;i1++) {
				if(!mat[i1][j])
					break;
				for(int j1 = j; j1 < maxj; j1++) {
					if(!mat[i1][j1]) {
						maxj = j1;
						break;
					}
					temp = mat;
					for(int k1 = i; k1 <= i1; k1++) {
						for( int k2 = j; k2 <= j1; k2++) {
							temp[k1][k2] = false;
						}
					}
					long x = get_no(temp);
					if(grundy[x] == -1) 
						grundy[x] = get_grundy(temp);
					arr.insert(grundy[x]);
				}
			}
		}
	}
	set<long>::iterator it;
	long ans = 0;
	for(it = arr.begin(); it != arr.end(); it++) {
		if(ans == *it)
			ans++;
		else return ans;
	}
	return ans;
}
class segment_tree{
public:
	vector<long> tnodes;
	vector<long> arr;
	segment_tree(long n){
		arr.resize(n);
		for(long k=0;k<n;k++){
			char* x = new char(5);
			vector<bool> temp(4,false);
			vvb ans(4,temp);
			for(int i=0;i<4;i++){
				scanf("%s",x);
				for(int j=3;j>=0;j--) {
					if(x[j] == '1')
						ans[i][j] = true;
				}
			}
			arr[k] = grundy[get_no(ans)];
		}
		build_segment_tree(0,0,arr.size()-1);
	}
	void build_segment_tree(long index, long start, long end) {
		if(start == end){
			// leaf node
			if(tnodes.size() <= index)
				tnodes.resize(index+1);
			tnodes[index] = arr[start];
		} else {
			long mid = (start+end)/2;
			build_segment_tree(2*index+1,start,mid);
			build_segment_tree(2*index+2,mid+1,end);
			tnodes[index] = tnodes[2*index+1] ^ tnodes[2*index+2];
		}
	}
	long long query_range(long index, long start, long end, long l, long r) {
		if(start > r || end < l)
			return 0;
		if(start >= l && end <= r)
			return tnodes[index];
		long mid = (start+end)/2;
		long long val1 = query_range(2*index+1,start,mid,l,r);
		long long val2 = query_range(2*index+2,mid+1,end,l,r);
		return val1^val2;
	}
	void update(long index, long start, long end, long updatepos, long long val) {
		// add val to updatepos indexed element
		if(start == end){
			arr[updatepos] = val;
			tnodes[index] = val;
		} else {
			long mid = (start+end)/2;
			if(start <= updatepos && mid >= updatepos)
				update(2*index+1,start,mid,updatepos,val);
			else
				update(2*index+2,mid+1,end,updatepos,val);
			tnodes[index] = tnodes[2*index+1] ^ tnodes[2*index+2];
		}
	}
};
int main() {
	long long size = 1;
	size <<= 16;
	grundy.resize(size,-1);
	grundy[0] = 0;
	long q = 1;
	while(q<size){
		grundy[q] = 1;
		q <<= 1;
	}
	for(long i=3;i<size;i++){
		if(grundy[i] == -1) { 
			grundy[i] = get_grundy(get_matrix(i));
		}
	}
	// cout<<"Not coming outside"<<endl;
	int t;
	cin>>t;
	while(t--) {
		long n,m;
		scanf("%ld %ld",&n,&m);
		segment_tree st(n);	
		while(m--) {
			int ch;
			long l,r;
			scanf("%d",&ch);
			if(ch == 1) {
				scanf("%ld %ld",&l,&r);
				if(st.query_range(0,0,st.arr.size()-1,l-1,r-1))
					printf("Pishty\n");
				else printf("Lotsy\n");
			} else {
				scanf("%ld",&l);
				char* x = new char(5);
				vector<bool> temp(4,false);
				vvb ans(4,temp);
				for(int i=0;i<4;i++){
					scanf("%s",x);
					for(int j=3;j>=0;j--) {
						if(x[j] == '1')
							ans[i][j] = true;
					}
				}
				long k = grundy[get_no(ans)];
				if(st.arr[l-1] != k)
					st.update(0,0,st.arr.size()-1,l-1,k);
			}
		}
	}
	return 0;
}