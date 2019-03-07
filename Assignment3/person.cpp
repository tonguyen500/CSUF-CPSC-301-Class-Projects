#include "person.h"
#include<string>
#include<iostream>
#include<fstream>
#include<stdio.h>

using namespace std;

Person::Person()
{}

//getters and setters
//firstName
void   Person::setFirstName(string fName)
{
  firstName = fName;
}
string Person::getFirstName()
{
  return firstName;
}

//lastName
void   Person::setLastName(string lName)
{
  lastName = lName;
}
string Person::getLastName()
{
  return lastName;
}

//employeeID
void   Person::setEmployeeId(int id)
{
  employeeID = id;
}
int    Person::getEmployeeId()
{
  return employeeID;
}

//companyName
void   Person::setCompanyName(string coName)
{
  companyName = coName;
}
string Person::getCompanyName()
{
  return companyName;
}

//payRate
void   Person::setPayRate(float rate)
{
    payRate = rate;
}
float  Person::getPayRate()
{
  return payRate;
}

//hoursWorked
void   Person::setHoursWorked(float hours)
{
    hoursWorked = hours;
}
float  Person::getHoursWorked()
{
  return hoursWorked;
}

//totalPay
float  Person::totalPay()
{
  return hoursWorked*payRate;
}
string Person::fullName()
{
  return firstName + " " + lastName;
}
