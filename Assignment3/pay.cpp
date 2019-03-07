#include "person.h"
#include "person.cpp"
#include<string>
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<iomanip>

using namespace std;

void readData(vector<Person> &v)
{
  string fName;
  string lName;
  int    id;
  string coName;
  float  hours;
  float  rate;

  ifstream inData;
  inData.open("input.txt");
  if(inData.is_open())
  {
    Person obj;
    while(inData >> fName >> lName >> id >> coName >> hours>> rate)
    {
      obj.setFirstName(fName);
      obj.setLastName(lName);
      obj.setEmployeeId(id);
      obj.setCompanyName(coName);
      obj.setHoursWorked(hours);
      obj.setPayRate(rate);
      v.push_back(obj);
    }
    for(int i = 0; i<v.size();i++)
    {
      cout << v.at(i).fullName() <<endl;
    }

  }
}

void getCompanies(vector<Person> &v,vector<string> &v2 )
{
  for(int i = 0; i<v.size();i++)
  {

  v2.push_back(v.at(i).getCompanyName());
  }
//test
    // for(int i = 0; i<v2.size();i++)
    // {
    //   cout << v2[i] << endl;
    //
    // }
}

void printHighestPaid(vector<Person> &v)
{
  float max = 0.0;
  for(int i = 0; i<v.size();i++)
  {
    if(v[i].totalPay() > max)
    {
      max = v[i].totalPay();
    }
  }

    for(int i = 0; i<v.size();i++)
    {
      if(v[i].totalPay() == max)
      {
        cout << "Highest paid: " << v[i].fullName() << endl;
        cout << "Employee ID: " << v[i].getEmployeeId() << endl;
        cout << "Employer: " << v[i].getCompanyName() << endl;
        cout << "Total Pay: $" << fixed <<setprecision(2)<< v[i].totalPay() << endl;
      }
    }
  }

  void seperateAndSave(vector<Person> &v,vector<string> &v2 )
  {
    fstream myfile("Intel.txt");
    if (myfile.is_open())
    {
      float totalCompany = 0.0;
      for(int i = 0; i<v2.size();i++)
      {
        if(v2[i]== "Intel")
        {
          for(int j = 0; j<v.size();j++)
          {
            if(v[j].getCompanyName() == v2[i])
            {
              myfile <<v[j].fullName() << " " << v[j].getEmployeeId() << " " <<
              v[j].getCompanyName() << endl;
              myfile << "$" << fixed <<setprecision(2)<<v[j].totalPay() <<endl;
              totalCompany += v[j].totalPay();
            }
          }
          myfile << "Total $" <<fixed <<setprecision(2)<<totalCompany <<endl <<endl;
          break;
        }
      }
    }

    fstream myfile2("Boeing.txt");
    if (myfile2.is_open())
    {
      float totalCompany = 0.0;
      for(int i = 0; i<v2.size();i++)
      {
        if(v2[i]== "Boeing")
        {
          for(int j = 0; j<v.size();j++)
          {
            if(v[j].getCompanyName() == v2[i])
            {
              myfile2 <<v[j].fullName() << " " << v[j].getEmployeeId() << " " <<
              v[j].getCompanyName() << endl;
            myfile2 << "$"<<fixed <<setprecision(2)<< v[j].totalPay() <<endl;
              totalCompany += v[j].totalPay();
            }
          }
          myfile2 << "Total $" <<fixed <<setprecision(2)<<totalCompany <<endl <<endl;

          break;
        }
      }
    }

    fstream myfile3("Douglas.txt");
    if (myfile3.is_open())
    {
      float totalCompany = 0.0;
      for(int i = 0; i<v2.size();i++)
      {
        if(v2[i]== "Douglas")
        {
          for(int j = 0; j<v.size();j++)
          {
            if(v[j].getCompanyName() == v2[i])
            {
              myfile3 <<v[j].fullName() << " " << v[j].getEmployeeId() << " " <<
              v[j].getCompanyName() << endl;
            myfile3 << "$"<<fixed <<setprecision(2)<< v[j].totalPay() <<endl;
              totalCompany += v[j].totalPay();
            }
          }
          myfile3 << "Total $" <<fixed <<setprecision(2)<<totalCompany <<endl <<endl;

          break;
        }
      }
    }
    fstream myfile4("Raytheon.txt");
    if (myfile4.is_open())
    {
      float totalCompany = 0.0;
      for(int i = 0; i<v2.size();i++)
      {
        if(v2[i]== "Raytheon")
        {
          for(int j = 0; j<v.size();j++)
          {
            if(v[j].getCompanyName() == v2[i])
            {
              myfile4 <<v[j].fullName() << " " << v[j].getEmployeeId() << " " <<
              v[j].getCompanyName() << endl;
              myfile4 << "$"<< fixed <<setprecision(2)<<v[j].totalPay() <<endl;
              totalCompany += v[j].totalPay();
            }
          }
          myfile4 << "Total $" <<fixed <<setprecision(2)<<totalCompany <<endl <<endl;

          break;
        }
      }
    }
    fstream myfile5("HealthTech.txt");
    if (myfile5.is_open())
    {
      float totalCompany = 0.0;
      for(int i = 0; i<v2.size();i++)
      {
        if(v2[i]== "HealthTech")
        {
          for(int j = 0; j<v.size();j++)
          {
            if(v[j].getCompanyName() == v2[i])
            {
              myfile5 <<v[j].fullName() << " " << v[j].getEmployeeId() << " " <<
              v[j].getCompanyName() << endl;
              myfile5 << "$"<<fixed <<setprecision(2)<< v[j].totalPay() <<endl;
              totalCompany += v[j].totalPay();
            }
          }
          myfile5 << "Total $" <<fixed <<setprecision(2)<<totalCompany <<endl <<endl;

          break;
        }
      }
    }
  }



int main()
{
  vector<Person> employees;
  vector<string> companyNames;
  readData(employees);
  getCompanies(employees,companyNames);
  printHighestPaid(employees);
  cout<<endl;
  seperateAndSave(employees,companyNames);
  return 0;
}
