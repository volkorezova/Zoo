//
//  Animals.h
//  ZooPark
//
//  Created by Tatyana Volkorezova on 20.11.2017.
//  Copyright © 2017 shpp.com. All rights reserved.
//
#include <iostream>
#ifndef Animals_h
#define Animals_h

using namespace std;

class Animal {
private:
    int age;
    string kind;
    string name;
    int pawsNum;
    int health;
    int isShow;
public:
    Animal() {}
    ~Animal() {}
    
    void setAge(int age) { this->age = age; }
    int getAge() { return age; }
    
    void setName(string name){this->name = name;}
    string getName(){return name;}
    
    void setKind(string kind){this->kind = kind;}
    string getKind(){return kind;}
    
    void setPawsNum(int pawsNum){this->pawsNum = pawsNum;}
    int getPawsNum(){return pawsNum;}
    
    void setHealth(){this->health = rand() % 100;}
    int getHealth(){return health;}
    
    void setIsShow(int isShow){
        if (isShow == 1){
            this->isShow=true;
        }else{
            this->isShow=false;
        }
    }
    bool getIsShow(){return isShow;}
};


#endif /* Animals_h */
