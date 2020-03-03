#include <stdio.h>

int K, C, M, N, m, n;

int check(){
   if(m != M || n != N)
       return 0;
   else
       return 1;
}

int max(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

int main() {

    scanf("%d", &K);
    scanf("%d", &C);


    for(int c = 0; c < C; c++){
        scanf("%d %d", &M, &N);

        m = 0; n = 0;
        for(int k = 1; k < K+1; k++){
            if(m == max(M, N) || n == max(M, N))
                break;

            if(m+1 <= M)
                m++;

            if(m+K-k < n) {
                break;
            }

            if(n+1 <= N)
                n++;

            if(n+K-k < m) {
                if(!check()) {
                    break;
                }
            }
        }
        if(!check()) {
            printf("0\n");
        }else
            printf("1\n");
    }



    return 0;
}