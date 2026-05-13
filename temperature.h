#ifndef FILE_H
#define FILE_H

const int APP = 3;
const int GIORNI = 7;



//PROSEGUI DICHIARANDO LE ALTRE DUE FUNZIONI NECESSARIE
void inserisciConsumi(float m[APP][GIORNI]);
void mostraTabella(float m[APP][GIORNI]);
void totaleAppartamento(float m[APP][GIORNI]);
void salvaCsv(float m[APP][GIORNI]);
void leggiCsv(float m[APP][GIORNI]);


#endif