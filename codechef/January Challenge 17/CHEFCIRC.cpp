#include <bits/stdc++.h>
#define pdd pair<double,double>
#define circle pair<pdd,double>
#define yc second
#define xc first
using namespace std;
double distance_pts(pdd a, pdd b){
	return sqrt(pow(a.xc - b.xc,2)+pow(a.yc - b.yc,2));
}
int m,n;
vector<pdd> points;
int noPtsWithinCircle(circle Circle) {
	int ans = 0;
	for(int i=0;i<points.size();i++)
		if(distance_pts(points[i],Circle.xc) <= Circle.yc)
			ans++;
	return ans;
}
circle getCircle2(pdd a, pdd b) {
	pdd center;
	double radius = distance_pts(a,b)/2;
	center.xc = (a.xc+b.yc)/2;
	center.yc = (a.xc+b.yc)/2;
	return make_pair(center,radius);
}
circle getCircle3(pdd a, pdd b, pdd c) {
	pdd center;
	double yaDelta = b.yc - a.yc, xaDelta = b.xc - a.xc;
    double ybDelta = c.yc - b.yc, xbDelta = c.xc - b.xc;
    double aSlope = yaDelta/xaDelta;
    double bSlope = ybDelta/xbDelta;
    if(aSlope == bSlope)
    	return make_pair(center,0);
    center.xc=(aSlope*bSlope*(a.yc-c.yc)+bSlope*(a.xc+b.xc)-aSlope*(b.xc+c.xc))/(2*(bSlope-aSlope));
    center.yc = -1*(center.xc-(a.xc+b.xc)/2)/aSlope+(a.yc+b.yc)/2;
    double radius = distance_pts(center,a);
	return make_pair(center,radius);
}
int main() {
	cin>>n>>m;
	points.resize(n);
	for(int i=0;i<n;i++)
		cin>>points[i].xc>>points[i].yc;
	double minval = -1;
	// Finding two endpoints of the circle
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			circle Circle = getCircle2(points[i],points[j]);
			if(noPtsWithinCircle(Circle) >= m)
				if (minval == -1 || Circle.yc < minval)
					minval = Circle.yc;
		}
	}
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			for(int k = j+1;k<n;k++) {
				circle Circle = getCircle3(points[i],points[j],points[k]);
				if(Circle.second != 0 && noPtsWithinCircle(Circle) >= m)
					if (minval == -1 || Circle.yc < minval)
						minval = Circle.yc;
			}
		}
	}
	cout<<minval;
	return 0;
}