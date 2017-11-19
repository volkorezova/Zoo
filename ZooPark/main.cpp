#include <iostream>
#define NUMBER_OF_ANIMALS 100

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

class ZooManager {
public:
    Zoo zoo;
    void showUserMenu();
};

void ZooManager::showUserMenu() {
    int userChoice;
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
                char* deleted_name = new char[20];
                cin >> deleted_name;
                fpurge(stdin);
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
                char* shown_name = new char[20];
                cin >> shown_name;
                zoo.showAboutInfo(shown_name);
                break;
            }
                
            case 5:{
                cout<<"You will EDIT info about some animal from zoo\n  ENTER NAME OF ANIMAL which you want to EDIT"<<endl;
                char* edit_name = new char[20];
                cin >> edit_name;
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

int main(int argc, const char * argv[]) {
    
    ZooManager* manager = new ZooManager();
    manager->showUserMenu();
    return 0;
}

