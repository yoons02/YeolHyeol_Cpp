#include <iostream>
using namespace std;

class Book{
private:
    char* title;
    char* isbn;
    int price;
public:
    Book(char* Btitle, char* Bisbn, int Bprice) : price(Bprice) {
        title = new char[strlen(Btitle)+1];
        strcpy(title, Btitle);

        isbn = new char[strlen(Bisbn)+1];
        strcpy(isbn, Bisbn);
    }

    ~Book(){
        delete[] title;
        delete[] isbn;
    }

    char* GetTitle(){
        return title;
    }

    char* GetIsbn(){
        return isbn;
    }

    int GetPrice(){
        return price;
    }

    void ShowBookInfo(){
        cout << "Title: " << GetTitle() << endl;
        cout << "ISBN: " << GetIsbn() << endl;
        cout << "Price: " << GetPrice() << endl;
    }
};

class EBook : public Book {
private:
    char* DRMkey;
public:
    EBook(char* Btitle, char* Bisbn, int Bprice, char* Edrmkey)
    : Book(Btitle, Bisbn, Bprice) {
        DRMkey = new char[strlen(Edrmkey)+1];
        strcpy(DRMkey, Edrmkey);
    }

    ~EBook(){
        delete[] DRMkey;
    }

    char* GetDRM(){
        return DRMkey;
    }

    void ShowEbookInfo(){
        ShowBookInfo();
        cout << "DRM key: " << GetDRM() << endl;
    }
};

int main(){
    Book book("좋은 Cpp", "555-12345-890-1", 20000);
    book.ShowBookInfo();
    cout << endl;

    EBook ebook("좋은 Cpp", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    ebook.ShowEbookInfo();

    cout << endl;
}