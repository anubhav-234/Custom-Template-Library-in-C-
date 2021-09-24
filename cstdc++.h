// ------------------------------------------Header Files Important in c++---------------------------------------
#include<bits/stdc++.h>
using namespace std;
//---------------------------------------------- Macros used In C++--------------------------------------------------
#define lld long long int
#define ld long int
#define v_d vector<int>
#define v_ld vector<long int>
#define v_lld vector<long long int>
#define fore(i,k,n) for(auto i=k;i<n;i++)
#define inf INT_MAX
#define l_inf LONG_MAX
#define ll_inf LLONG_MAX
#define least INT_MIN
#define l_least LONG_MIN
#define ll_least LLONG_MIN
#define u_map unordered_map
#define o_map map
#define o_set set
#define u_set unordered_set
//---------------------------------------------Some Important Mathmatical Functions ---------------------------------------------------
template<typename X>
vector<X> cfind_primes(X N)
{
   vector<bool >isprime(inf, true);
    vector<X>prime;
    vector<X>SPF(inf);
    isprime[0] = isprime[1] = false ;
  for (X i=2; i<N ; i++)
    { if (isprime[i]){prime.push_back(i);SPF[i] = i;}
        for (X j=0;j < (int)prime.size() && i*prime[j] < N && prime[j] <= SPF[i];j++)
        { isprime[i*prime[j]]=false;SPF[i*prime[j]] = prime[j] ;}
    }
    return prime;
}
template<typename X>
void cswap(X & x,X & y)
{
    X temp=x;
    x=y;
    y=temp;

}
//-------------------------------------------------------------------------------------------------------------
//-----------------------------Basic Operation Functions---------------------------------------------------------
template<typename X>
void cprint(X a)
{
  cout<<a<<endl;
}
//------------------------Some functions for Vectors--------------------------------------------------------------
template<typename X>
void cprint(vector<X> v)
{
  for(auto i: v)cout<<i<<" ";
  cout<<endl;
}
template<typename X>
void cincrement(vector<X> & arr,X s=1)
{
   for(int i=0;i<arr.size();i++)arr[i]+=s;
}
template<typename X>
void cdecrement(vector<X> & arr,X s=1)
{
  for(int i=0;i<arr.size();i++)arr[i]-=s;
}
template<typename X>
X cmax_element(vector<X> & arr)
{
    X temp=INT_MIN;
  for(auto i : arr)
  {
    if(temp<i)temp=i;
  }
  return temp;
}
template<typename X>
X cmin_element(vector<X> & arr)
{
    X temp=INT_MAX;
  for(auto i : arr)
  {
    if(temp>i)temp=i;
  }
  return temp;
}
//-------------------------------------------------Array_Custom_Implementation-------------------------------------
template<typename X,typename Y>
void cprint(X arr[],Y n ,Y a=0){
    fore(i,a,n){
      cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
  }
template<typename X,typename Y>
void cmake_zero(X arr[],Y n,Y a=0)
  {
    fore(i,a,n){
      arr[i]=0;
    }

    return;
  }
template<typename X,typename Y>
void cincrement(X arr[],Y n,X s=1)
{
   fore(i,0,n){
     arr[i]+=s;
   }
}
template<typename X,typename Y>
void cdecrement(X arr[],Y n,X s=1)
{
  fore(i,0,n){
    arr[i]-=s;
  }
}
template<typename X,typename Y>
void crprint(X arr[],Y n)
{
   for(Y i=n-1;i>=0;i--)
   {
     cout<<arr[i]<<" ";
   }
   cout<<endl;
}
template<typename X,typename Y>
void creverse(X arr[],Y n){
  Y k=n/2;
  fore(i,0,k){
    cSwap(arr[i],arr[n-1-i]);
  }
}
template<typename X,typename Y>
X cmax_element(X arr[],Y n)
{
  X temp=INT_MIN;
  fore(i,0,n)
  {
    if(temp<arr[i])temp=arr[i];
  }
  return temp;
}
template<typename X,typename Y>
X cmin_element(X arr[],Y n){
  X temp=INT_MAX;
  fore(i,0,n){
    if(temp>arr[i])temp=arr[i];
  }
  return temp;
}

//-------------------------------------------------Bubble_Sort---------------------------------------------------------------
  template<typename X,typename Y>
  void cbubble_sort(X arr[],Y n)
  {
    for(Y i=0;i<n;i++)
      {
          bool value=true;
          for(Y j=0;j<n-i-1;j++)
          {
              if(arr[j]>arr[j+1])
              {
                  cswap(arr[j],arr[j+1]);
                  value=false;
              }
          }
          if(value)break;
      }
  }
  //-------------------------------------------------------------------------------------------------------------------
  //----------------------------------------------Insertion_Sort----------------------------------------------------------------
template<typename X,typename Y>
  void cinsertion_sort(X arr[],Y n)
  {
    for(Y i=1;i<n;i++)
      {
          X temp=arr[i];
          bool val=false;
          for(Y j=0;j<=i;j++)
          {
              if(!val)
              {
                  if(arr[i]<=arr[j])
              {
                  temp=arr[i];
                  val=true;
              }
          }
              if(val)
              {
                  X temp1=arr[j];
                  arr[j]=temp;
                  temp=temp1;
              }
          }
      }
  }
  //---------------------------------------------Selection_Sort--------------------------------------------------------------------
template<typename X,typename Y>
  void cselection_sort(X arr[],Y n)
  {
    for(Y i=0;i<n;i++)
      {
          X min_value=INT_MAX;
          Y index;
          for(Y j=i;j<n;j++)
          {
              if(min_value>arr[j])
              {
                  index=j;
                  min_value=arr[j];
              }
          }
          cswap(arr[i],arr[index]);
      }
  }
  //---------------------------------------------------------------------------------------------------------------------------
  //--------------------------------------------Merge Sort Algorithm-----------------------------------------------------
template<typename X,typename Y>
void merge(X *Arr, X start, Y mid, Y end) {

	X temp[end - start + 1];


	Y i = start, j = mid+1, k = 0;


	while(i <= mid && j <= end) {
		if(Arr[i] <= Arr[j]) {
			temp[k] = Arr[i];
			k += 1; i += 1;
		}
		else {
			temp[k] = Arr[j];
			k += 1; j += 1;
		}
	}


	while(i <= mid) {
		temp[k] = Arr[i];
		k += 1; i += 1;
	}


	while(j <= end) {
		temp[k] = Arr[j];
		k += 1; j += 1;
	}


	for(i = start; i <= end; i += 1) {
		Arr[i] = temp[i - start];
	}
}


template<typename X,typename Y>
void cmerge_sort(X *Arr, Y start, Y end) {

	if(start < end) {
		Y mid = (start + end) / 2;
		cmerge_sort(Arr, start, mid);
		cmerge_sort(Arr, mid+1, end);
		merge(Arr, start, mid, end);
	}
}
//-----------------------------------------------------------Quick_Sort Algo------------------------------------------------------------------------------
template<typename X,typename Y>
Y partition (X arr[], Y low, Y high)
{
    X pivot = arr[high];
    Y i = (low - 1);

    for (Y j = low; j <= high- 1; j++)
    {

        if (arr[j] <= pivot)
        {
            i++;
            cswap(arr[i], arr[j]);
        }
    }
    cswap(arr[i + 1], arr[high]);
    return (i + 1);
}
template<typename X,typename Y>
void cquick_sort(X a[], Y p, Y r)
{
    if(p < r)
    {
        Y q;
        q = partition(a, p, r);
        cquick_sort(a, p, q-1);
        cquick_sort(a, q+1, r);
    }
}
//---------------------------------------------Linear Search -------------------------------------------------------------------
template<typename X,typename Y>
Y clinear_search(X arr[],Y n,X e)
{

  for(auto i=0;i<n;i++)
  {
    if(arr[i]==e)
      return i;
  }
  return -1;
}
template<typename X>
lld clinear_search(vector<X> arr,X e)
{
  for(auto i=0;i<arr.size();i++)
  {
    if(arr[i]==e)return i;
  }
  return -1;
}
//----------------------------------------------Binary_Search-------------------------------------------------------------------------
template<typename X,typename Y>
Y cbinary_search(X arr[],Y n,X e)
{
  Y left=0,right=n-1;
  while(left<=right)
  {
    Y mid=(left+right)/2;

    if(arr[mid]==e)return mid;

    else if(arr[mid]>e){
      right=mid-1;
    }
    else{
      left=mid+1;
    }
  }
  return -1;

}
template<typename X>
lld cbinary_search(vector<X> arr,X e)
{
  auto left=0,right=arr.size()-1;
  while(left<=right)
  {
    auto mid=(left+right)/2;

    if(arr[mid]==e)return mid;

    else if(arr[mid]>e){
      right=mid-1;
    }
    else{
      left=mid+1;
    }
  }
  return -1;
}
//-----------------------------------------Tarnery Search ------------------------------------------------------------------------
template<typename X,typename Y>
Y cternary_search(X arr[],Y n,X target)
{
   Y left=0,right=n-1;
   while(left<=right)
   {
       Y mid1=left+(right-left)/3;

       Y mid2=right-(right-left)/3;

       if(arr[mid1]==target || arr[mid2]==target)
       return arr[mid1]==target ? mid1 : mid2;

       else if(arr[mid1]>target)
       right=mid1-1;

       else if(arr[mid2]<target)
       left=mid2+1;

       else
       {
           left=mid1+1;
           right=mid2-1;
       }
   }
   return -1;

}
template<typename X,typename Y>
lld cternary_search(vector<X> & arr,X target)
{
  auto n=arr.size();
  Y left=0,right=n-1;
  while(left<=right)
  {
      Y mid1=left+(right-left)/3;

      Y mid2=right-(right-left)/3;

      if(arr[mid1]==target || arr[mid2]==target)
      return arr[mid1]==target ? mid1 : mid2;

      else if(arr[mid1]>target)
      right=mid1-1;

      else if(arr[mid2]<target)
      left=mid2+1;

      else
      {
          left=mid1+1;
          right=mid2-1;
      }
  }
  return -1;
}


// ---------------------------------------------------- Singly Linked List ------------------------------------------------------------------
template<typename X>
class Snode{
public:
  X data;
  Snode<X> * next;
  Snode(X data){
    this->data=data;
    this->next=NULL;
  }
};
template<typename X>
class clist{
  private :
  Snode<X>* head;
public:
  clist(){
    head=NULL;
  }
  void push_back(X data)
  {
    if(head==NULL)
    {
      head=new Snode<X>(data);
      return;
    }
    else
    {
      Snode<X>*temp=head;
      while(temp->next!=NULL)
      temp=temp->next;
      temp->next=new Snode<X>(data);
      return;
    }
  }
  void push_back(vector<X> val){
    for(auto i : val){
      this->push_back(i);
    }
    return;
  }
  void push_front(X data){
    if(head==NULL){
      head=new Snode<X>(data);
      return;
    }
    else
    {
      Snode<X>*temp=head;
      head=new Snode<X>(data);
      head->next=temp;
      return;
    }
  }
  void push_front(vector<X> ans){
  for(X i=ans.size()-1;i>=0;i--)
    this->push_front(ans[i]);
    return;
  }
  void pop_back()
  {
    if(head==NULL){
      cout<<" @@  No element to remove  @@";
      return;
    }
    else{
      Snode<X>*temp=head;
      if(temp->next==NULL)head=NULL;
      else
      {
        while(temp->next->next)
        temp=temp->next;
        temp->next=NULL;
      }
    }
    return;
  }
  void pop_front(){
    if(head==NULL)
    {
      cout<<"@@ No element to remove @@";
      return;
    }
    else{
      Snode<X>*temp=head;
      head=head->next;
      delete temp;
    }
  }
  void print(){
    Snode<X> *temp=head;
    while(temp){
      cout<<temp->data<<" ";
      temp=temp->next;
    }
    cout<<endl;
  }
  X size()
  {
    Snode<X> * temp=head;
    X n=0;
    while(temp)
    {
      n++;
      temp=temp->next;
    }
    return n;
  }
  Snode<X> * get_head()
  {
    return head;
  }
  Snode<X> * get_tail()
  {
    Snode<X> * temp=head;
    while(temp->next)
    temp=temp->next;
    return temp;
  }
  void reverse()
  {
    if(head==NULL)return;
     Snode<X> *temp1=NULL,*temp2=head,*temp3;

     while(temp2){
       temp3=temp2->next;
       temp2->next=temp1;
       temp1=temp2;
       temp2=temp3;

     }
     head=temp1;


  }
  Snode<X> * find(X data)
  {
    Snode<X> * x=head;
    while(x)
    {
      if(x->data==data)return x;
      x=x->next;
    }
    return NULL;
  }
  X front(){
    if(head==NULL){
      cout<<" @@ No front element @@ ";
      return;
    }
    else return head->data;
  }
  X back(){
    if(head==NULL){
      cout<<" @@ No front element @@ ";
      return;
    }
    else{
      Snode<X> * temp=head;
      while(temp->next)temp=temp->next;
      return temp->data;
    }
  }
  void increase(X t=1){
    Snode<X> * temp=head;
    if(head==NULL)return;
    else
    {
      while(temp){
        temp->data+=t;
        temp=temp->next;
      }
    }
  }
  void decrease(X t=1){
    Snode<X> * temp=head;
    if(head==NULL)return;
    else
    {
      while(temp){
        temp->data-=t;
        temp=temp->next;
      }
    }
  }




};

//-----------------------------------------------------------------------------------------------------------------------------------------
template<typename X>
Snode<X> * create_list(vector<X> numb){
   clist<X> list;
   list.push_back(numb);
   return list.get_head();
}
template<typename X>
clist<X> ccreate_list(vector<X> numb){
   clist<X> list;
   list.push_back(numb);
   return list;
}
// --------------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------Doubly_Linked_List--------------------------------------------------------------------------------------
template<typename X>
class Dnode{
public:
  X data;
  Dnode<X>*prev;
  Dnode<X> * next;
  Dnode(X data){
    this->data=data;
    prev=NULL;
    next=NULL;
  }
};
template<typename X>
class cdl_list{
  private :
  Dnode<X>*head;
  public:
  cdl_list(){
    head=NULL;
  }
  void push_back(X data){
    if(head==NULL){
      head=new Dnode<X>(data);
      return;
    }
    else
    {
      Dnode<X>* temp=head;
      while(temp->next)temp=temp->next;
      temp->next=new Dnode<X>(data);
      temp->next->prev=temp;
      return;
    }
  }
  void push_front(X data){
    if(head==NULL)
    {
      head=new Dnode<X>(data);
      return;
    }
    else
    {
      head->prev=new Dnode<X>(data);
      head->prev->next=head;
      head=head->prev;
      return;
    }
  }
  void push_back(vector<X> numb){
    for(auto i :numb)this->push_back(i);
  }

  void push_front(vector<X> numb){
    for(int i=numb.size()-1;i>=0;i--){
      this->push_front(numb[i]);
    }
  }
  void pop_front(){
    if(head==NULL){
      cout<<" @@ No element to delete @@ ";
      return;
    }
    else
    {
      Dnode<X>*temp=head;
      head=head->next;
      head->prev=NULL;
      delete temp;
      return;
    }
  }
  void pop_back(){
    if(head==NULL){
      cout<<" @@ No element to delete @@";
      return;
    }
    else
    {
      Dnode<X>*temp=head;
      if(head->next==NULL)head=NULL;
      else
      {
        while(temp->next->next)temp=temp->next;
        delete temp->next;
        temp->next=NULL;
      }
    }
  }
  void print(){
    Dnode<X>* temp=head;

    while(temp){
      cout<<temp->data<<" ";
      temp=temp->next;
    }
    return;
  }



};
//----------------------------------------------------Tree------------------------------------------------------------------------------------------------------------------------
template<typename X>
class Tnode{
public:
  X data;
  Tnode<X> * left;
  Tnode<X> * right;
  Tnode(X data){
    this->data=data;
    this->left=NULL;
    this->right=NULL;
  }
};
template<typename X>
class ctree{
private :
//Tnode<X>*root;
queue<Tnode<X>*> q;
public:
  Tnode<X>*root;
  ctree(){
    root=NULL;
  }
  void insert(X data)
  {
    if(root==NULL){
      root=new Tnode<X>(data);
      q.push(root);
    }
    else
    {
      Tnode<X> * front=q.front();
      if(front->left==NULL){
        front->left=new Tnode<X>(data);
        q.push(front->left);
        return;
      }
      if(front->right==NULL){
        front->right=new Tnode<X>(data);
        q.push(front->right);
        q.pop();
        return;
      }
    }
  }
  void insert(vector<X> v)
  {
    for(auto i : v)
    {
        this->insert(i);
    }
  }
  void pre_order(){
    Tnode<X> * temp=root;
    if(root){
      cout<<root->data<<" ";
      root=temp->left;
      this->pre_order();
      root=temp->right;
      this->pre_order();
      root=temp;

    }

  }
  void in_order(){
    Tnode<X> * temp=root;
    if(root){

      root=temp->left;
      this->in_order();
      root=temp;
      cout<<root->data<<" ";
      root=temp->right;
      this->in_order();
      root=temp;

    }

  }
  void post_order(){
    Tnode<X> * temp=root;
    if(root){

      root=temp->left;
      post_order();

      root=temp->right;
      post_order();
      root=temp;
      cout<<root->data<<" ";

    }

  }

  void dfs(){
    Tnode<X>*temp=root;
    if(root)
    {
      cout<<root->data<<" ";
      root=temp->left;
      dfs();
      root=temp->right;
      dfs();
    }
  }
  void bfs(){
    queue<Tnode<X>*> q;
    q.push(root);
    while(q.size())
    {
      Tnode<X>* temp=q.front();
      q.pop();
      cout<<temp->data<<" ";
    if(temp->left)q.push(temp->left);
    if(temp->right)q.push(temp->right);
    }
  }
 void traversals()
 {
   cout<<"> Pre_order Traversal :  ";
   this->pre_order();

   cout<<"\n\n> In_order Traversal :  ";
   this->in_order();
   cout<<"\n\n> Post_order Traversal :  ";
   this->post_order();
   cout<<"\n\n> Level_order Traversal :  ";
   this->bfs();

 }
Tnode<X> * get_root(){
  return root;
}





};
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
