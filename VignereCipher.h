#ifndef VIGNERECIPHER_H
#define VIGNERECIPHER_H
#include <stdlib.h> // abs
#include <string> // std::string
#include <locale> // std::locale, std::toupper

class VignereCipher {
public:
	static std::string Encrypt(std::string, std::string);
private:
	static void FormatKey(std::string&, std::string);
	static void FormatEncrypted(std::string&);
	static char ShiftChar(char, int);
	static int CalculateDistance(char, char);
};

#endif