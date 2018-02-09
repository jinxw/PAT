#include <iostream>
#include <vector>
#include <algorithm>

void MergeSort(std::vector<int> &v, int width);
void myprint(std::vector<int> &v);

int main(){
    std::size_t n;
    std::cin>>n;
    std::vector<int> a(n);
    std::vector<int> b(n);
    for(std::size_t i=0;i<n;++i)
        std::cin>>a[i];
    for(std::size_t i=0;i<n;++i)
        std::cin>>b[i];
    int status=1; //1:递增 2：相等 3：不是Insertion
    int flag;
    for(std::size_t i=0;i<n;++i){
        switch(status){
            case 1:
            if(b[i]<=b[i+1]){
                ;
            }else{
                flag = i;
                status = 2;
            }
            break;

            case 2:
            if(a[i]!=b[i]){
                status = 3;
            }
            break;

            case 3:
            break;
        }
    }
    if(status == 2){
        puts("Insertion Sort");
        std::sort(b.begin(),b.begin()+flag+2);
        myprint(b);
    }else{
        puts("Merge Sort");
        int width = 2;
        bool current = false;
        for(;a!=b;width*=2){
            MergeSort(a,width);
        }
        MergeSort(a,width);
        myprint(a);
    }
    return 0;
}

void MergeSort(std::vector<int> &v, int width){
    int i;
    for(i=0;i+width<=v.size();i+=width){
        std::sort(v.begin()+i,v.begin()+i+width);
    }
    std::sort(v.begin()+i,v.end());
}

void myprint(std::vector<int> &v){
    for(auto it=v.cbegin();it!=v.cend();++it){
        if(it!=v.cbegin())
            std::cout<<" ";
        std::cout<<*it;
    }
    std::cout<<std::endl;
}