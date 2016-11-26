#include<iostream>
using namespace std;

int computeMoves(int n){
    int dp[100][100]={0};

    dp[0][0] = 1;
    ///First Row
    for(int j=1;j<n;j++){
        int sum = 0;
        for(int k=j-1;k>=0;k--){
            sum += dp[0][k];
        }
        dp[0][j] = sum;
    }
    ///First Col
    for(int i=1;i<n;i++){
        int sum=0;
        for(int k=i-1;k>=0;k--){
            sum += dp[k][0];
        }
        dp[i][0]=sum;

    }
    ///Remaining Grid
    for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){

            int rsum =0, csum =0;
            ///Traverse Row
            for(int c=j-1;c>=0;c--){
                csum += dp[i][c];
            }

            ///Traverse Col
            for(int r=i-1;r>=0;r--){
                rsum += dp[r][j];
            }
            dp[i][j] = rsum+csum;
        }
    }
    return dp[n-1][n-1];
}


int main(){
    int n;
    cin>>n;
    cout<<computeMoves(n);


return 0;
}
