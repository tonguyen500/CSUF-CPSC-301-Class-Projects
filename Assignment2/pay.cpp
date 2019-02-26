#include "person.cpp"
#include<stdio.h>
#include <iostream>
#include <fstream>
using namespace std;

void readData(Person array[],int n)
{

  string lName, fName;
  float rate = 0.0 , hours = 0.0;
  ifstream inData;
  inData.open("input.txt");
  for(int i =0; i < n; i++)
  {

    inData >> fName >> lName >> rate >> hours;
    array[i].setFirstName(fName);
    array[i].getFirstName();

    array[i].setLastName(lName);
    array[i].getLastName();

    array[i].setPayRate(rate);
    array[i].getPayRate();

    array[i].setHoursWorked(hours);
    array[i].getHoursWorked();

  }
  inData.close();
}

void writeData(Person array[], int n)
{

  fstream myfile("output.txt");
  if(myfile.is_open())
  {
    for(int i = 0; i < n; i++)
    {
      // myfile << array[i].firstName << " " << array[i].lastName << " "
      // << array[i].payRate << " "<< array[i].hoursWorked << endl;
      if(array[i].totalPay() == array[i+1].totalPay())
      {
        cout << array[i].fullName() << " " << array[i].totalPay()<<endl;
        myfile << array[i].fullName() << " " << array[i].totalPay()<<endl;
        break;
      }
      else
      {
        cout << array[i].fullName() << " " << array[i].totalPay()<<endl;
        myfile << array[i].fullName() << " " << array[i].totalPay()<<endl;
      }
    }
  }
}

int main()

{
  int n = 20;
  Person E[n];
  readData(E, n);
  writeData(E,n);

  return 0;
}
