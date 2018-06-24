// calculates fibonacci numbers
// author: Cohen Robinson
// created: 23/06/18

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fac(double n);
double fib(int k);
double gregory(int k);
double wallis(int k);
double euler(int k);
double hayashi(int k);

int main()
{
  int n;
  printf("Enter number of iterations to make:");
  scanf("%d", &n);

  double pi_greg = gregory(n);
  double pi_wallis = wallis(n);
  double pi_euler = euler(n);
  double pi_hayashi = hayashi(n);

  double err_greg = fabs(pi_greg - M_PI);
  double err_wallis = fabs(pi_wallis - M_PI);
  double err_euler = fabs(pi_euler - M_PI);
  double err_hayashi = fabs(pi_hayashi - M_PI);

  printf("%9s\t%14s\t%14s\n", "Name |", "Approximation", "Error");
  printf("-------------------------------------------------\n");
  printf("%9s\t%1.12f\t%1.12f\n", "Gregory |", pi_greg, err_greg);
  printf("%9s\t%1.12f\t%1.12f\n", "Wallis |", pi_wallis, err_wallis);
  printf("%9s\t%1.12f\t%1.12f\n", "Euler |", pi_euler, err_euler);
  printf("%9s\t%1.12f\t%1.12f\n", "Hayashi |", pi_hayashi, err_hayashi);

}

// gregory pi approximation
double gregory(int k){

  double pi_new = 0;
  int i = 0;
  double j = 0;

  for (i=1;i<=k;i++){
    pi_new += pow(-1, i+1) / (2*i-1);
  }
  return 4 * pi_new;
}

// wallis pi approximation
double wallis(int k){

  double pi_new = 1;
  int i = 0;
  double j = 0;

  for (i=1;i<=k;i++){
    j = (double)i;

    pi_new = pi_new * (2*j * 2*j)/ ((2*j - 1)*(2*j + 1));
  }
  return 2 * pi_new;
}

// euler pi approximation
double euler(int k){

  double pi_new = 0;
  int i = 0;
  double j;
  for (i=0;i<=k;i++){
    j = (double)i;
    pi_new += (fac(j)*pow(2, j+1)) / (fac(2*j+1));
  }
  return pi_new;
}

// hayashi pi approximation
double hayashi(int k){

  double pi_new = 0;
  int i = 0;
  double j = 0;

  for (i=1;i<=k;i++){
    pi_new += atan(1/fib(2*i+1));
  }
  return 4 * pi_new;
}

// factorial function
double fac(double n)
{
  if (n < 0) {
    printf("ERROR! You entered a number less than 0\n");
  }
  else if (n == 0 || n == 1) {
    return 1;
  }
  else {
    return n * fac(n-1);
  }
}

// calculates the kth fibonacci number
double fib(int k)
{
  int i;
  int fib2;
  int fib1 = 1;
  int fib0 = 1;

  for (i=2; i<k; i++) {     // i = 2 since k
    fib2 = fib1 + fib0;     // will be three or greater
    fib0 = fib1;            // and F(1) and F(2) are already defined
    fib1 = fib2;
  }
  return fib2;
}
