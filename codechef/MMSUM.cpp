#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long n;
        cin>>n;
        vector<long long> arr(n);
        for(long i=0;i<n;i++){
            cin>>arr[i];
        }
        long long maxval,sum;
        maxval = *max_element(arr.begin(),arr.end());
        vector<long long>::iterator left,right;
        left = right = arr.begin();
        bool k_used = false;
        sum = 0;
        long noe_used = 0;
        long long minele_used;
        while(right!=arr.end()){
            if(k_used && sum + minele_used>=0 && minele_used > *right){
                sum += minele_used;
                noe_used++;
                k_used = false;
                if(noe_used!=0)
                    maxval = max(maxval,sum);
            }
            sum += *right;
            if(sum <=0 && k_used){
                sum -= *right;
                if(noe_used!=0)
                    maxval = max(maxval,sum);
                break;
            }else if(sum<=0){
                k_used = true;
                sum -= *right;
                minele_used = *right;
                right++;
                continue;
            }
            // cout<<"Increasing 2 for "<<*right<<endl;
            right++;
            noe_used++;
        }
        if(noe_used!=0)
            maxval = max(maxval,sum);
        else{
            cout<<maxval<<endl;
            continue;
        }
        while(left!=arr.end()||right!=arr.end()){
            long long prevsum = sum;
            if(!k_used){
                minele_used = *min_element(left,right);
                if(minele_used >= 0)
                    break;
                sum -= minele_used;
                maxval = max(sum,maxval);
                k_used = true;
            }
            while(left!=arr.end() && k_used){
                //cout<<"Inside left for "<<*left<<endl;
                if(*left!=minele_used){
                    sum -= *left;
                    noe_used--;
                    if(prevsum < sum){
                //        cout<<"Going out of presum"<<endl;
                        if(noe_used!=0)
                            maxval = max(maxval,sum);
                        left++;
                        break;
                    }
                } else{
                //    cout<<"Going out of min_ele"<<endl;
                    minele_used = 0;
                    k_used = false;
                }
                left++;
            }
            while(right!=arr.end()){
                if(k_used && sum + minele_used>=0 && minele_used > *right){
                    sum += minele_used;
                    noe_used++;
                    k_used = false;
                    if(noe_used!=0)
                        maxval = max(maxval,sum);
                }
                sum += *right;
                if(sum <=0 && k_used){
                    sum -= *right;
                    if(noe_used!=0)
                        maxval = max(maxval,sum);
                    break;
                }else if(sum<=0){
                    k_used = true;
                    sum -= *right;
                    minele_used = *right;
                    right++;
                    continue;
                }
                // cout<<"Increasing 2 for "<<*right<<endl;
                right++;
                noe_used++;
            }
        }
        if(noe_used!=0)
            maxval = max(maxval,sum);
        cout<<maxval<<endl;
    }
    return 0;
}
