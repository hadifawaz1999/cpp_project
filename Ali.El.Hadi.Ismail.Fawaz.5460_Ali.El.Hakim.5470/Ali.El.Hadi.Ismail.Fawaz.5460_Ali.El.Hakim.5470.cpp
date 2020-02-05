#include "classes.h"
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ofstream f;
    string p_name;
    int p_id,p_quantity;
    loc p_loc;
    string input_p_type;
    bool p_type;
    int p_first;
    float p_second;
    string input_is_or_not;
    bool is_or_not;
    string what_to_do;
    do
    {
        cout<<"Is your data ready in data.txt (Yes or No): ";
        cin>>what_to_do;
    }while(what_to_do!="Yes" && what_to_do!="No");
    if(what_to_do == "No")
    {
        f.open("data.txt");
        cout<<"First give us the data."<<endl;
        cout<<"How many product do you want to ship to this inventory?"<<endl;
        int num_p;
        do
        {
            cout<<"number of products (must be positive) = ";
            cin>>num_p;
        } while(num_p<=0);
        for(int i=1;i<=num_p;i++)
        {
            cout<<"Give us the name of the product #"<<i<<": ";
            cin>>p_name;
            f<<p_name<<" ";
            do
            {
                cout<<"Give us the ID of the product (Must be positive): ";
                cin>>p_id;
            } while(p_id<=0);
            f<<p_id<<" ";
            do
            {
                cout<<"Give us the quantity of the product (must be positive): ";
                cin>>p_quantity;
            }while (p_quantity<=0);
            f<<p_quantity<<" ";
            cout<<"Give us which block you want to put the product: ";
            cin>>p_loc.block;
            f<<p_loc.block<<" ";
            do
            {
                cout<<"Give us which shelf you want to put the product (must be positive): ";
                cin>>p_loc.shelf;
            } while (p_loc.shelf<0);
            f<<p_loc.shelf<<" ";
            do
            {
                cout<<"Give us the type of the product (solid or liquid): ";
                cin>>input_p_type;
            } while (input_p_type!="solid" && input_p_type!="liquid");
            if(input_p_type == "solid") f<<1<<" ";
            else f<<0<<" ";
            do
            {
                if(input_p_type == "solid") cout<<"Give us the number of peices and the price per peice of the solid product(must be positive): ";
                else cout<<"Give us the ammount in litters and the price per litter of the liquid product(must be positive): ";
                cin>>p_first>>p_second;
            } while (p_first<=0 || p_second<=0);
            f<<p_first<<" "<<p_second<<" ";
            do
            {
                if(input_p_type == "solid") cout<<"Give us the type of this solid product (fragile or nonfragile): ";
                else cout<<"Give us the type of this liquid product (flammable or nonflammable): ";
                cin>>input_is_or_not;
            } while (input_is_or_not!="flammable" && input_is_or_not!="nonflammable" && input_is_or_not!="fragile" && input_is_or_not!="nonfragile");
            if(input_is_or_not == "flammable" || input_is_or_not=="fragile") f<<1<<endl;
            else f<<0<<endl;
        }
        f.close();
    }
    inventory inv;
    cout<<"Now we create your inventory"<<endl;
    cout<<"You can do any of these operations"<<endl;
    cout<<"1- Load : to load all the inventory products from data.txt to its locsation."<<endl;
    cout<<"2- Save : to save all the inventory data into saved_data.txt ."<<endl;
    cout<<"3- Add : to add a given product to your inventory."<<endl;
    cout<<"4- Remove : to remove a product with its given id."<<endl;
    cout<<"5- Unit_Count : to show you the number of quantities in all your inventory."<<endl;
    cout<<"6- Inventory_Value : to show you the value of your inventory."<<endl;
    cout<<"7- Clear : to clear your inventory."<<endl;
    cout<<"8- Exit : to exit the program."<<endl;
    while (1)
    {
        string choice;
        do
        {
            cout<<"Choose from the list: Load, Save, Add, Remove, Unit_Count, Inventory_Value, Clear or Exit: ";
            cin>>choice;
        } while (choice!="Load" && choice!="Save" && choice!="Add" && choice!="Remove" && choice!="Unit_Count" && choice!="Inventory_Value" && choice!="Clear" && choice!="Exit");

        if(choice == "Load") inv.load();
        else if(choice == "Save") inv.save();
        else if(choice == "Add")
        {
            cout<<"Give us the name of the product: ";
            cin>>p_name;
            do
            {
                cout<<"Give us the ID of the product (Must be positive): ";
                cin>>p_id;
            } while(p_id<=0);
            do
            {
                cout<<"Give us the quantity of the product (must be positive): ";
                cin>>p_quantity;
            }while (p_quantity<=0);
            cout<<"Give us which block you want to put the product: ";
            cin>>p_loc.block;
            do
            {
                cout<<"Give us which shelf you want to put the product (must be positive): ";
                cin>>p_loc.shelf;
            } while (p_loc.shelf<0);
            do
            {
                cout<<"Give us the type of the product (solid or liquid): ";
                cin>>input_p_type;
            } while (input_p_type!="solid" && input_p_type!="liquid");
            if(input_p_type == "solid") p_type=1;
            else p_type=0;
            do
            {
                if(input_p_type == "solid") cout<<"Give us the number of peices and the price per peice of the solid product(must be positive): ";
                else cout<<"Give us the ammount in litters and the price per litter of the liquid product(must be positive): ";
                cin>>p_first>>p_second;
            } while (p_first<=0 || p_second<=0);
            do
            {
                if(input_p_type == "solid") cout<<"Give us the type of this solid product (fragile or nonfragile): ";
                else cout<<"Give us the type of this liquid product (flammable or nonflammable): ";
                cin>>input_is_or_not;
            } while (input_is_or_not!="flammable" && input_is_or_not!="nonflammable" && input_is_or_not!="fragile" && input_is_or_not!="nonfragile");
            if(input_is_or_not == "flammable" || input_is_or_not == "fragile") is_or_not=1;
            else is_or_not=0;
            product p(p_name,p_id,p_quantity,p_loc.block,p_loc.shelf,p_type);
            if(p_type) p.setters_solids(p_first,p_second,is_or_not);
            else p.setters_liquids(p_first,p_second,is_or_not);

            inv.add(p);
        }
        else if(choice == "Remove")
        {
            do
            {
                cout<<"Give us ID to remove (must be positive): ";
                cin>>p_id;
            } while (p_id<=0);
            inv.removeProduct(p_id);
        }
        else if(choice == "Unit_Count") cout<<"Unit count is: "<<inv.getUnitCount()<<endl;
        else if(choice == "Inventory_Value") cout<<"Inventory value is: "<<inv.getInventoryValue()<<endl;
        else if(choice == "Clear") inv.clearInventory();
        else if(choice == "Exit")
        {
            ifstream f;
            ofstream g;
            f.open("saved_data.txt");
            g.open("data.txt",ofstream::trunc);
            
            f>>p_name>>p_id>>p_quantity>>p_loc.block>>p_loc.shelf>>p_type>>p_first>>p_second>>is_or_not;
            while(!f.eof())
            {
                g<<p_name<<" "<<p_id<<" "<<p_quantity<<" "<<p_loc.block<<" "<<p_loc.shelf<<" "<<p_type<<" "<<p_first<<" "<<p_second<<" "<<is_or_not<<endl;
                f>>p_name>>p_id>>p_quantity>>p_loc.block>>p_loc.shelf>>p_type>>p_first>>p_second>>is_or_not;
            }
            f.close();
            g.close();
            break;
        }
    }
    cout<<"Program has ended"<<endl;
    return 0;
}