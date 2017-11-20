//
//  Zoo.h
//  ZooPark
//
//  Created by Tatyana Volkorezova on 20.11.2017.
//  Copyright © 2017 shpp.com. All rights reserved.
//
#include "Animals.h"
#ifndef Zoo_h
#define Zoo_h
#define NUMBER_OF_ANIMALS 100

class Zoo {
private:
    Animal* animals[NUMBER_OF_ANIMALS];
public:
    Zoo() {};
    ~Zoo() { for (int i=0; i<NUMBER_OF_ANIMALS; i++) delete animals[i]; }
    void addNewAnimal();//adding new animal to zoo
    void showPopulation(); //to show all info about all animal
    void deleteAnimal(string deleted_name); //delete animal using name
    void showAboutInfo(string shown_name);//to show info about selected animal using name
    void editAnimalInfo(string edit_name);//edit info for selected
};

//adding new animal to zoo
void Zoo::addNewAnimal() {
    int i;
    int age;
    string kind;
    string name;
    int pawsNum;
    int isShow;
    
    //find free element
    for (i = 0 ; animals[i] != nullptr ; i++);
    
    if (i > 100)
    {
        cout<<">>>>Animal was not sussecfully added to zoo ( No space )<<<<\n"<<std::endl;
        return;
    }
    
    animals[i] = new Animal();
    cout << "Enter age: ";
    cin >> age;
    animals[i]->setAge(age);
    
    cout << "Enter kind: ";
    getline(cin, kind);
    getline(cin, kind);
    animals[i]->setKind(kind);
    
    cout << "Enter name: ";
    getline(cin, name);
    animals[i]->setName(name);
    
    cout << "Enter number of paws: ";
    cin >> pawsNum;
    animals[i]->setPawsNum(pawsNum);
    
    animals[i]->setHealth();
    cout << "Health was set to: " <<animals[i]->getHealth()<<endl;
    
    cout << "Enter isShown (1-yes / 0-no): ";
    cin>>isShow;
    animals[i]->setIsShow(isShow);
    
    cout<<">>>>Animal was sussecfully added to zoo<<<<\n"<<std::endl;
};

//to show all info about animal
void Zoo::showPopulation() {
    bool res = false;
    for (int i = 0 ; i < NUMBER_OF_ANIMALS ; i++)
        if (animals[i] != nullptr){
            cout << "Age: "<< animals[i]->getAge();
            cout << "; Kind: "<< animals[i]->getKind();
            cout << "; Name: "<< animals[i]->getName();
            cout << "; Number of paws: "<< animals[i]->getPawsNum();
            cout << "; Health: "<< animals[i]->getHealth();
            cout << "; Is animal present in zoo?: "<< animals[i]->getIsShow()<<endl;
            cout<<endl;
            res = true;
        }
    if (res != true)
        cout << "Animal not found...\n\n";
};

//delete animal using name of animal
void Zoo::deleteAnimal(string deleted_name) {
    bool res = false;
    for (int i = 0 ; i < NUMBER_OF_ANIMALS ; i++)
        if (animals[i] != nullptr)
            if (animals[i]->getName().compare(deleted_name) == 0)  {
                delete animals[i];
                animals[i] = nullptr;
                res = true;
                cout<<">>>>>Animal was succesfully deleted<<<<<\n\n";
            }
    if (res == false)
        cout << "Not found...\n\n";
};

//show info about selected animal
void Zoo::showAboutInfo(string shown_name){
    bool res = false;
    for (int i = 0 ; i < NUMBER_OF_ANIMALS ; i++)
        if (animals[i] != nullptr)
        {
            if (animals[i]->getName().compare(shown_name) == 0) {
                cout << "Age: "<< animals[i]->getAge();
                cout << "; Kind: "<< animals[i]->getKind();
                cout << "; Name: "<< animals[i]->getName();
                cout << "; Number of paws: "<< animals[i]->getPawsNum();
                cout << "; Health: "<< animals[i]->getHealth();
                cout << "; Is animal present in zoo?: "<< animals[i]->getIsShow()<<endl;
                res = true;
                
            }
        }
    if (res == false)
        cout << "Not found...\n\n";
};

//edit info about selected animal
void Zoo::editAnimalInfo(string edit_name){
    bool res = false;
    int age;
    string kind;
    string name;
    int pawsNum;
    int isShow;
    
    for (int i = 0 ; i < NUMBER_OF_ANIMALS ; i++)
        if (animals[i] != nullptr)
            if (animals[i]->getName().compare(edit_name) == 0) {
                cout << "Enter new age: ";
                cin>> age;
                animals[i]->setAge(age);
                
                cout << "Enter kind: ";
                getline(cin, kind);
                getline(cin, kind);
                animals[i]->setKind(kind);
                
                cout << "Enter name: ";
                getline(cin, name);
                animals[i]->setName(name);
                
                cout << "Enter number of paws: ";
                cin >> pawsNum;
                animals[i]->setPawsNum(pawsNum);
                
                cout << "Enter isShown (1-yes / 0-no): ";
                cin>>isShow;
                animals[i]->setIsShow(isShow);
                res = true;
            }
    if (res == false)
        cout << "Not found...\n\n";
};

#endif /* Zoo_h */
