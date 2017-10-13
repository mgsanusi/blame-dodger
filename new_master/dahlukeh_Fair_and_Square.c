#include <stdio.h>
#include <stdlib.h>

#define TRUE         1
#define FALSE        0

void handleCase();

long long a, b;

char numSmall[200];

long long findNum (long long start);

int numDigits (long long num);
long long getPal (long long base, int digits);
void writeNumber (long long num, char *buf);
long long readNumber (char *buf);

int isPal (long long num);

int main() {
   freopen ("cin.txt", "r", stdin);
   freopen ("cout.txt", "w", stdout);
   int n;
   scanf ("%d ", &n);
   int i;
   for (i = 0; i < n; i++) {
      printf ("Case #%d: ", i + 1);
      handleCase();
   }
   return 0;
}



void handleCase() {
   scanf ("%I64d %I64d ", &a, &b);
   long long result = findNum (b) - findNum (a - 1);
   printf ("%I64d\n", result);
}



long long findNum (long long start) {
   long long cur;
   long long total = 0ll;
   int i, j;
   for (i = 1; ; i++) {
      cur = 1ll;
      for (j = 0; j < ((i - 1) / 2); j++) {
         cur *= 10ll;
      }
      long long end = cur * 10ll;
      for (; cur < end; cur++) {
         long long pal = getPal (cur, i);
         if (pal * pal > start) {
            return total;
         }
         if (isPal (pal * pal)) {
            total++;
         }
      }
   }
   return total;
}


long long getPal (long long base, int digits) {
   writeNumber (base, numSmall);
   int i;
   for (i = digits - 1; i >= 0; i--) {
      numSmall[i] = numSmall[digits - i - 1];
   }
   numSmall[digits] = '\0';
   return readNumber (numSmall);
}


int isPal (long long num) {
   writeNumber (num, numSmall);
   int dig = numDigits (num);
   int i;
   for (i = 0; i < dig; i++) {
      if (numSmall[i] != numSmall[dig - i - 1]) {
         return FALSE;
      }
   }
   return TRUE;
}


int numDigits (long long num) {
   int i = 1;
   long long cur = 10ll;
   for (; cur <= num; i++) {
      cur *= 10ll;
   }
   return i;
}


void writeNumber (long long num, char *buf) {
   int numDig = numDigits (num);
   int i;
   buf[numDig] = '\0';
   for (i = 0; i < numDig; i++) {
      char dig = (num % 10ll) + '0';
      buf[numDig - i - 1] = dig;
      num /= 10ll;
   }
}


long long readNumber (char *buf) {
   long long num = 0ll;
   int i;
   for (i = 0; buf[i] != '\0'; i++) {
      num *= 10ll;
      num += (buf[i] - '0');
   }
   return num;
}
