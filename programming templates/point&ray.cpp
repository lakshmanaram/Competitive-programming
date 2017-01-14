#include <bits/stdc++.h>
#defind pii pair<int,int>
using namespace std;
double distance_pts(pii a, pii b){
	return sqrt(pow(a.first - b.first,2)+pow(a.second - b.second,2));
}
double slope(pii a, pii b){
	// gives slope of the line ab - cannot give infinity slope
	return (double)(b.second - a.second)/(b.first - a.first);
}
double angle_pt_ray(pii a, pii b, pii c){
	// finds angle Labc in the same order => ba is the ray, c is the point
	if((c.first - a.first) == 0 && (c.first - b.first) == 0)
		return 0;
	else if(((c.first - a.first) != 0 && (c.first - b.first) != 0) && slope(a,c) == slope(b,c))
		return 0;
	double ab = distance_pts(a,b), bc = distance_pts(b,c), ca = distance_pts(a,c);
	double radians = acos((pow(ab,2) + pow(bc,2) - pow(ca,2))/(2*ab*bc));
	return radians*180/3.1415926536;
}
bool isPtrightofRay(pii a, pii b, pii c){
	// if a is striclty to the right of bc ray and Labc <=90
	double angle = angle_pt_ray(a,b,c);
	if(angle == 0 || angle > 90)
		return false;
	double x;
	return (a.second-b.second)*(c.first-b.first) < (a.first-b.first)*(c.second-b.second);
}
bool isPtLeftofRay(pii a, pii b, pii c){
	// if a is striclty to the left of bc ray and Labc <=90
	double angle = angle_pt_ray(a,b,c);
	if(angle == 0 || angle > 90)
		return false;
	double x;
	return (a.second-b.second)*(c.first-b.first) > (a.first-b.first)*(c.second-b.second);
}
int main(){
	int n;
	cin>>n;
	vector<pii > points(n);
	for(int i=0;i<n;i++){
		cin>>points[i].first>>points[i].second;
	}
	// test
	if(isPtrightofRay(points[2],points[1],points[0]))
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}
