#pragma once

std::string shiftBackChar(char c, int rshift);
std::string decryptCaesar(std::string ciphertext, int rshift);
std::string decryptVigenere(std::string ciphertext, std::string keyword);
