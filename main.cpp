#include <pybind11/embed.h>
//

#include <iostream>
#include <stdexcept>

namespace py = pybind11;

int main(int argc, char **argv)
{
    py::scoped_interpreter interpreter;

    py::module sys = py::module::import("sys");

#ifdef CUSTOM_SYS_PATH
    sys.attr("path").attr("append")(CUSTOM_SYS_PATH);
#endif

    try
    {
        auto py_module = py::module::import("test").attr("test")();
    }
    catch (const std::exception &ex)
    {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
