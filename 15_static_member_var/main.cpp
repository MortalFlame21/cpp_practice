#include <iostream>
#include <string>

class Book {
public:
	Book(std::string title);
	
	static int get_latest_id() { return s_id; };
	int get_id() { return m_id; }
	const std::string& get_title() { return m_title; }
	void print() const;
private:
	// static inline ^c++17 
	static inline int s_id{};
	std::string m_title{};
	int m_id{};
};

Book::Book(std::string title = "No title")
	: m_title{ title }, m_id{ s_id++ }
{
	print();
}

void Book::print() const {
	std::cout << m_id << ": " << m_title << "\n";
}

int main(int argc, char* argv[]) {
	Book b1{};
	Book b2{};
	std::cout << "latest id: " << Book::get_latest_id();
}