#include <iostream>
#include <math.h>
using namespace std;

int main(){

    int fun10(int z);
    int LinNum;
    int n=0,m=0,b=0,c=0;

    cout << "��ӭʹ��n������ʽ������!\n\n";
    cout << "���ߣ���(�����)����ΰ�ɦ�(�����)��\n\n ";
    cout << "������û��Ϲ��ĳ�������ת�أ����а�Ȩ������ʹ�á�\n\n\n\n";
    cout << "����������ʽ��������";
    cin>>LinNum;
    cout << "\n�밴��ʽ��������ʽ����(���ּ��ÿո�ֿ�)��\n\n";
    int a[100][100];
    for(int i=0;i<LinNum;i++){//for1
        char ch[1000];
        for(int i=0;i<1000;i++){
            ch[i]='\n';
        }
        cin.getline(ch,1000);
        for(int j=0;j<1000;j++){//for2
            if(ch[j]==32){//if1
                m=j-1;
                b=m-n+1;
                for(int t=0;t<b;t++){//for3
                    a[i][c]=(ch[n+t]-48)*fun10(b-1-t);
                    c=c+1;
                    if(c==LinNum){//if2
                        c=0;
                        break;
                    }//if2
                }//for3
            }//if1
        }//for2
    }//for1

    for(int c=0;c<LinNum;c++){
        for(int d=0;d<LinNum;d++){
            cout << a[c][d];
        }
        printf("\n");
    }
    return 0;
}
int fun10(int z){
  int n = 10;
  for(int i=0;i<z;i++){
    n=n*10;
  }
  n=n/10;
  return n;
}
