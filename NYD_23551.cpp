#include <iostream>
#include <cstdio>
using namespace std;

bool check(char map[105][105], char c, int start_row, int end_row, int start_col, int end_col, int inc_row, int inc_col ){
  for( ; start_row <= end_row && start_col <= end_col ; start_row += inc_row, start_col += inc_col ){
    if( map[start_row][start_col] != c ){
      return false;
    }
  }

  return true;
}


int main(){
  int T;
  while( scanf("%d", &T) != EOF ){
    int M, N, Q;
    for( int caseCount = 0 ; caseCount < T ; ++caseCount ){
      scanf("%d%d%d", &M, &N, &Q);
      printf("%d %d %d\n", M, N, Q);

      char map[105][105] = {0};
      for( int i = 1 ; i <= M ; ++i ){
        scanf("%s", &map[i][1]);
      }

      int x, y;
      for( int i = 0 ; i < Q ; ++i ){
        scanf("%d%d", &x, &y);
        ++x;
        ++y;

        int size = 1;
        while( true ){
          if( !check(map, map[x][y], x-size, x-size, y-size, y+size, 0, 1 ) ){
            break;
          }

          if( !check(map, map[x][y], x+size, x+size, y-size, y+size, 0, 1 ) ){
            break;
          }

          if( !check(map, map[x][y], x-size, x+size, y-size, y-size, 1, 0 ) ){
            break;
          }

          if( !check(map, map[x][y], x-size, x+size, y+size, y+size, 1, 0 ) ){
            break;
          }

          ++size;
        }
        --size;
        printf("%d\n", size * 2 + 1);
      }
    }
  }

  return 0;
}