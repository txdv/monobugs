#include <stdio.h>
#include <glib.h>
#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>

#define BUG

MonoMethod *search_method(MonoClass *klass, char *methodname)
{
  MonoMethod *m = NULL;
  gpointer iter = NULL;
  while ((m = mono_class_get_methods(klass, &iter))) {
    if (!strcmp(mono_method_get_name(m), methodname))
      return m;
  }
  return NULL;
}

int main()
{
  const char *file = "test.dll";
  MonoDomain   *domain   = mono_jit_init(file);
  MonoAssembly *assembly = mono_domain_assembly_open(domain, file);
  MonoImage    *image    = mono_assembly_get_image(assembly);
  MonoClass    *class    = mono_class_from_name(image, "", "Test");
  MonoMethod   *main     = search_method(class, "Main");
  
  MonoArray *args = (MonoArray *) mono_array_new (domain, mono_get_string_class(), 0);

#ifndef BUG
  mono_runtime_exec_main (main, args, NULL);
#endif
  mono_runtime_invoke(main, NULL,  args, NULL);
  return 0;
}
