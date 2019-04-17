// Name
// Section #
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "person.cpp"
#include "book.cpp"

using namespace std;

void printMenu() {
    cout << "----------Library Book Rental System----------" << endl;
    cout << "1.  Book checkout" << endl;
    cout << "2.  Book return" << endl;
    cout << "3.  View all available books" << endl;
    cout << "4.  View all outstanding rentals" << endl;
    cout << "5.  View outstanding rentals for a cardholder" << endl;
    cout << "6.  Open new library card" << endl;
    cout << "7.  Close library card" << endl;
    cout << "8.  Exit system" << endl;
    cout << "Please enter a choice: ";
}

// You are not obligated to use these function declarations - they're just given as examples
void readBooks(vector<Book *> & myBooks) {
    int id = 0;
    string bookName;
    string auth;
    string cat;
    string garbage;
    string line;
    ifstream inData;


    inData.open("books.txt");
    if (inData.is_open())
        while(inData >> id)
        {
          //cout << id << endl;
          getline(inData, garbage);// get rid of cin whitespace
          getline(inData, bookName);
          // cout << bookName <<endl;
          getline(inData, auth);
          // cout << auth <<endl;
          getline(inData, cat);
          // cout << cat <<endl;
          getline(inData, garbage); //get rid of new blank line
          myBooks.emplace_back(new Book(id,bookName,auth,cat));
      }
      // for(int i = 0; i<myBooks.size();i++)
      // {
      //   cout << myBooks.at(i)->getId() <<endl;
      // }
      inData.close();
}

int readPersons(vector<Person *> & myCardholders)
{
  string lName, fName;
  int cardNo = 0;
  bool act;
  int id = 0;

  ifstream inData;
  inData.open("persons.txt");
  while(inData >> cardNo >> act >> fName >> lName)
    {

      myCardholders.emplace_back(new Person(cardNo,act,fName,lName));
    }
    // for(int i = 0; i<myCardholders.size();i++)
    // {
    //   cout << myCardholders.at(i)->fullName() <<endl;
    // }
  id = myCardholders.back()->getId();
  return id;

  inData.close();
}

void readRentals(vector<Book *> & myBooks, vector<Person *> myCardholders) {
  int bookNo = 0;
  int cardNo = 0;

  ifstream inData;
  inData.open("rentals.txt");
  while(inData >> bookNo >> cardNo)
    {
      for(int i = 0; i<myBooks.size();i++)
      {
        if(myBooks.at(i)->getId() == bookNo)
        {
          for(int j = 0; j<myCardholders.size();j++)
          {
            if(myCardholders.at(j)->getId() == cardNo)
            {
              myBooks.at(i)->setPersonPtr(myCardholders.at(j));
            }
          }
        }
      }
    }

  inData.close();
}

void checkoutBooks(vector<Book *> & myBooks, vector<Person *> & myCardholders) {
  int cardID;
  int bookID;
  cout<<"Please enter the card ID: ";
  cin >> cardID;
  bool idfound = false;
  bool bidfound = false;
  //CHECK CARD ID
  for (int i = 0; i < myCardholders.size(); i++)
  {
    if(cardID == myCardholders.at(i)->getId())
    {
      idfound = true;
      cout <<"Cardholder: " << myCardholders.at(i)->fullName() <<endl;
      //CHECK IF BOOK IS THERE
      cout<<"Please enter the book ID: ";
      cin >> bookID;
      for (int i = 0; i < myBooks.size(); i++)
      {
        if(bookID == myBooks.at(i)->getId())
        {
          bidfound = true;
          cout << "Title: " << myBooks.at(i)->getTitle() << endl;
          //CHECK IS BOOK IS RENTED
          if(myBooks.at(i) ->getPersonPtr() == nullptr)
          {
            cout << "Rental Completed" <<endl;
          }
          else
          {
            cout << "Book already checked out" <<endl;
          }
        }
      }
      if(bidfound == false)
      {
        cout <<"Book ID not found";
      }
    }
  }

  if(idfound == false)
  {
    cout <<"Card ID not found";
  }
}

Book * returnBook(vector<Book *> myBooks, int id)
{

  bool bidfound = false;

  for (int i = 0; i < myBooks.size(); i++)
  {
    if(id == myBooks.at(i)->getId())
    {
      bidfound = true;
      cout << "Title: " << myBooks.at(i)->getTitle() << endl;
      myBooks.at(i)->setPersonPtr(nullptr);
        cout << "Return Completed" <<endl;
    }
  }

  if(bidfound == false)
  {
    cout <<"Book ID not found";
  }
}

void searchBook(vector<Book *> myBooks) {
  bool avail = false;
  for (int i = 0; i < myBooks.size(); i++)
  {
    if(myBooks.at(i)->getPersonPtr() == nullptr)
    {
      avail = true;
      cout << "Book ID: " << myBooks.at(i)->getId() << endl;
      cout << "Title: " << myBooks.at(i)->getTitle() << endl;
      cout << "Author: " << myBooks.at(i)->getAuthor() << endl;
      cout << "Category: " << myBooks.at(i)->getCategory() << endl;
      cout << endl;
    }
  }
  if (avail == false)
  {
    cout <<"No available books";
  }
}

void searchRentals(vector<Book *> myBooks,vector<Person*> myCardholders) {
  bool avail = false;
  for (int i = 0; i < myBooks.size(); i++)
  {
    if(myBooks.at(i)->getPersonPtr() != nullptr)
    {
      avail = true;
      cout << "Book ID: " << myBooks.at(i)->getId() << endl;
      cout << "Title: " << myBooks.at(i)->getTitle() << endl;
      cout << "Author: " << myBooks.at(i)->getAuthor() << endl;
      // for (int i = 0; i < myCardholders.size(); i++)
      // {

        cout << "Cardholder: " << myBooks.at(i)->getPersonPtr()->fullName() << endl;
        cout << "Card ID: " << myBooks.at(i)->getPersonPtr()->getId() << endl;
        cout << endl;
      //}

    }
  }
  if (avail == false)
  {
    cout <<"No available books";
  }
}
void searchRentalsPerson(vector<Book *> & myBooks, vector<Person *> myCardholders, int id) {
  bool idfound = false;
  bool rfound = false;

  for (int i = 0; i < myCardholders.size(); i++)
  {
    if(id == myCardholders.at(i)->getId())
    {
      idfound = true;
      cout << "Cardholder: " << myCardholders.at(i)->fullName() << endl;
      cout << endl;

      for(int j = 0; j < myBooks.size();j++)
      {
        if(myBooks.at(j)->getPersonPtr() == myCardholders.at(i))
        {
          rfound = true;
          cout << "Book ID: " << myBooks.at(j)->getId() << endl;
          cout << "Title: " << myBooks.at(j)->getTitle() << endl;
          cout << "Author: " << myBooks.at(j)->getAuthor() << endl;
        }
      }
      if(rfound == false)
      {
        cout <<"No books currently checked out";
      }
    }
  }
  if(idfound == false)
  {
    cout <<"Card ID not found";
  }

}

int openCard(vector<Person *> & myCardholders, int nextID, bool act, string firstname, string lastname)
{

    Person* person = new Person(nextID,act,firstname,lastname);
    myCardholders.push_back(person);
    cout << "Card ID " <<myCardholders.back()->getId() << " active" <<endl;
    cout << "Cardholder" << myCardholders.back()->fullName() << endl;
    return myCardholders.back()->getId() + 1;
}

int closeCard(vector<Person *> & myCardholders, int id)
{

  bool idfound = false;
  bool active = false;
  char choice = ' ';
  for (int i = 0; i < myCardholders.size(); i++)
  {
    if(id == myCardholders.at(i)->getId() && myCardholders.at(i)->isActive() == true)
    {
      idfound = true;
      cout << "Cardholder: " << myCardholders.at(i)->fullName() << endl;
      cout << "Are you sure you want to deactivate card (y/n)? ";
      cin >> choice;
      if(choice == 'y')
      {
        myCardholders.at(i)->setActive(active);
        cout << "Card ID deactivated";
        break;
      }
      else if (choice == 'n')
      {
        cout << "ok";
      }
      else
      {
        cout << "Invalid choice";
      }
    }
    else
    {
    if(id == myCardholders.at(i)->getId() && myCardholders.at(i)->isActive() == true)
      {
        cout << "Cardholder: " << myCardholders.at(i)->fullName() << endl;
        cout << "Card ID is already inactive";
      }
}
  }
  if(idfound == false)
    {
      cout <<"Card ID not found";
    }
}



int main()
{
    int bookID = 0;
    int cardID = 0;

    //for new card
    string fname, lname;
    bool active = true;
    bool newid = true;

    vector<Book *> books;
    vector<Person *> cardholders;
    readBooks(books);
    readPersons(cardholders);
    readRentals(books,cardholders);
    int uniqid = readPersons(cardholders);
    void printMenu();

    int choice;
    do
    {
        // If you use cin anywhere, don't forget that you have to handle the <ENTER> key that
        // the user pressed when entering a menu option. This is still in the input stream.
        printMenu();
        cin >> choice;
        switch(choice)
        {
            case 1:
                checkoutBooks(books,cardholders);
                break;

            case 2:
                // Book return

                cout<<"Please enter the book ID to return: ";
                cin >> bookID;
                returnBook(books, bookID);
                break;

            case 3:
                // View all available books
                searchBook(books);
                break;

            case 4:
                // View all outstanding rentals

                searchRentals(books,cardholders);
                break;

            case 5:
                // View outstanding rentals for a cardholder
                cout<<"Please enter the card ID: ";
                cin >> cardID;
                searchRentalsPerson(books,cardholders,cardID);
                break;

            case 6:
                // Open new library card

                cout<<"Please enter the the first name: ";
                cin >> fname;
                cout<<"Please enter the the last name: ";
                cin >> lname;


                for(int i = 0; i<cardholders.size();i++)
                {
                  if(cardholders.at(i)->fullName() == fname + " " +lname)
                  {
                    cardholders.at(i)->setActive(active);
                    cout << "Card ID " <<cardholders.at(i)->getId() << " active" <<endl;
                    cout << "Cardholder" << cardholders.at(i)->fullName() << endl;
                    newid = false;
                  }
                }
                if(newid == true)
                {
                uniqid = uniqid + 1;
                openCard(cardholders, uniqid, active, fname, lname);
                }

                break;

            case 7:
                // Close library card
                cout<<"Please enter the card ID: ";
                cin >> cardID;
                closeCard(cardholders,cardID);
                break;

            case 8:
                // Must update records in files here before exiting the program
                break;

            default:
                cout << "Invalid entry" << endl;
                break;
        }
        cout << endl;
   } while(choice != 8);
      return 0;
}
