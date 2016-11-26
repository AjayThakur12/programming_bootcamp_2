#include<iostream>
using namespace std;

int knapSack(int wts[],int price[],int n,int W){
    ///Base Case
    if(n==0||W==0){
        return 0;
    }
    ///Rec Case
    if(wts[n-1]>W){
        ///Leave that item
        return knapSack(wts,price,n-1,W);
    }
    else{
        ///Two options - Either Pick or Leave
        int inc = knapSack(wts,price,n,W-wts[n-1]) + price[n-1];
        int exc = knapSack(wts,price,n-1,W);
        return max(inc,exc);
    }
}

int main(){
    int n=3,w=10;
    int wts[] = { 3,4,5};
    int price[] ={3,2,1 };

    cout<<knapSack(wts,price,n,w);


    return 0;
}





