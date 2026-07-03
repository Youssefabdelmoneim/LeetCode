class Solution
{
public:
  int minimizeXor(int num1, int num2)
  {
    int numOfOnes = 0;
    for (int i = 0; i < 32; i++)
    {
      if ((1 << i) & num2)
        numOfOnes++;
    }

    int res = 0;

    for (int i = 31; i >= 0; i--) // put ones in front of 1's  in num1 as many times as possible
    {
      if (((1 << i) & num1) && numOfOnes)
      {
        res += (1 << i);
        numOfOnes--;
      }
    }
    for (int i = 0; i < 32; i++) // put extra ones in front of 0's in num1 // from the smallest to largest
    {
      if (!((1 << i) & num1) && numOfOnes)
      {
        res += (1 << i);
        numOfOnes--;
      }
    }

    return res;
  }
};