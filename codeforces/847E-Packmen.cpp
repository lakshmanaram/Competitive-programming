#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
string q;
vector<long> as, p;
vector<long> leftv, rightv;
bool check(long n) {
	long j=0;
	leftv = p;
	rightv = p;
	for(long i=0;i<as.size();i++){
		if(as[i] < p[j]){
			if(leftv[j] > as[i])
				leftv[j] = as[i];
			if(p[j]-leftv[j] > n) return false;
		} else {
			if( j < p.size()-1 && as[i] > p[j+1]){
				j++;
				i--;
				continue;
			}
			long cand = as[i];
			long r = cand - p[j];
			long l = p[j]-leftv[j];
			if(min(2*l + r, 2*r+l) <= n){
				rightv[j] = as[i];
				// cout<<"P at "<<p[j]<<" update r to "<<rightv[j]<<endl;
			} else {
				j++;
				if(j == p.size()) return false;
				leftv[j] = as[i];
				if(p[j]-leftv[j] > n) return false;
			}
		}
	}
	for(long i=0;i<p.size();i++){
		// cout<<"inside "<<leftv[i]<<" "<<p[i]<<" "<<rightv[i]<<endl;
		long r = rightv[i] - p[i];
		long l = p[i]-leftv[i];
		if(min(2*l + r, 2*r+l) > n){
			return false;
		}
	}
	return true;
}
int main(){
	long n;
	cin>>n;
	cin>>q;
	for(long i=0;i<q.size();i++){
		if(q[i] == '*') as.pb(i);
		if(q[i] == 'P') p.pb(i);
	}
	// cout<<"As ";
	// for(long i=0;i<as.size();i++) cout<<as[i]<<" ";
	// cout<<endl;
	// cout<<"P ";
	// for(long i=0;i<p.size();i++) cout<<p[i]<<" ";
	// cout<<endl;
	long mi = 0;
	long ma = q.size()*2;
	long mid = (mi+ma)/2;
	while(mid != mi){
		// cout<<mid<<" m = "<<mi<<" max = "<<ma<<endl;
		if(check(mid))
			ma = mid;
		else
			mi = mid;
		mid = (mi+ma)/2;
	}
	if(check(mi))
		cout<<mi;
	else
		cout<<ma;
	return 0;
}