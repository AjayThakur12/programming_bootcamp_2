#include<iostream>
using namespace std;



int fib(int dp[],int n){
    ///Base Case
    if(dp[n]!=-1){
        return dp[n];
    }

    if(n==0||n==1){
        dp[n] = n;
        return n;
    }

    ///Rec Case
    int f1 = fib(dp,n-1);
    int f2 = fib(dp,n-2);

    dp[n] = f1+f2;
    return dp[n];
}
int bottomUpDp(int n){
    int *arr = new int[n];
    arr[0]=0;
    arr[1] = 1;

    for(int i=2;i<=n;i++){
        arr[i] = arr[i-1]+arr[i-2];
    }
    return arr[n];
}

int main(){

int dp[100];
for(int i=0;i<100;i++){
    dp[i] = -1;
}

cout<<fib(dp,5)<<endl;

return 0;
}

