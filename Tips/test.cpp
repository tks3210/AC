#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int map[201][201] = {0};
int isBreak[201][201] = {0};
int finmap[201][201] = {0};

bool dfs(int x, int y, int z, vector<pair<int, int>>& v){
  int br = false;
  finmap[y][x] = 1;
  map[y][x] = z + 1;
  v.push_back(make_pair(y, x));
  int move[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  for (int i = 0; i < 4; i++){
    int nx = x + move[i][0];
    int ny = y + move[i][1];
    if (map[ny][nx] <= z && finmap[ny][nx] != 1){
      if (isBreak[ny][nx] == 1){
        br = true;
      } else {
        br |= dfs(nx, ny, z, v);
      }
    }
  }
  return br;
}

void show_map(int n , int m){
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      cout << map[i][j] << " ";
    }
    cout << endl;
  }
}

void show_break(int n , int m){
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      cout << isBreak[i][j] << " ";
    }
    cout << endl;
  }
}



int main(int argc, char *argv[]) {

  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> v;
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= m; j++){
      int tmp; cin >> tmp;
      map[i][j] = tmp;
    }
  }
  for (int i = 1; i <= m; i++){
    isBreak[1][i] = 1;
    isBreak[n][i] = 1;
  }
  for (int i = 1; i <= n; i++){
    isBreak[i][1] = 1;
    isBreak[i][m] = 1;
  }

  int ans = 0;
  for(int z = 1; z <= 9; z++){
    for (int i = 2; i <= n - 1; i++){
      for (int j = 2; j <= m - 1; j++){
        if (map[i][j] != z || isBreak[i][j] == 1) continue; 
        v.clear();
        memset(finmap, 0, sizeof(finmap));
        if(dfs(j, i, z, v)){
          for (auto p:v){
            isBreak[p.first][p.second] = 1;
          }
        } else {
          ans += v.size();
          for (auto p:v){
            map[p.first][p.second] = z + 1;
          }
        }
        if (v.size() != 0){
          for (auto p:v){
            printf("-------\n%d %d %d %d\n-------\n", i, j, p.second, p.first);
          }
        }
      }
    }
    show_map(n, m);
    show_break(n, m);
    cout << "water" << z << " " << ans << endl;
  }

    cout << ans << endl;

}
