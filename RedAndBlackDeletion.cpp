/*
RedAndBlackTree Deletion By Andrew Thomas 5/8/20 Mr.Galbriath C++ Class. Red And Black Tree. This will correctly build a red and black tree and will properally add nodes to the tree. one can also search for a value on the tree. Finally, it can delte any node from the tree and rebuild the tree properally
Sources:
https://en.wikipedia.org/wiki/Red%E2%80%93black_tree
https://www.andrew.cmu.edu/user/mm6/95-771/examples/RedBlackTreeProject/dist/javadoc/redblacktreeproject/RedBlackTree.html
 
*/
#include <iostream>
//#include <cstdlib>
#include <cstdlib>


#include<cstring>
#include<fstream>
#include "Node.h"
using namespace std; // functions below
// Node* temp = new Node;
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
void ACase1(Node* header, int*  DeleteValue, int* ADeleteValue, Node* ogHeader);
void ACase2(Node* header, int*  DeleteValue, int* ADeleteValue);
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

      //  cout << "herez" << endl;
      //cout << (*SearchReturn((*header), deleteValue).getData()) << endl;
      	Search(header, deleteValue, exists);
	if((*exists) == true){ // it exists

      Node* deleteNode = new Node;
      SearchReturn((*header), deleteValue, deleteNode);
      //xcout << (*(*deleteNode).getData()) << endl;
      // cout << (*(*(*deleteNode).getRight()).getData()) << endl;
      // cout << "here" << endl;
      // DeleteOneChild(SearchReturn(header, deleteValue));
      DeleteOneChild(deleteNode, header);
      //  DeleteOneChild((*header).getRight(), header);
      //  fixIssue(&header, (*header).getRight());
      //  delete deleteNode;
      //            cout << (*(*header).getData()) << endl;
      // cout << (*(*(*header).getRight()).getData()) << endl;
      //cout << (*(*(*(*header).getRight()).getRight()).getData()) << endl;
      //cout << (*(*header).getData()) << endl;
	    //cout << (*(*(*header).getRight()).getData()) << endl;
       //cout << (*(*(*(*header).getRight()).getRight()).getData()) << endl;
       //cout << (*(*(*header).getLeft()).getData()) << endl;
      // cout << "nubs" << endl;
    
       // cout << (*(*(*(*header).getRight()).getLeft()).getData()) << endl;
       //       cout << (*(*(*(*(*header).getRight()).getRight()).getLeft()).getData()) << endl;
       //cout << (*(*(*(*(*header).getRight()).getRight()).getRight()).getData()) << endl;

      cout << "deleted" << endl;
	}
	if((*exists) == false){ // it does not exist
	  cout << (*deleteValue) << " Does not exist in the tree" << endl;
	}
	(*exists) = false;
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
void ReplaceNode(Node* n, Node* child) { // this function replaces a node with another node
  (*child).setParent((*n).getParent()); // set childs parent to nodes parent
  if (n == (*(*n).getParent()).getLeft()) {
    (*(*n).getParent()).setLeft(child); // child is to the left of node
  } else {
    (*(*n).getParent()).setRight(child); // child is to the right of node
  }
}

void DeleteOneChild(Node* n, Node* header) { // this funciton deletest the node n
  // Precondition: n has at most one non-leaf child.
  //cout << "lolz" << endl;
  Node* child = ((*n).getRight() == nullptr) ? (*n).getLeft() : (*n).getRight(); // saves child in separate node
  // Node* child = (*n).getRight();
  //Node* child = (*n).getRight();
  // assert(child);
   
  if((*n).getLeft() == NULL && (*n).getRight() == NULL){ // when there are no children
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
    ACase1( header,  (*(*n).getParent()).getData(), (*n).getData(), header); // do alternate case 1
 (*n).setParent(NULL);
 return;
   }
  if((*n).getLeft() != NULL && (*n).getRight() != NULL){
    //cout << "here" << endl;
    ACase2( header,  (*(*n).getParent()).getData(), (*n).getData()); // do alternate case 2
    // (*n).setParent(NULL);
    // temp
    /*
          cout << (*(*header).getData()) << endl;
       cout << (*(*(*header).getRight()).getData()) << endl;
       cout << (*(*(*(*header).getRight()).getRight()).getData()) << endl;
       cout << (*(*(*header).getLeft()).getData()) << endl;
       cout << "nubs" << endl;
    */
 // cout << (*(*(*(*header).getRight()).getLeft()).getData()) << endl;
       // cout << (*(*(*(*(*header).getRight()).getRight()).getLeft()).getData()) << endl;
       //cout << (*(*(*(*(*header).getRight()).getRight()).getRight()).getData()) << endl;
    return;
  }
   
  //cout << "herezz" << endl;
   ReplaceNode(n, child); // replace the node with the child
   //cout << "here";
  if ((*n).getColor() == 1) { // if black do nothing
    // cout << "there" << endl;
    if ((*child).getColor() == 0) { // if child red
      //cout << "DN1" << endl;
      (*child).setColor(1); // child is now black
    } else {
      //  cout << "D1";
      DeleteCase1(child); // if neither then do Actual Case 1

    }
  }
  //cout << "lol" << endl;
  //temp
  // (*child).setLeft((*n).getRight());
  
  free(n);
  // delete n;
  //delete child;
}
void DeleteCase1(Node* n) { // case 1
  // cout << "1";
  if ((*n).getParent() != nullptr) {
    DeleteCase2(n); // if has parent move to next case
  }
}
void DeleteCase2(Node* n) { // case 2
  //cout << "2";
  Node* s = GetSibling(n); // s is nodes sibling

  if ((*s).getColor() == 0) { // s is red
    (*(*n).getParent()).setColor(0); // parent is now red
    (*s).setColor(1); // s is now black
    if (n == (*(*n).getParent()).getLeft()) {
      RotateLeft2((*n).getParent()); // rotate left
    } else {
      RotateRight2((*n).getParent()); // rotate right
    }
  }
  DeleteCase3(n);
}
void DeleteCase3(Node* n) { //case 3
  //cout << "3";
  Node* s = GetSibling(n);

  if (((*(*n).getParent()).getColor() == 1) && ((*s).getColor() == 1) &&
      ((*(*s).getLeft()).getColor() == 1) && ((*(*s).getRight()).getColor() == 1)) {
    (*s).setColor(0); // s is red
    DeleteCase1((*n).getParent()); // back to case 1
  } else { // or move to case 4
    DeleteCase4(n);
  }
}
void DeleteCase4(Node* n) { // case 4
  //cout << "4";
 Node* s = GetSibling(n); // s is sibling
  
  if (((*(*n).getParent()).getColor() == 0) && ((*s).getColor() == 1) &&
      ((*(*s).getLeft()).getColor() == 1) && ((*(*s).getRight()).getColor() == 1)) {
    (*s).setColor(0); // s is red
    (*(*n).getParent()).setColor(1); // parent is black
  } else {
    DeleteCase5(n); // or move to case 5
  }
}
void DeleteCase5(Node* n) { // case 5
  //cout << "5";
 Node* s = GetSibling(n); // s is sibling

  if ((*s).getColor() == 1) { // s is black
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
void DeleteCase6(Node* n) { // final case
  //cout << "6";
  Node* s = GetSibling(n); // s is sibling

  (*s).setColor((*(*n).getParent()).getColor()); // s color is parents color
  (*(*n).getParent()).setColor(1); //n parent is now black

  if (n == (*(*n).getParent()).getLeft()) {
    (*(*s).getRight()).setColor(1); // s right is now black
    RotateLeft2((*n).getParent()); // rotate left
  } else {
    (*(*s).getLeft()).setColor(1); // s left is now black
    RotateRight2((*n).getParent()); // rotate right
  }
}

Node* GetSibling(Node* n) { // gets the silbing
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

void RotateLeft2(Node* n) { // roates left
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

void RotateRight2(Node* n) { // rotates right
  Node* nnew = (*n).getLeft();
  Node* p = (*n).getParent();
  //assert(nnew != nullptr);  // Since the leaves of a red-black tree are empty,
                            // they cannot become internal nodes.

  (*n).setLeft((*nnew).getRight());
  (*nnew).setRight(n);
  (*n).setParent(nnew);

  
  if ((*n).getLeft() != nullptr) {
    (*(*n).getLeft()).setParent(n);
  }

  
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
void ACase1(Node* header, int*  DeleteValue, int* ADeleteValue, Node* ogHeader){ // alternate case 1
  //  cout << "inhere" << endl;
  if((*(*header).getData()) == (*DeleteValue)){ // THIS IS NODE

    //(*header).setColor(0);
    // cout << "here" << endl;
    // cout << "h1" << endl;
    /*
    try{
    if((*(*(*ogHeader).getRight()).getData()) == (*ADeleteValue)){
    (*(*ogHeader).getLeft()).setColor(0);
							 }
     if((*(*(*ogHeader).getLeft()).getData()) == (*ADeleteValue)){
    (*(*ogHeader).getRight()).setColor(0);

    
    }
    }
    catch(...){
    
    }
    */
    if((*ADeleteValue) > (*DeleteValue)){ // delete the node
	//cout << "h3" << endl;
       delete (*header).getRight(); // deletes the node
       (*header).setRight(NULL);
    }
      else{
      //cout << "h4" << endl;
	delete (*header).getLeft(); // deletes the node
	(*header).setLeft(NULL);
    
      }
      //  cout << "h5" << endl;
      return;
  }
  // cout << "fin" << endl;

   if((*DeleteValue) <= (*(*header).getData())){
     ACase1((*header).getLeft(), DeleteValue, ADeleteValue, ogHeader);
    }
  else{
    ACase1((*header).getRight(), DeleteValue, ADeleteValue, ogHeader);
  }
  
}
void ACase2(Node* header, int*  DeleteValue, int* ADeleteValue){ // alternate case 2
  //  cout << "inhere" << endl;
  if((*(*header).getData()) == (*DeleteValue)){ // THIS IS NODE
    //cout << "to left" << endl;
    //(*header).setColor(0);
    // cout << "here" << endl;
    // cout << "h1" << endl;
    
     if((*ADeleteValue) > (*DeleteValue)){ // delete the node
       //   cout << "here" << endl;
       Node* temp = new Node;
       Node* deletethis = new Node;
       (*deletethis) = (*(*header).getRight());
       (*temp) = (*(*(*header).getRight()).getRight());
       (*(*header).getRight()).setRight(NULL);
       (*header).setRight((*(*header).getRight()).getLeft());
       (*(*header).getRight()).setColor(1);
       // (*(*(*header).getRight()).getRight()).setColor(0);
       (*(*header).getRight()).setRight(temp);
       // cout << (*(*header).getData()) << endl;
       //cout << (*(*(*header).getRight()).getData()) << endl;
       //cout << (*(*(*(*header).getRight()).getRight()).getData()) << endl;
       delete deletethis;
       //cout << "h3" << endl;
       //delete (*header).getRight(); // deletes the node
       //(*header).setRight(NULL);
    }
      else{
	//	cout << "herez" << endl;
	       Node* temp = new Node;
	            Node* deletethis = new Node;
       (*deletethis) = (*(*header).getLeft());

	       (*temp) = (*(*(*header).getLeft()).getRight());
       (*header).setLeft((*(*header).getLeft()).getLeft());
       (*(*header).getLeft()).setColor(1);
       (*(*header).getLeft()).setRight(temp);
        delete deletethis;
      //cout << "h4" << endl;
	//delete (*header).getLeft(); // deletes the node
	//(*header).setLeft(NULL);
    
      }
      //  cout << "h5" << endl;
      
    
    return;
  }
  /*
  if((*(*(*header).getRight()).getData()) == (*DeleteValue)){ // THIS IS NODE
    //(*header).setColor(0);
    cout << "to right" << endl;
    // cout << "here" << endl;
    // cout << "h1" << endl;
    /*
     if((*ADeleteValue) > (*DeleteValue)){ // delete the node
	//cout << "h3" << endl;
       delete (*header).getRight(); // deletes the node
       (*header).setRight(NULL);
    }
      else{
      //cout << "h4" << endl;
	delete (*header).getLeft(); // deletes the node
	(*header).setLeft(NULL);
    
      }
      //  cout << "h5" << endl;
      */
  /*
    return;
  }
  */
  // cout << "fin" << endl;

   if((*DeleteValue) <= (*(*header).getData())){
     ACase2((*header).getLeft(), DeleteValue, ADeleteValue);
    }
  else{
    ACase2((*header).getRight(), DeleteValue, ADeleteValue);
  }
  
}
