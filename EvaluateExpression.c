//��ʼ�ַ���#��������ջ��OPTRΪ�Ĵ��������OPND�Ĵ��������������
void EvaluateExpression()
{
    InitStack(OPTR);
    Push(OPTR, '#');
    InitStack(OPND);
    c = getchar();
    while(c!='#' || GetTop(OPTR)!='#')
    {
        if(!In(c, OP))//�ж��ǲ��������ǲ����������Է���һ���ַ�������ַ����������ɣ����Լӿո��ֹ����
        {
            Push(OPND, c);
            c = getchar();
        }
        else
        {
            switch(Precede(GetTop(OPND), c))//�ж�ջ��������������������ȼ�
            {
                case '<':
                    push(OPTR, c);
                    c = getchar();
                    break;
                case '=':
                    Pop(OPTR, x);//������
                    c = getchar();
                    break;
                case '>':
                    Pop(OPTR, theta);
                    Pop(OPND, b);
                    Pop(OPND, a);
                    Push(OPND, Opreate(a, theta, b));//ֻ��һ�����㺯��
                    break;
            }
        }
        return;
    }



}
