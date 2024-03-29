// Online C compiler to run C program online
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define HASHMAP_DEFAULT_CAPACITY 20
#define HASHMAP_HASH_INIT 2166136261u
#define true 1
#define false 0

typedef int bool;

typedef struct bucket {
    void* key;
    size_t ksize; 
    uintptr_t value;
    uint32_t hash;
    struct bucket * next;
} bucket;

typedef struct hashmap {
    bucket** buckets;
    int capacity;
    int size;
    int bucketsSize;
} hashmap;

hashmap* hashmap_create(void);
uint32_t hash_data(const unsigned char*, size_t);
bool hashmap_set(hashmap*, void*, size_t, uintptr_t);
bucket* hashmap_create_bucket(void*, size_t, uintptr_t, uint32_t);
bool checkEntries(bucket*, uint32_t, size_t, void*);
bucket * hashmap_get(hashmap*, void*, size_t);

int main() {
    hashmap* m = hashmap_create();
    

    hashmap_set(m, "hellb", 5, 400);
    hashmap_set(m, "hellB", 5, 500);    
 
    bucket* val = hashmap_get(m, "hellb", 5), *val2 = hashmap_get(m, "hellB", 5);
    
    printf("%ld", val2->value);
    

    return 0;
}

bucket* hashmap_create_bucket(void* key, size_t ksize, uintptr_t value, uint32_t hash) {
    bucket * b = malloc(sizeof(bucket));
    b->key = key;
    b->value = value;
    b->hash = hash;
    b->ksize = ksize;
    b->next = NULL;
    
    return b;
}

bucket * hashmap_get(hashmap* m, void* key, size_t ksize) {
    uint32_t hash = hash_data(key, ksize), index = hash % m->capacity;
    
    bucket * entry = m->buckets[index], *rt = NULL;
    bool found = false;
    
    if (!entry) return NULL;
    
    if (checkEntries(entry, hash, ksize, key)) {
	        rt = entry;
    } else if (entry->next) {
        bucket* curr = entry->next;
        
        while (curr) {
            if (checkEntries(curr, hash, ksize, key)) {
                rt = curr;
                break;
            }
            curr = curr->next;
        }
    }
    
    return rt;
}

bool checkEntries(bucket* entry, uint32_t hash, size_t ksize, void* key) {
    if (entry->ksize == ksize &&
	    entry->hash == hash &&
	    memcmp(entry->key, key, ksize) == 0) {
	        return true;
    }
    
    return false;
}

bool hashmap_set(hashmap* m, void* key, size_t ksize, uintptr_t value) {
    uint32_t hash = hash_data(key, ksize), index = hash % m->capacity;
    
    if (m->size >= m->capacity) {
        #ifdef _HASHMAP_RESIZE
        realloc(m->buckets, m->capacity * 2);
        m->capacity *= 2;
        #endif
    }
    
    
    bucket * entry = m->buckets[index];
    bucket * newBucket = hashmap_create_bucket(key, ksize, value, hash);
    
    if (!entry) {
        m->buckets[index] = newBucket;
        m->size++;
    } else {
        bucket * curr = entry;
        
        while(curr->next) {
            curr = curr->next;
        }
        
        curr->next = newBucket;
    }
    
    m->bucketsSize++;
    
    return true;
}

hashmap* hashmap_create() {
    hashmap* m = malloc(sizeof(hashmap));
    m->capacity = HASHMAP_DEFAULT_CAPACITY;
    m->size = 0;
    m->buckets = (bucket**)malloc(sizeof(bucket*) * m->capacity);
    m->bucketsSize = 0;
    
    
    return m;
}



uint32_t hash_data(const unsigned char* data, size_t size) {
	size_t nblocks = size / 8;
	uint64_t hash = HASHMAP_HASH_INIT;
	for (size_t i = 0; i < nblocks; ++i)
	{
		hash ^= (uint64_t)data[0] << 0 | (uint64_t)data[1] << 8 |
			 (uint64_t)data[2] << 16 | (uint64_t)data[3] << 24 |
			 (uint64_t)data[4] << 32 | (uint64_t)data[5] << 40 |
			 (uint64_t)data[6] << 48 | (uint64_t)data[7] << 56;
		hash *= 0xbf58476d1ce4e5b9;
		data += 8;
	}

	uint64_t last = size & 0xff;
	switch (size % 8)
	{
	case 7:
		last |= (uint64_t)data[6] << 56; /* fallthrough */
	case 6:
		last |= (uint64_t)data[5] << 48; /* fallthrough */
	case 5:
		last |= (uint64_t)data[4] << 40; /* fallthrough */
	case 4:
		last |= (uint64_t)data[3] << 32; /* fallthrough */
	case 3:
		last |= (uint64_t)data[2] << 24; /* fallthrough */
	case 2:
		last |= (uint64_t)data[1] << 16; /* fallthrough */
	case 1:
		last |= (uint64_t)data[0] << 8;
		hash ^= last;
		hash *= 0xd6e8feb86659fd93;
	}

	// compress to a 32-bit result.
	// also serves as a finalizer.
	return hash ^ hash >> 32;
}
