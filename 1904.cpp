#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;

    long int M[N+1];
    if(2 < N){
        M[1] = 1;
        M[2] = 2;

        int n = 3;
        while(n <= N){
            M[n] = (M[n-1] + M[n-2]) % 15746;
            n++;
        }

        cout << M[N];
    }else{
        if(N == 1)
            cout << "1";
        else if(N == 2){
            cout << "2";
        }
    }
    return 0;
}