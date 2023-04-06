#include <iostream>

using ll = long long;
#define fastIo cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)

using namespace std;

int recursive(ll n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (n % 2) {
        return 1 - recursive(n / 2);
    } else {
        return recursive(n / 2);
    }
}

int main() {
    fastIo;

    //입력
    FILE *pFile = freopen("input.txt", "r", stdin);

    ll k;
    cin >> k;

    cout << recursive(k - 1);
}