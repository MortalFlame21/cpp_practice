#include <iostream>

int nine_plus_ten() {
	return 21;
}

int ret_num(int num) {
	return num;
}

int overload_ret_num(int num = 69) {
	if (num == 69) return num; 
	return num * 2;
}

int overload_ret_num(bool to_double, int num = 69) {
	if (to_double) return num * 2; 
	return num;
}

int main(int argc, char* argv[]) {
	{
		// this would try to output the function pointer (address)
		// but it would not know, however, vs compiler can.
		std::cout << nine_plus_ten << "\n";
		std::cout << &nine_plus_ten << "\n";
		std::cout << nine_plus_ten() << "\n";
	
		std::cout << ret_num << "\n";
		std::cout << &ret_num << "\n";
		std::cout << ret_num(69) << "\n";
	
		int (* const func_ptr_1)() { &nine_plus_ten };
		std::cout << func_ptr_1 << "\n";
		std::cout << func_ptr_1() << "\n";
	
		int (*func_ptr_2)(int) { &ret_num };
		std::cout << func_ptr_2 << "\n";
		std::cout << func_ptr_2(69) << "\n";
	
		func_ptr_2 = nullptr;
		std::cout << func_ptr_2 << "\n\n";
		// careful about nullptr!
		// std::cout << func_ptr_2(69) << "\n";
	}

	{
		int (*func_ptr_3)(int) { overload_ret_num };
		int (*func_ptr_4)(bool, int) { overload_ret_num };
		
		std::cout << func_ptr_3 << "\n";
		std::cout << func_ptr_4 << "\n";

		std::cout << func_ptr_3(5) << "\n";
		std::cout << func_ptr_4(true, 5) << "\n";
		// default arguments don't work :(
		// std::cout << func_ptr_4(true) << "\n";

	}

}