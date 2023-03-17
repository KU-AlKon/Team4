#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <unordered_set>
#include <set>
#include <unordered_map>
#include <map>
#include <tuple>
#include <cmath>
#include <numeric>
#include <memory.h>

#define MAXINT 2147483647
#define MININT -2147483647
#define MOD 1000000007
using ll = long long;
#define fastio cin.tie(0),cout.tie(0),ios::sync_with_stdio(0)

using namespace std;

int n, total, one[300001];

int main() {
    fastio;

    int grade;
    cin >> grade;
    if (grade >= 90) cout << "A";
    else if (grade >= 80) cout << "B";
    else if (grade >= 70) cout << "C";
    else if (grade >= 60) cout << "D";
    else cout << "F";
}
