#include<iostream>
using namespace std;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int a[32][32];
int n;
void dfs(int x, int y){
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < n && ny < n){
            if(a[nx][ny] == 2){
                a[nx][ny] = 0;
                dfs(nx, ny);
            }
        }
    }
}
int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
            if(i && j && i<n-1 && j<n-1)
                if(a[i][j] == 0)
                    a[i][j] = 2;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a[i][j] == 0) dfs(i, j);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}