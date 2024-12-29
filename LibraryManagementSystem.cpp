#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    int quantity;

    Book(int id, string title, string author, int quantity)
        : id(id), title(title), author(author), quantity(quantity) {}
};

class Library {
private:
    vector<Book> books;
    int nextBookId = 1;

public:
    void addBook() {
        string title, author;
        int quantity;

        cout << "\nEnter Book Title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter Book Author: ";
        getline(cin, author);
        cout << "Enter Quantity: ";
        cin >> quantity;

        books.emplace_back(nextBookId++, title, author, quantity);
        cout << "Book added successfully!\n";
    }

    void searchBook() {
        string query;
        cout << "\nEnter title or author to search: ";
        cin.ignore();
        getline(cin, query);

        bool found = false;
        for (const auto& book : books) {
            if (book.title.find(query) != string::npos || book.author.find(query) != string::npos) {
                displayBook(book);
                found = true;
            }
        }
        if (!found) {
            cout << "No book found matching the query.\n";
        }
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "\nNo books in the library.\n";
            return;
        }
        cout << "\nAvailable Books:\n";
        cout << left << setw(5) << "ID" << setw(20) << "Title" << setw(20) << "Author" << setw(10) << "Quantity" << "\n";
        for (const auto& book : books) {
            cout << left << setw(5) << book.id << setw(20) << book.title << setw(20) << book.author << setw(10) << book.quantity << "\n";
        }
    }

    void issueBook() {
        int id;
        cout << "\nEnter Book ID to issue: ";
        cin >> id;

        for (auto& book : books) {
            if (book.id == id) {
                if (book.quantity > 0) {
                    book.quantity--;
                    cout << "Book issued successfully!\n";
                } else {
                    cout << "Book out of stock.\n";
                }
                return;
            }
        }
        cout << "Book ID not found.\n";
    }

    void returnBook() {
        int id;
        cout << "\nEnter Book ID to return: ";
        cin >> id;

        for (auto& book : books) {
            if (book.id == id) {
                book.quantity++;
                cout << "Book returned successfully!\n";
                return;
            }
        }
        cout << "Book ID not found.\n";
    }

    void displayBook(const Book& book) {
        cout << "\nBook Details:\n";
        cout << "ID: " << book.id << "\n";
        cout << "Title: " << book.title << "\n";
        cout << "Author: " << book.author << "\n";
        cout << "Quantity: " << book.quantity << "\n";
    }
};

int main() {
    Library library;
    int choice;

    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Display All Books\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.searchBook();
                break;
            case 3:
                library.displayBooks();
                break;
            case 4:
                library.issueBook();
                break;
            case 5:
                library.returnBook();
                break;
            case 6:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
