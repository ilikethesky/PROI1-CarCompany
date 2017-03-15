#include "ClassMenu.h"
#include <stdio.h>
#include <cstdlib>

#ifdef _WIN32
#define CLEAR "cls"
#else //In any other OS
#define CLEAR "clear"
#endif

void Menu::printMainMenu() {
    std::cout << "Enter: \n 1 to show cars\n2 to create new car\n3 to delete a car\n4 to change a car\n5 to send a car on the road\n6 to send a car to service" << std::endl;
    std::cout << "7 to get a car back from the service\n8 to get a car back from the road\n9 to refuel a car\n0 to exit" << std::endl;
}
void Menu::printInfoMenu() {
    std::cout << "Enter:\n1 to print info about all cars\n2 to find broken cars\n3 to find cars on the road\n4 to find cars in service\n5to find cars that are ready to use" << std::endl;
    std::cout << "6 to find cars that needs refuelling\n0 to return to main menu" << std::endl;
}
void Menu::printChangeMenu() {
    std::cout << "Enter:\n1 to change number of packages\n2 to change mileage\n0 to return to main menu" << std::endl;
}

int Menu::enterNr() {
    int i = 0;
     char n[30];
     int finalnumber = 0;
     int multiplier = 1;
     fgets(n, 30, stdin);
     for(i = 0; i<30; i++) {
        if(n[i] == '\n') break;
        else if(n[i] < '0' || n[i] >'9') return -1;
     }
     for(i = i-1; i>=0; i--) {
        finalnumber += (n[i] - '0')*multiplier;
        multiplier *= 10;
     }
     return finalnumber;
}
void Menu::pressEnter() {
    int c;
    std::cout << "Press enter to continue ";
    c = getchar();
    while(c != '\n') c = getchar();
}

int Menu::returnChar(char *tab, int maximum) {
    int i;
    int c;
    while(1) {
        c = getchar();
        for(i = 0; i < maximum; i++) if(tab[i] == c) return c;
    }
}

void Menu::createNewCar() {
    int mileage, nSend, tankCapacity, nofCondition;
    std::cout << "Enter mileage: "; mileage = enterNr(); std::system(CLEAR);
    std::cout << "Enter number of packages in this car: "; nSend = enterNr(); std::system(CLEAR);
    std::cout << "Enter tank capacity: "; tankCapacity = enterNr(); std::system(CLEAR);
    std::cout << "Enter car's condition: \n0) on the road\n1) ready to use\n2) in the service\n"; nofCondition = enterNr(); std::system(CLEAR);
    if(mileage == -1 || nSend == -1 || tankCapacity == -1 || nofCondition < 0 || nofCondition > 2) {
        std::cout << "There was an error. Creating new car was stopped" << std::endl;
        Menu::pressEnter();
        std::system(CLEAR);
        return;
    }
    Car::Condition condition = (Car::Condition)nofCondition;
    Car car(nSend, mileage, tankCapacity, condition);
    current_ + car;
    std::cout << "Car created succesfully" << std::endl;
    Menu::pressEnter();
    std::system(CLEAR);
}

void Menu::SelectMainMenu() {
    int user_char;
    char tab[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    int lenght = 10;

    while(1) {
        std::system(CLEAR);
        Menu::printMainMenu();
        user_char = Menu::returnChar(tab, lenght);
        getchar(); // clean '\n' from the buffer
        std::system(CLEAR);
        switch(user_char) {
            case '1':
                Menu::SelectInfoMenu();
                break;
            case '2':
                Menu::createNewCar();
                break;
            case '3':
                //not implemented
                break;
            case '4':
                Menu::SelectChangeMenu();
                break;
            case '5':
                break;
            case '6':
                break;
            case '7':
                break;
            case '8':
                break;
            case '9':
                break;
            case '0':
                //czyszczenie pamieci
                break;
        }
        std::system(CLEAR);
    }
}

void Menu::SelectInfoMenu() {
    int user_char;
    char tab[] = {'1', '2', '3', '4', '5', '6', '0'};
    int lenght = 7;
    std::system(CLEAR);
    Menu::printInfoMenu();
    user_char = Menu::returnChar(tab, lenght);
    getchar(); // clean '\n' from the buffer
    std::system(CLEAR);

    switch(user_char) {
        case '1':
            CarCompany::printAllCars();
            break;
        case '2':
            CarCompany::printBrokenCars();
            break;
        case '3':
            CarCompany::printCars(Car::onTheRoad);
            break;
        case '4':
            CarCompany::printCars(Car::inService);
            break;
        case '5':
            CarCompany::printCars(Car::readyToUse);
            break;
        case '6':
            CarCompany::printCarsToRefuel();
            break;
        case '0':
            return;
    }
    Menu::pressEnter();
}

void Menu::SelectChangeMenu() {
}
