#pragma once
#include "footbal.h"
class Node {
public:
	footballer	data;
	Node* next;
	Node(const footballer& player);
};
class FootballClub
{
private:
	std::string club_name;
	double payment_coef;
	Node* head;
	void killList();
	void insertPlayer(const footballer& player);
public:
	FootballClub(std::string club_name, double payment_coef);
	FootballClub(const FootballClub& other);
	double getCoef()const;
	std::string getClubName();
	~FootballClub();
	void addPlayer(const std::string & name, const std::string& surname, int goals_scored);
	void printClubInfo();
	int calculateTotalGoals();
	double calculateTotalPayment();
};
void addPlayersToClub(const std::string& club_name, FootballClub& club, std::ifstream& file);
void readPlayersFromFile(const std::string& filename, FootballClub& Club1, FootballClub& Club2, FootballClub& Club3);
FootballClub mostWealthyClub(FootballClub& Club1, FootballClub& Club2, FootballClub& Club3);
FootballClub mostSuccesfulClub(FootballClub& Club1, FootballClub& Club2, FootballClub& Club3);
