#include <iostream>
#include "tree.h"

int main() {
    
        size_t n;
        Fruit_tree* Garden = plantAGarden("trees.txt", n);


        std::cout << "Initial Garden:" << std::endl;
        printGarden(Garden, n);
        Fruit_tree HighestTree = heighestTree(Garden, n);
        std::cout << "The highest tree is: \n ";
        HighestTree.print();
        std::cout << "The most productive tree is: \n " ;
        Fruit_tree MostProdTree = mostProductiveTree(Garden, n);
        MostProdTree.print();
        std::cout << std::endl;
        std::cout << "Only productive trees: \n" ;
        size_t newSize;
        Fruit_tree* ProdArr = onlyProdArray(Garden, n, isProdactive, newSize);
        printGarden(ProdArr, newSize);
        writeGarden(ProdArr, newSize, "Productive.txt");
        std::cout << "Check your files.\n" ;
        std::cout << "Enter 1 to skip this year(0 to stop)" << '\n';
        int count;
        do {                                        //if you want to see what will happen with your garden in the next year
            std::cin >> count;
            GardenYearAfter(Garden, n);
            std::cout << "Garden after a year :" << '\n';
            printGarden(Garden, n);
            Fruit_tree HighestTree = heighestTree(Garden, n);
            std::cout << "The highest tree is: \n ";
            HighestTree.print();
            std::cout << "The most productive tree is: \n ";
            Fruit_tree MostProdTree = mostProductiveTree(Garden, n);
            MostProdTree.print();
            std::cout << std::endl;
        } while (count != 0);
        std::cout << "TEST CASE: \n" ;
        try {
            Fruit_tree myTree("Acacia", 2.0, 5, 30); // other trees "Pine", "Beech", "Hornbeam", "Acacia", "Narra", "Maple", "Alder", "Willow"
            std::cout << "Tree created successfully." << std::endl;
        }
        catch (const InvalidTreeNameException& e) {
            std::cerr << "InvalidTreeNameException caught(not fruit tree): " << e.what() << std::endl;
            std::cerr << "Tree name: " << e.getTreeName() << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Standard exception caught: " << e.what() << std::endl;
        }
        delete[] Garden;
        delete[] ProdArr;
        return 0;
    }
    
    
