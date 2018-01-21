/**
 * A simple C interface for the plugins to use.
 */

extern "C"{

struct talker_t;

typedef void* handle_t;
typedef talker_t*(*get_functions_t)();

/**
 * Represents all the functions exposed by a plugin.
 */
struct talker_t {
    // returns a pointer to this plugin's "name"
    // (constant for each plugin)
    char const*(*get_name)(handle_t);
    // returns a handle to a new instance of this plugin
    handle_t(*make)();
    // arguments:
    // - self, an instance created by make()
    // - other_fns, talker_t for the other instance
    // - other, handle_t for the other instance
    // - msg, the message to say to the other instance
    char const *(*say_to)(handle_t, talker_t*, handle_t, char const*);
    // "destructor" function
    void(*free)(handle_t);
};

talker_t* talker_get_functions();

}

