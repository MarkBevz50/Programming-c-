#include "tree.h"
#include <fstream>

Fruit_tree::Fruit_tree()
    : tree(""), tree_height(0.5), tree_age(0.1), crop_capacity(50) {}

const std::string Fruit_tree::nonFruitTrees[] = { "Pine", "Beech", "Hornbeam", "Acacia", "Narra", "Maple", "Alder", "Willow" };

Fruit_tree::Fruit_tree(std::string tree, float tree_height, int tree_age, int crop_capacity)
    : tree(tree), tree_height(tree_height), tree_age(tree_age), crop_capacity(crop_capacity) {
    for (const auto& nonFruitTree : nonFruitTrees) {
        if (tree == nonFruitTree) {
            throw InvalidTreeNameException(tree);
        }
    }
    if (tree_height <= 0 || tree_age < 0)
    {
        std::cerr << "Invalid data, tree height and age can't be negative. Default values has been set(age = 0.1, height = 0.5)." << std::endl;
        tree_age = 0.1; 
        tree_height = 0.5;
    }
}

Fruit_tree::Fruit_tree(const Fruit_tree& T)
    : tree(T.tree), tree_height(T.tree_height), tree_age(T.tree_age), crop_capacity(T.crop_capacity) {}

Fruit_tree::~Fruit_tree() {}

std::string Fruit_tree::getTree() const {
    return tree;
}

float Fruit_tree::getTreeHeight() const {
    return tree_height;
}

int Fruit_tree::getTreeAge() const {
    return tree_age;
}

int Fruit_tree::getCropCapacity() const {
    return crop_capacity;
}

void Fruit_tree::setTree(std::string newTree) {
    tree = newTree;
}

void Fruit_tree::setTreeHeight(float newHeight) {
    tree_height = newHeight;
}

void Fruit_tree::setTreeAge(int newAge) {
    tree_age = newAge;
}

void Fruit_tree::setCropCapacity(int newCropCapacity) {
    crop_capacity = newCropCapacity;
}

void Fruit_tree::yearPassed() {
    ++tree_age;
    float firstIncrease = 1.25;      // Growth in height and productivity in the first 7 years
    float secondIncrease = 1.05;     // Growth in height and productivity in the next 10 years
    int ageOfProductivity = 3;
    int endOfQuickGrows = 7;
    int FirstCropCapacity = 25;
    int StableAge = 17;                      //fruit tree stops growing
    if (tree_age == ageOfProductivity)               
        crop_capacity = FirstCropCapacity;          
    else if (tree_age > ageOfProductivity && tree_age < endOfQuickGrows) {
        tree_height = tree_height * firstIncrease;
        crop_capacity = crop_capacity * firstIncrease;
    }
    else if (tree_age < StableAge) {
        tree_height = tree_height * secondIncrease;
        crop_capacity = crop_capacity * secondIncrease;
    }
}

void Fruit_tree::print() const {
    std::cout << "Tree: " << tree
        << ". Tree height:" << tree_height << " meters"
        << ". Tree age:" << tree_age << " years"
        << ". Crop Capacity:" << crop_capacity << " kilograms" << '\n';
}

void Fruit_tree::readFrom(std::istream& in) {
    in >> tree >> tree_height >> tree_age >> crop_capacity;
}

void Fruit_tree::writeTo(std::ostream& out) const {
    out << tree << " " << tree_height << " " << tree_age << " " << crop_capacity << " ";
}

bool Fruit_tree::operator<(const Fruit_tree& T) const {
    return getCropCapacity() < T.getCropCapacity();
}

std::istream& operator>>(std::istream& in, Fruit_tree& T) {
    T.readFrom(in);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Fruit_tree& T) {
    T.writeTo(out);
    return out;
}

Fruit_tree heighestTree(Fruit_tree* arr, int n) {
    Fruit_tree theHighestTree = arr[0];
    for (size_t i = 0; i < n; ++i) {
        if (arr[i].getTreeHeight() > theHighestTree.getTreeHeight())
            theHighestTree = arr[i];
    }
    return theHighestTree;
}

Fruit_tree mostProductiveTree(Fruit_tree* arr, int n) {
    Fruit_tree theMostProductiveTree = arr[0];
    for (size_t i = 0; i < n; ++i) {
        if (arr[i].getCropCapacity() > theMostProductiveTree.getCropCapacity())
            theMostProductiveTree = arr[i];
    }
    return theMostProductiveTree;
}

Fruit_tree* plantAGarden(const std::string& fileName, size_t& GardSize) {
    std::ifstream fin(fileName);
    fin >> GardSize;
    Fruit_tree* Garden = new Fruit_tree[GardSize];
    for (size_t i = 0; i < GardSize; ++i) {
        fin >> Garden[i];
    }
    fin.close();
    return Garden;
}

void GardenYearAfter(Fruit_tree* Garden, size_t& GardSize) {
    for (size_t i = 0; i < GardSize; ++i) {
        Garden[i].yearPassed();
    }
}

void printGarden(Fruit_tree* Garden, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        Garden[i].print();
        std::cout << std::endl;
    }
}

bool isProdactive(Fruit_tree* T) {
    const int AgeOfProductivity = 3;
    return T->getTreeAge() > AgeOfProductivity;
}

Fruit_tree* onlyProdArray(Fruit_tree* Garden, int n, bool (*predicate)(Fruit_tree*), size_t& newSize) {
    size_t count = 0;
    for (size_t i = 0; i < n; ++i) {
        if (predicate(&Garden[i]) == true) {
            ++count;
        }
    }
    newSize = count;
    Fruit_tree* GoodGarden = new Fruit_tree[count];
    count = 0;
    for (size_t i = 0; i < n; ++i) {
        if (predicate(&Garden[i]) == true) {
            GoodGarden[count] = Garden[i];
            ++count;
        }
    }
    return GoodGarden;
}

void writeGarden(Fruit_tree* Garden, size_t n, const std::string& fileName) {
    std::ofstream fout(fileName);
    fout << n << '\n';
    for (size_t i = 0; i < n; ++i) {
        fout << Garden[i] << '\n';
    }
    fout.close();
}
