#include <iostream>
#include <cstring>
using namespace std;
int price[25][25];
int M, C;
int memo[25][205];

int shop(int money, int g){
    if (money < 0) return -100000;
    if (g == C) return memo[money][g]= M - money;
    if (memo[money][g] != -1) return memo[money][g];
    int ans = -1000000;
    for (int model = 1; model <= price[g][0]; ++model)
        ans = max(ans, shop(money-price[g][model], g + 1));
    return memo[money][g] = ans;
}

int shop2(int money, int g){
    for (int i = 1; i < price[0][0]; ++i){
        memo[g][M-price[g][i]] = true;
    }
    for (int gar = 1; gar <= C; ++gar){
        for (int money = 0; money <= M; ++money){
            if (memo[gar - 1][money])
                for (int k = 1; k <= price[gar][0]; ++k)
                if (money-price[g][k] >= 0)
                memo[gar-1][money-price[g][k]] = true;
        }
    }
}
int main(){
    cin >> M >> C;
    for (int g = 0; g < C; ++g){
            cin >> price[g][0]; //no of models
        for (int model = 1; model <= price[g][0]; ++model)
            cin >> price[g][model];
    }
    memset(memo, -1, sizeof memo);
    cout << shop(M, 0);


}
