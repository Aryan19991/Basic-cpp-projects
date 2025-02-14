#include <iostream>
using namespace std;

enum Level
{
  sunday,
  monday,
  tuesday,
  wednesday,
  thrusday,
  friday,
  saturday
};

int main()
{
  enum Level myVar = saturday;
  cout << myVar;
  return 0;
}