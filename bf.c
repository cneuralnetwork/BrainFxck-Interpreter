#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define len 65535

static int ptr;
static char mem[len];

void bf(const char* code){
    int code_len=strlen(code);
    int cnt=0;
    for(int i=0;i<code_len;i++){
        switch(code[i]){
            case '>':
                if(ptr==len-1) ptr=0;
                else ptr=ptr+1;
                break;
            case '<':
                if(ptr==0) ptr=len-1;
                else ptr=ptr-1;
                break;
            case '+':
                mem[ptr]++;
                break;
            case '-':
                mem[ptr]--;
                break;
            case '.':
                putchar(mem[ptr]);
                break;
            case ',':
                mem[ptr]=getchar();
                break;
            case '[':
                if(mem[ptr]==0){
                    i++;
                    while(cnt>0 || code[i]!=']'){
                        if(code[i]=='[') cnt++;
                        else if(code[i]==']') cnt--;
                        i++;
                    }
                }
                break;
            case ']':
                if(mem[ptr]!=0){
                    i--;
                    while(cnt>0 || code[i]!='['){
                        if(code[i]==']') cnt++;
                        else if(code[i]=='[') cnt--;
                        i--;
                    }
                }
                break;
        }
    }
}

int main(){
    char code[10000];
    printf("Enter the code :\n");
    fgets(code,sizeof(code),stdin);
    code[strcspn(code,"\n")]=0;
    printf("Output :\n");
    bf(code);
    return 0;
}
