#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N, M, X;
        cin >> N >> M >> X;
        
        vector<vector<pair<int, int>>> data(N, vector<pair<int, int>>(M));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> data[i][j].first >> data[i][j].second;
            }
        }
        
        // dp[x] 表示使用 x 内存容量时，硬盘的最少读取次数
        vector<long long> dp(X + 1, LLONG_MAX);
        dp[0] = 0;  // 不使用内存时，硬盘的读取次数为 0
        
        // 遍历每道题目
        for (int i = 0; i < N; ++i) {
            // 遍历每组数据
            vector<long long> new_dp = dp;  // 存储更新后的 dp
            long long total_memory = 0;
            long long total_access = 0;
            
            for (int j = 0; j < M; ++j) {
                total_memory += data[i][j].first;
                total_access += data[i][j].second;
                
                // 如果数据存储在硬盘中
                for (int k = X; k >= 0; --k) {
                    if (dp[k] != LLONG_MAX) {
                        new_dp[k] = min(new_dp[k], dp[k] + data[i][j].second);
                    }
                }
                
                // 如果数据存储在内存中
                for (int k = X; k >= total_memory; --k) {
                    if (dp[k - total_memory] != LLONG_MAX) {
                        new_dp[k] = min(new_dp[k], dp[k - total_memory]);
                    }
                }
            }
            dp = new_dp;  // 更新 dp
        }
        
        // 输出最小的硬盘读取次数
        cout << dp[X] << endl;
    }

    return 0;
}
