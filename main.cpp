#include <iostream>
#include "funcs.h"
#include "caesar.h"
#include "decrypt.h"

int main()
{
  std::cout << solve(encryptCaesar("Hello there! How are you doing?", 22)) << "\n" << std::endl;

  std::cout << solve(encryptCaesar("There is a contest with 40 Pokemons. There are 18 Pokemons who like to fight in the sky, and 23 who like to fight on ground. Several of them like to fight in the water. The number of those who like to fight in the sky and on ground in 9. There are 7 Pokemons who like to fight in the sky and in water, and 12 who like to fight on ground and in water. There are4 Pokemons who like to fight in the sky, on ground, and in water. How many Pokemons like to fight in water?", 5)) << std::endl;

  std::cout << "\n" << solve(encryptCaesar("Credits to professor Saad Mneimneh for assigning this pokemon homework question.", 15)) << std::endl;
  
  return 0;
}
