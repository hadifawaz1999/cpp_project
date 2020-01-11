#include <bits/stdc++.h>

using namespace std;

typedef struct location
{
    char block;
    int shelf;
}loc;

class product
{
    private:
        string name;
        int id;
        int quantity;
        char block;
        int shelf;
        bool type;

        //for liquid type
        int ammount_in_liters;
        float price_per_liter;
        bool flammable;

        //for solid type
        int num_pieces;
        float price_per_piece;
        bool fragile;
    public:
        product(string,int,int,char,int,bool);
        string getname() const;
        int getid() const;
        int getquantity() const;
        loc getlocation() const;
        bool gettype() const;
        void setname(string);
        void setid(int);
        float calculate_total_price() const;

        //for liquid type
        int getammount_in_liters() const;
        float getprice_per_liter() const;
        bool isflammable() const;
        void setters_liquids(int,float,bool);

        //for solid type
        int getnum_pieces() const;
        float getprice_per_piece() const;
        bool isfragile() const;
        void setters_solids(int,float,bool);
};

int main()
{
    return 0;
}

product::product(string s,int ID,int q,char b,int sh,bool t)
{
    name=s;
    id=ID;
    quantity=q;
    block=b;
    shelf=sh;
    type=t;
}

string product::getname() const {return name;}
int product::getid() const {return id;}
int product::getquantity() const {return quantity;}
loc product::getlocation() const
{
    loc a;
    a.block=block;
    a.shelf=shelf;
    return a;
}
bool product::gettype() const {return type;}
void product::setname(string n) {name=n;}
void product::setid(int ID) {id=ID;}
float product::calculate_total_price() const
{
    if(type) return num_pieces*price_per_piece;
    else return ammount_in_liters*price_per_liter;
}

int product::getammount_in_liters() const {return ammount_in_liters;}
float product::getprice_per_liter() const {return price_per_liter;}
bool product::isflammable() const {return flammable;}
void product::setters_liquids(int amm,float price,bool flam)
{
    ammount_in_liters=amm;
    price_per_liter=price;
    flammable=flam;
}

int product::getnum_pieces() const {return num_pieces;}
float product::getprice_per_piece() const {return price_per_piece;}
bool product::isfragile() const {return fragile;}
void product::setters_solids(int num,float price,bool frag)
{
    num_pieces=num;
    price_per_piece=price;
    fragile=frag;
}