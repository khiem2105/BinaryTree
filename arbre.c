#include "arbre.h"

int main()
{
    nut *T=NULL;
    int i,n=6,valeur;
    for(i=0;i<=n;i++)
    {
        printf("Nhap gia tri cua la:\n"); scanf("%d",&valeur);
        BoSung(&T,valeur);
    }

    // prefixe(T);
    // infixe(T);
    // postfixe(T);
    infixe(T);
}
//     printf("Cau 1:\n");
//     printf("Chieu cao:%d\n",ChieuCao(T));
//     printf("Cau 4:\n");
//     printf("Phan tu lon nhat:%d\n",Max_BST(T));
//     printf("Phan tu lon nhat:%d\n",Max_OrdinaryTree(T));
//     printf("Cau 5:\n");
//     printf("Nut nhanh:%d\n",NutNhanh(T)-1);
//     printf("Cau 6:\n");
//     nut *temp=T->Left->Left;
//     if(TimNutCha(T,temp)!=NULL) printf("Nut cha cua %d la:%d\n",temp->info,TimNutCha(T,temp)->info);
//     else printf("Khong tim thay");
//     printf("Muc cua %d la:%d\n",temp->info,TimMuc(T,temp));
//     printf("Cau 7:\n");
//     if(Search_OrdinaryTree(T,3)!=NULL)
//     printf("Nut co gia tri 3:%d",Search_OrdinaryTree(T,3)->info);
//     else printf("Khong tim thay");
//     printf("Cau 8:\n");
//     InCayGiamDan(T);
//     printf("Cau 9:\n");
//     nut *newTree=NULL;
//     CopyCay(T,&newTree);
//     InCayGiamDan(newTree);
//     printf("Cau 10:\n");
//     if(check_BST(T)) printf("BST!\n");
//     else printf("Khong phai BST!\n");
//     printf("Cau 11\n");
//     printf("Cap:%d\n",TimCap(T));
//     printf("Cau 12\n");
//     ThayThe(&T,T);
//     InCayGiamDan(T);
//     printf("So nut muc 2:%d\n",TimSoNutMucx(T,0));
//     printf("Cau 13:\n");
//     node *F=NULL;
//     taoDanhsachtuCay(T,&F);
//     affichageListe(F);
//     arrangeListeIncrease(&F);
//     affichageListe(F);
//     nut *t,*L,*R;
//     t=(nut*)malloc(sizeof(nut)); L=(nut*)malloc(sizeof(nut)); R=(nut*)malloc(sizeof(nut));
//     t->info=5; L->info=7; R->info=2;
//     R->Left=NULL;R->Right=NULL;
//     L->Left=NULL;L->Right=NULL;
//     t->Left=L;t->Right=R;
//     transformtoBST(&temp);
//     if(check_BST(temp)) printf("BST!\n");
//     printf("Cau 14:\n");
//     if(check_heap(T)) printf("Cay la 1 dong\n");
//     else printf("Khong phai 1 dong\n");
//     heapsortTree(&T);
//     if(check_heap(T)) printf("Cay la 1 dong\n");
// }