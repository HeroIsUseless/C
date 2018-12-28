#include<stdio.h>
#include<stdlib.h>
typedef  int  KeyType;
typedef  struct {                      
  KeyType *elem; /*elem[0]一般作哨兵或缓冲区*/                       
  int Length;      
}SqList;
void  CreatSqList(SqList *L);/*待排序列建立，由裁判实现，细节不表*/ 
void  SelectSort(SqList L);
int main()
{
  SqList L;
  int i;
  CreatSqList(&L);
  SelectSort(L);
  for(i=1;i<=L.Length;i++)
   {		
     printf("%d ",L.elem[i]);
   }
  return 0;
}
/*你的代码将被嵌在这里 */
//待测长度1~1000
void SelectSort(SqList L){
    for(int i=1; i<=L.Length; i++){
        for(int j=i; j<=L.Length; j++){
            if(i != j){
                if(L.elem[i] > L.elem[j]){
                    int t;
                    t = L.elem[j];
                    L.elem[j] = L.elem[i];
                    L.elem[i] = t;
                }
            }
        }
    }
}