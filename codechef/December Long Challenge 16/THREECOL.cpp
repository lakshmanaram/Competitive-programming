#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > ans;
void fix2(int a, int b) {
	vector<int> temp;
	temp.push_back(a);
	temp.push_back(b);
	temp.push_back(a+1);
	temp.push_back(b);
	ans.push_back(temp);
	temp.clear();
	temp.push_back(a);
	temp.push_back(b+1);
	temp.push_back(a+1);
	temp.push_back(b+1);
	ans.push_back(temp);
	temp.clear();
	temp.push_back(a);
	temp.push_back(b);
	temp.push_back(a);
	temp.push_back(b+1);
	ans.push_back(temp);
	temp.clear();
	temp.push_back(a+1);
	temp.push_back(b);
	temp.push_back(a+1);
	temp.push_back(b+1);
	ans.push_back(temp);
}
void fix4(int a, int b) {
	fix2(a,b);
	fix2(a+2,b);
	fix2(a,b+2);
	fix2(a+2,b+2);
	fix2(a+1,b+1);
	fix2(a,b);
	fix2(a+2,b);
	fix2(a,b+2);
	fix2(a+2,b+2);
}
void fix8(int a, int b) {
	fix4(a,b);
	fix4(a+4,b);
	fix4(a,b+4);
	fix4(a+4,b+4);
	fix2(a+3,b+3);
	fix4(a,b);
	fix4(a+4,b);
	fix4(a,b+4);
	fix4(a+4,b+4);
}
void fix16(int a, int b) {
	fix8(a,b);
	fix8(a+8,b);
	fix8(a,b+8);
	fix8(a+8,b+8);
	fix2(a+7,b+7);
	fix8(a,b);
	fix8(a+8,b);
	fix8(a,b+8);
	fix8(a+8,b+8);
}
void fix5(int a, int b) {
	fix4(a+1,b+1);
	fix4(a+1,b);
	fix4(a,b+1);
	fix4(a+1,b+1);
	fix2(a,b);
	fix4(a+1,b+1);
	fix4(a+1,b);
	fix4(a,b+1);
}
void fix11(int a, int b) {
	fix8(a+3,b+3);
	fix8(a+3,b);
	fix8(a,b+3);
	fix8(a+3,b+3);
	fix4(a,b);
	fix8(a+3,b+3);
	fix8(a+3,b);
	fix8(a,b+3);
}
void fix13(int a, int b) {
	fix11(a+2,b+2);
	fix11(a+2,b);
	fix11(a,b+2);
	fix11(a+2,b+2);
	fix4(a,b);
	fix11(a+2,b+2);
	fix11(a+2,b);
	fix11(a,b+2);
}
void fix20(int a, int b) {
	fix16(a+4,b+4);
	fix16(a+4,b);
	fix16(a,b+4);
	fix16(a+4,b+4);
	fix8(a,b);
	fix16(a+4,b+4);
	fix16(a+4,b);
	fix16(a,b+4);
}

int main(){
	int n;
	cin>>n;
	if(n == 2)
		fix2(1,1);
	else if(n == 4)
		fix4(1,1);
	else if(n == 8)
		fix8(1,1);
	else if(n == 16)
		fix16(1,1);
	else if(n==5)
		fix5(1,1);
	else if(n==20)
		fix20(1,1);
	else if(n == 11)
		fix11(1,1);
	else if(n == 13)
		fix13(1,1);
	cout<<ans.size()<<endl;
	for(long i=0;i<ans.size();i++) {
		cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<" "<<ans[i][3]<<endl;
	}
	return 0;
}