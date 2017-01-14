#include <bits/stdc++.h>
#define pdd pair<double,double>
#define circle pair<pdd,double>
#define yc second
#define xc first
using namespace std;
double distance_pts(pdd a, pdd b){
	return sqrt(pow(a.xc - b.xc,2)+pow(a.yc - b.yc,2));
}
bool isPtWithinCircle(pdd point, pdd center, double radius) {
	return (distance_pts(point,center) <= radius);
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
int main(){
	int n;
	cin>>n;
	vector<pdd > points(n);
	for(int i=0;i<n;i++){
		cin>>points[i].xc>>points[i].yc;
	}
	pdd center;
	cin>>center.xc>>center.yc;
	double radius;
	cin>>radius
	// test
	if(isPtWithinCircle(points[0],center,radius))
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}
