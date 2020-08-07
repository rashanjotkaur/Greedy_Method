#include<bits/stdc++.h>
using namespace std;

struct Node{
    int fre;
    char ch;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int fre,char ch){
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->fre=fre;
    temp->ch=ch;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct cmp{
  bool operator()( struct Node *a,struct Node *b) {
      return a->fre > b->fre;
  } 
};
void preorder(Node*root,string s){
    if(root->left==NULL && root->right==NULL){
        cout<<s<<" ";
        return;
    }
    preorder(root->left,s+"0");
    preorder(root->right,s+"1");
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        int n=str.size();
        int x;
        priority_queue<Node*,vector<Node*>,cmp>pq;
        for(int i=0;i<n;i++){
            cin>>x;
            struct Node *temp=newNode(x,str[i]);
            pq.push(temp);
        }
        // to generate tree
        while(pq.size()!=1){
            struct Node* l=pq.top();
            pq.pop();
            struct Node* r=pq.top();
            pq.pop();
            int sum=l->fre+r->fre;
            struct Node* temp=newNode(sum,'$');
            temp->left=l;
            temp->right=r;
            pq.push(temp);
        }
        // get root
        Node* root=pq.top();
        string s="";
        preorder(root,s);
        cout<<endl;
    }
    return 0;
}

// we can also do this without storing the character because we have to print in preorder traversal not according to characters
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int fre;
    Node*left;
    Node*right;
};

struct Node *newNode(int fre){
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->fre=fre;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct cmp{
  bool operator()(struct Node *a,struct Node *b) {
      return a->fre > b->fre;
  } 
};

void preorder(Node*root,string s){
    if(root->left==NULL && root->right==NULL){
        cout<<s<<" ";
        return;
    }
    preorder(root->left,s+"0");
    preorder(root->right,s+"1");
}

int main(){
    int t;
    cin>>t;
    string str;
    while(t--){
        cin>>str;
        int n=str.length();
        int x;
        priority_queue<Node*,vector<Node*>,cmp>pq;
        for(int i=0;i<n;i++){
            cin>>x;
            struct Node *temp=newNode(x);
            pq.push(temp);
        }
        while(pq.size()!=1){
            struct Node* l=pq.top();
            pq.pop();
            struct Node* r=pq.top();
            pq.pop();
            int sum=l->fre + r->fre;
            Node* temp=newNode(sum);
            temp->left=l;
            temp->right=r;
            pq.push(temp);
        }
        Node* root=pq.top();
        string str="";
        preorder(root,str);
        cout<<endl;
    }
    return 0;
}
