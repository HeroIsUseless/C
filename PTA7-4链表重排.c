#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ERROR -1
#define NULL -1
struct Nod {
    int Data;
    int Next;
};
/*
*���������м�Ͽ����Ѻ�����Ǹ�����һ�£������Ϳ�����
*���������ֻ��һ��Ԫ�أ�ֻ������Ԫ��
*/
int main()
{
    int i, n, pHead1, pHead2, addr=1, p1, p2, p3, p4;
    struct Nod list[100010];
    //����
    scanf("%d %d", &pHead1, &n);
    for(i=1; i<=n; i++)
    {
        scanf("%d%d%d", &addr, &p1, &p2);
        list[addr].Data = p1;
        list[addr].Next = p2;
    }
    //���м�Ͽ�
    p1 = pHead1;
    for(i=1; i<=n; i++)
    {
        if(i == n/2)
        {
            pHead2 = list[p1].Next;
            list[p1].Next = NULL;
            break;
        }
        p1 = list[p1].Next;
    }
    //�Ѻ������������
    p1 = pHead2;
    p2 = list[p1].Next;
    list[p1].Next = NULL;
    while(p2 != NULL)
    {
        p3 = list[p2].Next;
        list[p2].Next = p1;
        p1 = p2;
        p2 = p3;
    }
    pHead2 = p1;
    //������������
    p1 = pHead1;
    p2 = pHead2;
    for(i=1; i<=n/2; i++)
    {
        p3 = list[p2].Next;
        p4 = list[p1].Next;
        list[p2].Next = p1;
        list[p1].Next = p3;
        p2 = p3;
        p1 = p4;
    }
    //���
    p1 = pHead2;
    while(p1 != NULL)
    {
        if(list[p1].Next == -1)
            printf("%05d %d %d\n", p1, list[p1].Data, list[p1].Next);
        else
            printf("%05d %d %05d\n", p1, list[p1].Data, list[p1].Next);
        p1 = list[p1].Next;
    }
    return 0;

}
