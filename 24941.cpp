//24941:Uncompress
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string input;
    string word = "";
    string num = "";
    vector<string> list;
	
    while(getline(cin, input) && input != "0"){
        input += '\n';
        for(int i = 0; i < input.size(); i ++){
            if(isalpha(input[i])){
                word += input[i];
            }
            else if(isdigit(input[i])){
                num += input[i];
            }
            else{
                if(!word.empty()){
                    auto it = list.insert(list.begin(), word);
                    for(int j = 0; j < list.size(); j ++){
                    	cout << list[j] << " ";
					}
					cout << endl;
                    cout << word;
                    word.clear();
                }
                else if(!num.empty()){
                	cout << list[stoi(num) - 1];
                	auto it = list.insert(list.begin(), list[stoi(num)]);
                	for(int j = 0; j < list.size(); j ++){
                    	cout << list[j] << " ";
					}
					cout << endl;
                	num.clear();
				}
                
                cout << input[i];
            }
        }
    }

    return 0;
}
