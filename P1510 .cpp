// https://www.luogu.com.cn/problem/P1510
// 2021.11.3
#include<bits/stdc++.h>
using namespace std;
const int N = 10000 + 15;
int v,n,c;
int k[N],w[N],dp[N];//dp[i]剩下体力值为i时填的最大体积
int main(){
    scanf("%d%d%d",&v,&n,&c);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&k[i],&w[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=c;j>=w[i];j--){
            dp[j]=max(dp[j],dp[j-w[i]]+k[i]);
        }
    }
    for(int i=0;i<=c;i++){
        if(dp[c]<v){
            printf("Impossible\n");
            break;
        }
        if(dp[i]>=v){
            printf("%d\n",c-i);
            break;
        }
    }
    return 0;
}