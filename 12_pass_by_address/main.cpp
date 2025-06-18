#include <iostream>
#include <string>

void print_passed_address(int* addr) {
	std::cout << addr << " " << (addr ? std::to_string(*addr) : "nullptr") << "\n";
}

void print_passed_address_reference(int*& addr) {
	std::cout << addr << " " << (addr ? std::to_string(*addr) : "nullptr") << "\n";
}

void set_val_nullptr(int* addr) {
	// nothing is changed. only the addr value of the param object
	// was copied into addr
	addr = nullptr;
}

void set_ref_nullptr(int*& addr) {
	// addr is a int* lvalue reference or reference to a pointer.
	// which is bound to the param/addr
	addr = nullptr;
}

int main(int argc, char* argv[]) {
	int x{ 100 };
	int* x_ptr{ &x };

	print_passed_address(x_ptr);
	print_passed_address_reference(x_ptr);

	set_val_nullptr(x_ptr);
	print_passed_address(x_ptr);
	print_passed_address_reference(x_ptr);
	
	set_ref_nullptr(x_ptr);
	print_passed_address(x_ptr);
	print_passed_address_reference(x_ptr);
}