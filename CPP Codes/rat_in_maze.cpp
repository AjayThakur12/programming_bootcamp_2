#include<iostream>
using namespace std;

void TOH(int n,char src,char helper,char dest){
    if(n==0){
        return ;
    }
    TOH(n-1,src, dest ,helper);
    cout<<"Moving "<<n<<"from "<<src<<" to "<<dest<<endl;
    TOH(n-1,helper,src  ,dest);
}

void print(int sol[][10],int m,int n){

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

}

bool rat_in_maze(char grid[][10],int sol[][10],int i,int j,int m,int n){
    ///Base Case
    if(i==m-1&&j==n-1){
        sol[i][j]=1;
        print(sol,m,n);
        return true;

    }
    ///Recursvie Case
    sol[i][j]=1;
    ///Down jake ddekho
    if(i+1<m && grid[i+1][j]!='X'){
        bool pathMila = rat_in_maze(grid,sol,i+1,j,m,n);
        if(pathMila==false){
            sol[i+1][j]=0;
        }
    }
    ///Right jake dekho
    if(j+1<n && grid[i][j+1]!='X'){
        bool pathMila = rat_in_maze(grid,sol,i,j+1,m,n);
        if(pathMila==false){
            sol[i][j+1]=0;
        }
    }


}

int main(){


    char grid[10][10] = { "..X..X","......",
    ".X.X.X",".....X","..XX.." };

    int solution[10][10];

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            solution[i][j]=0;
        }
    }
    int m=5;
    int n=6;


    rat_in_maze(grid,solution,0,0,m,n);


    return 0;
}
