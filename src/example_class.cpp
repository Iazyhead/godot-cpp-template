#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

class GDExtExample : public RefCounted {
    GDCLASS(GDExtExample, RefCounted)

protected:
    static void _bind_methods() {
        ClassDB::bind_method(D_METHOD("say_hello"), &GDExtExample::say_hello);
    }

public:
    String say_hello() {
        return "Hello from GDExtension";
    }
};

void initialize_gdext_example(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) return;
    ClassDB::register_class<GDExtExample>();
}

void uninitialize_gdext_example(ModuleInitializationLevel p_level) {
    if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) return;
}

extern "C" {
    GDExtensionBool GDE_EXPORT example_library_init(
        GDExtensionInterfaceGetProcAddress p_get_proc_address,
        const GDExtensionClassLibraryPtr p_library,
        GDExtensionInitialization *r_initialization
    ) {
        godot::GDExtensionBinding::InitObject init_obj(
            p_get_proc_address, p_library, r_initialization);
        init_obj.register_initializer(initialize_gdext_example);
        init_obj.register_terminator(uninitialize_gdext_example);
        init_obj.set_minimum_library_initialization_level(
            MODULE_INITIALIZATION_LEVEL_SCENE);
        return init_obj.init();
    }
}