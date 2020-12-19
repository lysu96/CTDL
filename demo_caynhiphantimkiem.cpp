#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node
{
    int data;
    Node* left;
    Node* right;
} node_t;
 
 node_t* Tao_Node(node_t*p,int x){
	p = (node_t*)malloc(sizeof(node_t));
	p->data = x;
	p->left = p->right = NULL;
	return p;
}
 
void Free( node_t* root )
{
    if ( root == NULL )
        return;
 
    Free( root->left );
    Free( root->right );
    free( root );
}
 
int LeftOf( const int value, const node_t* root )
{
    // Neu ban muon cây BST cho phép giá tri trùng lop, hãy su dung dòng code thu 2
    return value < root->data;
//    return value <= root->data;
}
 
int RightOf( const int value, const node_t* root )
{
    return value > root->data;
}
 
node_t* Insert( node_t* root, const int value )
{
    if ( root == NULL )
    {
        node_t* node = (node_t*)malloc( sizeof( node_t ) );
        node->left = NULL;
        node->right = NULL;
        node->data = value;
        return node;
    }
    if ( LeftOf( value, root ) )
        root->left = Insert( root->left, value );
    else if ( RightOf( value, root ) )
        root->right = Insert( root->right, value );
    return root;
}
 
bool Search( const node_t* root, int value )
{
    if ( root == NULL )
        return false;
    if(root->data == value){
        return true;
    }else if ( LeftOf( value, root ) ){
        return Search( root->left, value );
    }else if( RightOf( value, root ) ){
        return Search( root->right, value );
    }
}
 
int LeftMostValue( const node_t* root )
{
    while ( root->left != NULL )
        root = root->left;
    return root->data;
}
 
node_t* Delete( node_t* root, int value )
{
    if ( root == NULL )
        return root;
    if ( LeftOf( value, root ) )
        root->left = Delete( root->left, value );
    else if ( RightOf( value, root ) )
        root->right = Delete( root->right, value );
    else
    {
        // root->data == value, delete this node
        if ( root->left == NULL )
        {
            node_t* newRoot = root->right;
            free( root );
            return newRoot;
        }
        if ( root->right == NULL )
        {
            node_t* newRoot = root->left;
            free( root );
            return newRoot;
        }
        root->data = LeftMostValue( root->right );
        root->right = Delete( root->right, root->data );
    }
    return root;
}
 
void PreOrder(node_t* root){
    if(root != NULL)
    {
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
 
void InOrder(node_t* root){
    if(root != NULL)
    {
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}
 
void PostOrder(node_t* root){
    if(root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->data);
    }
}
 
 // nhap
node_t *Nhap_NPTK(node_t* p, int x){
	printf("Node = ");
	scanf("%d",&x);
	if(x==0)
		return NULL;
	p = Tao_Node(p,x);
	printf("\tCon trai node %d\n",x);
	p->left = Nhap_NPTK(p,x);
	printf("\tCon phai node %d\n",x);
	p->right = Nhap_NPTK(p,x);
	
	return p;
}
// nhap
node_t *Nhap_NPTK_TXX(node_t* p, int x){
	
	int n;
	printf("Nhap vao cac phan tu trong cay nhi phan tim kiem.\n");
	printf("Nhap (0) de ket thuc nhap\n");
	do{
		printf("Node = ");
		scanf("%d",&n);
		if(x != 0)
			Nhap_NPTK_TXX(p,n);
	}while(x != 0);
	
	return p;
}
 
int main()
{
    node_t* R = NULL;

 	int x;
 	node_t* root;
    root = Nhap_NPTK_TXX(R,x);

    printf("\nDuyet Dau : ");
    PreOrder(root);
    printf("\nDuyet Giua  : ");
    InOrder(root);
    printf("\nDuyet Cuoi:");
    PostOrder(root);
 
    printf("\n==Thu them phan tu vao cay==\n");
    int k;
    printf("Nhap phan tu: ");
    scanf("%d",&k);
    Insert(root,k);
    printf("\nDuyet Dau : ");
    PreOrder(root);
    printf("\nDuyet Giua  : ");
    InOrder(root);
    printf("\nDuyet Cuoi:");
    PostOrder(root);
 
    printf("\n==Thu xoa phan tu khoi Cay==\n");
    int h;
    printf("Nhap phan tu: ");
    scanf("%d",&h);
    Delete(root,h);
    printf("\nDuyet Dau : ");
    PreOrder(root);
    printf("\nDuyet Giua  : ");
    InOrder(root);
    printf("\nDuyet Cuoi:");
    PostOrder(root);
 
    Free( root );
    root = NULL;
    return 0;
}
