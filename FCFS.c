#include <unistd.h>
#include<stdio.h>
#include<fcntl.h>
using namespace std;
class Queue
{
  private:
  int front;
  int rear;
  int size;
  int *Q;
  public:
   
   Queue(){front=rear=-1;size=5000;Q=new int[size];}
   Queue(int size){front=rear=-1;this->size=size;Q=new int[this->size];}
   void enqueue(int x);
   int dequeue();
   void Display();
   int calResult(int n);
};
void Queue::enqueue(int x)
{
 if(rear==size-1)
  printf("Queue Full\n");
 else
 {
  rear++;
  Q[rear]=x;
 }
}
int Queue::dequeue()
{
 int x=-1;
 if(front==rear)
   printf("Queue is Empty\n");
 else
 {
  x=Q[front+1];
  front++;
 }
return x;
}
void Queue::Display()
{ 
   
	printf("---------------------------------------------------\n");
    printf("Quee : ");
    for(int i=front+1;i<=rear;i++)
         printf("%d ",Q[i]); 
    printf("\n");
    printf("---------------------------------------------------\n");
    
}

int Queue::calResult(int n)
{ 
	int distance = 0;
	
    int temp_answer  =  0 ;
	for(int i = 0;i<n-1;i++)
	{
	  temp_answer = Q[i] - Q[i+1];
	  if(temp_answer<0)
	  {
	  	temp_answer = -temp_answer;
	  	distance+= temp_answer;
	  	printf("Distance :");
		printf("%d\n",distance);
      }
      else
      {
      	distance+= temp_answer;
	  	printf("Distance :");
		printf("%d\n",distance);
	  }
	 } 
}

int main()
{
   /* #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif*/

    printf("Enter the number of requests to process...:->");
    int requests , temp =0;
    
    scanf("%d",&requests);
    printf("\n");
    int temp_requests = requests;
    int r = requests;
    Queue q(requests);
    printf("                INSERTION                      \n");
    while(requests--)    
    {
    	printf("Enter the request for the Queue :->");
    	scanf("%d",&temp);
    //	printf("\n");
    	if(temp>-1 && temp<5000)
    		q.enqueue(temp);
    	else
    		printf("Please enter requests under 5000 or above -1......!\n");
    }
    q.Display();
    q.calResult(r);
     
        printf("                    DELETION                      \n");
    while(temp_requests--)
    {
        int d = q.dequeue();
        printf("Request out form Ready Quee ->");
        printf("%d\n",d);
        q.Display();
    }
    return 0;
}
