#include <iostream>
using namespace std;

int main(){
    long int n, m1, m2, r;
    m1 = 0;
    m2 = 1;
    r = 1;

    cin >> n;
    if(n == 0)
        r = 0;

    for(int i = 1; i < n; i++){
        r = m1 + m2;
        m1 = m2;
        m2 = r;
    }

    cout << r;

    return 0;
}
