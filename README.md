# AddressBook
The address book program receives commands from the standard input.  The commands allow the user to add, edit, and delete contacts, as well as load or save contacts from/to a file. Each contact has a first name, last name, email address, and phone number.


Add a new contact:
Code:  a
First parameter:  0-based index where the new contact should be inserted.  0 would mean in front of the first contact in the list, 1 would mean in front of the second contact in the list, and so on.  This value will not be greater than the current number of contacts in the address book.
Second parameter: String containing a comma delimited list of contact property values.  The order is last_name, first_name, email, phone_number
Example: 
a
1
SMITH,AUNDREA,asmith@ign.com,8001110001

Delete a contact:
Code:  d
First parameter:  0-based index of the contact to delete.  NOTE:  if the index is higher than the number of contacts - 1, do nothing.
Example: 
d
1

Get a contact:
Code: g
First parameter:  0-based index of the contact.
Example:
g
1
Output to stdout: The value of the requested field, terminated with a \n.  E.g. "WILSON,HORACE,hwilson@mayoclinic.com,8001110008\n"

Get a field:
Code: f
First parameter:  0-based index of the contact.
Second parameter: Name of the field to get.  Valid values are firstName, lastName, email, phoneNumber.
Example:
f
1
lastName
Output to stdout: The value of the requested field, terminated with a \n.  E.g. "SMITH\n"

Get the number of contacts in the list:
Code: n
Example:
n
Output to stdout:  The number of contacts in the list, terminated with a \n.  E.g. "10\n".

Load a file:
Code: l
First parameter:  path of the file to load.
Notes: The file format is CSV.  There is one header line that describes the fields, then one contact per line thereafter.  The order of the contact information is the same as that of the second parameter of the add command.  If the address book is not empty, this command adds the loaded contacts at the end of the current list.  Here is an example file  (note: if you want to see what's in this file, open it in a text editor rather than a spreadsheet program).
Example: 
l
mycontacts.csv

Save the contacts to a file:
Code: s
First parameter:  path of the file to save to.
Notes:  The file format is CSV, one contact per line.  If the file already exists, it is overwritten.  
Example: 
s
mycontacts.csv

Quit program:
Code: q
Example:
q
Output to stdout:  "Complete\n"
