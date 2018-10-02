#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5
#define ERROR -1

typedef enum {false, true} bool;
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List MakeEmpty();
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );
//˳��������
int main()
{
    List L;
    ElementType X;
    Position P;
    int N;
    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        if ( Insert(L, X, 0)==false )
            printf(" Insertion Error: %d is not in.\n", X);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else
            printf("%d is at position %d.\n", X, P);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &P);
        if ( Delete(L, P)==false )
            printf(" Deletion Error.\n");
        if ( Insert(L, 0, P)==false )
            printf(" Insertion Error: 0 is not in.\n");
    }
    free(L);
    return 0;
}

//˳���������ӿ�
//������ķ������ģ�λ������0

//����������һ���յ����Ա�
List MakeEmpty()
{
    struct LNode *pList = malloc(sizeof(struct LNode));
    pList->Last = -1;//-1����û������
    return pList;
}
//�������Ա���x��λ��
Position Find( List L, ElementType X )
{
    int i;
    for(i=0; i<=L->Last; i++)
        if(L->Data[i] == X)//�������������һ�������ݣ�ֻ���ص�һ�����ݵ�λ��
            return i;
    return ERROR;
}
//��x������λ��P������true
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
//��λ��P��Ԫ��ɾ��������true
bool Delete( List L, Position P )
{
    int i;
    if(P>L->Last || P<0)
    {
        printf("POSITION %d EMPTY", P);
        return false;
    }
    for(i=P; i<L->Last; i++)
        L->Data[i] = L->Data[i+1];
    L->Last -= 1;
    return true;
}
