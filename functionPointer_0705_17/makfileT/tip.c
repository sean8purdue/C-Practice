#include <stdio.h>

int main() {
    double price, tip;
    printf("Enter price meal: ");
    scanf("%lf", &price);

    printf("Enter tip amout (percent): ");
    scanf("%lf", &tip);

    double tipAmt = price * tip / 100.0;
    double total = price + tipAmt;
    printf("Tip: %lf\n", tipAmt);
    printf("Total: %lf\n", total);
}
