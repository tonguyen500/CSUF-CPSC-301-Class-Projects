#include<stdio.h>
#include<string>
#include<cstring>
#include<fstream>
#include<iostream>

using namespace std;

struct PERSON {
    char Name[20];
    float Balance;
};

void Display(PERSON ok[], int n)
{
    string str1;
    string str2;
    string sname;
    float num;


        ifstream inData;
        inData.open("data.txt");

            for (int i = 0; i < n; i++)
            {
                inData >> str1;
                inData >> str2;
                inData >> num;
                sname = str1 + " " + str2;
                strcpy(ok[i].Name, sname.c_str());
                ok[i].Balance = num;
                cout << ok[i].Name;
                cout << " " << ok[i].Balance << endl;
            }
        inData.close();


}

void FindRichest(PERSON ok[], int n)
{
        float max = 0.0;
        for (int i = 0; i < n; i++)
        {
            if (max < ok[i].Balance)
            {
                max = ok[i].Balance;

            }

        }
        cout << max << endl;

        for (int i = 0; i < n; i++)
        {
            if (max == ok[i].Balance)
            {
                cout << "The customer with the maximum balance is: " << ok[i].Name << endl;

            }

        }

}

void Deposit(char* customer, PERSON ok[], int n)
{
    float deposit = 0.0;
    float total = 0.0;
    for (int i = 0; i < n; i++)
      {
        if (strcmp(customer, ok[i].Name) == 0)
        {
            cout << ok[i].Name << " " << "How much would you like to deposit ?"<<endl;
            cin >> deposit;
            ok[i].Balance = ok[i].Balance + deposit;
            total = ok[i].Balance;
            cout << "Now your new balance is " << ok->Balance << endl;
            cout << "Now your new balance is " << total << endl;
        }

      }
}

void NewCopy(PERSON ok[], int n)
{
  ofstream myfile ("data.txt");
  if (myfile.is_open())
{
  for (int i = 0; i < n; i++)
  {
    myfile << ok[i].Name << " " << ok[i].Balance<<endl;

  }
myfile.close();
}
else cout << "Unable to open file";
}




int main()
{

  std::ifstream hello;
  hello.open("data.txt");
  PERSON ok;
  int entry = 0;
   while(hello>>ok.Name)    //while(hello>>ok.Name)
      {
      hello.getline(ok.Name, 20);

       entry++;
      }
int n =entry;


cout<<"The counter is :"<<n<<endl;
 PERSON P[n];

  char CustName[20];
  Display(P,n);
  FindRichest(P,n);
  cout << "Enter your full name to deposit money: ";
  cin.getline (CustName,20);
  Deposit(CustName,P,n);
  NewCopy(P,n);

}
