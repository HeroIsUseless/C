#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN sizeof(struct St)
struct St{
    int id;char name[20];
    float score1;float score2;float score3;float avescore;
    int isUse;
};
int getStArrLen(struct St _st[]){
    int i;
    for(i=0;i<100;i++) if(_st[i].isUse==0) return i;
}
int main()
{
    int i,serial,n,nst=0;
    char name[20];
    struct St st[100],stTemp;
    FILE *pfile=NULL;
    for(i=0;i<100;i++) st[i].isUse=0;
    if((pfile=fopen("scores","rb"))==NULL) pfile=fopen("score","wb");fclose(pfile);
    printf("ѧ���ɼ�����ϵͳ\n");
    printf("--------------\n");
    printf(" ");printf("|");printf("��������");printf("|");printf("1");printf("|\n");
    printf(" ");printf("|");printf("��ʾ����");printf("|");printf("2");printf("|\n");
    printf(" ");printf("|");printf("��������");printf("|");printf("3");printf("|\n");
    printf(" ");printf("|");printf("��������");printf("|");printf("4");printf("|\n");
    printf(" ");printf("|");printf("��������");printf("|");printf("5");printf("|\n");
    printf(" ");printf("|");printf("���ݴ浵");printf("|");printf("6");printf("|\n");
    printf("--------------\n");
    be:
    printf("\n\n��������Ų��س���");
    scanf("%d",&serial);
    switch(serial){
        case 1:{//��������
            printf("\n������ѧ��������");
            scanf("%d",&n);
            printf("������ѧ�����ݣ�����Ϊ��\n");
            printf("ѧ�� ѧ������ �ɼ�1 �ɼ�2 �ɼ�3\n");
            pfile=fopen("scores","rb");fread(st,LEN,100,pfile);fclose(pfile);nst=getStArrLen(st);
            for(i=0;i<n;i++){
                scanf("%d %s %f %f %f",&st[nst+i].id,st[nst+i].name,
                      &st[nst+i].score1,&st[nst+i].score2,&st[nst+i].score3);
                st[nst+i].avescore=(st[nst+i].score1+st[nst+i].score2+st[nst+i].score3)/3;
                st[nst+i].isUse=1;
                nst++;
            }
            pfile=fopen("scores","wb");fwrite(st,LEN,100,pfile);fclose(pfile);
            printf("\n������ɣ�\n");
            goto be;}
        case 2:{//��ʾ����
            printf("ѧ�� ѧ������ �ɼ�1 �ɼ�2 �ɼ�3 ƽ���ɼ�\n");
            pfile=fopen("scores","rb");fread(st,LEN,100,pfile);fclose(pfile);nst=getStArrLen(st);
            for(i=0;i<nst;i++){
                printf("%d %s %.2f %.2f %.2f %.2f\n",st[i].id,st[i].name,
                      st[i].score1,st[i].score2,st[i].score3,st[i].avescore);
            }
            goto be;}
        case 3:{//���ҹ���
            printf("���������֣�");
            scanf("%s",name);
            pfile=fopen("scores","rb");fread(st,LEN,100,pfile);fclose(pfile);nst=getStArrLen(st);
            for(i=0;i<nst;i++) if(strcmp(name,st[i].name)==0) printf("%d %s %.2f %.2f %.2f %.2f\n",st[i].id,st[i].name,
                                                                    st[i].score1,st[i].score2,st[i].score3,st[i].avescore);
            goto be;}
        case 4:{//������
            pfile=fopen("scores","rb");fread(st,LEN,100,pfile);fclose(pfile);nst=getStArrLen(st);
            for(i=0;i<nst-1;i++){
                for(j=i;j<nst;j++){
                    if(st[i].avescore<st[j].avescore){
                        stTemp=st[i];
                        st[i]=st[j];
                        st[j]=stTemp;
                    }
                }
            }
            printf("\n����ɹ���\n");
            goto be;}
        case 5:{//���빦��
            printf("������ѧ�����ݣ�����Ϊ��\n");
            printf("ѧ�� ѧ������ �ɼ�1 �ɼ�2 �ɼ�3\n");
            pfile=fopen("scores","rb");fread(st,LEN,100,pfile);fclose(pfile);nst=getStArrLen(st);
            scanf("%d %s %f %f %f",&st[nst].id,st[nst].name,
                      &st[nst].score1,&st[nst].score2,&st[nst].score3);
            st[nst].avescore=(st[nst].score1+st[nst].score2+st[nst].score3)/3;
            st[nst+i].isUse=1;
            nst++;
            for(i=0;i<nst-1;i++){
                for(j=i;j<nst;j++){
                    if(st[i].avescore<st[j].avescore){
                        stTemp=st[i];
                        st[i]=st[j];
                        st[j]=stTemp;
                    }
                }
            }
            pfile=fopen("scores","wb");fwrite(st,LEN,100,pfile);fclose(pfile);
            printf("\n������ɣ�\n");
            goto be;}
        case 6:{//�浵����
            printf("�洢�ɹ���");
            goto be;}
        default:{
            printf("ִ��ʧ�ܣ����������룺");
            goto be;
        }
    }
    return 0;
}
