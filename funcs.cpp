#include <iostream>
#include <vector>
#include "funcs.h"
#include "caesar.h"
#include "decrypt.h"

std::string decoder(std::string encrypted_string){
  std::string decoded;
  /*vector<string> encrypted;
  encrypted.push_back(100);

  for(int i = 0; i < encrypted.size(); i++){
  std::cout << encrypted[i] << endl;*/
  return "lalala";
}

std::string solve(std::string encrypted_string){
  // for each of the 26 rotations of encrypted string:
  std::vector <double> englishFreqencies = {0.082, 0.015, 0.027, 0.047,
			      0.13, 0.022, 0.02, 0.062,
			      0.069, 0.0016, 0.0081, 0.04,
			      0.027, 0.067, 0.078, 0.019,
			      0.0011, 0.059, 0.062, 0.096,
			      0.027, 0.0097, 0.024, 0.0015,
			      0.02, 0.0078};
  
  // make a 26 space vector with the frequencies of all the letters based on encrypted string
  std::vector <double> letterFrequencies;
  int characters = 0;

  char lowerAlphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l','m', 'n',
			    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  char upperAlphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
			    'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

  for(int i = 0; i < 26; i++){
    // entries will be 0 for those that don't appear in the string
    letterFrequencies.push_back(0);
    
    for(int j = 0; j < encrypted_string.length(); j++){
      //if there is that letter in the string -> count how many there are
      if(encrypted_string[j] == lowerAlphabet[i] || encrypted_string[j] == upperAlphabet[i]){
	letterFrequencies[i] += 1;
	characters += 1;
      }
    }

  }

  for(int i = 0; i < 26; i++){
    if (letterFrequencies[i] > 0){
      letterFrequencies[i] = letterFrequencies[i] / characters;
    }
  }

  for(int i = 0; i < 26; i++){
    std::cout << letterFrequencies[i] << std::endl;
    }
  
  // calculate the distance between this vector and the vector of letter frequencies for English
  // rotation with the smallest distance is the solution 
  return "lalala";
}

