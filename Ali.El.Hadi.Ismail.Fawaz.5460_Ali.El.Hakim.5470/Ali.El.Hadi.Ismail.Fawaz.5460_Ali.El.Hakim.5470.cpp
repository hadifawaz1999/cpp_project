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

int main()
{
    inventory a;
    a.load();
    a.save();
    cout<<a.getUnitCount()<<endl<<a.getInventoryValue();
    return 0;
}

product::product()
{
    name="unknown";
    id=-1;
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
void product::changelocation(loc c)
{
    block=c.block;
    shelf=c.shelf;
}
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

inventory::inventory()
{
    size=0;
}

void inventory::load()
{
    ifstream f;
    f.open("data.txt");
    string s;
    int ID,q;
    loc l;
    bool t;
    int first;
    float second;
    bool flag;
    f>>s>>ID>>q>>l.block>>l.shelf>>t>>first>>second>>flag;
    while(!f.eof())
    {
        list[size]=new product(s,ID,q,l.block,l.shelf,t);
        if(t) list[size]->setters_solids(first,second,flag);
        else list[size]->setters_liquids(first,second,flag);
        size+=1;
        f>>s>>ID>>q>>l.block>>l.shelf>>t>>first>>second>>flag;
    }
    f.close();
}

void inventory::save()
{
    ofstream f;
    f.open("results.txt",ios::out | ios::trunc);
    for(int i=0;i<size;i++)
    {
        f<<list[i]->getname()<<" "<<list[i]->getid()<<" "<<list[i]->getquantity()<<" "<<list[i]->getlocation().block<<" "<<list[i]->getlocation().shelf<<" "<<list[i]->gettype()<<" ";
        if(list[i]->gettype()) f<<list[i]->getnum_pieces()<<" "<<list[i]->getprice_per_piece()<<" "<<list[i]->isfragile()<<endl;
        else f<<list[i]->getammount_in_liters()<<" "<<list[i]->getprice_per_liter()<<" "<<list[i]->isflammable()<<endl;
    }
    f.close();
}

void inventory::removeProduct(int x)
{
    int index=-1;
    for(int i=0;i<size;i++) if(list[i]->getid()==x) {index=i; break;}
    if(index==-1) cout<<"Product with ID:"<<x<<" is not found!."<<endl;
    else if(index==size-1)
    {
        size-=1;
        delete(list[index]);
    }
    else
    {
        for(int i=index;i<size-1;i++) list[i]=list[i+1];
        size-=1;
    }
}

void inventory::add(product& p)
{
    list[size]=new product(p.getname(),p.getid(),p.getquantity(),p.getlocation().block,p.getlocation().shelf,p.gettype());
    if(p.gettype()) list[size]->setters_solids(p.getnum_pieces(),p.getprice_per_piece(),p.isfragile());
    else list[size]->setters_liquids(p.getammount_in_liters(),p.getprice_per_liter(),p.isflammable());
    size+=1;
}

int inventory::getnewID()
{

    srand(time(0));
    int ID=rand()%1000+1;
    while(1)
    {
        int test=1;
        for(int i=0;i<size;i++) if(list[i]->getid()==ID) {test=0; break;}
        if(test) break;
        srand(time(0));
        int ID=rand()%1000+1;
    }
    return ID;
}

int inventory::getProductCount(product& p)
{
    int index=-1;
    for(int i=0;i<size;i++) if(list[i]->getid()==p.getid()) {index=i; break;}
    if(index==-1) return 0;
    return list[index]->getquantity();
}

int inventory::getUnitCount()
{
    int sum=0;
    for(int i=0;i<size;i++) sum+=list[i]->getquantity();
    return sum;
}

float inventory::getInventoryValue()
{
    float sum=0;
    for(int i=0;i<size;i++) sum+=list[i]->calculate_total_price();
    return sum;
}

void inventory::clearInventory()
{
    for(int i=0;i<size;i++) delete(list[i]);
    delete [] list;
}