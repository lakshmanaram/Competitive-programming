#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<char> > arr;
int getans(int x,int y){
    int maxradius = min(min(x,(int)arr.size()-1-x),min(y,(int)arr.size()-1-y));
    //cout<<maxradius<<"<-"<<endl;
    int radius = 1;
    while(radius <= maxradius){
        for(int i=x-radius;i<=x+radius;i++){
            int ax,ay;
            ax = abs(i-x);
            for(int j=y-radius;j<=y+radius;j++){
                ay = abs(j-y);
                if(ax*ax + ay*ay > radius*radius)
                    continue;
                else if(ax*ax + ay*ay <= (radius-1)*(radius-1))
                    break;
                else{
                    if(arr[i][j] == '*')
                        return radius-1;
                }
            }
            for(int j=y+radius;j>=y-radius;j--){
                ay = abs(j-y);
                if(ax*ax + ay*ay > radius*radius)
                    continue;
                else if(ax*ax + ay*ay <= (radius-1)*(radius-1))
                    break;
                else{
                    if(arr[i][j] == '*')
                        return radius-1;
                }
            }
        }
        radius++;
    }
    return radius-1;
}
int main() {
    int n;
    cin>>n;
    vector<char> temp(n);
    arr.resize(n,temp);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){

            cin>>arr[i][j];
        }
    }
    int ans = 0;
    for(int i=1;i<arr.size()-1;i++){
        for(int j=1;j<arr.size()-1;j++){
            int temp = getans(i,j);
            if(temp>ans)
                ans = temp;
        }
    }
    cout<<ans;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
