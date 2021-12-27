#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <time.h>
#include <fstream>

using namespace std;

int main();
int mygetch();
void prepare(int n);
void check();
void save_data(int n);
void save_res();
int gamilton (int k);
void printGam();
void printGam_s();
int** create(int n);
int** m_create(int n);
void size_A();
void size_M();
void pos(int a);
int mainmenu();
