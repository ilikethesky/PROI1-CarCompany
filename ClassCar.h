#include <cstring>
#include <iostream>

int uniqueNumber = 0;

class Car {
public:
    enum Condition {
        onTheRoad = 0,
        readyToUse = 1,
        inService = 2
    };
private:
    unsigned int nr_;
    unsigned int nSendings_;
    unsigned int mileage_;
    int tankCapacity_;
    Condition condition_;
    bool isBroken_;
    bool needsRefueling_;
    const char* conditionNames_[3] = {"onTheRoad", "readyToUse", "inService"};

public:
    void setnSendings(unsigned int number);
    int getnSendings();
    void setMileage(unsigned int number);
    int getMileage();
    int getTankCapacity();
    int getCondition();
    void setCondition(Condition condition);
    void setIsBroken(bool isBroken);
    bool getIsBroken();
    void setNeedsRefueling(bool needsRefueling);
    bool getNeedsRefueling();
    int getNr();
    void getInfo();


    Car(int nSendings, int mileage, int tankCapacity, Condition condition, bool isBroken, bool needsRefueling) {
        nSendings_ = nSendings;
        mileage_ = mileage;
        tankCapacity_ = tankCapacity;
        condition_ = condition;
        isBroken_ = isBroken;
        needsRefueling_ = needsRefueling;
        nr_ = uniqueNumber++;
    }

    Car() {
       mileage_ =  nSendings_ = tankCapacity_ = 0;
       isBroken_ = needsRefueling_ = 0;
       condition_ = readyToUse;
       nr_ = uniqueNumber++;
    }

};
