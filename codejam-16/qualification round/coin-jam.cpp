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
	long long i = 16384;
	while(i--){
		string a;
		infile>>a;
		string s = "1";
		s += a;
		s += "1\0";
		cout<<s<<endl;
	}
	file.close();
	return 0;
}
