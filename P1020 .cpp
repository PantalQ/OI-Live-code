// https://www.luogu.com.cn/problem/P1020
// 2021.11.6
#include<bits/stdc++.h>
using namespace std;
const int N = 100000 + 15;
int dp[50005];
int n;
int mis[N];
int main(){
    memset(dp,0,sizeof dp);
    int cnt=0;
    int num_max=INT_MIN;
    while(~scanf("%d",&mis[++cnt])){
        num_max=max(mis[cnt-1],num_max);
        dp[mis[cnt-1]]=1;
    }
    cout<<num_max<<endl;
    for(int i=1;i<cnt;i++){
        for(int j=num_max;j>=mis[i];j--){
            // cout<<dp[j]<<endl;
            dp[j]=max(dp[j],dp[mis[i]]+1);
            // cout<<dp[j]<<endl;
        }
    }
    printf("%d\n",dp[num_max]);

    return 0;
}