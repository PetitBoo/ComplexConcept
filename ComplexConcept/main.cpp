#include <type_traits>
#include <concepts>
#include <string>
#include <iostream>

template <typename T>
concept ComplexConcept =
	requires(const T v) {
		{ v.hash() } -> std::convertible_to<long>;
}
&&
	requires(const T v) {
		{ v.to_string() } -> std::same_as<std::string>;
}
&&
	requires(const T v) {
	(std::has_virtual_destructor<T>::value != true);
}
;