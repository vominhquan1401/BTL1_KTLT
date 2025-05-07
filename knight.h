#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "main.h"

int LEVELO(int count);
bool primeNumber(int n);
string HERO(int maxhp);
void MUSHMARIO(int& HP, int maxhp, int level, int& phoenix);
int Shaman(int& HP, int maxhp, int& level, int& Remedy, int& phoenix, int ThuTuSuKien, int minisize, int frog);
bool isFibonacci(int n);
void fibo_mush(int& HP);
int BaseDamage(int event1To5);
int Damage(int sukien, int count, int& level);
bool CheckHP(int& HP, int maxhp, int& phoenixdown, int& minisize, int& frog, int& level, int templevel);
int Vajsh(int& HP, int& level, int templevel, int& maidenkiss, int& phoenix, int ThuTuSuKien, int minisize, int frog);
void Aclepius(string file_aclepius_pack, int& HP, int maxhp, int templevel, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& minisize, int& frog);
void Merlin(string file_merlin_pack, int& HP, int max_hp);
void MushG(char type, int mushG[], int n2, int& HP, int maxhp, int& phoenixdown, int& minisize, int& rescue, int& frog, int& level, int templevel);
void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue);
void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue);

#endif // __KNIGHT_H__