#ifndef LCSTRING_H
#define LCSTRING_H

#pragma once
#include <cstring>
#include <cstdio>
#include <cstdlib>

#define LCstring char*

/* #define out(str) printf("%s\n", str)
#define out_v(x) printf("%s: %d\n", #x, x)
#define out_s(x) printf("%s: %s\n", #x, x)
#define out_c(x) printf("%s: %c\n", #x, x) */

// Just an append function. It appends str onto source.
void Append(LCstring str, LCstring* source);

// Preappend destination into source.
void Preappend(LCstring destination, LCstring* source);

// Replaces X in source with Y 
// NOTE: Only works with allocated (malloc) variables at the moment.
void Replace(LCstring X, LCstring* source, LCstring Y);

// Returns a substring from x to y in source 
LCstring SubString(int x, LCstring source, int y);

// Returns the first index of the word in source
int Find(LCstring word, LCstring source);

// Exactly the same as normal find but starting at index n
int Find_n(LCstring word, LCstring source, int n);

// Returns how many of word are in source. 
// NOTE: Could rename function to FindAll or How_Many
int FindAllOccurrences(LCstring word, LCstring source);

// Removes all characters from min to max
void Remove(LCstring* source, int min, int max);

// Gets all of the characters to the left of index
LCstring Left(LCstring source, int index);

// Gets all of the characters to the right of index
LCstring Right(LCstring source, int index);

// Inserts word at index in source
void Insert(LCstring word, int index, LCstring* source);

// Changes string to lowercase.
extern inline void Lower(LCstring string);

// Changes string to uppercase.
extern inline void Upper(LCstring string);

// Returns the strings length.
extern inline int Length(LCstring string);

// Replaces characters in range min to max within string source with character p.
void Replace_Range(LCstring source, int min, int max, char p);

// Sets the specified string(source) to another string(destination).
void SetSpecial(LCstring source, LCstring destination);

// Adds padding of thickness amount of character arround word
void AddPadding(LCstring* source, char* character, int thickness);

#endif