#include <set>
#include <cstdio>
#include <cctype>

int main(){
    std::set<char> wrong;
    char ch;
    while((ch=getchar())!='\n'){
        wrong.insert(ch);
    }
    while((ch=getchar())!='\n'){
        if(isupper(ch)){
            if(wrong.find('+')!=wrong.end()){
                continue;
            }
        }
        if(isalpha(ch)){
            if(wrong.find(toupper(ch))!=wrong.end()){
                continue;
            }
        }
        if(wrong.find(ch)!=wrong.end()){
            continue;
        }
        putchar(ch);
    }
    putchar('\n');
    return 0;
}