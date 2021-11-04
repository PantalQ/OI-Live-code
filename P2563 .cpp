// https://www.luogu.com.cn/problem/P2563
// 2021.11.3
//完全背包
#include<bits/stdc++.h>
using namespace std;
const int N = 200 +15;
int dp[N];
int su[N];
int cnt=1;
void findsu(int sup){
    for(int i=2;i<=sup;i++){
        bool nosu=0;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0){
                nosu=1;
                break;
            }
        }
        if(!nosu) su[cnt++]=i;
    }
}
int main(){
    int n;
    findsu(200);
    while(~scanf("%d",&n)){
        memset(dp,0,sizeof dp);
        dp[0]=1;
        // dp[1]=0,dp[2]=1,dp[3]=1;
        for(int i=1;i<cnt;i++){
            if(su[i]>n) break;
            for(int j=2;j<=n;j++){
                if(j-su[i]>=0){
                    // cout<<"dp["<<j<<"]="<<dp[j]<<' '<<"j="<<j<<' '<<"dp["<<j-su[i]<<"]="<<dp[j-su[i]]<<endl;
                    dp[j]=dp[j]+dp[j-su[i]];
                    // dp[j]=max(dp[j],dp[j-su[i]]+dp[su[i]]);
                    // cout<<i<<' '<<j<<endl;
                } 
            }
        }
        printf("%d\n",dp[n]);
    }


    return 0;
}