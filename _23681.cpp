//23681:Bachet's Game
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
    int n;//number of stones
    int m;//number of steps choice
    int move[10];
    while(cin >> n >> m){
        bool DP[1000005];
        memset(DP, false, sizeof(DP));
        for(int i = 0; i < m; i ++){
            cin >> move[i];
        }
        sort(move, move + m);
        //DP table
        for(int i = 1; i <= n; i ++){
            for(int j = 0; j < m; j ++){
                if(move[j] <= i && !DP[i - move[j]]){
                    DP[i] = true;
                    break;
                }
            }
        }
        if(DP[n]){
            cout << "Stan wins" << endl;
        }
        else{
            cout << "Ollie wins" << endl;
        }
    }

    return 0;
}
