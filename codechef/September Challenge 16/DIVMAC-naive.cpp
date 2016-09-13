// segment tree for sum of subarray lazy propogation
#include <bits/stdc++.h>
using namespace std;
int primes[1000001];
void SieveOfEratosthenes(int n) {
    for(int i=1;i<n;i++)
    	primes[i] = i;
    for (int i=2; i*i<=n; ++i)
        if ( primes[i] == i ){
        	for (int j=i*2; j<=n; j += i)
                if(primes[j]==j)
                	primes[j]=i;
        }
}
int tnodes[300001];
int arr[100001];
void build_segment_tree(int index, int start, int end) {
	if(start == end){
		tnodes[index] = primes[arr[start]];
	} else {
		int mid = (start+end)/2;
		build_segment_tree(2*index,start,mid);
		build_segment_tree(2*index+1,mid+1,end);
		tnodes[index] = max(tnodes[2*index],tnodes[2*index+1]);
	}
}	
void get_segment_tree(int n){
	for(int i=0;i<n;i++)
		cin>>arr[i];
	build_segment_tree(1,0,n-1);
}
int query_range(int index, int start, int end, int l, int r){//, int curmax) {
	if(start > r || end < l || start > end || tnodes[index] == 1)// || tnodes[index] <= curmax)
		return 1;
	if(start >= l && end <= r)
		return tnodes[index];
	int mid = (start+end)/2;
	int val1 = query_range(2*index,start,mid,l,r);//,curmax);
	int val2 = query_range(2*index+1,mid+1,end,l,r);//,curmax);
	return max(val1,val2);
}
void update_range(int index, int start, int end, int l, int r){
	if(start > end || start > r || end < l || tnodes[index] == 1)
		return;
	if(start == end){
		arr[start] /= primes[arr[start]];
		tnodes[index] = primes[arr[start]];
		return;
	} else {
		int mid = (start+end)/2;
		update_range(2*index, start, mid, l, r);
		update_range(2*index+1, mid+1, end, l, r);
		tnodes[index] = max(tnodes[2*index],tnodes[2*index+1]);
	}
}
int main(){
	int t;
	cin>>t;
    SieveOfEratosthenes(1000001);
	while(t--) {
		int n,m;
		scanf("%d %d",&n,&m);
		get_segment_tree(n);
		while(m--){
			int choice, l,r;
			scanf("%d %d %d",&choice,&l,&r);
			if(choice == 0){
				update_range(1,0,n-1,l-1,r-1);
			}
			else{
				printf("%d ",query_range(1,0,n-1,l-1,r-1));
			}
		}
		cout<<endl;
	}
	return 0;
}