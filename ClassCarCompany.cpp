#include "ClassCarCompany.h"

    void CarCompany::printAllCars() {
        CarCompany::printCars(Car::onTheRoad);
        CarCompany::printCars(Car::readyToUse);
        CarCompany::printCars(Car::inService);
    }

    void CarCompany::printCars(Car::Condition condition) {
        CarList *temp;
        temp = companyCars;
        if(!temp) std::cout << "There are no cars" << std::endl;
        while(temp) {
            if(temp->car.getCondition() == condition) {
                temp->car.getInfo();
                std::cout <<  std::endl;
            }
            temp = temp->next;
        }
    }

    void CarCompany::printBrokenCars() {
        CarList *temp;
        bool sthprinted = 0;
        temp = companyCars;
        if(!temp) std::cout << "There are no cars" << std::endl;
        while(temp) {
            if(temp->car.getIsBroken() == true) {
                temp->car.getInfo();
                std::cout <<  std::endl;
                sthprinted = 1;
            }
            temp = temp->next;
        }
        if(!sthprinted) std::cout << "There are no such cars" << std::endl;
    }

    void CarCompany::printCarsToRefuel() {
        CarList *temp;
        bool sthprinted = 0;
        temp = companyCars;
        if(!temp) std::cout << "There are no cars" << std::endl;
        while(temp) {
            if(temp->car.getNeedsRefueling() == true) {
                temp->car.getInfo();
                std::cout <<  std::endl;
                sthprinted = 1;
            }
            temp = temp->next;
        }
        if(!sthprinted) std::cout << "There are no such cars" << std::endl;
    }

    void CarCompany::operator+(Car x) {
        CarList *temp = companyCars;
        if(!temp) {
            temp = new CarList;
            temp->car = x;
            temp->next = temp->prev = NULL;
            return;
        }
        while(temp->next) temp = temp->next;
        CarList *added = new CarList;
        added->car = x;
        added->next = NULL;
        added->prev = temp;
        temp->next = added;
    }

    void CarCompany::operator-(CarList *x) {
        CarList *next = x->next;
        CarList *prev = x->prev;
        delete x;
        if(next) next->prev = prev;
        if(prev) prev->next = next;
    }

    CarCompany::CarList* CarCompany::findCar(int nr) {
        CarList *temp = companyCars;
        while(temp) {
            if(temp->car.getNr() == nr) return temp;
            temp = temp->next;
        }
        return NULL;
    }

