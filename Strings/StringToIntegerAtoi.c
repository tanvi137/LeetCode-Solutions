int myAtoi(char* s) {
    int i = 0;
    int sign = 1;
    int result = 0;

    while (s[i] == ' ')
        i++;

    if (s[i] == '-' || s[i] == '+') {
        if (s[i] == '-')
            sign = -1;
        i++;
    }

    while (s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';

        if (result > 214748364 ||
            (result == 214748364 && digit > 7)) {
            return sign == 1 ? 2147483647 : -2147483647 - 1;
        }

        result = result * 10 + digit;
        i++;
    }

    return result * sign;
}
