#include <stdio.h>
//�ж�ջ�ܷ�Ӵ�С���У����Ӧ���ǱȽ���ȷ��
int main()
{
    int i,j,a,M,N,K;
    int A[1000]={0},NA=0,
        B[1000]={0},NB=0,
        Nid=1;
    scanf("%d%d%d", &M, &N, &K);
    while(K--)
    {
        for(i=1; i<=N; i++) {scanf("%d", &a); A[i] = a;}
        NA = N; B[0] = 1001; NB = 0; Nid = 1;
        while(NA!=0)                    //ֻҪA����վ���
        {
            if(A[NA]<B[NB])             //��A[NA]<B[NB]��ֱ��ѹ��
                if(NB >= N)             //ջ��ֱ�Ӵ����˳�
                    {printf("NO\n"); goto Error;}
                else                    //����
                    B[++NB] = A[NA--];
            else                        //��A[NA]>B[NB]�������жϣ���ѹ��A
            {
                while(A[NA] > B[NB])    //��������С��A[NA]��ֵ
                {
                    if(B[NB] != Nid)    //���û�а�˳�򵯳��������˳�
                        {printf("NO\n"); goto Error;}
                    else
                        {NB--; Nid++;}
                }
                B[++NB] = A[NA--];
            }
        }
        printf("YES\n");
        Error:;
    }
    return 0;
}
