#include <iostream>
#include <math.h>
using namespace std;

bool is_prime(int number)
{
  bool isPrime = true;

  for(int i = 2; i <= number / 2; ++i)
  {
    if(number % i == 0)
    {
      isPrime = false;
      break;
    }
  }

  return isPrime;
}

int main()
{
  double number_sqrt, fractpart, intpart;
  bool is_input_valid = false;
  int start, end;

  do {
    cout << "Please enter start of range: ";
    cin >> start;
    cout << "Please enter end of range: ";
    cin >> end;

    if(start <= 0 || end <= 0) {
      cout << "start and end shoule be positive\n";
      continue;
    }

    if(start > end) {
      cout << "start shoule be less the end\n";
      continue;
    }

    is_input_valid = true;
  }while(!is_input_valid);

  for(int number = start; number < end; number++)
  {
    if(number == 1)
    {
      continue;
    }

    number_sqrt = sqrt(number);
    fractpart = modf(number_sqrt, &intpart);

    if(fractpart == 0 && is_prime(intpart))
    {
      cout << number <<  " is prime (sqrt is " << intpart << ")\n";
    }
  }

  return 1;
}

