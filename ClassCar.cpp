
#include "ClassCar.h"

void Car::setnSendings(unsigned int number) {
    nSendings_ = number;
}
int Car::getnSendings() {
    return nSendings_;
}
void Car::setMileage(unsigned int number) {
    mileage_ = number;
}
int Car::getMileage() {
    return mileage_;
}
int Car::getTankCapacity() {
    return tankCapacity_;
}
int Car::getCondition() {
    return condition_;
}
void Car::setCondition(Condition condition) {
    condition_ = condition;
}
void Car::setIsBroken(bool isBroken) {
    isBroken_ = isBroken;
}
bool Car::getIsBroken() {
    return isBroken_;
}
void Car::setNeedsRefueling(bool needsRefueling) {
    needsRefueling_ = needsRefueling;
}
bool Car::getNeedsRefueling() {
    return needsRefueling_;
}
int Car::getNr() {
    return nr_;
}
void Car::getInfo() {
    std::cout << "Car nr: " << nr_ << std::endl;
    std::cout << "Mileage: " << mileage_ << std::endl;
    std::cout << "Tank capacity: " << tankCapacity_ << std::endl;
    std::cout << "Nr of sendings: " << nSendings_ << std::endl;
    std::cout << "Is broken: " << (isBroken_ ? "Yes" : "No") << std::endl;
    std::cout << "Needs refueling: " << (needsRefueling_ ? "Yes" : "No") << std::endl;
    std::cout << "Current condition: " << conditionNames_[condition_] << std::endl;
}
