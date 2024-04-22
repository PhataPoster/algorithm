#include<stdio.h>
int main(){
    char s;
    int count=0;
    scanf("%s",s);
    for(int i=0;i!="\0";i++){
        if(s>"a" && s<"z"){
            count++;
        }
        else 
        printf("-1");
        break;
    }
    printf("%d",count);
}