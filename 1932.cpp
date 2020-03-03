#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int n, input;

    cin >> n;
    vector<vector<long int>> arr;

    for(int i = 0; i < n; i++){
        vector<long int> vec;

        for(int j = 0; j < i+1; j++){
            cin >> input;
            vec.push_back(input);
        }
        arr.push_back(vec);
    }

    vector<vector<long int>> memory(n, vector<long int>(n));
    long int answer = 0;
    memory[0][0] = arr[0][0];
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(j == 0){
                memory[i][j] = memory[i-1][j] + arr[i][j];
            }else if(i == j){
                memory[i][j] = memory[i-1][j-1] + arr[i][j];
            }else{
                memory[i][j] = max(memory[i-1][j-1] + arr[i][j], memory[i-1][j] + arr[i][j]);
            }

            if(i == n-1){
                answer = max(answer, memory[i][j]);
            }
        }

    }

    cout << answer;
    return 0;
}