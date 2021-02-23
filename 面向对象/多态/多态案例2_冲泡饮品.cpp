#include <iostream>
using namespace std;
class BoilWatersome
{
public:
    virtual void BoilWater() = 0;
    virtual void Brew() = 0;
    virtual void PutInCup() = 0;
    virtual void AddSomeThing() = 0;
    void MakeDrink()  //写一个流程制作的函数来调用所有的流程。
    {
        BoilWater();
        Brew();
        PutInCup();
        AddSomeThing();
    }
};
class MakeTea : public BoilWatersome
{
public:
    void BoilWater()
    {
        cout << "You have made Boiled Water" << endl;
    }
    void Brew()
    {
        cout << "You have brewed tea" << endl;
    }
    void PutInCup()
    {
        cout << "You have put tea in glass cup" << endl;
    }
    void AddSomeThing()
    {
        cout << "Add some milk in tea" << endl;
    }
};
class MakeCoffee : public BoilWatersome
{
public:
    void BoilWater()
    {
        cout << "You have made Boiled Water" << endl;
    }
    void Brew()
    {
        cout << "You have brewed Coffee" << endl;
    }
    void PutInCup()
    {
        cout << "You have put Coffee in glass cup" << endl;
    }
    void AddSomeThing()
    {
        cout << "Add some milk in COffee" << endl;
    }
};

void StartMakeDrink(BoilWatersome *abs)  //这是一个外部接口调用父类的函数，传入不同子类的对象，实现一个接口，实现多种功能。
{
    abs->MakeDrink(); //调用abs的函数，调用函数再次调用函数，这些函数已经在子类重写过了。
    delete abs; //在堆区开辟内存之后记得删除。
}
void test01()
{
    StartMakeDrink(new MakeTea); //匿名的方式声明一个对象，把他传进abs里面。
}
void test02()
{
    StartMakeDrink(new MakeCoffee);
}
int main()
{
    test01();
    test02();
}