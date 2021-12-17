//11266:Generate random numbers
#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int input;
    bool list[10001];
    while(cin >> input && input != 0){
        int count = 0;
        memset(list, false, sizeof(list));
        while(!list[input]){
            count ++;
            list[input] = true;
            input = input * input;
            cout << input << endl;
            input /= 100;
            input %= 10000;
        }
        cout << count << endl;
    }

    return 0;
}
