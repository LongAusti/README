#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Trie {
    struct Trie *children[26];
    int count;
};

struct Trie *createTrieNode() {
    struct Trie *node = (struct Trie *)malloc(sizeof(struct Trie));
    if (node) {
        node->count = 0;
        for (int i = 0; i < 26; i++) {
            node->children[i] = NULL;
        }
    }
    return node;
}

void insert(struct Trie *root, char *word) {
    struct Trie *current = root;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        int index = word[i] - 'a';
        if (!current->children[index]) {
            current->children[index] = createTrieNode();
        }
        current = current->children[index];
    }
    current->count++;
}

int numberOfOccurances(struct Trie *root, char *word) {
    struct Trie *current = root;
    int len = strlen(word);
    for (int i = 0; i < len; i++) {
        int index = word[i] - 'a';
        if (!current->children[index]) {
            return 0; // Word not found
        }
        current = current->children[index];
    }
    return current->count;
}

struct Trie *deallocateTrie(struct Trie *root) {
    if (root) {
        for (int i = 0; i < 26; i++) {
            if (root->children[i]) {
                deallocateTrie(root->children[i]);
            }
        }
        free(root);
    }
    return NULL;
}

struct Trie *createTrie() {
    return createTrieNode();
}

int readDictionary(char *filename, char **pInWords) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int numWords = 0;
    char word[256];

    while (fscanf(file, "%s", word) != EOF) {
        pInWords[numWords] = strdup(word);
        numWords++;
    }

    fclose(file);
    return numWords;
}

int main(void) {
    char *inWords[256];

    int numWords = readDictionary("dictionary.txt", inWords);
    for (int i = 0; i < numWords; ++i) {
        printf("%s\n", inWords[i]);
    }

    struct Trie *pTrie = createTrie();
    for (int i = 0; i < numWords; i++) {
        insert(pTrie, inWords[i]);
    }

    char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
    for (int i = 0; i < 5; i++) {
        printf("\t%s : %d\n", pWords[i], numberOfOccurances(pTrie, pWords[i]));
    }

    pTrie = deallocateTrie(pTrie);

    if (pTrie != NULL)
        printf("There is an error in this program\n");

    return 0;
}
