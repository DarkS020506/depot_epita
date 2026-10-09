struct node* searchBST(struct node* root, int value){
    //condition d'arret
    if (root==NULL){
        return NULL;
    }
    if (root->key==value){
        return root;
    }
    //recurence
    if (root->key < value){
        return searchBST(root->right_child, value);
    }else{
        return searchBST(root->left_child, value);
    }
}

struct node* searchBST(struct node* root, int value){
    struct node* current=root;
    while (current != NULL && current->key != value){
        if (current->key < value){
            current=current->right_child;
        }else{
            current=current->left_child;
        }
    }
    return current;
}


struct node * insertLeaf(struct node * root, int value){
    struct node* current=root;
    while (current != NULL){
        if (current->key < value){
            current=current->right_child;
        }else{
            current=current->left_child;
        }
    }
    current->key=
}