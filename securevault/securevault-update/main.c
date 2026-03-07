#include <stdio.h>
#include <string.h>
#include "vault/vault.h"
#include "intelligence/intelligence.h"

int	main(void)
{
	int	score;
	uint8_t	
		ciphertext[128];
	uint8_t	
		decrypted[64];
	uint8_t	
		data[64];
	uint8_t	
		password[32];

	strcpy((char *)data, "SecureVault test message");
	strcpy((char *)password, "superpassword");
	printf("Message original: %s\n", data);
	vault_encrypt_data(data, ciphertext, password);
	vault_decrypt_data(ciphertext, decrypted, password);
	printf("Message dechiffre: %s\n", decrypted);
	score = compute_attack_score(5, 1, 0, 2);
	printf("Attack score: %d\n", score);
	is_attack_probable(score);
	return (0);
}
