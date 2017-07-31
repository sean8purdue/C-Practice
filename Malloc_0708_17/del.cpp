#include <stdio.h>
#include <iostream>

using namespace std;

int main () {
   double* pvalue  = NULL; // Pointer initialized with null
   pvalue  = new double;   // Request memory for the variable
 
   *pvalue = 29494.99;     // Store value at allocated address
   cout << "Value of pvalue : " << *pvalue << endl;

   delete pvalue;         // free up the memory.
   //deete do not delete the content of pointer pointed to.
   cout << "Value of pvalue after free : " << *pvalue << endl;
   fprintf(stderr, "Value of pvalue after free : %f\n", *pvalue);


   *pvalue = 29494.99;     // Store value at allocated address
   cout << "Value of pvalue : " << *pvalue << endl;

   double* pv = NULL;
   pv = new double;
   *pv = 1.0;
   cout << "value of pv : " << *pv << endl;

   *pvalue = 29494.99;     // Store value at allocated address
   cout << "Value of pvalue : " << *pvalue << endl;

   return 0;
}
