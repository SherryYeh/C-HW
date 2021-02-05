#include<stdio.h>
#include<math.h>
typedef struct Link{
        int power;
        int coef;
        struct Link* pNext;
};

typedef struct Link* Poly;
typedef struct Link* pLink;

// =============================================
void AddData(Poly p, int _coef, int _power); // �s�W���
void Travel(Poly p); // �L�X���
void InputData(Poly p); // ��J���
void LinkAdd(Poly A, Poly B, Poly C); // a+b=c�ۥ[
void LinkMul(Poly A, Poly B, Poly C); // a*b=c�ۭ�
void RemoveCoefZero(Poly p); //�N�t�Ƭ�0�� node ����
// =============================================

// =============================================
// �s�W���
void AddData(Poly p, int _coef, int _power)
{
        Poly tmp = p;

        while(tmp->pNext!=NULL) {

                if(tmp->pNext->power == _power) {
                        // ����@�ˡA�t�ƪ����A�[�i�h
                        tmp->pNext->coef += _coef;
                        return ;
                }
                else if(tmp->pNext->power > _power){
                        // �����{�����p�A�`�I�[�b�o�Ӥ��e
                        Poly tmp2 = tmp->pNext;
                        tmp->pNext = (pLink)malloc(sizeof(struct Link));
                        tmp->pNext->power = _power;
                        tmp->pNext->coef=_coef;
                        tmp->pNext->pNext = tmp2;
                        return ;

                }
                else{
                        // �����{�����j�A�~�򩹫��
                        tmp=tmp->pNext;
                }
        }

        // �̫�S���, �ͭӷs���`�I�X��
        // malloc the new node, be the last .
        tmp->pNext = (pLink)malloc(sizeof(struct Link));
        tmp->pNext->pNext = NULL;
        tmp->pNext->coef = _coef;
        tmp->pNext->power = _power;
}
// =============================================
// �L�X���
void Travel(Poly p)
{
        Poly tmp = p->pNext;
        printf("\n===== travel =====\n");
        if(tmp==NULL) {
                printf("0\n");
                return ;
        }

        while(tmp!=NULL){
                if(tmp==p->pNext)printf("%d*X^%d ",  tmp->coef,tmp->power);
                else printf("%+d*X^%d ",  tmp->coef,tmp->power);
                tmp = tmp->pNext;
        }
        printf("\n");
}
// =============================================
// ��J���
void InputData(Poly p)
{
        int n=0, i=0;
        int _coef=0, _power=0;
        scanf("%d", &n);
        for(i=0; i<n; i++){
                scanf("%d%d", &_coef, &_power);
                AddData(p, _coef, _power );

        }
}
// =============================================
// �ۥ[
void LinkAdd(Poly A, Poly B, Poly C)
{
        Poly tmpA = A->pNext;
        Poly tmpB = B->pNext;

        while(tmpA!=NULL) AddData(C, tmpA->coef, tmpA->power), tmpA=tmpA->pNext;
        while(tmpB!=NULL) AddData(C, tmpB->coef, tmpB->power), tmpB=tmpB->pNext;
}
// =============================================
// �ۭ�
void LinkMul(Poly A, Poly B, Poly C)
{
        Poly tmpA = A->pNext;
        Poly tmpB = B->pNext;

        while(tmpA!=NULL){
                tmpB = B->pNext;

                while(tmpB!=NULL){
                        AddData(C, tmpA->coef * tmpB->coef,        tmpA->power + tmpB->power);
                        tmpB = tmpB ->pNext;
                }
                tmpA = tmpA->pNext;
        }
}
// =============================================
// �N�t�Ƭ� 0 �̥h��
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
// ����O����
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
        // initialize

        Poly A, B, Add_C, Mul_D;
        A = (pLink)malloc(sizeof(struct Link));
        A->pNext = NULL;

        B = (pLink)malloc(sizeof(struct Link));
        B->pNext = NULL;

        Add_C = (pLink)malloc(sizeof(struct Link));
        Add_C->pNext = NULL;

        Mul_D = (pLink)malloc(sizeof(struct Link));
        Mul_D->pNext = NULL;

        // input data
        InputData(A);
        InputData(B);
        LinkAdd(A, B, Add_C);
        LinkMul(A, B, Mul_D);
        RemoveCoefZero(Add_C), Travel(Add_C);
        RemoveCoefZero(Mul_D), Travel(Mul_D);
        ReleaseLink(A);
        ReleaseLink(B);

        return 0;
}
