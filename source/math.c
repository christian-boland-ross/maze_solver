double sqrt(double n)
{
    if (n < 0) return -1;
    if (n == 0) return 0;

    double x = n;
    double y = (x + 1) / 2;

    while (y < x)
    {
        x = y;
        y = (x + n / x) / 2;
    }

    return x;
}

double sin(double angle) // takes radians
{
    double result = 0;
    double term = angle; // first term in the series
    int n = 1; // term index

    while (term > 0.00001 || term < -0.00001) // continue until the term is very small
    {
        result += term;
        n += 2; // move to the next odd number
        term *= -angle * angle / (n * (n - 1)); // calculate the next term in the series
    }

    return result;
}

double cos(double angle) // takes radians
{
    double result = 1;
    double term = 1; // first term in the series
    int n = 0; // term index

    while (term > 0.00001 || term < -0.00001) // continue until the term is very small
    {
        n += 2; // move to the next even number
        term *= -angle * angle / (n * (n - 1)); // calculate the next term in the series
        result += term;
    }

    return result;
}

double absolute(double n)
{
    return (n < 0) ? -n : n;
}