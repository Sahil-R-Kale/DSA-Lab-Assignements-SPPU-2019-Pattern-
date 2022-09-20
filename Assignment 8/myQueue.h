
#define max 20
template <class T>
class Queue{
	T queue[max];
	int front,rear;
public:
	Queue(){
		front=rear=-1;
	}
	bool isFull(){
		if(rear==max-1)
			return true;
		else
			return false;
	}
	bool isEmpty(){
			if(front==-1 && rear==-1)
				return true;
			else
				return false;
		}
	void enque(T x){
		if(this->isFull())
			return;
		queue[++rear]=x;
		if(front==-1)
			front++;
	}
	T deque(){
		if(this->isEmpty())
			return -1;
		T a=queue[front];
		if(front==rear)
			front=rear=-1;
		else
			front++;
		return a;
	}
};
