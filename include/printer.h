#include <string>
#include <iostream>
// #include <stdio.h>

class Exception
{
  std::string exc_msg;
public:
  Exception(std::string _msg = std::string()): exc_msg(_msg) {}
  const char *msg()
  {
  	return exc_msg.c_str();
  }
};

class AssertException: public Exception
{
  using Exception::Exception;
};
class FatalException: public Exception
{
  using Exception::Exception;
};

class Printer
{
  static const std::string debug_msg_color;
  static const std::string assert_msg_color;
  static const std::string error_msg_color;
  static const std::string fatal_msg_color;
  static const std::string note_msg_color;
  static const std::string msg_color;

  static const std::string debug_msg;
  static const std::string assert_msg;
  static const std::string error_msg;
  static const std::string fatal_msg;
  static const std::string note_msg;
  static const std::string empty_msg;

  static const char black[];
  static const char red[];
  static const char green[];
  static const char yellow[];
  static const char blue[];
  static const char magenta[];
  static const char cyan[];
  static const char white[];

public:
  /*

  msg - provides a message to output
  who - provides a name before the :
  in_place - \r instead of \n. Useful when output is inside a cycle
  expr - boolean expression that is checked in assertion

  */
  static void debug(std::string msg = empty_msg, std::string who = debug_msg, bool in_place = false)
  {
  	if(in_place)
      std::cerr << debug_msg_color << who.c_str() << white << ": " << msg.c_str() << "\r";
  	  // fprintf(stderr, "%s: %s\r", who.c_str(), msg.c_str());
  	else
      std::cerr << debug_msg_color << who.c_str() << white << ": " << msg.c_str() << "\n";
      // fprintf(stderr, "%s: %s\n", who.c_str(), msg.c_str());
  }
  static void assert(bool expr, std::string msg = empty_msg, std::string who = assert_msg)
  {
  	if(!expr) {
  	  // fprintf(stderr, "%s: %s\n", who.c_str(), msg.c_str());
      std::cerr << assert_msg_color << who.c_str() << white << ": " << msg.c_str() << "\n";
  	  throw AssertException(msg);
  	}
  }
  static void note(std::string msg = empty_msg, std::string who = note_msg, bool in_place = false)
  {
  	if(in_place)
      std::cerr << note_msg_color << who.c_str() << white << ": " << msg.c_str() << "\r";
  	  // fprintf(stderr, "%s: %s\r", who.c_str(), msg.c_str());
  	else
      std::cerr << note_msg_color << who.c_str() << white << ": " << msg.c_str() << "\n";
      // fprintf(stderr, "%s: %s\n", who.c_str(), msg.c_str());  	
  }
  static void error(std::string msg = empty_msg, std::string who = error_msg)
  {
  	// fprintf(stderr, "%s: %s\n", who.c_str(), msg.c_str());
    std::cerr << error_msg_color << who.c_str() << white << ": " << msg.c_str() << "\n";
  }
  static void fatal(std::string msg = empty_msg, std::string who = fatal_msg)
  {
  	// fprintf(stderr, "%s: %s\n", who.c_str(), msg.c_str());
    std::cerr << fatal_msg_color << who.c_str() << white << ": " << msg.c_str() << "\n";
  	throw FatalException(msg);
  }
};

  const std::string Printer::msg_color = std::string("white");
  const std::string Printer::debug_msg = std::string("Debug");
  const std::string Printer::assert_msg = std::string("Assertion failed");
  const std::string Printer::error_msg = std::string("Error");
  const std::string Printer::fatal_msg = std::string("Fatal error");
  const std::string Printer::note_msg = std::string("Note");
  const std::string Printer::empty_msg = std::string("");

  const char Printer::black[] = { 0x1b, '[', '1', ';', '3', '0', 'm', 0 };
  const char Printer::red[] = { 0x1b, '[', '1', ';', '3', '1', 'm', 0 };
  const char Printer::green[] = { 0x1b, '[', '1', ';', '3', '2', 'm', 0 };
  const char Printer::yellow[] = { 0x1b, '[', '1', ';', '3', '3', 'm', 0 };
  const char Printer::blue[] = { 0x1b, '[', '1', ';', '3', '4', 'm', 0 };
  const char Printer::magenta[] = { 0x1b, '[', '1', ';', '3', '5', 'm', 0 };
  const char Printer::cyan[] = { 0x1b, '[', '1', ';', '3', '6', 'm', 0 };
  const char Printer::white[] = { 0x1b, '[', '1', ';', '3', '7', 'm', 0 };

  const std::string Printer::debug_msg_color = std::string(Printer::green);
  const std::string Printer::assert_msg_color = std::string(Printer::red);
  const std::string Printer::error_msg_color = std::string(Printer::red);
  const std::string Printer::fatal_msg_color = std::string(Printer::red);
  const std::string Printer::note_msg_color = std::string(Printer::yellow);