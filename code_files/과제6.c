#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

struct BinarySearchTreeNode {
	int data;
	struct BinarySearchTreeNode* left;
	struct BinarySearchTreeNode* right;
};

struct BinarySearchTreeNode* Find(struct BinarySearchTreeNode* root, int data) {
    if (root == NULL)
        return NULL;
    if (data < root->data)
        return Find(root->left, data);
    else if (data > root->data)
        return Find(root->right, data);
    return root;
}


struct BinarySearchTreeNode* FindBSTree(struct BinarySearchTreeNode* root, int data) { //O(logn)
    if (root == NULL)
        return NULL;
    while (root) {
        if (data == root->data)
            return root;
        else if (data > root->data)
            root = root->right;
        else
            root = root->left;
    }
    return NULL;
}

struct BinarySearchTreeNode* InsertBS(struct BinarySearchTreeNode* root, int data) { //O(n)
    if (root == NULL) {
        root = (struct BinarySearchTreeNode*)malloc(sizeof(struct BinarySearchTreeNode));
        if (root == NULL) {
            printf("Memory Error");
            return NULL;
        }
        else {
            root->data = data;
            root->left = root->right = NULL;
        }
    }
    else {
        if (data < root->data)   root->left = InsertBS(root->left, data);
        else if (data > root->data)   root->right = InsertBS(root->right, data);
    }
    return root;
}

void DeleteAllBSTree(struct BinarySearchTreeNode* BSnode) {
    if (BSnode) {
        DeleteAllBSTree(BSnode->left);
        DeleteAllBSTree(BSnode->right);
    }
    free(BSnode);
}

struct AVLTreeNode {
    int data;
    struct AVLTreeNode* left;
    struct AVLTreeNode* right;
    int height;
};

int Height(struct AVLTreeNode* root) {
    if (!root) return -1;
    else return root->height;
}


struct AVLTreeNode* FindAVLTree(struct AVLTreeNode* root, int data) { //O(logn)
    if (root == NULL)
        return NULL;
    while (root) {
        if (data == root->data)
            return root;
        else if (data > root->data)
            root = root->right;
        else
            root = root->left;
    }
    return NULL;
}

struct AVLTreeNode* SingleRotateLeft(struct AVLTreeNode* X) {
    struct AVLTreeNode* W = X->left;
    X->left = W->right;
    W->right = X;
    X->height = max(Height(X->left), Height(X->right)) + 1;
    W->height = max(Height(W->left), X->height) + 1;
    return W;
}

struct AVLTreeNode* SingleRotateRight(struct AVLTreeNode* W) {
    struct AVLTreeNode* X = W->right;
    W->right = X->left;
    X->left = W;
    W->height = max(Height(W->left), Height(W->right)) + 1;
    X->height = max(W->height, Height(X->right)) + 1;
    return X;
}

struct AVLTreeNode* DoubleRotatewithLeft(struct AVLTreeNode* Z) {
    Z->left = SingleRotateRight(Z->left);
    return  SingleRotateLeft(Z);
}

struct AVLTreeNode* DoubleRotatewithRight(struct AVLTreeNode* X) {
    X->right = SingleRotateLeft(X->right);
    return  SingleRotateRight(X);
}

struct AVLTreeNode* InsertAVL(struct AVLTreeNode* root, int data) { //O(logn)
    if (!root) {
        root = (struct AVLTreeNode*)malloc(sizeof(struct AVLTreeNode));
        if (!root) {
            printf("Memory Error");
            return NULL;
        }
        else {
            root->data = data;
            root->height = 0;
            root->left = root->right = NULL;
        }
    }
    else if (data < root->data) { 
        root->left = InsertAVL(root->left, data);
        if ((Height(root->left) - Height(root->right)) == 2) {
            if (data < root->left->data) 
                root = SingleRotateLeft(root);
            else root = DoubleRotatewithLeft(root); 
        }
    }
    else if (data > root->data) { 
        root->right = InsertAVL(root->right, data);
        if ((Height(root->right) - Height(root->left)) == 2) {
            if (data > root->right->data) 
                root = SingleRotateRight(root);
            else root = DoubleRotatewithRight(root); 
        }
    }

    root->height = max(Height(root->left), Height(root->right)) + 1;
    return root;
}

void DeleteAllAVLTree(struct AVLTreeNode* node) {
    if (node) {
        DeleteAllAVLTree(node->left);
        DeleteAllAVLTree(node->right);
    }
    free(node);
}

int main() {
    clock_t start, end;
    //1¹ø
    printf("<<1¹ø>>\n");
    for (int size = 100000; size <= 1000000; size += 100000) {
        printf("<%d>\n", size);
        struct BinarySearchTreeNode* BSRoot = NULL;

        start = clock();
        for (int i = 0; i < size; i++) {
            BSRoot = InsertBS(BSRoot, (int)(((double)((rand() << 15) | rand())) / (((RAND_MAX << 15) | RAND_MAX) + 1) * (size)));
        }
        end = clock();

        printf("Binary Search Insert %d : %d\n", size, (end - start));

        start = clock();
        for (int i = 0; i < size; i++) {
            FindBSTree(BSRoot, (int)(((double)((rand() << 15) | rand())) / (((RAND_MAX << 15) | RAND_MAX) + 1) * (size)));
        }
        end = clock();

        printf("Binary Search find %d : %d\n\n", size, (end - start));

        DeleteAllBSTree(BSRoot);

        struct AVLTreeNode* AVLRoot = NULL;

        start = clock();
        for (int i = 0; i < size; i++) {
            AVLRoot = InsertAVL(AVLRoot, (int)(((double)((rand() << 15) | rand())) / (((RAND_MAX << 15) | RAND_MAX) + 1) * (size)));
        }
        end = clock();

        printf("AVL Search Insert %d : %d\n", size, (end - start));

        start = clock();
        for (int i = 0; i < size; i++) {
            FindAVLTree(AVLRoot, (int)(((double)((rand() << 15) | rand())) / (((RAND_MAX << 15) | RAND_MAX) + 1) * (size)));
        }
        end = clock();

        printf("AVL Search find %d : %d\n\n", size, (end - start));

        DeleteAllAVLTree(AVLRoot);
    }


    printf("\n\n<<2¹ø>>\n");
    for (int size = 1000; size <= 10000; size += 1000) {
        printf("<%d>\n", size);
        struct BinarySearchTreeNode* BSRoot = NULL;

        start = clock();
        for (int i = 0; i < size; i++) {
            BSRoot = InsertBS(BSRoot, i);
        }
        end = clock();

        printf("Binary Search Insert %d : %d\n", size, (end - start));

        start = clock();
        for (int i = 0; i < size; i++) {
            FindBSTree(BSRoot, rand() % size);
        }
        end = clock();

        printf("Binary Search find %d : %d\n\n", size, (end - start));

        DeleteAllBSTree(BSRoot);

        struct AVLTreeNode* AVLRoot = NULL;

        start = clock();
        for (int i = 0; i < size; i++) {
            AVLRoot = InsertAVL(AVLRoot, i);
        }
        end = clock();

        printf("AVL Search Insert %d : %d\n", size, (end - start));

        start = clock();
        for (int i = 0; i < size; i++) {
            FindAVLTree(AVLRoot, rand() % size);
        }
        end = clock();

        printf("AVL Search find %d : %d\n\n", size, (end - start));

        DeleteAllAVLTree(AVLRoot);
    }
}