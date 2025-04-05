// Title : 단어의 개수
// Link  : https://www.acmicpc.net/problem/1152 
// Time  : 8 ms
// Memory: 1968 KB

// 질문글 확인용
// https://www.acmicpc.net/board/view/158135#post

#include <stdio.h>
#include <string.h>

int main() {
    char str[1000005];
    int len, count, i;
    count = 0;

    
    fgets(str,1000005,stdin);
    len = strlen(str)-1;//
    for(i=0;i<len+1;i++){
        if(str[i]==' '){
            count++;
        }
    }
    
    if(str[0]==' '&&str[len-1]==' '){
        --count;
    }
    if(str[0]!=' '&&str[len-1]!=' '){
        ++count;
    }
    printf("%d",count);
}