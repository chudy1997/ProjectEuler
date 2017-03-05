//
// Created by Karol on 2017-02-13.
//

#include <iostream>
#include <math.h>
#include "FirstTenProblems.h"

//1.1
int findSumOfDividersOfXAndYBelowZ1(int x, int y, int z){
    int sum=0;
    for(int i=x;i<z;i+=x)sum+=i;
    for(int j=y;j<z;j+=y)if(j%x)sum+=j;
    return sum;
}

//1.2
int NWW(int x,int y){
    int tx=x,ty=y;
    int temp;
    while(y!=0)
    {
        temp = y;
        y = x%y;
        x = temp;
    }
    return tx/x*ty;
}
int findSumOfDividersOfXAndYBelowZ2(int x, int y, int z){
    int xy = NWW(x,y);
    return (int) ((x+z/x*x)*(z/x)/2.0+(y+z/y*y)*(z/y)/2.0-(xy+z/xy*xy)*(z/xy)/2.0-((z%x) && (z%y) && (z%y) ? 0 : z));
}

//2
long findSumOfFibsUnderBoardSatisfyingCondition(long board, bool condition(long)){
    long sum=0;
    long a=1,b=2,c;
    while(a<board){
        if(condition(a))sum+=a;
        c=b;
        b+=a;
        a=c;
    }
    return sum;
}

//3

bool isPrime(long long int x){
    if(x==2)return true;
    if(x<2 || !(x%2))return false;
    for(int i=3;i*i<=x;i+=2)if(!(x%i))return false;
    return true;
}

long long int findLargestPrimeFactorOfX(long long int x){
    for(long long int i=2;i<=x;i++){
        if(!(x%i) && isPrime(x/i))return x/i;
    }
    return -1;
}

//4
bool isPalidromic(std::string s){
    if(s.size()>1) {
        if (s.at(0) != s.at(s.size() - 1))return false;
        return isPalidromic(s.substr(1,s.size()-2));
    }
    return true;
}

int findLargestProductPalindromeFromNDigitsNumbers(int n){
    int max=(int) pow(10,n)-1,min=(int) pow(10,n-1);
    int largest=-1;

    for(int i=max;i>=min;i--)
        for(int j=i;j>=min;j--){
            if(isPalidromic(std::to_string(i*j)) && i*j>largest)largest=i*j;
        }
    return largest;
}

//5
int findSmallestNumberDividableByAllNumbersFrom1ToN(int n){
    for(int i=n;;i+=n)
        for(int j=1;j<=n;j++){
            if(i%j)break;
            if(j==n)return i;
        }
}

//LOL
//(1 + 2 + ... + n)^2 = n^2 * (n+1)^2 * 1/4
//1^2 + 2^2 + ... + n^2 = n * (n+1) * (2n+1) * 1/6

//6
long long int findDiffBetweenSquareOfSumAndSumOfSquaresOf1ToNNumbers(int n){
    long long int sumOfSquares=0,sumOfNumbers=0;
    for(int i=1;i<=n;i++){
        sumOfSquares+=i*i;
        sumOfNumbers+=i;
    }
    return sumOfNumbers*sumOfNumbers-sumOfSquares;
}

//7
int findNthPrimeNumber(int n){
    int index=1;
    for(int i=3;;i+=2) {
        if(isPrime(i))index++;
        if(index==n)return i;
    }
}

std::string s= "73167176531330624919225119674426574742355349194934"
        "96983520312774506326239578318016984801869478851843"
        "85861560789112949495459501737958331952853208805511"
        "12540698747158523863050715693290963295227443043557"
        "66896648950445244523161731856403098711121722383113"
        "62229893423380308135336276614282806444486645238749"
        "30358907296290491560440772390713810515859307960866"
        "70172427121883998797908792274921901699720888093776"
        "65727333001053367881220235421809751254540594752243"
        "52584907711670556013604839586446706324415722155397"
        "53697817977846174064955149290862569321978468622482"
        "83972241375657056057490261407972968652414535100474"
        "82166370484403199890008895243450658541227588666881"
        "16427171479924442928230863465674813919123162824586"
        "17866458359124566529476545682848912883142607690042"
        "24219022671055626321111109370544217506941658960408"
        "07198403850962455444362981230987879927244284909188"
        "84580156166097919133875499200524063689912560717606"
        "05886116467109405077541002256983155200055935729725"
        "71636269561882670428252483600823257530420752963450";

//8
long long int findNDigitNumberWithTheGreatestProduct(int n){
    long long int greatestProduct=0;
    for(int i=0;i<=s.size()-n;i++){
        long long int temp=1;
        for(int j=i;j<i+n;j++)temp*= std::stol(s.substr(j,1), nullptr);
        if(temp>greatestProduct){
            greatestProduct=temp;
        }
    }
    return greatestProduct;
}

//9
int findProductOfPythageoransTripleWithSumN(int n){
    for(int c=1;c<n;c++)
        for(int b=c-1;b>0;b--){
            int a=n-c-b;
            if(a*a+b*b==c*c)return a*b*c;
        }
    return 0;
}

//10
long long int findSumOfAllPrimesBelowN(int n) {
    long long int res = 2;
    for (int i = 3; i < n; i += 2)if (isPrime(i))res += i;
    return res;
}
