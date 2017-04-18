#include <bits/stdc++.h>
using namespace std;
class problem{
public:
	vector<long long > arr;
	vector<long long  > quer;
	vector<long long > answer;
	problem(long long  n, long long  m){
		arr.resize(n);
		quer.resize(m);
		answer.resize(m);
		vector<pair<long long ,long long > > elements;
		for(long long  i=0;i<n;i++){
			scanf("%lld",&arr[i]);
			elements.push_back(make_pair(arr[i],i));
		}
		for(long long  i=0;i<m;i++)
			scanf("%lld",&quer[i]);
		sort(elements.begin(),elements.end());
		reverse(elements.begin(),elements.end());
		set<long long > indices;
		set<long long >::iterator it;
		pair<long long ,long long > ans_pair;
		set<pair<long long  , long long > > ans;
		long long  siz, top = n, bot = 0,cur;
		for(long long  i=0;i<elements.size();i++) {
			if(i == 0) {
				indices.insert(elements[i].second);
				cur = elements[i].second;
				siz = top-bot;
				ans_pair.first = siz*(siz+1)/2;
				siz = cur-bot;
				ans_pair.first -= siz*(siz+1)/2;
				cur++;
				siz = top-cur;
				ans_pair.first -= siz*(siz+1)/2;
				ans_pair.second = elements[i].first;
				// cout<<ans_pair.first<<endl;
			} else {
				if(elements[i].first != ans_pair.second) {
					ans.insert(ans_pair);
				}
				it = indices.lower_bound(elements[i].second);
				cur = elements[i].second;
				if(it == indices.begin()){
					bot = 0;
					top = *it;
				} else if (it == indices.end()){
					top = n;
					it--;
					bot = (*it)+1;
				} else {
					top = *it;
					it--;
					bot = (*it)+1;
				}
				siz = top-bot;
				ans_pair.first += siz*(siz+1)/2;
				siz = cur-bot;
				ans_pair.first -= siz*(siz+1)/2;
				cur++;
				siz = top-cur;
				ans_pair.first -= siz*(siz+1)/2;
				ans_pair.second = elements[i].first;
				indices.insert(elements[i].second);
			}
		}
		ans.insert(ans_pair);
		for(long long  i=0;i<quer.size();i++) {
			// cout<<"quer "<<quer[i]<<endl;
			answer[i] = ans.lower_bound(make_pair(quer[i],0))->second;
		}
		for(long long  i=0;i<answer.size();i++)
			printf("%lld\n",answer[i]);
	}
};
int main(){
	
	int t;
	cin>>t;
	while(t--){
		long long  n,m;
		cin>>n>>m;
		problem st(n,m);	
	}
	
	return 0;
}