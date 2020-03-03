#include <iostream>
using namespace std;

int main(){
    long int M[101] = {1, 1, 1};
    int n = 3;

    while(n <= 100){
        M[n] = M[n-2] + M[n-3];
        n++;
    }

    int T, N;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> N;

        cout << M[N-1] << endl;
    }

    return 0;
}