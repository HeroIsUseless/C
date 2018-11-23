#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//��׺���ʽת���ɺ�׺���ʽ������������Ȳ�������һʱ����ʼִ�м��㣬������������
typedef double ElementType;
#define Infinity 1e8
#define Max_Expr 30   /* max size of expression */

void TralPostfix( char *expr );

int main()
{
    char expr[Max_Expr];
    gets(expr);
    TralPostfix( expr );
    return 0;
}

/* Your function will be put here */
void TralPostfix( char *expr )
{
    float SN[Max_Expr]; int Ntop = 0;
    char SO[Max_Expr]; int Otop = 0;
    float ft; int isDot; float dot; int i;//��ʱ����
    while(*expr != 0)
    {
        if(*expr>='0' && *expr<='9')//ת�����ֲ�ѹ������
        {
            ft = 0.0;
            isDot = 0;//�Ƿ������С����
            dot = 1;
            while(*expr!=' ' || *expr!='(' || *expr!=')')
            {
                if(*expr == '.') {isDot = 1; expr++; continue;}
                if(isDot)
                {
                    ft += ((float)(*expr-'0'))*dot*0.1; dot *= 0.1;
                    expr++;
                }
                else
                {
                    ft = ft*10 + *expr - '0';
                    expr++;
                }
            }
            SN[Ntop++] = ft;
        }
        if(*expr=='+' || *expr=='*' || *expr=='/')//ѹ�������
        {
            SO[Otop++] = *expr;
        }
        if(*expr=='-')//���������Ǹ������Ǽ���
        {
            if(*(expr+1)==' '|| *(expr+1)=='\0')
                SO[Otop++] = *expr;
            else
            {
                expr++;//�������ֲ���
                ft = 0.0;
                isDot = 0;//�Ƿ������С����
                while(*expr!=' ' || *expr!='(' || *expr!=')')
                {
                    if(*expr == '.'){isDot = 1; expr++; continue;}
                    if(isDot)
                    {
                        ft += *expr*pow(0.1, isDot++);
                        expr++;
                    }
                    else
                    {
                        ft = ft*10 + *expr - '0';
                        expr++;
                    }
                }
                SN[Ntop++] = -ft;
            }
        }
        expr++;//�ո��λ
        //�ж��Ƿ���������
        if(Ntop-Otop == 1)
        {
            for(i=0; i<Ntop; i++)
                printf("%f ", SN[i]);
            Ntop = 0;
            for(i=0; i<Otop; i++)
                printf("%c ", SO[i]);
            Otop = 0;
        }
    }
}





