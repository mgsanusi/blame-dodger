#define __USE_C99_MATH

#include <stdbool.h>
#include<stdio.h>
#include<math.h>

void initializeBinary();
void convertBin(unsigned long int decimalNumber);
void printbinary();
unsigned long long int calculateBase(int base) ;
bool checkComposite(unsigned long long int number,unsigned long long int *divisor);
unsigned long long int power(unsigned long long int base, int exponent);
bool isJamCoin();

int bin[32], maxPlace;
unsigned long long basepair[9];

void initializeBinary() {
	int place = 0;
	maxPlace = 0;
	for(place = 0; place<32; place++) {
		bin[place] = 0;
	}
}

void convertBin(unsigned long int decimalNumber) {
	unsigned long  int quot, rem;
	int place = 0;
	unsigned long int number = decimalNumber;
	initializeBinary();
	quot = rem = 0;
	while(number!=0) {
		quot = number/2;
		rem = number%2;
		bin[place] = rem;
		number = quot;
		place++;
	}
	maxPlace = place-1;
}

void printbinary() {
	int idx;
	for(idx =maxPlace; idx>= 0; idx--){
		printf("%d",bin[idx]);
	}
}

unsigned long long int calculateBase(int base) {
    int idx = 0;
    unsigned long long int baseNumber = 0;
    for(idx = 0; idx<=maxPlace; idx++){
        baseNumber += (power(base,idx))*bin[idx];
    }
    return baseNumber;
}

unsigned long long int power(unsigned long long int base, int exponent) {
    int cnt = 0;
    unsigned long long int number = 1;
    for(cnt = 0; cnt<exponent; cnt++) {
        number = number*base;
    }
    return number;
}

double squareRoot(unsigned long long n){
  double x = n;
  double y = 1;
  double e = 1; 
  while(x - y > e)
  {
    x = (x + y)/2;
    y = n/x;
  }
  return x;
}

bool checkComposite(unsigned long long int number,unsigned long long int *divisor) {
    unsigned long long int idx = 0;    
    for(idx = 2; idx<(unsigned long int)squareRoot(number); idx++) {
        if((number%idx) == 0) {
            *divisor = idx;
            return true;
        }
    }
    return false;
}

bool isJamCoin() {
    int base =2;
    unsigned long long int divisor = 0;
    if(bin[0]!=1)
        return false;
    for(base = 2; base<=10; base++){
        if(!checkComposite(calculateBase(base), &divisor))
            return false;
        else{
            basepair[base-2] = divisor;
        }
    }
    return true;
}

void createJamCoin(int digits, int number_of_coins){
    unsigned long int minPossibility = (int)pow(2,digits-1);
    unsigned long int maxPossibility = (int)pow(2,digits)-1;
    unsigned long int cnt = 0;
    int base =0;
    int numberOfJamCoinsFound = 0;
    for(cnt = minPossibility; cnt<=maxPossibility; cnt++) {
        if(numberOfJamCoinsFound >= number_of_coins) {
            break;
        }
        convertBin(cnt);
        if(isJamCoin()){
            printf("\n");
            printbinary();
            for(base =2; base<=10; base++) {
                printf(" %llu",basepair[base-2]);
            }
            numberOfJamCoinsFound++;
        }
    }
}

int main() {
    int TestCaseCount, cnt, length, numberOfCoins;
    length = numberOfCoins = TestCaseCount = cnt = 0;
    FILE*   fpIn = freopen("in", "r+", stdin);
    FILE*   fpOut = freopen("out", "w+", stdout);
    scanf("%d",&TestCaseCount);
    
    for(cnt = 0; cnt<TestCaseCount; cnt++) {
        scanf("%d %d",&length,&numberOfCoins);
        if(cnt!=0)
            printf("\n");
        printf("Case #%d:", cnt+1);
        createJamCoin(length,numberOfCoins);
    }
    
    fclose(fpIn);
    fclose(fpOut);
    
    return 0;    
}

 

