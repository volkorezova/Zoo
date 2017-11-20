//
//  ZooManager.h
//  ZooPark
//
//  Created by Tatyana Volkorezova on 20.11.2017.
//  Copyright © 2017 shpp.com. All rights reserved.
//

#include "Zoo.h"
#ifndef ZooManager_h
#define ZooManager_h

class ZooManager {
public:
    Zoo zoo;
    void showUserMenu();
};

void ZooManager::showUserMenu() {
    int userChoice;
    string shown_name;
    string edit_name;
    string deleted_name;
    
    cout<<"Welcome to zoo. Pls choose what do you want to do?"<<endl;
    for (;;){
        cout<<"Press 1 - to ADD new animal\nPress 2 - to DELETE animal\nPress 3 - to SHOW info about ALL animals\nPress 4 - to SHOW info about SELECTED animal\nPress 5 - to EDIT info of SELECTED animal\nPress 6 - to EXIT."<<endl;
        cin>>userChoice;
        fpurge(stdin);
        switch (userChoice){
            case 1:{
                cout<<"You will add new animal to zoo\n"<<endl;
                zoo.addNewAnimal();
                break;
            }
            case 2:{
                cout << "You will delete animal from zoo\n  ENTER NAME OF ANIMAL which you want to DELETE: ";
                getline(cin, deleted_name);;
                zoo.deleteAnimal(deleted_name);
                break;
            }
            case 3:{
                cout<<"You will receive info about ALL animals from zoo\n"<<endl;
                zoo.showPopulation();
                break;
            }
            case 4:{
                cout<<"You will receive info about selected animal\n  ENTER NAME OF ANIMAL which you want to SEE"<<endl;
                getline(cin, shown_name);
                zoo.showAboutInfo(shown_name);
                break;
            }
                
            case 5:{
                cout<<"You will EDIT info about some animal from zoo\n  ENTER NAME OF ANIMAL which you want to EDIT"<<endl;
                getline(cin, edit_name);
                zoo.editAnimalInfo(edit_name);
                break;
            }
                
            case 6:{
                cout<<"GOOD BYE\n"<<endl;
                return;
            }
            default:{
                cout << "Invalid choice. Try again" << endl;
                return;
            }
        }
    }
};
#endif /* ZooManager_h */
