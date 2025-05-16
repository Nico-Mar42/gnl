Voici le fichier **README.md** complet, écrit en **Markdown**, prêt à être utilisé dans ton projet `get_next_line` de l’école 42 :

---

````markdown
# get_next_line

> Projet de l'école 42 visant à implémenter une fonction permettant de lire un fichier ligne par ligne.

## 🧠 Objectif

Ce projet a pour but d’écrire une fonction `get_next_line` capable de lire une ligne depuis un descripteur de fichier à chaque appel, jusqu’à atteindre la fin du fichier.

## 📌 Prototype

```c
char *get_next_line(int fd);
````

* **fd** : descripteur de fichier à lire.
* **Retour** :

  * La ligne lue (incluant le `\n` si présent).
  * `NULL` en cas d’erreur ou de fin de fichier.

## 🔧 Contraintes

* Utiliser uniquement la fonction `read` pour lire les fichiers.
* Gérer correctement la mémoire : pas de fuites !
* La fonction doit fonctionner avec n’importe quelle valeur positive de `BUFFER_SIZE`.
* Doit gérer plusieurs appels consécutifs (lecture ligne par ligne).
* Doit fonctionner avec plusieurs descripteurs ouverts en même temps.

## 📁 Fichiers fournis

* `get_next_line.c` — fonction principale.
* `get_next_line_utils.c` — fonctions utilitaires (`ft_strjoin`, `ft_strlen`, etc.).
* `get_next_line.h` — prototypes et includes.
* `main.c` (optionnel) — pour tester votre fonction.

## ⚙️ Compilation

Compilez avec le `BUFFER_SIZE` de votre choix (ex : 42) :

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

## 🧪 Exemple d'utilisation

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("file.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## 🏁 Bonus (si réalisé)

* Optimisation mémoire.
* Lecture depuis `stdin` ou `pipe`.
* Une seule lecture par appel à `get_next_line`.
* Gérer des fichiers très longs efficacement.

## ✅ Compétences évaluées

* Lecture bas-niveau avec `read`.
* Manipulation de chaînes et de buffers.
* Allocation dynamique.
* Gestion fine de la mémoire.
* Gestion de plusieurs file descriptors.

## 📚 Ressources utiles

* [man read](https://man7.org/linux/man-pages/man2/read.2.html)
* [man open](https://man7.org/linux/man-pages/man2/open.2.html)
* [man malloc](https://man7.org/linux/man-pages/man3/malloc.3.html)
* [man free](https://man7.org/linux/man-pages/man3/free.3.html)

## 👤 Auteur

Nicolas Martin

Projet réalisé dans le cadre du cursus [42](https://42.fr).
