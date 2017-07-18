#include "printer.hpp"
#include "foo1.h"
#include "foo2.h"


int main()
{
  foo1();
  foo2();
  Printer::debug("Все закончилось хорошо");
  return 0;
}
