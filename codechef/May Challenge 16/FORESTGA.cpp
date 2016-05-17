#include<bits/stdc++.h>
using namespace std;
long n;
long long w,l;
vector<long long> h,r;
bool check_feasible(long long x ){
	long long ans = 0;
	for(long i=0;i<h.size();i++){
		long long temp = r[i]*x+h[i];
		if(temp >= l)
			ans += temp;
		if(ans >= w)
			return true;
	}
	return false;
}
int main()
{
	cin>>n>>w>>l;
	vector<long long> th(n);
	vector<long long> tr(n);
	long long maxrate;
	for(long i=0;i<n;i++){
		cin>>th[i]>>tr[i];
		if(i==0 || maxrate < tr[i])
			maxrate = tr[i];
	}
	h = th;
	r = tr;
	long long left = l/maxrate;
	long long right = w/maxrate + 1,mid;
	while(left<right){
		mid = left+(right-left)/2;
		if(check_feasible(mid))
			right = mid;
		else
			left = mid+1;
	}
	left++;
	bool flag = true;
	while(true){
		if(check_feasible(left)){
			left--;
			flag = false;
		}
		else{
			if(flag){
				while(true){
					left++;
					if(check_feasible(left)){
						if(left>=0)
							cout<<left;
						else
							cout<<0;
						break;
					}
				}
				break;
			}
			if(left+1 >=0)
				cout<<left+1;
			else
				cout<<0;
			break;
		}
	}
	return 0;
}  
