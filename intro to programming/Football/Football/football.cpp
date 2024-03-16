#include "football.h"
#include <fstream>
using namespace std;

Player::Player()
	: player_name("")
	, player_club()
	, player_goals(0)
{
	calculateReward();
}

Player::Player(const string& name, const Club& club, int goals)
	: player_name(name)
	, player_club(club)
	, player_goals(goals)
{
	calculateReward();
}

Player::Player(const string& name, const string& clubName, int clubRate, int goals)
	: player_name(name)
	, player_club(clubName, clubRate)
	, player_goals(goals)
{
	calculateReward();
}

Player::Player(const Player& P)
	: player_name(P.player_name)
	, player_club(P.player_club)
	, player_goals(P.player_goals)
{
	calculateReward();
}

Player::~Player()
{}

void Player::calculateReward()
{
	player_reward = 100 * player_goals;
}


string Player::getClub() const
{
	return player_club.getName();
}

int Player::getGoals() const
{
	return player_goals;
}

void Player::setClub(const Club& newClub)
{
	if (newClub.getName() == "Zenit")
		throw ClubNameException(newClub.getName());
	if (newClub.getRate() < player_club.getRate())
		throw ClubRateException(player_club.getRate(), newClub.getRate());
	player_club = newClub;
	calculateReward();
}

void Player::addGoals(int newGoals)
{
	if (newGoals < 0)
		throw GoalException(newGoals);
	player_goals += newGoals;
	calculateReward();
}

void Player::print() const
{
	cout << "Player: " << player_name
		<< ". Club: " << player_club.getName()
		<< ". Total: " << player_goals << " goals\n";
	cout << "\tReward: " << getReward() << " usd\n";
}

void Player::readFrom(istream& in)
{
	// Lionell Messi*Real Madrid*250*37
	getline(in, player_name, '*');
	in >> player_club;
	in.get();
	in >> player_goals;
	calculateReward();
}

void Player::writeTo(ostream& out) const
{
	out << player_name << '*'
		<< player_club << '*'
		<< player_goals;
}

istream& operator>>(istream& in, Player& P)
{
	P.readFrom(in);
	return in;
}

ostream& operator<<(ostream& out, const Player& P)
{
	P.writeTo(out);
	return out;
}

Player* createTeam(const std::string& teamName, size_t& teamSize)
{
	ifstream fin(teamName);
	fin >> teamSize;

	Player* team = new Player[teamSize];
	for (size_t i = 0; i < teamSize; ++i)
	{
		fin.get();
		fin >> team[i];
	}

	fin.close();
	return team;
}

void printTeam(Player* team, size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		team[i].print();
	}
	cout << endl;
}

int Player::getReward() const
{
	return player_reward;
}

bool Player::operator<(Player& P)
{
	return getGoals() < P.getGoals();
}

Player* maxPlayer(Player* team, size_t n)
{
	Player* max = &team[0];
	for (size_t i = 1; i < n; ++i)
	{
		if (*max < team[i])
		{
			max = &team[i];
		}
	}
	return max;
}

void sortTeam(Player* team, size_t n)
{
	for (size_t i = 0; i < n; ++i)
	{
		size_t min = i;
		for (size_t j = i + 1; j < n; ++j)
		{
			if (team[j] < team[min])
			{
				min = j;
			}
		}

		if (min != i)
		{
			Player temp = team[i];
			team[i] = team[min];
			team[min] = temp;
		}
	}
}

void writeTeam(Player* team, size_t n, const std::string& fileName)
{
	ofstream fout(fileName);
	fout << n << '\n';
	for (size_t i = 0; i < n; ++i)
	{
		fout << team[i] << '\n';
	}
	fout.close();
}


bool byClub(Player& A, Player& B)
{
	return A.getClub() < B.getClub();
}

bool byReward(Player& A, Player& B)
{
	return A.getReward() < B.getReward();
}

void sortTeamBy(Player* team, size_t n, bool(*compare)(Player&, Player&))
{
	for (size_t i = 0; i < n; ++i)
	{
		size_t min = i;
		for (size_t j = i + 1; j < n; ++j)
		{
			if (compare(team[j], team[min]))
			{
				min = j;
			}
		}

		if (min != i)
		{
			Player temp = team[i];
			team[i] = team[min];
			team[min] = temp;
		}
	}
}

Player* selectPlayers(Player* team, size_t n, size_t& newN)
{
	Player* selected = new Player[n];
	newN = 0;
	for (size_t i = 0; i < n; ++i)
	{
		if (team[i].getGoals() < 35)
		{
			selected[newN] = team[i];
			++newN;
		}
	}
	return selected;
}

void Player::GoalException::info() const
{
	cout << "Number of goals" << goal_value << "is invalid. \n";
}
