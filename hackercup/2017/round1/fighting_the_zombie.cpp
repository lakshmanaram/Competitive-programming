#include <bits/stdc++.h>
#define ll long long
#define Point pair<ll,ll>
#define vpts vector<Point >
using namespace std;
vpts points;
vector<vpts> arr;
ll r;
vpts ptsInsideSquare(ll x1, ll y1, ll x2, ll y2 ) {
    vpts ans;
    for(int i=0;i<points.size();i++) {
        if(points[i].first >= x1 && points[i].first <= x2) 
            if(points[i].second >= y1 && points[i].second <= y2) 
                ans.push_back(points[i]);
    }
    return ans;
}
void findAllSquares(Point a) {
    vpts temp = ptsInsideSquare(a.first, a.second, a.first + r, a.second + r);
    if(temp.size()!=0)
        arr.push_back(temp);
    temp = ptsInsideSquare(a.first - r, a.second, a.first, a.second + r);
    if(temp.size()!=0)
        arr.push_back(temp);
    temp = ptsInsideSquare(a.first, a.second - r, a.first + r, a.second);
    if(temp.size()!=0)
        arr.push_back(temp);
    temp = ptsInsideSquare(a.first - r , a.second - r, a.first, a.second);
    if(temp.size()!=0)
        arr.push_back(temp);
}
int main(){
    ifstream infile;
    ofstream outfile;
    ll t;
    infile.open("fighting_the_zombies.txt");
    outfile.open("output.txt");
    infile>>t;
    for(ll tk=1;tk<=t;tk++){
        int n;
        infile>>n>>r;
        points.clear();
        arr.clear();
        points.resize(n);
        for(int i=0;i<n;i++)
            infile>>points[i].first>>points[i].second;
        sort(points.begin(),points.end());
        for(int i=0;i<n;i++) {
            findAllSquares(points[i]);
        }
        vpts newarr(100);
        int ans = 0;
        for(int i=0;i<arr.size();i++) {
            for(int j=i+1;j<arr.size();j++) {
                vpts::iterator it = set_intersection(arr[i].begin(),arr[i].end(),arr[j].begin(),arr[j].end(),newarr.begin());
                ans = max(ans,(int)(arr[i].size()+arr[j].size()-distance(newarr.begin(),it)));
            }
        }
        if(ans > n)
            cout<<"hola"<<endl;
        cout<<n<<" "<<ans<<endl;
        outfile<<"Case #"<<tk<<": "<<ans<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
}
