#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int N, M;
int pos[1005];
int dp[1005][1005];
int opt[1005][1005];
int INF = 0x3f3f3f3f;

int main() {
    cin >> N >> M;
    for (int i=1; i<=M; i++){
        scanf("%d", &pos[i]);
    }
    memset(dp, INF, sizeof(dp));
    pos[0] = 0;
    pos[M+1] = N;
    for (int len=0; len<=M+1; len++){
        for (int i=0; i+len<=M+1; i++){
            if (len <= 1){
                dp[i][i+len] = 0;
                opt[i][i+len] = i;
                continue;
            }
            for (int j=opt[i][i+len-1]; j<=opt[i+1][i+len]; j++){
                int best = dp[i][j] + dp[j][i+len] + pos[i+len] - pos[i];
                if (best < dp[i][i+len]){
                    dp[i][i+len] = best;
                    opt[i][i+len] = j;
                }
            }
        }
    }

    cout << dp[0][M+1] << endl;
    return 0;
}
