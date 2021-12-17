//10655:Sumsets

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    while(cin >> n && n != 0){
        vector<int> S;
        bool solved = false;
        int sum = 0;
        for(int i = 0; i < n; i ++){
            int tmp;
            cin >> tmp;
            S.push_back(tmp);
        }

        //remember to sort
        sort(S.begin(), S.begin() + n);
        //IMPORTANT//
        //find larget d 所以要從最大的數字開始找
        for(int d = n - 1; d >= 0 && !solved; d --){
            for(int a = 0; a < n && !solved; a ++){
                if(a == d) continue;
                sum += S[a];
                for(int b = a + 1; b < n && !solved; b ++){
                    if(b == d) continue;
                    sum += S[b];
                    for(int c = b + 1; c < n && !solved; c ++){
                        if(c == d) continue;
                        sum += S[c];
                        if((S[d] == sum)){
                            cout << S[d] << endl;
                            solved = true;
                            break;
                        }
                        if(!solved) sum -= S[c];
                    }
                    if(!solved) sum -= S[b];
                }
                if(!solved) sum -= S[a];
            }
        }
        if(!solved) cout << "no solution" << endl;
    }

    return 0;
}

