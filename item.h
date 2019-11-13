
#include <iostream>
#include <string>
#include <fstream>

#ifndef _ITEM_H



class Item{
private:
    int _id;
    std::string _name;
    double _price;
    int _quantity;
public:
    Item(int id, const std::string& name, double price, int quan);
    int getID() const;
    std::string getName() const;
    double getPrice() const;
    int getQuantity() const;
    void setID(int);
    void setName(std::string);
    void setPrice(double);
    void setQuantity(int);


};



#endif // _ITEM_H
