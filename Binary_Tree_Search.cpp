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
//================================
void DeleteX(pTree &t,int data){
    if(t==NULL){
        return;
    }else{
        if(data > t->data){
            DeleteX(t->right,data);
        }else if(data < t->data){
            DeleteX(t->left,data);
        }else{
            NODE * X = t;
            if(t->left == NULL){
                t = t->right;
            }else if(t->right == NULL){
                t = t->left;
            }
            delete X;
        }
    }
}
//===============================
int DemSoNODE(pTree t){
    if(t == NULL)
    return 0;
    return 1 + DemSoNODE(t->left) + DemSoNODE(t->right);
}
//================================
int DemNodeLa(pTree t){
    if(t == NULL) return 0;
    int dem = 0;
    if(t->left == NULL && t->right == NULL) dem = 1;
        return dem + DemNodeLa(t->left) + 
                     DemNodeLa(t->right);
}
//================================
void XuatNodeLa(pTree t){
    if(t != NULL){
        if(t->left == NULL && t->right == NULL)
            printf("%d, ",t->data);
            XuatNodeLa(t->left);
            XuatNodeLa(t->right);
    }
}
//================================
void menu(pTree t){
    while(true){
        printf("\n");
        printf("\n//==========MENU==============//\n");
        printf("1.Nhap du lieu\n");
        printf("2.Xuat du lieu\n");
        printf("3.Xoa 1 node X bat ki\n");
        printf("4.Dem so NODE trong cay\n");
        printf("5.Dem node la va Xuat\n");
        printf("//=============================//\n");
        int chon;
        printf("Nhap 1 lua chon: ");
        scanf("%d",&chon);
        if(chon < 1 || chon > 5){
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
        }else if(chon == 3){
            int x;
            printf("Nhap 1 node X can xoa: ");
            scanf("%d",&x);
            DeleteX(t,x);
        }else if(chon == 4){
            printf("Co khoang %d so node trong cay",DemSoNODE(t));
        }else if(chon == 5){
            printf("So node LA trong cay: %d",DemNodeLa(t));
            printf("Xuat cac Node LA: ");
            XuatNodeLa(t);
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
