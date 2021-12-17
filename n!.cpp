#include <iostream>
#define MAX 100000000 //八進位

using namespace std;


int main(){
    int n;
    while(cin >> n){
        long long int ans[100000];
        ans[0] = 1;
        int len = 0;
        for(int i = 1; i <= n; i ++){
            int temp = 0;
            for(int j = 0; j <= len; j ++){
                ans[j] = ans[j] * i + temp;
                temp = ans[j] / MAX;
                ans[j] = ans[j] % MAX;
            }
            if(temp > 0){
                ans[++len] = temp;
            }
        }
    }

    return 0;
}