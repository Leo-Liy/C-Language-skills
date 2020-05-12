//////////////////////////////////////////////////////////////////////////////////
//单链表的初始化，建立，插入，查找，删除。//
//////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
////////////////////////////////////////////////////////////////////////////////
//定义结点类型
typedef struct Node
{
    ElemType data;  //单链表中的数据域
    struct Node *next;  //单链表的指针域
}Node, *LinkedList;
////////////////////////////////////////////////////////////////////////////////
//单链表的初始化
LinkedList LinkedListInit()
{
    Node *L;
    L = (Node *)malloc(sizeof(Node));   //申请节点空间
    if (L == NULL)
    {
        //printf("申请内存空间失败/n");
        printf("member apply failed!\n");
    }
    L->next = NULL; 
}
////////////////////////////////////////////////////////////////////////////////
//单链表的建立1，头插法建立单链表
LinkedList LinkedListCreatH()
{
    Node *L;
    L = (Node *)malloc(sizeof(Node));   //申请头结点空间
    L->next = NULL;                     //初始化一个空链表

    ElemType x;                         //x 为链表数据域中的数据
    while (scanf("%d", &x) != EOF)
    {
        Node *p;
        p =  (Node *)malloc(sizeof(Node));  //申请新的结点
        p->data = x;                        //结点数据域赋值
        p->next = L->next;                  //将节点插入到表头L-->|2|-->|1|-->|NULL|
        L->next = p;
    }
    return L;
}
////////////////////////////////////////////////////////////////////////////////
//单链表的建立2，尾插法建立单链表
LinkedList LinkedListCreatT()
{
    Node *L;
    L = (Node *)malloc(sizeof(Node));       //申请头结点空间
    L->next = NULL;                         //初始化一个空链表
    Node *r;
    r = L;                                  //r始终指向终端结点，开始时指向头结点
    ElemType x;                             //x为链表数据域中的数据
    while (scanf("%d", &x) != EOF)
    {
        Node *p;
        p = (Node *)malloc(sizeof(Node));   //申请新的结点
        p->data = x;                        //结点数据域赋值
        r->next = p;                        //将结点插入到表头 L-->|1|-->|2|-->NULL
        r = p;
    }
    r->next = NULL;
    return L;
}

////////////////////////////////////////////////////////////////////////////////
//单链表的插入，在链表的第i个位置插入x的元素
LinkedList LinkedListInsert(LinkedList L, int i, ElemType x)
{
    Node *pre;                      //pre 为前驱结点
    pre = L;
    int tempi = 0;
    for (tempi = 1; tempi < i; tempi++)
    {
        pre = pre->next;            //查找第i个位置的前驱结点
    }
    Node *p;                        //插入的结点为P
    p = (Node *)malloc(sizeof(Node));
    p->data = x;
    p->next = pre->next;
    pre->next = p;

    return L;
}

////////////////////////////////////////////////////////////////////////////////
//单链表的删除链表中删除值为x的元素
LinkedList LinkedListDelete(LinkedList L, ElemType x)
{
    Node *p, *pre;
    //p = L->next;
    p = L;
    while (p->data != x)
    {
        pre = p;
        p = p->next;
    }
    pre->next = p->next;
    free(p);
    
    return L;
}

////////////////////////////////////////////////////////////////////////////////
int main()
{
    LinkedList list, start;
/*    printf("请输入单链表的数据：");
    list = LinkedListCreatH();
    for (start = list->next; start!= NULL; start = start->next)
    {
        printf("%d", start->data);
    }
    printf("\n");
*/  printf("Pls input link data:\n");
    list = LinkedListCreatT();
    for (start = list->next; start!= NULL; start = start->next)
    {
        printf("%d\n", start->data);
    }
    printf("\n");

    int i;
    ElemType x;
    printf("Pls input insert position:\n");
    scanf("%d", &i);
    printf("Pls input insert data:\n");
    scanf("%d", &x);
    printf("\n");
    LinkedListInsert(list, i, x);
    for (start = list->next; start != NULL; start = start->next)
        printf("%d\n", start->data);
    printf("\n");

    printf("Pls input delete value:\n");
    scanf("%d", &x);
    printf("\n");

    LinkedListDelete(list, x);
    for(start = list->next; start != NULL; start = start->next)
        printf("%d\n", start->data);
    printf("\n");

    getchar();
    system("pause");
    //return 0;
}




































