#include <iostream>

char shiftBackChar(char c, int rshift){
  //lower case a-z is 97-122
  //upper case A-Z is 65-90
  int asciiCode = c;

  //std::cout << "the letter is " << c << " and the value is " << asciiCode << std::endl;

  bool lower = false;
  bool upper = false;
  
  if(asciiCode <= 90 && asciiCode >= 65){
    upper = true;
  }else if(asciiCode <= 122 && asciiCode >= 97){
    lower = true;
  }

  if(upper == true){

    asciiCode -= rshift;

    // std::cout << "after the shift, the value is " << asciiCode << std::endl;
    
    while(asciiCode < 65){
      asciiCode += 26;
    }
    
  }else if(lower == true){

    asciiCode -= rshift;

    // std::cout << "after the shift, the value is " << asciiCode << std::endl;
    
    while(asciiCode < 97){
      asciiCode += 26;
    }
    
  }else{
    //if c is not an alphabet then
    return char(asciiCode);
    
  }

  //std::cout << char(asciiCode) << "this is the new letter and here's the num " << asciiCode << std::endl;

  return char(asciiCode);
}

std::string decryptCaesar(std::string ciphertext, int rshift){
   //char array to hold each letter converted from string
  char letters[ciphertext.length()];
  std::string decrypted;

  for(int i = 0; i < ciphertext.length(); i++){
   //to convert each letter from string to char
    letters[i] = ciphertext[i];

    //std::cout << shiftChar(letters[i], rshift) << "this is the new letter" << std::endl;

    decrypted += shiftBackChar(letters[i], rshift);
  }

  return decrypted;
}

std::string decryptVigenere(std::string ciphertext, std::string keyword){
 char alphabet[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l','m', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  int index = -1;
  std::string decrypted;
  int loop = 0;
  int asciiCode;

  for(int i = 0; i < ciphertext.length(); i++){
    //ascii code to check if char is an alphabet
    asciiCode = ciphertext[i];
    //std::cout << asciiCode << plaintext[i]<< std::endl;

    if(asciiCode <= 122 && asciiCode >= 97){
    for(int j = 0; index < 0; j++){
      
      //saves number into the index variable for lowercases
      if(keyword[loop] == alphabet[j]){
	index = j;
	loop++;
      }

    }

    }else if (asciiCode <= 90 && asciiCode >= 65){
      for(int j = 0; index < 0; j++){
      
      //saves number into the index variable for uppercases
      if(keyword[loop] == alphabet[j]){
	index = j;
	loop++;
      }
      }
    }

    //loop through keyword after reaching the end
      if(loop >= keyword.length()){
	loop = 0;
      }

    if(index > -1){
      //std::cout << shiftBackChar(ciphertext[i], index) << std::endl;
      decrypted += shiftBackChar(ciphertext[i], index);
      //std::cout << "this is the index" << index << std::endl;
      index = -1;
    }else{//if it is not an alphabet
      decrypted += shiftBackChar(ciphertext[i], index);
    }
    
  }
  return decrypted;
  }
