#include <iostream>
#include "temperature.h"
#include  <fstream>
#include  <sstream>
using namespace std;


//FUNZIONE VISTA INSIEME IN LAB
void inserisciConsumi(float m[APP][GIORNI]) {
    for (int i = 0; i < APP; i++) {
        for (int j = 0; j < GIORNI; j++) {
            cout << "Consumo appartamento " << i << " giorno " << j << ": ";
            cin >> m[i][j];
        }
    }
}


//IMPLEMENTA LE FUNZIONI RICHIESTA

//Implementa la funzione per poter stampare i dati inseriti
void mostraTabella(float m[APP][GIORNI]) {
    for (int i = 0; i < APP; i++) {
        cout << "Appartamento " << i << ": ";
        for (int j = 0; j < GIORNI; j++) {
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}


/*La funzione deve chiedere all’utente quale appartamento analizzare
Deve controllare che il valore inserito sia valido
Deve calcolare la somma dei consumi di quell’appartamento
Deve stampare il totale
*/

void totaleAppartamento(float m[APP][GIORNI]) {
    int sceltaApp;
    cout << "Di quale appartamento (0-2) vuoi il totale? ";
    cin >> sceltaApp;

    if (sceltaApp >= 0 && sceltaApp < APP) {
        float somma = 0;
        for (int j = 0; j < GIORNI; j++) {
            somma += m[sceltaApp][j];
        }
        cout << "Totale consumi: " << somma << " kWh" << endl;
    } else {
        cout << "Indice non valido!" << endl;
    }
}
void salvaCsv(float m[APP][GIORNI]) {
    //ofstream file;
    //file.open("consumi.csv");

    ofstream file("consumi.csv");
    if (!file) {
        cout<<"Errore nel salvataggio del file";
        return;
    }
    for (int  i=0; i<APP; i++) {
        file << i;
        //scrive nel file il numero dell'appartamento
        for (int j=0;j<GIORNI;j++) {
            file << "," << m[i][j];
        } //scrive una virgola e poi il consumo del giorno j
        file << "\n";
        //finiti tutti i giorni di quell'appartamento,
        //va  capo e passa alla riga dell appartamento successivo'
    }
    file.close();
    cout << "Dati salvati im consumi.csv";
}
void leggiCsv(float m[APP][GIORNI]) {
    ifstream file("consumi.csv");
    if (!file) {
        cout<< "File non trovato!";
        return;
    }
    string riga;
    //variabile che conterrà una riga intera letta dal file
    for (int i=0; i<APP;i++) {
        if (!getline(file, riga)) {
            cout <<"Dati non presenti";
            file.close();
            return;
        }
        //getline=prova a leggere una riga del file
        // se non riesce, significa file vuoto
        if (riga == "") {
            cout << "Dati non presenti nel file";
            //se la riga letta è vuota non ci sono dati da caricare
            file.close();
        }
        //Stringstream è una classe che permette di leggere da una stringa come se fosse un flusso di input
        stringstream ss(riga);
        //trasformo la riga in un flusso di lettura, in questo modo posso leggere i valori uno alla volta
        //separati dalla virgola.
        string valore;
        //variabile temporanea che conterrà ogni singolo valore letto nel file
        for (int j=0;j<GIORNI;j++) {
            if (!getline(ss,valore,',')) {
                cout << "Dati non presenti\n";
                file.close();
                return;
            }
             if (valore== "") {
                 cout << "Dati non presenti\n";
                 file.close();
                 return;
             }
            m[i][j]=stof(valore);
        }
    }
    file.close();
    cout << "Dati caricati da csv";
}