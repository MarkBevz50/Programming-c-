#pragma once
#include <string>

class Driver {
protected:
    std::string name;
    int age;

public:
    Driver(const std::string& name, int age);
    int getAge() const;
    void printInfo() const;
};
struct Node {
    Player player;
    Node* left;
    Node* right;

    Node(const Player& p) : player(p), left(nullptr), right(nullptr) {}
};
class FootballClub {
private:
    std::string clubName;
    double playerPayCoefficient;
    Node* root;
    int maxSize;
    int numPlayers;

    void addPlayer(Node*& node, const Player& player);
    void printInOrder(Node* node) const;
    int getTotalGoals(Node* node) const;
    double getTotalPayment(Node* node) const;
    void destroyTree(Node* node);

public:
    FootballClub(const std::string& name, double coefficient, int size);
    ~FootballClub();

    void addPlayer(const std::string& playerName, int goals);
    void printClubInfo() const;
    void sortPlayersByGoals();
    int getTotalGoalsScored() const;
    double getTotalPayment() const;
};
