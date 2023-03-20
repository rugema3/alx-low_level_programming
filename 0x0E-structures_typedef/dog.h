#ifndef DOG_H
#define DOG_H

/**
 * struct dog - a dog structure
 * @name: the name of the dog
 * @age: the age of the dog
 * @owner: the owner of the dog
 */
struct dog
{
	char *name;
	float age;
	char *owner;
};

/* prototype for init_dog function */
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
typedef struct dog dog_t;
#endif /* DOG_H */

