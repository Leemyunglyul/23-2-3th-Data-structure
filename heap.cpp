#include "heap.h"
#include <iostream>
#include <string>

using namespace std;

string PriorityQueue::printPQ()
{
    string answer;
    for (int i = 1; i <= size; i++)
        answer += to_string(heap[i].value) + " ";
    return answer;
}

bool PriorityQueue::insert(int value)
{ 
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    if (size == MAX_SIZE){
        return 0;
    }
    int i=++size;
    while ((i != 1) && (value > heap[i/2].value)) {
        heap[i].value = heap[i/2].value;
        i /= 2;
    }
    heap[i].value = value;

    return 1;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

bool PriorityQueue::removeMax()
{
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    if (size == 0) {
        return 0;
    }
    int temp=heap[size--].value;
    int parent = 1;
    int child = 2;

    while(child<=size){
      if(child<size&& heap[child].value<heap[child+1].value)
        child++;

      if(temp>=heap[child].value)
        break;

      heap[parent]=heap[child];

      parent=child;
      child*=2;
    }
    heap[parent].value=temp;

    return 1;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

pq_element PriorityQueue::getMax()
{
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    return heap[1];
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}

bool PriorityQueue::empty()
{
    /////////////////////////////////////////////////////////
    //////////  TODO: Implement From Here      //////////////
    if (size == 0) return 1;
    else return 0;
    ///////////      End of Implementation      /////////////
    /////////////////////////////////////////////////////////
}
