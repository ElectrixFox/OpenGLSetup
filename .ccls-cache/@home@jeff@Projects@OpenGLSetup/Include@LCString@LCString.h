#ifndef LCSTRING_H
#define LCSTRING_H

#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define LCstring char*

#ifndef LCSTRING_HEADERONLY

#define out(str) printf("%s\n", str)
#define out_v(x) printf("%s: %d\n", #x, x)
#define out_s(x) printf("%s: %s\n", #x, x)
#define out_c(x) printf("%s: %c\n", #x, x)

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


#else

void Append(LCstring str, LCstring* source) 
{
    // Allocates source to avoid not working.
    LCstring temp = *source;
    *source = malloc(sizeof(LCstring) * 128);
    strcpy(*source, temp);

    // Frees temp as it is no longer needed.
    free(temp);

    // Sets a n_source to the de reffed pointer to make it easier to read.
    LCstring n_source = *source;

    const LCstring n_str = str;

    int str_len = strlen(n_str);

    // Adds n_str onto the string at the end of n_source (because it is coppied at the length of n_source)
    memcpy(n_source + strlen(n_source), n_str, str_len + 1);
}

void Preappend(LCstring destination, LCstring* source)
{
    {
        // New temp string to store the origional source safely during allocation.
        LCstring temp = *source;
        *source = malloc(sizeof(LCstring) * 128);

        // Coppies the origional source into the new allocted source.
        strcpy(*source, temp);
    }

    // A separate variable just for derefferenced source so that I don't have to dereff it every time.
    LCstring n_source = *source;
    
    // String to preappend
    const LCstring n_str = destination;
    
    // Move the origional string that many moves to the right so something can be moved before it.
    int str_len = strlen(n_str);

    // Add one because for some reason it stops corruption.
    memmove(n_source + str_len, n_source, strlen(n_source) + 1);

    // Coppies the new string into the begining of the old one.
    memcpy(n_source, n_str, str_len);
}

void Replace(LCstring X, LCstring* source, LCstring Y) 
{
    {
        // Creates a new temp variable to that source can be allocated memory.
        LCstring temp = *source;
        *source = malloc(sizeof(char*) * 128);

        // Coppies temp into the new allocated source.
        strcpy(*source, temp);

        // Clears temp as it is no longer needed.
        free(temp);
    }

    // Allocates a new variable for using
    LCstring t_str = malloc(sizeof(char*) * 128);

    // Coppies source into it so that t_str can act like source.
    strcpy(t_str, *source);

    int x_len = strlen(X);

    // Find the location of X in source
    int location = Find(X, t_str);

    // Coppies Y into source from location onwards for x length
    memcpy(&t_str[location], Y, x_len);

    // Sets source to t_str.
    *source = t_str;
}

LCstring SubString(int x, LCstring source, int y) 
{
    int n_len = y - x;
    LCstring Substr = malloc(sizeof(LCstring) * n_len);

    // Coppies from x in source to the length of the substring determined by y - x 
    memcpy(Substr, &source[x], y-x);

    // Null terminator to stop corruption
    Substr[y-x] = '\0';

    return Substr;
}

int Find(LCstring word, LCstring source) 
{
    int Length = strlen(word);

    int index = -1;
    // Through the length of the source checking
    for (int i = 0; i < strlen(source); i++)
    {
        // Compares a substring from i to the words length in source to the actual word.
        if(!strcmp(SubString(i, source, i+Length), word))
        {
            index = i;
            break;
        }
    }

    return index;
}

int Find_n(LCstring word, LCstring source, int n) 
{
    int Length = strlen(word);
    int index = -1;

    for (int i = n; i < strlen(source); i++)
    {
        if(!strcmp(SubString(i, source, i+Length), word))
        {
            index = i;
            break;
        }
    }

    return index;
}

int FindAllOccurrences(LCstring word, LCstring source)
{
    int count = 0;
    LCstring temp = malloc(sizeof(char*) * 128);
    strcpy(temp, word);
    //AddPadding(&temp, " ", 1);

    LCstring n_word = temp;

    int len = Length(source);
    int w_len = Length(n_word);

    out_v(len);
    out_s(n_word);
    out_s(source);

    int index = 0;

    for (int i = 0; i < len; i++)
    {
        int Find_IX = Find_n(n_word, source, index);

        if(Find_IX != -1)
        {
            // Checks if previous character is a begining a null character or a space if not then it terminates it.
            if(!(source[Find_IX - 1] == 2 ||
                source[Find_IX - 1] == 0 ||
                source[Find_IX - 1] == 32))
            {
                out_v(source[Find_IX + w_len]);

                break;
            }
            // Checks if next character is a begining a null character or a space if not then it terminates it.
            if(!(source[Find_IX + w_len] == 2 ||
                    source[Find_IX + w_len] == 0 || 
                    source[Find_IX + w_len] == 32))
                {
                    out_v(source[Find_IX + w_len]);
                    break;
                }
            
            count++;
            index = Find_IX + w_len;

            //out_v(index-w_len);
            //out_c(source[index-w_len]);
            //out_s(SubString(index-w_len, source, index));
        }
        else
        {
            break;
        }
    }
    
    

    return count;
}

void Remove(LCstring* source, int min, int max) 
{
    int n_len = max - min;

    // Litterally just a little thing that I've found to work for fixing strings.
    {
        // New temp string to store the origional source safely during allocation.
        LCstring temp = *source;
        *source = malloc(sizeof(LCstring) * 128);

        // Coppies the origional source into the new allocted source.
        strcpy(*source, temp);
    }

    LCstring n_source = *source;
    
    // This starts the source at min and then inserts maximum for the length of the source - the length add one
    // Even this kind of confuses me
    memmove(&n_source[min], &n_source[max], strlen(n_source) - n_len + 1);
}

LCstring Left(LCstring source, int index) 
{
    return SubString(0, source, index);
}

LCstring Right(LCstring source, int index) 
{
    return SubString(index, source, strlen(source));
}

void Insert(LCstring word, int index, LCstring* source) 
{
    LCstring temp = *source;
    *source = malloc(sizeof(LCstring) * 128);
    strcpy(*source, temp);
}

extern inline void Lower(LCstring string) 
{
    strlwr(string);
}

extern inline void Upper(LCstring string) 
{
    strupr(string);
}

extern inline int Length(LCstring string) 
{
    return strlen(string);
}

void Replace_Range(LCstring source, int min, int max, char p) 
{
    for (int i = min; i < max; i++)
        source[i] = p;
}

void SetSpecial(LCstring source, LCstring destination) 
{
    LCstring n_source = source;
    source = malloc(sizeof(char*) * Length(destination));
    strcpy(source, destination);
}

void AddPadding(LCstring* source, char* character, int thickness) 
{
    LCstring temp = *source;
    *source = malloc(sizeof(LCstring) * 128);
    strcpy(*source, temp);

    LCstring n_source = *source;

    for (int i = 0; i < thickness; i++)
    {
        Preappend(character, &n_source);
        Append(character, &n_source);
    }
    Append("\0", &n_source);

    *source = n_source;
}

#endif

#endif