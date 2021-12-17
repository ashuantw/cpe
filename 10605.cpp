//10605:Count the Trees
#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip> //setw

#define MAX 100000000

using namespace std;

int main(){
    int n;
    while(cin >> n && n != 0){
        long long int ans[100050];
        int len = 0;
        ans[0] = 1;

        //n >= 2
        for(int i = 2 + n; i <= 2 * n; i ++){
            long long temp = 0;
            for(int j = 0; j <= len ; j ++){
                ans[j] = ans[j] * i + temp;
                temp = ans[j] / MAX;
                ans[j] = ans[j] % MAX;
            }
            if(temp > 0){
                ans[++len] = temp;
            }
        }
        
        cout << ans[len];
        for(int i = len - 1; i >= 0; i --){
            cout << setw(8) << setfill('0') << ans[i];
        }
        
        /*
		//¦Û°Ê¸É 0  
        printf("%lld",ans[len]);
        for(int i=len-1;i>=0;i--){
            printf("%08lld",ans[i]);
        }
        */
            
        cout<<endl;
    }

    return 0;
}
