#include<iostream>

using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      if(!l1){
        return l2;
      }else if(!l2){
        return l1;
      }
      ListNode *result = new ListNode(0);
      ListNode *p = result;
      int digit = 0, overflow = 10, carryOver = 0;
      while(l1||l2){
        if(l1){
          digit += l1->val;
          l1 = l1->next;
        }
        if(l2){
          digit += l2->val;
          l2 = l2->next;
        }
        digit += carryOver;
        if (digit >= overflow){
          digit -= overflow;
          carryOver = 1;
        }else{
          carryOver = 0;
        }
        p->next = new ListNode(digit);
        p = p->next;
        digit = 0;
      }
      if(carryOver>0){
        p->next =  new ListNode(carryOver);
      }
      return result->next;
    }
};

int main(int argc, const char * argv[]){
  ListNode *l1 = new ListNode(0);
  ListNode *l2 = new ListNode(0);
  ListNode *p = l1;
  int num;
  cout << "Please enter the fist number, end with ENTER" << endl;
  while(cin.peek() != '\n'){
    cin >> num;
    p->next = new ListNode(num);
    p = p->next;
  }
  l1 = l1->next;
  p = l2;
  cin.ignore(10000, '\n');
  cout << "Please enter the second number, end with ENTER" << endl;
  while(cin.peek() != '\n'){
    cin >> num;
    p->next = new ListNode(num);
    p = p->next;
  }
  l2 = l2->next;
  Solution solution;
  ListNode *result = solution.addTwoNumbers(l1, l2);
  cout << "l1 is:" << endl;
  while(l1){
    cout<<l1->val<<" ";
    l1 = l1->next;
  }
  cout << "\nl2 is:" << endl;
  while(l2){
    cout<<l2->val<<" ";
    l2 = l2->next;
  }
  cout << "\nresult is:" << endl;
  while(result){
    cout<<result->val<<" ";
    result = result->next;
  }
}
