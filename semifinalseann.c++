#include<iostream>
#include <vector>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    string genre;
};

class LibraryManagementSystem {
private:
    vector<Book> books;

public:
    void createBook() {
        Book newBook;
        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, newBook.title);
        cout << "Enter author name: ";
        getline(cin, newBook.author);
        cout << "Enter genre (Self-Improvement/Business): ";
        getline(cin, newBook.genre);
        books.push_back(newBook);
        cout << "Book added successfully!\n";
    }

    void readBooks() {
        if (books.empty()) {
            cout << "No books available.\n";
            return;
        }
        cout << "\nBooks in the Library:\n";
        for (size_t i = 0; i < books.size(); ++i) {
            cout << i + 1 << ". Title: " << books[i].title
                 << ", Author: " << books[i].author
                 << ", Genre: " << books[i].genre << endl;
        }
    }

    void updateBook() {
        readBooks();
        int index;
        cout << "Enter the book number to update: ";
        cin >> index;
        if (index < 1 || index > books.size()) {
            cout << "Invalid book number.\n";
            return;
        }
        Book& bookToUpdate = books[index - 1];
        cout << "Updating Book: " << bookToUpdate.title << endl;
        cout << "Enter new title (or press enter to keep current): ";
        cin.ignore();
        string newTitle;
        getline(cin, newTitle);
        if (!newTitle.empty()) bookToUpdate.title = newTitle;
        
        cout << "Enter new author (or press enter to keep current): ";
        string newAuthor;
        getline(cin, newAuthor);
        if (!newAuthor.empty()) bookToUpdate.author = newAuthor;

        cout << "Enter new genre (or press enter to keep current): ";
        string newGenre;
        getline(cin, newGenre);
        if (!newGenre.empty()) bookToUpdate.genre = newGenre;

        cout << "Book updated successfully!\n";
    }

    void deleteBook() {
        readBooks();
        int index;
        cout << "Enter the book number to delete: ";
        cin >> index;
        if (index < 1 || index > books.size()) {
            cout << "Invalid book number.\n";
            return;
        }
        books.erase(books.begin() + index - 1);
        cout << "Book deleted successfully!\n";
    }

    void menu() {
        while (true) {
            cout << "\nLibrary Management System\n";
            cout << "1. Add Book\n";
            cout << "2. View Books\n";
            cout << "3. Update Book\n";
            cout << "4. Delete Book\n";
            cout << "5. Exit\n";
            cout << "Select an option: ";

            int choice;
            cin >> choice;
            switch (choice) {
                case 1:
                    createBook();
                    break;
                case 2:
                    readBooks();
                    break;
                case 3:
                    updateBook();
                    break;
                case 4:
                    deleteBook();
                    break;
                case 5:
                    cout << "Exiting the program.\n";
                    return;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        }
    }
};

int main() {
    LibraryManagementSystem library;
    library.menu();
    return 0;
}
