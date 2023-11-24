#include "myBazooka.h"
bool isPrime(int num) // checks if a number is prime or not
{
    if(num == 2)
        return true;
    if (num % 2 != 0)
    {
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
                return false;
        }
        return true;
    }
    else
        return false;
}
bool isPalindrome(int num) // checks if a number is palindrome or not
{
    int checkNum{0}, digits{0}, log{num};

    while (log)
    {
        log /= 10;
        digits++;
    }
    log = num;
    while (digits--)
    {
        checkNum += (log % 10) * pow(10, digits);
        log /= 10;
    }
    return ((num - checkNum) == 0 ? true : false);
}
void printAscii() // prints ascii
{
    for (int i{0}; i < 129; i++)
    {
        std::cout << (char)i << " : " << i << '\n';
    }
}
void pascalTriangle(int n) // prints Pascal Triangle
{
    std::vector<int> row = {1}; // Initialize the first row
    for (int i = 1; i <= n; i++)
    {
        // Print spaces to align the output
        std::cout << std::setw(n - i + 1);
        // Print the current row
        for (int j : row)
            if (j != 0) // Print only non-zero elements
                std::cout << j << " ";
        std::cout << std::endl;
        // Update the current row for the next iteration
        // Add 0 at the beginning and end of the row
        row.insert(row.begin(), 0);
        row.push_back(0);
        // Calculate the new values based on the previous row
        for (int k = 0; k < i; k++)
            row[k] = row[k] + row[k + 1];
    }
}
int findinLCM(int num1, int num2) // returns LCM of two numbers
{
    int log{num1};
 
        if (!isPrime(num1) and !isPrime(num2))
        {
            for (int i{2}; i < (num1 / 2); i++)
            {
                if (isPrime(i) and (num1 % i == 0) and (num2 % i == 0))
                {
                    num1 /= i;
                    num2 /= i;
                }
            }
            return log * num2;
        }
        else
            return num1 * num2;
}
long long baseConversionToDecimal(long long preValue, int baseInfo) //inefficient during conversion from hexa to decimal 
{
    long long postValue{0}, power{0};
    while (preValue)
    {
        if ((preValue % 10) >= baseInfo)
        {
            postValue = -1;
            break;
        }
        postValue += (preValue % 10) * pow(baseInfo, power);
        preValue /= 10;
        power++;
    }
    return postValue;
}
long long baseConversionFromDecimal(long long preValue, int baseInfo) //Argument preValue is the convertable decimal, baseInfo represents the destinition base
//inefficient during conversion from decimal to hexa
{
    long long postValue{0}, power{0}, midValue{0};

    while (midValue < preValue)
    {
        midValue = pow(baseInfo, power);
        power++;
    }
    power -= 2;
    while (power >= 0)
    {
        postValue += static_cast<long long>(preValue / pow(baseInfo, power)) * pow(10, power);
        preValue = preValue % static_cast<long long>(pow(baseInfo, power));
        while (midValue > preValue)
        {
            power--;
            midValue = pow(baseInfo, power);
        }
    }
    return postValue;
}