// palindrome test using stacks and queues
// Sample input: racecar

// should take a look at: #include <list>,<stack>,<queue>,<deque> (double ended queue) 
#include <iostream>
using namespace std;



// STACK/QUEUE OUTPERFORMS VECTOR (probably because implementing queue with vector is inefficient)
#include <stack>
#include <queue>
class Solution1 {
	public:
	stack<char> s;
	queue<char> q;	
	
	// inserts element at the top
	void pushCharacter(char c){
		s.push(c);
	}
	
	// removes the top element
	char popCharacter() {
		if(!s.empty()){
			char top = s.top();
			s.pop();
			return top;
		}
		return '\0';
	}
	
	
	// inserts element at the end
	void enqueueCharacter(char c) {
		q.push(c);
	}
	
	// removes the first element
	char dequeueCharacter() {
		if (!q.empty()){
		char front = q.front();
		q.pop();
		return front;
		}
		return '\0';
	}
};





#include <vector>
class Solution2 {
	public:
		// stack: LIFO, queue: FIFO
		vector<char> stack,queue;	
		

	// add to top of stack (last index)	
	void pushCharacter(char ch){
		stack.push_back(ch);    
	}
	
	// remove and return from top of stack (last index)   
	char popCharacter(){
		if (stack.size() > 0) {	
			char top = stack.back();	
			stack.pop_back();
			return top;
		}
		return '\0';
	}
	
	// add to queue (first index)
	void enqueueCharacter(char ch){
		queue.insert(queue.begin(), ch);
	}
	
	// remove from queue (last index)
	char dequeueCharacter(){
		if (queue.size() > 0) {
			char dequeue = queue.back();
			queue.pop_back();
			return dequeue;
		}
		return '\0';
	}	
};

int main() {
	// read the string s.
	string s;
	getline(cin, s);
	
  	// create the Solution class object p.
	Solution1 obj;
	

	// push/enqueue all the characters of string s to stack.
	for (int i = 0; i < s.length(); i++) {
		obj.pushCharacter(s[i]);
		obj.enqueueCharacter(s[i]);
	}
	
	bool isPalindrome = true;
	
	// pop the top character from stack.
	// dequeue the first character from queue.
	// compare both the characters.
	for (int i = 0; i < s.length() / 2; i++) {
		if (obj.popCharacter() != obj.dequeueCharacter()) {
			isPalindrome = false;
			
			break;
		}
	}
	
	// finally print whether string s is palindrome or not.
	if (isPalindrome) {
		cout << "The word, " << s << ", is a palindrome.";
	} else {
		cout << "The word, " << s << ", is not a palindrome.";
	}
	
	
	
	return 0;
	
	
	
}

/*
// STACK TEST
obj.pushCharacter('a');
obj.pushCharacter('b');
cout << "Entire stack: ";
for (auto i = obj.stack.begin(); i != obj.stack.end(); ++i)
	std::cout << *i << ' '; cout << endl;
cout << "stack size after two pushes: " << obj.stack.size() << endl;
cout << "pop: " << obj.popCharacter() << endl;
cout << "stack size after one pop: " << obj.stack.size() << endl;
cout << "pop: " << obj.popCharacter() << endl;
cout << "pop: " << obj.popCharacter() << endl << endl;
	
// QUEUE TEST
obj.enqueueCharacter('x');
obj.enqueueCharacter('y');
cout << "Entire queue: ";
for (auto i = obj.queue.begin(); i != obj.queue.end(); ++i)
	std::cout << *i << ' '; cout << endl;	
cout << "queue size after two pushes: " << obj.queue.size() << endl;
cout << "dequeue: " << obj.dequeueCharacter() << endl;
cout << "queue size after one dequeue: " << obj.queue.size() << endl;
cout << "dequeue: " << obj.dequeueCharacter() << endl;
cout << "dequeue: " << obj.dequeueCharacter() << endl;
*/

/* 
Vector member functions:
	Iterators:
	begin
	Return iterator to beginning (public member function )
	end
	Return iterator to end (public member function )
	rbegin
	Return reverse iterator to reverse beginning (public member function )
	rend
	Return reverse iterator to reverse end (public member function )
	cbegin 
	Return const_iterator to beginning (public member function )
	cend 
	Return const_iterator to end (public member function )
	crbegin 
	Return const_reverse_iterator to reverse beginning (public member function )
	crend 
	Return const_reverse_iterator to reverse end (public member function )

	Capacity:
	size
	Return size (public member function )
	max_size
	Return maximum size (public member function )
	resize
	Change size (public member function )
	capacity
	Return size of allocated storage capacity (public member function )
	empty
	Test whether vector is empty (public member function )
	reserve
	Request a change in capacity (public member function )
	shrink_to_fit 
	Shrink to fit (public member function )

	Element access:
	operator[]
	Access element (public member function )
	at
	Access element (public member function )
	front
	Access first element (public member function )
	back
	Access last element (public member function )
	data 
	Access data (public member function )

	Modifiers:
	assign
	Assign vector content (public member function )
	push_back
	Add element at the end (public member function ) 
	pop_back 
	Delete last element (public member function ) 
	insert 
	Insert elements (public member function ) 
	erase 
	Erase elements (public member function ) 
	swap 
	Swap content (public member function ) 
	clear 
	Clear content (public member function ) 
	emplace  
	Construct and insert element (public member function ) 
	emplace_back  
	Construct and insert element at the end (public member function ) 
 
	Allocator:
	get_allocator 
	Get allocator (public member function )
*/




/* Explanation:
queue and stack are higher level containers. than deque or list or vector. By this I mean that you CAN build a queue or stack out of the lower level containers.

For example:

	std::stack<int, std::deque<int> > s;
	std::queue<double, std::list<double> > q;
Will build a stack of ints using a deque as the underlying container and a queue of doubles using a list as the underlying container.

You can think of s as a restricted deque and q as a restricted list.

All that is necessary is that the lower level container implements the methods needed by the higher level container. These are back(), push_back() and pop_back() for stack and front(), back(), push_back() and pop_front() for queue.

See stack and queue for more detail.

With respect to the deque, it is much more than a queue where you can insert at both ends. In particular, it has the random access operator[]. This makes it more like a vector, but a vector where you can insert and delete at the beginning with push_front() and pop_front().

See deque for detail.
*/