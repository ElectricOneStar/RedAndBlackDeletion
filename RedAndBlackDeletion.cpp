/*
RedAndBlackTree Insertion By Andrew Thomas 4/12/20 Mr.Galbriath C++ Class. Red And Black Tree. This will correctly build a red and black tree and will properally add nodes to the tree. one can also search for a value on the tree. 
Sources:
https://en.wikipedia.org/wiki/Red%E2%80%93black_tree
https://www.andrew.cmu.edu/user/mm6/95-771/examples/RedBlackTreeProject/dist/javadoc/redblacktreeproject/RedBlackTree.html
 
*/
#include <iostream>
//#include <cstdlib>


#include<cstring>
#include<fstream>
#include "Node.h"
using namespace std; // functions below
int* Parce(char* input, int* index, int* counterOne, int* wordCounter, int* parced); // functions

void BuildTree(char* input, int* index, int* counterOne, int* wordCounter, int* parced, int* size, Node* header);
//void Add(Node* header, Node* add);
//void Subtract();
//void Subtract(Node* header, int* deleteThis, Node* previous, int* DCounter, int* skip, int* special);
void Print(Node* header, int length, int count, int i);
//void Search();
void Search(Node* header, int* searchData, bool* exists);
void maxSize(char* input, int* size);
Node* getRightMost(Node* header);
void rotateLeft(Node *&header, Node *&pointer);
void rotateRight(Node *&header, Node *&pointer);
void fixViolation(Node* &header, Node* &pointer);
void balance(Node* &head, Node* &curr);
void balance2(Node* &head, Node* &curr);
void add (Node** root, Node* parentNode, int* NUMBER);
void fixIssue(Node** header, Node* nnew);
void leftRotate(Node** header, Node* next);
void rightRotate(Node** header, Node* temporary);
void setGrandparent(Node* n);
Node* getGrandparent(Node* n);
void add (Node** header, Node* parent, int* in);
void ReplaceNode(Node* n, Node* child);
void DeleteOneChild(Node* n, Node* header);
void DeleteCase1(Node* n);
void DeleteCase2(Node* n);
void DeleteCase3(Node* n);
void DeleteCase4(Node* n);
void DeleteCase5(Node* n);
void DeleteCase6(Node* n);
Node* GetSibling(Node* n);
void RotateRight2(Node* n);
//Node* GetSibling(Node* n);
  void RotateLeft2(Node* n);
Node* SearchReturn2(Node* header, int* searchData);
//Node SearchReturn(Node header, int* searchData);
void SearchReturn(Node header, int* searchData, Node* deleteNode);
void ACase1(Node* header, int*  DeleteValue, int* ADeleteValue);
int main(){ // initialization of variables
  //HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  //SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
  char* inputType = new char[20]; // initializing variables
  char* input = new char[500];
  char* FileName = new char[20];
  char* inputFunction = new char[20];
  bool quit = false;
  int* index = new int;
  int* parced = new int;
  int* counterOne = new int;
  (*counterOne) = 0;
  int* wordCounter = new int;
  (*wordCounter) = 0;
  int* size = new int;
  Node* header = new Node;
  (*size) = 1;
  char* additionInput = new char[20];
  bool* exists = new bool;
  (*exists) = false;
  // Node* one = new Node;
  //(*one).setData(Parce(input, index, counterOne, wordCounter, parced));
  char* searchInput = new char[20];
  char* subtractInput = new char[20];
  Node* previous = new Node;
  int* DCounter = new int;
  (*DCounter) = 0;
  int* skip = new int;
  (*skip) = 0;
  int* special = new int;
  Node* Parent = new Node;
  Node* Uncle = new Node;
  Node* GrandParent = new Node;
  int* deleteValue = new int;
  /*
  int* ones = new int;
  int* twos = new int;
  int* threes = new int;
  */
(*index) = 1;
  do{
  cout << "Welcome to Red and Black Tree Please Select your Input: User or File" << endl;
  cin.get(inputType, 20); // will continue to ask for type of input
  cin.clear();
  cin.ignore();
  }
  while(strcmp(inputType, "User") != 0 && strcmp(inputType, "File") != 0);
  if(strcmp(inputType, "User") == 0){ // USER INPUT
    cout << "Please Enter a series of number separated by spaces. Up to 100 numbers should be stored" << endl;
    cin.get(input, 500); // gets the user input
    cin.ignore();
      cin.clear();
      //cout << "Input: " << input << endl;
  }
  else if(strcmp(inputType, "File") == 0){ // FILE INPUT
    cout << "Please Enter the name of the file" << endl;
    cin.get(FileName, 500); // gets the file name
    cin.ignore();
      cin.clear();
      ifstream rfile;
      rfile.open(FileName);
      rfile.getline(input, 500); // gets input from file
      //cout << "Input: " << input << endl;
  }
  maxSize( input, size); // gets size of tree
  //cout << "First Number: " << (*Parce(input, index, counterOne, wordCounter, parced)) << endl;
  BuildTree(input, index, counterOne, wordCounter, parced, size, header); // builds the tree
  do{
    //   Node* one = new Node;
    //  (*one).setData(Parce(input, index, counterOne, wordCounter, parced)); // creates the new node
    // cout << (*Parce(input, index, counterOne, wordCounter, parced)) << endl;
    int* data = new int;
    (*data) = (*Parce(input, index, counterOne, wordCounter, parced));
    //  cout << (*data) << endl;
    //add(&header, header, data); // adds a new node to the tree

    add(&header, header, data);
    //cout << (*data) << endl;
    //(*one).setColor(BLACK);
    //cout << "data" << (*(*one).getData()) << endl;
    // Add(header, one); // adds the new node

    // fixViolation(header, one);
    (*index)++;
  }
  while((*index) != (*size)+1); // continues to do this until all the numbers from i
  do{
  cout << "The RedAndBlack is now created. you can ADD, DELETE, SEARCH, or PRINT from the tree. You can also type QUIT if you want to quit the program" << endl; 
  cin.get(inputFunction, 20); // gets the function that the users want to do
  //cin.ignore();
  cin.clear();
    cin.ignore();
    if(strcmp(inputFunction, "ADD") == 0){ //add function that adds a node to the tree
    // cout << "add" << endl;
    cout << "Please enter the 3 digit value that you want to add to the tree" << endl;
    cin.get(additionInput, 20);
    cin.clear();
    cin.ignore();
    int* lol = new int;
    ///(*counterOne) = 0;
    (*index) = 1;
    (*wordCounter) = 0;
      for(int i = 0; i < strlen(additionInput); i++){
    if(additionInput[i] != ' ' && (*wordCounter) != 3){ // add to integer up to 3 digits
      (*wordCounter)++;
	if((*wordCounter) == 1){
	  (*lol) = (int)additionInput[i]-48;
	}
      	if((*wordCounter) == 2){
	  (*lol) = (int)additionInput[i]-48 + (*lol)*10;
	}
	if((*wordCounter) == 3){
	  (*lol) = (int)additionInput[i]-48 + (*lol)*10;
	}

      
    }
      }
    //  (*lol) = (*Parce(input, index, counterOne, wordCounter, parced));
    //(*lol) = (int)(*additionInput) - 48;
    //cout << (*lol) << endl;
    //Parce(input, index, counterOne, wordCounter, parced);
      //   Node* two = new Node; // creates the new node
    //(*two).setData(Parce(additionInput, index, counterOne, wordCounter, parced));
    //cout << "added data" << (*(*two).getData()) << endl;
    //Node*
    add(&header, header, lol); // adds to the tree
    cout << "Added" << endl;
  }
    if(strcmp(inputFunction, "DELETE") == 0){ // delete function that deletes a node form tree
      cout << "please enter the value of the node that you want to delete" << endl;
      cin >> (*deleteValue);
      // cin.get(deleteValue, 20);
      // cin.ignore();
      //cin.clear();

      cout << "herez" << endl;
      //cout << (*SearchReturn((*header), deleteValue).getData()) << endl;
      Node* deleteNode = new Node;
      SearchReturn((*header), deleteValue, deleteNode);
      cout << (*(*deleteNode).getData()) << endl;
      // cout << (*(*(*deleteNode).getRight()).getData()) << endl;
      cout << "here" << endl;
      // DeleteOneChild(SearchReturn(header, deleteValue));
      DeleteOneChild(deleteNode, header);
      //  DeleteOneChild((*header).getRight(), header);
      cout << "deleted" << endl;
    }

    if(strcmp(inputFunction, "SEARCH") == 0){ // function that searches the binary tree and checks if a node exists or not
	//cout << "search" << endl;
	//int Length = (*size);
	cout << "Please enter the 3 digit number that you want to search for in the tree" << endl;
	cin.get(searchInput, 20); // what node should I search for
	cin.clear();
	cin.ignore();
	Search(header, Parce(searchInput, index, counterOne, wordCounter, parced), exists);
	if((*exists) == true){ // it exists
	  cout << (*Parce(searchInput, index, counterOne, wordCounter, parced)) << " exists in the tree" << endl;
	  //cout << "deleted" << endl;
	}
	if((*exists) == false){ // it does not exist
	  cout << (*Parce(searchInput, index, counterOne, wordCounter, parced)) << " Does not exist in the tree" << endl;
	}
	(*exists) = false;
      }
      if(strcmp(inputFunction, "PRINT") == 0){ // function that prints the tree in a way that clearly demonstrates the parent and child relationship
	  //  cout << "print" << endl;
	  int Length = (*size);
	  if(header == NULL){
	    cout << "tree is empty" << endl;
	  }
	  else{
	  Print(header, Length, 0, 1);
	  }
	  }
	if(strcmp(inputFunction, "QUIT") == 0){ // quit the program
	  quit = true;
	}
	//if(strcmp(inputFunction, "ADD") == 0){
	//  cout << "add" << endl;
	//  }

  }

  while(strcmp(inputFunction, "ADD") != 0 && strcmp(inputFunction, "SUBTRACT") != 0 && strcmp(inputFunction, "SEARCH") != 0 && strcmp(inputFunction, "PRINT") != 0 && strcmp(inputFunction, "QUIT") != 0 || quit == false); 
}
int* Parce(char* input, int* index, int* counterOne, int* wordCounter, int* parced){ // this function pareces the input
  //cout << "parce" << endl;
  for(int i = 0; i < strlen(input); i++){
    if(input[i] != ' ' && (*wordCounter) != 3){ // add to integer up to 3 digits
      (*wordCounter)++;
	if((*wordCounter) == 1){
	  (*parced) = (int)input[i]-48;
	}
      	if((*wordCounter) == 2){
	  (*parced) = (int)input[i]-48 + (*parced)*10;
	}
	if((*wordCounter) == 3){
	  (*parced) = (int)input[i]-48 + (*parced)*10;
	}

      
    }
    if(input[i] == ' '){ // there is a space
      (*wordCounter) = 0;
      (*counterOne)++;
    }
    if((*counterOne) == (*index) || input[i+1] == '\0'){ // I want this number pareced
      (*wordCounter) = 0;
      (*counterOne) = 0;
      return parced; // returns parced integer
    }
  }
  //return index;
}
void BuildTree(char* input, int* index, int* counterOne, int* wordCounter, int* parced, int* size, Node* header){ // this builds the tree
  //Node* one = new Node;
      // (*one).setData(Parce(input, index, counterOne, wordCounter, parced));

  // cout << "build tree" << endl;
  // cout << (*size) << endl;
  // Node* header = new Node;
  
  int* RED = new int;
  (*RED) = 0;
  int* BLACK = new int;
  (*BLACK) = 1;
  int* dat = new int;
  (*dat) = (*Parce(input, index, counterOne, wordCounter, parced));
  (*header).setData(dat); // creates the head
  //cout << (*dat) << endl;
  // cout << (*Parce(input, index, counterOne, wordCounter, parced)) << endl;
  (*header).setColor((*BLACK));
 
(*index)++; 
  //cout << "head data" << (*(*header).getData()) << endl;
/*
 do{
    //   Node* one = new Node;
    //  (*one).setData(Parce(input, index, counterOne, wordCounter, parced)); // creates the new node
    // cout << (*Parce(input, index, counterOne, wordCounter, parced)) << endl;
    int* data = new int;
    (*data) = (*Parce(input, index, counterOne, wordCounter, parced));
    cout << (*data) << endl;
    //add(&header, header, data); // adds a new node to the tree
    add(&header, header, data);
    //cout << (*data) << endl;
    //(*one).setColor(BLACK);
    //cout << "data" << (*(*one).getData()) << endl;
    // Add(header, one); // adds the new node
    // fixViolation(header, one);
    (*index)++;
  }
  while((*index) != (*size)+1);
*/
  // continues to do this until all the numbers from input are put into the tree
}
void Print(Node* header, int length, int count, int i){ // this funciton prints the tree where the parent and child relationship is clear
  //cout << "print" << endl;
   int left = 2*i;
  int right = 2*i+1;
  // if(right <= length && (*header).getRight() != NULL){ // right child exist so recurse
      if((*header).getRight() != NULL){ // right child exist so recurse
    Print((*header).getRight(), length, count+1, right);
  }
  int current = count;
  while(count > 0){ // add spaces
    cout << "    ";
    count--;
  }
  //textcolor(RED);
  //system("Color 7C");
  if((*header).getColor() == 0){
    cout << (*(*header).getData()) << "R" << endl;
  }
  else{
    cout << (*(*header).getData()) << "B" << endl;
  }
  //cout << sortedHeap[i-1 << endl; // print current with some number of idenetation
  // if(left <= length && (*header).getLeft() != NULL){ // left child exists so recurse
      if((*header).getLeft() != NULL){ // left child exists so recurse
    Print((*header).getLeft(), length, current + 1, left);
  }
}


void Search(Node* header, int* searchData, bool* exists){ // this function searches the tree for a node
  //cout << "search" << endl;
  if((*(*header).getData()) == (*searchData)){ // THIS IS THE NODE
	 (*exists) = true;
       }

  if((*header).getRight() != NULL && (*searchData) > (*(*header).getData())){ // not the node search rihgt
	 Search((*header).getRight(), searchData, exists);
       }
  /*
  if((*(*header).getData()) == (*searchData)){
	 (*exists) = true;
       }
  */
  if((*header).getLeft() != NULL && (*searchData) <= (*(*header).getData())){ // not the node so search left
	 Search((*header).getLeft(), searchData, exists);
       }
}
void maxSize(char* input, int* size){ // this function gets the size of the tree
  for(int i = 0; i < strlen(input); i++){
    if(input[i] == ' '){ // every time there is a space there should be a new node
      (*size)++;
    }
  }
}
void setGrandparent(Node* n){ // sets the grandparent
  (*(*n).getParent()).setParent(n);
}
//getting the grandparent
Node* getGrandparent(Node* n){ // gets the grandparent
  return (*(*n).getParent()).getParent();
} 
void rightRotate(Node** header, Node* temporary){ // rotates right
  Node* nextNode = temporary -> getLeft(); // next node is left of temp
   (*temporary).setLeft((*nextNode).getRight());
   if((*nextNode).getRight() != NULL){
     (*(*nextNode).getRight()).setParent(temporary); // next nodes right new parent is temp
       }
   (*nextNode).setParent((*temporary).getParent()); // nextnodes parent is temp
   if(temporary == (*header)){ // if header
     (*header) = nextNode; // header is now next node
  }
   else{ // temp is not header
     if(temporary == (*(*temporary).getParent()).getLeft()){ // temp is left
       (*(*temporary).getParent()).setLeft(nextNode); // temps parents new left is newnode
                 }
     else if (temporary != (*(*temporary).getParent()).getLeft()){ // temp is right
       (*(*temporary).getParent()).setRight(nextNode); // temps parents new right is new node
		  }
       }
   nextNode -> setRight(temporary); // new nodes right is temp
   temporary -> setParent(nextNode); // temp parent is next node
}
 
void leftRotate(Node** header, Node* next){ // rotates left
  Node* current = (*next).getRight();  // current is next's right
  (*next).setRight((*current).getLeft()); //next new right is currents left
  if((*current).getLeft() != NULL){
    (*(*current).getLeft()).setParent(next);  // current left's parent is now next
   }
  (*current).setParent((*next).getParent()); // current's parent is next's parent
   if(next == *header){
         *header = current; //The new header is now the current
       }
   else{
     if(next == (*(*next).getParent()).getLeft()){ // next is left
       (*(*next).getParent()).setLeft(current); /// next's parents left is now current
         }
         else{
           (*(*next).getParent()).setRight(current); // next is right and current is now right
         }
   }
   (*current).setLeft(next); // currents left is next
   (*next).setParent(current); // nexts parent is current
}
void fixIssue(Node** header, Node* nnew){ // fixes the tree after adding the node
  while((*nnew).getParent() != NULL && (*(*nnew).getParent()).getColor() == 0 && nnew != (*header)){ // while nnew has a parent
    if((*nnew).getParent() == (*getGrandparent(nnew)).getLeft()){ // if new's parent is nnew's left
      Node* next = (*getGrandparent(nnew)).getRight(); // set next to the right of new's grandparent
      if(next != NULL && (*next).getColor() == 0){ // next is not null
	(*(*nnew).getParent()).setColor(1); // set parent color to 1
	(*next).setColor(1); // next color is 1
	      (*getGrandparent(nnew)).setColor(0); // sets parents color to 0
	      nnew = getGrandparent(nnew); // recurse with grandparent
           }
           else{
	     if(nnew == (*(*nnew).getParent()).getRight()){ // if neew is on right
	       nnew = (*nnew).getParent(); // nnew is now its parent
	       leftRotate(header, nnew); // left rotate
                    }
	     (*(*nnew).getParent()).setColor(1); // set nnew parent color 1
	     (*getGrandparent(nnew)).setColor(0);  // grandparents color 0
	     rightRotate(header, getGrandparent(nnew)); // right roate
                   }
           }
    else{// nnew is left
      if ((*getGrandparent(nnew)).getLeft() != NULL && (*(*getGrandparent(nnew)).getLeft()).getColor() == 0){ // grandparents left exists
               Node* in = new Node();
	       in = (*getGrandparent(nnew)).getLeft(); // in is grandparents left
               (*(*nnew).getParent()).setColor(1); //nnew parents color is now 1
	       (*in).setColor(1); // in color is 1
	       (*getGrandparent(nnew)).setColor(0); //setting colors
               nnew = getGrandparent(nnew); // nnew is now grandparent
           }
      else{ //grandparents left does not exist
	     if (nnew == (*(*nnew).getParent()).getLeft()){
		 nnew = (*nnew).getParent();
		 rightRotate(header, nnew); // right roatate
               }
               (*(*nnew).getParent()).setColor(1);
	       (*getGrandparent(nnew)).setColor(0);
	       leftRotate(header, getGrandparent(nnew)); // left rotate
           }
        }
    }
    (*(*header)).setColor(1);
}
void add (Node** header, Node* parent, int* in){
  if ((*(*parent).getData()) == 0){ // add to header
       (*parent).setColor(1);
	(*parent).setData(in);
     }
     else{
       if((*in) <= (*(*parent).getData())){ // smaller data
	 if ((*parent).getLeft() == NULL){ // end of list
	    Node* newNode = new Node(); // add node
               (*newNode).setData(in);
               (*newNode).setParent(parent);
               (*parent).setLeft(newNode);
               fixIssue(header, newNode);
           }           
	 else{ // not end so recurse
      add(header, (*parent).getLeft(), in);
           }
       }
       else { // greater 
	 if ((*parent).getRight() == NULL){ // end of list 
           Node* newNode = new Node(); // add node
           (*newNode).setData(in);
           (*newNode).setParent(parent);
           (*parent).setRight(newNode);
           fixIssue(header, newNode);
       }
         else{ // not end so recurse
           add(header, (*parent).getRight(), in);
        }
  }
     }
   }
void ReplaceNode(Node* n, Node* child) {
  (*child).setParent((*n).getParent());
  if (n == (*(*n).getParent()).getLeft()) {
    (*(*n).getParent()).setLeft(child);
  } else {
    (*(*n).getParent()).setRight(child);
  }
}

void DeleteOneChild(Node* n, Node* header) {
  // Precondition: n has at most one non-leaf child.
  cout << "lolz" << endl;
   Node* child = ((*n).getRight() == nullptr) ? (*n).getLeft() : (*n).getRight();
  // Node* child = (*n).getRight();
  //Node* child = (*n).getRight();
  // assert(child);
   
   if((*n).getLeft() == NULL && (*n).getRight() == NULL){
     /*    if((*(*getGrandparent(n)).getData()) <= (*(*(*n).getParent()).getData())){
       cout << "wow" << endl;
       (*getGrandparent(n)).setLeft(NULL);
     }
     else{
     (*getGrandparent(n)).setLeft(NULL);
     cout << "wow2" << endl;
     }
     */
     /* 
     cout << "wow1" << endl;
     Node* nn = new Node;
     SearchReturn((*header),  (*(*n).getParent()).getData(), nn);
     //void SearchReturn(Node header, int* searchData, Node* deleteNode)
     cout << (*(*nn).getData()) << endl;
     (*nn).setLeft(NULL);
   (*nn).setRight(NULL);
   cout << "wow2" << endl;
*/
     /*
     cout << "wowx" << endl;
     (*SearchReturn2( header, (*(*n).getParent()).getData())).setLeft(NULL);
     (*SearchReturn2( header, (*(*n).getParent()).getData())).setRight(NULL);
     cout << "wowz" << endl;
     */
     //cout << (*(*(*(*header).getRight()).getRight()).getData()) << endl;
     //(*(*header).getRight()).setRight(NULL);
     //return;
     ACase1( header,  (*(*n).getParent()).getData(), (*n).getData());
 (*n).setParent(NULL);
 return;
   }
   
   cout << "herezz" << endl;
  ReplaceNode(n, child);
  cout << "here";
  if ((*n).getColor() == 1) {
    cout << "there" << endl;
    if ((*child).getColor() == 0) {
      cout << "DN1" << endl;
      (*child).setColor(1);
    } else {
      cout << "D1";
      DeleteCase1(child);

    }
  }
  cout << "lol" << endl;
  //temp
  // (*child).setLeft((*n).getRight());
  free(n);
}
void DeleteCase1(Node* n) {
  cout << "1";
  if ((*n).getParent() != nullptr) {
    DeleteCase2(n);
  }
}
void DeleteCase2(Node* n) {
  cout << "2";
  Node* s = GetSibling(n);

  if ((*s).getColor() == 0) {
    (*(*n).getParent()).setColor(0);
    (*s).setColor(1);
    if (n == (*(*n).getParent()).getLeft()) {
      RotateLeft2((*n).getParent());
    } else {
      RotateRight2((*n).getParent());
    }
  }
  DeleteCase3(n);
}
void DeleteCase3(Node* n) {
  cout << "3";
  Node* s = GetSibling(n);

  if (((*(*n).getParent()).getColor() == 1) && ((*s).getColor() == 1) &&
      ((*(*s).getLeft()).getColor() == 1) && ((*(*s).getRight()).getColor() == 1)) {
    (*s).setColor(0);
    DeleteCase1((*n).getParent());
  } else {
    DeleteCase4(n);
  }
}
void DeleteCase4(Node* n) {
cout << "4";
  Node* s = GetSibling(n);
  
  if (((*(*n).getParent()).getColor() == 0) && ((*s).getColor() == 1) &&
      ((*(*s).getLeft()).getColor() == 1) && ((*(*s).getRight()).getColor() == 1)) {
    (*s).setColor(0);
    (*(*n).getParent()).setColor(1);
  } else {
    DeleteCase5(n);
  }
}
void DeleteCase5(Node* n) {
cout << "5";
  Node* s = GetSibling(n);

  // This if statement is trivial, due to case 2 (even though case 2 changed
  // the sibling to a sibling's child, the sibling's child can't be red, since
  // no red parent can have a red child).
 if ((*s).getColor() == 1) {
    // The following statements just force the red to be on the left of the
    // left of the parent, or right of the right, so case six will rotate
    // correctly.
   if ((n == (*(*n).getParent()).getLeft()) && ((*(*s).getRight()).getColor() == 1) &&
       ((*(*s).getLeft()).getColor() == 0)) {
      // This last test is trivial too due to cases 2-4.
     (*s).setColor(0);
     (*(*s).getLeft()).setColor(1);
      RotateRight2(s);
   } else if ((n == (*(*n).getParent()).getRight()) && ((*(*s).getLeft()).getColor() == 1) &&
	      ((*(*s).getRight()).getColor() == 0)) {
      // This last test is trivial too due to cases 2-4.
     (*s).setColor(0);
     (*(*s).getRight()).setColor(1);
     RotateLeft2(s);
    }
  }
  DeleteCase6(n);
}
void DeleteCase6(Node* n) {
  cout << "6";
  Node* s = GetSibling(n);

  (*s).setColor((*(*n).getParent()).getColor());
  (*(*n).getParent()).setColor(1);

  if (n == (*(*n).getParent()).getLeft()) {
    (*(*s).getRight()).setColor(1);
        RotateLeft2((*n).getParent());
  } else {
    (*(*s).getLeft()).setColor(1);
        RotateRight2((*n).getParent());
  }
}

Node* GetSibling(Node* n) {
  Node* p = (*n).getParent();

  // No parent means no sibling.
  if (p == nullptr) {
    return nullptr;
  }

  if (n == (*p).getLeft()) {
    return (*p).getRight();
  } else {
    return (*p).getLeft();
  }
}

void RotateLeft2(Node* n) {
  Node* nnew = (*n).getRight();
  Node* p = (*n).getParent();
  // assert(nnew != nullptr);  // Since the leaves of a red-black tree are empty,
                            // they cannot become internal nodes.
  (*n).setRight((*nnew).getLeft());
  (*nnew).setLeft(n);
  (*n).setParent(nnew);
  // Handle other child/parent pointers.
  if ((*n).getRight() != nullptr) {
    (*(*n).getRight()).setParent(n);
  }

  // Initially n could be the root.
  if (p != nullptr) {
    if (n == (*p).getLeft()) {
      (*p).setLeft(nnew);
    } else if (n == (*p).getRight()) {
      (*p).setRight(nnew);
    }
  }
  (*nnew).setParent(p);
}

void RotateRight2(Node* n) {
  Node* nnew = (*n).getLeft();
  Node* p = (*n).getParent();
  //assert(nnew != nullptr);  // Since the leaves of a red-black tree are empty,
                            // they cannot become internal nodes.

  (*n).setLeft((*nnew).getRight());
  (*nnew).setRight(n);
  (*n).setParent(nnew);

  // Handle other child/parent pointers.
  if ((*n).getLeft() != nullptr) {
    (*(*n).getLeft()).setParent(n);
  }

  // Initially n could be the root.
  if (p != nullptr) {
    if (n == (*p).getLeft()) {
      (*p).setLeft(nnew);
    } else if (n == (*p).getRight()) {
      (*p).setRight(nnew);
    }
  }
  (*nnew).setParent(p);
}


void SearchReturn(Node header, int* searchData, Node* deleteNode){ // this function searches the tree for a node
  //cout << "search" << endl;
  if((*header.getData()) == (*searchData)){ // THIS IS THE NODE
    //cout << "return this" << (*header.getData()) << endl;
    //   Node* replace = new Node;
    //return header;
    (*deleteNode) = header;
    // return replace;
    //(*exists) = true;
       }

  if(header.getRight() != NULL && (*searchData) > (*header.getData())){ // not the node search rihgt
    SearchReturn((*header.getRight()), searchData, deleteNode);
       }
  //if((*(*header).getData()) == (*searchData)){
      //(*exists) = true;
  //   }
    if(header.getLeft() != NULL && (*searchData) <= (*header.getData())){ // not the node so search left
      SearchReturn((*header.getLeft()), searchData, deleteNode);
       }
}

Node* SearchReturn2(Node* header, int* searchData){ // this function searches the tree for a node
  //cout << "search" << endl;
  if((*(*header).getData()) == (*searchData)){ // THIS IS THE NODE
    //cout << "return this" << (*header.getData()) << endl;
    //   Node* replace = new Node;
    //return header;
    // (*deleteNode) = header;
    return header;
    // return replace;
    //(*exists) = true;
       }

  if((*header).getRight() != NULL && (*searchData) > (*(*header).getData())){ // not the node search rihgt
    SearchReturn2((*header).getRight(), searchData);
       }
  //if((*(*header).getData()) == (*searchData)){
      //(*exists) = true;
  //   }
  if((*header).getLeft() != NULL && (*searchData) <= (*(*header).getData())){ // not the node so search left
    SearchReturn2((*header).getLeft(), searchData);
       }
}
/*
void SearchReturnParent(Node header, int* searchData, Node* deleteNode){ // this function searches the tree for a node
  //cout << "search" << endl;
  if((*header.getData()) == (*searchData)){ // THIS IS THE NODE
    //cout << "return this" << (*header.getData()) << endl;
    //   Node* replace = new Node;
    //return header;
    (*deleteNode) = header;
    // return replace;
    //(*exists) = true;
       }

  if(header.getRight() != NULL && (*searchData) > (*header.getData())){ // not the node search rihgt
    SearchReturn((*header.getRight()), searchData, deleteNode);
       }
  //if((*(*header).getData()) == (*searchData)){
      //(*exists) = true;
  //   }
    if(header.getLeft() != NULL && (*searchData) <= (*header.getData())){ // not the node so search left
      SearchReturn((*header.getLeft()), searchData, deleteNode);
       }
}

/*						\
&&
      ((*(*s).getLeft()).getColor() == 1) && ((*(*s).getRight()).getCo\
lor() == 1)) {
    (*s).setColor(0);
    (*(*n).getParent()).setColor(1);
  } else {
    DeleteCase5(n);
  }
}
void DeleteCase5(Nod\
&&
      ((*(*s).getLeft()).getColor() == 1) && ((*(*s).getRight()).getCo\
lor() == 1)) {
    (*s).setColor(0);
    (*(*n).getParent()).setColor(1);
  } else {
    DeleteCase5(n);
  }
}
void DeleteCase5(Node* n) {
*/
void ACase1(Node* header, int*  DeleteValue, int* ADeleteValue){
  cout << "inhere" << endl;
  if((*(*header).getData()) == (*DeleteValue)){
    // cout << "here" << endl;
     cout << "h1" << endl;
     //  if((*header).getRight() == NULL){
     //cout << "here" << endl;
     // }
     /*      try{
     
     if((*header).getRight() != NULL && (*(*(*header).getRight()).getData()) == (*ADeleteValue)){
	  (*header).setRight(NULL);
	 
	  return;
	  	 }
      }
	  catch (...) {
       cout << "her3e" << endl;
	  }
	  try{
	  if((*header).getLeft() != NULL && (*(*(*header).getLeft()).getData()) == (*ADeleteValue)){
	  (*header).setLeft(NULL);
	 
	 return;
	  }
	  }
	  catch (...) {
	    cout << "her3e" << endl;
	  }
  }
     */
	 // }catch (const std::exception& e) {
	 
	

       
     // if((*header).getRight() != NULL && (*(*(*header).getRight()).getData()) == (*ADeleteValue) || (*header).getLeft() != NULL && (*(*(*header).getLeft()).getData()) == (*ADeleteValue)){
      //cout << "here" << endl;
      //cout << "h2" << endl;
      if((*ADeleteValue) > (*DeleteValue)){
	//cout << "h3" << endl;
	(*header).setRight(NULL);
    }
      else{
      //cout << "h4" << endl;
    (*header).setLeft(NULL);
    }
      //  cout << "h5" << endl;
      return;
  }
  // cout << "fin" << endl;

  // try{   
  /*
  if((*(*(*header).getLeft()).getData()) == (*DeleteValue)){
    if((*ADeleteValue) > (*DeleteValue)){
    (*(*header).getLeft()).setRight(NULL);
    }
    else{
    (*(*header).getLeft()).setLeft(NULL);
    }
    return;
  }
  //}
  //catch(...){
  // }
  //try
  if((*(*(*header).getRight()).getData()) == (*DeleteValue)){
    if((*ADeleteValue) > (*DeleteValue)){
    (*(*header).getRight()).setRight(NULL);
    }
    else{
    (*(*header).getRight()).setLeft(NULL);
    }
    return;
  }
  */
  if((*DeleteValue) <= (*(*header).getData())){
    ACase1((*header).getLeft(), DeleteValue, ADeleteValue);
    }
  else{
    ACase1((*header).getRight(), DeleteValue, ADeleteValue);
  }
  
}
