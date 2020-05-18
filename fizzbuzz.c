#include <stdio.h>
#include <stdbool.h>
#include <sys/resource.h> // for benchmarking

// upper bound: FizzBuzz will be played from 1 to N
#define N 1000000000

// prototypes
double calculate(const struct rusage *b, const struct rusage *a);
void fizzbuzz1(void);
void fizzbuzz2(void);

int main(void)
{
  struct rusage before, after;
  struct timeval start, end;

  getrusage(RUSAGE_SELF, &before);
  fizzbuzz1();
  getrusage(RUSAGE_SELF, &after);
  float first_time = calculate(&before, &after);

  getrusage(RUSAGE_SELF, &before);
  fizzbuzz2();
  getrusage(RUSAGE_SELF, &after);
  float second_time = calculate(&before, &after);

  printf("\nTIME IN fizzbuzz1: %.2fs\n", first_time);
  printf("TIME IN fizzbuzz2: %.2fs\n", second_time);
}

void fizzbuzz1(void)
{
  for (unsigned int i = 1; i <= N; i++)
  {
    bool div_three = i % 3 == 0;
    bool div_five = i % 5 == 0;

    if (div_three && div_five)
    {
      //puts("FizzBuzz");
    }
    else if (div_three)
    {
      //puts("Fizz");
    }
    else if (div_five)
    {
      //puts("Buzz");
    }
    else
    {
      //printf("%i\n", i);
    }
  }
}

void fizzbuzz2(void)
{
  char *strings[3] = {"Fizz", "Buzz", "FizzBuzz"};
  int num_to_string[15] = {-1, -1, 0, -1, 1, 0, -1, -1, 0, 1, -1, 0, -1, -1, 2};

  for (unsigned int i = 0; i <= N; i+=15)
  {
    for (unsigned int j = 1; j <= 15 && i+j <= N; j++)
    {
      if (num_to_string[j-1] == -1)
      {
        // for benchmark: include calculation if not printing
        int k = i + j;
        //printf("%i\n", i + j);
      }
      else
      {
        // for benchmark: include string lookup when not printing
        char * s = strings[num_to_string[j-1]];
        //puts(strings[num_to_string[j-1]]);
      }
    }
  }
}

// returns number of seconds between a and b
double calculate(const struct rusage *b, const struct rusage *a)
{
  if (b == NULL || a == NULL)
  {
    return 0.0;
  }
  else
  {
    return ((((a->ru_utime.tv_sec * 1000000 + a->ru_utime.tv_usec) -
              (b->ru_utime.tv_sec * 1000000 + b->ru_utime.tv_usec)) +
             ((a->ru_stime.tv_sec * 1000000 + a->ru_stime.tv_usec) -
              (b->ru_stime.tv_sec * 1000000 + b->ru_stime.tv_usec)))
            / 1000000.0);
  }
}
