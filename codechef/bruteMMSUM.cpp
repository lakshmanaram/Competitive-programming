#include<stdio.h>
#define ll long long

long long int a[100000];
long long int mini[100000];
ll int ind;

ll int max(ll int a, ll int b) {
	if(a<b){
		return b;
	}
	return a;
}

ll int maxSubArraySum()
{
   ll int i = 1;
   ll int max_so_far_nu, curr_max_u, max_so_far_u;
   ll int curr_max_nu;
   if(a[0]<0){
   	curr_max_u = max_so_far_u = a[0]-mini[0];
   	max_so_far_nu = a[0];
   	curr_max_nu = a[0];
   	i=1;
   }
   else{
   	curr_max_u = max_so_far_u = a[0]+a[1]-mini[1];
   	max_so_far_nu = a[0]+a[1];
   	curr_max_nu = a[0]+a[1];
   	i=2;
   }
   for (; i < ind; i++)
   {
   	if(mini[i]==0){
   		curr_max_u = max(a[i], curr_max_u+a[i]);
		max_so_far_u = max(max_so_far_u, curr_max_u);
   		curr_max_nu = max(a[i], curr_max_nu+a[i]);
        	max_so_far_nu = max(max_so_far_nu, curr_max_nu);
   	}
   	else{
		curr_max_u = max(max(a[i], curr_max_u+a[i]), max(a[i]-mini[i], curr_max_nu+a[i]-mini[i]));
		max_so_far_u = max(max_so_far_u, curr_max_u);
		curr_max_nu = max(a[i], curr_max_nu+a[i]);
		max_so_far_nu = max(max_so_far_nu, curr_max_nu);
	}
   }
   return max(max_so_far_u, max_so_far_nu);
}

int main() {

   int t;
   ll int temp, maxi, size, i;
   int pos_flag=0;
   scanf("%d", &t);
   while(t--){
       scanf("%lld", &size);
       ind=0;
       pos_flag=0;
       for(i=0;i<size;i++){
        scanf("%lld", &temp);
        if(i==0) maxi=temp;
        if(maxi<temp)maxi=temp;
        if(temp>=0){
            if(pos_flag==0){
                ind++;
                if(i==0) ind--;
                a[ind]=0;
                mini[ind]=0;
            }
            a[ind]+=temp;
            pos_flag=1;
        }
        else{
            if(pos_flag==1){
                ind++;
                a[ind]=0;
                mini[ind]=0;
            }
            a[ind]+=temp;
            if(temp<mini[ind]){
                mini[ind]=temp;
            }
            pos_flag=0;
        }
       }
       if(maxi<=0) {
        printf("%lld\n", maxi);
        continue;
       }
       ind++;
       if(ind==1) {
       	printf("%lld\n", a[0]);
        continue;
       }
       printf("%lld\n", maxSubArraySum());
   }
   return 0;
}
