#include<bits/stdc++.h>
using namespace std;
typedef struct node Node;
int top=-1;

struct Stack
{
    Node *po;
    int x;
    Stack(Node *p,int i)
    {
        po=p;
        x=i;
    }
    Stack()
    {

    }
} st[100];

struct node
{

    int data;
    Node *left;
    Node *right;

};
void push(Stack temp)
{

    if(top!=100)
    {
        st[++top]=temp;
    }
    else
    {
        cout<<"Stack Overflow"<<endl;
    }
}
Stack pop()
{

    if(top>-1)
    {

        return st[top--];

    }
    else
    {
        cout<<"Stack Underflow"<<endl;
    }

}
bool isEmpty()
{
    if(top>-1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
Node* create_node(int item)
{
    Node *new_node = new Node;

    new_node->data = item;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}
void add_left_child(Node *parent_node, Node *child)
{
    parent_node->left = child;
}
void add_right_child(Node *parent_node, Node *child)
{
    parent_node->right = child;
}
Node* create_tree()
{
    Node *two = create_node(2);
    Node *seven = create_node(7);
    Node *nine = create_node(9);
    add_left_child(two, seven);
    add_right_child(two,nine);

    Node *one = create_node(1);
    Node *six = create_node(6);
    add_left_child(seven,one);
    add_right_child(seven,six);

    Node *five = create_node(5);
    Node *ten = create_node(10);
    add_left_child(six,five);
    add_right_child(six,ten);

    Node *eight = create_node(8);
    add_right_child(nine,eight);

    Node *three = create_node(3);
    Node *four = create_node(4);
    add_left_child(eight,three);
    add_right_child(eight,four);

    return two;
}

void pre_order(Node *node)
{
    Stack temp(node,1);
    push(temp);
    while(!isEmpty())
    {
        Node *p;
        int i;
        temp=pop();
        p=temp.po;
        i=temp.x;
        if(p!=NULL)
        {

            if(i==1)
            {
                Stack temp1(p,2);
                push(temp1);
                cout<<p->data<<"->";
            }
            else if(i==2)
            {
                Stack temp1(p,3);
                push(temp1);
                Stack temp2(p->left,1);
                push(temp2);

            }
            else if(i==3)
            {
                Stack temp1(p->right,1);
                push(temp1);

            }

        }

    }
}

int main()
{

    Node *root=create_tree();
    cout<<root->data<<endl;
    pre_order(root);
    cout<<endl;

}

