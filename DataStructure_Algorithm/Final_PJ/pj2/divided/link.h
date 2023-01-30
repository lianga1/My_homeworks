#ifndef __LINK_H__
#define __LINK_H__

#include "location.h"
#include <malloc.h>
#include <stdlib.h>

typedef struct n{
    Location loc;
    struct n *next;
} LinkNode;

LinkNode* CreateEmptyList();
LinkNode* List_pushback(LinkNode* prior,Location data);
LinkNode* List_add_from_front(LinkNode* head,Location data);
LinkNode* ReverseList(LinkNode* new_head,LinkNode* origin_head);
void DestroyList(LinkNode* head);

#endif