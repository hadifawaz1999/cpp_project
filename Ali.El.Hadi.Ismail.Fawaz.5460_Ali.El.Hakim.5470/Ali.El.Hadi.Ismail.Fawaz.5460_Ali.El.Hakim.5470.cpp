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

        //for liquid type
        int getammount_in_liters() const;
        float getprice_per_liter() const;
        bool getflammable() const;

        //for solid type
        int getnum_pieces() const;
        float getprice_per_piece() const;
        bool getfragile() const;
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

int product::getammount_in_liters() const {return ammount_in_liters;}
float product::getprice_per_liter() const {return price_per_liter;}
bool product::getflammable() const {return flammable;}

int product::getnum_pieces() const {return num_pieces;}
float product::getprice_per_piece() const {return price_per_piece;}
bool product::getfragile() const {return fragile;}