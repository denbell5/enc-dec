#include <stdio.h>
#include <string.h>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <enc.h>

int main(int argc, char *argv[])
{
  printf("Arg count - %d\n", argc);
  unsigned char *action = "enc";
  unsigned char *key = (unsigned char *)"01234567890123456789012345678901";
  unsigned char *iv = (unsigned char *)"0123456789012345";

  if (argc >= 4)
  {
    action = (unsigned char *)argv[1];
    key = (unsigned char *)argv[2];
    iv = (unsigned char *)argv[3];
  }
  printf("Action - %s\n", action);
  printf("Key - %s\n", key);
  printf("IV - %s\n", iv);

  unsigned char *plaintext = (unsigned char *)"The quick brown fox jumps over the lazy dog";
  unsigned char ciphertext[128];
  unsigned char decryptedtext[128];
  int decryptedtext_len, ciphertext_len;

  ciphertext_len = encrypt(plaintext, strlen((char *)plaintext), key, iv, ciphertext);

  BIO_dump_fp(stdout, (const char *)ciphertext, ciphertext_len);

  decryptedtext_len = decrypt(ciphertext, ciphertext_len, key, iv, decryptedtext);
  decryptedtext[decryptedtext_len] = '\0';

  printf("Decrypted text is:\n");
  printf("%s\n", decryptedtext);

  return 0;
}
