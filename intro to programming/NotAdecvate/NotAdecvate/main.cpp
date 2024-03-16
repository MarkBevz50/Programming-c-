#include <iostream>
#include <fstream>
#include <iomanip>
std::string containesZV(const std::string& str)
{
    for (char c : str) {
        if (c == 'Z' || c == 'V') {
            return "|YES";
        }
    }  
    return "|NO";
}
int main() {
    int size;
    std::ifstream fin("NotAdecvate.txt");
    fin >> size;
    std::string* words = new std::string[size];
    for (size_t i = 0; i < size; ++i) {
        fin >> words[i];
    }
    fin.close();
    for (int i = 0; i < size; ++i)
    {
        std::string YesNo = containesZV(words[i]);
        std::cout << std::setw(10) << std::left << words[i] << std::setw(5) << YesNo << std::endl;
    }

    delete[]words;
    return 0;
}
