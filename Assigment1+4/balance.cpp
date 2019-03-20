//Luan Nguyen
//Section 1
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

PERSON *readData(int & N )
{
    string str1;
    string str2;
    string sname;
    float num;
    PERSON *array = NULL;
    array = new PERSON[N];


        ifstream inData;
        inData.open("data.txt");

            for (int i = 0; i < N; i++)
            {
                inData >> str1;
                inData >> str2;
                inData >> num;
                sname = str1 + " " + str2;
                strcpy(array[i].Name, sname.c_str());
                array[i].Balance = num;
                cout << array[i].Name;
                cout << " " << array[i].Balance << endl;
            }
        inData.close();
return array;

}

void FindRichest(PERSON *ok, int n)
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

void Deposit(PERSON *ok, int n, const char* customer, float amount)
{

    float total = 0.0;
    bool found = false;
    for (int i = 0; i < n; i++)
      {
        if (strcmp(customer, ok[i].Name) == 0)
        {
            total = ok[i].Balance + amount;
            ok[i].Balance = total;
            cout << "Now your new balance is " << total << endl;
            found = true;
        }
      }
      if(found == false)
      {
        cout <<"Record not found" <<endl;
      }
}

void NewCopy(PERSON *ok, int n)
{
  ofstream myfile ("data.txt");
  if (myfile.is_open())
{
  for (int i = 0; i < n; i++)
  {
    myfile << ok[i].Name << " " << ok[i].Balance<<endl;

  }
myfile.close();
cout <<"File updated...";
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

  PERSON *P= NULL;

  char CustName[20];
  float deposit = 0.0;
  readData(n);
  P = readData(n);
  FindRichest(P,n);
   cout << "Enter your full name to deposit money: ";
   cin.getline (CustName,20);
   cout << "\t" << CustName << " " << "How much would you like to deposit?"<<endl;
   cin >> deposit;

  Deposit(P,n,CustName,deposit);
  NewCopy(P,n);

  delete P;
  P = nullptr;
}
