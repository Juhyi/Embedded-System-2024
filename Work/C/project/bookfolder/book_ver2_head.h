/*
FILE: book_ver2.head.h
Created: 24-03-27
Author: 이주희
*/
#ifndef BOOK_VER2_H
#define BOOK_VER2_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BOOKINFO{
	char title[100];
	char writer[100];
	int year;
	int rented;
	struct BOOKINFO* next;
}book;

book* bookRegister(book*);
void showBooks(book*);
void deleteBooks(book*);
void searchBooks(book*);
void rentBooks(book*);
void returnBooks(book*);

#endif
