#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <cmath>

union ieee754_hex {
   unsigned int hex;
   struct {
        unsigned int fraction:23;
        unsigned int exponent:8;
        unsigned int s:1;
   } ieee;
 };

using namespace std;

int main(int argc, char *argv[])
{
  union ieee754_hex num;
  int i;
  double fval, decimal;

  for (i=1; i < argc; i++) {

     sscanf(argv[i],"%x", &(num.hex));
	fval=pow((double)2.0,(double)(num.ieee.exponent-127));
	decimal=pow(-1,num.ieee.s)*(1+num.ieee.fraction *
		(pow((double)2,(double)-23.0))) *fval;

     cout << "For hexademical number 0x" << hex << num.hex << "\n";
     cout << "\tSign bit:    0x" << hex << num.ieee.s << "(" 
	  << dec << num.ieee.s << ")\n";
     cout << "\tExponent:    0x" << hex << num.ieee.exponent 
	  << "(" << dec << num.ieee.exponent << ")\n";
     cout << "\tFraction:    0x" << hex << num.ieee.fraction 
	  << "(" << dec << num.ieee.fraction << ")\n";

	cout << "\tDecimal Value:  " <<scientific << decimal << endl;
  }
  return 0;
}
