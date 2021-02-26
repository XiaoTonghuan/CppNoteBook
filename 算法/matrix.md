## 三角矩阵压缩

将三角矩阵压缩进如一个一维数组

```c++
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
const int max = (int)1e3;
int row;
int line;
int martix[max][max];
int compact_martix_left[max];
int compact_martix_right[max];
int main()
{
    
    cin>>line>>row;
    for(int i = 0 ; i < line ; i++)
        for(int j = 0 ; j < row ; j++)
            cin>>martix[i][j];
    //输入矩阵
    
		for(int i= 0 ; i < line ; i++)//控制行
        	for(int j = 0 ; j <= i ; ++j) //控制列
                compact_martix_left[i*(i+1)/2+j] = martix[i][j];//存对角线左下元素
    	
    	for(int i = line - 1 ; i >= 0 ; --i)//控制行,同时控制元素
        	for(int j = row - 1 ; j >= i ; --j) //控制列，同时控制元素
                compact_martix_right[j*(j+1)/2+i] = martix[i][j];//存对角线左下元素
        
    for(int i = 0; i < line * (1 + row)/2 ; i++)
        cout<<compact_martix_left[i];
        cout<<endl;
    for(int i = 0; i < line * (1 + row)/2 ; i++)
        cout<<compact_martix_right[i];
    system("pause");
    
  // 输入下标，求解位置和元素
    //i > j ： 说明在左下角 i*(i+1)/2 + j
    //i < j ： 说明在右上 j*(j+1)/2 + i
    
}

```

## 稀疏矩阵压缩

```c++
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
const int max = (int)1e3;
int martix[max][max];
int line;
int row;
int cnt;
struct _compact_martix {
    int line;
    int row;
    int data;
} compact_martix[1000];
int main()
{
    cin>>line; //输入行
    cin>>row;  //输入列
    for(int i=0; i< line; ++i)
        for(int j=0; j< row; ++j){
            cin>>martix[i][j]; //输入元素
            if(martix[i][j]){ //不为0
                compact_martix[cnt].line = i + 1; //存行
                compact_martix[cnt].row = j + 1;  //存列
                compact_martix[cnt].data = martix[i][j]; //存内容
                cnt++;
            }
        }
    for(int i = 0; i < cnt; ++i)
        cout<<compact_martix[i].line<<" "
        	<<compact_martix[i].row<<" "
        	<<compact_martix[i].data<<endl;
    system("pause");
}
```

## 对角矩阵压缩

```c++
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
const int max = (int)1e3;
int martix[max][max];
int line;
int row;
int diagonal;
int compact_martix_diagnal[1000];
int main()
{
    cin>>line;
    cin>>row;
    cin>>diagonal; //非0对角线的条数
    for(int i=0; i< line; ++i)
        for(int j=0; j< row; ++j){
            cin>>martix[i][j];
            if(martix[i][j])
                compact_martix_diagnal[(diagonal - 1 )*i + j ] = martix[i][j]; //存阵，
            										//先假设第一行也有diagnal个数，都计算-1然后														//统计最后一行的个数
        }
    for(int i = 0; i < diagonal * line - 4; ++i)
        cout<<compact_martix_diagnal[i];
    system("pause");
}

```

## 十字链表压缩稀疏矩阵

解决向压缩矩阵中添加非零元素的难题

```c++
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int line;
int row;
const int max = (int)1e3;
int martix[max][max];
struct cross_node{
    int line,row,data;
    cross_node* down,*right;
};
cross_node ** lhead,**rhead;
int main()
{
    cin>>line>>row;
    lhead = new cross_node*[row + 1];
    rhead = new cross_node*[line + 1];    
    for(int i=1;i<=line;i++)
        lhead[i]=NULL;
    for(int j=1;j<=row;j++)
        rhead[j]=NULL;
    for(int i = 1; i<=line; ++i){
        for(int j = 1; j <= row; ++j){
            cin>>martix[i][j];
            if(martix[i][j]){

            cross_node *node = new cross_node,*q;
            //创建新结点

            node->data = martix[i][j];
            node->line = i;
            node->row = j;
            node->down = nullptr;
            node->right = nullptr;
            //存数据
            if(lhead[i] == nullptr || lhead[i]->row > j){ //如果左边没有元素指向空（这一行没有元素）或者
                                                            //新加入的元素在旧元素的左边
                    node->right = lhead[i];  //将新元素的右边链接
                    lhead[i] = node;  //重置头指针为新加入元素
                }else{ //有元素，或者新元素在右边
                    for(q = lhead[i] ; (q->right) && (q->right-> row < j) ; q = q->right );
                    //遍历右边的元素直到找到行比较小的元素
                    node->right = q->right; //将p目标元素放在最大和次大元素的中间
                    q->right = node;  //同上
                }if(rhead[j] == nullptr || rhead[j]->line > i){ //列指针为空(没有元素)或者列指针
                                                                //目标元素比较列数小
                    node->down=rhead[j];  //将这个元素放在头元素前面
                    rhead[j]=node;  //更新头元素
                }else{
                    for(q = rhead[j];(q->down)&&(q->down->line< i);q=q->down);
                    node->down=q->down;
                    q->down=node;
                    //和上面一样
                }
            }
        }
    }

    for(int i = 1; i <= line ; i++){  //遍历行
        cross_node *p = lhead[i];  //控制行指针 
        for(int j = 1; j <=row ; ++j){  //遍历列 
        if(p!=nullptr && p->row == j  ){  
            cout<<p->data<<" ";
            p=p->right; //该元素遍历完成指向下一个
        }
        else
            cout<<0<<" ";
        }
        cout<<endl;
    }
    system("pause");
}

```





