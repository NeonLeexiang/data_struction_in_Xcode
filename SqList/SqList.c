//
//  SqList.c
//  data_structure_and_algorithm
//
//  Created by NeonRocks on 2019/3/24.
//  Copyright © 2019 NeonRocks. All rights reserved.
//

#include "SqList.h"


// InitList_Sq()
Status InitList_Sq(SqList *L) {
    // init method of SqList
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE* sizeof(ElemType));
    
    if(!L->elem) exit(OVERFLOW);
    
    L->length = 0;
    L->list_size = LIST_INIT_SIZE;
    
    return OK;
}

// CreateList_Sq()
void CreateList_Sq(SqList *L,int length){
    // create a SqList by entering the length and every elem of list
    printf("we use InitList_Sq function to create a Sq_list\n");
    L->length = length;
    
    for(int i = 0; i < L->length; i++){
        printf("please enter L[%d]\n",i);
        scanf("%d",&L->elem[i]);
    }
}

// Display_Sq()
void Display_Sq(SqList *L){
    // method to display all the elem of SqList
    printf("the elem of SqList\n");
    
    for(int i = 0;i < L->length;i++){
        printf("%4d",L->elem[i]);
    }
    
    printf("\n");
}


void DestroyList_Sq(SqList *L){
    free(L);
    L->length = 0;
    if (L != NULL) {printf("error in Destory List");}
}

void ClearList_Sq(SqList *L){
    for (int i = 0; i < L->length; i++) {
        L->elem[i] = 0;
    }
    printf("list has been clear to zero!");
}


Status ListLength_Sq(SqList L){
    printf("the length of the SqList is:\n %d \n", L.length);
    return L.length;
}


Status ListEmpty_Sq(SqList L){
    // L.length == 0 ? printf("list is empty!\n") : printf("list length is %d \n", L.length);
    if (L.length==0) {
        printf("list is empty!\n");
        return TRUE;
    }
    else {
        printf("list length is %d \n", L.length);
        return FALSE;
    };
}


Status GetElem_Sq(SqList *L, int i, int *e){
    if (i < 1 || i > L->length){
        printf("Index Error of i!");
        return INFEASIBLE;
    }
    *e = L->elem[i];
    return OK;
}

Status LocateElem_Sq(SqList L, int e /*compare*/){
    int j = 0;
    for (int i = 0; i < L.length; i++){
        if (L.elem[i] == e){
            j = i;
            break;
        }
    }
    if (j != 0) {printf("the %d is locate in %d \n", e, j);}
    return j;
}

Status ListInsert_Sq(SqList *L, int i, int e){
    if (i < 0) {
        printf("the i: %d is out of range", i);
        return INFEASIBLE;
    }
    
    if (i > L->length){
        // extend the SqList
    }
    
    for (int j = L->length + 1; j > i; j--) {
        *(L->elem + j) = *(L->elem + j - 1);
    }
    
    *(L->elem + i) = e;
    L->length += 1;
    
    return OK;
    
}


Status ListDelete_Sq(SqList *L, int i, int* e){
    if (i < 0 || i > L->length) {
        printf("the i is out of range \n");
        return INFEASIBLE;
    }
    
    e = &L->elem[i];
    
    for (int j = i; j < L->length; j++) {
        *(L->elem+j) = *(L->elem+j+1);
    }
    
    L->length -= 1;
    
    return OK;
}


void MergeList(SqList *La, SqList *Lb, SqList *Lc){
    if (La->length + Lb->length > LIST_INIT_SIZE){
        // add the space of SqList Lc
    }
    // do the merge
    
    int i = 0, j = 0, k = 0;
    
    while (i < La->length && j < Lb->length) {
        if (*(La->elem+i) < *(Lb->elem+j)) {
            *(Lc->elem+k) = *(La->elem+i);
            ++k; ++i;
        }
        else if (*(La->elem+i) == *(Lb->elem+j)){
            *(Lc->elem+k) = *(La->elem+i);
            ++k; ++i;
            *(Lc->elem+k) = *(Lb->elem+j);
            ++k; ++j;
        }
        else{
            *(Lc->elem+k) = *(Lb->elem+j);
            ++k; ++j;
        }
    }
    
    while (i < La->length) {
        *(Lc->elem+k) = *(La->elem+i);
        ++k; ++i;
    }
    
    while (j < Lb->length) {
        *(Lc->elem+k) = *(Lb->elem+j);
        ++k; ++j;
    }
    
    // printf("k = %d, i = %d, j = %d \n", k, i, j);
    
    Lc->length = La->length + Lb->length;
    
}


int SqListUse(void) {
    // insert code here...
    
    /*
    SqList sq_list;
    InitList_Sq(&sq_list);  // init a sq_list
    int len = LIST_INIT_SIZE;
    printf("please enter the length of your SqList: \n");
    scanf("%d", &len);
    CreateList_Sq(&sq_list, len);
    Display_Sq(&sq_list);
    
    // test
    ListLength_Sq(sq_list);
    
    int i = 0;
    printf("please enter the ith you want to get elem: \n");
    scanf("%d", &i);
    
    int e = 0;
    GetElem_Sq(&sq_list, i, &e);
    printf("the %d th elem is %d \n", i, e);
    
    int e2;
    printf("please enter the elem you want to locate \n");
    scanf("%d", &e2);
    LocateElem_Sq(sq_list, e2);
    
    int i2;
    int e3;
    printf("the ith element you want to delete\n");
    scanf("%d", &i2);
    ListDelete_Sq(&sq_list, i2, &e3);
    printf("the %dth number you have been deleted is %d", i2, e3);
    Display_Sq(&sq_list);
    
    int i3;
    int e4;
    printf("the index of i you want to insert into the list \n");
    scanf("%d", &i3);
    printf("the elem you want to insert\n");
    scanf("%d", &e4);
    ListInsert_Sq(&sq_list, i3, e4);
    Display_Sq(&sq_list);
     
     */
    
    // try the merge method
    SqList sq_list_a;
    SqList sq_list_b;
    
    int len = LIST_INIT_SIZE;
    
    printf("please enter the len of the list a and b\n");
    scanf("%d", &len);
    
    InitList_Sq(&sq_list_a);
    InitList_Sq(&sq_list_b);
    printf("create list a\n");
    CreateList_Sq(&sq_list_a, len);
    
    printf("create list b\n");
    CreateList_Sq(&sq_list_b, len);
    
    SqList sq_list_c;
    InitList_Sq(&sq_list_c);
    
    printf("Now merge the list_a and list_b into list_c\n");
    MergeList(&sq_list_a, &sq_list_b, &sq_list_c);
    printf("the length of c = \n %d \n", sq_list_c.length);
    Display_Sq(&sq_list_c);
    
    return 0;
}
