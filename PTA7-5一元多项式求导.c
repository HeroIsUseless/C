#include <stdio.h>
//�����һ��0�����������ɣ�
//�������ݲ������
//�����ֻ���������������
//���������ֻ��һ��Ԫ��
int main()
{
    int xi, zhi, a=1;//�����һ������
    while(scanf("%d%d", &xi, &zhi) != EOF)
    {
        if(xi*zhi != 0)
            if(a)
            {
                printf("%d %d", xi*zhi, zhi-1);
                a=0;
            }
            else
                printf(" %d %d", xi*zhi, zhi-1);
        else
            break;
    }
    if(a) printf("0 0");
    return 0;
}
