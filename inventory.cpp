#include "inventory.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>

Node::Node(Item* item){              // Node constructor with 1 param Item*
    _item = item;                    //params: Item*
    _next = nullptr;
}

Node::~Node(){                       //Node destructor
    delete _item;
}

Node* Node::getNext() const{         //gets the next node
    return _next;
}

Item* Node::getItem() const{         //gets item in Node
    return _item;
}

void Node::setItem(Item* item){      //sets item in Node
    _item = item;

}

void Node::setNext(Node* next){      //sets next Node
    _next = next;
}

Inventory::Inventory(){              //Inventory default constructor
    _head = nullptr;
}

Inventory::~Inventory(){             //Inventory destructor
    while(isEmpty()==false){
        pop_front();
    }
}

void Inventory::push_front(Item* item){ // adds new Node at the start of the list
    Node* node = new Node(item);        // params: Item*
    node->setNext(_head);
    _head = node;

}
Item* Inventory::front() const{        //returns first item on the list
    if (_head == nullptr)
        return nullptr;
    return _head->getItem();

}
bool Inventory::pop_front(){           //deletes first node in the list
                                       //returns: true if successful, false otherwise
    if (_head == nullptr)
        return false;
    Node* temp = _head;
    _head = _head->getNext() ;
    delete temp;
    return true;
}
Node* Inventory::findNodeByName(const std::string& name) const{  //finds Node from list by the name of item
    Node* i = _head;                                             //params: string
    while (i != nullptr){                                        //returns: Node*, nullptr if name is not found
        if (i->getItem()->getName() == name)
            return i;
        i = i->getNext();
    }
    return nullptr;
}
Node* Inventory::findNodeByID(const int id) const{               //finds Node from list by the id of item
    Node* i = _head;                                             //params: int
    while (i != nullptr){                                        //returns: Node*, nullptr if id is not found
        if (i->getItem()->getID() == id)
            return i;
        i = i->getNext();
    }
    return nullptr;
}
Item* Inventory::findItemByName(const std::string& name) const{  //finds item from list by the id of item
    Node* x = findNodeByName(name);                              //params:string
    if (x == nullptr)                                            //returns: Item*, nullptr if id is not found
        return nullptr;
    return x->getItem();
}
Item* Inventory::findItemByID(const int id) const{             //finds Node from list by the id of item
    Node* x = findNodeByID(id);                                //params: int
    if (x == nullptr)                                          //returns: Item*, nullptr if id is not found
        return nullptr;
    return x->getItem();
}
int Inventory::stockIn(const int id,const int quan){           //search for an item with the id and add the quantity by quan
    Item* x = findItemByID(id);                                //params: int id, int quantity
    if (x == nullptr)                                          //returns updated quantity of item, -1 if item is not found
        return -1;
    int q = x->getQuantity();
    q += quan;
    x->setQuantity(q);
    return q;
}
int Inventory::stockOut(const int id,const int quan){          //search for an item with the id and decrease the quantity by quan
    Item* x = findItemByID(id);                                //params: int id, int quantity
    if (x == nullptr)                                          //returns the number of quantity that is taken, -1 if item is not found
        return -1;
    int q = x->getQuantity();
    if (q > quan){
        q -= quan;
        x->setQuantity(q);
        return quan;
    }
    else{
        x->setQuantity(0);
        return q;
    }
}
bool Inventory::addNewItem(Item* item){                           //adds Node with new item at the start of the list, id of item must be unique otherwise fails to add
    if (findItemByID(item->getID()) != nullptr)                   //params: Item*
        return false;                                             //return true if successful, false if failed
    push_front(item);
    return true;
}
bool Inventory::deleteItem(const int id){                         //deletes Node with item that contains the given id
    Node* x = findNodeByID(id);                                   //params: id
    if (x == nullptr)                                             //returns true if successful, false if item is not found
        return false;
    Item* temp = x->getItem();
    x->setItem(_head->getItem());
    _head->setItem(temp);
    pop_front();
    return true;

}
bool Inventory::isEmpty() const{                                 //checks whether the inventory list is empty or not
    if (_head == nullptr)                                        //returns true if empty, false otherwise
        return true;
    return false;
}
int Inventory::load(std::istream& fin){                          //load the Inventory list with data from the given istream input
    int id;                                                      //params: istream
    std::string name;                                            //returns the number of items added
    double price;
    int quantity;
    int record = 0;
    while (fin >> id){
        fin >> name;
        fin >> price;
        fin >> quantity;
        if (findItemByID(id) != nullptr)
            continue;
        Item* item = new Item(id, name,price,quantity);
        addNewItem(item);
        record++;
    }
    return record;
}
void Inventory::formattedPrint(std::ostream& out){                        //prints the formatted list in Inventory to the given ostream
    Node* i = _head;                                                      //params: ostream
    Item* item;
    while (i != nullptr){
        item = i->getItem();
        out << std::left << std::fixed << std::setprecision(2);
        out << std::setw(6) << item->getID();
        out << std::setw(12) << item->getName();
        out << std::setw(8) << item->getPrice();
        out << std::setw(4) << item->getQuantity() << std::endl;
        i = i->getNext();
    }
}
