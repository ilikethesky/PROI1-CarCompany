#include "ClassCarCompany.cpp"

class Menu {
public:
    Menu(CarCompany x) { current_ = x;}
    void printMainMenu();
    void printInfoMenu();
    void printChangeMenu();
    int enterNr();
    void pressEnter();
    void createNewCar();
    void SelectMainMenu();
    void SelectInfoMenu();
    void SelectChangeMenu();
    int returnChar(char *tab, int maximum);

private:
    CarCompany current_;

};
