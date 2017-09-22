#include "VignereCipher.h"

std::string VignereCipher::Encrypt(std::string key, std::string plaintext) {
	// std::string to hold our encrypted text
	std::string encrypted;
	// Format key
	FormatKey(key, plaintext);
	// Begin encryption
	for (int i = 0; i < plaintext.length(); i++) {
		int keyDistance = CalculateDistance(key.at(i), 'a'); // Key's current char distance from 'a'
		char EncryptedChar = ShiftChar(plaintext.at(i), keyDistance); // Encrypt the plaintext char shifting the plaintext char by the keyDistance
		encrypted.push_back(EncryptedChar); // Add char to encrypted string
	}
	FormatEncrypted(encrypted);
	return encrypted; // Return the encrypted string
}

int VignereCipher::CalculateDistance(char a, char b) {
	return abs(a - b);
}

char VignereCipher::ShiftChar(char a, int keyDistance) {
	for (int i = 0; i < keyDistance; i++) {
		a += 1; // shift our char once
		if (a > 122) // Check if we've gone past z
			a = 97; // Set our char back to a
	}
	return a;
}

void VignereCipher::FormatKey(std::string& key, std::string plaintext) {
	// append key length to plaintext's size
	// note: key may end up larger than plaintext here, but will be trimmed in the next if statement
	if (key.length() < plaintext.length()) {
		while (key.length() < plaintext.length())
			key.append(key); // append key onto itself until >= plaintext.length()
	}
	// shrink key length to plaintext's size
	if (key.length() > plaintext.length())
		key.erase(key.length(), std::string::npos);
}

void VignereCipher::FormatEncrypted(std::string& encrypted) {
	std::locale loc;
	for (int i = 0; i < encrypted.length(); i++)
		encrypted.at(i) = std::toupper(encrypted.at(i), loc); // Make all character uppercase
}