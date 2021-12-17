//11006:Rank the Languages
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char map[22][22] = {0};
bool visited[22][22];

void DFS(int x, int y){
    visited[x][y] = true;
    if(!visited[x - 1][y] && map[x - 1][y] == map[x][y]){
        DFS(x - 1, y);
    }
    if(!visited[x][y - 1] && map[x][y - 1] == map[x][y]){
        DFS(x, y - 1);
    }
    if(!visited[x + 1][y] && map[x + 1][y] == map[x][y]){
        DFS(x + 1, y);
    }
    if(!visited[x][y + 1] && map[x][y + 1] == map[x][y]){
        DFS(x, y + 1);
    }
}

int main(){
    int N;
    while(cin >> N){
        for(int c = 1; c <= N; c ++){
            cout << "World #" << c << endl;
            memset(visited, false, sizeof(visited));
            int H, W;
            int maxarea = 0;
            int letters[29] = {0};
            cin >> H >> W;
            getchar();
            for(int i = 1; i <= H; i ++){
                for(int j = 1; j <= W; j ++){
                    scanf("%c", &map[i][j]);
                }
                getchar();
            }
            for(int i = 1; i <= H; i ++){
                for(int j = 1; j <= W; j ++){
                    if(!visited[i][j]){
                        letters[map[i][j] - 'a'] ++;
                        if(letters[map[i][j] - 'a'] > maxarea){
                            maxarea = letters[map[i][j] - 'a'];
                        }
                        DFS(i, j);
                    }
                }
            }
            for(int i = maxarea; i > 0; i --){
                for(int j = 0; j < 29; j ++){
                    if(letters[j] == i){
                        printf("%c: %d\n", j + 'a', i);
                    }
                }
            }

        }
    }

    return 0;
}
