#include <bits/stdc++.h>
using namespace std;
map<pair< pair<int,int>,pair<int,int> >,double> precomp_dist;
bool pointscomp(pair<int,int> a, pair<int,int> b){
    if(a.first < b.first)
        return true;
    else if (a.first > b.first)
        return false;
    if(a.second < b.second)
        return true;
    return false;
}
double distance_pts(pair<int,int> a, pair<int,int> b){
	return sqrt(pow(a.first - b.first,2)+pow(a.second - b.second,2));
}
int angle_pt_ray(pair<int,int> a, pair<int,int> b, pair<int, int> c){
	// finds angle Labc in the same order => ba is the ray, c is the point
	if((c.first - a.first)*(b.second - a.second) == (b.first - a.first)*(c.second - a.second))
		return false;
	double ab, bc, ac;
    if(pointscomp(a,b))
        ab = precomp_dist[make_pair(a,b)];
    else
        ab = precomp_dist[make_pair(b,a)];
    if(pointscomp(c,b))
        bc = precomp_dist[make_pair(c,b)];
    else
        bc = precomp_dist[make_pair(b,c)];
    if(pointscomp(a,c))
        ac = precomp_dist[make_pair(a,c)];
    else
        ac = precomp_dist[make_pair(c,a)];
    if(ab + bc >= ac){
        if(ab + ac >= bc)
            return 2;
        else
            return 1;
    }
    if(ab + ac >= bc)
        return -1;
    return 0;
}
int findside(pair<int,int> a, pair<int,int> b, pair<int, int> c){
	int val = angle_pt_ray(c,b,a);
    if(val == 2){
        if((a.second-b.second)*(c.first-b.first) < (a.first-b.first)*(c.second-b.second))
	       return 1;
        if((a.second-b.second)*(c.first-b.first) > (a.first-b.first)*(c.second-b.second))
            return -1;
    }
    else if(val == 1){
        if((a.second-b.second)*(c.first-b.first) < (a.first-b.first)*(c.second-b.second))
	       return 1;
    }
    else if(val == -1){
        if((a.second-b.second)*(c.first-b.first) > (a.first-b.first)*(c.second-b.second))
            return -1;
    }
    return 0;
}
int main(){
	int n;
	cin>>n;
	vector<pair<int, int> > points(n);
	for(int i=0;i<n;i++){
		cin>>points[i].first>>points[i].second;
	}
    sort(points.begin(),points.end(),pointscomp);
    long long ans = 0;
    for(int i=0;i<n;i++){
        for(int j = i+1;j<n;j++){
            precomp_dist[make_pair(points[i],points[j])] = pow(distance_pts(points[i],points[j]),2);
        }
    }
    for(int i=0;i<n;i++){
        for(int j = i+1;j<n;j++){
            int left = 0, right = 0;
            for(int k=0;k<n;k++){
                if(k == i || k == j)
                    continue;
                int x = findside(points[k],points[i],points[j]);
                if(x == 1)
                    right++;
                else if(x == -1)
                    left++;
            }
            ans += left*right;
        }
    }
    cout<<ans;
	return 0;
}