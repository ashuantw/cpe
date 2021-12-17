//Hay Points
#include <iostream>
#include <map>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    map<string, int> dictionary;
    map<string, int>::iterator iter;
    for(int i = 0; i < a; i ++){
        string job;
        int salary;
        cin >> job >> salary;
        dictionary[job] = salary;
    }
    string input;
    for(int i = 0; i < b; i ++){
        int count = 0;
        while(cin >> input){
            if(input == ".") break;
            for(iter = dictionary.begin(); iter != dictionary.end(); iter ++){
                if(input == iter->first){
                    count += iter->second;
                }
            }
        }
        cout << count << endl;
    }

    return 0;
}