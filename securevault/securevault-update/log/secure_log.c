#include "secure_log.h"
#include <string.h>
#include <stdio.h>

void log_incident(const char *prev_hash, const char *incident_data, char *out_hash) {
    snprintf(out_hash, 65, "%s%s", prev_hash, incident_data);
    printf("[SecureLog] Incident enregistré : %s\n", out_hash);
}