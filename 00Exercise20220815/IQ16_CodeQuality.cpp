
#include <iostream>
// #include <algorithm>  //std::equal 比较两个范围内数是否全相等

using namespace std;

bool g_invalidinput = false;
bool Equal(double num1, double num2);// 对自己定义的equal函数进行声明

double Power(double& base, int& exponent)
{
      g_invalidinput = false; // add
      
      double result = 1.0;
      if(exponent == 0)
      {
            result = 1.0;
      }else if(exponent > 0) // include equal(base, 0.0)
      {
            for(int i = 1; i <= exponent; i++)
            {
                  result *= base;
            }
      }else{
            // if(base == 0.0)
            if(Equal(base, 0.0))  // 自己定义的equal函数
            {
                  g_invalidinput = true; // add
                  return 0.0;
            }
            for(int i = -1; i >= exponent; i--)
            {
                  result *= base;
            }
            result = 1/result;
      }

      return result;
}
// #include <cmath>
// fabs(num1 - num2) < 0.0000001
// 自己定义的函数
bool Equal(double num1, double num2)
{
    if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
        return true;
    else
        return false;
}
