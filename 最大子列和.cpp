#include <stdio.h>
//����һ�����飬����������к�
//�����Ǵ�1��ʼ������󳤴����������е���ֵ����ȶ�
int a[200000]={0};
int main()
{
    int n;
    int m=-10000;
    scanf("%d", &n);
    for(int i=0; i<n-1; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &a[n-1]);

    for(int i=0; i<n; i++)
    {
        int t=0;
        for(int j=0; j<n-i; j++)
        {
            t += a[i+j];
            if(m < t)
            {
                m = t;
            }
        }
    }
    printf("%d", m);
    return 0;
}
