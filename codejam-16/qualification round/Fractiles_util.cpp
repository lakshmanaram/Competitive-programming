#include<bits/stdc++.h>
using namespace std;
ofstream file;
void getstring(string a, int c){
	c--;
	string old = a;
	while(c--){
		string b = "";
		for(int i=0;i<old.size();i++){
			for(int j=0;j<a.size();j++){
				if(old[i] == 'G'){
					b += 'G';
				} else {
					b += a[j];
				}
			}
		}
		a = b;
	}
	cout<<a<<endl;
	file<<a<<"P"<<endl;
	return;
}
int main()
{
	int n;
	cin>>n;
	file.open("Fractiles-util.out");
	ifstream infile;
	infile.open("combinations");
	int i = 64;
	while(i--){
		string a;
		infile>>a;
		replace(a.begin(),a.end(),'1','G');
		replace(a.begin(),a.end(),'0','L');
		getstring(a,n);
	}
	file.close();
	return 0;
}
