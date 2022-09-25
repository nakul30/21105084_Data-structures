#include <iostream>
#include <string>
using namespace std;
class Node{
    public:
    string name;
    int age;
    Node*prev;
    Node*next;
    Node(string name,int age){
        this ->name=name;
        this->age=age;
        prev=NULL;
        next=NULL;
    }
};
int family_size(Node*head){
    if(head==NULL){
        return 0;
    }
    int size=1;
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
        size+=1;
    }
    return size;
}
void insertmember_end(Node*head,string name1, int age1){
    if(head==NULL){
        return;
    }
    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node*prev1=temp;
    temp->next=new Node(name1,age1);
    temp=temp->next;
    temp->prev=prev1;
}
void print(Node*head){
    if(head==NULL){
        cout<<-1<<endl;
    }
    Node*temp=head;
    cout<<"PRINT IN INPUT ORDER:"<<endl;
    while(temp->next!=NULL){
        cout<<temp->name<<":"<<temp->age<<" -> ";
        temp=temp->next;
    }
    cout<<temp->name<<":"<<temp->age<<endl;
    cout<<endl;
    cout<<"PRINT IN REVERSE ORDER:"<<endl;
    while(temp->prev!=NULL){
        cout<<temp->name<<":"<<temp->age<<" -> ";
        temp=temp->prev;
    }
    cout<<temp->name<<":"<<temp->age<<endl;
}
Node* takeInput(){
    string name;
    cout<<"Enter name: ";
    cin>>name;
    int age;
    cout<<"Enter age: ";
    cin>>age;
    cout<<endl;
    Node*head=NULL;
    Node*tail=NULL;
    while(name!="-1" or age!=-1){
        Node*newNode=new Node(name,age);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        }
        else{
            Node*prev1=tail;
            tail->next=newNode;
            tail=tail->next;
            tail->prev=prev1;
        }
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter age: ";
        cin>>age;
        cout<<endl;
    }
    return head;
}
int main(){
    Node*head=takeInput();
    cout<<endl;
    print(head);
    cout<<endl;
    cout<<"Family size:";
    int familysize=family_size(head);
    cout<<familysize<<endl;
    cout<<endl;
    string name;
    cout<<"Give the NAME of the member you want to insert :"<<endl;
    cin>>name;
    cout<<endl;
    int age;
    cout<<"Give the AGE of the member you want to insert:"<<endl;
    cin>>age;
    insertmember_end(head,name,age);
    cout<<endl;
    print(head);
    cout<<endl;
    cout<<"Family size:";
    familysize=family_size(head);
    cout<<familysize<<endl;
    cout<<endl;
    return 0;
}
// when you want to stop giving the input enter the name as -1 and age as -1 as shown in the below input
/*
custom input->
father 30
mother 29
child1 3
child2 1
-1 -1
*/