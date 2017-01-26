#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	int m,d;
	cin>>m>>d;
	int days = 0;
	switch(m) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		days = 31;
		break;
		case 2:
		days = 28;
		break;
		case 4:
		case 6:
		case 9:
		case 11:
		days = 30;
	}
	days = days - (7-d+1);
	cout<<ceil((double)days/7.0)+1;
	return 0;
}