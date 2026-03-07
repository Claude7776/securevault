#ifndef INTELLIGENCE_H
#define INTELLIGENCE_H

int compute_attack_score(int failed_auth, int entropy_mismatch, int vault_tamper, int timing_attack_pattern);
int is_attack_probable(int score);

#endif