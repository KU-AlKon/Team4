#include <iostream>
#include <algorithm>
#include <vector>

#define fastIo cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)

using namespace std;
#define MAX 2020
#define INF 2100000000

int dp[MAX][MAX];
int N;
int arr[MAX];
int result;

int main() {
    fastIo;

    //입력
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i <= N; i++)
        for (int j = 0; j <= N; j++)
            dp[i][j] = INF;

    dp[1][0] = 0;
    dp[0][1] = 0;
    for (int i = 0; i <= N; ++i) {
        for (int j = 0; j <= N; ++j) {
            if(i == j) continue;
            int next = max(i, j) + 1;

            if (j == 0 || i == 0) arr[0] = arr[next];
            dp[next][j] = min(dp[next][j], dp[i][j] + abs(arr[next] - arr[i]));
            dp[i][next] = min(dp[i][next], dp[i][j] + abs(arr[next] - arr[j]));

        }
    }

    result = INF;
    for (int i = 0; i <= N - 1; ++i) {
        result = min(result, dp[N][i]);
        result = min(result, dp[i][N]);
    }

    //출력
    cout << result;
}