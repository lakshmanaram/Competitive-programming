#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
#define max_size 100
using namespace std;
struct avlnode{											//a single node containing value, pointer to parent and left and right children. ------ having a parent pointer is optional, can be proceeded without having it.
	int value;
	avlnode *parent, *left_child, *right_child;
};
class avltree{
public:
	avlnode *root;
	avltree(){
		root = NULL;
	}
	avlnode *RRrotation(avlnode *node){
		avlnode *temperory_right = node->right_child;
		temperory_right->parent = node->parent;
		node->right_child = temperory_right->left_child;
		if(temperory_right->left_child!=NULL) temperory_right->left_child->parent = node;
		node->parent = temperory_right;
		temperory_right->left_child = node;
		return temperory_right;
	}
	avlnode *LLrotation(avlnode *node){
		avlnode *temperory_left = node->left_child;
		temperory_left->parent = node->parent;
		node->left_child = temperory_left->right_child;
		if(temperory_left->right_child != NULL) temperory_left->right_child->parent = node;
		node->parent = temperory_left;
		temperory_left->right_child = node;
		return temperory_left;	
	}
	avlnode *LRrotation(avlnode *node){
		node -> left_child = RRrotation(node->left_child);
		node -> left_child -> parent = node;
		return LLrotation(node);
	}
	avlnode *RLrotation(avlnode *node){
		node -> right_child = LLrotation(node->right_child);
		node -> right_child -> parent = node;
		return RRrotation(node);
	}
	void preorder_traversal(avlnode *node){
		if(node == NULL)
			return;
		cout<<" "<<node->value<<" "; 
		preorder_traversal(node->left_child);
		preorder_traversal(node->right_child);
		return;
	}
	void postorder_traversal(avlnode *node){
		if(node == NULL)
			return;
		postorder_traversal(node->left_child);
		postorder_traversal(node->right_child);
		cout<<" "<<node->value<<" "; 
		return;
	}
	void inorder_traversal(avlnode *node){
		if(node == NULL)
			return;
		inorder_traversal(node->left_child);
		cout<<" "<<node->value<<" "; 
		inorder_traversal(node->right_child);
		return;
	}
	int get_height(avlnode *node){
		if(node==NULL)
			return 0;
		return 1 + max(get_height(node -> left_child),get_height(node -> right_child));
	}
	int get_balance(avlnode *node){
		if(node == NULL)
			return 0;
		return get_height(node -> left_child) - get_height(node->right_child);
	}
	avlnode *createnode(int value){
		avlnode *temp_node = new avlnode;
		temp_node->value = value;
		temp_node->right_child = NULL;
		temp_node->left_child = NULL;
		temp_node->parent = NULL;
		return temp_node;
	}
	avlnode *insertnode(avlnode *node, int value){
		if(node == NULL){
			return createnode(value);
		}
		else if(value < node->value){
			node->left_child = insertnode(node->left_child,value);
			node->left_child->parent = node;
		}
		else{
			node->right_child = insertnode(node->right_child,value);
			node->right_child->parent = node;
		}
		int balance = get_balance(node);
		display();
		if(balance>1){
			if(get_balance(node->left_child)>0){
				cout<<node->value<<"  Left-Left rotation"<<endl;
				return LLrotation(node);
			}
			else{
				cout<<node->value<<" Left-Right rotation"<<endl;
				return LRrotation(node);
			}
		}
		else if(balance<-1){
			if(get_balance(node->right_child)>0){
				cout<<node->value<<" Right-Left rotation"<<endl;
				return RLrotation(node);
			}
			else{
				cout<<node->value<<" Right-Right rotation"<<endl;
				return RRrotation(node);
			}
		}
		return node;
	}
	void insert(int value){
		root = insertnode(root,value);
		display();
	}
	void display(){
		//this function and it's sub-functions are for visualization 
		queue<avlnode*> bfsqueue;
		bfsqueue.push(root);
		bfs(bfsqueue,1,1);
	}
	void bfs(queue<avlnode*> bfsqueue,int remaining, int pow_of_2){
		//remaining - number of values remaining in a particular line
		remaining --;
		for(int i=0;i<(max_size/2)/pow_of_2;i++)
			cout<<" ";
		avlnode *temp = bfsqueue.front();
		bfsqueue.pop();
		if(temp == NULL){
			if(pow_of_2<pow(2,get_height(root))){
				cout<<" ";
				bfsqueue.push(NULL);
				bfsqueue.push(NULL);
			}
		}
		else{
			if(pow_of_2<pow(2,get_height(root))){
				cout<<temp->value;
				bfsqueue.push(temp->left_child);
				bfsqueue.push(temp->right_child);
			}
		}
		for(int i=0;i<(max_size/2)/pow_of_2;i++)
			cout<<" ";
		if(remaining==0){
			cout<<endl;
			pow_of_2*=2;
			remaining = pow_of_2;
		}
		if(bfsqueue.empty())
			return;
		bfs(bfsqueue,remaining,pow_of_2);
	}
	void deletenode(int x){
		return;
	}
}avl_tree;
int main(){
	int ch;
	int x;
	do{
		cout<<"Enter Choice: 1.Insert 2.Delete 3.Preorder 4.Postorder 5.Inorder 6.Actual tree 7.Exit: ";
		cin>>ch;
		switch(ch){
			case 1:
			cout<<"Enter value to be inserted: ";
			cin>>x;
			avl_tree.insert(x);
			break;
			case 2:
			cout<<"Enter value to be deleted: ";
			cin>>x;
			avl_tree.deletenode(x);
			break;
			case 3:
			avl_tree.preorder_traversal(avl_tree.root);
			break;
			case 4:
			avl_tree.postorder_traversal(avl_tree.root);
			break;
			case 5:
			avl_tree.inorder_traversal(avl_tree.root);
			break;
			case 6:
			avl_tree.display();
			case 7:
			break;
			default:
			cout<<"Invalid Choice";
		}
	}while(ch!=4);
	return 0;
}