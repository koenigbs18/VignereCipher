/*
************************************
@Title:  Vignere Cipher
@Author: Brett Koenig
@Date:   9/21/17
@TODO:   Support spaces, delimiters
************************************
*/

#include <iostream> // std::cout, std::getline
#include <fstream> // std::ofstream
#include <string> // std::string
#include <Windows.h> // Sleep, GetASyncKeyState
#include "VignereCipher.h"

void WriteToFile(std::string);

int main() {
	// Variables to be used for input
	std::string key;
	std::string plaintext;
	std::string encrypted;
	// Prompt user input
	std::cout << "Vignere Cipher";
	std::cout << std::endl << std::endl;
	std::cout << "Enter key: ";
	std::getline(std::cin, key);
	std::cout << "Enter plaintext: ";
	std::getline(std::cin, plaintext);
	// Do encryption
	encrypted = VignereCipher::Encrypt(key, plaintext);
	std::cout << std::endl;
	std::cout << "Your encrypted string: " << encrypted;
	// Write our result to file
	WriteToFile(encrypted);
	std::cout << std::endl;
	std::cout << "Press space to exit.";
	while (!GetAsyncKeyState(VK_SPACE))
		Sleep(100);

	return 0;
}

void WriteToFile(std::string write) {
	std::ofstream output("output.txt", std::ios::out, std::ios::trunc);
	if (output.is_open()) {
		output << write;
		output.close();
		std::cout << "\n\nWrote to file.";
	}
	else
		std::cout << "\n\nError writing to file!";
}