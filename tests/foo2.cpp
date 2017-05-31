#include "printer.h"
#include "foo2.h"
#include "foo1.h"

int foo2() {
  Printer::debug("This message is the ground truth", "Foo2");
  foo1();
  return 0;
}
