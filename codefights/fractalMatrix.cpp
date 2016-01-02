/*std::vector<std::vector<int> > fractalMatrix(int K, int x, int y, int N, int c = 1) {
    using namespace std;
    vector<vector<int> > ans;
    int i,j;
    if(K==1){
        vector<vector<int> > a = {{1,0,1},{1,0,1},{1,1,1}};
        if(c==1){
            for(i = x;i < x+N;i++){
                vector<int> temp;
                for(j=y;j<y+N;j++){
                    temp.push_back(a[i][j]);
                }
                ans.push_back(temp);
            }
            return ans;
        }
        return a;
    }
}
*/
#include<bits/stdc++.h>
using namespace std;
void rot(int n, int &x, int &y, int rx, int ry) {
    if (ry == 0) {
        if (rx == 1) {
            x = n-1 - x;
            y = n-1 - y;
        }
        int t  = x;
        x = y;
        y = t;
    }
}
//convert d to (x,y)
void d2xy(int n, int d, int &x, int &y) {
    int rx, ry, s, t=d;
    x = y = 0;
    for (s=1; s<n; s*=2) {
        rx = 1 & (t/2);
        ry = 1 & (t ^ rx);
        rot(s, x, y, rx, ry);
        x += s * rx;
        y += s * ry;
        t /= 4;
    }
}
vector<vector<int> > fractalMatrix(int K, int x, int y, int N) {
    int i,j;
    int n = pow(2,K);
    vector<int> a (2*n - 1,0);
    vector<vector<int> > arr (2*n - 1,a);
    vector<vector<int> > ans;
    for(i=0;i<2*n - 1;i++){
        for(j=0;j<2*n - 1;j++){
            arr[j][i] = 0;
        }
    }
    int px, py;
    px = 0;
    py = 0;
    for(i=0;i<n*n;i++){
        int c,d;
        d2xy(n,i,c,d);
        arr[2*c][2*d] = 1;
        arr[(c+px)][(d+py)] = 1;
        px = c;
        py = d;
    }
    for(i=y;i<y+N;i++){
        vector<int> temp;
        for(j=x;j<x+N;j++){
            temp.push_back(arr[j][i]);
        }
        ans.push_back(temp);
    }
    return ans;
}
int main(){
    int i,j;
    vector<vector<int> > arr = fractalMatrix(2,1,0,3);
    for(i=0;i<arr.size();i++){
        for(j=0;j<arr[0].size();j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
