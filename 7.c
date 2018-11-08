#define MAX 50
struct queue
{
  int ele[MAX];
  int front,rear;
};

void insert(struct queue *,int);
int removeElement(struct queue *);
int isEmpty(struct queue *);
int isFull(struct queue *);
void displayQueue(struct queue *);

void main()
{
	int element,choice;
	struct queue q;
	q.rear=MAX-1;
	q.front=MAX-1;
	do
	{
	 printf("\n 1-Insert an element into the queue");
	 printf("\n 2-Remove an element from the queue");
	 printf("\n 3-Display the elements of the queue");
	 printf("\n 4-Exit");
	 printf("\n Enter your choice: \t");
	 scanf("%d",&choice);
	 switch (choice)
	 {
	  case 1:
		  if(isFull(&q))
			  printf("\n The queue is full");
		  else
		  {
		   printf("\n Enter the element to be inserted : ");
		   scanf("%d",&element);
		   insert(&q,element);
		  }
		   break;
	   case 2:
		  if(isEmpty(&q))
			printf("\n Queue is empty");
		  else
			printf("\n Element removed = %d",removeElement(&q));
		  break;
	    case 3:
		  displayQueue(&q);
		  break;
	    case 4:
		  exit(0);
		  break;
	    default:
		  printf("\n Please enter your choice correctly");
		  break;
	   }
	 }while(choice!=4);
}

void insert(struct queue *pq, int e)
{
	if(pq->rear==MAX-1)
			  pq->rear=0;
	else
		pq->rear++;
	pq->ele[pq->rear]=e;
}

int removeElement(struct queue *pq)
{
	if(pq->front==MAX-1)
			pq->front=0;
	else
		  pq->front++;
	return (pq->ele[pq->front]);
}

int isEmpty(struct queue *pq)
{
	  if(pq->rear==pq->front)
			 return 1;
	  else
			 return 0;
}

int isFull(struct queue *pq)
{
	int i;
	if(pq->rear ==(MAX-1))
			i=0;
	else
		  i=pq->rear+1;
	if(i==pq->front)
			return 1;
	else
		 return 0;
}

void displayQueue(struct queue *pq)
{
	int i;
	if(isEmpty(pq))
			printf("\n The queue is empty");
	else
	{
			if(pq->front==MAX-1)
						i=0;
			else
					i=pq->front+1;

			printf("\n Elements of the queue from front to rear are : ");
			while(i!=pq->rear)
			{
					printf("\t %d",pq->ele[i]);
					if(i==MAX-1)
						  i=0;
					else
						i++;
			}
			printf("\t %d",pq->ele[i]);
	}
}
