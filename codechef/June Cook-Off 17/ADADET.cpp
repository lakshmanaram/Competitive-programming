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
			queue<long> temp;
			while(st.size() !=0 && points[i].second > points[st.top()].second){
				// ans[st.top()] = cur+1;
				// cur = st.top();
				temp.push(st.top());
				st.pop();
			}
			if(temp.size() > 0) {
				stack<long> convex_hull;

				while(temp.size() != 0) {
					if(convex_hull.size() == 0) {
						convex_hull.push(temp.front());
					} else {
						while(convex_hull.size() > 1){ 
							long p = convex_hull.top();
							convex_hull.pop();
							long pp = convex_hull.top();
							if((points[pp].y-points[temp.front()].y)*(points[p].x - points[temp.front()].x) < (points[p].y - points[temp.front()].y)*(points[pp].x-points[temp.front()].x)) {
								convex_hull.push(p);
								break;
							} else {
								ans[p] = pp+1;
							}
						}
						convex_hull.push(temp.front());
					}
					temp.pop();
				}

				while(convex_hull.size() > 1){
					long p = convex_hull.top();
					convex_hull.pop();
					ans[p] = convex_hull.top()+1;
				}
				ans[convex_hull.top()] = -1;
			}
			st.push(i);
		}
		queue<long> temp;
		while(st.size() !=0){
			// ans[st.top()] = cur+1;
			// cur = st.top();
			temp.push(st.top());
			st.pop();
		}

		if(temp.size() > 0) {
			stack<long> convex_hull;

			while(temp.size() != 0) {
				if(convex_hull.size() == 0) {
					convex_hull.push(temp.front());
				} else {
					while(convex_hull.size() > 1){ 
						long p = convex_hull.top();
						convex_hull.pop();
						long pp = convex_hull.top();
						if((points[pp].y-points[temp.front()].y)*(points[p].x - points[temp.front()].x) < (points[p].y - points[temp.front()].y)*(points[pp].x-points[temp.front()].x)) {
							convex_hull.push(p);
							break;
						} else {
							ans[p] = pp+1;
						}
					}
					convex_hull.push(temp.front());
				}
				temp.pop();
			}
			while(convex_hull.size() > 1){
				long p = convex_hull.top();
				convex_hull.pop();
				ans[p] = convex_hull.top()+1;
			}
			ans[convex_hull.top()] = -1;
		}
		for(long i=0;i<n;i++)
			printf("%lld ",ans[i]);
		cout<<endl;
	}
	return 0;
}