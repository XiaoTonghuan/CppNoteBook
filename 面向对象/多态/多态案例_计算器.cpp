#include <iostream>
using namespace std;
class Calculator
{
public:
    double m_num1;
    double m_num2;
    virtual double GetResult()
    {
        return 0;
        //父类虚函数空实现，方便子类对功能进行拓展。
    }
};
class AddCalculator : public Calculator //实现加法的操作
{
public:
    double GetResult()
    {
        return m_num1 + m_num2;
    }
};
class SubCalculator : public Calculator //实现减法的操作
{
public:
    double GetResult()
    {
        return m_num1 - m_num2;
    }
};
class mulCalculator : public Calculator //实现乘法的操作
{
public:
    double GetResult()
    {
        return m_num1 * m_num2;
    }
};
class devCalculator : public Calculator //实现除法的操作
{
public:
    double GetResult()
    {
        return m_num1 / m_num2;
    }
};
void testCalculator()
{
    AddCalculator add;
    add.m_num1 = 100;
    add.m_num2 = 198;
    cout << "m_num1 + m_num2 = " << add.GetResult();
}

int main()
{
    testCalculator();
}