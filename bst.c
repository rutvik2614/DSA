#include <stdio.h>
#include <stdlib.h>
 
struct node 
{
    int key;
    struct node *left, *right;
};
 
// A utility function to create a new BST node
struct node* newNode(int item)
{
    struct node* temp ;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
 

void inorder(struct node* root)
{
    if (root != NULL) 
    {
        inorder(root->left);
        printf("%d \t", root->key);
        inorder(root->right);
    }
}
void preorder(struct node* root)
{
    if (root != NULL) 
    {
        printf("%d \t", root->key);
        preorder(root->left);    
        preorder(root->right);
    }
}
void postorder(struct node* root)
{
    if (root != NULL) 
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d \t", root->key);
    }
}
 
/* A utility function to insert
   a new node with given key in
 * BST */
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);
    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    /* return the (unchanged) node pointer */
    return node;
}
struct node* minValueNode(struct node* node)
{
    struct node* current = node;
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
    current = current->left;
    return current;
}
  
/* Given a binary search tree 
   and a key, this function
   deletes the key and 
   returns the new root */
struct node* deleteNode(struct node* root, int key)
{
    // base case                                  
    if (root == NULL)                 //empty tree
    return root;
    // If the key to be deleted 
    // is smaller than the root's
    // key, then it lies in left subtree
    if (key < root->key)
    root->left = deleteNode(root->left, key);
    // If the key to be deleted 
    // is greater than the root's
    // key, then it lies in right subtree
    else if (key > root->key)
    root->right = deleteNode(root->right, key);
    // if key is same as root's key, 
    // then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL) 
        {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) 
        {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
  
        // node with two children: 
        // Get the inorder successor
        // (smallest in the right subtree)
        struct node* temp = minValueNode(root->right);
        // Copy the inorder 
        // successor's content to this node
        root->key = temp->key;
  
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
       return root;
    
    // Key is greater than root's key
    if (root->key < key)
       return search(root->right, key);
 
    // Key is smaller than root's key
    return search(root->left, key);
}

int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    
    // root=insert(root, 50);
    // root=insert(root, 30);
    // root=insert(root, 20);
    // root=insert(root, 40);
    // root=insert(root, 70);
    // root=insert(root, 60);
    // root=insert(root, 80);
    int n,x,choice;
    struct node* root = NULL;
    printf("enter the number of nodes in bst : ");
    scanf("%d",&n);
    do
    {
        printf("\n1.INSERT\n2.DELETE\n3.INORDER\n4.PREORDER\n5.POSTORDER\n6.EXIT\nENTER YOUR CHOICE :");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
            for(int i=1;i<=n;i++)
            {
                printf("enter the value to be inserted : ");
                scanf("%d",&x);
                root=insert(root,x);
            }
            break;
            case 2 :
            printf("enter the value to be deleted : ");
            scanf("%d",&x);
            root=deleteNode(root,x);
            break;
            case 3 :
            printf("INORDER TRAVERSAL :\n");
            inorder(root);
            break;
            case 4 :
            printf("PREORDER TRAVERSAL :\n");
            preorder(root);
            break;
            case 5 :
            printf("POSTORDER TRAVERSAL :\n");
            postorder(root);
            break;
            case 6 :
            exit(0);
            default:printf("invalid choice.\n");
        }
    }while(choice!=6);
    return 0;
}