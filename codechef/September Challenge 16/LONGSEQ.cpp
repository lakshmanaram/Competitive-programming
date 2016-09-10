#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--) {
		string d;
		cin>>d;
		int no = 0, nz  = 0;
		for(int i=0;i <d.size();i++){
			if(d[i] == '0')
				nz++;
			else no++;
		}
		if(no == 1 || nz== 1) 
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;

	}
	return 0;
}