#include <stdio.h>
#include <string.h>
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>
#include <enc.h>
#include <io.h>

int main(int argc, char *argv[])
{
  printf("Arg count - %d\n\n", argc);
  unsigned char *action = "enc";
  unsigned char *key = (unsigned char *)"01234567890123456789012345678901";
  unsigned char *iv = (unsigned char *)"0123456789012345";
  unsigned char *filename;

  if (argc >= 4)
  {
    action = (unsigned char *)argv[1];
    filename = (unsigned char *)argv[2];
    key = (unsigned char *)argv[3];
    iv = (unsigned char *)argv[4];
  }
  printf("Action - %s\n", action);
  printf("Filename - %s\n", argv[2]);
  printf("Key - %s\n", key);
  printf("IV - %s\n\n", iv);

  int plaintext_len;
  unsigned char *plaintext = read_file(filename, &plaintext_len);
  printf("Plaintext %d is:\n%s\n", plaintext_len, plaintext);

  unsigned char ciphertext[128];
  unsigned char decryptedtext[128];
  int decryptedtext_len, ciphertext_len;

  ciphertext_len = encrypt(plaintext, strlen((char *)plaintext), key, iv, ciphertext);

  printf("Encrypted bytes:\n");
  BIO_dump_fp(stdout, (const char *)ciphertext, ciphertext_len);
  printf("\n");

  write_file("../encrypted", ciphertext);
  int ciphertext_len2;
  unsigned char *ciphertext2 = read_file("../encrypted", &ciphertext_len2);

  decryptedtext_len = decrypt(ciphertext2, ciphertext_len2, key, iv, decryptedtext);
  decryptedtext[decryptedtext_len] = '\0';

  printf("Decrypted text is:\n");
  printf("%s\n", decryptedtext);

  return 0;
}
