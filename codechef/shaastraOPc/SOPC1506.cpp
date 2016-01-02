#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,i,j,k,x,y;
        cin>>n>>m;
        int s = 2*n-1;
        int box[s][s];
        for(i=0;i<s;i++){
            for(j=0;j<s;j++){
                if(i%2==0&&j%2==0)
                    box[i][j] = 2;
                else
                    box[i][j] = 0;
            }
        }
        for(i=0;i<m;i++){
            char ch;
            cin>>ch>>x>>y;
            x = 2*(x-1);
            y = 2*(y-1);
            switch(ch){
                case 'H':
                    box[x][y+1] = 1;
                break;
                case 'V':
                    box[x+1][y] = 1;
                break;
            }
        }
        long ans = 0;
        int size = 1;
        while(size<n){
            for(i=0;i+2*size<s;i+=2){
                for(j=0;j+2*size<s;j+=2){
                    bool yes = true;
                    for(x = j+1 ; x < j+2*size ; x += 2){
                        if(box[i][x]!=1)
                            yes = false;
                    }
                    for(x = i+1 ; x < i+2*size ; x += 2){
                        if(box[x][j]!=1)
                            yes = false;
                    }
                    for(x = j+2*size-1 ; x > j ; x -= 2){
                        if(box[i+2*size][x]!=1)
                            yes = false;
                    }
                    for(x = i+2*size-1 ; x > i ; x -= 2){
                        if(box[x][j+2*size]!=1)
                            yes = false;
                    }
                    if(yes)
                        ans++;
                }
            }
            size++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
