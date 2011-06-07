This bug shows how AppDomain.CurrentDomain.BaseDirectory is not set when
using only the mono_runtime_invoke method without invoking mono_runtime_exec_main
before.

mono_runtime_exec_main must be setting the AppDomain.CurrentDomain.BaseDirectory
variable somewhere deep down in the blue sea of the mono C code.
