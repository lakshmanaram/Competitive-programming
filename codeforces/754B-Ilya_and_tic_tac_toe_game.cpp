#include <bits/stdc++.h>
using namespace std;
int main() {
	vector<string> arr(4);
	bool flag = false;
	cin>>arr[0]>>arr[1]>>arr[2]>>arr[3];
	for(int i=0;i<4;i++) {
		for(int j=0;j<2;j++) {
			int empty=0, x=0;
			for(int k=0;k<3;k++){
				if(arr[i][j+k] == '.')
					empty++;
				else if(arr[i][j+k] == 'x')
					x++;
			}
			if(x==2 && empty == 1)
				flag = true;
		}
	}
	for(int i=0;i<2;i++) {
		for(int j=0;j<4;j++) {
			int empty=0, x=0;
			for(int k=0;k<3;k++){
				if(arr[i+k][j] == '.')
					empty++;
				else if(arr[i+k][j] == 'x')
					x++;
			}
			if(x==2 && empty == 1)
				flag = true;
		}
	}
	for(int i=0;i<2;i++) {
		for(int j=0;j<2;j++) {
			int empty=0, x=0;
			for(int k=0;k<3;k++){
				if(arr[i+k][j+k] == '.')
					empty++;
				else if(arr[i+k][j+k] == 'x')
					x++;
			}
			if(x==2 && empty == 1)
				flag = true;
		}
	}
	reverse(arr.begin(),arr.end());

	for(int i=0;i<2;i++) {
		for(int j=0;j<2;j++) {
			int empty=0, x=0;
			for(int k=0;k<3;k++){
				if(arr[i+k][j+k] == '.')
					empty++;
				else if(arr[i+k][j+k] == 'x')
					x++;
			}
			if(x==2 && empty == 1)
				flag = true;
		}
	}
	for(int i=0;i<4;i++)
		reverse(arr[i].begin(),arr[i].end());
	for(int i=0;i<2;i++) {
		for(int j=0;j<2;j++) {
			int empty=0, x=0;
			for(int k=0;k<3;k++){
				if(arr[i+k][j+k] == '.')
					empty++;
				else if(arr[i+k][j+k] == 'x')
					x++;
			}
			if(x==2 && empty == 1)
				flag = true;
		}
	}
	reverse(arr.begin(),arr.end());

	for(int i=0;i<2;i++) {
		for(int j=0;j<2;j++) {
			int empty=0, x=0;
			for(int k=0;k<3;k++){
				if(arr[i+k][j+k] == '.')
					empty++;
				else if(arr[i+k][j+k] == 'x')
					x++;
			}
			if(x==2 && empty == 1)
				flag = true;
		}
	}
	if(flag)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}