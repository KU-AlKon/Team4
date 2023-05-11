#include <iostream>
#include <algorithm>

#define fastIo cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)

using namespace std;

int arr[1000001];
int N;
int minValue;

int fun(int target) {
    //1이면 0 반환
    if (target == 1) {
        return 0;
    }

    //기록이 있으면 반환
    if (arr[target] != 0) {
        return arr[target];
    }

    minValue = fun(target - 1);

    //3의 배수
    if (target % 3 == 0) {
        minValue = min(minValue, fun(target / 3));
    }

    //2의 배수
    if (target % 2 == 0) {
        minValue = min(minValue, fun(target / 2));
    }

    //배열에 저장
    arr[target] = minValue + 1;

    return arr[target];
}

int main() {
    fastIo;

    //입력
    cin >> N;

    fun(N);

    cout << arr[N];
}