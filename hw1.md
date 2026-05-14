## 1. Swap two integers

#include <stdio.h>

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

int main(void) {
    int x, y;
    scanf("%d %d", &x, &y);

    swap(&x, &y);

    printf("%d %d\n", x, y);
    return 0;
}


## 2. Allocate array, reverse it, print it, free memory

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n;
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n / 2; i++) {
        int t = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = t;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    free(a);
    return 0;
}


---

## 3. Allocate matrix, transpose it, print result, free memory

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    int **a = (int **)malloc(n * sizeof(int *));
    int **b = (int **)malloc(m * sizeof(int *));
    if (a == NULL || b == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        a[i] = (int *)malloc(m * sizeof(int));
        if (a[i] == NULL) {
            return 1;
        }
    }

    for (int i = 0; i < m; i++) {
        b[i] = (int *)malloc(n * sizeof(int));
        if (b[i] == NULL) {
            return 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b[j][i] = a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);

    for (int i = 0; i < m; i++) {
        free(b[i]);
    }
    free(b);

    return 0;
}


---

## 4. Singly linked list, read until 0, reverse, print, free

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
};

int main(void) {
    struct Node *head = NULL;
    struct Node *tail = NULL;

    int x;
    while (scanf("%d", &x) == 1 && x != 0) {
        struct Node *cur = (struct Node *)malloc(sizeof(struct Node));
        if (cur == NULL) {
            return 1;
        }

        cur->value = x;
        cur->next = NULL;

        if (head == NULL) {
            head = cur;
            tail = cur;
        } else {
            tail->next = cur;
            tail = cur;
        }
    }

    struct Node *prev = NULL;
    struct Node *cur = head;

    while (cur != NULL) {
        struct Node *nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }

    head = prev;

    cur = head;
    while (cur != NULL) {
        printf("%d ", cur->value);
        cur = cur->next;
    }
    printf("\n");

    cur = head;
    while (cur != NULL) {
        struct Node *nxt = cur->next;
        free(cur);
        cur = nxt;
    }

    return 0;
}
