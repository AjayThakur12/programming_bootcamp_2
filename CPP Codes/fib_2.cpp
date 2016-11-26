#include<iostream>
using namespace std;

int fib(int dp[],int n){
    ///Base Case
    if(dp[n]!=-1){
        return dp[n];
    }
    if(n==0||n==1){
        return n;
    }
    ///Rec Case
    int f1 = fib(dp,n-1);
    int f2 = fib(dp,n-2);

    dp[n] = f1+f2;

    return dp[n];
}
///Bottom Up Dp
int bottomUpDp(int n){
    int dp[100];

    dp[0] = 0;
    dp[1] = 1;

    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}


int main(){
    int dp[100];

    for(int i=0;i<100;i++){
        dp[i] = -1;
    }

    cout<<fib(dp,6)<<endl;
    cout<<bottomUpDp(6)<<endl;
return 0;
}
