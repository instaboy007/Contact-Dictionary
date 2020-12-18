#include<iostream>
#include<stdlib.h>
#include<cstring>
#include<string.h>

using namespace std;

class node
{
    public:
        node(char n[] ,char r[] ,char g[]);
        char number[50];
        char gmail[40];
        char name[30];
        node *prev,*next;

        friend class list;
};
node::node(char n[],char r[],char g[])
{
        strcpy(name,n);
        strcpy(number,r);
        strcpy(gmail,g);
        next=NULL;
        prev=NULL;
}
class list
{
    private:
        node *head,*ptr,*temp;
        node *ptr1, *ptr2, *dup;
    public:
        node *prevn;
        list();
        void insert();
        void sort();
        void accept();
        void deletecontact(char s[20]);
        void deletesamenumber();
        void deletesamegmail();
        void searchbyname(char na[20]);
        void searchbynumber(char num[30]);
        void searchbygmail(char gm[20]);
        void display();
        void update(char n[10]);
};
list::list()
{
    head=NULL;
    ptr=NULL;
    temp=NULL;
    ptr1=NULL;
    ptr2=NULL;
    dup=NULL;
}
void list::insert()
{
    char number[50];
    char gmail[40];
    char name[30];
    char ans;
    do
    {
        cout<<"ENTER THE PERSON NAME      :";
        cin>>name;
        cout<<"ENTER HIS NUMBER           :";
        cin>>number;
        while(strlen(number)!=10)
        {
          cout<<"VALID NUMBER PLEASE      :";
          cin>>number;
        }
         cout<<"ENTER HIS G-MAIL           :";
         cin>>gmail;
         temp=new node(name,number,gmail);
        if(head==NULL)
        {
           head=temp;
        }
        else
        {
            ptr=head;
		    while(ptr->next!=NULL)
		    {
                ptr=ptr->next;
		    }
		    ptr->next=temp;
		    temp->prev=ptr;
        }
	    cout<<"DO YOU WANT TO CONTINUE WITH INSERTION(y/n)?????????";
        cin>>ans;
    }while(ans=='y');
}
void list::sort()
{
    node *i,*j;
    int temp;
    char n[10];
    char p[10];
    char g[50];
    for(i=head;i->next!=NULL;i=i->next)
    {
        for(j=i->next;j!=NULL;j=j->next)
        {
            temp=strcmp(i->name,j->name);
            if(temp>0)
            {
               strcpy(n,i->name);
               strcpy(i->name,j->name);
               strcpy(j->name,n);

               strcpy(p,i->number);
               strcpy(i->number,j->number);
               strcpy(j->number,p);

               strcpy(g,i->gmail);
               strcpy(i->gmail,j->gmail);
               strcpy(j->gmail,g);
            }
        }
    }
}
void list::accept()
{
    insert();
}
void list::deletecontact(char s[20])
{
        if(head == NULL)
            cout<<"CONTACT LIST EMPTY"<<endl;
        int f=0;
        ptr=head;
        while(ptr!=NULL)
        {
            if(strcmp(s,ptr->name)==0)
            {
                f=1;
                break;
            }
            else
            {
                f=2;
            }
            ptr=ptr->next;
        }
        if(f==1 && ptr!=head && ptr->next!=NULL)
        {
            ptr->prev->next=ptr->next;
           ptr->next->prev=ptr->prev;
           delete(ptr);
           cout<<"YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
        }
        if(ptr==head)
        {
            head=head->next;
            head->prev=NULL;
            delete(ptr);
           cout<<"YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
        }
        if(ptr->next==NULL)
        {
            ptr->prev->next=NULL;
            ptr->prev=NULL;
            delete(ptr);
           cout<<"YOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
        }
        if(f==2)
        {
            cout<<"YOUR ENTERED NAME IS NOT IN THE LIST...";
        }
}

void list::deletesamenumber()
{
    if(head == NULL)
            cout<<"CONTACT LIST EMPTY"<<endl;
     ptr1=head;
        while(ptr1 != NULL && ptr1->next !=NULL)
        {
            ptr2=ptr1;
            while(ptr2->next != NULL)
            {
                if(strcmp(ptr1->number,ptr2->next->number)==0)
                {
                    dup=ptr2->next;
                    if(ptr2->next->next == NULL)
                    {
                        ptr2->next = NULL;
                        delete(dup);
                    }
                    else
                    {
                        ptr2->next = ptr2->next->next;
                        ptr2 = ptr2->next;
                        ptr2->prev = ptr2->prev->prev;
                        delete(dup);
                    }
                }
                else
                {
                    ptr2 = ptr2->next;
                }
            }
            ptr1 = ptr1->next;
        }    
}
void list::deletesamegmail()
{
    if(head == NULL)
            cout<<"CONTACT LIST EMPTY"<<endl;
     ptr1=head;
        while(ptr1 != NULL && ptr1->next !=NULL)
        {
            ptr2=ptr1;
            while(ptr2->next != NULL)
            {
                if(strcmp(ptr1->gmail,ptr2->next->gmail)==0)
                {
                    dup=ptr2->next;
                    if(ptr2->next->next == NULL)
                    {
                        ptr2->next = NULL;
                        delete(dup);
                    }
                    else
                    {
                        ptr2->next = ptr2->next->next;
                        ptr2 = ptr2->next;
                        ptr2->prev = ptr2->prev->prev;
                        delete(dup);
                    }
                }
                else
                {
                    ptr2 = ptr2->next;
                }
            }
            ptr1 = ptr1->next;
        }    
}
void list::searchbyname(char na[10])
{
    ptr=head;
    while(ptr!=NULL)
    {
        if(strcmp(na,ptr->name)==0)
        {
            cout<<"NAME FOUND"<<endl;
            cout<<"CONTACT DETAILS ARE BELOW:\n"<<endl;
        	cout<<"\n\nNAME  ::\t"<< ptr->name;
			cout<<"\nNUMBER::\t+91-"<< ptr->number;
			cout<<"\nG-MAIL::\t"<< ptr->gmail;        
        }
        ptr=ptr->next;
    }
}
void list::searchbynumber(char num[20])
{
    ptr=head;
    while(ptr!=NULL)
    {
        if(strcmp(num,ptr->number)==0)
        {
            cout<<"NUMBER FOUND\n"<<endl;
            cout<<"CONTACT DETAILS ARE BELOW:\n"<<endl;
        	cout<<"\n\nNAME  ::\t"<< ptr->name;
			cout<<"\nNUMBER::\t+91-"<< ptr->number;
			cout<<"\nG-MAIL::\t"<< ptr->gmail;
		}
            ptr=ptr->next;
    }   
}
void list::searchbygmail(char gm[20])
{
    ptr=head;
    while(ptr!=NULL)
    {
        if(strcmp(gm,ptr->gmail)==0)
        {
            cout<<"G-MAIL FOUND\n"<<endl;
            cout<<"CONTACT DETAILS ARE BELOW:\n"<<endl;
        	cout<<"\n\nNAME  ::\t"<< ptr->name;
			cout<<"\nNUMBER::\t+91-"<< ptr->number;
			cout<<"\nG-MAIL::\t"<< ptr->gmail;
		        
        }
        ptr=ptr->next;
    }
}
void list::display()
{
    ptr=head;//start the node
	while(ptr!=NULL)//traverse till last
	{
			cout<<"\n\nNAME  ::\t"<<ptr->name;
			cout<<"\nNUMBER::\t+91-"<<ptr->number;
			cout<<"\nG-MAIL::\t"<<ptr->gmail;
			ptr=ptr->next;
	}
}
void list::update(char n[20])
{
    char ans;
    int c;
    ptr=head;
    while(ptr!=NULL)
    {
        if(strcmp(n,ptr->name)==0)
        {        
            do
            {
                cout<<"\nWHAT DO YOU WANT TO UPDATE?\n1.NAME\n2.PHONE NUMBER\n3.G-MAIL\n";
                cin>>c;
                switch(c)
                {
                    case 1:
                        cout<<"ENTER NEW-NAME=";
                        cin>>ptr->name;
                        break;

                    case 2:
                        cout<<"ENTER NEW PHONE-NUMBER?";
                        cin>>ptr->number;
                        while(strlen(ptr->number)!=10)
                        {
                            cout<<"ENTER VALID NUMBER  :";
                            cin>>ptr->number;
                        }
                        break;

                    case 3:
                        cout<<"ENTER NEW G-MAIL";
                        cin>>ptr->gmail;
                        break;
                }
                cout<<"DO YOU WANT TO CONTINUE UPDATING(y/n)?";
                cin>>ans;
            }while(ans=='y');
        }
            ptr=ptr->next;
    }
}

class BST
{
    public:
        string word;
        string meaning;
        BST *left,*right;

}*root=NULL;

BST *Newnode(string word,string meaning)
{
    BST *newnode;
    newnode=new BST[sizeof(BST)];
    newnode->word=word;
    newnode->meaning=meaning;
    newnode->left=newnode->right=NULL;
    return newnode;
}

void insert(string word,string meaning)
{
    BST *parent=NULL,*current=NULL,*newnode=NULL;
    int check=0;
    if(!root)
    {
        root = Newnode(word,meaning);
        return;
    }
    for(current = root ; current!=NULL ; current= (check > 0) ? current->right : current->left)
    {
        check=strcasecmp(word.c_str(),current->word.c_str());
        if(check == 0)
        {
            cout<<"THE WORD IS ALREADY PRESENT!"<<endl;
            return;
        }
        parent=current;
    }
    newnode = Newnode(word,meaning);
    check > 0 ? (parent->right=newnode) : (parent->left=newnode);
    return;
}

void Delete(string word)
{
    BST *parent=NULL,*current=NULL,*node=NULL;
    int flag=0,check=0;
    if(!root)
    {
        cout<<"\nNO WORD PRESENT TO DELETE!"<<endl;
        return;
    }
    current=root;
    while(1)
    {
        check = strcasecmp(current->word.c_str(),word.c_str());
        if(check == 0)
            break;
        flag = check;
        parent = current;
        current = (check > 0) ? current->left : current->right;
        if (current == NULL)
            return;
    }
    //DELETING LEAF NODE
    if(current->right == NULL)
    {
        if (current == root && current->left == NULL) 
        {
            current=NULL;
            root = NULL;
            return;
        } 
        else if (current == root)
        {
            root = current->left;
            current=NULL;
            return;
        }
        flag > 0 ? (parent->left = current->left) :(parent->right = current->left);
    }
    else
    {
        node=current->right;
        //DELETING NODE WITH SINGLE CHILD
        if(!node->left)
        {
            node->left=current->left;
            if(current == root)
            {
                root = node;
                current=NULL;
                return;
            }
            flag > 0 ? ( parent->left = node ) : ( parent->right = node );
        }
        //DELETING NODE WITH TWO CHILD
        else
        {
            BST *next=NULL;
            while(1) 
            {
                next=node->left;
                if(!next->left)
                    break;
                node=next;
            }
            node->left=next->right;
            next->left=current->left;
            next->right=current->right;
            if(current == root)
            {
                root=next;
                current=NULL;
                return;
            }
            (flag > 0) ? (parent->left = next) :( parent->right = next );
        }         
    }
    current=NULL;
    return;
}

void Search(string word)
{
    BST *node=NULL;
    int flag=0,check=0;
    if(root==NULL)
    {
        cout<<"\nNO WORDS ARE PRESENT !"<<endl;
        return;
    }
    node=root;
    while(node)
    {  
        if((check = strcasecmp(node->word.c_str(),word.c_str())) == 0)
        {
            cout<<"\nWORD IS PRESENT!"<<endl;
            cout<<"WORD : "<<word<<endl;
            cout<<"MEANING : "<<node->meaning<<endl;
            flag=1;
            break;
        }
        node = (check>0) ? node->left : node->right;
    }
    if(flag==0)
    {
        cout<<"\nWORD NOT FOUND!"<<endl;
    }
    return;
}

void Traverse(BST *node)
{
    if(node)
    {
        Traverse(node->left);
        cout<<"\nWORD : "<<node->word;
        cout<<"\nMEANING : "<<node->meaning<<"\n";
        Traverse(node->right);
    }
    return;
}

int main()
{
    int option;
    do
    {
        cout<<"\n1.)PHONE BOOK\n2.)DICTIONARY\n3.)EXIT\nENTER YOUR CHOICE ==> ";
        cin>>option;
        if(option==1)
        {
            char n[20];
            char nam[20];
            char name[10];
            char number[10];
            char gmail[20];
            list l1;
            char ans;
            int ch,a;
            cin.ignore();
            cout<<"######   PHONE BOOK   ######";
            cout<<"\n\nWHAT IS YOUR NAME?\n";
            cin.getline(name,20);
            cout<<"\n\n!!!!!!   WELCOME "<< name <<"   !!!!!!!!!!!";
            cout<<"\n\n\n CREATE YOUR PHONEBOOK "<<name<<"  \n\n";
            l1.accept();
            l1.sort();
            do
            {
                cout<<"\n\n\n\n1) DISPLAY YOUR PHONE BOOK\n2) INSERT NEW CONTACT\n3) UPDATE DETAILS ON EXISTING CONTACT\n4) DELETE CONTACT\n5) DELETE SAME NUMBERS\n 6) DELETE SAME GMAIL\n7) SEARCH\n PRESS ANY KEY FOR EXIT\n ENTER YOUR CHOICE==>";
                cin>>ch;
                switch(ch)
                {
                    case 1:
                        // l1.sort();
                        l1.display();
                        break;
                    case 2:
                        l1.insert();
                        l1.sort();
                        break;
                    case 3:
                        cout<<"\n\nENTER THE NAME OF PERSON WHOSE DETAILS YOU WANT TO UPDATE...\n";
                        cin>>n;
                        l1.update(n);
                        l1.sort();
                        break;
                    case 4:
                        cout<<"\nENTER THE NAME YOU WANT TO DELETE FROM PHONEBOOK\n";
                        cin>>name;
                        l1.deletecontact(name);
                        break;
                    case 5:
                        l1.deletesamenumber();
                        l1.display();
                        break;
                    case 6:
                        l1.deletesamegmail();
                        l1.display();
                        break;
                    case 7:
                        do
                        {
                            cout<<"1.SEARCH BY NAME\n2.SEARCH BY NUMBER\n3.SEARCH BY GMAIL";
                            cin>>a;
                            switch(a)
                            {
                                case 1:
                                    cout<<"ENTER THE NAME TO BE SEARCHED\n";
                                    cin>>name;
                                    l1.searchbyname(name);
                                    break;
                                case 2:
                                    cout<<"ENTER THE NUMBER TO BE SEARCHED\n";
                                    cin>>number;
                                    l1.searchbynumber(number);
                                    break;
                                case 3:
                                    cout<<"ENTER THE MAIL TO BE SEARCHED\n";
                                    cin>>gmail;
                                    l1.searchbygmail(gmail);
                                    break;
                                default:cout<<"\nNO PROPER INPUT GIVEN.....\n";
                            }
                            cout<<"DO YOU WANT TO CONTINUE SEARCHING(y/n)?????????";
                            cin>>ans;
                        }while(ans=='y');
                        break;
                        default:cout<<"\nNO PROPER INPUT GIVEN..\n";
                        exit(0);
                    }
                    cout<<"\n\nDO YOU WANT TO CONTINUE WITH ABOVE OPERATIONS(y/n)?????????";
                    cin>>ans;
                }while(ans=='y');
        }
        else if(option==2)
        {
            int choice;
            do
            {
                string word,meaning;
                cout<<"\n1.)INSERT\n2.)DELETE\n3.)SEARCH\n4.)DISPLAY\n5.)EXIT\nENTER YOUR CHOICE==> ";
                cin>>choice;
                switch(choice)
                {
                    case 1:
                        cin.ignore();
                        cout<<"\nENTER THE WORD TO INSERT : ";
                        getline(cin,word);
                        cout<<"\nENTER THE MEANING : ";
                        getline(cin,meaning);
                        insert(word,meaning);
                        break;
                    case 2:
                        cin.ignore();
                        cout<<"\nENTER THE WORD TO DELETE :";
                        getline(cin,word);
                        Delete(word);
                        break;
                    case 3:
                        cin.ignore();
                        cout<<"\nENTER THE WORD TO SEARCH : ";
                        getline(cin,word);
                        Search(word);
                        break;
                    case 4:
                        Traverse(root);
                        break;
                }
            } while (choice<5);
        } 
    }while(option<=2);
}