#include<stdio.h>
#include<string.h>
#include<math.h>
typedef struct Link{
        int exp;
        int coef;
        struct Link* pNext;
};

typedef struct Link* Poly;
typedef struct Link* pLink;

void AddData(Poly p, int _coef, int _exp)
{
        Poly tmp = p;

        while(tmp->pNext!=NULL) {

                if(tmp->pNext->exp == _exp) {
                        // 次方一樣，系數直接再加進去
                        tmp->pNext->coef += _coef;
                        return ;
                }
                else if(tmp->pNext->exp < _exp){
                        // 次方比現有的小，節點加在這個之前
                        Poly tmp2 = tmp->pNext;
                        tmp->pNext = (pLink)malloc(sizeof(struct Link));
                        tmp->pNext->exp = _exp;
                        tmp->pNext->coef=_coef;
                        tmp->pNext->pNext = tmp2;
                        return ;

                }
                else{
                        // 次方比現有的大，繼續往後找
                        tmp=tmp->pNext;
                }
        }

        // 最後沒找到, 生個新的節點出來
        // malloc the new node, be the last .
        tmp->pNext = (pLink)malloc(sizeof(struct Link));
        tmp->pNext->pNext = NULL;
        tmp->pNext->coef = _coef;
        tmp->pNext->exp = _exp;
}

void Print(Poly p)
{
        Poly tmp = p->pNext;
        if(tmp==NULL) {
                printf("0\n");
                return ;
        }

        while(tmp!=NULL){
                printf("%d ",  tmp->coef);
                tmp = tmp->pNext;
        }
        printf("\n");
}

void InputData(Poly p)
{
    char str[50],*_coef,*word[50];
    int n=-1,i=0;
    gets(str);
    _coef = strtok(str," ");
    while (_coef != NULL){
        word[i]=_coef;
        i++;
        _coef = strtok (NULL," ");
        n++;
      }
    for(i=n; i>=0; i--){
        AddData(p,atoi(word[i]),n-i);
    }
}

void LinkAdd(Poly A, Poly B, Poly C)
{
        Poly tmpA = A->pNext;
        Poly tmpB = B->pNext;

        while(tmpA!=NULL) AddData(C, tmpA->coef, tmpA->exp), tmpA=tmpA->pNext;
        while(tmpB!=NULL) AddData(C, tmpB->coef, tmpB->exp), tmpB=tmpB->pNext;
}

void LinkMul(Poly A, Poly B, Poly C)
{
        Poly tmpA = A->pNext;
        Poly tmpB = B->pNext;

        while(tmpA!=NULL){
                tmpB = B->pNext;

                while(tmpB!=NULL){
                        AddData(C, tmpA->coef * tmpB->coef,        tmpA->exp + tmpB->exp);
                        tmpB = tmpB ->pNext;
                }
                tmpA = tmpA->pNext;
        }
}
// =============================================
// 將系數為 0 者去除
void RemoveCoefZero(Poly p)
{
        Poly pre = p;
        Poly cur = p->pNext;

        while(cur!=NULL){
                if(cur->coef==0) {
                        pre->pNext = cur->pNext;
                        free(cur);
                        cur = pre->pNext;
                        continue;
                }
                pre = cur;
                cur = cur->pNext;
        }
}

// =============================================
// 釋放記憶體
void ReleaseLink(Poly p)
{
        Poly tmp = p->pNext;
        while(tmp!=NULL){
                p->pNext = tmp->pNext;
                free(tmp);
                tmp = p->pNext;
        }
        free(p);
}
// =============================================
int main()
{
        int i=0;
        Poly A, B, Add_C, Mul_D;
        A = (pLink)malloc(sizeof(struct Link));
        A->pNext = NULL;

        B = (pLink)malloc(sizeof(struct Link));
        B->pNext = NULL;

        Add_C = (pLink)malloc(sizeof(struct Link));
        Add_C->pNext = NULL;

        Mul_D = (pLink)malloc(sizeof(struct Link));
        Mul_D->pNext = NULL;
        InputData(A);
        InputData(B);
        LinkAdd(A, B, Add_C);
        LinkMul(A, B, Mul_D);
        RemoveCoefZero(Add_C), Print(Add_C);
        RemoveCoefZero(Mul_D), Print(Mul_D);
        ReleaseLink(A);
        ReleaseLink(B);

}
