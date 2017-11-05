#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector<long long> 
using namespace std;
int a, b;
long long nCk(long long n, long long k){
    if(k==1) return n;
    else if(k==2) return (n*(n-1))/2;
    else if(k==0) return 1;
    else if(k==3) return (n*(n-1)*(n-2))/6;
    else while(1);
}
long long straight(long a1, long a2) {
	int ans = 0;
	for(int x = 1;x <= a-4; x++){
		int c = 0;
		for(int y = x; y <= x+4; y++){
			if(y == a1 || y == a2) c++;
		}
		if(c == 2) ans++;
	}
	return ans;
}
int main(){
	cin>>a>>b;
	int a1, b1, a2, b2;
	cin>>a1>>b1>>a2>>b2;
	ll i1, i2, i3, i4, i5, i6, i7, i8, i9;
	if(b1 == b2){
		i4 = nCk(a-2,3);
	} else {
		i4 = 0;
	}
	if (b == 1) {
		i2 = i3 = i6 = i7 = i8 = i5 = 0;
		i1 = straight(a1, a2);
	} else if (b == 2){
		i2 = i3 = i6 = 0;
		if(a1 != a2){
			i5 = straight(a1,a2)*pow(2,3);
		} else i5 = 0;
		if(i4 != 0 && i5 != 0){
			i1 = straight(a1,a2);
		}
		if(a1 == a2) i7 = (a-1) + (a-2)*2;
		else i7 = (a-2)*2;
		if(a1 == a2) i8 = nCk(a*b-2,3);
		else i8 = nCk(a*b-3,2)*2;
	} else if (b == 3) {
		i2 = 0;
		if(a1 == a2) i5 = 0;
		else i5 = straight(a1,a2)*pow(3,3);
		if(a1 != a2) i3 = 4;
		else i3 = (a-1)*4;
		if(a1 == a2) i6 = nCk(a*b-3,2);
		else i6 = 2*nCk(a*b-4,1);
		i6 -= i3;
		if(a1 == a2) i7 = (a-1)*3 + nCk(a*b-4,1);
		else i7 = 
		if(a1 == a2) i8 = nCk(a*b-2,3);
		else i8 = nCk(a*b-3,2)*2;
	} else if (b == 4) {
		if(a1 == a2) i5 = 0;
		else i5 = straight(a1,a2)*pow(4,3);
		if(a1 != a2) i2 = 2;
		else i2 = a-1;
		if(a1 != a2) i3 = 18;
		else i3 = (a-1)*16;
		if(a1 == a2) i6 = 2*nCk(a*b-3,2);
		else i6 = 2*3*nCk(a*b-4,1);
		i6 -= i3;
		if(a1 == a2)
		if(a1 == a2) i8 = nCk(a*b-2,3);
		else i8 = nCk(a*b-3,2)*2;
	}
	if(i4 != 0 && i5 != 0){
		i1 = straight(a1,a2);
	}
	i4 -= i1;
	i5 -= i1;
	// i6 -= i2+i3;
	// i7 -= i3+i6;
	i8 -= (i7+i6+i3+i2);
	i9 = nCk(a*b-2,3);
	i9 -= i1+i2+i3+i4+i5+i6+i7+i8;
	cout<<i1<<" "<<i2<<" "<<i3<<" "<<i4<<" "<<i5<<" "<<i6<<" "<<i7<<" "<<i8<<" "<<i9<<endl;
	return 0;
}