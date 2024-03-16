#include "String.h"
#include <iostream>

int main() {
    String defaultString;
    std::cout << "Default String: " << defaultString.getString() << ", Length: " << defaultString.getLength()
        << ", Is Empty: " << (defaultString.isEmpty() ? "Yes" : "No") << std::endl;

    const char* hello = "Hello, World!";
    String stringFromCharArray(hello);
    std::cout << "String from char array: " << stringFromCharArray.getString() << ", Length: "
        << stringFromCharArray.getLength() << ", Is Empty: " << (stringFromCharArray.isEmpty() ? "Yes" : "No")
        << std::endl;

    String copiedString(stringFromCharArray);
    std::cout << "Copied String: " << copiedString.getString() << ", Length: " << copiedString.getLength()
        << ", Is Empty: " << (copiedString.isEmpty() ? "Yes" : "No") << std::endl;

    const char chars[] = { 'H', 'e', 'l', 'l', 'o' };
    size_t size = sizeof(chars) / sizeof(chars[0]);
    String stringFromArray(chars, size);
    std::cout << "String from char array with size: " << stringFromArray.getString() << ", Length: "
        << stringFromArray.getLength() << ", Is Empty: " << (stringFromArray.isEmpty() ? "Yes" : "No")
        << std::endl;

    String emptyString;
    std::cout << "Empty String: " << emptyString.getString() << ", Length: " << emptyString.getLength()
        << ", Is Empty: " << (emptyString.isEmpty() ? "Yes" : "No") << std::endl;

    String anotherString("Hello");
    std::cout << "Another String: " << anotherString.getString() << ", Length: " << anotherString.getLength()
        << ", Is Empty: " << (anotherString.isEmpty() ? "Yes" : "No") << std::endl;

    String copiedAnotherString(anotherString);
    std::cout << "Copied Another String: " << copiedAnotherString.getString() << ", Length: "
        << copiedAnotherString.getLength() << ", Is Empty: "
        << (copiedAnotherString.isEmpty() ? "Yes" : "No") << std::endl;
   const size_t SIZE = 9;
     int numb[SIZE] = { 9, 4, 76, 22, 15, 21, 25, 20, 21 };

    

     String resultString{ createStringWithNumbers(numb, SIZE) };

     std::cout << "Result String: " << resultString.getString();
        
    return 0;
}
