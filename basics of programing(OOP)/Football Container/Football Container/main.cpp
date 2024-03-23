#include "footbal.h"
#include "club.h"
int main()
{
    FootballClub Barcelona("Barcelona", 170); 
    FootballClub RealMadrid("RealMadrid", 300); 
    FootballClub Liverpool("Liverpool", 160);
    readPlayersFromFile("footballer.txt", Barcelona, RealMadrid, Liverpool);
    std::cout << "Information for Football Club Barcelona:" << std::endl;
    Barcelona.printClubInfo();
    std::cout << "Total goals: " << Barcelona.calculateTotalGoals();
    std::cout << std::endl;
    std::cout << "Total payment: " << Barcelona.calculateTotalPayment() << std::endl;
    std::cout << "Information for Football Club Real Madrid:" << std::endl;
    RealMadrid.printClubInfo();
    std::cout << "Total goals: " << RealMadrid.calculateTotalGoals() << std::endl;
    std::cout << "Total payment: " << RealMadrid.calculateTotalPayment() << std::endl;
    std::cout << "Information for Football Club Liverpool:" << std::endl;
    Liverpool.printClubInfo();
    std::cout << "Total goals: " << Liverpool.calculateTotalGoals() << std::endl;
    std::cout << "Total payment: " << Liverpool.calculateTotalPayment() << std::endl;

    std::cout << "The most wealthy club: ";
    FootballClub richest = mostWealthyClub(Barcelona, RealMadrid, Liverpool);
    richest.printClubInfo();
    std::cout << "Total payment: " << richest.calculateTotalPayment() << std::endl;
    std::cout << "The most Succesful club: ";
    FootballClub succesful = mostSuccesfulClub(Barcelona, RealMadrid, Liverpool);
    succesful.printClubInfo();
    std::cout << "Total goals: " << succesful.calculateTotalGoals();
    return 0;
}