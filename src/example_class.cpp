#include "example_class.h" 

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

void ExampleClass::_bind_methods() {
    ClassDB::bind_method(D_METHOD("print_type", "variant"), &ExampleClass::print_type);
    ClassDB::bind_method(D_METHOD("say_hello"), &ExampleClass::say_hello);
}

void ExampleClass::print_type(const Variant &p_variant) const {
    print_line(vformat("Type: %d", p_variant.get_type()));
}

String ExampleClass::say_hello() {
    return "Hello from GDExtension";
}
