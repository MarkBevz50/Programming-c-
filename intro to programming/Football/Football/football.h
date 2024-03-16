#pragma once
#include <iostream>
#include <string>
#include "club.h"

class Player
{
private:
	std::string player_name;
	Club player_club;
	int player_goals;
	int player_reward;

	void calculateReward();

public:
	class GoalException 
	{
	private:
		int goal_value;
	public:
		GoalException(int value) : goal_value(value) {}
		void info() const;
	
	};
	class ClubNameException
	{
	private:
		std::string club_name;
	public:
		ClubNameException(const std::string& name) : club_name(name) {}
		void info() const { std::cout << "Club: " << club_name << " is forbidden.\n"; }
	};
public:
	class ClubRateException
	{
	private:
		int club_oldRate;
		int club_newRate;
	public:
		ClubRateException(int oldRate, int newRate) : club_oldRate(oldRate), club_newRate(newRate) {}
		void info() const
		{
			std::cout << "New rate " << club_newRate
				<< " is lower than old rate " << club_oldRate << ".\n";
		}
	};
	Player();
	Player(const std::string& name, const Club& club, int goals);
	Player(const std::string& name, const std::string& clubName, int clubRate, int goals);
	Player(const Player& P);
	~Player();

	std::string getClub() const;
	int getGoals() const;
	int getReward() const;

	void setClub(const Club& newClub);
	void addGoals(int newGoals);

	void print() const;

	void readFrom(std::istream& in);
	void writeTo(std::ostream& out) const;

	bool operator<(Player& P);

};

std::istream& operator>>(std::istream& in, Player& P);
std::ostream& operator<<(std::ostream& out, const Player& P);

Player* createTeam(const std::string& teamName, size_t& teamSize);
void printTeam(Player* team, size_t n);
Player* maxPlayer(Player* team, size_t n);
void sortTeam(Player* team, size_t n);

bool byClub(Player& A, Player& B);
bool byReward(Player& A, Player& B);
void sortTeamBy(Player* team, size_t n, bool(*compare)(Player&, Player&));

void writeTeam(Player* team, size_t n, const std::string& fileName);

Player* selectPlayers(Player* team, size_t n, size_t& newN);