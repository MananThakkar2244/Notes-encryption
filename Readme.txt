NOTES LOCKER - USER GUIDE

----------------------------------------
ABOUT
----------------------------------------

Notes Locker is a simple C++ based file locking utility.

It works by renaming files with a ".locked" extension.
When unlocked, the file opens normally.
After 1 hour, the file automatically relocks.

This program is designed for controlled access to notes.


----------------------------------------
HOW IT WORKS
----------------------------------------

1. Run NotesLocker.exe
2. Choose whether you are an Admin or Regular User
3. Enter the correct password
4. Select the note you want to open
5. The file unlocks and opens
6. After 1 hour, it automatically locks again


----------------------------------------
IMPORTANT
----------------------------------------

- All note files must be in the same folder as NotesLocker.exe
- Files must already have the ".locked" extension before running
- Do not rename files manually while the timer is running
- Do not close the program before the timer ends if you want auto-relock


----------------------------------------
SECURITY NOTE
----------------------------------------

This program uses file renaming for locking.
It does NOT use real encryption.

It is intended for basic access control only.


----------------------------------------
FILES INCLUDED
----------------------------------------

NotesLocker.exe
ASC_QB.pdf.locked
MATH_QB.pdf.locked
CON_QB.pdf.locked
WSD_QB.pdf.locked
CPP_QB.pdf.locked


----------------------------------------
CREATED BY
----------------------------------------

Manan
C++ Student Project
IMPORTANT note:-
this is created with the help of AI ,i.e 30% of coding is done by AI at the end and 70% of coding 
is done by me from the start