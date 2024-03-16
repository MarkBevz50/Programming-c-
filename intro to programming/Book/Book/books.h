#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Book {
private:
    std::string author;
    std::string title;
    int year;

public:
    // Конструктори, методи та операції перевантаження операторів
    Book();
    Book(const std::string& author, const std::string& title, int year);
    Book(const Book& B);
    void print() const;
    std::string getAuthor() const;
    void setAuthor(const std::string& newAuthor);
    std::string getTitle() const;
    void setTitle(const std::string& newTitle);
    int getYear() const;
    void setYear(int newYear);
    void readFrom(std::istream& in);
    void writeTo(std::ostream& out)const;
};

std::istream& operator>>(std::istream& in, Book& book);
std::ostream& operator<<(std::ostream& out, const Book& book);

Book* readBooksFromFile(const std::string& fileName, size_t& numBooks);
void printAllBooks(Book* books, size_t numBooks);
void sortBooksByAuthor(Book* books, size_t numBooks);
void writeBooksToFile(Book* books, size_t numBooks, size_t total_books, const std::string& fileName);
bool isAuthor(const Book& book, const std::string& targetAuthor);
bool isYear(const Book& book, int targetYear);
Book* filterBooksByPredicateString(const Book* books, size_t numBooks, bool (*predicate)(const Book&, const std::string&), const std::string& param, size_t& newSize);
Book* filterBooksByPredicateInt(const Book* books, size_t numBooks, bool (*predicate)(const Book&, int), int param, size_t& newSize);
size_t countAllBooks(const Book* books, size_t numBooks);