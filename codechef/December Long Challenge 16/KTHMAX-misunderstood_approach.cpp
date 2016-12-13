// segment tree for sum of subarray
#include <bits/stdc++.h>
using namespace std;
class segment_tree{
public:
	vector<long> tnodes;
	vector<long> arr;
	vector<long long> quer;
	vector<long> ans;
	long overall_max;
	set<pair<long long,vector<long> > > hashedarr;
	set<pair<long long,vector<long> > >::iterator sit, psit;
	segment_tree(long n, long m){
		arr.resize(n);
		quer.resize(m);
		ans.resize(m);
		vector<pair<long,long> > elements;
		for(long i=0;i<n;i++){
			scanf("%ld",&arr[i]);
			elements.push_back(make_pair(arr[i],i));
		}
		for(long i=0;i<m;i++)
			scanf("%lld",&quer[i]);
		pair<long long,vector<long> > prev;
		sort(elements.begin(),elements.end());
		reverse(elements.begin(),elements.end());
		overall_max = elements[0].first;
		for(long i=0;i<n;i++){
			if(i==0) {
				prev.first = n - elements[i].second;
				prev.second.push_back(elements[i].second);
			} else if(arr[prev.second[0]] == elements[i].first) {
					prev.first += n-elements[i].second;
					prev.second.push_back(elements[i].second);
			} else {
				hashedarr.insert(prev);
				prev.first += n-elements[i].second;
				prev.second.clear();
				prev.second.push_back(elements[i].second);
			}
		}
		hashedarr.insert(prev);
	}
	void build_segment_tree(long index, long start, long end) {
		if(start == end){
			if(tnodes.size() <= index)
				tnodes.resize(index+1);
			tnodes[index] = arr[start];
		} else {
			long mid = (start+end)/2;
			build_segment_tree(2*index+1,start,mid);
			build_segment_tree(2*index+2,mid+1,end);
			tnodes[index] = max(tnodes[2*index+1],tnodes[2*index+2]);
		}
	}
	long query_range(long index, long start, long end, long l, long r) {
		if(start > r || end < l)
			return 0;
		if(l <= start && end <= r)
			return tnodes[index];
		long mid = (start+end)/2;
		long val1 = query_range(2*index+1,start,mid,l,r);
		long val2 = query_range(2*index+2,mid+1,end,l,r);
		return max(val1,val2);
	}
	long ans_util(long max_till, vector<pair<long,long> > elements, long long p) {
		if(max_till == overall_max)
			return max_till;
		if(elements.size()==1)
			return max(max_till,query_range(0,0,arr.size()-1,elements[0].second,arr.size()-p));
		else {
			sort(elements.begin(),elements.end());
			reverse(elements.begin(),elements.end());
			pair<long long,vector<long> > cur,prev;
			prev.first = 0;
			long value;
			for(long i=0;i<elements.size();i++){
				if(i==0) {
					cur.first = arr.size() - elements[i].second;
					cur.second.push_back(elements[i].second);
					value = elements[i].first;
				}
				else {
					if(value == elements[i].first) {
						cur.first += arr.size()-elements[i].second;
						cur.second.push_back(elements[i].second);
					} else {
						if(p <= cur.first) {
							break;
						} else {
							prev = cur;
							cur.first += arr.size()-elements[i].second;
							cur.second.clear();
							cur.second.push_back(elements[i].second);
							value = elements[i].first;
						}
					}
				}
			}
			long long total;
			if(prev.first == 0){
				total = cur.first - cur.second.size();
			} else {
				total = cur.first - prev.first - cur.second.size();
				p -= prev.first;
			}
			if(p > total)
				return max(max_till,value);
			elements.clear();
			for(long j = 0;j <cur.second.size();j++){
				if(cur.second[j]+1 != arr.size())
					elements.push_back(make_pair(arr[cur.second[j]+1],cur.second[j]+1));
			}
			return ans_util(max(value,max_till), elements, p);
		}
	}
	long get_ans() {
		for(long i=0;i<quer.size();i++){
			// cout<<endl<<endl<<quer[i]<<" query starts"<<endl;
			vector<long> temp;
			long long total;
			long long p;
			// cout<<"quer[i] = "<<quer[i]<<endl;
			sit = hashedarr.lower_bound(make_pair(quer[i],temp));
			if(sit == hashedarr.begin()){
				// cout<<"cumulative = "<<(*sit).first<<endl;
				ans[i] =  overall_max;
			} else {
				psit = sit;
				psit--;
				total = sit->first - psit -> first - sit->second.size();
				p = quer[i] - psit -> first;
				// cout<<"p = "<<p<<" total = "<<total<<endl;
				// cout<<"(*sit).first = "<<(*sit).first<<" (*sit).second[0] = "<<(*sit).second[0]<<endl;
				if(p > total)
					ans[i] =  arr[(*sit).second[0]];
				else {
					vector<pair<long,long> > elements;
					for(long j = 0;j <(*sit).second.size();j++){
						if((*sit).second[j]+1 != arr.size())
							elements.push_back(make_pair(arr[(*sit).second[j]+1],(*sit).second[j]+1));
					}
					ans[i] =  ans_util(arr[(*sit).second[0]], elements, p);
				}
			}
		}
	}
	void print_ans() {
		for(long i=0;i<ans.size();i++)
			printf("%ld\n",ans[i]);
	}
};
int main(){
	
	int t;
	cin>>t;
	while(t--){
		long n,m;
		cin>>n>>m;
		segment_tree st(n,m);	
		st.build_segment_tree(0,0,st.arr.size()-1);
		st.get_ans();
		st.print_ans();
	}
	
	return 0;
}