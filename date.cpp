#include <stdio.h>
#define BYEAR 1949
#define EYEAR 2000
//�г���BYEAR��EYEAR���ڵ�����
//��ʽ��һ����һ���Σ�����������Ϊһ�꣬�ٸ�һ������һ�꣬������ڵĶ����кܶ࣬�Ȱѹ���ʵ������˵������
int lmonth[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
void printDate();
int month[4][35] = {{0}};//һ����1-4����
int main()
{
    FILE *pFile = fopen("date.txt","w");
    //�ж������껹��ƽ��
    for(int y=BYEAR; y<=EYEAR; y++)//�ж�����
    {
        isRunNian(y);
        for(int m=0; m<3; m++)//������
        {
            printDate();//�������
            getData(y,m);//��������������
            printDay();//�������0
        }
    }
    fclose(pFile);
    return 0;
}
void printDate()
{
    for(int a=1; a<=4; a++)
    {
        for(int b=0; b<=6; b++)
        {
            switch(b)
            {
                case 0:
                    fprintf(pFile, "�� ");
                    break;
                case 1:
                    fprintf(pFile, "һ ");
                    break;
                case 2:
                    fprintf(pFile, "�� ");
                    break;
                case 3:
                    fprintf(pFile, "�� ");
                    break;
                case 4:
                    fprintf(pFile, "�� ");
                    break;
                case 5:
                    fprintf(pFile, "�� ");
                    break;
                case 6:
                    fprintf(pFile, "��   ");
                    break;
            }
        }
    }
    fprintf(pFile,"\n");
}
void getData(int y, int m)//m�Ǵ�0��ʼ��
{
    int mo = 0;
    int theFirstDay = 0;//�������1����������ĵڼ�λ
    for(int i=0; i<4; i++)
    {
        mo = m*4+i+1;
        theFirstDay = getTED(y,mo)
        for(int j=0; j<lmonth[mo-1]; j++)
        {//��ܳ��Ҫ��һ��ѭ��
            month[i][theFirstDay+j]=j+1;//��ѽ�ҵĸ���
        }//�Ҹо������
    }
}
void printDay()
{
   for(int i=0; i<5; i++)
   {
       for(int j=0; j<4; j++)
       {

       }
   }
}
void isRunNian(int y)
{
     if((y%100!=0 && y%4==0) || (y%400==0))
    {
        lmonth[1] = 29;//���¾������12
    }
    else
    {
        lmonth[1] = 28;
    }
}
