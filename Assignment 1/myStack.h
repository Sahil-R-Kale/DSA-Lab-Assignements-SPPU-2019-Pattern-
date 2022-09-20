#define max 20
template <class T>
class Stack{
	T stack[max];
	int top;
public:
	Stack(){
		top=-1;
	}
	T showTop(){
		return stack[top];
	}
	bool isFull(){
		if(top==max-1)
			return true;
		else
			return false;
	}
	bool isEmpty(){
		if(top==-1)
			return true;
		else
			return false;
	}
	void push(T x){
		if(this->isFull())
			return;
		stack[++top]=x;
	}
	T pop(){
		if(this->isEmpty())
			return NULL;
		T a=stack[top--];
		return a;
	}
};
