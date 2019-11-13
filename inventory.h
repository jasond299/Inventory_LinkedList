#include <iostream>
#include <string>
#include <fstream>
#include "item.h"

#ifndef _INVENTORY_H

class Node {
private:
    Item* _item;
    Node* _next;
public:
    Node(Item*);
    ~Node();
    Item* getItem() const;
    Node* getNext() const;
    void setItem(Item*);
    void setNext(Node*);
};

class Inventory {
private:
    Node* _head;
public:
    Inventory();
    ~Inventory();
    void push_front(Item*);
    Item* front() const;
    bool pop_front();
    Node* findNodeByName(const std::string&) const;
    Node* findNodeByID(const int) const;
    Item* findItemByName(const std::string&) const;
    Item* findItemByID(const int) const;
    int stockIn(const int,const int);
    int stockOut(const int,const int);
    bool addNewItem(Item*);
    bool deleteItem(const int);
    bool isEmpty() const;
    int load(std::istream&);
    void formattedPrint(std::ostream& out);
};








#endif // _INVENTORY_H
