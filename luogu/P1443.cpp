#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int dx[8] = {1, -1, 2, -2, 1, -1, 2, -2};
int dy[8] = {2, 2, 1, 1, -2, -2, -1, -1};
int a[402][402];
int n, m, x, y;
queue<pair<int, int>> q;
void bfs(int x, int y){
    q.push({x, y});
    while(!q.empty()){
        auto [cx, cy] = q.front();
        q.pop();
        for(int i=0; i<8; i++){
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx >= 1 && ny >= 1 && nx <= n && ny <= m){
                if(a[nx][ny] > a[cx][cy] + 1){
                    a[nx][ny] = a[cx][cy] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}
int main(){
    cin >> n >> m >> x >> y;
    memset(a, 0x3f3f3f3f, sizeof(a));
    a[x][y] = 0;
    bfs(x, y);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i][j] == 0x3f3f3f3f) cout << -1 << ' ';
            else cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}