#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	
}

/*

new/delete operations are said to take place on the free-store.
malloc/free operations use the heap. 





In Herb's book "Exceptional C++", he defines:

	Heap: A dynamic memory area that is allocated/freed by the malloc/free functions.

	Free Store: A dynamic memory area that is allocated/freed by new/delete.

	Its possible for new and delete to be implemented in terms of malloc and free, so technically, they could be the same memory area. However, as the standard doesn't specify this, its best to treat them separatly, and not to mix malloc/delete or new/free.






The C++ standard refers to "free store". It does not specify how it is implemented. "heap" is a specific implementation technique. Implementations are free to manage memory as they see fit, although in practice most implementations use a heap. So in most cases, heap and free store are interchangable.

The distinction between malloc/free and new/delete is one of language.
C supports malloc/free but has no concept of new/delete, nor constructors and destructors. C++ introduces the concept of new/delete, constructors and destructors. Because C++ is an extension of C, malloc/free are still available, but are not the C++ way of doing things.

As to whether both refer to the same memory region, that is implementation specific, but in general the answer is yes. Some C++ new/delete implementations will use malloc/free under the covers, some may call OS specific heap management routines if the OS provides them, while other implementations will code new/delete from scratch for efficiency.

*/



/*
My Mail:

	Dear Mr Stroustrup,

	Sorry to disturb you again. You have mentioned several times in the TC++PL that 'new' allocates memory from the 'free store (or heap)'. There has been a huge cry on the C++ community at Orkut (that I am moderating) as to whether free-store is the same as heap. The argument given against is that Mr Herb Sutter has mentioned that the free-store is different from the heap: 

	http://www.gotw.ca/gotw/009.htm

	and that global 'new' has nothing to do with the heap. 

	So, if so, why has TC++PL used 'free store (or heap)' instead of mentioning the use of 'heap' separately.

	Waiting anxiously for the response.

	Regards,
	Zaman Bakshi

	His Reply:


	Note that Herb says: "Note about Heap vs. Free Store: We distinguish between "heap" and "free store" because the draft deliberately leaves unspecified the question of whether these two areas are related. For example, when memory is deallocated via operator delete, 18.4.1.1 states:"

	In other word, the "free store" vs "heap" distinction is Herb's attempt to distinguish malloc() allocation from new allocation.

	>
	> So, if so, why has TC++PL used 'free store (or heap)' instead of
	> mentioning the use of 'heap' separately.

	Because even though it is undefined from where new and malloc() get their memory, they typically get them from exactly the same place. It is common for new and malloc() to allocate and free storage from the same part of the computer's memory. In that case, "free store" and "heap" are synonyms. I consistently use "free store" and "heap" is not a defined term in the C++ standard (outside the heap standard library algorithms, which are unrelated to new and malloc()). In relation to new, "heap" is simply a word someone uses (typically as a synonym to "free store") - usually because they come from a different language background.
	
*/