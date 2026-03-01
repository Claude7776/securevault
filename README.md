SecureVault – Coffre-Fort Numérique en C 🔐
Description
SecureVault est un coffre-fort numérique développé en C, conçu pour chiffrer et déchiffrer des fichiers de manière sécurisée.
Il utilise les meilleures pratiques de cryptographie modernes :
AES-256-GCM pour un chiffrement authentifié
PBKDF2 pour dériver la clé depuis un mot de passe
Header .vlt contenant MAGIC, salt et IV pour chaque fichier
Mot de passe masqué à l’écran avec getpass()
Effacement sécurisé de la mémoire après usage
Le projet est entièrement compilable et exécutable sur Linux.
Fonctionnalités
🔹 Chiffrement / déchiffrement d’un fichier unique
🔹 Support prévu pour dossiers et multiples fichiers (option future)
🔹 Mot de passe masqué ou fourni via ligne de commande
🔹 Export et réutilisation de la clé dérivée (option future)
🔹 Vérification d’intégrité avec AES-GCM (tag)
Installation
Prérequis
Linux
GCC
OpenSSL (libssl-dev)
