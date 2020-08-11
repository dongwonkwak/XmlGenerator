#pragma once

#include <string>
#include <iostream>
#include <type_traits>
#include <assert.h>

template <typename T>
struct is_string
	: std::integral_constant<
	bool,
	std::is_same_v<char*, T> || std::is_same_v<const char*, T> ||
	std::is_same_v<std::string, T> || std::is_same_v<const std::string, T>
	> {};


template <typename T>
void foo(T t)
{
	if constexpr (std::is_integral_v<T>)
	{
		std::cout << "\t<Integer>" << t << "</Integer>\n";
	}
	else if constexpr (std::is_floating_point_v<T>)
	{
		std::cout << "\t<Float>" << t << "</Float>\n";
	}
	else if constexpr (is_string<T>::value)
	{
		std::cout << "\t<String>" << t << "</String>\n";
	}
	else
	{
		static_assert(false, "Compile Error. Unsupported Type");
	}
}


template <typename... Args>
void foo(Args&&... args)
{
	std::cout << "<Foo>\n";
	(foo(args), ...);
	std::cout << "</Foo>\n";
}