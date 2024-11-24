#include "address_book.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

AddressBook* addressbook_create() { //creates space for contact, initializes pointers
	AddressBook *contact = (AddressBook*) malloc(sizeof(AddressBook));
	if (contact) {
		contact->number = 0;
		contact->contact_list = NULL;
		return contact;
	}
	return NULL;
}

void addressbook_delete(AddressBook *linkList) { //deletes contact, saves pointer value in new struct, frees deleted node
	ContactNode *node = linkList->contact_list;
	while (node) {
		ContactNode *temp = node->next;
		free(node);
		node = temp;
	}
	free(linkList);
	return;
}

void addContact(AddressBook *contact, int input, char *property_str) { //checks for valid input, breaks at , and adds values to struct, readjusts pointers
	if ( input > contact->number||input < 0 ) {
	} else {
		ContactNode *node = (ContactNode*) calloc(sizeof(ContactNode),
				sizeof(char));
		if (!node)
			exit(1);
		char *token = 0;
		if ((token = strtok(property_str, ","))) {
			strcpy(node->contact.last_name, token);
		}
		if ((token = strtok(NULL, ","))) {
			strcpy(node->contact.first_name, token);
		}
		if ((token = strtok(NULL, ","))) {
			strcpy(node->contact.email_address, token);
		}
		if ((token = strtok(NULL, ","))) {
			strcpy(node->contact.phone_number, token);
		}

		node->next = NULL;

		{
			ContactNode *prev_node = pre_node(contact, input);

			if (!prev_node) {
				node->next = contact->contact_list;
				contact->contact_list = node;
			} else {
				node->next = prev_node->next;
				prev_node->next = node;
			}
		}
		contact->number++;
	}

	return;
}

void deleteContact(AddressBook *linkList, int input) { //deletes contact at given index, readjusts pointers
	if (input < 0 || linkList->number == 0 || input > linkList->number - 1) {
	} else {
		ContactNode *prev_node = pre_node(linkList, input);

		if (!prev_node) {
			ContactNode *tdel = linkList->contact_list;
			linkList->contact_list = tdel->next;
			free(tdel);
		} else {
			ContactNode *tdel = prev_node->next;
			prev_node->next = tdel->next;
			free(tdel);
		}
		linkList->number--;
	}

	return;
}

void getField(AddressBook *linkList, int input, char *field) { //same as get contact, but searches for specific field and returns specific value
	if (input < 0 || input > linkList->number == 0 || input > linkList->number - 1) {
	} else {
		ContactNode *node = get_node(linkList, input);

		switch (field[0]) {
		case 'f':
			printf("%s\n", node->contact.first_name);
			break;
		case 'p':
			printf("%s\n", node->contact.phone_number);
			break;
		case 'l':
			printf("%s\n", node->contact.last_name);
			break;
		default:
			break;
		}
	}
	return;
}

void getContact(AddressBook *linkList, int input) {  //returns contact from given input
	if (input > linkList->number - 1  || input<0 || linkList->number == 0) {
	} else {
		ContactNode *node = get_node(linkList, input);
		printf("%s,%s,%s,%s\n", node->contact.last_name,
				node->contact.first_name, node->contact.email_address,
				node->contact.phone_number);
	}
	return;
}

void getNumber(AddressBook *linkList) { //returns size pointer
	printf("%d\n", linkList->number);
	return;
}

void saveTofile(AddressBook *linkList, char *file_path) { //prints result to input file
	FILE *pFile;
	pFile = fopen(file_path, "w");
	if (pFile != NULL) {
		fputs("lastName,firstName,email,phoneNumber\n", pFile);
		ContactNode *node = linkList->contact_list;
		while (node) {
			fputs(node->contact.last_name, pFile);
			fputs(",", pFile);
			fputs(node->contact.first_name, pFile);
			fputs(",", pFile);
			fputs(node->contact.email_address, pFile);
			fputs(",", pFile);
			fputs(node->contact.phone_number, pFile);
			fputs("\n", pFile);

			node = node->next;
		}
		fclose(pFile);
	}
	return;
}

void loadFile(AddressBook *linkList, char *file_path) { //loads infro from given file
	FILE *pFile;
	pFile = fopen(file_path, "r");
	if (pFile != NULL) {
		char contact_infor[255] = { 0 };
		fscanf(pFile, "%s", contact_infor);
		while (fscanf(pFile, "%s", contact_infor) > 0) {
			addContact(linkList, linkList->number, contact_infor);
		}
		fclose(pFile);
	}
	return;
}




ContactNode* get_node(AddressBook *linkList, int input) {
	ContactNode *prev_node = pre_node(linkList, input);
	if (!prev_node) {
		return linkList->contact_list;
	} else
		return prev_node->next;
}
ContactNode* pre_node(AddressBook *linkList, int input) {
	ContactNode *cursor = NULL;
	while (input--) {
		if (!cursor)
			cursor = linkList->contact_list;
		else
			cursor = cursor->next;
	}
	return cursor;
}

int compare_contacts(ContactNode *first, ContactNode *second) {
	int r1 = strcmp(first->contact.last_name, second->contact.last_name);
	int r2 = strcmp(first->contact.first_name, second->contact.first_name);
	int r3 = strcmp(first->contact.email_address,
			second->contact.email_address);
	int r4 = strcmp(first->contact.phone_number, second->contact.phone_number);

	if (r1 == 0) {
		if (r2 == 0) {
			if (r3 == 0) {
				return r4;
			} else
				return r3;
		} else
			return r2;
	} else
		return r1;
}
