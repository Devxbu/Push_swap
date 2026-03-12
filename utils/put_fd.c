#include "../push_swap.h"

void putstr_fd(char *s, int fd) {
  int i;

  i = 0;
  while (s[i])
    i++;
  write(fd, s, i);
}

void putnbr_fd(int n, int fd) {
  char c;

  if (n == -2147483648) {
    write(fd, "-2147483648", 11);
    return;
  }
  if (n < 0) {
    write(fd, "-", 1);
    n = -n;
  }
  if (n >= 10)
    putnbr_fd(n / 10, fd);
  c = (n % 10) + '0';
  write(fd, &c, 1);
}

void putfloat_fd(double n, int fd) {
  int int_part;
  int frac;

  if (n < 0) {
    write(fd, "-", 1);
    n = -n;
  }
  int_part = (int)n;
  putnbr_fd(int_part, fd);
  write(fd, ".", 1);
  frac = (int)((n - int_part) * 100 + 0.5);
  if (frac < 10)
    write(fd, "0", 1);
  putnbr_fd(frac, fd);
}