#include <iostream>
#include "books.h"
int main() {
    size_t numBooks;
    Book* books = readBooksFromFile("books.txt", numBooks);

    printAllBooks(books, numBooks);

    sortBooksByAuthor(books, numBooks);

    std::cout << "Sorted by author:\n";
    printAllBooks(books, numBooks);

    std::string targetAuthor;
    std::cout << "Enter the author to filter by: ";
    std::cin >> targetAuthor;
    size_t newSize;
    Book* filteredBooksByAuthor = filterBooksByPredicateString(books, numBooks, isAuthor, targetAuthor, newSize);
    std::cout << "All books of " << targetAuthor << "in the list:\n";
    printAllBooks(filteredBooksByAuthor, newSize);
    size_t newerSize;
    std::cout << "Enter year of book in list:\n ";
    int targetYear;
    std::cin >> targetYear;
    Book* filteredBooksByAuthorAndYear = filterBooksByPredicateInt(filteredBooksByAuthor, newSize, isYear, targetYear, newerSize);
    std::cout << "Your books is: \n";
    printAllBooks(filteredBooksByAuthorAndYear, newerSize);
    size_t AllBooksCertainAuthorAndYear = countAllBooks(filteredBooksByAuthorAndYear, newerSize);
    std::cout << "Amount of books written that year: " << AllBooksCertainAuthorAndYear << '\n';
    writeBooksToFile(filteredBooksByAuthorAndYear, newerSize, AllBooksCertainAuthorAndYear, "YourBooksToRead.txt");
    std::cout << "Check your files.";
    delete[] books;  
    delete[] filteredBooksByAuthor;
    delete[] filteredBooksByAuthorAndYear;
    return 0;
}