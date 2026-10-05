int divide(int dividend, int divisor) {
    if (dividend == -2147483648 && divisor == -1)
        return 2147483647;

    long long a = dividend;
    long long b = divisor;

    int negative = 0;

    if (a < 0) {
        a = -a;
        negative = !negative;
    }

    if (b < 0) {
        b = -b;
        negative = !negative;
    }

    long long quotient = 0;

    for (int i = 31; i >= 0; i--) {
        if ((b << i) <= a) {
            a -= (b << i);
            quotient += (1LL << i);
        }
    }

    if (negative)
        quotient = -quotient;

    if (quotient > 2147483647)
        return 2147483647;

    if (quotient < -2147483648LL)
        return -2147483648LL;

    return (int)quotient;
}
