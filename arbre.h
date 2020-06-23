#include <stdio.h>
#include <stdlib.h>

struct nut 
{
    int info;
    struct nut *Left, *Right;
};

typedef struct nut nut;

struct node
{
    int info;
    struct node* next;
};

typedef struct node node;
//*****Câu 1*****//
int ChieuCao(nut *T)
{
    if(T==NULL) return 0;
    else
    {
        int ChieuCaoLeft=ChieuCao(T->Left),ChieuCaoRight=ChieuCao(T->Right);
        if(ChieuCaoLeft>ChieuCaoRight) return ChieuCaoLeft+1;
        else return ChieuCaoRight+1;
    }
}
//*****Câu 2*****//
void BoSung(nut **T,int value)
{
    if(*T==NULL)
    {
        (*T)=(nut*)malloc(sizeof(nut));
        (*T)->info=value;
        (*T)->Left=NULL;
        (*T)->Right=NULL;
    }
    else if(value >= (*T)->info) BoSung(&((*T)->Right),value);
    else BoSung(&((*T)->Left),value);    
}
//*****Câu 3*****//
void xoaCay(nut **T)
{
    if((*T)==NULL) return;
    xoaCay(&((*T)->Left));
    xoaCay(&((*T)->Right));
    free(*T);
}
//*****Câu 4*****//
int Max_BST(nut *T)
{
    if(T->Right==NULL) return T->info;
    return Max_BST(T->Right);
}

int Max_OrdinaryTree(nut *T)
{
    if(T->Right==NULL && T->Left==NULL) return T->info;
    if(T->Left==NULL && T->Right!=NULL)
    {
        if(Max_OrdinaryTree(T->Right)>T->info) return Max_OrdinaryTree(T->Right);
        return T->info;
    }
    if(T->Left!=NULL && T->Right==NULL)
    {
        if(Max_OrdinaryTree(T->Left)>T->info) return Max_OrdinaryTree(T->Left);
        return T->info;
    }
    
    int Max_L=Max_OrdinaryTree(T->Left),Max_R=Max_OrdinaryTree(T->Right);
    if(Max_L >= Max_R && Max_L >= T->info) return Max_L;
    if(Max_R >= Max_L && Max_R >= T->info) return Max_R;
    if(T->info >= Max_L && T->info >= Max_R) return T->info;
}
//*****Câu 5*****//
int NutNhanh(nut *T)
{
    if(T==NULL) return 0;
    if(T->Right==NULL && T->Left==NULL) return 0;
    return (NutNhanh(T->Left)+NutNhanh(T->Right)+1);
}
//*****Câu 6*****//
nut* TimNutCha(nut *T,nut *p)
{
    if(p==NULL) return NULL;
    if(T==NULL) return NULL;
    if(T->Left==p || T->Right==p) return T;
    if(TimNutCha(T->Left,p)==NULL && TimNutCha(T->Right,p)==NULL) return NULL;
}

int TimMuc(nut *T,nut *p)
{
    if(p==NULL)
    {
        printf("Khong tim thay");
        return -1;
    }
    if(p==T) return 0;
    return 1+TimMuc(T,TimNutCha(T,p));
}
//*****Câu 7*****//
nut* Search_BST(nut *T,int value)
{
    if(T==NULL) return NULL;
    if(value == T->info) return T;
    if(value > T->info) return Search_BST(T->Right,value);
    return Search_BST(T->Left,value);
}

nut* Search_OrdinaryTree(nut *T,int value)
{
    if(T==NULL) return NULL;
    if(value==T->info) return T;
    if(Search_OrdinaryTree(T->Left,value)==NULL && Search_OrdinaryTree(T->Right,value)==NULL)
    return NULL;
}
//*****Câu 8*****//
void InCayGiamDan(nut *T)
{
    if(T!=NULL)
    {
        InCayGiamDan(T->Right);
        printf("%d ",T->info);
        InCayGiamDan(T->Left);
    }
}
//*****Câu 9*****//
void CopyCay(nut *T,nut **new)
{
    if(T!=NULL)
    {
        BoSung(new,T->info);
        CopyCay(T->Left,new);
        CopyCay(T->Right,new);
    }
}
//*****Câu 10*****//
int check_BST(nut *T)
{
    if(T!=NULL &&(T->Left!=NULL || T->Right!=NULL))
    {
        if(T->Right==NULL) return (check_BST(T->Left) && (T->Left->info < T->info));
        if(T->Left==NULL) return (check_BST(T->Right) && (T->Right->info > T->info));
        return (check_BST(T->Left) && check_BST(T->Right) 
               && (T->Left->info < T->info) && (T->Right->info > T->info));
    }
    return 1;
}
//*****Câu 11*****//
int TimCap(nut *T)
{
    if(T!=NULL && (T->Left!=NULL || T->Right!=NULL))
    {
        if(T->Left==NULL && (TimCap(T->Right) > 1)) return TimCap(T->Right);
        if(T->Left==NULL && (TimCap(T->Right) <= 1)) return 1;
        if(T->Right==NULL && (TimCap(T->Left) > 1)) return TimCap(T->Left);
        if(T->Right==NULL && (TimCap(T->Left) <= 1)) return 1;
        return 2;
    }
    return 0;
}
//*****Câu 12*****//
void ThayThe(nut **T,nut *temp)
{
    if((*T)!=NULL)
    {
        ThayThe(&((*T)->Left),temp);
        (*T)->info=TimMuc(temp,*T);
        ThayThe(&((*T)->Right),temp); 
    }
}

int SonutMucx(nut *T,int x)
{
    if(T!=NULL && T->info < x) return SonutMucx(T->Left,x)+SonutMucx(T->Right,x);
    if(T!=NULL && T->info==x) return 1;
    if(T==NULL) return 0;
}

int TimSoNutMucx(nut *T,int x)
{
    ThayThe(&T,T);
    return SonutMucx(T,x);
}
//*****Câu 13*****//
//Danh sách
void initiateListe(node **f)
{
    *f=NULL;
}//khởi tạo ds

int listeVide(node *f)
{
    return(f==NULL);
}//kiểm tra ds trống

void ajouteListe(node **f,int x)
{
    if(*f==NULL)
    {
        *f=(node*)malloc(sizeof(node));
        (*f)->info=x;
        (*f)->next=NULL;
    }
    else
    {
        node *n,*q;
        q=*f;
        n=(node*)malloc(sizeof(node));
        n->info=x;
        while(q->next!=NULL)
        {
            q=q->next;
        }
        q->next=n;
        n->next=NULL;
    }
}//thêm vào cuối danh sách

void affichageListe(node *f)
{
    while(f->next!=NULL)
    {
        printf("%d\n",f->info);
        f=f->next;
    }
    printf("%d\n",f->info);
}//hiển thị ds

void taoDanhsachtuCay(nut *T,node **F)
{
    if(T!=NULL)
    {
        ajouteListe(F,T->info);
        taoDanhsachtuCay(T->Left,F);
        taoDanhsachtuCay(T->Right,F);
    }
}

void arrangeListeIncrease(node **f)
{
    node *q,*n;
    q=*f;
    while(q->next!=NULL)
    {
       n=q->next;
       while(n!=NULL)
        {
            if(n->info < q->info)
            {
                int tmp;
                tmp=q->info;
                q->info=n->info;
                n->info=tmp;
            }
            n=n->next;
        }
        q=q->next;
    }

}//sắp xếp danh sách tăng dần

void transformtoBST(nut **T)
{
    node *F=NULL;
    taoDanhsachtuCay(*T,&F);
    xoaCay(T);
    while(F!=NULL)
    {
        BoSung(T,F->info);
        F=F->next;
    }
}
//*****Câu 14*****//
int check_heap(nut *T)
{
    if(T!=NULL && (T->Left!=NULL || T->Right!=NULL))
    {
        if(T->Left==NULL) return(check_heap(T->Right) && (T->Right->info <= T->info));
        if(T->Right==NULL) return(check_heap(T->Left) && (T->Left->info <= T->info));
        return(check_heap(T->Left) && check_heap(T->Right) 
              && (T->Left->info <= T->info) && (T->Right->info <= T->info));
    }
    return 1;
}

void swap(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

void heapsortTree(nut **T)
{
    if(*T!=NULL && ((*T)->Left!=NULL || (*T)->Right!=NULL))
    {
        if((*T)->Left==NULL)
        {
            heapsortTree(&((*T)->Right));
            if((*T)->Right->info > (*T)->info) 
            {
                swap(&((*T)->Right->info),&((*T)->info));
                heapsortTree(&((*T)->Right));
            }    
        }
        if((*T)->Right==NULL)
        {
            heapsortTree(&((*T)->Left));
            if((*T)->Left->info > (*T)->info) 
            {
                swap(&((*T)->Left->info),&((*T)->info));
                heapsortTree(&((*T)->Left));
            }    
        }
        if((*T)->Left!=NULL && (*T)->Right!=NULL)
        {
            heapsortTree(&((*T)->Left)); heapsortTree(&((*T)->Right));
            if((*T)->Left->info >= (*T)->Right->info && (*T)->Left->info > (*T)->info) 
            {   
               swap(&((*T)->Left->info),&((*T)->info));
               heapsortTree(&((*T)->Left));
            }   
            else if((*T)->Right->info >= (*T)->Left->info && (*T)->Right->info > (*T)->info) 
            { 
               swap(&((*T)->Right->info),&((*T)->info));
               heapsortTree(&((*T)->Right));
            }
        }
    }
}
