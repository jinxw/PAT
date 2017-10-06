#include<iostream>
#include<string>
#include<cctype>    //tolower,isalpha
//#include<cstdlib>   //itoa在gcc 4.9.2里没有
int main(){
    std::string s;
    std::getline(std::cin,s);
    size_t sum=0;
    for(const auto c:s){
        if(isalpha(c)){
            sum+=tolower(c)-'a'+1;
        }
    }
    //长度不超过100000，sum<=2,600,000.二进制22位
    char str[23];
    //itoa(sum,str,2);
    sprintf(str,"%o",sum);
    std::string binary;
    size_t zero=0,one=0;
    for(size_t i=0;str[i]!='\0';++i){
        switch(str[i]){
            case '0':
            binary+="000";
            break;

            case '1':
            binary+="001";
            break;

            case '2':
            binary+="010";
            break;

            case '3':
            binary+="011";
            break;

            case '4':
            binary+="100";
            break;

            case '5':
            binary+="101";
            break;

            case '6':
            binary+="110";
            break;

            case '7':
            binary+="111";
            break;
        }
    }
    bool begin = true;
    for(const auto &c:binary){
        if(c=='1'){
            begin = false;
            ++one;
        }
        if(c=='0'&&begin==false){
            ++zero;
        }
    }
    std::cout<<zero<<" "<<one<<std::endl;
    return 0;
}