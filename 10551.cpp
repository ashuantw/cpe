//10551:Bee Maja
#include <iostream>
#include <vector>

#define MAX 100001

using namespace std;

struct Point{
    int x;
    int y;
};

//Point ans[100001];
vector<Point> ans;

int main(){
	Point start = {0, 0};
    ans.push_back(start);
    int index = 1;
    for(int num = 1; index < MAX; num ++){
    	Point current;
        for(int i = 0; i < num; i ++){
        	current.x = ans[index - 1].x;
            current.y = ans[index - 1].y + 1;
			ans.push_back(current);
            index ++;
        }
        for(int i = 0; i < num - 1; i ++){
            current.x = ans[index - 1].x - 1;
            current.y = ans[index - 1].y + 1;
            ans.push_back(current);
            index ++;
        }
        for(int i = 0; i < num; i ++){
            current.x = ans[index - 1].x - 1;
            current.y = ans[index - 1].y;
            ans.push_back(current);
            index ++;
        }
        for(int i = 0; i < num; i ++){
        	current.x = ans[index - 1].x;
            current.y = ans[index - 1].y - 1;
            ans.push_back(current);
            index ++;
        }
        for(int i = 0; i < num; i ++){
            current.x = ans[index - 1].x + 1;
            current.y = ans[index - 1].y - 1;
            ans.push_back(current);
            index ++;
        }
        for(int i = 0; i < num; i ++){
            current.x = ans[index - 1].x + 1;
            current.y = ans[index - 1].y;
            ans.push_back(current);
            index ++;
        }   
    }
    int input;
    while(cin >> input){
        cout << ans[input - 1].x << " " << ans[input - 1].y << endl;
    }

    return 0;
}
