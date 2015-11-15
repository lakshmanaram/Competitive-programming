#include<bits/stdc++.h>
using namespace std;
vector<char> c;
void init(){
	c.push_back('A');
	c.push_back('H');
	c.push_back('I');
	c.push_back('M');
	c.push_back('O');
	c.push_back('T');
	c.push_back('U');
	c.push_back('V');
	c.push_back('W');
	c.push_back('X');
	c.push_back('Y');
}
bool notfunc(char a ){
	int i;
	for(i=0;i<c.size();i++){
		if(a == c[i])
			return false;
	}
	return true;
}
int main()
{
	init();
	string x;
	cin>>x;
	int i;
	string y = x;
	reverse(x.begin(),x.end());
	if(x == y){
		for(i=0;i<x.length();i++){
			if(notfunc(x[i])){
				cout<<"NO";
				break;
			}
		}
		if(i==x.length())
			cout<<"YES";
	}
	else{
		cout<<"NO";
	}

	return 0;
}