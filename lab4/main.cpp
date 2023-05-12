#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
public:

    Book(string title, string author) {
        this->title = title;
        this->author = author;
    }
    string get_title() {
        return title;
    }
    string get_author() {
        return author;
    }
};

class Library {
private:
    string name;

public:
    vector<Book> books;

    Library() {
        name = "Unnamed Library";
    }

    Library(string name) {
        this->name = name;
    }

    void add_book(Book book) {
        books.push_back(book);
        cout << "Book added: " << book.get_title() << " by " << book.get_author() << endl;
    }

    void remove_book(Book book) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].get_title() == book.get_title() && books[i].get_author() == book.get_author()) {
                books.erase(books.begin() + i);
                cout << "Book removed: " << book.get_title() << " by " << book.get_author() << endl;
                return;
            }
        }
        cout << "Book not found: " << book.get_title() << " by " << book.get_author() << endl;
    }

    void show_books() {
        cout << "Books in " << name << " library:" << endl;
        for (int i = 0; i < books.size(); i++) {
            cout << i+1 << ". " << books[i].get_title() << " by " << books[i].get_author() << endl;
        }
    }
};

class Person {
protected:
    string name;

public:
    Person(string name) {
        this->name = name;
    }

    virtual void show_info() = 0;
};

class Reader : public Person {
private:
    vector<Book> borrowed_books;

public:
    Reader(string name) : Person(name) {
    }

    void borrow_book(string book_name, Library& library) {
        for (int i = 0; i < library.books.size(); i++) {
            if (library.books[i].get_title() == book_name) {
                borrowed_books.push_back(library.books[i]);
                library.remove_book(library.books[i]);
                cout << "Book borrowed: " << book_name << endl;
                return;
            }
        }
        cout << "Book not found in the library: " << book_name << endl;
    }

    void return_book(string book_name, Library& library) {
        for (int i = 0; i < borrowed_books.size(); i++) {
            if (borrowed_books[i].get_title() == book_name) {
                library.add_book(borrowed_books[i]);
                borrowed_books.erase(borrowed_books.begin() + i);
                cout << "Book returned: " << book_name << endl;
                return;
            }
        }
        cout << "You have not borrowed this book: " << book_name << endl;
    }

    virtual void show_info() {
        cout << "Reader name: " << name << endl;
        cout << "Borrowed books:" << endl;
        for (int i = 0; i < borrowed_books.size(); i++) {
            cout << i+1 << ". " << borrowed_books[i].get_title() << " from " << borrowed_books[i].get_author() << endl;
        }
    }
};

class Librarian : public Person {
public:
    Librarian(string name) : Person(name) {
    }

    void add_book(string book_name, Library& library) {
        Book book(book_name, name);
        library.add_book(book);
    }

    void remove_book(string book_name, Library& library) {
        Book book(book_name, name);
        library.remove_book(book);
    }

    virtual void show_info() {
        cout << "Librarian name: " << name << endl;
    }
};
int main() {
    string libname, librarianname, bookname, reader1name,reader2name,reader3name,reader4name,borrowname,returnname, ans;
    char variable, readerchoice, returnbookreader;
    cout<<"Hello input library name: " << endl;
    cin >> libname;
    Library library(libname);
    cout << "Name the librarian: " << endl;
    cin >> librarianname;
    Librarian librarian(librarianname);
    cout << "Name readers in the library: " << endl;
    cout << "Name the 1 reader: " << endl;
    cin >> reader1name;
    Reader reader1(reader1name);
    cout << "Name the 2 reader: " << endl;
    cin >> reader2name;
    Reader reader2(reader2name);
    cout << "Name the 3 reader: " << endl;
    cin >> reader3name;
    Reader reader3(reader3name);
    cout << "Name the 4 reader: " << endl;
    cin >> reader4name;
    Reader reader4(reader4name);


    do{
    cout << "What do you want to do? " << endl;
    cout << "1. Add book to the library "<< endl<<"2. Borrow book from the library"<<endl<<"3. Return book to the library"<<endl;
    cout << "4. Show information"<<endl;
    cin >> variable;
    switch(variable){
    case '1' : {
        cout << "Enter book name: " << endl;
        cin >> bookname;
        librarian.add_book(bookname, library);
        break;
    }
    case '2' : {
        cout << "Who will borrow the book? " << endl << "1. For the first reader" << endl;
        cout << "2. For the second reader" << endl << "3. For the third reader" << endl;
        cout << "4. For the fourth reader" << endl;
        cin >> readerchoice;
            switch (readerchoice) {
                case ('1'): {
                    cout << "Enter the book name: " << endl;
                    cin >> borrowname;
                    reader1.borrow_book(borrowname, library);
                    break;

                }
                case ('2'): {
                    cout << "Enter the book name: " << endl;
                    cin >> borrowname;
                    reader2.borrow_book(borrowname, library);
                    break;
                }
                case ('3'): {
                    cout << "Enter the book name: " << endl;
                    cin >> borrowname;
                    reader3.borrow_book(borrowname, library);
                    break;
                }
                case ('4'): {
                    cout << "Enter the book name: " << endl;
                    cin >> borrowname;
                    reader4.borrow_book(borrowname, library);
                    break;
                }
            }
        break;
    }
    case '3' : {
        cout << "Who wants to return the book? " << endl << "1. For the first reader" << endl;
        cout << "2. For the second reader" << endl << "3. For the third reader" << endl;
        cout << "4. For the fourth reader" << endl;
        cin >> returnbookreader;
        switch(returnbookreader) {
            case('1'):{
                cout << "Which book do you want to return? " << endl;
                cin>> returnname;
                reader1.return_book(returnname, library);
                break;
            }
            case('2'):{
                cout << "Which book do you want to return? " << endl;
                cin>> returnname;
                reader2.return_book(returnname, library);
                break;
            }
            case('3'):{
                cout << "Which book do you want to return? " << endl;
                cin>> returnname;
                reader3.return_book(returnname, library);
                break;
            }
            case('4'):{
                cout << "Which book do you want to return? " << endl;
                cin>> returnname;
                reader4.return_book(returnname, library);
                break;
            }
        }
        break;
    }
    case '4' : {
        cout << "Here is your information: " << endl;
        reader1.show_info();
        reader2.show_info();
        reader3.show_info();
        reader4.show_info();
        librarian.show_info();
        library.show_books();
        break;
    }
    default :{
        cout << "Please choose valid option" << endl;
        break;
    }
}
cout << "Do you want to continue? " << endl;
    cin >> ans;
}while (ans == "Yes" || ans == "yes");

}