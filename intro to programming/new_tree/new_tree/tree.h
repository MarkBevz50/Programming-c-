#pragma once
#include <iostream>
#include <string>

class InvalidTreeNameException : public std::exception {
public:
    explicit InvalidTreeNameException(const std::string& treeName)
        : treeName_(treeName), message_("Invalid tree name: " + treeName) {}

    const char* what() const noexcept override {
        return message_.c_str();
    }

    const std::string& getTreeName() const {
        return treeName_;
    }

private:
    std::string treeName_;
    std::string message_;
};
class Fruit_tree {
private:
    std::string tree;
    float tree_height;
    int tree_age;
    int crop_capacity;

    static const std::string nonFruitTrees[];
public:
    Fruit_tree();
    Fruit_tree(std::string tree, float tree_height, int tree_age, int crop_capacity);
    Fruit_tree(const Fruit_tree& T);
    ~Fruit_tree();

    std::string getTree() const;
    float getTreeHeight() const;
    int getTreeAge() const;
    int getCropCapacity() const;

    void setTree(std::string newTree);
    void setTreeHeight(float newHeight);
    void setTreeAge(int newAge);
    void setCropCapacity(int newCropCapacity);

    void yearPassed();

    void print() const;
    void readFrom(std::istream& in);
    void writeTo(std::ostream& out) const;

    bool operator<(const Fruit_tree& T) const;
};

std::istream& operator>>(std::istream& in, Fruit_tree& T);
std::ostream& operator<<(std::ostream& out, const Fruit_tree& T);

Fruit_tree heighestTree(Fruit_tree* arr, int n);
Fruit_tree mostProductiveTree(Fruit_tree* arr, int n);
Fruit_tree* plantAGarden(const std::string& fileName, size_t& GardSize);
void GardenYearAfter(Fruit_tree* Garden, size_t& GardSize);
void printGarden(Fruit_tree* Garden, size_t n);
bool isProdactive(Fruit_tree* T);
Fruit_tree* onlyProdArray(Fruit_tree* Garden, int n, bool(*predicate)(Fruit_tree*), size_t& newSize);
void writeGarden(Fruit_tree* Garden, size_t n, const std::string& fileName);
