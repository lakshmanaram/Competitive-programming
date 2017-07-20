#include <bits/stdc++.h>
using namespace std;
int main(){
	long x,y;
	cin>>x>>y;
	vector<string> arr(x);
	for(long i=0;i<x;i++){
		cin>>arr[i];
	}
	long black = 0;
	long top = -1;
	long bottom = -1, left = -1, right = -1;
	for(long i=0;i<x;i++){
		for(long j=0;j<y;j++){
			if(arr[i][j] == 'B'){
				black++;
				if(top == -1 || top > i) top = i;
				if(bottom == -1 || bottom < i) bottom = i;
				if(left == -1 || left > j) left = j;
				if(right == -1 || right < j) right = j;
			}
		}
	}
	long side = max(abs(left-right)+1,abs(top-bottom)+1);
	long area = side*side;
	if(area > x*y || side > x || side > y)
		cout<<-1<<endl;
	else cout<<area-black<<endl;
	return 0;
}