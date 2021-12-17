//11017:Longest Common Subsequence
#include <iostream>
#include <cstring>

using namespace std;

int main(){
    string s1, s2;
    int lcs[1002][1002];
    while(getline(cin, s1)){
        getline(cin, s2);
        memset(lcs, 0, sizeof(lcs));
        for(int i = 1; i <= s1.size(); i ++){
            for(int j = 1; j <= s2.size(); j ++){
                if(s1[i - 1] == s2[j - 1]){
                    lcs[i][j] = lcs[i - 1][j - 1] + 1;
                }
                else{
                    if(lcs[i - 1][j] > lcs[i][j - 1]){
                        lcs[i][j] = lcs[i - 1][j];
                    }
                    else{
                        lcs[i][j] = lcs[i][j - 1];
                    }
                }
            }
        }
        cout << lcs[s1.size()][s2.size()] << endl;
    }

    return 0;
}
