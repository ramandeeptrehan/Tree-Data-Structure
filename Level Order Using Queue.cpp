//
//  Level Order Using Queue.cpp
//  Tree
//
//  Created by Ramandeep Singh Trehan on 25/10/16.
//  Copyright © 2016 Ramandeep Singh Trehan. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#define maxQueueSize 1000

using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

queue<struct node*> myQueue; //queue holds different nodes of tree

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    
    node->data=data;
    node->right=NULL;
    node->left=NULL;
    
    return node;
}

void printLevelOrder(struct node *root)
{
    struct node *temp = root;
    myQueue.push(temp);
    
    while(myQueue.empty()==0)
    {
        temp= myQueue.front();
        myQueue.pop();
        
        cout<<temp->data<<" ";
        
        if(temp->left!=NULL)
        {
            myQueue.push(temp->left);
        }
        
        if(temp->right!=NULL)
        {
            myQueue.push(temp->right);
        }
        
    }
}
int main()
{
    struct node* root=newNode(1);
    
    root->left = newNode(8);
    root->right = newNode(3);
    
    root->left->left = newNode(90);
    root->left->right = newNode(5);
    
    printLevelOrder(root);
    
}

