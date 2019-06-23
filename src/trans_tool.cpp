#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main(int argc, char** argv) {
    FILE * fpr;
    FILE * fpw;
    while(1) {
        if((fpw = fopen(argv[2], "w")) == NULL)
            cout<<"Output File Created Error!"<<endl;
        else if((fpr = fopen(argv[1], "r")) == NULL)
            cout<<"Can Not Find Input File!"<<endl;
        else break;
    }
    char s;
    bool trimSpace=true;
    // 用于压缩多个空格
    while(1) {
        s = fgetc(fpr);
        
        // 结束判断
        if (s == EOF) {
            fputc(10, fpw);
            fputc(s, fpw);
            break;
        }
        
        // 换行变空格
        if (s == 10 || s == 13) {
            if (!trimSpace) {
                fputc(32, fpw);
                trimSpace=true;
            }
            continue;
        }
        
        // 句尾换行
        if (s == '.') {
            fputc(s, fpw);
            fputc(10, fpw);
            trimSpace = true;
            continue;
        }
        
        // 开始压缩空格
        if (s == 32 && !trimSpace) {
            fputc(s, fpw);
            trimSpace = true;
            continue;
        }
        
        // 正常处理
        if (!(s ==32 && trimSpace)){
            fputc(s, fpw);
            trimSpace = false;
        }
    }
    fclose(fpr);
    fclose(fpw);
    return 0;
}
