export module helper;

double internal_divide_impl(double a, double b)
{
   return a / b;
}

export double divide(double a, double b)
{
   return internal_divide_impl(a, b);
}