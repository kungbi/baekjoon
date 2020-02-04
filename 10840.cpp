#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <cmath>


using namespace std;

vector<int> Prime;
const int mod = 524287;
vector<pair<int, int>> Hash[mod];
int x, y, len, Nlen, Mlen, now, result = 0;

bool isPrime(int num){
    for(int i = 2; i <= sqrt(num); i++){
        if(num % i == 0)
            return false;
    }
    return true;
}

void getPrime(){
    int count = 0;
    int num = 2;
    while(true){
        if(isPrime(num)){
            Prime.push_back(num);
            ++count;
        }
        ++num;
        if(count == 2000) {
//            cout << num;
            break;
        }
    }
}

void solve(string &N, string &M){
    Nlen = N.length();
    Mlen = M.length();

    for(int i = 0; i < Nlen; i++){
        x = y = 1;
        for(int k = i; k < Nlen; k++){
            len = k-i+1;
            now = N[k] - 'a';

            x = (x*Prime[now]) % mod;
            y = (y*Prime[now+26]) % mod;

            Hash[x].push_back({y, len});
        }
    }

    for(int i = 0; i < Mlen; i++){
        x = y = 1;
        for(int k = i; k < Mlen; k++){
            len = k-i+1;
            now = M[k] - 'a';

            x = (x*Prime[now]) % mod;
            y = (y*Prime[now+26]) % mod;

            bool flag = false;
            for(int j = 0; j < Hash[x].size(); j++){
                if(Hash[x][j] == make_pair(y, len)) {
                    flag = true;
                    break;
                }
            }
            if(flag){
                result = max(len, result);
            }
        }
    }

    cout << result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    getPrime();
    string N, M;
    cin >> N >> M;
    solve(N, M);
    return 0;
}