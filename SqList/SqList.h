//
//  SqList.h
//  data_structure_and_algorithm
//
//  Created by NeonRocks on 2019/3/24.
//  Copyright © 2019 NeonRocks. All rights reserved.
//


// header is used to store the definition of the method and function
// also header can store some header and typedef, morevoer, structure


#ifndef SqList_h
#define SqList_h

#include <stdio.h>
#include "Header.h"

#endif /* SqList_h */

typedef struct {
    ElemType *elem;
    int length;
    int list_size;
}SqList;

// definition of SqList method

Status InitList_Sq(SqList *L);
/*
 Parameter: SqList *L : (is to input the pointer L)
 do:
    init the SqList Structure and divide the space to it
 */


void CreateList_Sq(SqList *L,int length);
/*
 Parameter: SqList *L :is to input the pointer L
 Parameter: int length : the length of the SqList to create
 do:
    input the pointer pointing to the SqList
    create the list with length
 
 */


void Display_Sq(SqList *L);
/*
 Parameter: SqList *L : the pointer point to the SqList
 do:
    display the specific SqList
 */


void DestroyList_Sq(SqList *L);
/*
 Parameter : SqList *L : the pointer point to the SqList
 do:
    destroy the list and create the contain of the list
 */

void ClearList_Sq(SqList *L);

Status ListEmpty_Sq(SqList L);

Status ListLength_Sq(SqList L);

Status GetElem_Sq(SqList *L, int i, int* e);

Status LocateElem_Sq(SqList L, int e /*compare*/);

Status ListInsert_Sq(SqList *L, int i, int e);

Status ListDelete_Sq(SqList *L, int i, int* e);

void MergeList(SqList *La, SqList *Lb, SqList *Lc);


int SqListUse(void);
