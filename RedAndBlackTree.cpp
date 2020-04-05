/*
Citation: https://en.wikipedia.org/wiki/Red%E2%80%93black_tree
  */
#include <iostream>
//#include <conio.h>
//#include <cstdlib>
//HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
//#include <stdlib.h>

#include<cstring>
#include<fstream>
#include "Node.h"
using namespace std;
//void FixTree(Node* n);
void getParent(Node* header, Node* n, Node* Parent, Node* ActualParent);
//void FixTree(Node* header, Node* n, Node* Uncle, Node* GrandParent, Node* Parent);
//Node* getParent(Node* header, Node* n, Node* Parent);
void FixTree(Node* header, Node* n, Node* ActualUncle, Node* ActualGrandParent, Node* ActualParent, Node* Uncle, Node* GrandParent, Node* Parent);
void getGrandParent(Node* header, Node* n, Node* GrandParent, Node* Parent, Node* ActualGrandParent);
//void getUncle(Node* header, Node* n, Node* Uncle, Node* GrandParent, Node* Parent);
void getUncle(Node* GrandParent, Node* Parent, Node* ActualUncle);
//Node* getUncle(Node* n);
//Node* getParent(Node* n);
//Node* getGrandParent(Node* n);
int* Parce(char* input, int* index, int* counterOne, int* wordCounter, int* parced); // functions
//void BuildTree(char* input, int* index, int* counterOne, int* wordCounter, int* parced, int* size, Node* header);
void BuildTree(char* input, int* index, int* counterOne, int* wordCounter, int* parced, int* size, Node* header, Node* ActualUncle, Node* ActualGrandParent, Node* ActualParent, Node* Uncle, Node* GrandParent, Node* Parent); // this builds the tre
void Add(Node* header, Node* add);
void RotateLeft(Node* n, Node* ActualParent, Node* nnew);
//void Subtract();
void Subtract(Node* header, int* deleteThis, Node* previous, int* DCounter, int* skip, int* special);
void Print(Node* header, int length, int count, int i);
//void Search();
void Search(Node* header, int* searchData, bool* exists);
void maxSize(char* input, int* size);
Node* getRightMost(Node* header);
void RotateRight(Node* n, Node* ActualParent, Node* nnew);
void InsertCaseFour(Node* n, Node* ActualParent, Node* ActualGrandParent, Node* Parent, Node* GrandParent, Node* header, Node* ogg);
void InsertCaseFour2(Node* n, Node* ActualParent, Node* ActualGrandParent, Node* ogg);
int main(){ // initialization of variables
  //HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  //SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
  Node* ActualGrandParent = new Node;
  Node* ActualUncle = new Node;
  Node* ActualParent = new Node;
  char* inputType = new char[20];
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
  BuildTree(input, index, counterOne, wordCounter, parced, size, header, ActualUncle, ActualGrandParent, ActualParent, Uncle, GrandParent, Parent); // builds the tree
  do{
  cout << "The Red and Black tree is now created. you can ADD, DELETE, SEARCH, or PRINT from the tree. You can also type QUIT if you want to quit the program(NOTE THAT ALL THE FUNCTIONS ARE COMPLETE FOR PART 1 EXCEPT for DELETE I WILL WORK ON THAT IN PART 2)" << endl; 
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
    Node* two = new Node; // creates the new node
    (*two).setData(Parce(additionInput, index, counterOne, wordCounter, parced));
    //cout << "added data" << (*(*two).getData()) << endl;
    // cout
    //  cout << (*(*getParent(header, two, Parent)).getData()) << endl;
    Add(header, two);
    getParent(header, two, Parent, ActualParent);
    getGrandParent(header,  two,  GrandParent, ActualParent, ActualGrandParent); // check NULL case
    getUncle(ActualGrandParent, ActualParent, ActualUncle); // check NULL case
    Parent = NULL;
      Uncle = NULL;
      GrandParent = NULL;
    //  cout << "final DATA" << endl;
    // cout << "P" << (*(*ActualParent).getData()) << endl;
    //cout << "GP" <<(*(*ActualGrandParent).getData()) << endl;
    //cout << "U" << (*(*ActualUncle).getData()) << endl;
    // cout << (*(*ActualParent).getData()) << endl;
	//cout << "why" << endl;
    // }
      //cout << (*(*getParent(header, two, Parent)).getData()) << endl;
    //cout << (*getParent(header, two, Parent).getData()) << endl;
    //cout << "there" << endl;
     FixTree(header, two, ActualUncle, ActualGrandParent, ActualParent, Uncle, GrandParent, Parent);
    //FixTree(header, two, getUncle(header, two, Uncle), getGrandParent(header, two, GrandParent), getParent(header, two, Parent));
    cout << "Added" << endl;
  }
    if(strcmp(inputFunction, "DELETE") == 0){ // delete function that deletes a node form tree
      // cout << "subtract" << endl;
      cout << "Please enter the 3-digit number you would like to delete from the tree" << endl; 
      cin.get(subtractInput, 20); // which node do you want to delete
      cin.clear();
      cin.ignore();
      Search(header, Parce(subtractInput, index, counterOne, wordCounter, parced), exists);
	if((*exists) == true){ // it exists
	  // cout << (*Parce(searchInput, index, counterOne, wordCounter, parced)) << " exists in the tree" << endl;
	  //(*(*previous).getData()) = (*(*header).getData());
	  Subtract(header, Parce(subtractInput, index, counterOne, wordCounter, parced), header, DCounter, skip, special);
	  // (*size)--;
	  if((*special) == 1){
	    (*(*header).getData()) = (*skip);
	  }
	  (*special) = 0;
	  (*skip) = 0;
	  (*DCounter) = 0;
	  cout << "deleted" << endl;
	}
	if((*exists) == false){ // it does not exist
	  cout << (*Parce(subtractInput, index, counterOne, wordCounter, parced)) << " Does not exist in the tree" << endl;
	}
	(*exists) = false;
	// Subtract();
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
void BuildTree(char* input, int* index, int* counterOne, int* wordCounter, int* parced, int* size, Node* header, Node* ActualUncle, Node* ActualGrandParent, Node* ActualParent, Node* Uncle, Node* GrandParent, Node* Parent){ // this builds the tree
  //Node* one = new Node;
      // (*one).setData(Parce(input, index, counterOne, wordCounter, parced));

  // cout << "build tree" << endl;
  // cout << (*size) << endl;
  // Node* header = new Node;
  int* RED = new int;
  (*RED) = 0;
  int* BLACK = new int;
  (*BLACK) = 1;
  (*header).setData(Parce(input, index, counterOne, wordCounter, parced)); // creates the head
  (*header).setColor(BLACK);
  (*index)++; 
  //cout << "head data" << (*(*header).getData()) << endl;
  do{
    Node* one = new Node;
    (*one).setData(Parce(input, index, counterOne, wordCounter, parced)); // creates the new node
    
    //(*one).setColor(BLACK);
    //cout << "data" << (*(*one).getData()) << endl;
    Add(header, one); // adds the new node
    (*index)++;
    // Add(header, two);
    getParent(header, one, Parent, ActualParent);
    getGrandParent(header,  one,  GrandParent, ActualParent, ActualGrandParent); // check NULL case
    getUncle(ActualGrandParent, ActualParent, ActualUncle); // check NULL case
    //cout << "final DATA" << endl;
     //     cout << "P" << (*(*ActualParent).getData()) << endl;
    //cout << "GP" <<(*(*ActualGrandParent).getData()) << endl;
    //cout << "U" << (*(*ActualUncle).getData()) << endl;
    //     cout << (*(*ActualParent).getData()) << endl;
	//cout << "why" << endl;
    // }
      //cout << (*(*getParent(header, two, Parent)).getData()) << endl;
    //cout << (*getParent(header, two, Parent).getData()) << endl;
    //cout << "there" << endl;
     FixTree(header, one, ActualUncle, ActualGrandParent, ActualParent, Uncle, GrandParent, Parent);

  }
  while((*index) != (*size)+1); // continues to do this until all the numbers from input are put into the tree
  //cout << "double jump value: " <<  (*(*(*(*header).getRight()).getRight()).getData())<< endl;
  //cout << "triple jump value: " <<  (*(*(*(*(*header).getRight()).getRight()).getRight()).getData())<< endl;
}
void Add(Node* header, Node* add){ // this funcitons adds a node to the list
  // cout << "add" << endl;
  if((*(*add).getData()) <= (*(*header).getData()) && (*header).getLeft() != NULL){ // this node should go to the left because it is <= current node
    Add((*header).getLeft(), add);
  }
  //if((*(*header).getData()) >= (*(*add).getData()) && (*header).getLeft() == NULL){
     if((*(*add).getData()) <= (*(*header).getData()) && (*header).getLeft() == NULL){
       (*header).setLeft(add);
     } // add it to the end

     //if((*(*header).getData()) < (*(*add).getData()) &&(*header).getLeft() != NULL){
     if((*(*add).getData()) > (*(*header).getData()) && (*header).getRight() != NULL){ // this node should go to the right because it is > than current node
	Add((*header).getRight(), add);
      } 
      // if((*(*header).getData()) < (*(*add).getData()) &&(*header).getLeft() == NULL){
  if((*(*add).getData()) > (*(*header).getData()) && (*header).getRight() == NULL){
    (*header).setRight(add);
  } // add it to the end
}
void Subtract(Node* header, int* deleteThis, Node* previous, int* DCounter, int* skip, int* special){ // this function deletes a node from the list
  // cout << "subtract" << endl;
   if((*header).getRight() == NULL && (*header).getLeft() == NULL){
     // if((*(*(*header).getRight()).getData()) == (*deleteThis) || (*(*(*header).getLeft()).getData()) == (*deleteThis)){
     if((*(*header).getData()) == (*deleteThis)){
       //cout << "no child" << endl;
     //cout << "Parent" << (*(*header).getData()) << endl;
    //}
    if((*DCounter) == 0){
      delete header;
      return;
    }
       
    else if((*(*header).getData()) > (*(*previous).getData())){
    (*previous).setRight(NULL);
    }
    else{
      (*previous).setLeft(NULL);
    }
    (*DCounter) = 0;
    delete header;
    return;
     }
   }
   if((*header).getRight() == NULL && (*header).getLeft() != NULL || (*header).getRight() != NULL && (*header).getLeft() == NULL){
     if((*header).getRight() != NULL && (*(*header).getData()) == (*deleteThis)){
       // cout << "one right child" << endl;
       // cout << "Parent" << (*(*header).getData()) << endl;
        if((*DCounter) == 0){
	  //(*(*header).getData()) = (*(*(*header).getRight()).getData());
	  (*DCounter) = 1;
	  (*special) = 1;
	  (*skip) = (*(*(*header).getRight()).getData());
	  //  cout << "woah: "<< (*(*(*header).getRight()).getData()) << endl;
	    Subtract((*header).getRight(), (*(*header).getRight()).getData(), header, DCounter, skip, special);
	    return;
    }

	if((*(*header).getData()) > (*(*previous).getData())){
      (*previous).setRight((*header).getRight());
      //	(*DCounter) = 0;
      //	(*skip) = 0;
	delete header;
	return;

    }
     if((*(*header).getData()) <= (*(*previous).getData()) ){
      (*previous).setLeft((*header).getRight());
      //	(*DCounter) = 0;
	//	(*skip) = 0;
	delete header;
    return;

    }
     //(*skip) = 0;
	//(*DCounter) = 0;
	//delete header;
   
	//  return;
     }
     if((*header).getLeft() != NULL && (*(*header).getData()) == (*deleteThis)){
       //cout << "one left child" << endl;
       // cout << "Parent" << (*(*header).getData()) << endl;
        if((*DCounter) == 0){
	  //cout << "here" << endl;
	  	  (*DCounter) = 1;
	  (*special) = 1;
	  (*skip) = (*(*(*header).getLeft()).getData());
	  //  cout << "woah: "<< (*(*(*header).getRight()).getData()) << endl;
	    Subtract((*header).getLeft(), (*(*header).getLeft()).getData(), header, DCounter, skip, special);
	    return;
	  // header = (*header).getLeft();
	  //(*(*header).getData()) = (*(*(*header).getLeft()).getData());
	  // (*DCounter) = 1;
	  //(*skip) = 1;
	  //	  Subtract(header, (*(*header).getLeft()).getData(), header, DCounter, skip, special);
	  //return;
    }

	if((*(*header).getData()) > (*(*previous).getData())){
      (*previous).setRight((*header).getLeft());
      	(*DCounter) = 0;
	delete header;
    return;

    }
	if((*(*header).getData()) <= (*(*previous).getData())){
      (*previous).setLeft((*header).getLeft());
      	(*DCounter) = 0;
	
	delete header;
    return;

    }
	//if((*skip) == 1){
	// (*skip) = 0;
	  // Subtract((*header).getLeft(), deleteThis, header, DCounter, skip);
	//	}
	//(*skip) = 0;
	//	(*DCounter) = 0;
	//	delete header;
	//return;
     }

   }
   if((*header).getRight() != NULL && (*header).getLeft() != NULL){
          if((*(*header).getData()) == (*deleteThis)){
	    // cout << "both child" << endl;
	    //cout << "Parent" << (*(*header).getData()) << endl;
    //   (*getRightMost((*header).getLeft())).setLeft(NULL);
    // (*getRightMost((*header).getLeft())).setRight(NULL);

    if((*DCounter) == 0){
	  return;
    }
    //	(*getRightMost((*header).getLeft())).setLeft(NULL);
    //	(*getRightMost((*header).getLeft())).setRight(NULL);
	else if((*(*header).getData()) > (*(*previous).getData())){
     //(*getRightMost((*header).getLeft())).setRight((*previous).getLeft());
	  (*previous).setRight(getRightMost((*header).getLeft()));
	  (*(*header).getLeft()).setRight(NULL);
	  // (*(*header).getLeft()).setRight((*(*previous).getLeft()).getLeft());
	  (*(*header).getLeft()).setRight((*(*previous).getLeft()).getLeft());
	  (*(*(*header).getLeft()).getRight()).setRight((*(*previous).getLeft()).getRight());
	  ///(*(*previous).getRight()).setRight(NULL);
	   (*(*previous).getRight()).setRight((*header).getRight());
	   (*(*previous).getRight()).setLeft((*header).getLeft());
     //(*previous).setRight(getRightMost(header));
     // (*header)
     //(*previous).setLeft((*header).getRight());
     //(*(*previous).get()).setRight();
   }
    else{
      (*previous).setLeft(getRightMost((*header).getLeft()));
      (*(*header).getLeft()).setRight(NULL);
      (*(*header).getLeft()).setRight((*(*previous).getLeft()).getLeft());
        (*(*(*header).getLeft()).getRight()).setRight((*(*previous).getLeft()).getRight());
      (*(*previous).getLeft()).setRight((*header).getRight());

      (*(*previous).getLeft()).setLeft((*header).getLeft());
       //  (*previous).setLeft(getRightMost(header));
      // (*previous).setRight((*header).getLeft());
    }
   (*DCounter) = 0;
   delete header;
    //}
    return;
     }

   }
  
   if((*header).getRight() != NULL && (*deleteThis) > (*(*header).getData())){
     (*DCounter) = 1;
     Subtract((*header).getRight(), deleteThis, header, DCounter, skip, special);
   }
       if((*header).getLeft() != NULL && (*deleteThis) <= (*(*header).getData())){
	 (*DCounter) = 1;
	 Subtract((*header).getLeft(), deleteThis, header, DCounter, skip, special);
	 
       }

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
  if((*(*header).getColor()) == 0){
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
Node* getRightMost(Node* header){
  if((*header).getRight() == NULL){
    return header;
  }
  else{
    getRightMost((*header).getRight());
  }
}

void getParent(Node* header, Node* n, Node* Parent, Node* ActualParent){
  // if((*(*n).getData()) == )){ // THIS IS THE NODE
  if(header == n){
  //	 (*exists) = true;
    // cout << "here" << endl;
    //cout << (*(*Parent).getData()) << endl;
    // cout << "gotone" << endl;
    if(Parent != NULL){
      // cout << "here" << endl;
      (*ActualParent) = (*Parent);
    //return Parent;
    }
  else{
    //cout << "hereyes" << endl;
    ActualParent = NULL;
  }
    return;
  }
  else{
    // cout << "herex" << endl;
    // ActualParent = NULL;
    //cout << "herenot" << endl;
    // return;
  }

  
  

  if((*header).getRight() != NULL && (*(*n).getData()) > (*(*header).getData())){ // not the node search rihgt
    //cout << "here1" << endl;
    getParent((*header).getRight(), n, header, ActualParent);
       }
  /*
  if((*(*header).getData()) == (*searchData)){
	 (*exists) = true;
       }
  */
  if((*header).getLeft() != NULL && (*(*n).getData()) <= (*(*header).getData())){ // not the node so search left
    //cout << "here2" << endl;
    getParent((*header).getLeft(), n, header, ActualParent);
       }
  //cout << "herez" << endl;
  //return NULL;
}
void FixTree(Node* header, Node* n, Node* ActualUncle, Node* ActualGrandParent, Node* ActualParent, Node* Uncle, Node* GrandParent, Node* Parent){
  // cout << "here" << endl;
  //cout << (*(*n).getData()) << endl;
  //cout << (*(*Parent).getData()) << endl;
  //cout << (*(*Parent).getColor()) << endl;
  // cout << (*(*Parent).getData()) << endl;
  if(ActualParent == NULL){
    // cout << "why" << endl;
  }
  int* RED = new int;
  (*RED) = 0;
  int* BLACK = new int;
  (*BLACK) = 1;
  if(ActualParent == NULL){
    //  cout << "here1" << endl;
       (*n).setColor(BLACK);
    return;
  }
  else if((*(*ActualParent).getColor()) == (*BLACK)){
    //(*n).setColor(BLACK);
    //cout << "here2" << endl;
    return;
  }
  else if(ActualUncle != NULL && (*(*ActualUncle).getColor()) == (*RED)){
    (*ActualParent).setColor(BLACK);
    (*ActualUncle).setColor(BLACK);
    (*ActualGrandParent).setColor(RED);
    //(*n) = (*ActualGrandParent);
      Node* save = new Node;
    (*save) = (*ActualGrandParent);
          Node* save2 = new Node;
    (*save2) = (*ActualGrandParent);

    Parent = NULL;
    GrandParent = NULL;
      Uncle = NULL;
      ActualParent = NULL;
      ActualGrandParent = NULL;
	ActualUncle = NULL;
      // cout << "P" << (*(*Parent).getData()) << endl;
	//	cout << "a1" << endl;
	  getParent(header, save, Parent, ActualParent);
	  //cout << "a2" << endl;
	  getGrandParent(header,  save,  GrandParent, ActualParent, ActualGrandParent); // check NULL case
	  
	  //cout << "a3" << endl;
    getUncle(ActualGrandParent, ActualParent, ActualUncle); // check NULL case
    //  cout << "a4" << endl;
    //cout << "Mod Data" << endl;
    // cout << "P" << (*(*ActualParent).getData()) << endl;
    //cout << "GP" <<(*(*ActualGrandParent).getData()) << endl;
    //cout << "U" << (*(*ActualUncle).getData()) << endl;
    //    cout << (*(*save).getData()) << endl;
    //cout << "here" << endl;
    FixTree(header, save2, ActualUncle, ActualGrandParent, ActualParent, Uncle, GrandParent, Parent);
    // FixTree(header, n, Uncle,  GrandParent,  Parent);
  }
  else{
    Parent = NULL;
    GrandParent = NULL;
    //(*ogg) = (*ActualGrandParent);
    InsertCaseFour(n, ActualParent, ActualGrandParent, Parent, GrandParent, header, ActualGrandParent);
    (*header).setLeft((*ActualGrandParent).getLeft());
    //  InsertCaseFour2( n,  ActualParent,  ActualGrandParent, ActualGrandParent); // watch ogg
    //  (*header) = (*ActualParent);
    //(*header).setLeft((*ActualGrandParent).getLeft());
    int* red = new int;
    (*red) = 0;
    cout << (*(*ActualGrandParent).getColor()) << endl;
    cout << (*(*header).getColor()) << endl;
    //  (*ActualGrandParent).setColor(red);
      cout << (*(*ActualGrandParent).getColor()) << endl;
    cout << (*(*header).getColor()) << endl;
    cout << "RET3 FINDATA" << endl;
    
    // cout << (*(*(*ActualGrandParent).getLeft()).getData()) << endl;
    //cout << (*(*(*header).getLeft()).getData()) << endl;
    //    (*ActualGrandParent).setData(red);
    //cout << (*(*header).getData()) << endl;
    //cout << (*(*ActualGrandParent).getData()) << endl;
    //cout << (*(*(*(*ActualGrandParent).getLeft()).getRight()).getData()) << endl;
    //cout << (*(*(*ActualGrandParent).getLeft()).getData()) << endl;
    //cout << "rotateRight" << endl;
    // RotateRight( n,  ActualParent);
    //  cout << "rotate left" << endl;
     //RotateLeft( n, ActualParent);
    // RotateLeft( ActualParent, ActualGrandParent);
    //cout << "finish" << endl;
  }
  
}
void getUncle(Node* GrandParent, Node* Parent, Node* ActualUncle){
  //return Uncle;
  // cout << "here" << endl;
  //cout << "left" << (*(*(*GrandParent).getLeft()).getData()) << endl;
  //cout << "right" << (*(*(*GrandParent).getRight()).getData()) << endl;
  //cout << "infunct" << endl;
  if(Parent != NULL && (*(*Parent).getData()) > (*(*GrandParent).getData())){
    //cout << "t1" << endl;
     //    cout << "here1" << endl;
     if((*GrandParent).getLeft() != NULL){
       // cout << "t2" << endl;
       (*ActualUncle) = (*(*GrandParent).getLeft());
       // return;
     }
     else{
       //cout << "t3" << endl;
       ActualUncle = NULL;
     }
     //cout << "exit" << endl;
     return;
   }
   else if(Parent != NULL && (*(*Parent).getData()) <= (*(*GrandParent).getData())){
     // cout << "here2" << endl;
     //cout << "t4" << endl;
     if((*GrandParent).getRight() != NULL){
     (*ActualUncle) = (*(*GrandParent).getRight());
     //return;
     //cout << "t5" << endl;
     }
     else{
       //  ((*ActualUncle).getData()) = NULL;
          ActualUncle = NULL;
	  //	  cout << "t6" << endl; 
     }
     return; 
   }
   else{
     
     // cout << "rotate left" << endl;
     //RotateLeft( n, ActualParent);
     //cout << "finish" << endl;
     //cout << "t7" << endl;
     // ActualUncle = NULL;
     //return;
   }
  //cout << "here" << endl;
   //cout << "UNCLE:" << (*(*ActualUncle).getData()) << endl;
   }
/*
Node* getParent(Node* header, Node* n, Node* Parent){
  // if((*(*n).getData()) == )){ // THIS IS THE NODE
  if(header == n){
  //	 (*exists) = true;
    cout << "here" << endl;
    cout << (*(*Parent).getData()) << endl;
    return Parent;
    }

  if((*header).getRight() != NULL && (*(*n).getData()) > (*(*header).getData())){ // not the node search rihgt
    cout << "here1" << endl;
    getParent((*header).getRight(), n, header);
       }
  /*
  if((*(*header).getData()) == (*searchData)){
	 (*exists) = true;
       }
*/
//if((*header).getLeft() != NULL && (*(*n).getData()) <= (*(*header).getData())){ // not the node so search left
//  cout << "here2" << endl;
//  getParent((*header).getLeft(), n, header);
//     }
  //cout << "herez" << endl;
  //return NULL;
//}
//*/
void getGrandParent(Node* header, Node* n, Node* GrandParent, Node* Parent, Node* ActualGrandParent){
   if(header == n){
  //	 (*exists) = true;
    // cout << "here" << endl;
    //  cout << (*(*GrandParent).getData()) << endl;
     if(GrandParent != NULL){
     (*ActualGrandParent) = (*GrandParent);
     
     }
     else{
       ActualGrandParent = NULL;
     }
    //return Parent;
     return;
   }
 else{
   //ActualGrandParent = NULL;
	//return;
   }
  if((*header).getRight() != NULL && (*(*n).getData()) > (*(*header).getData())){ // not the node search rihgt
    //cout << "here1" << endl;
    getGrandParent((*header).getRight(), n, Parent, header, ActualGrandParent);
       }
  /*
  if((*(*header).getData()) == (*searchData)){
	 (*exists) = true;
       }
  */
  if((*header).getLeft() != NULL && (*(*n).getData()) <= (*(*header).getData())){ // not the node so search left
    //cout << "here2" << endl;
    getGrandParent((*header).getLeft(), n, Parent, header, ActualGrandParent);
       }

  //return GrandParent;
}
void InsertCaseFour(Node* n, Node* ActualParent, Node* ActualGrandParent, Node* Parent, Node* GrandParent, Node* header, Node* ogg){
  cout << "inside" << endl;
  Node* p = ActualParent;
  Node* g = ActualGrandParent;
  //Node* ogg = new Node*;
  //;
  //ut << "match" << endl;
  if(n == (*p).getRight()){
    cout << "yes" << endl;
  }
  cout <<  (*(*p).getData()) << endl;
  cout <<  (*(*g).getData()) << endl;
  cout << (*(*(*g).getLeft()).getData()) << endl;
  // cout <<  (*(*p).getData()) << endl;
  if(p == (*g).getLeft()){
    cout << "yes2" << endl;
  }
  if(ActualParent == (*ActualGrandParent).getLeft()){
    cout << "yes3" << endl;
  }
  //if(n == (*p).getRight() && p == (*g).getLeft()){
  if(n == (*p).getRight() && (*(*p).getData()) <= (*(*g).getData())){
    cout << "here" << endl;
    // RotateLeft(p, ActualGrandParent);
    RotateLeft(p, g, (*p).getRight());
      //cout << (*(*(*g).getLeft()).getData());
      cout << "RET 2" << endl;
      n = (*n).getLeft();
    
  }
  else if(n == (*p).getLeft() && (*(*p).getData()) > (*(*g).getData())){
    cout << "here" << endl;
    RotateRight(p, ActualGrandParent, (*p).getLeft());
    //(*n).getRight();
  
   n = (*n).getRight();
  }
  //(*header).setLeft((*ActualGrandParent).getLeft());
  getParent(header, n, Parent, ActualParent);
	  //cout << "a2" << endl;
  	  getGrandParent(header,  n,  GrandParent, ActualParent, ActualGrandParent); // check NULL 
	  //	  InsertCaseFour2( n,  ActualParent,  ActualGrandParent, ogg);
	  //ActualParent = 
  //assert(nnew != NULL);
  
}
void RotateLeft(Node* n, Node* ActualParent, Node* nnew){
  cout << "LR" << endl;
  cout << (*(*n).getData()) << endl;
  // Node* nnew = new Node;
  //(*nnew) = (*(*n).getRight());
  //Node* p = new Node;
  //(*p) =  (*ActualParent);
  //(*p).setLeft(NULL);
  //(*ActualParent).setLeft(NULL);
  //cout << (*(*(*p).getLeft()).getData()) << endl;
  cout << "RET" << endl;
  // return;
  //int* black = new int;
  //(*black) = 1;
  //(*nnew).setColor(black);
  //return;
  //(*p).setLeft(nnew);
  //return;
  //  cout << (*(*p).getData()) << endl;
  //cout << (*(*nnew).getData()) << endl;
  //cout << (*(*p).getData()) << endl;
  cout << "t2" << endl;
  //if((*nnew).getLeft() != NULL){ // safegaurd
  // if((*(*n).getData()) <= (*(*p).getData())){
  //assert(nnew != nullptr);  // Since the leaves of a red-black tree are empty,
  (*n).setRight((*nnew).getLeft()); 
  //(*n).setRight((*nnew).getLeft()); 
  //}
  
  cout << "here" << endl;
  (*nnew).setLeft(n);
  // (*nnew).setLeft(n);
  cout << "t3" << endl;
  if((*n).getRight() != NULL){
    cout << "t5" << endl;
  }
  cout << "t6" << endl;
  if(ActualParent != NULL){
    cout << "t7" << endl;
    //if(n == (*p).getLeft()){
    if((*(*n).getData()) <= (*(*ActualParent).getData())){
      cout << "t8" << endl;
      //(*p).setLeft(nnew);
      (*ActualParent).setLeft(nnew);
      //  cout << (*(*(*p).getLeft()).getData()) << endl;
      cout << (*(*ActualParent).getData()) << endl;
      cout << (*(*(*ActualParent).getLeft()).getData()) << endl;
    }
    // else if(n == (*p).getRight()){
    else if((*(*n).getData()) > (*(*ActualParent).getData())){
      (*ActualParent).setRight(nnew);
      cout << "t9" << endl;
    }
  }
  cout << "done" << endl;
  //cout << "RET3 FINDATA" << endl;
      //  cout << (*(*(*p).getLeft()).getData()) << endl;
  // cout << (*(*(*ActualParent).getLeft()).getData()) << endl;
  // cout << (*(*(*(*ActualParent).getLeft()).getRight()).getData()) << endl;

  //ActualParent = 
  //assert(nnew != NULL);
}
void RotateRight(Node* n, Node* ActualParent, Node* nnew){
  cout << "t1" << endl;
  ///Node* nnew = (*n).getLeft();
  Node* p = ActualParent;
  cout << "t2" << endl;
  //if((*nnew).getRight() != NULL){ // safegaurd
  (*n).setLeft((*nnew).getRight());
  //}
  cout << "here" << endl;
  (*nnew).setRight(n);
  cout << "t3" << endl;
  if((*n).getLeft() != NULL){
    cout << "t5" << endl;
  }
  cout << "t6" << endl;
      if(p != NULL){
    cout << "t7" << endl;
    if((*(*n).getData()) <= (*(*ActualParent).getData())){
      cout << "t8" << endl;
      (*p).setLeft(nnew);
    }
    else if((*(*n).getData()) > (*(*ActualParent).getData())){
      (*p).setRight(nnew);
      cout << "t9" << endl;
    }
  }
  cout << "done" << endl;
  /*
   */
}
/*
void InsertCaseFour(Node* n, Node* ActualParent, Node* ActualGrandParent){
  cout << "inside" << endl;
  Node* p = ActualParent;
  Node* g = ActualGrandParent;
  //ut << "match" << endl;
  if(n == (*p).getRight()){
    cout << "yes" << endl;
  }
  cout <<  (*(*p).getData()) << endl;
  cout <<  (*(*g).getData()) << endl;
  cout << (*(*(*g).getLeft()).getData()) << endl;
  // cout <<  (*(*p).getData()) << endl;
  if(p == (*g).getLeft()){
    cout << "yes2" << endl;
  }
  if(ActualParent == (*ActualGrandParent).getLeft()){
    cout << "yes3" << endl;
  }
  //if(n == (*p).getRight() && p == (*g).getLeft()){
  if(n == (*p).getRight() && (*(*p).getData()) <= (*(*g).getData())){
    cout << "here" << endl;
    // RotateLeft(p, ActualGrandParent);
    RotateLeft(p, g, (*p).getRight());
      //cout << (*(*(*g).getLeft()).getData());
      cout << "RET 2" << endl;
      n = (*n).getLeft();
    
  }
  else if(n == (*p).getLeft() && p == (*g).getRight()){
    cout << "here" << endl;
    RotateRight(p, ActualGrandParent);
    //(*n).getRight();
  
   n = (*n).getRight();
  }
}
*/
void InsertCaseFour2(Node* n, Node* ActualParent, Node* ActualGrandParent, Node* ogg){
  // node* GreatGrandParent = new Node*
  cout << (*(*n).getData()) << endl;
  cout << (*(*ActualParent).getData());
  cout << "C1" << endl;
  if((*(*n).getData()) <= (*(*ActualParent).getData())){
    cout << "C2" << endl;
    RotateRight(ActualGrandParent, ogg, (*n).getLeft());
  }
  else{
    cout << "C3" << endl;
    RotateLeft(ActualGrandParent, ogg, (*n).getRight());
  }
  int* black = new int;
  int* red = new int;
  (*black) = 1;
  (*red) = 0;
  (*ActualParent).setColor(black);
  (*ActualGrandParent).setColor(red);
}
