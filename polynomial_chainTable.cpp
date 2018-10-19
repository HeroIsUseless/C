#include <stdio.h>
#include <stdlib.h>
//�涨��ͷָ��
//�涨ֻ�ܴӴ�С����
namespace Polynomial
{
    typedef struct Elem
    {
        float coef;//����
        int expn;//ָ��
        Elem *next;
    };

    class Polynomial
    {
        public: Elem *head, *tail;
        public:
        //���캯��
        Polynomial()
        {
            head = (Elem*)malloc(sizeof(Elem));
            head->next = NULL;
            tail = head;
        }
        //���
        void ClearPoly()
        {
            Elem *p1, *p2;
            p1 = head;
            p2 = head->next;
            p1->next = NULL;
            while(p2 != NULL)
            {
                p1 = p2;
                p2 = p2->next;
                free(p1);
            }
        }
        void CopyPoly(Polynomial pol)//���Ǵ�����Ķ���ʽ��ȫ���������������ж������ô�죿����ɾ��
        {
            ELem *p1 = head, *p2 = pol.head->next, *p3;
            while(p2 != NULL)
            {
                if(p1->next != NULL)
                {
                    p1->coef = p2->coef;
                    p1->expn = p2->expn;
                }
                else
                {
                    p3 = malloc(sizeof(Elem));
                    p3->coef = p2->coef;
                    p3->expn = p2->expn;
                    p3->next = NULL;
                    p1->next = p3;
                }
                p1 = p1->next;
                p2 = p2->next;
            }
            p1 = p1->next;//��ʱ��p1�����һ����
            while(p1 != NULL)
            {
                p3 = p1->next;
                free(p1);
                p1 = p3;
            }
        }
        //��ӡ
        void PrintPolyn()
        {
            Elem *p1;
            p1 = head->next;
            while(p1->next != NULL)
            {
                printf("%d %d ", p1->coef, p1->expn);
            }
            printf("%d %d", p1->coef, p1->expn);
        }
        //���س���
        int PolyLength()
        {
            int n = 0;
            Elem *p1 = head;
            while(p1 != NULL)
            {
                p1 = p1->next;
                n++;
            }
            return n;
        }
        //��ӽڵ�
        void AddPolyn(Elem *cp)//�涨ֻ�ܴӴ�С����
        {//�����ĺô��Ƿ���ĸ��Ĳ���
            tail->next = cp;
            tail = tail->next;
            tail->next = NULL;
        }
        //����ʽ�ӷ�
        void AdditivePolyn(Polynomial pol)
        {
            Elem *p1, *p2=pol.head->next;
            while(p2 != NULL)
            {
                p1 = head->next;
                while(p1 != NULL)
                {
                    if(p1->expn == p2->expn)
                    {
                        p1->coef += p2->coef;
                        break;
                    }
                    p1 = p1->next;
                }
                if(p1 == NULL)//û���ҵ����²���һ��
                {
                    p1 = head;
                    while(1)
                    {
                        if(p1->next==NULL || p1->expn<p2->expn)
                        {
                            Elem *p3 = (Elem*)malloc(sizeof(Elem));
                            p3->coef = p2->coef;
                            p3->expn = p2->expn;
                            p3->next = p1->next;
                            p1->next = p3;
                        }
                        else
                        {
                            p1 = p1->next;
                        }
                    }
                }
                p2 = p2->next;
            }
        }
        //����ʽ����
        void SubtractPolyn(Polynomial pol)//ʵ�ַ�������p2Ϊѭ�������������������
        {
            Elem *p1 = head, *p2 = pol.head->next, *p3;
            while(p2 != NULL)//���Ҳֻ��ѭ��һ��
            {
                if(p1->next != NULL)
                {
                    if(p1->next->expn < p2->expn)//�����¿ռ����
                    {
                        p3 = (Elem*)malloc(sizeof(Elem));
                        p3->expn = p2->expn;
                        p3->coef = -p2->coef;
                        p3->next = p1->next;
                        p1->next = p3;
                        p1 = p1->next;
                        p2 = p2->next;
                    }
                    else if(p1->next->expn == p2->expn)//�����������
                    {
                        p1->next->coef -= p2->coef;
                        p1 = p1->next;
                        p2 = p2->next;
                    }
                    else if(p1->next->expn > p2->expn)
                    {
                        p1 = p1->expn;
                    }
                }
                else
                {
                    p3 = malloc(sizeof(Elem));
                    p3->coef = -p2->coef;
                    p3->expn = p2->expn;
                    p3->next = NULL;
                    p1->next = p3;
                }
            }
        }

        //����ʽ�˷�
        void MultiplyPolyn(Polynomial pol)//����ʽ�˷��ǲ�ְ���ÿ������һ���µ��죬Ȼ��ϲ����
        {
            Elem *p1 = head, *p2 = pol.head->next;
            Polynomial poly = new Polynomial();
            Polynomial polySum = new Polynomial();
            while(p2 != NULL)//��ÿһ������Ǹ�������ӣ����ɹ�
            {
                poly.CopyPoly(this);
                poly.MultiplyCoef(p2->coef);
                poly.MultiplyExpn(p2->expn);
                polySum.AdditivePolyn(poly);
                poly.ClearPoly();
            }
            this.ClearPoly();
            this.CopyPoly(polySum);
        }
        //ϵ���˷�
        void MultiplyCoef(float f)
        {
            Elem *p1 = head->next;
            while(p1 != NULL)
            {
                p1->coef *= f;
                p1 = p1->next;
            }
        }
        //ָ���˷�
        void MultiplyExpn(int e)
        {
            Elem *p1 = head->next;
            while(p1 != NULL)
            {
                p1->expn += e;
                p1 = p1->next;
            }
        }
        //����ʽ����
        Polynomial DivisionPolyn(Polynomial pol)//������ôʵ�ֵ����ţ���Ҫ�����̺�����
        {//�������������������
            Elem *p;
            Polynomial polRes = new Polynomial();
            Polynomial polt = new Polynomial();
            if(this.head->next == NULL) return NULL;
            if(pol.head->next == NULL) return NULL;
            while(this.head->next->expn > pol.head->next->expn)
            {
                p = malloc(sizeof(Elem));
                p->coef = this.head->next->coef / pol.head->coef;
                p->expn = this.head->next->expn - pol.head->next->expn;
                polRes.AddPolyn(p);
                polt.CopyPoly(pol);
                polt.MultiplyCoef(p->coef);
                polt.MultiplyExpn(p->expn);
                this.DivisionPolyn(polt);
            }
            return polRes;
        }
        //��������
        ~Polynomial()
        {
            Elem *p1, *p2;
            p1 = head;
            p2 = head->next;
            free(p1);
            while(p2 != NULL)
            {
                p1 = p2;
                p2 = p2->next;
                free(p1);
            }
        }
    };
}
int main()//���Ժ���
{
    return 0;
}
