#include <iostream>

#define fastIo cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)

using namespace std;

int DP[1000000];
int N;

int main() {
    fastIo;

    //입력
    cin >> N;

    for (int i = 2; i <= N; ++i) {
        // 1. 1을 뺀다.
        DP[i] = DP[i - 1] + 1;

        // 2. 2로 나누어지면
        if (i % 2 == 0) {
            DP[i] = min(DP[i], DP[i / 2] + 1);
        }

        // 3. 3으로 나누어지면
        if (i % 3 == 0) {
            DP[i] = min(DP[i], DP[i / 3] + 1);
        }
    }

    cout << DP[N];
}