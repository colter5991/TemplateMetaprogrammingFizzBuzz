#include <iostream>
#include <type_traits>

// A string that is easy to work with in templates
template <char... chars>
struct MetaString {
	// A meta function to append another string to this string
	template <typename string>
	struct Append {};

	// A template specialization is used so we can access the 
	// individual characters of the string
	template <char... c>
	struct Append<MetaString<c...> > {
		typedef MetaString<chars..., c...> value;
	};

	// Convert the MetaString to a C style string that can be printed
	static const char c_str[sizeof...(chars) + 1];
};


// MetaFunction to convert an integer to a string
template <int x>
struct IntToString {

	typedef typename IntToString<x/10>::value::template Append<MetaString<'0' + (x%10)> >::value value;
};

template <>
struct IntToString<0> {
	typedef MetaString<> value;
};

// Class to generate a MetaString for n number of FizzBuzz iterations
template<int n>
struct FizzBuzz {
	typedef typename std::conditional<
		// FizzBuzz if divisible by both 3 and 5
		(n % 3 == 0) && (n % 5 == 0),
		MetaString<'F', 'i', 'z', 'z', 'B', 'u', 'z', 'z'>,
		typename std::conditional<
			// Fizz if divisible by just 3
			n % 3 == 0,
			MetaString<'F', 'i', 'z', 'z'>,
			typename std::conditional<
				// Buzz if divisible by just 5
				n % 3 == 0,
				MetaString<'B', 'u', 'z', 'z'>,
				//otherwise convert the integer to a string
				typename IntToString<n>::value
			>::type
		>::type
	>::type this_iteration;
	typedef typename MetaString<'\n'>::template Append<this_iteration>::value this_iteration_plus_newline;
	typedef typename FizzBuzz<n-1>::value::template Append<this_iteration_plus_newline>::value value;
};

template <>
struct FizzBuzz<1> {
	typedef MetaString<'1'> value;
};

template <char... chars>
const char MetaString<chars...>::c_str[sizeof...(chars) + 1] = {chars..., '\0'};

int main() {
	// Print out the string
	std::cout << FizzBuzz<100>::value::c_str << std::endl;
}
