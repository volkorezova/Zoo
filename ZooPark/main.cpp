#include <iostream>
#include "include/ZooManager.h"
using namespace std;

int main(int argc, const char * argv[]) {
    
    ZooManager* manager = new ZooManager();
    manager->showUserMenu();
    return 0;
}

