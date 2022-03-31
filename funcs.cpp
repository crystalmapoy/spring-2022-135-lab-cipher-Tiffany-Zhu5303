#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <cfloat>

#include "funcs.h"
#include "caesar.h"
#include "decrypt.h"

double distance(std::vector <double> v1, std::vector <double> v2, int len){
  double distance;

  //distance formula
  for(int i = 0; i < len; i++){
    if(v1[i] != 0){
      distance += pow(v1[i], 2) - pow(v2[i], 2);
    }
  }
  
  distance = pow(distance, 0.5);
  // std::cout << distance << std::endl;
  
  return distance;
}

std::string solve(std::string encrypted_string){
  // for each of the 26 rotations of encrypted string:
  std::vector <double> englishFrequencies = {0.082, 0.015, 0.027, 0.047,
			      0.13, 0.022, 0.02, 0.062,
			      0.069, 0.0016, 0.0081, 0.04,
			      0.027, 0.067, 0.078, 0.019,
			      0.0011, 0.059, 0.062, 0.096,
			      0.027, 0.0097, 0.024, 0.0015,
			      0.02, 0.0078};
  
  // make a 26 space vector with the frequencies of all the letters based on encrypted string
  std::vector <double> letterFrequencies = {0, 0, 0, 0,
			      0, 0, 0, 0,
			      0, 0, 0, 0,
			      0, 0, 0, 0,
			      0, 0, 0, 0,
			      0, 0, 0, 0,
			      0, 0};
  int characters = 0;
  int rotate = 0;
  std::string rotated;

  std::string lowerAlphabet = "abcdefghijklmnopqrstuvwxyz";
  std::string upperAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

  double min = DBL_MAX;

  for(int i = 0; i < 26; i++){
    // entries will be 0 for those that don't appear in the string
    //letterFrequencies.push_back(0);

    rotated = encryptCaesar(encrypted_string, i);

    //if there is that letter in the string -> count how many there are
    for(int j = 0; j < encrypted_string.length(); j++){
      
      //see if the letter of the string is in the alphabet with find
      if(lowerAlphabet.find(rotated[j])!= std::string::npos){
	letterFrequencies[lowerAlphabet.find(rotated[j])] += 1;
	//std::cout << lowerAlphabet.find(rotated[j]) << std::endl;
	characters += 1;
      }else if(upperAlphabet.find(rotated[j]) != std::string::npos){
	 letterFrequencies[upperAlphabet.find(rotated[j])] += 1;
	characters += 1;
	}
      }

    int sum = 0;

    for(int j = 0; j < 26; j++){
      if (letterFrequencies[j] > 0){
	letterFrequencies[j] = letterFrequencies[j] / characters;
      }
    }

    //calculate the distance between this vector and the vector of letter frequencies for English
    // rotation with the smallest distance is the solution
    if(min > distance(letterFrequencies, englishFrequencies, 26)){
	min = distance(letterFrequencies, englishFrequencies, 26);
	rotate = i;
      }

    letterFrequencies = {0, 0, 0, 0,
			      0, 0, 0, 0,
			      0, 0, 0, 0,
			      0, 0, 0, 0,
			      0,0, 0, 0,
			      0, 0, 0, 0,
			      0, 0};
    characters = 0;
  }
  std::string decrypted = decryptCaesar(encrypted_string, 26 - rotate);

  return decrypted;
}

