#include<stdio.h>
struct node{
    int data;
    struct node * left;
    struct node * right;
};
typedef struct node NODE;
typedef NODE * pTree;
//=========================
void Init(pTree &t){
    t = NULL;
}
//=========================
void AddNode(pTree &t, int x){
    if(t == NULL){
        NODE * p = new NODE;
        p->data = x;
        p->left = NULL;
        p->right = NULL;
        t = p;
    }else{
        if(t->data > x){
            AddNode(t->left,x);
        }else if(t->data < x){
            AddNode(t->right,x);
        }
    }
}
//===============================
void NLR(pTree t){
    if(t != NULL){
        printf(" %d",t->data);
        NLR(t->left);
        NLR(t->right);
    }
}
//================================
void LNR(pTree t){
    if(t != NULL){
        LNR(t->left);
        printf(" %d",t->data);
        LNR(t->right);
    }
}
//=================================
void LRN(pTree t){
    if(t != NULL){
        LRN(t->left);
        LRN(t->right);
        printf(" %d",t->data);
    }
}
//=================================
void menu(pTree t){
    while(true){
        printf("\n");
        printf("\n//==========MENU==============//\n");
        printf("1.Nhap du lieu\n");
        printf("2.Xuat du lieu\n");
        printf("//=============================//\n");
        int chon;
        printf("Nhap 1 lua chon: ");
        scanf("%d",&chon);
        if(chon < 1 || chon > 2){
            printf("\nLua chon khong hop le !!!!!");
        }else if(chon == 1){
            int x;
            printf("Hay nhap gia tri x: ");
            scanf("%d",&x);
            AddNode(t,x);
        }else if(chon == 2){
            printf("\nCAY NHI PHAN THEO NLR: \n");
            NLR(t);
            printf("\nCAY NHI PHAN THEO LNR: \n");
            LNR(t);
            printf("\nCAY NHI PHAN THEO LRN: \n");
            LRN(t);
        }else{
            break;
        }
    }
}
//=================================
int main(){
    pTree t;
    Init(t);
    menu(t);
    return 0;
}