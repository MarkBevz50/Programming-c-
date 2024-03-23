#include "club.h"
# include <fstream>
Node::Node(const footballer& player)
	:data(player), next (nullptr)
{
}

void FootballClub::killList()
{
	while (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
}

void FootballClub::insertPlayer(const footballer& player)
{
	Node* new_player = new Node(player);
	if (head == nullptr || head->data.getGoals() < player.getGoals())
	{
		new_player->next = head;
		head = new_player;
	}
	else {
		Node* current = head;
		while (current->next != nullptr && current->next->data.getGoals() > player.getGoals())
		{
			current = current->next;
		}
		new_player->next = current->next;
		current->next = new_player;
	}
}

FootballClub::FootballClub(std::string club_name, double payment_coef)
	: club_name(club_name), payment_coef(payment_coef), head(nullptr)
{
}

FootballClub::FootballClub(const FootballClub& other)
:club_name(other.club_name), head(nullptr)
{
	Node* current = other.head;
	while (current != nullptr)
	{
		insertPlayer(current->data);
		current = current->next;
	}
}

double FootballClub::getCoef() const
{
	return payment_coef;
}

std::string FootballClub::getClubName()
{
	return club_name;
}

FootballClub::~FootballClub()
{
	killList();
}

void FootballClub::addPlayer(const std::string& name, const std::string& surname, int goals_scored)
{
	footballer new_player(name, surname, goals_scored, payment_coef);
	insertPlayer(new_player);
}

void FootballClub::printClubInfo()
{
	std::cout << "Football Club: " << club_name << std::endl;
	std::cout << "Players:" << std::endl;
	Node* current = head;
	while (current != nullptr) {
		current->data.print();
		current = current->next;
	}
}

int FootballClub::calculateTotalGoals()
{
	int total_goals = 0;
	Node* current = head;
	while (current != nullptr) {
		total_goals += current->data.getGoals();
		current = current->next;
	}
	return total_goals;
}

double FootballClub::calculateTotalPayment()
{
		double total_payment = 0;
		Node* current = head;
		while (current != nullptr) {
			total_payment += current->data.calculateTotalIncome() ;
			current = current->next;
		}
		return total_payment;
}

void readPlayersFromFile(const std::string& filename, FootballClub& Club1, FootballClub& Club2, FootballClub& Club3) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error: Unable to open file " << filename << std::endl;
		return;
	}

	std::string club_name, player_name, player_surname;
	int goals_scored;
	while (file >> club_name >> player_name >> player_surname >> goals_scored) {
		if (club_name == Club1.getClubName()) {
			Club1.addPlayer(player_name, player_surname, goals_scored);
			
		}
		else if (club_name == Club2.getClubName()) {
			Club2.addPlayer(player_name, player_surname, goals_scored);
		}
		else if (club_name == Club3.getClubName()) {
			Club3.addPlayer(player_name, player_surname, goals_scored);
		}
		else {
			std::cerr << "Error: Unknown club name " << club_name << std::endl;
		}
		file >> std::ws;
	}

	file.close();
}
void addPlayersToClub(const std::string& club_name, FootballClub& club, std::ifstream& file) {
	std::string name, surname;
	int goals_scored;
	while (file >> name >> surname >> goals_scored) {
		if (club_name == club.getClubName()) {
			club.addPlayer(name, surname, goals_scored);
		}
	}
}
void readPlayersFromFile(const std::string& filename, FootballClub& Club1, FootballClub& Club2, FootballClub& Club3);
FootballClub mostWealthyClub(FootballClub& Club1, FootballClub& Club2, FootballClub& Club3)
{
	double club1 = Club1.calculateTotalPayment();
	double club2 = Club2.calculateTotalPayment();
	double club3 = Club3.calculateTotalPayment();
	if (club1 > club2 && club1 > club3)
	{
		return Club1;
	}
	else if (club2 > club1 && club2 > club3)
	{
		return Club2;
	}
	return Club3;
}

FootballClub mostSuccesfulClub(FootballClub& Club1, FootballClub& Club2, FootballClub& Club3)
{
	double club1 = Club1.calculateTotalGoals();
	double club2 = Club2.calculateTotalGoals();
	double club3 = Club3.calculateTotalGoals();
	if (club1 > club2 && club1 > club3)
	{
		return Club1;
	}
	else if (club2 > club1 && club2 > club3)
	{
		return Club2;
	}
	return Club3;
}
