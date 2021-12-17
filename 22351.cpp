//22351:Quirksome Squares
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int n;
    int table[9] = {0, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
    while(cin >> n){
        for(int i = 0; i * i < table[n]; i ++){
            int number;
            int firsthalf, secondhalf;
            number = i * i;
            firsthalf = number / table[n / 2];
            secondhalf = number % table[n / 2];
            int sum;
            sum = (firsthalf + secondhalf) * (firsthalf + secondhalf);
            if(sum == number){
                cout << setw(n) << setfill('0') << number << endl;
            }

        }
    }

    return 0;
}