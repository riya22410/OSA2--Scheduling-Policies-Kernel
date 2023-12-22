#include <stdio.h>
#include <math.h>

int main() {
    unsigned long long count = 0; 
    unsigned long long max_count = pow(2, 32);

    while (count < max_count) {
        count++;
    }

    return 0;
}
