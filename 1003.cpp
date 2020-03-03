#include <iostream>
using namespace std;

int main(){
    int M[41] = {0, 1};
    int n = 2;
    while(n <= 40){
        M[n] = M[n-1] + M[n-2];
        n++;
    }

    int T, input;

    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> input;
        if(input == 0){
            cout << "1 0" << endl;
        } else if (input == 1){
            cout << "0 1" << endl;
        } else {
            cout << M[input-1] << " " << M[input] << endl;
        }
    }

}
