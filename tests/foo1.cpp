#include "printer.hpp"
#include "foo1.h"

int foo1() {
  Printer::debug("This message is a lie!!1!1", "Foo1");
  return 0;
}
