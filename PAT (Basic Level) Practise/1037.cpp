#include<cstdio>
#include<utility>
struct magic_money{
    int galleon;
    int sickle;
    int knut;
    bool operator<(const magic_money &rhs){
        if(this->galleon!=rhs.galleon){
            return this->galleon<rhs.galleon;
        }else if(this->sickle!=rhs.sickle){
            return this->sickle<rhs.sickle;
        }else{
            return this->knut<rhs.knut;
        }
    }
};
int main(){
    magic_money p,a;
    scanf("%d.%d.%d %d.%d.%d",
    &p.galleon,&p.sickle,&p.knut,&a.galleon,&a.sickle,&a.knut);
    if(a<p){
        printf("-");
        std::swap(p,a);
    }
    a.knut-=p.knut;
    if(a.knut<0){
        --a.sickle;
        a.knut+=29;
    }
    a.sickle-=p.sickle;
    if(a.sickle<0){
        --a.galleon;
        a.sickle+=17;
    }
    a.galleon-=p.galleon;
    printf("%d.%d.%d\n",a.galleon,a.sickle,a.knut);
    return 0;
}