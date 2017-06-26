#include <bits/stdc++.h>
#define x first
#define long long long
#define y second
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		long n;
		cin>>n;
		vector<pair<long, long> > points;
		for(long i=0;i<n;i++) {
			long x,y;
			scanf("%lld %lld",&x,&y);
			points.push_back(make_pair(x,y));
		}
		stack<long> st;
		long cur;
		vector<long> ans(n);
		for(long i=0;i<n;i++) {
			cur = -2;
			while(st.size() !=0 && points[i].second > points[st.top()].second){
				ans[st.top()] = cur+1;
				cur = st.top();
				st.pop();
			}
			while(st.size() > 1) {
				long p = st.top();
				st.pop();
				long pp = st.top();
				if((points[pp].y-points[i].y)*(points[p].x - points[i].x) > (points[p].y - points[i].y)*(points[pp].x-points[i].x)) {
					st.push(p);
					break;
				} else {
					ans[p] = i+1;
				}
			}

			st.push(i);
		}
		cur = -2;
		while(st.size() !=0){
			ans[st.top()] = cur+1;
			cur = st.top();
			st.pop();
		}
		for(long i=0;i<n;i++)
			printf("%lld ",ans[i]);
		cout<<endl;
	}
	return 0;
}