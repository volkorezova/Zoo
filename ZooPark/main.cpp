#include <iostream>
#define NUMBER_OF_ANIMALS 100

using namespace std;

class Animal {
public:
    Animal() { name = new char [20]; kind = new char [20]; }
    ~Animal() { delete[] name; delete[] kind; }
    int age;
    char* kind;
    char* name;
    int pawsNum;
    int health = rand() % 100;
    bool isShow = true;
};

class Zoo {
public:
    void addNewAnimal();//adding new animal to zoo
    void showPopulation(); //to show all info about all animal
    void deleteAnimal(char* deleted_name); //delete animal using name
    void showAboutInfo(char* shown_name);//to show info about selected animal using name
    void editAnimalInfo(char* edit_name);//edit info for selected
    
    
    
    Animal *animals[NUMBER_OF_ANIMALS];
};

//adding new animal to zoo
void Zoo::addNewAnimal() {
    int i;
    //find free element
    for (i = 0 ; animals[i] != nullptr ; i++);
    animals[i] = new Animal();
    
    cout << "Enter age: ";
    cin >> animals[i]->age;
    cout << "Enter kind: ";
    cin >> animals[i]->kind;
    cout << "Enter name: ";
    cin >> animals[i]->name;
    cout << "Enter number of paws: ";
    cin >> animals[i]->pawsNum;
    cout<<">>>>Animal was sussecfully added to zoo<<<<\n"<<std::endl;
};

//to show all info about animal
void Zoo::showPopulation() {
    bool res = false;
    for (int i = 0 ; i < NUMBER_OF_ANIMALS ; i++)
        if (animals[i] != nullptr){
            std::cout << "Age: "<< animals[i]->age;
            std::cout << "; Kind: "<< animals[i]->kind;
            std::cout << "; Name: "<< animals[i]->name;
            std::cout << "; Number of paws: "<< animals[i]->pawsNum;
            std::cout << "; Health: "<< animals[i]->health;
            std::cout << "; Is animal present in zoo?: "<< animals[i]->isShow<<std::endl;
            res = true;
        }
    if (res != true)
        std::cout << "Animal not found...\n\n";
};

//delete animal using name of animal
void Zoo::deleteAnimal(char* deleted_name) {
    bool res = false;
    for (int i = 0 ; i < NUMBER_OF_ANIMALS ; i++)
        if (animals[i] != nullptr)
            if (strcmp(animals[i]->name, deleted_name) == 0)  {
                delete animals[i];
                animals[i] = NULL;
                res = true;
                cout<<">>>>>Animal was succesfully deleted<<<<<\n\n";
            }
    if (res == false)
        std::cout << "Not found...\n\n";
    delete[] deleted_name;
};

//show info about selected animal
void Zoo::showAboutInfo(char* shown_name){
    bool res = false;
    for (int i = 0 ; i < NUMBER_OF_ANIMALS ; i++)
        if (animals[i] != nullptr)
            if (strcmp(animals[i]->name, shown_name) == 0) {
                std::cout << "Age: "<< animals[i]->age;
                std::cout << "; Kind: "<< animals[i]->kind;
                std::cout << "; Name: "<< animals[i]->name;
                std::cout << "; Number of paws: "<< animals[i]->pawsNum;
                std::cout << "; Health: "<< animals[i]->health;
                std::cout << "; Is animal present in zoo?: "<< animals[i]->isShow<<std::endl;
                res = true;
                
            }
    if (res == false)
        std::cout << "Not found...\n\n";
    delete[] shown_name;
};

//edit info about selected animal
void Zoo::editAnimalInfo(char* edit_name){
    bool res = false;
    for (int i = 0 ; i < NUMBER_OF_ANIMALS ; i++)
        if (animals[i] != nullptr)
            if (strcmp(animals[i]->name, edit_name) == 0) {
                std::cout << "Enter new age: "; std::cin>>animals[i]->age;
                std::cout << "Enter kind: "; std::cin>>animals[i]->kind;
                std::cout << "Enter name: "; std::cin>>animals[i]->name;
                std::cout << "Enter number of paws: "; std::cin>>animals[i]->pawsNum;
                res = true;
                
            }
    if (res == false)
        std::cout << "Not found...\n\n";
    delete[] edit_name;
    
};

class ZooManager {
public:
    Zoo zoo;
    void showUserMenu();
};

void ZooManager::showUserMenu() {
    int userChoice;
    std::cout<<"Welcome to zoo. Pls choose what do you want to do?"<<endl;
    for (;;){
        std::cout<<"Press 1 - to ADD new animal\nPress 2 - to DELETE animal\nPress 3 - to SHOW info about ALL animals\nPress 4 - to SHOW info about SELECTED animal\nPress 5 - to EDIT info of SELECTED animal\nPress 6 - to EXIT."<<endl;
        std::cin>>userChoice;
        fpurge(stdin);
        switch (userChoice){
            case 1:{
                std::cout<<"You will add new animal to zoo\n"<<endl;
                zoo.addNewAnimal();
                break;
            }
            case 2:{
                std::cout << "You will delete animal from zoo\n  ENTER NAME OF ANIMAL which you want to DELETE: ";
                char* deleted_name = new char[20];
                std::cin >> deleted_name;
                fpurge(stdin);
                zoo.deleteAnimal(deleted_name);
                break;
            }
            case 3:{
                std::cout<<"You will receive info about ALL animals from zoo\n"<<endl;
                zoo.showPopulation();
                break;
            }
            case 4:{
                std::cout<<"You will receive info about selected animal\n  ENTER NAME OF ANIMAL which you want to SEE"<<endl;
                char* shown_name = new char[20];
                std::cin >> shown_name;
                zoo.showAboutInfo(shown_name);
                break;
            }
                
            case 5:{
                std::cout<<"You will EDIT info about some animal from zoo\n  ENTER NAME OF ANIMAL which you want to EDIT"<<endl;
                char* edit_name = new char[20];
                std::cin >> edit_name;
                zoo.editAnimalInfo(edit_name);
                break;
            }
                
                
            case 6:{
                std::cout<<"GOOD BYE\n"<<endl;
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

