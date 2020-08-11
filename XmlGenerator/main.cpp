#include <iostream>
#include "XmlBuilder.h"

/*
	Foo("Hello", 123, 123.4, "Hi");

	<Foo>
		<String>Hello</String>
		<Integer>123</Integer>
		<Float>123.4</Float>
		<String>Hi</Hi>
	</Foo>


	MyClass myclass;

	Foo("Hello", 123, 123.4, "Hi", myclass);
	// Compile Error. Unsupported Type
*/

int main(int argc, char* argv[])
{

	std::string hi = "Hi";
	foo("Hello", 33, 2.3, hi);
	
	struct Myclass {};
	Myclass myclass;

	foo("Hello", 123, 123.4, "Hi", myclass);
	return 0;
}