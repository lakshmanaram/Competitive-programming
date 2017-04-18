#include <bits/stdc++.h>
using namespace std;
vector<int> gl;
vector<bool> glbool;
bool utilfunc(vector<int> arr, vector<bool> lbool, int arrpos, int glpos){
	// cout<<"util func "<<arrpos<<" <- arrpos "<<glpos<<endl;
	if(arrpos == arr.size()){
		glbool = lbool;
		return true;
	}
	int searching = arr[arrpos];
	for(long long i = gl.size()-1;i>glpos;i--){
		if(gl[i] == searching && !lbool[i]){
			lbool[i] = true;
			if(utilfunc(arr,lbool,arrpos+1,i))
				return true;
			lbool[i] = false;
		}
	}
	return false;
}
int main(){
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		vector<int> temp;
		long long total = 0;
		vector<vector<int> > arr(n,temp);
		for(int i=0;i<n;i++){
			long long ai;
			cin>>ai;
			total += ai;
			for(long long j=0; j<ai;j++) {
				int x;
				cin>>x;
				arr[i].push_back(x);
			}
		}
		vector<int> l(total);
		for(long long i=0;i<total;i++) {
			cin>>l[i];
		}
		if(n==1){
			reverse(arr[0].begin(),arr[0].end());
			if(l == arr[0])
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		} else {
			vector<bool> lbool(total,false);
			gl = l;
			glbool = lbool;
			bool answer = true;
			for(int i=0;i<n;i++) {
				vector<int> arri = arr[i];
				reverse(arri.begin(), arri.end());
				if(!utilfunc(arri,lbool,0,-1)){
					cout<<"No"<<endl;
					answer = false;
					break;
				}
			}
			if(answer)
				cout<<"Yes"<<endl;
		}
	}
	return 0;
}