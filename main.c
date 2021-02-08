#include <stdio.h>

/**
 * 百钱买百鸡
 * @param g 公鸡
 * @param m 母鸡
 * @param s 小鸡
 * @return 多少种情况
 */
int Chicken(int g[], int m[], int s[]) {
  int a, b, c, k = 0;
  for (a = 0; a <= 20; a++) {
    for (b = 0; b <= 33; b++) {
      c = 100 - a - b;
      if ((5 * a + 3 * b + c / 3 == 100) && (c % 3 == 0)) {
        g[k] = a;
        m[k] = b;
        s[k] = c;
        k++;
      }
    }
  }
  return k;
}

#define ListSize 100
typedef int DataType;
typedef struct {
  DataType data[ListSize];
  int length;
} SeqList;

/**
 * 顺序表插入操作
 * @param L 顺序表指针
 * @param i 插入的位置，从 1 开始
 * @param x 插入的值
 */
void InsertList(SeqList *L, int i, DataType x) {
  int j;
  if (i < 1 || i > L->length + 1) {
    printf("position error\n");
    return;
  }

  if (L->length >= ListSize) {
    printf("%d overflow\n", L->length);
    return;
  }
  for (j = L->length - 1; j >= i - 1; j--) {
    L->data[j + 1] = L->data[j];
  }
  L->data[i - 1] = x;
  L->length++;
}

/**
 * 顺序表删除操作
 * @param L 顺序表指针
 * @param i 删除的位置，从 1 开始
 */
void DeleteList(SeqList *L, int i) {
  int j;
  if (i < 1 || i > L->length) {
    printf("position error");
    return;
  }

  for (j = i; j <= L->length - 1; j++) {
    L->data[j - 1] = L->data[j];
  }
  L->length--;
}

/**
 * 顺序表元素调换
 * @param L 顺序表
 * @return 调换后的顺序表
 */
SeqList ConVerts(SeqList L) {
  DataType x;
  int i, k;
  k = L.length / 2;
  for (i = 0; i < k; i++) {
    x = L.data[i];
    L.data[i] = L.data[L.length - i - 1];
    L.data[L.length - i - 1] = x;
  }
  return L;
}

/**
 * 求最大值，最小值，以及最大值位置，最小值位置
 * @param L 顺序表
 * @param max 最大值指针
 * @param min 最小值指针
 * @param k 最大值位置指针
 * @param j 最小值位置指针
 */
void MaxMin(SeqList L, DataType *max, DataType *min, int *k, int *j) {
  int i;
  *max = *min = L.data[0];
  *k = *j = 1;
  for (i = 1; i < L.length; i++) {
    if (L.data[i] > *max) {
      *max = L.data[i];
      *k = i + 1;
    } else if (L.data[i] < *min) {
      *min = L.data[i];
      *j = i + 1;
    }
  }
}

int main() {
  int i;

  int g[4], m[4], s[4], count;
  count = Chicken(g, m, s);
  for (i = 0; i < count; i++) {
    printf("公鸡：%d 只, 母鸡 %d 只, 小鸡 %d 只\n", g[i], m[i], s[i]);
  }

  SeqList L;
  L.length = 0;
  for (i = 0; i < 10; i++) {
    InsertList(&L, i + 1, i + 1);
  }

  L = ConVerts(L);

  for (i = 0; i < L.length; i++) {
    printf("L.data[%d] = %d\n", i, L.data[i]);
  }

  DataType max, min;
  int maxPos, minPos;
  MaxMin(L, &max, &min, &maxPos, &minPos);
  printf("max=%d, maxPos=%d, min=%d, minPos=%d", max, maxPos, min, minPos);
  return 0;
}

