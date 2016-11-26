#include<iostream>
using namespace std;

int countWays(int n){

    if(n==1)
    {
        return 1;
    }
    if(n==2){
        return 2;
    }
    if(n==0){
        return 1;
    }
    return countWays(n-1)+countWays(n-2)+countWays(n-3);

}

int countUsingDp(int n){
    int arr[100];

    arr[0]=1;
    arr[1]=1;
    arr[2] = 2;

    for(int i=3;i<=n;i++){
            arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
    }
    return arr[n];
}


int main(){
cout<<countWays(4)<<endl;
cout<<countUsingDp(4)<<endl;

return 0;
}
