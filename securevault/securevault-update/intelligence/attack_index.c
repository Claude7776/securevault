#include "intelligence.h"
#include <stdio.h>

int compute_attack_score(int failed_auth, int entropy_mismatch, int vault_tamper, int timing_attack_pattern) {
    int score = 0;
    score += failed_auth * 3;
    score += entropy_mismatch * 5;
    score += vault_tamper * 10;
    score += timing_attack_pattern * 4;
    return score;
}

int is_attack_probable(int score) {
    if(score >= 40)
    printf("🚨 Attaque detectee\n");
else if(score > 20)
    printf("⚠️ Activite suspecte\n");
else {
    printf("✔ Systeme normal\n");
}
    return score;
}