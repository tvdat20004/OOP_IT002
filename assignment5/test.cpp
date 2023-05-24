#include <bits/stdc++.h>
using namespace std;
static int maxHP = 0;
static int HP = 0;
class VuKhi{
    public:
        float id_satthuong;
        int luotdung;
        VuKhi(){}
        virtual float Calsatthuong() = 0;
        virtual void Input(){
            cin >> id_satthuong >> luotdung;
        }
};

class Dao : public VuKhi {
    public:
        float chieudai;
        virtual void Input(){
            VuKhi::Input();
            cin >> chieudai;
        }
        virtual float Calsatthuong(){
            luotdung--;
            return id_satthuong * chieudai;
        }
};

class CungTen : public VuKhi {
    public:
        float somuiten;
        virtual void Input(){
            VuKhi :: Input();
            cin >> somuiten;
        }
        virtual float Calsatthuong(){
            luotdung -= 2;
            return (id_satthuong*somuiten)/2;
        }
};

class TayKhong : public VuKhi {
    public:
        // TayKhong(){
        //     luotdung = 10000000;
        // }
        virtual float Calsatthuong(){
            HP -= float(maxHP)*0.1;
            return maxHP % 10;
        }
};


class ThuDu {
    public:
        float id_HP;
        int satthuong;
        // bool status;
        virtual void Input(){
            cin >> id_HP >> satthuong;
        }
        virtual float decreaseHP(float HPgiam){
            return id_HP -= HPgiam;
        }
        virtual bool Chetchua(){
            // if (id_HP <= 0) status = false;
            // else status = true;
            return(id_HP <= 0);
        }
        virtual float Calthuong() = 0;
};

class Bo:public ThuDu{
    public:
        int solan;
        virtual void Input(){
            ThuDu :: Input();
            cin >> solan;
        }
        virtual bool Chetchua(){
            this->solan -= 1;
            // if (solan <= 0 || id_HP <= 0) status =false;
            // else status = true;
            return(solan <= 0 || id_HP <= 0);
        }
        virtual float Calthuong(){
            return this->satthuong;
        }
};

class Ho:public ThuDu{
    public:
        virtual float Calthuong(){
            return (float)1.5*satthuong;
        }
};

int main(){
    cin >> maxHP;
    HP = maxHP;
    int n;
    cin >> n;
    VuKhi **vukhi = new VuKhi *[n+1];
    for(int i = 0; i < n; i++){
        int type;
        cin >> type;
        if(type == 1 ) vukhi[i] = new Dao;
        if (type == 2 ) vukhi[i] = new CungTen;
        vukhi[i]->Input();
        
    }
    vukhi[n] = new TayKhong;
    int m; 
    cin >> m;
    ThuDu **thudu = new ThuDu *[m];
    for(int i = 0; i < m; i++){
        int type; cin >> type;
        if(type == 1) thudu[i] = new Bo;
        else if(type == 2) thudu[i] =  new Ho;
        thudu[i]->Input();
    }

    int idxThu = 0;
    int idxVukhi = 0;
    if(m == 0){
        cout << "A Phu chien thang, hp con lai: " << HP << ", so vu khi con lai: " << n - idxVukhi << endl;
        exit(0);
    } 
    while(idxThu < m && idxVukhi < n+1 && HP > 0){
        float _satthuong = vukhi[idxVukhi]->Calsatthuong();
        if(vukhi[idxVukhi]->luotdung <= 0) idxVukhi++;
        thudu[idxThu]->decreaseHP(_satthuong);
        
        if(!(thudu[idxThu]->Chetchua())) HP -= thudu[idxThu]->Calthuong();
        else  idxThu++;
        if(HP <=0) {
            cout << "A Phu that bai, so thu du con lai: " << m - idxThu << endl;
            break;
        }
        if(idxThu == m){
            cout << "A Phu chien thang, hp con lai: " << HP << ", so vu khi con lai: " << n - idxVukhi << endl;
            break;
        }
    }
}