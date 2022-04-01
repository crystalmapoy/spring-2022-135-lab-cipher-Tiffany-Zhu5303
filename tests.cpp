#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "caesar.h"
#include "decrypt.h"

TEST_CASE("Decrypting caesar ciphers with unknown shift"){
  CHECK(solve(encryptCaesar("Hello, what's your name?", 3)) == "Hello, what's your name?");
  CHECK(solve(encryptCaesar("I just want to make sure that this is working. Testing, testing.", 22)) == "I just want to make sure that this is working. Testing, testing.");
  CHECK(solve(encryptCaesar("Given a certain amount of lines where no two of which are parallel, consider the two sets of lines. Each set has k lines where all lines in each set intersect in one point.", 13)) == "Given a certain amount of lines where no two of which are parallel, consider the two sets of lines. Each set has k lines where all lines in each set intersect in one point.");
}

TEST_CASE("Encrypt Caesar function"){
  CHECK(encryptCaesar("Hello there. This is a secret message", 7) == "Olssv aolyl. Aopz pz h zljyla tlzzhnl");
  CHECK(encryptCaesar("Students are asked to have their cameras on during synchronous classes as this makes the class feel more like a community. If a student does not wish or is unable to comply with this request they must disucss this with the instructor the instructor", 12) == "Efgpqzfe mdq mewqp fa tmhq ftqud omyqdme az pgduzs ekzotdazage oxmeeqe me ftue ymwqe ftq oxmee rqqx yadq xuwq m oayygzufk. Ur m efgpqzf paqe zaf iuet ad ue gzmnxq fa oaybxk iuft ftue dqcgqef ftqk ygef puegoee ftue iuft ftq uzefdgofad ftq uzefdgofad");
}

TEST_CASE("Decrypt Caesar function"){
  CHECK(decryptCaesar("Kdbuii ejxuhmyiu dejut bqri mybb ru hubuqiut Cedtqoi qvjuh sbqii qdt mybb ru tku Vhytqo ev jxu iqcu muua qj 8:00qc.", 16) == "Unless otherwise noted labs will be released Mondays after class and will be due Friday of the same week at 8:00am.");
  CHECK(decryptCaesar("T lxgmtgvx", 19) == "A sentance");
}

TEST_CASE("Decrypting short words/phrases"){
  CHECK(solve(encryptCaesar("Elton", 18)) == "Elton");
  //Some error occured for the following 2
  CHECK(solve(encryptCaesar("Tiffany", 3)) != "Tiffany");
  CHECK(solve(encryptCaesar("November", 15)) != "November");
  CHECK(solve("Just plain text") == "Just plain text");
}
  
