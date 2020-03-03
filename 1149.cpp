#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, input;
    cin >> N;

    int arr[N][3];


    for(int i = 0; i < N; i++){
        cin >> input;
        arr[i][0] = input;
        cin >> input;
        arr[i][1] = input;
        cin >> input;
        arr[i][2] = input;
    }


    int result[3] = {0,}, min = 0, color = 0;
    for(int c = 0; c < 3; c++){
        color = c;
        for(int i = 0; i < N; i++){
            min = 1001;
            if(min > arr[i][0] && color != 0) {
                min = arr[i][0];
                color = 0;
            }else if(min > arr[i][1] && color != 1) {
                min = arr[i][1];
                color = 1;
            }else if(min >> arr[i][2] && color != 2) {
                min = arr[i][2];
                color = 2;
            }

            result[c] += min;
        }
    }

    min = result[0];
    for(int i = 1; i < 3; i++){
        if(min > result[i])
            min = result[i];
    }
    cout << min;

    return 0;
}