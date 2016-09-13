#include <bits/stdc++.h>
using namespace std;
string to_string( int a ) {
    stringstream ss;
	ss << a;
	return ss.str();
}
int main(){
	long long n;
	cin>>n;
	long long x1,y1,x2,y2;
	x1=y1=1;
	x2=y2=n;
	map<string,long> ans;
	long long mid;
	// Get right top first
	long long nx1,ny1,nx2,ny2;
	mid = (x1+x2+1)/2;
	int vals;
	while(true){
		if(mid == x2)
			break;
		string s = "? "+to_string(x1)+" "+to_string(y1)+" "+to_string(mid)+" "+to_string(y2);
		if(ans.find(s)!=ans.end()){
			vals = ans[s];
		} else {
		cout<<s<<endl;

		fflush(stdout);
		scanf("%d",&vals);
		ans[s] = vals;
	}
		if(vals == 2){
			x2 = mid;
			mid = (x1 + x2+1)/2;
		// } else if(vals == 0){
		// 	x1 = mid;
		// 	mid = (x1 + x2+1)/2;
		} else {
			mid = (mid + x2+1)/2;
		}
	}
	mid = (y1+y2+1)/2;
	while(true){
		if(mid == y2)
			break;
		string s = "? "+to_string(x1)+" "+to_string(y1)+" "+to_string(x2)+" "+to_string(mid);
		if(ans.find(s)!=ans.end()){
			vals = ans[s];
		} else {
		cout<<s<<endl;

		fflush(stdout);
		scanf("%d",&vals);
		ans[s] = vals;
	}
		if(vals == 2){
			y2 = mid;
			mid = (y1 + y2+1)/2;
		// } else if(vals == 0){
		// 	y1 = mid;
		// 	mid = (y1 + y2+1)/2;
		} 
		else {
			mid = (mid + y2+1)/2;
		}
	}
	mid = (x1+x2)/2;
	while(true){
		if(mid == x1)
			break;
		string s = "? "+to_string(mid)+" "+to_string(y1)+" "+to_string(x2)+" "+to_string(y2);
		if(ans.find(s)!=ans.end()){
			vals = ans[s];
		} else {
		cout<<s<<endl;

		fflush(stdout);
		scanf("%d",&vals);
		ans[s] = vals;
	}
		if(vals == 2){
			x1 = mid;
			mid = (x1 + x2)/2;
		} else {
			mid = (mid + x1)/2;
		}
	}
	mid = (y1+y2)/2;
	while(true){
		if(mid == y1)
			break;
		string s = "? "+to_string(x1)+" "+to_string(mid)+" "+to_string(x2)+" "+to_string(y2);
		if(ans.find(s)!=ans.end()){
			vals = ans[s];
		} else {
		cout<<s<<endl;

		fflush(stdout);
		scanf("%d",&vals);
		ans[s] = vals;
	}
		if(vals == 2){
			y1 = mid;
			mid = (y1 + y2)/2;
		} else {
			mid = (mid + y1)/2;
		}
	}
	// cout<<"recatngles "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
	nx1 = x2;
	ny1 = y2;
	mid = (x1+nx1)/2;
	while(true){
		// cout<<"mid values is "<<mid<<" and x1 is "<<x1<<" and nx1 is "<<nx1<<endl;
		if(mid == nx1)
			break;
		string s = "? "+to_string(x1)+" "+to_string(y1)+" "+to_string(mid)+" "+to_string(ny1);
		if(ans.find(s)!=ans.end()){
			vals = ans[s];
		} else {
		cout<<s<<endl;

		fflush(stdout);
		scanf("%d",&vals);
		ans[s] = vals;
	}
		if(vals >= 1){
			nx1 = mid;
			mid = (x1 + nx1)/2;
		} else {
			mid = (mid + nx1)/2;
		}
	}
	// cout<<"right of rectangle 1 is "<<nx1<<endl;
	mid = (y1+ny1)/2;
	while(true){
		if(mid == ny1)
			break;
		string s = "? "+to_string(x1)+" "+to_string(y1)+" "+to_string(nx1)+" "+to_string(mid);
		if(ans.find(s)!=ans.end()){
			vals = ans[s];
		} else {
		cout<<s<<endl;

		fflush(stdout);
		scanf("%d",&vals);
		ans[s] = vals;
	}
		if(vals == 1){
			ny1 = mid;
			mid = (y1 + ny1)/2;
		} else {
			mid = (mid + ny1)/2;
		}
	}
	// cout<<"top of rectangle 1 is "<<ny1<<endl;
	nx2 = x1;
	ny2 = y1;
	mid = (nx2+x2+1)/2;
	while(true){
		// cout<<"mid values is "<<mid<<" and nx2 is "<<nx2<<" and x2 is "<<x2<<endl;
		if(mid == nx2)
			break;
		string s = "? "+to_string(mid)+" "+to_string(ny2)+" "+to_string(x2)+" "+to_string(y2);
		if(ans.find(s)!=ans.end()){
			vals = ans[s];
		} else {
		cout<<s<<endl;

		fflush(stdout);
		scanf("%d",&vals);
		ans[s] = vals;
	}
		if(vals == 1){
			nx2 = mid;
			mid = (nx2 + x2+1)/2;
		} else {
			mid = (mid + nx2)/2;
		}
	}
	// cout<<"left of rectangle 1 is "<<nx2<<endl;
	mid = (ny2+y2+1)/2;
	while(true){
		// cout<<"mid values is "<<mid<<" and ny2 is "<<ny2<<" and y2 is "<<y2<<endl;
		if(mid == ny2)
			break;
		string s = "? "+to_string(nx2)+" "+to_string(mid)+" "+to_string(x2)+" "+to_string(y2);
		if(ans.find(s)!=ans.end()){
			vals = ans[s];
		} else {
		cout<<s<<endl;

		fflush(stdout);
		scanf("%d",&vals);
		ans[s] = vals;
	}
		if(vals == 1){
			ny2 = mid;
			mid = (ny2 + y2+1)/2;
		} else {
			mid = (mid + ny2)/2;
		}
	}
	
	cout<<"! "<<x1<<" "<<y1<<" "<<nx1<<" "<<ny1<<" "<<nx2<<" "<<ny2<<" "<<x2<<" "<<y2<<endl;
	fflush(stdout);
	return 0;
}