//Codeforces Round #337 (Div. 2) A
#include<iostream>
using namespace std;
int main(){
	long long n;
	cin>>n;
	if (n%2==1){
		cout<<0<<endl; 
	}
	else{
	if(n%4==0)
		cout<<n/4-1;
	else
		cout<<n/4;
	}
	return 0;
}