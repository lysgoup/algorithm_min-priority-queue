/*
References

*/
// Should use Heap data structure
// Element index should begin from 1 not 0
/* 
1) Assume maximum heap size is 30.

2) Each element has three fields – name, id, and school.

3) ‘name’ consists of English alphabet (at most 10 characters). You don’t need to
check validity of ‘name’ (i.e. we assume user always enter alphabet letters whose
length is less than or equal to 10. No extreme/unusal input.). 

4) id is 4 digit (integer) number and used as a key field.
case1) We assume user always enter integer, but might enter a number other than 4 digit number (such as 12345. If 1000’s number is 0, it is not 4 digit number, i.e. 0123 is not valid one.).
case2) User may enter any character, such as “12 34”, “123o”, “12_34”, etc.
If you choose to do your program with case2, you will get extra 20% points. 

5) ‘school’ is either “Handong”, “Doodong”, or “Sedong”.
Your program should consists of following functions:
- INSERT(S, x) : inserts element x into set S.
- MINIMUM(S) : returns element of S with smallest key.
- EXTRACT-MIN(S) : removes and returns element of S with smallest key. 
- DECREASE-KEY(S, x, k) : decreases value of element x's key to k.
You may use other functions describe other than above functions.
When your program starts, it repeatedly presents menu until user enters ‘Q’. Following is description of each menu.
I: When this menu is chosen, program asks user’s name and score, then inserts
element into queue.
D: When this menu is chosen, program removes and displays record of element
with smallest score and rebuild queue.
C: When this menu is chosen, program asks index of element and new score of
element, then decreases key value of the element and place the element in
proper position.
P: When this menu is chosen, program displays all elements in queue. 
Q: When this menu is chosen, program gets terminated.
*/

#include <iostream>
#include <string>
using namespace std;
#define HEAP_SIZE 30

class student{
  string name;
  int id;
  string school;
public: 
  void set_data(string n, int i, string s){
    name = n;
    id = i;
    school = s;
  };
  int get_id(){
    return id;
  }
  string get_name(){
    return name;
  }
  string get_school(){
    return school;
  }
};

class heap{
  student h[HEAP_SIZE];
  int csize;
public:
  heap();
  void insert_heap(student newstd);
  int get_csize();
  void print_info(int n);
};

//initialize heap
heap::heap(){
  csize = 0;
};

//return the size of heap
int heap::get_csize(){
  return csize;
}

//print the nth element
void heap::print_info(int n){
  cout << "[" << h[n].get_name() << ", " << h[n].get_id() << ", " << h[n].get_school() << "]" << endl;
}

//insert elements in heap
void heap::insert_heap(student newstd){
  csize++;
  int k = csize;
  //make a space to insert newstd
  while((k!=1)&&(newstd.get_id()<h[k/2].get_id())){
    h[k] = h[k/2];
    k/=2;
  }
  h[k] = newstd;
  cout << csize << endl;
}

//function that print menu
void print_menu(){
  cout << "*********** MENU ***********\n";
  cout << "I : insert new element into queue\n" << "D : Delete element with smallest key from queue\n" << "C : Decrease key of element of queue\n" << "P : Print out all elements in queue\n" << "Q : Quit" << endl;
}

void INSERT(heap S, student x){
  S.insert_heap(x);
}

/*
void MINIMUM(S){

}

void EXTRACT-MIN(S){

}

void DECREASE-KEY(S, x, k){

}
*/


//main function start
int main(){
  heap my_heap;
  char choose;

  while(1){
    //print menu
    print_menu();

    //choose the menu
    cout << "Choose menu: ";
    cin >> choose;

    //INSERT
    if(choose == 'I'){
      student stu;
      string n;
      int i;
      string s;
      cout << "Enter name of element: ";
      cin >> n;
      cout << "Enter id of element: ";
      cin >> i;
      cout << "Enter school of element: ";
      cin >> s;
      stu.set_data(n,i,s);
      my_heap.insert_heap(stu);
      //INSERT(my_heap,stu);
      cout << my_heap.get_csize() << endl;
    }
    else if(choose == 'D'){

    }
    else if(choose == 'C'){

    }
    else if(choose == 'P'){
      cout << my_heap.get_csize() << endl;
      for(int i=1;i <= my_heap.get_csize();i++){
        my_heap.print_info(i);
      }
    }
    else if(choose == 'Q'){
      cout << "Thank you, Bye!" <<endl;
      return 0;
    }
    else{
      cout << "Wrong Input : Please choose again\n";
    }
  }
  return 0;
}
