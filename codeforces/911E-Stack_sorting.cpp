#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
#define S(n) scanf("%lld", &n)
using namespace std;
int main(){
	ll n, k;
	S(n);
	S(k);
	vll arr(n);
	for(long i=0;i<k;i++){
		S(arr[i]);
	}
	// initially check so far
	bool flag = true;
	stack<ll> expected;
	expected.push(n);
	vll b;
	stack<ll> st;
	for(long i=0;i<k;i++){
		st.push(arr[i]);
		// cout<<"top = "<<st.top()<<" expected top = "<<expected.top()<<endl;
		if(st.size()!=0 && st.top() == expected.top()){
			ll temp = expected.top();
			expected.pop();
			expected.push(temp-1);
			while(expected.size()!=0 && expected.top() < b.size()+1){
				expected.pop();
			}
		} else if(st.size()!=0 && st.top() == b.size()+1){
			while(st.size()!=0 && st.top() == b.size()+1){
				b.pb(st.top());
				st.pop();
			}
		} else if(st.top() < expected.top()){
			expected.push(st.top()-1);
		} else {
			// cout<<i<<" debug"<<endl;
			flag = false;
			break;
		}
		while(st.size()!=0 && st.top() == b.size()+1){
			b.pb(st.top());
			st.pop();
		}
		while(expected.size()!=0 && expected.top() < b.size()+1){
			expected.pop();
		}
	}
	if(!flag) cout<<-1<<endl;
	else {
		long i = k;
		while(expected.size() != 0){
			while(expected.top() >= b.size()+1){
				arr[i++] = expected.top();
				st.push(expected.top());
				ll temp = expected.top();
				expected.pop();
				expected.push(temp-1);
			}
			expected.pop();
			while(st.size()!=0 && st.top() == b.size()+1){
				b.pb(st.top());
				st.pop();
			}
		}
		for(long i=0;i<n;i++){
			printf("%lld ", arr[i]);
		}
	}
	return 0;
}
