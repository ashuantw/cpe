//Sum of Consecutive Prime Numbers
#include <iostream>
#include <vector>

using namespace std;

int main(){
    //build prime table
    vector<int> prime_list;
    int number[10001] = {0};
    for(int i = 2; i < 10001; i ++){
        if(number[i] == 0){
            for(int j = i + i; j < 10001; j += i){
                number[j] = 1;
            }
            prime_list.push_back(i);
        }
    }
    int input;
    while(cin >> input && input != 0){
        int count = 0;
        for(int i = 0; prime_list[i] <= input; i ++){
            int sum = 0;
            for(int j = i; sum < input; j ++){
                sum += prime_list[j];
                if(sum == input){
                    count ++;
                    break;
                }
            }
        }
        cout << count << endl;
    }

    return 0;
}