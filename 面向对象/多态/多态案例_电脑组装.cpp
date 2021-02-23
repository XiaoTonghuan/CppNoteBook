#include <iostream>
using namespace std;
class CPU   //一个cpu的父类，虚构类，没有任何的实现。
{
public:
    virtual void RunCPU() = 0;
};
class VideoCard  //一个显卡的父类，虚构类，没有任何的实现。
{
public:
    virtual void RunVideoCard() = 0;
};
class MemoryBar  //内存的父类，只是提供一个接口。
{
public:
    virtual void RunMemoryBar() = 0;
};
class Computer  //定义一个计算机的类。
{
public:
    Computer(CPU *cpu, MemoryBar *mem, VideoCard *card)  //构造函数，用来使用不同的零件来组装电脑
    {
        m_cpu = cpu;
        m_mem = mem;
        m_card = card;
    }
    void dowork()  //用来使运行电脑
    {
        m_cpu->RunCPU();
        m_mem->RunMemoryBar();
        m_card->RunVideoCard();
    }
    ~Computer()  //当你使用完电脑之后，将电脑中的零件全部销毁。
    {
        if(m_cpu!=NULL)
        {
            delete m_cpu;
            m_cpu = NULL;
        }
       if(m_mem!=NULL)
       {
           delete m_mem;
           m_mem = NULL;
       }
       if(m_card!=NULL)
       {
           delete m_card;
           m_card = NULL;
       }

    }

private: //电脑中可以用来存放零件。
    CPU *m_cpu;
    MemoryBar *m_mem;
    VideoCard *m_card;
};
class IntelCpu : public CPU  //子类，用来将不同的cpu分类。
{
public:
    void RunCPU()
    {
        cout << "Your CPU is running" << endl;
    }
};
class IntelVideoCard : public VideoCard  //同理
{
public:
    void RunVideoCard()
    {
        cout << "Your VideoCard is running" << endl;
    }
};
class IntelMemoryBar : public MemoryBar //同理
{
public:
    void RunMemoryBar()
    {
        cout << "Your MemoryBar is running" << endl;
    }
};
class DellCpu : public CPU
{
public:
    void RunCPU()
    {
        cout << "Your CPU is running dell" << endl;
    }
};
class DellVideoCard : public VideoCard
{
public:
    void RunVideoCard()
    {
        cout << "Your VideoCard is running dell" << endl;
    }
};
class DellMemoryBar : public MemoryBar
{
public:
    void RunMemoryBar()
    {
        cout << "Your MemoryBar is running dell" << endl;
    }
};

void test01()  //第一个测试文件，从创建cpu文件开始，到组装到电脑里，再到执行完销毁。
{
    CPU *cpu1 = new IntelCpu;
    VideoCard *card1 = new IntelVideoCard;
    MemoryBar *bar1 = new IntelMemoryBar;
    Computer *computer1 = new Computer(cpu1, bar1, card1); //在堆区开辟内存+构造函数。
    computer1->dowork();
    delete computer1;
    cout<<"-------------------------------"<<endl;
}
void test02()
{
    Computer *computer2 = new Computer(new DellCpu,new DellMemoryBar, new DellVideoCard);
    computer2->dowork();
    delete computer2;
}
int main()
{
    test01();
    test02();
}