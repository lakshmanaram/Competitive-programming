#include <bits/stdc++.h>
using namespace std;
class SellingFruits{
public:
	long long maxDays(long long  x, long long f, long long d, long long p) {
		if( f >= (d/x))
			return d/x;
		long long y = p*(d-x*f);
		cout<<y<<endl;
		y /= (p+x);
		long long ans = f + (y / p);
		if (ans > ((d - y)/x))
			ans = ((d - y)/x);
		y -= 1;
		long long ans1 = f + (y / p);
		if (ans1 > ((d - y)/x))
			ans1 = ((d - y)/x);
		if (ans1 > ans)
			ans = ans1;
		y += 2;
		ans1 = f + (y / p);
		if (ans1 > ((d - y)/x))
			ans1 = ((d - y)/x);
		if (ans1 > ans)
			ans = ans1;
		return ans;
	}
};