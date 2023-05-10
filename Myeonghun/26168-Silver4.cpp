#include <iostream>
#include <algorithm>

#define fastIo cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)

using ull = unsigned long long;
using namespace std;

int N, M;
ull arr[100000];
ull i, j, k;
int type;
int idx;

int findLowestOne(ull target, int begin, int end) {
    if (arr[N - 1] < target) {
        return -1;
    } else if (target < arr[0]) {
        return -2;
    }

    int mid = (begin + end) / 2;

    if (arr[mid] == target) {
        idx = mid;
        while (arr[idx] == target && idx >= 0) {
            --idx;
        }
        return idx + 1;
    }

    else if (arr[mid] > target) {
        if (arr[mid - 1] < target) {
            return mid;
        }
        return findLowestOne(target, begin, mid);
    }
    else if (arr[mid] < target) {
        if (target < arr[mid + 1]) {
            return mid + 1;
        }
        return findLowestOne(target, mid + 1, end);
    }
}

int findHighestOne(ull target, int begin, int end) {
    if (arr[N - 1] < target) {
        return -1;
    } else if (target < arr[0]) {
        return -2;
    }

    int mid = (begin + end) / 2;

    if (arr[mid] == target) {
        idx = mid;
        while (arr[idx] == target && idx < N) {
            ++idx;
        }
        return idx - 1;
    }

    else if (arr[mid] > target) {
        if (arr[mid - 1] < target) {
            return mid - 1;
        }
        return findHighestOne(target, begin, mid);
    }
    else if (arr[mid] < target) {
        if (target < arr[mid + 1]) {
            return mid;
        }
        return findHighestOne(target, mid + 1, end);
    }
}

int main() {
    fastIo;

    //입력
    cin >> N >> M;

    for (int iter = 0; iter < N; ++iter) {
        cin >> arr[iter];
    }

    //정렬
    sort(arr, arr + N);

    for (int iter = 0; iter < M; ++iter) {
        cin >> type;

        if (type == 1) {
            cin >> k;

            //k보다 크거나 같은 원소의 개수
            int lowestIdx = findLowestOne(k, 0, N);

            if (lowestIdx == -1) {
                cout << 0 << '\n';
                continue;
            } else if (lowestIdx == -2) {
                cout << N << '\n';
                continue;
            }

            //k보다 크거나 같은 원소의 개수
            cout << N - lowestIdx << '\n';
        }
        else if (type == 2) {
            cin >> k;

            //k보다 큰 원소의 개수
            int highestIdx = findHighestOne(k, 0, N);

            if (highestIdx == -1) {
                cout << 0 << '\n';
                continue;
            } else if (highestIdx == -2) {
                cout << N << '\n';
                continue;
            }

            //k보다 큰 원소의 개수
            cout << N - highestIdx - 1 << '\n';
        }
        else if (type == 3) {
            cin >> i >> j;

            int lowestIdx = findLowestOne(i, 0, N);
            int highestIdx = findHighestOne(j, 0, N);

            //왼쪽이 왼쪽 범위 넘어갔을 때
            if (lowestIdx == -2) {
                //오른쪽도 왼쪽 범위 넘어갔을 때
                if (highestIdx == -2) {
                    cout << 0 << '\n';
                    continue;
                }
                //오른쪽은 오른쪽 범위 넘어갔을 때
                else if (highestIdx == -1) {
                    cout << N << '\n';
                    continue;
                }
                //오른쪽은 배열 범위 내에 있을 때
                else {
                    cout << highestIdx + 1 << '\n';
                    continue;
                }
            }
            //왼쪽이 오른쪽 범위 넘어갔을 때
            else if (lowestIdx == -1) {
                //오른쪽도 오른쪽 범위 넘어갔을 때
                if (highestIdx == -1) {
                    cout << 0 << '\n';
                    continue;

                }
            }
            //오른쪽이 오른쪽 범위를 넘어갔을 때
            else if (highestIdx == -1) {
                //왼쪽도 오른쪽 범위를 넘어갔을 때
                if (lowestIdx == -1) {
                    cout << 0 << '\n';
                    continue;
                }
                //왼쪽은 범위 내에 있을 때
                else {
                    cout << N - lowestIdx << '\n';
                    continue;
                }
            }

            //i보다 크거나 같고 j보다 작거나 같은 원소의 개수
            cout << highestIdx - lowestIdx + 1 << '\n';
        }
    }
}