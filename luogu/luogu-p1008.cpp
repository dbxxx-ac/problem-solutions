#include <cstdio>
int gf(int x){
    return x/100;
}

int gm(int x){
    return x/10%10;
}

int gl(int x){
    return x%10;
}
int main(){
    for(int i=123,j,k;i<=333;i++){
        j=i*2;k=i*3;
        if( gf(i)+gm(i)+gl(i)+gf(j)+gm(j)+gl(j)+gf(k)+gm(k)+gl(k)==45&&
            gf(i)*gm(i)*gl(i)*gf(j)*gm(j)*gl(j)*gf(k)*gm(k)*gl(k)==362880)
            printf("%d %d %d\n",i,j,k);
    }
}