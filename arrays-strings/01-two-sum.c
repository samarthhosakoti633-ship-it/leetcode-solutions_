#include <stdio.h>
#include <stdlib.h>

// Definition for a hash table node
typedef struct HashNode {
    int key;
    int val;
    struct HashNode* next;
} HashNode;

#define TABLE_SIZE 10007

// Simple hash function handling negative numbers
unsigned int hash(int key) {
    return (unsigned int)(key < 0 ? -key : key) % TABLE_SIZE;
}

// Insert a key-value pair into the hash table
void insert(HashNode** table, int key, int val) {
    unsigned int h = hash(key);
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->val = val;
    newNode->next = table[h];
    table[h] = newNode;
}

// Search for a key in the hash table, returns its value (index) or -1 if not found
int find(HashNode** table, int key) {
    unsigned int h = hash(key);
    HashNode* curr = table[h];
    while (curr != NULL) {
        if (curr->key == key) {
            return curr->val;
        }
        curr = curr->next;
    }
    return -1;
}

// Free memory allocated for the hash table
void freeTable(HashNode** table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* curr = table[i];
        while (curr != NULL) {
            HashNode* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

// Two Sum function
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashNode** table = (HashNode**)calloc(TABLE_SIZE, sizeof(HashNode*));
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int foundIndex = find(table, complement);
        
        if (foundIndex != -1) {
            result[0] = foundIndex;
            result[1] = i;
            freeTable(table);
            free(table);
            return result;
        }
        
        insert(table, nums[i], i);
    }

    freeTable(table);
    free(table);
    *returnSize = 0;
    return NULL;
}