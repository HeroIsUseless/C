#include <stdio.h>
//�Ȱ������ȳ��ǽ��������󲢼���Ȼ����������λ��
//��i+j=n-1��ʱ�򣬱���һ����n-1���Ǹ���
//����һ��Ӧ����ǰ����Ǹ���
//��ͳ�2����
int a[200000];
int b[100000];
int c[100000];
int n;
int main()
{
    int i, j, a1, a2;
    scanf("%d", &n);
    for(i=0; i<n; i++)
        scanf("%d", &b[i]);
    for(i=0; i<n; i++)
        scanf("%d", &c[i]);
    i=0; j=0;
    while(1)
    {
        if(i+j == n-1)
            break;
        if(b[i]>=c[j])
            j++;
        else
            i++;
    }
    printf("%d\n",(b[i]+c[j])/2);
    return 0;
}

