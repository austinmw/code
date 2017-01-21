/* Sample input:

The Alchemist
Paulo Coelho
248

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Book{
	protected:
		string title;
		string author;
	public:
		Book(string t,string a){
			title=t;
			author=a;
		}
		virtual void display()=0;

};

//Write MyBook class
class MyBook : public Book {
	public:
		MyBook(string title, string author, int price)
		: Book(title, author), m_price(price)
		{}
	int Price() {
		return m_price;
	}
	
	void display(void) {
		cout << "Title: " << title << endl;
		cout << "Author: " << author << endl;
		cout << "Price: " << m_price << endl;
		
	}
	
	private:
		int m_price;
	
};

int main() {
	string title,author;
	int price;
	getline(cin,title);
	getline(cin,author);
	cin>>price;
	MyBook novel(title,author,price);
	novel.display();
	return 0;
}

