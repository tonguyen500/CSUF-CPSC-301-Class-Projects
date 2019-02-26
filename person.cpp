#include "person.h"

using namespace std;

Person::Person()
{
}
//getters and setters

//firstname
string Person::getFirstName()
{
  return firstName;
}

void Person::setFirstName(string fName)
{
  firstName = fName;
}

//lastname
string Person::getLastName()
{
  return lastName;
}

void Person::setLastName(string lName)
{
  lastName = lName;
}

//payrate
float Person::getPayRate()
{
  return payRate;
}

void Person::setPayRate(float rate)
{
  payRate = rate;
}

//hoursWorked
float Person::getHoursWorked()
{
  return hoursWorked;
}

void Person::setHoursWorked(float hours)
{
  hoursWorked = hours;
}

//totalPay
float Person::totalPay()
{
  return hoursWorked * payRate;
}

string Person:: fullName()
{
  return firstName + " " + lastName;
}
