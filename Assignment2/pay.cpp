//Luan Nguyen
//Section 1
#include "person.cpp"
#include<stdio.h>
#include <iostream>
#include <fstream>
#include<vector>
using namespace std;

void readData(vector<Person> &v)
{

  string lName, fName;
  float rate = 0.0 , hours = 0.0;
  ifstream inData;
  inData.open("input.txt");
  while(inData >> fName >> lName >> rate >> hours)
    {

      v.emplace_back(fName,lName,rate,hours);
    }
  inData.close();
}

void writeData(vector<Person> &v)
{

  fstream myfile("output.txt");
  if(myfile.is_open())
  {
    for(int i = 0; i < v.size(); i++)
    {
      if(v[i].totalPay() == v[i+1].totalPay())
      {
        cout << v[i].fullName() << " " << v[i].totalPay()<<endl;
        myfile << v[i].fullName() << " " << v[i].totalPay()<<endl;
        break;
      }
      else
      {
        cout << v[i].fullName() << " " << v[i].totalPay()<<endl;
        myfile << v[i].fullName() << " " << v[i].totalPay()<<endl;
      }
    }
  }
}

int main()

{
  // int n = 20;
  // Person E[n];
  vector<Person> E;
  readData(E);
  writeData(E);

  return 0;
}
