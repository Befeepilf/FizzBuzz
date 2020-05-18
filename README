# Benchmarking two FizzBuzz algorithms

In the source code all commands writing to stdout (`puts` and `printf`) are commented out because they are slow.

## Algorithm 1 (fizzbuzz1)

```c
for (unsigned int i = 1; i <= N; i++) {
  bool div_three = i % 3 == 0;
  bool div_five = i % 5 == 0;

  if (div_three && div_five) {
    puts("FizzBuzz");
  }
  else if (div_three) {
    puts("Fizz");
  }
  else if (div_five) {
    puts("Buzz");
  }
  else {
    printf("%i\n", i);
  }
}
```

This is probably the most intuitive and straight-forward way to implement FizzBuzz. But it has an issue: **The modulo operator is expensive.**

So how can we do better? Let's take a look at the second algorithm.


## Algorithm 2 (fizzbuzz2)

```c
char *strings[3] = {"Fizz", "Buzz", "FizzBuzz"};
int num_to_string[15] = {-1, -1, 0, -1, 1, 0, -1, -1, 0, 1, -1, 0, -1, -1, 2};

for (unsigned int i = 0; i <= N; i+=15) {
  for (unsigned int j = 1; j <= 15 && i+j <= N; j++) {
    if (num_to_string[j-1] == -1) {
      printf("%i\n", i + j);
    }
    else {
      puts(strings[num_to_string[j-1]]);
    }
  }
}
```

Since 15 is the smallest number which is divisible by 3 and 5, every multiple of 15 is also divisible by both 3 and 5. Hence the same pattern will occur every 15 iterations. This means we can save some computation time by computing this pattern once and storing it in memory.


## Results

For `N = 1000000000` these are the results of the benchmark (without printing) running it on an Intel(R) Core(TM) i5-3320M:
```
TIME IN fizzbuzz1: 10.57s
TIME IN fizzbuzz2: 4.09s
```
