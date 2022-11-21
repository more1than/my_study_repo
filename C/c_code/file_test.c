#include <stdio.h>
#define SQUARE(X) X *X
#define PRINT(X) printf("the value of " #X " is %d\n", X)
#define CAT(X, Y) X##Y

int main()
{
    int Class84 = 2022;
    printf("%d\n", CAT(Class, 84));
    return 0;
}