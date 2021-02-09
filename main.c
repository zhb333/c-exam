//
// Created by Administrator on 2021/2/9.
//
#include <stdio.h>
#include <stdlib.h>
typedef char DataType;

typedef struct node {
  DataType data;
  struct node *next;
} ListNode;

typedef ListNode *LinkList;
//ListNode *p;
//LinkList head;

/**
 * 头插法建立单链表
 * @return 头指针
 */
LinkList CreateListF() {
  LinkList head;
  ListNode *p;
  char ch;
  head = NULL;
  ch = getchar();
  while (ch != '\n') {
    p = (ListNode *) malloc(sizeof(ListNode));
    p->data = ch;
    p->next = head;
    head = p;
    ch = getchar();
  }
  return head;
}

/**
 * 尾插法建立单链表
 * @return 头指针
 */
LinkList CreateListR() {
  LinkList head, rear;
  ListNode *p;
  char ch;
  head = NULL;
  rear = NULL;
  ch = getchar();
  while (ch != '\n') {
    p = (ListNode *) malloc(sizeof(ListNode));
    p->data = ch;
    if (head == NULL) {
      head = p;
    } else {
      rear->next = p;
    }
    rear = p;
    ch = getchar();
  }
  if (rear != NULL) {
    rear->next = NULL;
  }
  return head;
}

/**
 * 尾插法建立带头节点的单链表
 * @return 头节点
 */
LinkList CreateListR1() {
  LinkList head = (ListNode *) malloc(sizeof(ListNode));
  ListNode *p, *r;
  DataType ch;
  r = head;
  while ((ch = getchar()) != '\n') {
    p = (ListNode *) malloc(sizeof(ListNode));
    p->data = ch;
    r->next = p;
    r = p;
  }
  r->next = NULL;
  return head;
}

/**
 * 带头节点的单链表根据位置查找
 * @param head 头指针
 * @param i 查找的位置，从 1 开始
 * @return 查找位置的指针 或 NULL
 */
ListNode *GetNode(LinkList head, int i) {
  ListNode *p;
  int j;
  p = head->next;
  j = 1;
  while (p != NULL && j < i) {
    p = p->next;
    j++;
  }
  if (j == i) {
    return p;
  } else {
    return NULL;
  }
}

/**
 * 带头节点的单链表按值查找
 * @param head 头节点
 * @param k 查找的值
 * @return 查找到的位置指针 或 NULL
 */
ListNode *LocateNode(LinkList head, DataType k) {
  ListNode *p = head->next;
  while (p && p->data != k) {
    p = p->next;
  }
  return p;
}

/**
 * 带头节点的单链表插入操作
 * @param head 头节点
 * @param i 插入位置，从 1 开始；
 * @param x 插入的值
 */
void InsertList(LinkList head, int i, DataType x) {
  ListNode *p, *s;
  int j;
  p = head;
  j = 0;
  while (p != NULL && j < i - 1) {
    p = p->next;
    j++;
  }

  if (p == NULL) {
    printf("Error\n");
    return;
  } else {
    s = (ListNode *) malloc(sizeof(ListNode));
    s->data = x;
    s->next = p->next;
    p->next = s;
  }
}

/**
 * 删除带头节点的单链表
 * @param head 头指针
 * @param i 删除是位置，从 1 开始
 * @return 删除节点的数据值
 */
DataType DeleteList(LinkList head, int i) {
  ListNode *p, *s;
  DataType x;
  int j;
  p = head;
  j = 0;
  while (p != NULL && j < i - 1) {
    p = p->next;
    j++;
  }
  if (p == NULL) {
    printf('位置错误\n');
    exit(0);
  } else {
    s = p->next;
    p->next = s->next;
    x = s->data;
    free(s);
    return x;
  }
}

/**
 * 将不带头节点的单链表的开始节点连接到原单链表的尾部，原来第二个节点变成开始节点
 * @param L 不带头节点的单链表
 * @return 连接后的单链表头指针
 */
LinkList MyNote(LinkList L) {
  ListNode *q, *p;
  if (L && L->next) {
    q = L;
    L = L->next;
    p = L;
    while (p->next) {
      p = p->next;
    }
    p->next = q;
    q->next = NULL;
  }
  return L;
}

/**
 * 按序号奇偶分解单链表
 * @param a 带头节点，待分解的单链表
 * @param b 带头节点的空链表
 */
void split(LinkList a, LinkList b) {
  ListNode *p, *r, *s;
  p = a->next;
  r = a;
  s = b;
  while (p != NULL) {
    r->next = p;
    r = p;
    p = p->next;
    if (p) {
      s->next = p;
      s = p;
      p = p->next;
    }
    r->next = s->next = NULL;
  }
}

/**
 * 将两个递增有序的单链表，合并为另一个单链表
 * @param La 带头节点的单链表
 * @param Lb 带头节点的单链表
 * @return 合并后的单链表
 */
LinkList MergeList(LinkList La, LinkList Lb) {
  ListNode *pa, *pb, *pc;
  LinkList Lc;
  pa = La->next;
  pb = Lb->next;
  Lc = pc = La;
  while (pa != NULL && pb != NULL) {
    if (pa->data <= pb->data) {
      pc->next = pa;
      pc = pa;
      pa = pa->next;
    } else {
      pc->next = pb;
      pc = pb;
      pb = pb->next;
    }
  }
  pc->next = pa != NULL ? pa : pb;
  free(Lb);
  return Lc;
}

/**
 * 在从大到小的单链表中，执行插入操作，并使单链表保持递减有序
 * @param L 带头节点的单链表
 * @param x 待插入的值
 */
void InsertList(LinkList L, int x) {
  ListNode *s, *p, *q;
  s = (ListNode *) malloc(sizeof(ListNode));
  s->data = x;
  p = L;
  q = p->next;
  while (q->data > x && q != L) {
    p = p->next;
    q = p->next;
  }
  p->next = s;
  s->next = q;
}

/**
 * 删除带头节点的单链表中重复的值
 * @param head 头指针
 */
void UniqueList(LinkList head) {
  ListNode *p, *q;
  p = head->next;
  while (p != head) {
    q = p->next;
    while (q != head && q->data == p->data) {
      p->next = q->next;
      free(q);
      q = p->next;
    }
    p = p->next;
  }
}

typedef struct dlnode {
  DataType data;
  struct dlnode *prior, *next;
} DLNode;

typedef DLNode *DLinkList;
//DLinkList head;

/**
 * 删除带头节点的双向链表中指定节点
 * @param p 待删除节点指针
 * @return 删除节点的数据值
 */
DataType DLDelete(DLNode *p) {
  p->prior->next = p->next;
  p->next->prior = p->prior;
  DataType x = p->data;
  free(p);
  return x;
}

/**
 * 将值为 x 的新节点插入到带头节点的双向链表中指定节点 *p 之前
 * @param p 指定节点
 * @param x 待插入的值
 */
void DLInsertBefore(DLNode *p, DataType x) {
  DLNode *s = (DLNode *) malloc(sizeof(DLNode));
  s->data = x;
  s->prior = p->prior;
  s->next = p;
  p->prior->next = s;
  p->prior = s;
}

/**
 * 将值为 x 的新节点插入到带头节点的双向链表中指定节点 *p 之后
 * @param p 指定节点
 * @param x 待插入的值
 */
void DLInsertBefore(DLNode *p, DataType x) {
  DLNode *s = (DLNode *) malloc(sizeof(DLNode));
  s->data = x;
  s->prior = p;
  s->next = p->next;
  p->next->prior = s;
  p->next = s;
}

/**
 * 修复双向循环链表的前驱指针域
 * @param head 头指针
 */
void trans(DLinkList head) {
  DLNode *p;
  p = head;
  while (p->next != head) {
    p->next->prior = p;
    p=p->next;
  }
  head->prior = p;
}