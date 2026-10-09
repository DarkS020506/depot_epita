struct node{
    int key;
    struct node * left_child;
    struct node * right_child;
};

struct binary_tree{
    struct node* root;
    int size;
    int height;
};

void BFS(struct node*root){
    struct queu * myqueu=create();
    enqueu(myqueu, root);
    while{
        struct node * curr=dequeu(myqueu);
        printf("%d\n", curr->key);
        if (curr->left_child != NULL){
            enqueu(myqueu,curr->left_child);
        }
        if (curr->right_child != NULL){
            enqueu(myqueu,curr->right_child);
        }
    }
}

struct node *insertLeaf(struct node *root, int value) {
    if (root == NULL) {
        struct node *nouveau = (struct node *)malloc(sizeof(struct node));
        nouveau->value = value;
        nouveau->left = NULL;
        nouveau->right = NULL;
        return root;
    }
    if (value < root->value) {
        root->left = insertLeaf(root->left, value);
    }
    else if (value > root->value) {
        root->right = insertLeaf(root->right, value);
    }
    return root;
}

struct node *insertLeaf(struct node *root, int value) {

    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL) {
        return newNode;
    }

    struct node *current = root;
    struct node *parent = NULL;

    while (current != NULL) {
        parent = current;
        if (value < current->value) {
            current = current->left;
        } else if (value > current->value) {
            current = current->right;
        } 
    }
    if (value < parent->value) {
        parent->left = newNode;
    } else {
        parent->right = newNode;
    }

    return root;
}

struct node * deleteNode(struct node* root, int value){
    if (root==NULL){
        return NULL
    }else{
        struct node * delNode=root;
        struct node * parent=NULL;
        while (delNode != NULL && delNode->key!=value){
            parent=delNode;
            if (delNode->key < value){
                delNode=delNode->left_child;
            }else{
                delNode=delNode->right_child;
            }
        }
        if (delNode==NULL){
            return root;
        }
        if (delNode->left_child==NULL && delNode->right_child==NULL){
            if (delNode==NULL){
                root=root->left_child;
            }else{
                if (parent->key<value){
                    parent->right_child=NULL;
                }else{
                    parent->left_child=NULL;
                }
            }
            free(delNode);
            delNode=NULL;
            return root;
        }
        if (delNode->left_child!=NULL && delNode->right_child!=NULL){
            if (delNode==NULL){
                root=root->left_child;
            }else{
                if (parent->key<value){
                    parent->right_child=delNode->left_child;
                }else{
                    parent->left_child=delNode->right_child;
                }
            }
            free(delNode);
            delNode=NULL;
            return root;
        }
    }
}