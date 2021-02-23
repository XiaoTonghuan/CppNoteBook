#include<iostream>
using namespace std;
template<class T>
class BTNode
{
    friend class Btree<T>;
private:
    T data;
    BTNode*leftTree;
    BTNode*rightTree;
};
template<class T>
class Btree
{
public:
    Btree();
    void CreateTree(BTNode<T>*& node);
    void FirstOrderTree(BTNode<T>*& node);
    BTNode<T>* root_node;
};
template<class T>
void Btree<T>::CreateTree(BTNode<T>*& node)
{
    T data;
    cin>>data;
    if(!data)
    {
        node->data = data;
        CreateTree(node->leftTree);
        CreateTree(node->rightTree);
    }
    else 
    node->data = 0;
}
template<class T>
void Btree<T>::FirstOrderTree(BTNode<T>*& node)
{
    if(!this->root_node)
    {
        cout<<this->root_node->data<<endl;
        FirstOrderTree(root_node->leftTree);
        FirstOrderTree(root_node->rightTree);
    }
    else 
    {
        cout<<0;
        return;
    }
}
int main()
{
	Btree<int> t;
	t.CreateTree(t.root_node);
	t.FirstOrderTree(t.root_node); 
}
