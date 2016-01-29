/*
   char arr[R][C] = { {'E', 'C', 'C', 'C', 'C'},
                       {'C', '#', 'C', '#', 'E'},
                       {'#', 'C', 'C', '#', 'C'},
                       {'C', 'E', 'E', 'C', 'E'},
                       {'C', 'E', '#', 'C', 'E'}
                     };
   maxCoinRec(arr, 0, 0, 1);
   
   if (arr[i][j] = '#')
   return 0;
   if (arr[i][j] == 'C')
   result = 1;
   else
   result = 0;
   if (dir == 0)
     result = result + max( maxCoinRec(arr, i, j + 1, 0),
     maxCoinRec(arr, i + 1, j, 1) );
*/

#define R 5
#define C 5
#include <iostream>
#include <algorithm>
using namespace std;

bool isCheck(int i, int j) {
  if (i < 0 || i >= R)
    return false;
  if (j < 0 || j >= C)
    return false;
  return true;
}

int maxCoinRec(char arr[R][C], int i, int j, int dir) {
  
  
  if (!isCheck(i, j))
    return 0;

  if (arr[i][j] == '#')
    return 0;

  int result;
  if (arr[i][j] == 'C')
    result = 1;
  else
    result = 0;

  if (dir == 0)
   return  result + max(maxCoinRec(arr, i, j + 1, 0),
                        maxCoinRec(arr, i + 1, j, 1));

  return result + max(maxCoinRec(arr, i, j - 1, 1),
                      maxCoinRec(arr, i + 1, j, 0));

}

int main() {
  char arr[R][C] = { {'E', 'C', 'C', 'C', 'C'},
                     {'C', '#', 'C', '#', 'E'},
                     {'#', 'C', 'C', '#', 'C'},
                     {'C', 'E', 'E', 'C', 'E'},
                     {'C', 'E', '#', 'C', 'E'}
  };
  cout << "\n\n" << maxCoinRec(arr, 0, 0, 0) << "\n\n";
  return 0;
}


