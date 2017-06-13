#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
vector<long> primes;
vector<vector<long> > factors;
vector<vector<pair<long,int> > > factorization;
bool arr[1000001];
void markMultiples(long a, long n)
{
    long i = 1, num;
    while ( (num = i*a) <= n ) {
        arr[num] = true;
        factors[num].pb(a);
        ++i;
    }
}
void SieveOfEratosthenes()
{
	factorization.resize(1000001);
	factors.resize(1000001);
    fill(arr,arr+1000001,false);
    for (long i=2; i<1000001; ++i)
        if ( arr[i] == false ){
        	primes.pb(i);
            markMultiples(i, 1000001);
        }
}

vector<pair<long, int> > get_factors(long num) {
	vector<pair<long, int> > ans;
	long temp = num;
	int count = 0;
	if(num <= 1 || factorization[num].size()!=0)
		return factorization[num];
	else {
		for(long i=0;i<factors[temp].size();i++) {
			while(num % factors[temp][i] == 0) {
				count++;
				num /= factors[temp][i];
			}
			ans.pb(mp(factors[temp][i],count));
		}
		factorization[temp] = ans;
	}
	return factorization[temp];
}

class node{
public:
	long val;
	vector<pair<long, int> > facs;
};
class segment_tree{
public:
	vector<node> tnodes;
	vector<node> arr;
	long l, r, x, y;
	segment_tree(long n){
		arr.resize(n);
		for(long i=0;i<n;i++)
			cin>>arr[i].val;
	}
	void build_segment_tree(long index, long start, long end) {
		if(start == end){
			// leaf node
			if(tnodes.size() <= index)
				tnodes.resize(index+1);
			tnodes[index].val = arr[start].val;
			tnodes[index].facs = get_factors(tnodes[index].val);
		} else {
			long mid = (start+end)/2;
			build_segment_tree(2*index+1,start,mid);
			build_segment_tree(2*index+2,mid+1,end);
			long a_so_far, b_so_far;
			a_so_far = b_so_far = 0; 
			vector<pair<long, int> >::iterator ait = tnodes[2*index+1].facs.begin(), bit = tnodes[2*index+2].facs.begin();
			while(ait != tnodes[2*index+1].facs.end() && bit != tnodes[2*index+2].facs.end()) {
				if(ait->first == bit->first){
					tnodes[index].facs.pb(mp(ait->first, ait->second + bit->second));
					b_so_far = bit->second;
					a_so_far = ait->second;
					ait++;
					bit++;
				} else if(ait->first < bit->first){
					tnodes[index].facs.pb(mp(ait->first,ait->second + b_so_far));
					a_so_far = ait->second;
					ait++;
				}
				else {
					tnodes[index].facs.pb(mp(bit->first,bit->second + a_so_far));
					b_so_far = bit->second;
					bit++;
				}
			}
			while(ait != tnodes[2*index+1].facs.end()) {
				tnodes[index].facs.pb(mp(ait->first,ait->second + b_so_far));
				ait++;
			}
			while(bit != tnodes[2*index+2].facs.end()) {
				tnodes[index].facs.pb(mp(bit->first,bit->second + a_so_far));
				bit++;
			}
		}
	}
	long query_range(long index, long start, long end) {
		if(start > r || end < l)
			return 0;
		if(start >= l && end <= r){
			long ans = 0;
			vector<pair<long, int> >::iterator temp = lower_bound(tnodes[index].facs.begin(), tnodes[index].facs.end(), mp((long)y+1,(int)0));
			vector<pair<long, int> >::iterator it = lower_bound(tnodes[index].facs.begin(), tnodes[index].facs.end(), mp((long)x,(int)0));
			long start,end;
			if(it == tnodes[index].facs.begin())
				start = 0;
			else {
				it--;
				start = it->second;
			}
			if(temp == tnodes[index].facs.begin())
				end = 0;
			else {
				temp--;
				end = temp->second;
			}
			return max((long)0,end-start);
		}
		long mid = (start+end)/2;
		long val1 = query_range(2*index+1,start,mid);
		long val2 = query_range(2*index+2,mid+1,end);
		return val1+val2;
	}
};

int main(){
	SieveOfEratosthenes();
	long n;
	cin>>n;
	segment_tree st(n);	
	st.build_segment_tree(0,0,st.arr.size()-1);
	long q;
	cin>>q;
	while(q--){
		long l,r,x,y;
		scanf("%ld %ld %ld %ld",&l,&r,&x,&y);
		st.l = l-1;
		st.r = r-1;
		st.x = x;
		st.y = y;
		printf("%ld\n",st.query_range(0,0,st.arr.size()-1));
	}
	
	return 0;
}	