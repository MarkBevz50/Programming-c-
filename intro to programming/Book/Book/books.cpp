#include "books.h"

Book::Book() : author(""), title(""), year(2005) {}

Book::Book(const std::string& author, const std::string& title, int year)
    : author(author), title(title), year(year) {}

Book::Book(const Book& B)
    : author(B.author), title(B.title), year(B.year)
{
}

void Book::print() const {
    std::cout << "Author: " << author
        << ". Title: " << title
        << ". Year: " << year << '\n';
}

std::string Book::getAuthor() const {
    return author;
}

void Book::setAuthor(const std::string& newAuthor) {
    author = newAuthor;
}

std::string Book::getTitle() const {
    return title;
}

void Book::setTitle(const std::string& newTitle) {
    title = newTitle;
}

int Book::getYear() const {
    return year;
}

void Book::setYear(int newYear) {
    year = newYear;
}

void Book::readFrom(std::istream& in)
{

    std::getline(in, author, '*');
    std::getline(in, title, '*');
    in >> year;
}

void Book::writeTo(std::ostream& out) const
{
    out << author << " * " << title << " * " << year;
}

std::istream& operator>>(std::istream& in, Book& book) {
    book.readFrom(in);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Book& book) {
    book.writeTo(out);
    return out;
}


Book* readBooksFromFile(const std::string& fileName, size_t& numBooks) {
    std::ifstream fin(fileName);
    fin >> numBooks;

    Book* books = new Book[numBooks];
    for (size_t i = 0; i < numBooks; ++i) {
        fin.get();  
        fin >> books[i];
    }

    fin.close();
    return books;
}

void printAllBooks(Book* books, size_t numBooks) {
    for (size_t i = 0; i < numBooks; ++i) {
        books[i].print();
    }
    std::cout << std::endl;
}

void sortBooksByAuthor(Book* books, size_t numBooks) {
    for (size_t i = 0; i < numBooks - 1; ++i) {
        for (size_t j = 0; j < numBooks - i - 1; ++j) {
            if (books[j].getAuthor() > books[j + 1].getAuthor()) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

void writeBooksToFile(Book* books, size_t numBooks, size_t total_books, const std::string& fileName) {
    std::ofstream fout(fileName);
    fout << numBooks << '\n';
    for (size_t i = 0; i < numBooks; ++i) {
        fout << books[i] << '\n';
    }
    fout << total_books << '\n';
    fout.close();
}


Book* filterBooksByPredicateString(const Book* books, size_t numBooks, bool (*predicate)(const Book&, const std::string&), const std::string& param, size_t& newSize) {
    size_t count = 0;
    for (size_t i = 0; i < numBooks; ++i) {
        if (predicate(books[i], param)) {
            ++count;
        }
    }

    newSize = count;
    Book* filteredBooks = new Book[count];
    count = 0;

    for (size_t i = 0; i < numBooks; ++i) {
        if (predicate(books[i], param)) {
            filteredBooks[count] = books[i];
            ++count;
        }
    }

    return filteredBooks;
}
bool isAuthor(const Book& book, const std::string& targetAuthor)
{
    return book.getAuthor() == targetAuthor;
}

bool isYear(const Book& book, int targetYear)
{
    return book.getYear() == targetYear;
}
Book* filterBooksByPredicateInt(const Book* books, size_t numBooks, bool (*predicate)(const Book&, int), int param, size_t& newSize) {
    size_t count = 0;
    for (size_t i = 0; i < numBooks; ++i) {
        if (predicate(books[i], param)) {
            ++count;
        }
    }

    newSize = count;
    Book* filteredBooks = new Book[count];
    count = 0;

    for (size_t i = 0; i < numBooks; ++i) {
        if (predicate(books[i], param)) {
            filteredBooks[count] = books[i];
            ++count;
        }
    }

    return filteredBooks;
}

size_t countAllBooks(const Book* books, size_t numBooks) {
    size_t count = 0;
    for (size_t i = 0; i < numBooks; ++i) {
        ++count;
    }
    return count;
}