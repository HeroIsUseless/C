#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define ERROR -1
#define NULL -1
struct Nod {
    int Data;
    int Next;
};
struct Nod list[100010];
int a[100000] = {0};
void print(int cp)
{
    if(list[cp].Next == -1)
        printf("%05d %d %d\n", cp, list[cp].Data, list[cp].Next);
    else
        printf("%05d %d %05d\n", cp, list[cp].Data, list[cp].Next);
}
/*
*��������һ��������飬ֻѭ��һ��,�����Ƕ�ȡһ���ڵ㣬�������в鿴�ظ���������ظ���ȥ������ڵ�
*���������û���ظ���ֻ��һ���ڵ�
*/
int main()
{
    int n, pHead, pHDel=100001, pDel, addr=1, p1, p2;
    scanf("%d %d", &pHead, &n);
    while(n--)
    {
        scanf("%d %d %d", &addr, &p1, &p2);
        list[addr].Data = p1;
        list[addr].Next = p2;
    }
    //���д���
    p1 = pHead;
    a[abs(list[p1].Data)] = 1;
    p2 = list[pHead].Next;
    list[pHDel].Next = NULL;
    pDel = pHDel;
    while(p2 != NULL)
    {
        if(a[abs(list[p2].Data)] != 1)//���û���ظ���ǰ��
        {
            a[abs(list[p2].Data)] = 1;
            p2 = list[p2].Next;
            p1 = list[p1].Next;
        }
        else//����ظ�����ȥ������ڵ�
        {
            list[p1].Next = list[p2].Next;
            list[pDel].Next = p2;
            pDel = list[pDel].Next;
            p2 = list[p2].Next;
            list[pDel].Next = NULL;
        }
    }
    //���ȥ�غ�Ľڵ�
    p1 = pHead;
    while(p1 != NULL)
    {
        print(p1);
        p1 = list[p1].Next;
    }
    //�����ɾ���Ľڵ�
    p2 = list[pHDel].Next;
    while(p2 != NULL)
    {
        print(p2);
        p2 = list[p2].Next;
    }
    return 0;
}
