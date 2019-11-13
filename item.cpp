
#include <iostream>
#include <istream>
#include <string>
#include <iomanip>
#include "item.h"


Item::Item(int id, const std::string& name, double price, int quan){    //Item constructor with 4 parameters id,name,price,quantity
    _id = id;
    _name = name;
    _price = price;
    _quantity = quan;
}

int Item::getID() const{                                                //gets item's id
    return _id;

}

std::string Item::getName() const{                                      //gets item's name
    return _name;
}
double Item::getPrice() const{                                          //gets item's price
    return _price;
}
int Item::getQuantity() const{                                          //gets item's quantity
    return _quantity;
}
void Item::setID(int id){                                               //sets item's id
    _id = id;
}
void Item::setName(std::string name){                                   //sets item's name
    _name = name;
}
void Item::setPrice(double price){                                      //sets item's price
    _price = price;
}
void Item::setQuantity(int quan){                                       //sets item's quantity
    _quantity = quan;
}
