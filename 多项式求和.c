#include <stdio.h>
//����ʽ��ͣ�����
int main()
{
    int i;
    int n;//����ʽϵ��
    float x;//�Ա���x��ȡֵ
    float a[40000];
    float b = 1;
    float c = 0;

    scanf("%d %f", &n, &x);
    for(i=0; i<n; i++)
        scanf("%f ", &a[i]);
    scanf("%f", &a[n]);

    for(i=0; i<=n; i++)
    {
        c += b * a[n-i];
        b *= x;
    }

    printf("%.3f\n", c);
    return 0;
}

