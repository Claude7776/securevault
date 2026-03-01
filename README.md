# 🔐 SecureVault – Coffre-Fort Numérique en C

## 📌 Description

**SecureVault** est un coffre-fort numérique développé en **C**, conçu pour chiffrer et déchiffrer des fichiers de manière sécurisée sous Linux.

Il implémente des primitives cryptographiques modernes :

- 🔐 AES-256-GCM (chiffrement authentifié)
- 🔑 PBKDF2-HMAC-SHA256 (dérivation de clé)
- 🧂 Salt aléatoire unique par fichier
- 🎲 IV aléatoire généré à chaque chiffrement
- 🏷 Header `.vlt` contenant MAGIC + salt + IV
- 👁 Mot de passe masqué via `getpass()`
- 🧹 Effacement sécurisé de la mémoire sensible après usage

Le projet est compilable et exécutable sur Linux avec GCC et OpenSSL.

---

## 🏗 Format du fichier chiffré (.vlt)

Chaque fichier chiffré contient :

[MAGIC HEADER]
[SALT]
[IV]
[CIPHERTEXT]
[AUTH TAG]


Cela permet :

- Vérification du format
- Dérivation correcte de la clé
- Détection d’un mot de passe incorrect
- Protection contre modification ou corruption

---

## ⚙️ Fonctionnalités

- 🔹 Chiffrement d’un fichier unique
- 🔹 Déchiffrement sécurisé
- 🔹 Vérification d’intégrité avec AES-GCM
- 🔹 Mot de passe masqué à l’entrée
- 🔹 Gestion propre des erreurs

### 🚀 Fonctionnalités prévues

- Support multi-fichiers / dossiers
- Mode batch
- Option verbose
- Export / réutilisation clé dérivée

---

## 🖥 Installation

### 📋 Prérequis

- Linux
- GCC
- OpenSSL (`libssl-dev`)

### Installation des dépendances (Debian / Ubuntu)

```bash
sudo apt update
sudo apt install build-essential libssl-dev
```

## 🔨 Compilation

Avec Makefile :

```bash
make
```
Ou manuellement :
```bash
gcc -Wall -Wextra -Werror main.c crypto.c utils.c -lssl -lcrypto -o securevault
```
## 🚀 Utilisation
🔐 Chiffrer un fichier (Fichier de test déjà existant)

```bash
cd build
./securevault -e secret.txt
```
Le programme demandera un mot de passe (masqué).

Fichier généré :
```bash
secret.txt.vlt
```
## 🔓 Déchiffrer un fichier

```bash
./securevault -d secret.txt.vlt
```
**Le programme demande le mot de passe et restaure le fichier original.**

## 🔑 Fournir le mot de passe via ligne de commande (si activé)

```bash
./securevault -e secret.txt -p "MotDePasseFort"
```
**⚠️ Moins sécurisé que l’entrée masquée.**

## ❌ Mot de passe incorrect

Si le mot de passe est erroné :
```bash
Erreur : échec d’authentification (mot de passe incorrect ou fichier corrompu)
```
Grâce à AES-GCM, aucune donnée ne sera produite si l’intégrité échoue.

## 🔒 Sécurité

SecureVault implémente :

- Dérivation lente de clé (PBKDF2)

- Chiffrement authentifié (AES-256-GCM)

- Salt et IV uniques

- Protection contre modification

- Nettoyage mémoire des données sensibles

## 📈 Objectif pédagogique

Ce projet permet de comprendre :

- Différence entre CBC et GCM

- Importance du salt

- Rôle du IV

- Dérivation de clé sécurisée

- Intégrité et authentification

- Conception d’un format sécurisé

## 📜 Licence

Projet open-source à but éducatif.
