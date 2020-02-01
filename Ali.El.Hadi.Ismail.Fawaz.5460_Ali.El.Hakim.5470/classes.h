#ifndef START
#define START
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
        //type=true means its solid and liquid otherwise
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
        product();
        product(string,int,int,char,int,bool);
        string getname() const;
        int getid() const;
        int getquantity() const;
        loc getlocation() const;
        bool gettype() const;

        void setname(string);
        void setid(int);
        void changelocation(loc c);
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

class inventory
{
    private:
        product *list[1000];
        int size;
    public:
        inventory();
        void load();
        void save();
        void removeProduct(int);
        void add(product&);
        int getnewID();
        int getProductCount(product&);
        int getUnitCount();
        float getInventoryValue();
        void clearInventory();
};

#endif