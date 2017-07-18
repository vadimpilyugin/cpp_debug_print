#include "printer.hpp"

int main(int argc, char **argv)
{
	if(argc != 6)
	{
		Printer::fatal("printer <arg1> <arg2> <arg3> <arg4> <arg5>", "Usage");
	}
	else
	{
		Printer::debug(argv[1], "Debug message", { 	{"argv1", argv[1]}, 
													{"argv2", argv[2]},
													{"argv3", argv[3]},
													{"argv4", argv[4]},
													{"argv5", argv[5]} });
		try 
		{
			Printer::assert(false, argv[2], "Assert message");
		}
		catch(Printer::AssertException &a)
		{
			Printer::debug(a.what(), "Caught AssertException instance, msg");
		}
		Printer::note(argv[3], "Note message");
		Printer::error(argv[4], "Error message");
		try
		{
			Printer::fatal(argv[5], "Fatal error");
		}
		catch(Printer::FatalException &a)
		{
			Printer::debug(a.what(), "Caught AssertException instance, msg");
		}
		for(int i = 0; i <= 200000; i++) {
			std::string s = std::to_string(i);
			Printer::debug(s, "Doing calculations", {}, true);
		}
		std::cerr << std::endl;
		for(int i = 0; i <= 200000; i++) {
			std::string s = std::to_string(i);
			Printer::note(s, "Doing calculations", {}, true);
		}
		std::cerr << std::endl;
	}
	return 0;
}
