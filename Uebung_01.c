#include <stdio.h>

/**
 * Prints bit of stuff. Highest bit is printed first, platform indepented
 * @param stuff
 * @author  Moritz Schleunes
 */
void printInBinaryFancy(unsigned int stuff) {

    for (int j = sizeof(stuff) * 8 - 1; j >= 0; --j) printf("%d", (stuff >> j) & 1);


    printf("\n");
}

/**
 * Prints the first 16 bit, the highest bit is printed first.
 * @author Moritz Schleunes
 */
void solveAufgabe1(void) {

    unsigned int stuff;
    scanf("%d", &stuff);

    printf("%d", (stuff >> 15) & 1);
    printf("%d", (stuff >> 14) & 1);
    printf("%d", (stuff >> 13) & 1);
    printf("%d", (stuff >> 12) & 1);
    printf("%d", (stuff >> 11) & 1);
    printf("%d", (stuff >> 10) & 1);
    printf("%d", (stuff >> 9) & 1);
    printf("%d", (stuff >> 8) & 1);
    printf("%d", (stuff >> 7) & 1);
    printf("%d", (stuff >> 6) & 1);
    printf("%d", (stuff >> 5) & 1);
    printf("%d", (stuff >> 4) & 1);
    printf("%d", (stuff >> 3) & 1);
    printf("%d", (stuff >> 2) & 1);
    printf("%d", (stuff >> 1) & 1);
    printf("%d\n", (stuff >> 0) & 1);
}

/**
 * Switches the right n bits from x starting at p, with the first n bits from y
 * @author Moritz Schleunes
 */
void solveAufgabe2(void) {
    unsigned int p = 5, n = 3, x = 183, y = 26;
    unsigned int ybitMask = ~0, xbitMask;

    printf("Enter p n x y\n");

    // scanf("%d %d %d %d", &p, &n, &x, &y);

    printf("p %d n %d x %d y %d\n", p, n, x, y);

    //bitmask for the first n bits
    ybitMask = ~ (ybitMask << (n));
    //we know we need n bits, so we can reuse ybitmask we just need to shift it to the position p, invert it because we want to delete the bits between position p and n
    xbitMask = ~(ybitMask << (p - n + 1));
    //zero the bits we want to override
    x &= xbitMask;
    //get the startin n bits we want, zero the others
    y &= ybitMask;
    //shift the bits to position p
    y <<= (p - n + 1);
    //concat x with y
    x ^= y;

    printf("x=");
    printInBinaryFancy(x);

}

int main() {
    solveAufgabe2();
    return 0;
}

