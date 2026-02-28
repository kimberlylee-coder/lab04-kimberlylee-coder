// heap.cpp
// Diba Mirza

#include "heap.h"
#include <iostream>
using std::cout;

Heap::Heap(vector<int>::iterator begin,vector<int>::iterator end){
  vdata=vector<int>(begin,end);

  for(int i=(vdata.size()/2)-1;i>=0;i--){
    int index=i;
    bool done=false;

    while(true){
      int left=2*index+1;
      int right=2*index+2;
      int smallest=index;

      if(left<vdata.size() && vdata[left]<vdata[smallest]){
        smallest=left;
      }

      if(right<vdata.size() && vdata[right]<vdata[smallest]){
        smallest=right;
      }

      if(smallest!=index){
        int temp=vdata[index];
        vdata[index]=vdata[smallest];
        vdata[smallest]=temp;
        index=smallest;
      }
      else{
        done=true;
      }
  

    }
    
  }
}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
vdata.push_back(value);

int index=vdata.size()-1;
while(index>0){
  int parentIndex=(index-1)/2;
  if(vdata[index]<vdata[parentIndex]){
    int i=vdata[index];
    vdata[index]=vdata[parentIndex];
    vdata[parentIndex]=i;

    index=parentIndex;
  }
  else{
    return;
  }
  
}
return;
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  vdata[0]=vdata[vdata.size()-1];
  vdata.pop_back();

  int index=0;
  while(true){
    int left=2*index+1;
    int right=2*index+2;
    int smallest=index;

    if(left<vdata.size() && vdata[left]<vdata[smallest]){
      smallest=left;
    }

    if(right<vdata.size() && vdata[right]<vdata[smallest]){
      smallest=right;
    }

    if(smallest!=index){
      int temp=vdata[index];
      vdata[index]=vdata[smallest];
      vdata[smallest]=temp;
      index=smallest;
    }
    else{
      return;
    }
  }
  return;
}

// Returns the minimum element in the heap
int Heap::top(){
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.empty();
}
    