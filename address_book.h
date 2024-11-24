#ifndef __ADDRESS_BOOK_H__
#define __ADDRESS_BOOK_H__
#endif
struct Contact   //base contact struct, without pointers
{
	char last_name[255];
	char first_name[255];
	char phone_number[255];
	char email_address[255];
};
typedef struct Contact Contact;  //passes last struct in, adds pointer
struct ContactNode {
	Contact contact;
	struct ContactNode* next;
};
typedef struct ContactNode ContactNode;
typedef struct AddressBook {  //passes the 2nd struct in, adds list counter value
	ContactNode* contact_list;
	int number;
}AddressBook;
AddressBook* addressbook_create();  //adds initial contact info first struct
void addressbook_delete(AddressBook* addr_book);  //declare all the methods
void addContact(AddressBook* adr_book, int input, char* prop_str);
void deleteContact(AddressBook* adr_book, int input);
void getField(AddressBook* adr_book, int input, char* field);
void getContact(AddressBook* adr_book, int input);
void getNumber(AddressBook* adr_book);
void saveTofile(AddressBook* adr_book, char* file_path);
void loadFile(AddressBook* adr_book, char* file_path);
ContactNode* get_node(AddressBook* adr_book, int input);
ContactNode* pre_node(AddressBook* adr_book, int input);
int compare_contacts(ContactNode* first, ContactNode* second);
