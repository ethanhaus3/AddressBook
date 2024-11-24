#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "address_book.h"

int main() {
	setvbuf(stdout, NULL, _IONBF, 0);
	AddressBook *c1 = addressbook_create();
	printf("Ready\n");
	bool loop = true;
	while (loop) {
		char check = 0;
		fscanf(stdin, "%c", &check);
		int input = 0;
		char str1[255] = {0};

		switch (check) { //checking for input from user
		case 'a': {
			fscanf(stdin, "%d%s", &input, str1); //if add, gets index, and adds contact
			addContact(c1, input, str1);
		}
			break;

		case 'd': { //to delete, gets index and deletes node at that index
			fscanf(stdin, "%d", &input);
			deleteContact(c1, input);
		}
			break;

		case 'g': {  //to get a contact, gets index and returns node at that index
			fscanf(stdin, "%d", &input);
			getContact(c1, input);
		}
			break;

		case 'f': {  //same as get contact, but gets specific field to return
			fscanf(stdin, "%d%s", &input, str1);
			getField(c1, input, str1);
		}
			break;

		case 'n': {  //calls getSize method, returns value
			getNumber(c1);
		}
			break;

		case 'l': { //gets file to load, and loades values from file
			fscanf(stdin, "%s", str1);
			loadFile(c1, str1);
		}
			break;

		case 's': { //gets file to print result to
			fscanf(stdin, "%s", str1);
			saveTofile(c1, str1);
		}
			break;

		case 'q': { //prints final message, makes boolean false
			printf("Complete\n");
			loop = false;
		}
			break;



		default:
			break;
		}
	}

	addressbook_delete(c1);

	return EXIT_SUCCESS;
}
