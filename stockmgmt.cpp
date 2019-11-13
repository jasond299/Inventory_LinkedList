/*
Title: Lab 4 -stockmgmt.cpp
Purpose:Read a list of item records from a file, store them in a Inventory linked list, and perform various operations
Class: CSC 2430 Spring2019
Author: Jason Djajasasmita
*/
#include <iostream>
#include <fstream>
#include <string>
#include <ostream>
#include <iomanip>
#include "inventory.h"

using namespace std;

int main()
{
    ifstream fin;
    string file;
    int record;
    int choice;
    Inventory* inven = new Inventory();
    do {
    cout << "1. Load an Inventory File" << endl;
    cout << "2. List all items" <<endl;
    cout << "3. Search by Name" <<endl;
    cout << "4. Search by ID" <<endl;
    cout << "5. Add a New Item" <<endl;
    cout << "6. Delete Item" <<endl;
    cout << "7. Exit" <<endl;
    cin >> choice;
    if (choice == 7)
        return 0;
    switch (choice){
        case 1:cout << "Input filename:" << endl;
               cin >> file;
               fin.open(file);
               record = inven->load(fin);
               cout << record << " items loaded." << endl;
               fin.close();
               break;
        case 2:if (inven->isEmpty()){
                   cout << "No item" << endl;
                   break;
               }
               cout << left << fixed;
               cout  << setw(6) << "ID" ;
               cout  << setw(12)<< "Name";
               cout   << setw(8)<< "Price";
               cout << setw(4) << "Quantity" << endl;
               inven->formattedPrint(cout);
               break;
        case 3:{
               string name;
               int id;
               int quantity;
               cout << "Input item name:" << endl;
               cin >> name;
               Item* item = inven->findItemByName(name);
               if (item == nullptr){
                    cout << "No such item" << endl;
                    break;
               }
               id = item->getID();
               quantity = item->getQuantity();
               cout << "ID: " << id << ", Quantity: " << quantity << endl;

        }
               break;
        case 4:{
               string name;
               int id;
               int quantity;
               cout << "Input item ID:" << endl;
               cin >> id;
               Item* item = inven->findItemByID(id);
               if (item == nullptr){
                    cout << "No such item" << endl;
                    break;
               }
               name = item->getName();
               quantity = item->getQuantity();
               cout << "Name: " << name << ", Quantity: " << quantity << endl;

        }
               break;
        case 5:{
               string name;
               int id;
               double price;
               int quantity;
               cout << "Input item ID:" << endl;
               cin >> id;
               cout << "Input item name:" << endl;
               cin >> name;
               cout << "Input price:" << endl;
               cin >> price;
               cout << "Input quantity:" << endl;
               cin >> quantity;
               Item* item = new Item(id,name,price,quantity);
               if (inven->addNewItem(item) == false)
                    cout << "Same ID exists, failed to add" << endl;
               else{
                    cout << "Item has been successfully added" << endl;
               }
        }
                break;
        case 6:{
               int id;
               cout << "Input item ID:" << endl;
               cin >> id;
               if (inven->deleteItem(id) == false)
                    cout << "No such item" << endl;
               else
                    cout << "Item has been successfully deleted" << endl;
        }
               break;
    }
    }while(choice != 7);

    return 0;
}
