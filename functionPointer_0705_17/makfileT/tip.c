#include <stdio.h>

#include "get_double.h"

int main() {
    double price, tip;
    /*printf("Enter price meal: ");*/
    /*scanf("%lf", &price);*/

    /*printf("Enter tip amout (percent): ");*/
    /*scanf("%lf", &tip);*/

    price = get_double("Enter price meal: ", 0, 1000);
    tip = get_double("Enter tip amount (percent): ", 0, 100);

    double tipAmt = price * tip / 100.0;
    double total = price + tipAmt;
    printf("Tip: %lf\n", tipAmt);
    printf("Total: %lf\n", total);
}
