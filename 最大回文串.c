#include <stdio.h>
//��Գ��Ӵ�
//�ô�����������ɢ�ķ�����������һ��˫����һ��
char c[2000]={0};
int ln=0;//�ַ�������
int isHuiWen(int ci)
{
    int i, j;
    int n;
    int m = 1;
    //����
    i=ci; j=ci;
    n = 1;
    while(c[i] == c[j])
    {
        n+=2;
        i--; j++;

        if(i < 0 || j > ln-1)
        {
            break;
        }
    }
    n-=2;//�����ֲ���һ�ε������㶨���
    if(m < n) m = n;
    //˫��
    i=ci; j=ci+1;
    n = 0;
    while(c[i] == c[j])
    {
        n+=2;
        i--; j++;
        if(i < 0 || j > ln-1) break;
    }
    if(m < n) m = n;
    return m;
}
int main()
{
    int i,j;
    int m = 1;//��󳤶�
    int t;
    gets(c);
    while(c[ln] != 0)
    {
        ln++;
    }
    for(i=0; i<ln-1; i++)
    {
        t = isHuiWen(i);
        if(m < t)
            m = t;
    }
    printf("%d", m);
    return 0;
}
