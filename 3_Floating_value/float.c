#include <stdio.h>

int main(void)
{
    float f = 3.14f;      // single precision
    double d = 3.14;     // double precision

    printf("Float value  : %.7f\n", f);
    printf("Double value : %.15f\n", d);

    printf("Size of float  : %lu bytes\n", sizeof(float));
    printf("Size of double : %lu bytes\n", sizeof(double));

    return 0;
}



///
Float value  : 3.1400001
Double value : 3.140000000000000
Size of float  : 4 bytes
Size of double : 8 bytes
///
