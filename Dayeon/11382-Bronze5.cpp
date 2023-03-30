#include <iostream>
#include <algorithm>


using namespace std;

/*
 struct dot{
    int x;
    int y;
};

bool compare(const dot& a, const dot& b){
    if(a.x<b.x){
        return true;
    }
    else if(a.x==b.x){
        if(a.y<b.y) {
            return a.y < b.y;
        }
    }
    else{
        return false;
    }
}

int main() {

    int dotNum;
    cin>>dotNum;

    dot dotArr[dotNum];
    for (int i = 0; i < dotNum; i++) {
        cin >> dotArr[i].x >> dotArr[i].y;
    }

    sort(dotArr, dotArr+dotNum, compare );


    for (int i = 0; i < dotNum; i++) {
        cout << dotArr[i].x << " " << dotArr[i].y<<endl;
    }
    return 0;
}
*/

int main(){
    long long a, b, c;
    cin>>a>>b>>c;

    cout<<(a+b+c);

    return 0;
}