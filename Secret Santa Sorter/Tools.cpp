#include "Tools.h"

HANDLE Tools::consoleHandle{ nullptr };

void Tools::Initialize()
{
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
}

void Tools::Log(const std::string& outputMessage, Colour colour)
{
	//Did you forget to call Initialize()?
	assert(consoleHandle);

	SetConsoleTextAttribute(consoleHandle, static_cast<WORD>(colour));
	std::cout << outputMessage << std::endl;
	SetConsoleTextAttribute(consoleHandle, static_cast<WORD>(Colour::Green));
}
