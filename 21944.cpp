//21944:Power Crisis
#include <iostream>
#include <list>

using namespace std;

int main(){
    int N;
    list<int> l;
    while(cin >> N && N != 0){
        int m = 1;
        while(m){
            l.clear();
            for(int i = 1; i <= N; i ++){
                l.push_back(i);
            }

            while(l.size() > 1){
                l.pop_front();

                for(int i = 1; i < m; i ++){
                    l.push_back(l.front());
                    l.pop_front();
                }
            }
            m ++;
            if(l.front() == 13){
                cout << --m << endl;
                break;
            }
        }
    }

    return 0;
}
