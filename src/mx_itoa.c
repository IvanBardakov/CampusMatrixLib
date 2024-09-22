#include "../inc/libmx.h"

char *mx_itoa(int number) {

    if (number == -2147483648) {
        char *str = mx_strnew(11);
        if (str != NULL) {
            str = "-2147483648";
        }
        return str;
    }
    
    int temp = number;
    int length = (number <= 0) ? 1 : 0;
    while (temp != 0) {
        length++;
        temp /= 10;
    }

    char *str = mx_strnew(length);
    if (str == NULL) {
        return NULL;
    }

    if (number < 0) {
        str[0] = '-';
        number = -number;
    }

    while (length > 0 && str[length - 1] != '-') {
        str[--length] = (number % 10) + '0';
        number /= 10;
    }

    return str;
}
