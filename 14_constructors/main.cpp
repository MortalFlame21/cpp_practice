#include <iostream>
#include <string>

class Employee {
public:
	Employee() = default;
	Employee(std::string f_name, std::string l_name, int age);
	// Employee(std::string f_name, std::string l_name, int age, int employee_id);

	void set_first_name(std::string f_name);
	void set_last_name(std::string l_name);
	void set_age(int age);
	void set_employee_id(int employee_id);

	const std::string& get_first_name() const;
	const std::string& get_last_name() const;
	const int& get_age() const;
	const int& get_employee_id() const;
protected:
private:
	// static int  s_employee_id{};
	std::string m_f_name{ "John" };
	std::string m_l_name{ "Doe" };
	int			m_age{};
	int			m_employee_id{};
};

Employee::Employee(std::string f_name, std::string l_name, int age)
	: m_f_name{f_name} , m_l_name{l_name} , m_age{age}
{

}

// Employee::Employee(std::string f_name, std::string l_name, int age, int employee_id);

void Employee::set_first_name(std::string f_name) {
	m_f_name = f_name;
}

void Employee::set_last_name(std::string l_name) {
	m_l_name = l_name;
}

void Employee::set_age(int age) {
	m_age = age;
}

void Employee::set_employee_id(int employee_id) {
	m_employee_id = employee_id;
}

const std::string& Employee::get_first_name() const {
	return m_f_name;
}

const std::string& Employee::get_last_name() const {
	return m_l_name;
}

const int& Employee::get_age() const {
	return m_age;
}

const int& Employee::get_employee_id() const {
	return m_employee_id;
}

void print_employee(const Employee& e) {
	std::cout << "Employee: " << e.get_first_name() << " "
		<< e.get_last_name() << ", " << e.get_age()
		<< ", " << e.get_employee_id() << ".\n";
}

int main(int argc, char* argv[]) {
	Employee e1{ "John", "Pork", 21 };
	print_employee(e1);

	Employee e2{};
	print_employee(e2);
	e2.set_first_name("Tim");
	e2.set_last_name("Cheese");
	e2.set_age(420);
	print_employee(e2);
}

