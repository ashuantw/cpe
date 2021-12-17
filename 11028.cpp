//11028:Digit Primes
#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

struct Number{
    bool isComposite;
    int DigitPrimeCount;
};

vector<Number> numberlist(1000000, Number{false, 0});
//Number numberlist[1000000];

int main(){
    //create digit primes table
    for(int i = 2; i < 1000000; i ++){
        if(numberlist[i].isComposite){
            numberlist[i].DigitPrimeCount = numberlist[i - 1].DigitPrimeCount;
            continue;
        }
        for(int j = i + i; j < 1000000; j += i){
            numberlist[j].isComposite = true;
        }
        
        int x = i;
        //caculate i's digit sum
        int sum = 0;
        while(x > 0){
            sum += x % 10;
            x /= 10;
        }
        if(numberlist[sum].isComposite){
            numberlist[i].DigitPrimeCount = numberlist[i - 1].DigitPrimeCount;
        }
        else{
            numberlist[i].DigitPrimeCount = numberlist[i - 1].DigitPrimeCount + 1;
        }

        
    }

    int N;
    while(scanf("%d", &N) != EOF){
        for(int casenumber = 0; casenumber < N; casenumber ++){
            int t1, t2;
            scanf("%d %d", &t1, &t2);
            int ans = 0;
            ans = numberlist[t2].DigitPrimeCount - numberlist[t1 - 1].DigitPrimeCount;
            printf("%d\n", ans);
        }
    }

    return 0;
}
