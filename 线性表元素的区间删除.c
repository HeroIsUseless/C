#include <stdio.h>
//���Ա�Ԫ�ص�����ɾ��
#define MAXSIZE 20
#define ERROR -1

typedef enum {false, true} bool;
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�0��ʼ�洢 */
void PrintList( List L ); /* ����ʵ�֣�ϸ�ڲ��� */
List Delete( List L, ElementType minD, ElementType maxD );
List MakeEmpty()
{
    struct LNode *pList = malloc(sizeof(struct LNode));
    pList->Last = -1;//-1����û������
    return pList;
}
bool Insert( List L, ElementType X, Position P )
{
    int i;
    if(L->Last+1 >= MAXSIZE)
    {
        printf("FULL");
        return false;
    }
    if(P>L->Last+1 || P<0)//���ݲ�׼���뵽����֮��ĵط�
    {
        printf("ILLEGAL POSITION");
        return false;
    }
    for(i=L->Last; i>=P; i--)
        L->Data[i+1] = L->Data[i];
    L->Last += 1;
    L->Data[P] = X;
    return true;
}
int main()
{
    List L;
    ElementType X;
    ElementType minD, maxD;
    Position P;
    int N;
    int i;
    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        if ( Insert(L, X, 0)==false )
            printf(" Insertion Error: %d is not in.\n", X);
    }
    printf("�������\n");
    scanf("%d %d", &minD, &maxD);
    L = Delete( L, minD, maxD );
    for(i=0; i<=L->Last; i++)
        printf("%d ", L->Data[i]);
    free(L);
    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
//��Ƶ�ɾ��������ɾ��ֵΪmin��max֮���Ԫ��
List Delete( List L, ElementType minD, ElementType maxD )
{
    int i, n=0;
    ElementType a[MAXSIZE];
    for(i=0; i<=L->Last; i++)
    {
        if(!(L->Data[i]>minD && L->Data[i]<maxD))
                a[n++] = L->Data[i];
    }
    for(i=0; i<n; i++)
        L->Data[i] = a[i];
    L->Last = n-1;
    return L;
}
















