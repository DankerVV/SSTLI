//  Operaciones.cpp
//  Programa-STLI
//  Created by Carlos Salcido on 27/10/22.
#include<stdlib.h>
#include<time.h>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

struct linea{
    char contloc[4];
    char source[18];
    char op[10];
    char resultado[30];
    char linea[50];
}rg[30];
char temp[4];

struct etiqueta{
    char etq[4];
}et[5];

void dec_to_hex(int dec, int i);
void oct_to_hex(int oct, int i);
void bin_to_hex(int bin, int i);
void formula1_neg(int dec, int i);
void formula1_pos(int dec, int i);
void formula2_pos(int dec, int i);
void formula2_neg(int dec, int i);
void formula3(int i);
void formula3_larga(int i);
void formula4_neg(int dec, int i);
void formula4_pos(int dec, int i);
void resta_2_bytes(int i, char etq1, char etq2, char etq3, char etq4, char contl1, char contl2, char contl3, char  contl4);
void resta_4_bytes(int i, char etq1, char etq2, char etq3, char etq4, char contl1, char contl2, char contl3, char  contl4);
int hex_to_dec_1byte(char hex);
char dec_to_hex_1byte(int dec);
int dec_to_binary(int dec);
void resta_IBNE(int i, char ABDXYSP, char etq1, char etq2, char etq3, char etq4, char contl1, char contl2, char contl3, char  contl4);

void hola(){////////////////////////////////////////////////////////////////////////////////////////////////////////////HOLA MUNDO
    cout<<"Hola Mundo"<<endl;
}

void lectura(){////////////////////////////////////////////////////////////////////////////////////////////////////////////LEER EL ARCHIVO .ASM
    hola();
    char texto;
    int i=0, j=0, band=0;
    ifstream archivo;
    archivo.open("/Users/carlossalcidoa/Documents/CUCEI - INCO/Semestre 5/STLI/P14.asm", ios::in);//Abrir

    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo\n";
        exit(1);
    }

    while(!archivo.eof()){
        archivo.get(texto);

        if(texto!='\t'){
            if(texto!='\n'){
                if(band==0){
                    rg[i].source[j] = texto;
                    j++;
                    if(texto==' '){
                        band++;
                        j=0;
                    }
                }
                else{//band diferente a 0
                    rg[i].op[j] = texto;
                    j++;
                }
            }
        }
        else{
            i++;
            j=0;
            band=0;
        }
    }
    cout<<endl<<endl;
    archivo.close();
    
    for(int i=0;i<=30;i++){//MOSTRAR LOS REGISTROS
        for(int j=0;j<=18;j++){
            cout<<rg[i].source[j];
        }
        for(int k=1;k<10;k++){
            cout<<rg[i].op[k];
        }
    }
}

void escribir(){////////////////////////////////////////////////////////////////////////////////////////////////////////////ESCRIBIR EL ARCHIVO .LST
    ofstream archivo;
    
    archivo.open("/Users/carlossalcidoa/Documents/CUCEI - INCO/Semestre 5/STLI/PruebaAct14.lst");
    if(archivo.fail()){
        cout<<"No se pudo crear el archivo\n";
        exit(1);
    }
    for(int i=0;i<=25;i++){//MOSTRAR LOS REGISTROS
        for(int j=0; j<=35; j++){
            archivo<<rg[i].linea[j];
            
        }
        archivo<<endl;
    }
    for(int i=1; i<5; i++){
        archivo<<"Etiqueta " << i << ": ";
        archivo<<et[i].etq[0];
        archivo<<et[i].etq[1];
        archivo<<et[i].etq[2];
        archivo<<et[i].etq[3];
        archivo<<endl;
    }
    archivo.close();
}
void mostrar_todo(){////////////////////////////////////////////////////////////////////////////////////////////////////////////MOSTRAR_TODO
    for(int i=0;i<=30;i++){//MOSTRAR LOS REGISTROS
        
        for(int l=0;l<4;l++){
            cout<<rg[i].contloc[l];
        }
        for(int j=0;j<=18;j++){
            cout<<rg[i].source[j];
        }
        for(int k=1;k<10;k++){
            cout<<rg[i].op[k];
            //cout<<"_";
        }
    }
}

void mostrar_lineas(){////////////////////////////////////////////////////////////////////////////////////////////////////////////MOSTRAR LINEAS
    for(int i=0;i<=25;i++){//MOSTRAR LOS REGISTROS
    cout<<rg[i].linea[0];
    cout<<rg[i].linea[1];
    cout<<rg[i].linea[2];
    cout<<rg[i].linea[3];
    cout<<rg[i].linea[4];
    cout<<rg[i].linea[5];
    cout<<rg[i].linea[6];
    cout<<rg[i].linea[7];
    cout<<rg[i].linea[8];
    cout<<rg[i].linea[9];
    cout<<rg[i].linea[10];
    cout<<rg[i].linea[11];
    cout<<rg[i].linea[12];
    cout<<rg[i].linea[13];
    cout<<rg[i].linea[14];
    cout<<rg[i].linea[15];
    cout<<rg[i].linea[16];
    cout<<rg[i].linea[17];
    cout<<rg[i].linea[18];
    cout<<rg[i].linea[19];
    cout<<rg[i].linea[20];
    cout<<rg[i].linea[21];
    cout<<rg[i].linea[22];
    cout<<rg[i].linea[23];
    cout<<rg[i].linea[24];
    cout<<rg[i].linea[25];
    cout<<rg[i].linea[26];
    cout<<rg[i].linea[27];
    cout<<rg[i].linea[28];
    cout<<rg[i].linea[29];
    cout<<rg[i].linea[30];
    cout<<rg[i].linea[31];
    cout<<rg[i].linea[32];
    cout<<rg[i].linea[33];
    cout<<rg[i].linea[34];
    cout<<rg[i].linea[35];
    cout<<endl;
}}

void arreglar_contloc(int y){////////////////////////////////////////////////////////////////////////////////////////////////////////////ACTUALIZAR CONTLOC
    int bandera;
    while (y>0) {
        bandera=0;
        if(temp[2]=='1' && temp[3]=='F'){
            temp[2]='2';
            temp[3]='0';
            bandera=1;
        }
        if(temp[3]=='F'){
            temp[2]='1';
            temp[3]='0';
            bandera=1;
        }
        if(temp[3]=='E'){
            temp[3]='F';
        }
        if(temp[3]=='D'){
            temp[3]='E';
        }
        if(temp[3]=='C'){
            temp[3]='D';
        }
        if(temp[3]=='B'){
            temp[3]='C';
        }
        if(temp[3]=='A'){
            temp[3]='B';
        }
        if(temp[3]=='9'){
            temp[3]='A';
        }
        if(temp[3]=='8'){
            temp[3]='9';
        }
        if(temp[3]=='7'){
            temp[3]='8';
        }
        if(temp[3]=='6'){
            temp[3]='7';
        }
        if(temp[3]=='5'){
            temp[3]='6';
        }
        if(temp[3]=='4'){
            temp[3]='5';
        }
        if(temp[3]=='3'){
            temp[3]='4';
        }
        if(temp[3]=='2'){
            temp[3]='3';
        }
        if(temp[3]=='1'){
            temp[3]='2';
        }
        if(temp[3]=='0' && bandera==0){
            temp[3]='1';
        }
        y=y-1;
    }
}

void first_read(){////////////////////////////////////////////////////////////////////////////////////////////////////////////CALCULAR CONTLOC
    temp[0]='0';//Inicializar CONTLOC en 0000
    temp[1]='0';
    temp[2]='0';
    temp[3]='0';
    for(int i=0;i<=30;i++){//MOSTRAR LOS REGISTROS
        if(rg[i].source[0]=='O'){////////////////////ORG CASE
            rg[i].linea[0]=rg[i].contloc[0]=temp[0];
            rg[i].linea[1]=rg[i].contloc[1]=temp[1];
            rg[i].linea[2]=rg[i].contloc[2]=temp[2];
            rg[i].linea[3]=rg[i].contloc[3]=temp[3];
            for(int x=0; x<5;x++){//Tomar el valor del ORG
                temp[x]=rg[i].op[x+1];
            }
        }//FIN ORG
        if(rg[i].source[0]=='L'&&rg[i].source[1]=='D'&&rg[i].source[2]=='A'&&rg[i].source[3]=='A'){////////////////////LDAA CASE
            rg[i].linea[0]=rg[i].contloc[0]=temp[0];
            rg[i].linea[1]=rg[i].contloc[1]=temp[1];
            rg[i].linea[2]=rg[i].contloc[2]=temp[2];
            rg[i].linea[3]=rg[i].contloc[3]=temp[3];
            if(((rg[i].op[0]=='[')==false)&&(rg[i].op[1]==','||rg[i].op[2]==','||
                rg[i].op[3]==','||rg[i].op[4]==',')){//IDENTIFICAR LDAA CON , y sin [
                arreglar_contloc(3);
            }
            if(rg[i].op[0]=='['&&(rg[i].op[1]==','||rg[i].op[2]==','||
                rg[i].op[3]==','||rg[i].op[4]==',')){//IDENTIFICAR LDAA CON , y con [
                arreglar_contloc(4);
            }
            if(rg[i].op[0]=='#' || rg[i].op[0]=='@' || rg[i].op[0]=='$'){//IDENTIFICAR LDAA normal
                arreglar_contloc(2);
            }
        }//FIN LDAA
        if(rg[i].source[0]=='B'&&rg[i].source[1]=='N'&&rg[i].source[2]=='E'){////////////////////BNE CASE
            rg[i].linea[0]=rg[i].contloc[0]=temp[0];
            rg[i].linea[1]=rg[i].contloc[1]=temp[1];
            rg[i].linea[2]=rg[i].contloc[2]=temp[2];
            rg[i].linea[3]=rg[i].contloc[3]=temp[3];
            arreglar_contloc(2);
        }//FIN BNE
        if(rg[i].source[0]=='J'&&rg[i].source[1]=='M'&&rg[i].source[2]=='P'){////////////////////JMP CASE
            rg[i].linea[0]=rg[i].contloc[0]=temp[0];
            rg[i].linea[1]=rg[i].contloc[1]=temp[1];
            rg[i].linea[2]=rg[i].contloc[2]=temp[2];
            rg[i].linea[3]=rg[i].contloc[3]=temp[3];
            if((rg[i].op[1]==','||rg[i].op[2]==','||
                rg[i].op[3]==','||rg[i].op[4]==',')){//IDENTIFICAR JMP CON ,
                arreglar_contloc(3);//AQUI HAY ALGO RARO, PERO NOMAS ASI FUNCIONA
            }
            else{//IDENTIFICAR JMP normal
                arreglar_contloc(3);
            }
        }//FIN JMP
        if(rg[i].source[0]=='L'&&rg[i].source[1]=='B'&&rg[i].source[2]=='N'){////////////////////LBNE CASE
            rg[i].linea[0]=rg[i].contloc[0]=temp[0];
            rg[i].linea[1]=rg[i].contloc[1]=temp[1];
            rg[i].linea[2]=rg[i].contloc[2]=temp[2];
            rg[i].linea[3]=rg[i].contloc[3]=temp[3];
            arreglar_contloc(4);
        }//FIN LBNE
        if(rg[i].source[0]=='I'&&rg[i].source[1]=='B'&&rg[i].source[2]=='N'){////////////////////IBNE CASE
            rg[i].linea[0]=rg[i].contloc[0]=temp[0];
            rg[i].linea[1]=rg[i].contloc[1]=temp[1];
            rg[i].linea[2]=rg[i].contloc[2]=temp[2];
            rg[i].linea[3]=rg[i].contloc[3]=temp[3];
            arreglar_contloc(3);
        }//FIN IBNE
        if(rg[i].source[0]=='B'&&rg[i].source[1]=='S'&&rg[i].source[2]=='Z'){////////////////////BSZ CASE
            rg[i].linea[0]=rg[i].contloc[0]=temp[0];
            rg[i].linea[1]=rg[i].contloc[1]=temp[1];
            rg[i].linea[2]=rg[i].contloc[2]=temp[2];
            rg[i].linea[3]=rg[i].contloc[3]=temp[3];
            if(rg[i].op[1]=='0'||rg[i].op[1]=='1'||rg[i].op[1]=='2'||rg[i].op[1]=='3'
               ||rg[i].op[1]=='4'||rg[i].op[1]=='5'||rg[i].op[1]=='6'||rg[i].op[1]=='7'
               ||rg[i].op[1]=='8'||rg[i].op[1]=='9'){//2 cifras
                int temp_dec = ((int(rg[i].op[0])-48)*10) + ((int(rg[i].op[1])-48)*1);
                arreglar_contloc(temp_dec);
            }
            else{
                int temp_dec = ((int(rg[i].op[0])-48)*1);// + ((int(rg[i].op[1])-48)*1);
                arreglar_contloc(temp_dec);}
        }//FIN BSZ
        if(rg[i].source[0]=='D'&&rg[i].source[1]=='C'&&rg[i].source[3]=='W'){////////////////////DC.W CASE
            rg[i].linea[0]=rg[i].contloc[0]=temp[0];
            rg[i].linea[1]=rg[i].contloc[1]=temp[1];
            rg[i].linea[2]=rg[i].contloc[2]=temp[2];
            rg[i].linea[3]=rg[i].contloc[3]=temp[3];
            if(rg[i].op[1]==','||rg[i].op[2]==','||
                rg[i].op[3]==','||rg[i].op[4]==','){//IDENTIFICAR DC.W CON ,
                arreglar_contloc(4);
            }
            if(rg[i].op[0]==NULL){
                arreglar_contloc(2);
            }
            if((rg[i].op[1]==','||rg[i].op[2]==','||
               rg[i].op[3]==','||rg[i].op[4]==',')==false){
                arreglar_contloc(2);
            }
        }//FIN DC.W
        if(rg[i].source[0]=='A'&&rg[i].source[1]=='B'&&rg[i].source[2]=='A'){////////////////////ABA CASE
            rg[i].linea[0]=rg[i].contloc[0]=temp[0];
            rg[i].linea[1]=rg[i].contloc[1]=temp[1];
            rg[i].linea[2]=rg[i].contloc[2]=temp[2];
            rg[i].linea[3]=rg[i].contloc[3]=temp[3];
            arreglar_contloc(2);
        }//FIN ABA
        if(rg[i].source[0]=='A'&&rg[i].source[1]=='D'&&rg[i].source[2]=='C'){////////////////////ADCA CASE
            rg[i].linea[0]=rg[i].contloc[0]=temp[0];
            rg[i].linea[1]=rg[i].contloc[1]=temp[1];
            rg[i].linea[2]=rg[i].contloc[2]=temp[2];
            rg[i].linea[3]=rg[i].contloc[3]=temp[3];
            arreglar_contloc(2);
        }//FIN ADCA
        if(rg[i].source[0]=='A'&&rg[i].source[1]=='D'&&rg[i].source[2]=='D'){////////////////////ADDD CASE
            rg[i].linea[0]=rg[i].contloc[0]=temp[0];
            rg[i].linea[1]=rg[i].contloc[1]=temp[1];
            rg[i].linea[2]=rg[i].contloc[2]=temp[2];
            rg[i].linea[3]=rg[i].contloc[3]=temp[3];
            if(rg[i].op[0]=='#')
                arreglar_contloc(3);
            else
                arreglar_contloc(2);
        }//FIN ADDD
        if(rg[i].source[0]=='E'&&rg[i].source[1]=='Q'&&rg[i].source[2]=='U'){////////////////////EQU CASE
            rg[i].linea[0]=rg[i].contloc[0]=temp[0];
            rg[i].linea[1]=rg[i].contloc[1]=temp[1];
            rg[i].linea[2]=rg[i].contloc[2]=temp[2];
            rg[i].linea[3]=rg[i].contloc[3]=temp[3];
        }//FIN EQU
        if(rg[i].source[0]=='A'&&rg[i].source[1]=='S'&&rg[i].source[2]=='L'){////////////////////ASL CASE
            rg[i].linea[0]=rg[i].contloc[0]=temp[0];
            rg[i].linea[1]=rg[i].contloc[1]=temp[1];
            rg[i].linea[2]=rg[i].contloc[2]=temp[2];
            rg[i].linea[3]=rg[i].contloc[3]=temp[3];
            if(rg[i].op[0]=='['){//[
                arreglar_contloc(4);}
            if(rg[i].op[0]!=',' && rg[i].op[1]!=',' && rg[i].op[2]!=',' && rg[i].op[3]!=','){
                arreglar_contloc(3);
            }
            if(rg[i].op[1]==','||rg[i].op[2]==','||rg[i].op[3]==','){
                if((rg[i].op[0]=='[')==false){
                    if(rg[i].op[2]!='-'&&rg[i].op[2]!='+'&&rg[i].op[4]!='+'&&rg[i].op[4]!='-'&&rg[i].op[5]!='+'&&rg[i].op[5]!='-'){
                        arreglar_contloc(2);
                    }
                }
            }
            if(rg[i].op[1]==','||rg[i].op[2]==','||rg[i].op[3]==','){
                if((rg[i].op[0]=='[')==false){
                    if(rg[i].op[2]=='-'||rg[i].op[2]=='+'||rg[i].op[4]=='+'||rg[i].op[4]=='-'||rg[i].op[5]=='+'||rg[i].op[5]=='-'){
                        arreglar_contloc(2);
                    }
                }
            }
        }//FIN ASL
        if(rg[i].source[0]=='C'&&rg[i].source[1]=='M'&&rg[i].source[2]=='P'){////////////////////CMPA CASE
            rg[i].linea[0]=rg[i].contloc[0]=temp[0];
            rg[i].linea[1]=rg[i].contloc[1]=temp[1];
            rg[i].linea[2]=rg[i].contloc[2]=temp[2];
            rg[i].linea[3]=rg[i].contloc[3]=temp[3];
            arreglar_contloc(3);
        }//FIN CMPA
        if(rg[i].source[0]=='C'&&rg[i].source[1]=='L'&&rg[i].source[2]=='R'){////////////////////CLR CASE
            rg[i].linea[0]=rg[i].contloc[0]=temp[0];
            rg[i].linea[1]=rg[i].contloc[1]=temp[1];
            rg[i].linea[2]=rg[i].contloc[2]=temp[2];
            rg[i].linea[3]=rg[i].contloc[3]=temp[3];
            arreglar_contloc(3);
        }//FIN CLR
        if(rg[i].source[0]=='S'&&rg[i].source[1]=='T'&&rg[i].source[2]=='A'){////////////////////START CASE
            rg[i].linea[0]=rg[i].contloc[0]=temp[0];
            rg[i].linea[1]=rg[i].contloc[1]=temp[1];
            rg[i].linea[2]=rg[i].contloc[2]=temp[2];
            rg[i].linea[3]=rg[i].contloc[3]=temp[3];
            temp[0]='0';//Inicializar CONTLOC en 0000
            temp[1]='0';
            temp[2]='0';
            temp[3]='0';
        }//FIN START
        if(rg[i].source[0]=='E'&&rg[i].source[1]=='N'&&rg[i].source[2]=='D'){////////////////////END CASE
            rg[i].linea[0]=rg[i].contloc[0]=temp[0];
            rg[i].linea[1]=rg[i].contloc[1]=temp[1];
            rg[i].linea[2]=rg[i].contloc[2]=temp[2];
            rg[i].linea[3]=rg[i].contloc[3]=temp[3];
        }//FIN END
    }//FIN FOR
    mostrar_lineas();
    cout<<endl;
    mostrar_todo();
}//FIN FUNCIÓN

void buscar_etiquetas(){////////////////////////////////////////////////////////////////////////////////////////////////////////////BUSCAR ETIQUETAS
    cout<<endl;
    for(int i=0;i<=30;i++){//MOSTRAR LOS REGISTROS
        /*for(int l=0;l<4;l++){
            cout<<rg[i].contloc[l];
        }
        for(int j=0;j<=18;j++){
            cout<<rg[i].source[j];
        }*/
        for(int k=1;k<10;k++){
            //cout<<rg[i].op[k];
            if(k>1 && rg[i].op[k-1]!=',' && rg[i].op[k]=='E' && rg[i].op[k+1]=='T'){//ENCONTRAR ETIQUETAS
                if(rg[i].op[k+2]=='1'){
                    et[1].etq[0]=rg[i+1].contloc[0];
                    et[1].etq[1]=rg[i+1].contloc[1];
                    et[1].etq[2]=rg[i+1].contloc[2];
                    et[1].etq[3]=rg[i+1].contloc[3];
                }
                if(rg[i].op[k+2]=='2'){
                    et[2].etq[0]=rg[i+1].contloc[0];
                    et[2].etq[1]=rg[i+1].contloc[1];
                    et[2].etq[2]=rg[i+1].contloc[2];
                    et[2].etq[3]=rg[i+1].contloc[3];
                }
                if(rg[i].op[k+2]=='3'){
                    et[3].etq[0]=rg[i+1].contloc[0];
                    et[3].etq[1]=rg[i+1].contloc[1];
                    et[3].etq[2]=rg[i+1].contloc[2];
                    et[3].etq[3]=rg[i+1].contloc[3];
                }
                if(rg[i].op[k+2]=='4'){
                    et[4].etq[0]=rg[i+1].contloc[0];
                    et[4].etq[1]=rg[i+1].contloc[1];
                    et[4].etq[2]=rg[i+1].contloc[2];
                    et[4].etq[3]=rg[i+1].contloc[3];
                }
                if(rg[i+1].source[0]=='E' && rg[i+1].source[1]=='Q'){//EQU CASE
                    if(rg[i].op[k+2]=='1'){
                        et[1].etq[0]=rg[i+1].op[1];
                        et[1].etq[1]=rg[i+1].op[2];
                        et[1].etq[2]=rg[i+1].op[3];
                        et[1].etq[3]=rg[i+1].op[4];
                    }
                    if(rg[i].op[k+2]=='2'){
                        et[2].etq[0]=rg[i+1].op[1];
                        et[2].etq[1]=rg[i+1].op[2];
                        et[2].etq[2]=rg[i+1].op[3];
                        et[2].etq[3]=rg[i+1].op[4];
                    }
                    if(rg[i].op[k+2]=='3'){
                        et[3].etq[0]=rg[i+1].op[1];
                        et[3].etq[1]=rg[i+1].op[2];
                        et[3].etq[2]=rg[i+1].op[3];
                        et[3].etq[3]=rg[i+1].op[4];
                    }
                    if(rg[i].op[k+2]=='4'){
                        et[4].etq[0]=rg[i+1].op[1];
                        et[4].etq[1]=rg[i+1].op[2];
                        et[4].etq[2]=rg[i+1].op[3];
                        et[4].etq[3]=rg[i+1].op[4];
                    }
                }
            }
        }
    }
}

void mostrar_etiquetas(){////////////////////////////////////////////////////////////////////////////////////////////////////////////MOSTRAR ETIQUETAS
    for(int i=1; i<5; i++){
        cout<<"Etiqueta " << i << ": ";
        cout<<et[i].etq[0];
        cout<<et[i].etq[1];
        cout<<et[i].etq[2];
        cout<<et[i].etq[3];
        cout<<endl;
    }
}

void second_read(){////////////////////////////////////////////////////////////////////////////////////////////////////////////MANDAR A HACER LAS OPERACIONES
    int temp_dec, temp_oct, temp_bin;
    for(int i=0;i<=30;i++){//MOSTRAR LOS REGISTROS
        if(rg[i].source[0]=='O'){//ORG CASE
            rg[i].linea[5]='\t';
            rg[i].linea[6]='\t';
            rg[i].linea[7]='\t';
            rg[i].linea[8]=rg[i].source[0];
            rg[i].linea[9]=rg[i].source[1];
            rg[i].linea[10]=rg[i].source[2];
            rg[i].linea[11]=rg[i].op[0];
            rg[i].linea[12]=rg[i].op[1];
            rg[i].linea[13]=rg[i].op[2];
            rg[i].linea[14]=rg[i].op[3];
            rg[i].linea[15]=rg[i].op[4];
        }//FIN ORG
        if(rg[i].source[0]=='L'&&rg[i].source[1]=='D'&&rg[i].source[2]=='A'&&rg[i].source[3]=='A'){////////////////////LDAA CASE
            if(((rg[i].op[0]=='[')==false)&&(rg[i].op[1]==','||rg[i].op[2]==','||
                rg[i].op[3]==','||rg[i].op[4]==',')){//IDENTIFICAR LDAA CON , y sin [, FORUMULA 1 y 2
                if(rg[i].op[0]=='-'){//VALOR NEGATIVO
                    
                    //temp_dec = ((int(rg[i].resultado[2])-48));
                    if(rg[i].op[1]=='1' && rg[i].op[2]=='6'){//formula2
                        //cout<<"aaa";
                        temp_dec = ((int(rg[i].op[1])-48)*10) + ((int(rg[i].op[2])-48)*1);
                        formula2_neg(temp_dec, i);
                        rg[i].resultado[3]='1';
                        rg[i].resultado[4]='0';
                    }
                    if(rg[i].op[1]=='1' && rg[i].op[2]=='0'){//formula1
                        temp_dec = ((int(rg[i].op[1])-48)*10) + ((int(rg[i].op[2])-48)*1);
                        formula1_neg(temp_dec, i);
                    }
                    rg[i].linea[5]='\t';
                    rg[i].linea[6]='A';
                    rg[i].linea[7]='6';
                    rg[i].linea[8]=rg[i].resultado[1];
                    rg[i].linea[9]=rg[i].resultado[2];
                    rg[i].linea[10]=rg[i].resultado[3];
                    rg[i].linea[11]=rg[i].resultado[4];
                    rg[i].linea[12]='\t';
                    rg[i].linea[13]=rg[i].source[0];
                    rg[i].linea[14]=rg[i].source[1];
                    rg[i].linea[15]=rg[i].source[2];
                    rg[i].linea[16]=rg[i].source[3];
                    rg[i].linea[17]=rg[i].op[0];
                    rg[i].linea[18]=rg[i].op[1];
                    rg[i].linea[19]=rg[i].op[2];
                    rg[i].linea[20]=rg[i].op[3];
                    rg[i].linea[21]=rg[i].op[4];
                    rg[i].linea[22]=rg[i].op[5];
                }
                else{//VALOR POSITIVO
                    temp_dec = ((int(rg[i].op[0])-48)*10) + ((int(rg[i].op[1])-48)*1);
                    formula2_pos(temp_dec, i);
                    if(rg[i].op[0]=='1' && rg[i].op[1]=='6'){
                        rg[i].resultado[2]='1';
                        rg[i].resultado[3]='0';
                    }
                    rg[i].linea[5]='\t';
                    rg[i].linea[6]='A';
                    rg[i].linea[7]='6';
                    rg[i].linea[8]=rg[i].resultado[1];
                    rg[i].linea[9]=rg[i].resultado[0];
                    rg[i].linea[10]=rg[i].resultado[2];
                    rg[i].linea[11]=rg[i].resultado[3];
                    rg[i].linea[12]='\t';
                    rg[i].linea[13]=rg[i].source[0];
                    rg[i].linea[14]=rg[i].source[1];
                    rg[i].linea[15]=rg[i].source[2];
                    rg[i].linea[16]=rg[i].source[3];
                    rg[i].linea[17]=rg[i].op[0];
                    rg[i].linea[18]=rg[i].op[1];
                    rg[i].linea[19]=rg[i].op[2];
                    rg[i].linea[20]=rg[i].op[3];
                    rg[i].linea[21]=rg[i].op[4];
                }
            }
            if(rg[i].op[0]=='['&&rg[i].op[3]==','){//IDENTIFICAR LDAA CON [__,
                rg[i].linea[5]='\t';
                rg[i].linea[6]='A';
                rg[i].linea[7]='6';
                formula3(i);
                rg[i].linea[8]=rg[i].resultado[1];
                rg[i].linea[9]=rg[i].resultado[2];
                temp_dec = ((int(rg[i].op[1])-48)*10) + ((int(rg[i].op[2])-48)*1);
                dec_to_hex(temp_dec, i);
                rg[i].linea[10]='0';
                rg[i].linea[11]='0';
                rg[i].linea[12]=rg[i].resultado[2];
                rg[i].linea[13]=rg[i].resultado[3];
                rg[i].linea[14]='\t';
                rg[i].linea[15]=rg[i].source[0];
                rg[i].linea[16]=rg[i].source[1];
                rg[i].linea[17]=rg[i].source[2];
                rg[i].linea[18]=rg[i].source[3];
                rg[i].linea[19]=rg[i].op[0];
                rg[i].linea[20]=rg[i].op[1];
                rg[i].linea[21]=rg[i].op[2];
                rg[i].linea[22]=rg[i].op[3];
                rg[i].linea[23]=rg[i].op[4];
                rg[i].linea[24]=rg[i].op[5];
                rg[i].linea[25]=rg[i].op[6];
            }
            if(rg[i].op[0]=='['&&rg[i].op[4]==','){//IDENTIFICAR LDAA CON [___,
                rg[i].linea[5]='\t';
                rg[i].linea[6]='A';
                rg[i].linea[7]='6';
                formula3_larga(i);
                rg[i].linea[8]=rg[i].resultado[1];
                rg[i].linea[9]=rg[i].resultado[2];
                temp_dec = ((int(rg[i].op[1])-48)*100) + (int(rg[i].op[2])-48)*10 + ((int(rg[i].op[3])-48)*1);
                dec_to_hex(temp_dec, i);
                rg[i].linea[10]='0';
                rg[i].linea[11]=rg[i].resultado[2];
                rg[i].linea[12]=rg[i].resultado[3];
                rg[i].linea[13]=rg[i].resultado[4];
                rg[i].linea[14]='\t';
                rg[i].linea[15]=rg[i].source[0];
                rg[i].linea[16]=rg[i].source[1];
                rg[i].linea[17]=rg[i].source[2];
                rg[i].linea[18]=rg[i].source[3];
                rg[i].linea[19]=rg[i].op[0];
                rg[i].linea[20]=rg[i].op[1];
                rg[i].linea[21]=rg[i].op[2];
                rg[i].linea[22]=rg[i].op[3];
                rg[i].linea[23]=rg[i].op[4];
                rg[i].linea[24]=rg[i].op[5];
                rg[i].linea[25]=rg[i].op[6];
                rg[i].linea[26]=rg[i].op[7];
            }
            if(rg[i].op[0]=='[' && rg[i].op[1]=='-'){//IDENTIFICAR LDAA CON con [ y -
                rg[i].linea[5]='\t';
                rg[i].linea[6]=rg[i].resultado[0]='I';
                rg[i].linea[7]=rg[i].resultado[1]='N';
                rg[i].linea[8]=rg[i].resultado[2]='V';
                rg[i].linea[9]=rg[i].resultado[3]='L';
                rg[i].linea[10]='\t';
                rg[i].linea[11]=rg[i].source[0];
                rg[i].linea[12]=rg[i].source[1];
                rg[i].linea[13]=rg[i].source[2];
                rg[i].linea[14]=rg[i].source[3];
                rg[i].linea[15]=rg[i].op[0];
                rg[i].linea[16]=rg[i].op[1];
                rg[i].linea[17]=rg[i].op[2];
                rg[i].linea[18]=rg[i].op[3];
                rg[i].linea[19]=rg[i].op[4];
                rg[i].linea[20]=rg[i].op[5];
                
            }
            if(rg[i].op[0]=='#'){//IDENTIFICAR LDAA #
                temp_dec = ((int(rg[i].op[1])-48)*10) + ((int(rg[i].op[2])-48)*1);
                dec_to_hex(temp_dec, i);
                rg[i].linea[5]='\t';
                rg[i].linea[6]='8';
                rg[i].linea[7]='6';
                rg[i].linea[8]=rg[i].resultado[1];
                rg[i].linea[9]=rg[i].resultado[2];
                rg[i].linea[10]='\t';
                rg[i].linea[11]=rg[i].source[0];
                rg[i].linea[12]=rg[i].source[1];
                rg[i].linea[13]=rg[i].source[2];
                rg[i].linea[14]=rg[i].source[3];
                rg[i].linea[15]=rg[i].op[0];
                rg[i].linea[16]=rg[i].op[1];
                rg[i].linea[17]=rg[i].op[2];
            }
            if(rg[i].op[0]=='@'){//IDENTIFICAR LDAA OCTAL
                temp_oct = ((int(rg[i].op[1])-48)*10) + ((int(rg[i].op[2])-48)*1);
                oct_to_hex(temp_oct, i);
                rg[i].linea[5]='\t';
                rg[i].linea[6]='9';
                rg[i].linea[7]='6';
                rg[i].linea[8]=rg[i].resultado[1];
                rg[i].linea[9]=rg[i].resultado[2];
                rg[i].linea[10]='\t';
                rg[i].linea[11]=rg[i].source[0];
                rg[i].linea[12]=rg[i].source[1];
                rg[i].linea[13]=rg[i].source[2];
                rg[i].linea[14]=rg[i].source[3];
                rg[i].linea[15]=rg[i].op[0];
                rg[i].linea[16]=rg[i].op[1];
                rg[i].linea[17]=rg[i].op[2];
            }
            if(rg[i].op[0]=='$'){//IDENTIFICAR LDAA HEX
                ;
            }
        }//FIN LDAA
        if(rg[i].source[0]=='B'&&rg[i].source[1]=='N'&&rg[i].source[2]=='E'){////////////////////BNE CASE
            if(rg[i].op[0]=='E'&&rg[i].op[1]=='T'){//IDENTIFICAR BNE con etiqueta
                if(rg[i].op[2]=='1'){//ETIQUETA 1
                    resta_4_bytes(i, et[1].etq[0], et[1].etq[1], et[1].etq[2], et[1].etq[3],
                                  rg[i+1].contloc[0], rg[i+1].contloc[1], rg[i+1].contloc[2], rg[i+1].contloc[3]);
                }
                if(rg[i].op[2]=='2'){//ETIQUETA 2
                    resta_4_bytes(i, et[2].etq[0], et[2].etq[1], et[2].etq[2], et[2].etq[3],
                                  rg[i+1].contloc[0], rg[i+1].contloc[1], rg[i+1].contloc[2], rg[i+1].contloc[3]);
                    
                }
                if(rg[i].op[2]=='3'){//ETIQUETA 3
                    resta_4_bytes(i, et[3].etq[0], et[3].etq[1], et[3].etq[2], et[3].etq[3],
                                  rg[i+1].contloc[0], rg[i+1].contloc[1], rg[i+1].contloc[2], rg[i+1].contloc[3]);
                }
                if(rg[i].op[2]=='4'){//ETIQUETA 4
                    resta_4_bytes(i, et[4].etq[0], et[4].etq[1], et[4].etq[2], et[4].etq[3],
                                  rg[i+1].contloc[0], rg[i+1].contloc[1], rg[i+1].contloc[2], rg[i+1].contloc[3]);
                }
               /*if((int(rg[i].resultado[0])-48)<8){
                    rg[i].resultado[4]= 'F';
                    rg[i].resultado[5]= 'D';
                    rg[i].resultado[6]= 'R';
                }
                if((int(et[1].etq[0] + et[1].etq[1] + et[1].etq[2] + et[1].etq[3]))>(int(rg[i+1].contloc[0]+ rg[i+1].contloc[1] + rg[i+1].contloc[2] + rg[i+1].contloc[3]))){
                    rg[i].resultado[4]= ' ';
                    rg[i].resultado[5]= ' ';
                    rg[i].resultado[6]= ' ';
                }*/
                rg[i].linea[5]='\t';
                rg[i].linea[6]='2';
                rg[i].linea[7]='6';
                //rg[i].linea[8]=rg[i].resultado[0];
                //rg[i].linea[9]=rg[i].resultado[1];
                rg[i].linea[10]=rg[i].resultado[2];
                rg[i].linea[11]=rg[i].resultado[3];
                rg[i].linea[12]=rg[i].resultado[4];
                rg[i].linea[13]=rg[i].resultado[5];
                rg[i].linea[14]=rg[i].resultado[6];
                rg[i].linea[15]=rg[i].resultado[7];
                rg[i].linea[16]='\t';
                rg[i].linea[17]=rg[i].source[0];
                rg[i].linea[18]=rg[i].source[1];
                rg[i].linea[19]=rg[i].source[2];
                rg[i].linea[20]=' ';
                rg[i].linea[21]=rg[i].op[0];
                rg[i].linea[22]=rg[i].op[1];
                rg[i].linea[23]=rg[i].op[2];
            }
        }//FIN BNE
        if(rg[i].source[0]=='J'&&rg[i].source[1]=='M'&&rg[i].source[2]=='P'){////////////////////JMP CASE
            if((rg[i].op[0]=='-'&&rg[i].op[3]==',')){//IDENTIFICAR JMP CON -__,__
                temp_dec = ((int(rg[i].op[1])-48)*10) + ((int(rg[i].op[2])-48)*1);
                formula1_neg(temp_dec, i);
               
                rg[i].linea[5]='\t';
                rg[i].linea[6]='0';
                rg[i].linea[7]='5';
                rg[i].linea[8]=rg[i].resultado[1];
                rg[i].linea[9]=rg[i].resultado[2];
                rg[i].linea[10]=rg[i].resultado[3];
                rg[i].linea[11]=rg[i].resultado[4];
                rg[i].linea[12]='\t';
                rg[i].linea[13]=rg[i].source[0];
                rg[i].linea[14]=rg[i].source[1];
                rg[i].linea[15]=rg[i].source[2];
                rg[i].linea[17]=rg[i].op[0];
                rg[i].linea[18]=rg[i].op[1];
                rg[i].linea[19]=rg[i].op[2];
                rg[i].linea[20]=rg[i].op[3];
                rg[i].linea[21]=rg[i].op[4];
                rg[i].linea[22]=rg[i].op[5];
            }
            if(rg[i].op[0]=='E'&&rg[i].op[1]=='T'){//IDENTIFICAR JMP con etiqueta
                if(rg[i].op[2]=='1'){//ETIQUETA 1
                    rg[i].resultado[0]=et[1].etq[0];
                    rg[i].resultado[1]=et[1].etq[1];
                    rg[i].resultado[2]=et[1].etq[2];
                    rg[i].resultado[3]=et[1].etq[3];
                }
                if(rg[i].op[2]=='2'){//ETIQUETA 2
                    rg[i].resultado[0]=et[2].etq[0];
                    rg[i].resultado[1]=et[2].etq[1];
                    rg[i].resultado[2]=et[2].etq[2];
                    rg[i].resultado[3]=et[2].etq[3];
                }
                if(rg[i].op[2]=='3'){//ETIQUETA 3
                    rg[i].resultado[0]=et[3].etq[0];
                    rg[i].resultado[1]=et[3].etq[1];
                    rg[i].resultado[2]=et[3].etq[2];
                    rg[i].resultado[3]=et[3].etq[3];
                }
                if(rg[i].op[2]=='4'){//ETIQUETA 4
                    rg[i].resultado[0]=et[4].etq[0];
                    rg[i].resultado[1]=et[4].etq[1];
                    rg[i].resultado[2]=et[4].etq[2];
                    rg[i].resultado[3]=et[4].etq[3];
                }
                rg[i].linea[5]='\t';
                rg[i].linea[6]='0';
                rg[i].linea[7]='6';
                rg[i].linea[8]=rg[i].resultado[0];
                rg[i].linea[9]=rg[i].resultado[1];
                rg[i].linea[10]=rg[i].resultado[2];
                rg[i].linea[11]=rg[i].resultado[3];
                rg[i].linea[12]='\t';
                rg[i].linea[13]=rg[i].source[0];
                rg[i].linea[14]=rg[i].source[1];
                rg[i].linea[15]=rg[i].source[2];
                rg[i].linea[16]=rg[i].source[3];
                rg[i].linea[17]=rg[i].op[0];
                rg[i].linea[18]=rg[i].op[1];
                rg[i].linea[19]=rg[i].op[2];
            }
        }//FIN JMP
        if(rg[i].source[0]=='L'&&rg[i].source[1]=='B'&&rg[i].source[2]=='N'){////////////////////LBNE CASE
            if(rg[i].op[0]=='E'&&rg[i].op[1]=='T'){//IDENTIFICAR LBNE con etiqueta
                if(rg[i].op[2]=='1'){//ETIQUETA 1
                    resta_4_bytes(i, et[1].etq[0], et[1].etq[1], et[1].etq[2], et[1].etq[3],
                                  rg[i+1].contloc[0], rg[i+1].contloc[1], rg[i+1].contloc[2], rg[i+1].contloc[3]);
                }
                if(rg[i].op[2]=='2'){//ETIQUETA 2
                    resta_4_bytes(i, et[2].etq[0], et[2].etq[1], et[2].etq[2], et[2].etq[3],
                                  rg[i+1].contloc[0], rg[i+1].contloc[1], rg[i+1].contloc[2], rg[i+1].contloc[3]);
                    
                }
                if(rg[i].op[2]=='3'){//ETIQUETA 3
                    resta_4_bytes(i, et[3].etq[0], et[3].etq[1], et[3].etq[2], et[3].etq[3],
                                  rg[i+1].contloc[0], rg[i+1].contloc[1], rg[i+1].contloc[2], rg[i+1].contloc[3]);
                }
                if(rg[i].op[2]=='4'){//ETIQUETA 4
                    resta_4_bytes(i, et[4].etq[0], et[4].etq[1], et[4].etq[2], et[4].etq[3],
                                  rg[i+1].contloc[0], rg[i+1].contloc[1], rg[i+1].contloc[2], rg[i+1].contloc[3]);
                }
                rg[i].linea[5]='\t';
                rg[i].linea[6]='1';
                rg[i].linea[7]='8';
                rg[i].linea[8]='2';
                rg[i].linea[9]='6';
                rg[i].linea[10]=rg[i].resultado[0];
                rg[i].linea[11]=rg[i].resultado[1];
                rg[i].linea[12]=rg[i].resultado[2];
                rg[i].linea[13]=rg[i].resultado[3];
                rg[i].linea[14]=rg[i].resultado[4];
                rg[i].linea[15]=rg[i].resultado[5];
                rg[i].linea[16]=rg[i].resultado[6];
                rg[i].linea[17]='\t';
                rg[i].linea[18]=rg[i].source[0];
                rg[i].linea[19]=rg[i].source[1];
                rg[i].linea[20]=rg[i].source[2];
                rg[i].linea[21]=rg[i].source[3];
                rg[i].linea[22]=' ';
                rg[i].linea[23]=rg[i].op[0];
                rg[i].linea[24]=rg[i].op[1];
                rg[i].linea[25]=rg[i].op[2];
            }
        }//FIN LBNE
        if(rg[i].source[0]=='I'&&rg[i].source[1]=='B'&&rg[i].source[2]=='N'){////////////////////IBNE CASE
            if(rg[i].op[2]=='E'&&rg[i].op[3]=='T'){//IDENTIFICAR IBNE con etiqueta
                if(rg[i].op[4]=='1'){//ETIQUETA 1
                    resta_IBNE(i, rg[i].op[0], et[1].etq[0], et[1].etq[1], et[1].etq[2], et[1].etq[3],
                                  rg[i+1].contloc[0], rg[i+1].contloc[1], rg[i+1].contloc[2], rg[i+1].contloc[3]);
                }
                if(rg[i].op[4]=='2'){//ETIQUETA 2
                    resta_IBNE(i, rg[i].op[0], et[2].etq[0], et[2].etq[1], et[2].etq[2], et[2].etq[3],
                                  rg[i+1].contloc[0], rg[i+1].contloc[1], rg[i+1].contloc[2], rg[i+1].contloc[3]);
                    
                }
                if(rg[i].op[4]=='3'){//ETIQUETA 3
                    resta_IBNE(i, rg[i].op[0], et[3].etq[0], et[3].etq[1], et[3].etq[2], et[3].etq[3],
                                  rg[i+1].contloc[0], rg[i+1].contloc[1], rg[i+1].contloc[2], rg[i+1].contloc[3]);
                }
                if(rg[i].op[4]=='4'){//ETIQUETA 4
                    resta_IBNE(i, rg[i].op[0], et[4].etq[0], et[4].etq[1], et[4].etq[2], et[4].etq[3],
                                  rg[i+1].contloc[0], rg[i+1].contloc[1], rg[i+1].contloc[2], rg[i+1].contloc[3]);
                }
                rg[i].linea[5]='\t';
                rg[i].linea[6]='0';
                rg[i].linea[7]='4';
                rg[i].linea[8]=rg[i].resultado[0];
                rg[i].linea[9]=rg[i].resultado[1];
                rg[i].linea[10]=rg[i].resultado[2];
                rg[i].linea[11]=rg[i].resultado[3];
                rg[i].linea[12]='\t';
                rg[i].linea[13]=rg[i].source[0];
                rg[i].linea[14]=rg[i].source[1];
                rg[i].linea[15]=rg[i].source[2];
                rg[i].linea[16]=rg[i].source[3];
                rg[i].linea[17]=' ';
                rg[i].linea[18]=rg[i].op[0];
                rg[i].linea[19]=rg[i].op[1];
                rg[i].linea[20]=rg[i].op[2];
                rg[i].linea[21]=rg[i].op[3];
                rg[i].linea[22]=rg[i].op[4];
            }
            if(rg[i].op[1]==','&&rg[i].op[2]=='$'){//X,Y
                resta_IBNE(i, rg[i].op[0], rg[i].op[3], rg[i].op[4], rg[i].op[5], rg[i].op[6],
                           rg[i+1].contloc[0], rg[i+1].contloc[1], rg[i+1].contloc[2], rg[i+1].contloc[3]);
                rg[i].linea[5]='\t';
                rg[i].linea[6]='0';
                rg[i].linea[7]='4';
                rg[i].linea[8]=rg[i].resultado[0];
                rg[i].linea[9]=rg[i].resultado[1];
                rg[i].linea[10]=rg[i].resultado[2];
                rg[i].linea[11]=rg[i].resultado[3];
                rg[i].linea[12]='\t';
                rg[i].linea[13]=rg[i].source[0];
                rg[i].linea[14]=rg[i].source[1];
                rg[i].linea[15]=rg[i].source[2];
                rg[i].linea[16]=rg[i].source[3];
                rg[i].linea[17]=' ';
                rg[i].linea[18]=rg[i].op[0];
                rg[i].linea[19]=rg[i].op[1];
                rg[i].linea[20]=rg[i].op[2];
                rg[i].linea[21]=rg[i].op[3];
                rg[i].linea[22]=rg[i].op[4];
                rg[i].linea[23]=rg[i].op[5];
                rg[i].linea[24]=rg[i].op[6];
            }
            if(rg[i].op[0]=='S'&&rg[i].op[2]==','&&rg[i].op[3]=='$'){//SP
                resta_IBNE(i, rg[i].op[0], rg[i].op[4], rg[i].op[5], rg[i].op[6], rg[i].op[7],
                           rg[i+1].contloc[0], rg[i+1].contloc[1], rg[i+1].contloc[2], rg[i+1].contloc[3]);
                rg[i].linea[5]='\t';
                rg[i].linea[6]='0';
                rg[i].linea[7]='4';
                rg[i].linea[8]=rg[i].resultado[0];
                rg[i].linea[9]=rg[i].resultado[1];
                rg[i].linea[10]=rg[i].resultado[2];
                rg[i].linea[11]=rg[i].resultado[3];
                rg[i].linea[12]='\t';
                rg[i].linea[13]=rg[i].source[0];
                rg[i].linea[14]=rg[i].source[1];
                rg[i].linea[15]=rg[i].source[2];
                rg[i].linea[16]=rg[i].source[3];
                rg[i].linea[17]=' ';
                rg[i].linea[18]=rg[i].op[0];
                rg[i].linea[19]=rg[i].op[1];
                rg[i].linea[20]=rg[i].op[2];
                rg[i].linea[21]=rg[i].op[3];
                rg[i].linea[22]=rg[i].op[4];
                rg[i].linea[23]=rg[i].op[5];
                rg[i].linea[24]=rg[i].op[6];
            }
            if(rg[i].op[0]=='P'){
                rg[i].linea[5]='\t';
                rg[i].linea[6]='I';
                rg[i].linea[7]='N';
                rg[i].linea[8]='V';
                rg[i].linea[9]='L';
                rg[i].linea[10]='\t';
                rg[i].linea[11]=rg[i].source[0];
                rg[i].linea[12]=rg[i].source[1];
                rg[i].linea[13]=rg[i].source[2];
                rg[i].linea[14]=rg[i].source[3];
                rg[i].linea[15]=' ';
                rg[i].linea[16]=rg[i].op[0];
                rg[i].linea[17]=rg[i].op[1];
                rg[i].linea[18]=rg[i].op[2];
                rg[i].linea[19]=rg[i].op[3];
                rg[i].linea[20]=rg[i].op[4];
                rg[i].linea[21]=rg[i].op[5];
                rg[i].linea[22]=rg[i].op[6];
                rg[i].linea[23]=rg[i].op[7];
                
            }
            
        }//FIN IBNE
        if(rg[i].source[0]=='B'&&rg[i].source[1]=='S'&&rg[i].source[2]=='Z'){////////////////////BSZ CASE
            rg[i].linea[5]='\t';
            int temp_dec;// = ((int(rg[i].op[0])-48)*10) + ((int(rg[i].op[1])-48)*1);
            if(rg[i].op[1]=='0'||rg[i].op[1]=='1'||rg[i].op[1]=='2'||rg[i].op[1]=='3'
               ||rg[i].op[1]=='4'||rg[i].op[1]=='5'||rg[i].op[1]=='6'||rg[i].op[1]=='7'
               ||rg[i].op[1]=='8'||rg[i].op[1]=='9'){//2 cifras
                temp_dec = ((int(rg[i].op[0])-48)*10) + ((int(rg[i].op[1])-48)*1);
                for(int it=0;it<(temp_dec*2);it+=2){
                    rg[i].linea[it+6]= rg[i].resultado[it]='0';
                    rg[i].linea[it+6+1]= rg[i].resultado[it+1]='0';
                }
            }
            else{
                int temp_dec = ((int(rg[i].op[0])-48)*1);// + ((int(rg[i].op[1])-48)*1);
                for(int it=0;it<(temp_dec*2);it+=2){
                    rg[i].linea[it+6]= rg[i].resultado[it]='0';
                    rg[i].linea[it+6+1]= rg[i].resultado[it+1]='0';
                }}
            rg[i].linea[30]='\t';
            rg[i].linea[31]=rg[i].source[0];
            rg[i].linea[32]=rg[i].source[1];
            rg[i].linea[33]=rg[i].source[2];
        }//FIN BSZ
        if(rg[i].source[0]=='A'&&rg[i].source[1]=='B'&&rg[i].source[2]=='A'){////////////////////ABA CASE
            rg[i].linea[5]='\t';
            if(rg[i].op[0]!=NULL){
                rg[i].linea[6]='I';
                rg[i].linea[7]='N';
                rg[i].linea[8]='V';
                rg[i].linea[9]='L';
                rg[i].linea[15]= rg[i].op[0];
                rg[i].linea[16]= rg[i].op[1];
            }
            if(rg[i].op[0]==NULL){
                rg[i].linea[6]='1';
                rg[i].linea[7]='8';
                rg[i].linea[8]='0';
                rg[i].linea[9]='6';
            }
            rg[i].linea[10]='\t';
            rg[i].linea[11]=rg[i].source[0];
            rg[i].linea[12]=rg[i].source[1];
            rg[i].linea[13]=rg[i].source[2];
            rg[i].linea[14]=' ';
        }//FIN ABA
        if(rg[i].source[0]=='A'&&rg[i].source[1]=='D'&&rg[i].source[2]=='C'){////////////////////ADCA CASE
            rg[i].linea[5]='\t';
            if(rg[i].op[0]=='#'){
                if(rg[i].op[1]=='@'){//#octal
                    temp_oct = ((int(rg[i].op[2])-48)*10) + (int(rg[i].op[3])-48)*1;
                    oct_to_hex(temp_oct, i);
                    rg[i].linea[6]='8';
                    rg[i].linea[7]='9';
                    rg[i].linea[8]=rg[i].resultado[1];
                    rg[i].linea[9]=rg[i].resultado[2];
                    rg[i].linea[10]='\t';
                    rg[i].linea[11]=rg[i].source[0];
                    rg[i].linea[12]=rg[i].source[1];
                    rg[i].linea[13]=rg[i].source[2];
                    rg[i].linea[14]=rg[i].source[3];
                    rg[i].linea[15]=' ';
                    rg[i].linea[16]=rg[i].op[0];
                    rg[i].linea[17]=rg[i].op[1];
                    rg[i].linea[18]=rg[i].op[2];
                    rg[i].linea[19]=rg[i].op[3];
                }
                else if(rg[i].op[1]=='$'){//#hexadecimal
                    rg[i].resultado[1]=rg[i].op[2];
                    rg[i].resultado[2]=rg[i].op[3];
                    rg[i].linea[6]='8';
                    rg[i].linea[7]='9';
                    rg[i].linea[8]=rg[i].resultado[1];
                    rg[i].linea[9]=rg[i].resultado[2];
                    rg[i].linea[10]='\t';
                    rg[i].linea[11]=rg[i].source[0];
                    rg[i].linea[12]=rg[i].source[1];
                    rg[i].linea[13]=rg[i].source[2];
                    rg[i].linea[14]=rg[i].source[3];
                    rg[i].linea[15]=' ';
                    rg[i].linea[16]=rg[i].op[0];
                    rg[i].linea[17]=rg[i].op[1];
                    rg[i].linea[18]=rg[i].op[2];
                    rg[i].linea[19]=rg[i].op[3];
                }
                else{//#decimal
                    temp_dec = ((int(rg[i].op[1])-48)*10) + (int(rg[i].op[2])-48)*1;
                    dec_to_hex(temp_dec, i);
                    rg[i].linea[6]='8';
                    rg[i].linea[7]='9';
                    rg[i].linea[8]=rg[i].resultado[1];
                    rg[i].linea[9]=rg[i].resultado[2];
                    rg[i].linea[10]='\t';
                    rg[i].linea[11]=rg[i].source[0];
                    rg[i].linea[12]=rg[i].source[1];
                    rg[i].linea[13]=rg[i].source[2];
                    rg[i].linea[14]=rg[i].source[3];
                    rg[i].linea[15]=' ';
                    rg[i].linea[16]=rg[i].op[0];
                    rg[i].linea[17]=rg[i].op[1];
                    rg[i].linea[18]=rg[i].op[2];
                }
            }
            if(rg[i].op[0]=='@'){//octal
                temp_oct = ((int(rg[i].op[1])-48)*10) + (int(rg[i].op[2])-48)*1;
                oct_to_hex(temp_oct, i);
                resta_2_bytes(i, '0', '0', rg[i].resultado[1], rg[i].resultado[2],
                              rg[i+1].contloc[0], rg[i+1].contloc[1], rg[i+1].contloc[2], rg[i+1].contloc[3]);
                rg[i].linea[6]='8';
                rg[i].linea[7]='9';
                rg[i].linea[8]=rg[i].resultado[0];
                rg[i].linea[9]=rg[i].resultado[1];
                rg[i].linea[10]='\t';
                rg[i].linea[11]=rg[i].source[0];
                rg[i].linea[12]=rg[i].source[1];
                rg[i].linea[13]=rg[i].source[2];
                rg[i].linea[14]=rg[i].source[3];
                rg[i].linea[15]=' ';
                rg[i].linea[16]=rg[i].op[0];
                rg[i].linea[17]=rg[i].op[1];
                rg[i].linea[18]=rg[i].op[2];
                rg[i].linea[19]=rg[i].op[3];
            }
            if(rg[i].op[0]=='$'){//hexadecimal
                resta_2_bytes(i, '0', '0', rg[i].op[1], rg[i].op[2],
                              rg[i+1].contloc[0], rg[i+1].contloc[1], rg[i+1].contloc[2], rg[i+1].contloc[3]);
                rg[i].linea[6]='8';
                rg[i].linea[7]='9';
                rg[i].linea[8]=rg[i].resultado[0];
                rg[i].linea[9]=rg[i].resultado[1];
                rg[i].linea[10]='\t';
                rg[i].linea[11]=rg[i].source[0];
                rg[i].linea[12]=rg[i].source[1];
                rg[i].linea[13]=rg[i].source[2];
                rg[i].linea[14]=rg[i].source[3];
                rg[i].linea[15]=' ';
                rg[i].linea[16]=rg[i].op[0];
                rg[i].linea[17]=rg[i].op[1];
                rg[i].linea[18]=rg[i].op[2];
                rg[i].linea[19]=rg[i].op[3];
            }
            if(rg[i].op[0]!='#'&&rg[i].op[0]!='$'&&rg[i].op[0]=='@'){//decimal
                temp_dec = ((int(rg[i].op[0])-48)*10) + (int(rg[i].op[1])-48)*1;
                dec_to_hex(temp_dec, i);
                resta_2_bytes(i, '0', '0', rg[i].resultado[1], rg[i].resultado[2],
                              rg[i+1].contloc[0], rg[i+1].contloc[1], rg[i+1].contloc[2], rg[i+1].contloc[3]);
                rg[i].linea[6]='8';
                rg[i].linea[7]='9';
                rg[i].linea[8]=rg[i].resultado[0];
                rg[i].linea[9]=rg[i].resultado[1];
                rg[i].linea[10]='\t';
                rg[i].linea[11]=rg[i].source[0];
                rg[i].linea[12]=rg[i].source[1];
                rg[i].linea[13]=rg[i].source[2];
                rg[i].linea[14]=rg[i].source[3];
                rg[i].linea[15]=' ';
                rg[i].linea[16]=rg[i].op[0];
                rg[i].linea[17]=rg[i].op[1];
            }
        }//FIN ADCA
        if(rg[i].source[0]=='A'&&rg[i].source[1]=='D'&&rg[i].source[2]=='D'&&rg[i].source[3]=='D'){////////////////////ADDD CASE
            rg[i].linea[5]='\t';
            if(rg[i].op[0]=='#'){
                if(rg[i].op[1]=='@'){//#octal
                    temp_oct = ((int(rg[i].op[2])-48)*10) + (int(rg[i].op[3])-48)*1;
                    oct_to_hex(temp_oct, i);
                    rg[i].linea[6]='C';
                    rg[i].linea[7]='3';
                    rg[i].linea[8]='0';
                    rg[i].linea[9]='0';
                    rg[i].linea[10]=rg[i].resultado[1];
                    rg[i].linea[11]=rg[i].resultado[2];
                    rg[i].linea[12]='\t';
                    rg[i].linea[13]=rg[i].source[0];
                    rg[i].linea[14]=rg[i].source[1];
                    rg[i].linea[15]=rg[i].source[2];
                    rg[i].linea[16]=rg[i].source[3];
                    rg[i].linea[17]=' ';
                    rg[i].linea[18]=rg[i].op[0];
                    rg[i].linea[19]=rg[i].op[1];
                    rg[i].linea[20]=rg[i].op[2];
                    rg[i].linea[21]=rg[i].op[3];
                }
                else if(rg[i].op[1]=='$'){//#hexadecimal
                    rg[i].linea[6]='C';
                    rg[i].linea[7]='3';
                    rg[i].linea[8]=rg[i].resultado[0]='0';
                    rg[i].linea[9]=rg[i].resultado[1]='0';
                    rg[i].linea[10]=rg[i].resultado[2]= rg[i].op[2];
                    rg[i].linea[11]=rg[i].resultado[3]= rg[i].op[3];
                    rg[i].linea[12]='\t';
                    rg[i].linea[13]=rg[i].source[0];
                    rg[i].linea[14]=rg[i].source[1];
                    rg[i].linea[15]=rg[i].source[2];
                    rg[i].linea[16]=rg[i].source[3];
                    rg[i].linea[17]=' ';
                    rg[i].linea[18]=rg[i].op[0];
                    rg[i].linea[19]=rg[i].op[1];
                    rg[i].linea[20]=rg[i].op[2];
                    rg[i].linea[21]=rg[i].op[3];
                }
                else{//#decimal
                    temp_dec = ((int(rg[i].op[1])-48)*10) + (int(rg[i].op[2])-48)*1;
                    dec_to_hex(temp_dec, i);
                    rg[i].linea[6]='C';
                    rg[i].linea[7]='3';
                    rg[i].linea[8]='0';
                    rg[i].linea[9]='0';
                    rg[i].linea[10]=rg[i].resultado[1];
                    rg[i].linea[11]=rg[i].resultado[2];
                    rg[i].linea[12]='\t';
                    rg[i].linea[13]=rg[i].source[0];
                    rg[i].linea[14]=rg[i].source[1];
                    rg[i].linea[15]=rg[i].source[2];
                    rg[i].linea[16]=rg[i].source[3];
                    rg[i].linea[17]=' ';
                    rg[i].linea[18]=rg[i].op[0];
                    rg[i].linea[19]=rg[i].op[1];
                    rg[i].linea[20]=rg[i].op[2];
                }
            }
            if(rg[i].op[0]=='@'){//octal
                temp_oct = ((int(rg[i].op[1])-48)*10) + (int(rg[i].op[2])-48)*1;
                oct_to_hex(temp_oct, i);
                resta_2_bytes(i, '0', '0', rg[i].resultado[1], rg[i].resultado[2],
                              rg[i+1].contloc[0], rg[i+1].contloc[1], rg[i+1].contloc[2], rg[i+1].contloc[3]);
                rg[i].linea[6]='D';
                rg[i].linea[7]='3';
                rg[i].linea[8]=rg[i].resultado[0];
                rg[i].linea[9]=rg[i].resultado[1];
                rg[i].linea[10]='\t';
                rg[i].linea[11]=rg[i].source[0];
                rg[i].linea[12]=rg[i].source[1];
                rg[i].linea[13]=rg[i].source[2];
                rg[i].linea[14]=rg[i].source[3];
                rg[i].linea[15]=' ';
                rg[i].linea[16]=rg[i].op[0];
                rg[i].linea[17]=rg[i].op[1];
                rg[i].linea[18]=rg[i].op[2];
                //rg[i].linea[19]=rg[i].op[3];
            }
            if(rg[i].op[0]=='$'){//hexadecimal
                resta_2_bytes(i, '0', '0', rg[i].op[1], rg[i].op[2],
                              rg[i+1].contloc[0], rg[i+1].contloc[1], rg[i+1].contloc[2], rg[i+1].contloc[3]);
                rg[i].linea[6]='D';
                rg[i].linea[7]='3';
                rg[i].linea[8]=rg[i].resultado[0];
                rg[i].linea[9]=rg[i].resultado[1];
                rg[i].linea[10]='\t';
                rg[i].linea[11]=rg[i].source[0];
                rg[i].linea[12]=rg[i].source[1];
                rg[i].linea[13]=rg[i].source[2];
                rg[i].linea[14]=rg[i].source[3];
                rg[i].linea[15]=' ';
                rg[i].linea[16]=rg[i].op[0];
                rg[i].linea[17]=rg[i].op[1];
                rg[i].linea[18]=rg[i].op[2];
                //rg[i].linea[19]=rg[i].op[3];
            }
            if(rg[i].op[0]!='#'&&rg[i].op[0]!='$'&&rg[i].op[0]=='@'){//decimal
                temp_dec = ((int(rg[i].op[0])-48)*10) + (int(rg[i].op[1])-48)*1;
                dec_to_hex(temp_dec, i);
                resta_2_bytes(i, '0', '0', rg[i].resultado[1], rg[i].resultado[2],
                              rg[i+1].contloc[0], rg[i+1].contloc[1], rg[i+1].contloc[2], rg[i+1].contloc[3]);
                rg[i].linea[6]='D';
                rg[i].linea[7]='3';
                rg[i].linea[8]=rg[i].resultado[0];
                rg[i].linea[9]=rg[i].resultado[1];
                rg[i].linea[10]='\t';
                rg[i].linea[11]=rg[i].source[0];
                rg[i].linea[12]=rg[i].source[1];
                rg[i].linea[13]=rg[i].source[2];
                rg[i].linea[14]=rg[i].source[3];
                rg[i].linea[15]=' ';
                rg[i].linea[16]=rg[i].op[0];
                rg[i].linea[17]=rg[i].op[1];
            }
        }//FIN ADDD
            if(rg[i].source[0]=='A'&&rg[i].source[1]=='S'&&rg[i].source[2]=='L'){////////////////////ASL CASE
                rg[i].linea[5]='\t';
                if(rg[i].op[0]=='['&&rg[i].op[1]!='-'){//formula 3
                    rg[i].linea[6]='6';
                    rg[i].linea[7]='8';
                    formula3(i);
                    rg[i].linea[8]=rg[i].resultado[1];
                    rg[i].linea[9]=rg[i].resultado[2];
                    temp_dec = ((int(rg[i].op[1])-48)*10) + ((int(rg[i].op[2])-48)*1);
                    dec_to_hex(temp_dec, i);
                    rg[i].linea[10]='0';
                    rg[i].linea[11]='0';
                    rg[i].linea[12]='0';
                    rg[i].linea[13]=rg[i].resultado[2];
                    rg[i].linea[14]='\t';
                    rg[i].linea[15]=rg[i].source[0];
                    rg[i].linea[16]=rg[i].source[1];
                    rg[i].linea[17]=rg[i].source[2];
                    rg[i].linea[18]=rg[i].source[3];
                    rg[i].linea[19]=rg[i].op[0];
                    rg[i].linea[20]=rg[i].op[1];
                    rg[i].linea[21]=rg[i].op[2];
                    rg[i].linea[22]=rg[i].op[3];
                    rg[i].linea[23]=rg[i].op[4];
                    rg[i].linea[24]=rg[i].op[5];
                    rg[i].linea[25]=rg[i].op[6];
                }
                if(rg[i].op[0]=='['&&rg[i].op[1]=='-'){//formula 3 negativa
                    rg[i].linea[6]='I';
                    rg[i].linea[7]='N';
                    rg[i].linea[8]='V';
                    rg[i].linea[9]='L';
                    rg[i].linea[10]='\t';
                    rg[i].linea[11]=rg[i].source[0];
                    rg[i].linea[12]=rg[i].source[1];
                    rg[i].linea[13]=rg[i].source[2];
                    rg[i].linea[14]=rg[i].source[3];
                    rg[i].linea[15]=rg[i].op[0];
                    rg[i].linea[16]=rg[i].op[1];
                    rg[i].linea[17]=rg[i].op[2];
                    rg[i].linea[18]=rg[i].op[3];
                    rg[i].linea[19]=rg[i].op[4];
                    rg[i].linea[20]=rg[i].op[5];
                    rg[i].linea[21]=rg[i].op[6];
                }
                if(rg[i].op[0]!=',' && rg[i].op[1]!=',' && rg[i].op[2]!=',' && rg[i].op[3]!=','){
                    temp_dec = ((int(rg[i].op[0])-48)*10) + (int(rg[i].op[1])-48)*1;
                    dec_to_hex(temp_dec, i);//Decimal
                    rg[i].linea[6]='7';
                    rg[i].linea[7]='8';
                    rg[i].linea[8]='0';
                    rg[i].linea[9]='0';
                    rg[i].linea[10]=rg[i].resultado[1];
                    rg[i].linea[11]=rg[i].resultado[2];
                    rg[i].linea[12]='\t';
                    rg[i].linea[13]=rg[i].source[0];
                    rg[i].linea[14]=rg[i].source[1];
                    rg[i].linea[15]=rg[i].source[2];
                    rg[i].linea[16]=' ';
                    rg[i].linea[17]=rg[i].op[0];
                    rg[i].linea[18]=rg[i].op[1];
                    if(rg[i].op[0]=='$'){//Hexadecimal
                        rg[i].linea[6]='7';
                        rg[i].linea[7]='8';
                        rg[i].linea[8]=rg[i].resultado[0]=rg[i].op[1];
                        rg[i].linea[9]=rg[i].resultado[1]=rg[i].op[2];
                        rg[i].linea[10]=rg[i].resultado[2]=rg[i].op[3];
                        rg[i].linea[11]=rg[i].resultado[3]=rg[i].op[4];
                        rg[i].linea[12]='\t';
                        rg[i].linea[13]=rg[i].source[0];
                        rg[i].linea[14]=rg[i].source[1];
                        rg[i].linea[15]=rg[i].source[2];
                        rg[i].linea[16]=' ';
                        rg[i].linea[17]=rg[i].op[0];
                        rg[i].linea[18]=rg[i].op[1];
                        rg[i].linea[19]=rg[i].op[2];
                        rg[i].linea[20]=rg[i].op[3];
                        rg[i].linea[21]=rg[i].op[4];
                    }
                }
                if(rg[i].op[1]==','||rg[i].op[2]==','||rg[i].op[3]==','){
                    if((rg[i].op[0]=='[')==false){
                        if(rg[i].op[3]!='-'&&rg[i].op[3]!='+'&&rg[i].op[4]!='+'&&rg[i].op[4]!='-'&&rg[i].op[5]!='+'&&rg[i].op[5]!='-'){//formula 1
                            if(rg[i].op[0]=='-'){//formula 1 negativa
                                temp_dec = ((int(rg[i].op[1])-48)*10) + ((int(rg[i].op[2])-48)*1);
                                formula1_neg(temp_dec, i);
                                rg[i].linea[6]='6';
                                rg[i].linea[7]='8';
                                rg[i].linea[8]=rg[i].resultado[1];
                                rg[i].linea[9]=rg[i].resultado[2];
                                rg[i].linea[10]='\t';
                                rg[i].linea[11]=rg[i].source[0];
                                rg[i].linea[12]=rg[i].source[1];
                                rg[i].linea[13]=rg[i].source[2];
                                rg[i].linea[14]=' ';
                                rg[i].linea[15]=rg[i].op[0];
                                rg[i].linea[16]=rg[i].op[1];
                                rg[i].linea[17]=rg[i].op[2];
                                rg[i].linea[18]=rg[i].op[3];
                                rg[i].linea[19]=rg[i].op[4];
                                rg[i].linea[20]=rg[i].op[5];
                            }
                            else{//formula 1 positiva
                                temp_dec = ((int(rg[i].op[0])-48)*10) + ((int(rg[i].op[1])-48)*1);
                                formula1_pos(temp_dec, i);
                                rg[i].linea[6]='6';
                                rg[i].linea[7]='8';
                                rg[i].linea[8]=rg[i].resultado[1];
                                rg[i].linea[9]=rg[i].resultado[2] = rg[i].op[1];
                                rg[i].linea[10]='\t';
                                rg[i].linea[11]=rg[i].source[0];
                                rg[i].linea[12]=rg[i].source[1];
                                rg[i].linea[13]=rg[i].source[2];
                                rg[i].linea[14]=' ';
                                rg[i].linea[15]=rg[i].op[0];
                                rg[i].linea[16]=rg[i].op[1];
                                rg[i].linea[17]=rg[i].op[2];
                                rg[i].linea[18]=rg[i].op[3];
                                rg[i].linea[19]=rg[i].op[4];
                            }
                        }
                    }
                }
                if(rg[i].op[1]==','||rg[i].op[2]==','||rg[i].op[3]==','){
                    if((rg[i].op[0]=='[')==false){
                        if((rg[i].op[3]=='-'||rg[i].op[4]=='-'||rg[i].op[5]=='-')){//formula 4 neg
                            temp_dec = ((int(rg[i].op[0])-48)*10) + ((int(rg[i].op[1])-48)*1);
                            formula4_neg(temp_dec, i);
                            rg[i].linea[6]='6';
                            rg[i].linea[7]='8';
                            rg[i].linea[8]=rg[i].resultado[1];
                            rg[i].linea[9]=rg[i].resultado[2];
                            rg[i].linea[10]='\t';
                            rg[i].linea[11]=rg[i].source[0];
                            rg[i].linea[12]=rg[i].source[1];
                            rg[i].linea[13]=rg[i].source[2];
                            rg[i].linea[14]=' ';
                            rg[i].linea[15]=rg[i].op[0];
                            rg[i].linea[16]=rg[i].op[1];
                            rg[i].linea[17]=rg[i].op[2];
                            rg[i].linea[18]=rg[i].op[3];
                            rg[i].linea[19]=rg[i].op[4];
                            rg[i].linea[20]=rg[i].op[5];
                            if(rg[i].op[3]=='P'||rg[i].op[4]=='P'){
                                rg[i].linea[6]='I';
                                rg[i].linea[7]='N';
                                rg[i].linea[8]='V';
                                rg[i].linea[9]='L';
                            }
                        }
                        if((rg[i].op[3]=='+'||rg[i].op[4]=='+'||rg[i].op[5]=='+')){//formula 4 pos
                            temp_dec = ((int(rg[i].op[0])-48)*10) + ((int(rg[i].op[1])-48)*1);
                            formula4_pos(temp_dec, i);
                            rg[i].linea[6]='6';
                            rg[i].linea[7]='8';
                            rg[i].linea[8]=rg[i].resultado[1];
                            rg[i].linea[9]=rg[i].resultado[2];
                            rg[i].linea[10]='\t';
                            rg[i].linea[11]=rg[i].source[0];
                            rg[i].linea[12]=rg[i].source[1];
                            rg[i].linea[13]=rg[i].source[2];
                            rg[i].linea[14]=' ';
                            rg[i].linea[15]=rg[i].op[0];
                            rg[i].linea[16]=rg[i].op[1];
                            rg[i].linea[17]=rg[i].op[2];
                            rg[i].linea[18]=rg[i].op[3];
                            rg[i].linea[19]=rg[i].op[4];
                            rg[i].linea[20]=rg[i].op[5];
                            if(rg[i].op[3]=='P'||rg[i].op[4]=='P'){
                                rg[i].linea[6]='I';
                                rg[i].linea[7]='N';
                                rg[i].linea[8]='V';
                                rg[i].linea[9]='L';
                            }
                        }
                    }
                }
            }//FIN ASL
        if(rg[i].source[0]=='C'&&rg[i].source[1]=='M'&&rg[i].source[2]=='P'){////////////////////CMPA CASE
            temp_dec = ((int(rg[i].op[0])-48)*10) + ((int(rg[i].op[1])-48)*1);
            formula2_pos(temp_dec, i);
            rg[i].linea[5]='\t';
            rg[i].linea[6]='A';
            rg[i].linea[7]='1';
            rg[i].linea[8]=rg[i].resultado[1];
            rg[i].linea[9]=rg[i].resultado[2];
            dec_to_hex(temp_dec, i);
            rg[i].linea[10]=rg[i].resultado[2];
            rg[i].linea[11]=rg[i].resultado[3];
            rg[i].linea[12]='\t';
            rg[i].linea[13]=rg[i].source[0];
            rg[i].linea[14]=rg[i].source[1];
            rg[i].linea[15]=rg[i].source[2];
            rg[i].linea[16]=' ';
            rg[i].linea[17]=rg[i].op[0];
            rg[i].linea[18]=rg[i].op[1];
            rg[i].linea[19]=rg[i].op[2];
            rg[i].linea[20]=rg[i].op[3];
        }//FIN CMPA
        if(rg[i].source[0]=='C'&&rg[i].source[1]=='L'&&rg[i].source[2]=='R'){////////////////////CLR CASE
            if(rg[i].op[0]=='E'&&rg[i].op[1]=='T'){//IDENTIFICAR CLR con etiqueta
                if(rg[i].op[2]=='1'){//ETIQUETA 1
                    rg[i].resultado[0]=et[1].etq[0];
                    rg[i].resultado[1]=et[1].etq[1];
                    rg[i].resultado[2]=et[1].etq[2];
                    rg[i].resultado[3]=et[1].etq[3];
                }
                if(rg[i].op[2]=='2'){//ETIQUETA 2
                    rg[i].resultado[0]=et[2].etq[0];
                    rg[i].resultado[1]=et[2].etq[1];
                    rg[i].resultado[2]=et[2].etq[2];
                    rg[i].resultado[3]=et[2].etq[3];
                }
                if(rg[i].op[2]=='3'){//ETIQUETA 3
                    rg[i].resultado[0]=et[3].etq[0];
                    rg[i].resultado[1]=et[3].etq[1];
                    rg[i].resultado[2]=et[3].etq[2];
                    rg[i].resultado[3]=et[3].etq[3];
                }
                if(rg[i].op[2]=='4'){//ETIQUETA 4
                    rg[i].resultado[0]=et[4].etq[0];
                    rg[i].resultado[1]=et[4].etq[1];
                    rg[i].resultado[2]=et[4].etq[2];
                    rg[i].resultado[3]=et[4].etq[3];
                }
                rg[i].linea[5]='\t';
                rg[i].linea[6]='7';
                rg[i].linea[7]='9';
                rg[i].linea[8]=rg[i].resultado[0];
                rg[i].linea[9]=rg[i].resultado[1];
                rg[i].linea[10]=rg[i].resultado[2];
                rg[i].linea[11]=rg[i].resultado[3];
                rg[i].linea[12]='\t';
                rg[i].linea[13]=rg[i].source[0];
                rg[i].linea[14]=rg[i].source[1];
                rg[i].linea[15]=rg[i].source[2];
                rg[i].linea[16]=' ';
                rg[i].linea[17]=rg[i].op[0];
                rg[i].linea[18]=rg[i].op[1];
                rg[i].linea[19]=rg[i].op[2];
            }
        }//FIN CLR
        if(rg[i].source[0]=='E'&&rg[i].source[1]=='Q'&&rg[i].source[2]=='U'){////////////////////EQU CASE
            rg[i].linea[5]='\t';
            rg[i].linea[6]='\t';
            rg[i].linea[7]='\t';
            rg[i].linea[8]=rg[i].source[0];
            rg[i].linea[9]=rg[i].source[1];
            rg[i].linea[10]=rg[i].source[2];
            rg[i].linea[11]=' ';
            rg[i].linea[12]= rg[i].op[0];
            rg[i].linea[13]= rg[i].op[1];
            rg[i].linea[14]= rg[i].op[2];
            rg[i].linea[15]= rg[i].op[3];
            rg[i].linea[16]= rg[i].op[4];
        }//FIN EQU
        if(rg[i].source[0]=='D'&&rg[i].source[1]=='C'&&rg[i].source[3]=='W'){////////////////////DC.W CASE
            if(rg[i].op[1]==','||rg[i].op[2]==','||
                rg[i].op[3]==','||rg[i].op[4]==','){//IDENTIFICAR DC.W CON ,
                rg[i].linea[5]='\t';
                rg[i].linea[6]=rg[i].resultado[0]='0';
                rg[i].linea[7]=rg[i].resultado[1]='0';
                rg[i].linea[8]=rg[i].resultado[2]='0';
                rg[i].linea[9]=rg[i].resultado[3]=rg[i].op[0];
                rg[i].linea[10]=rg[i].resultado[4]='0';
                rg[i].linea[11]=rg[i].resultado[5]='0';
                rg[i].linea[12]=rg[i].resultado[6]='1';
                rg[i].linea[13]=rg[i].resultado[7]='E';
                rg[i].linea[14]='\t';
                rg[i].linea[15]=rg[i].source[0];
                rg[i].linea[16]=rg[i].source[1];
                rg[i].linea[17]=rg[i].source[2];
                rg[i].linea[18]=rg[i].source[3];
                rg[i].linea[19]=rg[i].op[0];
                rg[i].linea[20]=rg[i].op[1];
                rg[i].linea[21]=rg[i].op[2];
                rg[i].linea[22]=rg[i].op[3];
            }
            if(rg[i].op[0]==NULL){
                ;
            }
            if((rg[i].op[1]==','||rg[i].op[2]==','||
               rg[i].op[3]==','||rg[i].op[4]==',')==false){
                ;
            }
        }//FIN DC.W
        if(rg[i].source[0]=='S'&&rg[i].source[1]=='T'&&rg[i].source[2]=='A'){////////////////////START CASE
            rg[i].linea[5]='\t';
            rg[i].linea[6]='\t';
            rg[i].linea[7]='\t';
            rg[i].linea[8]=rg[i].source[0];
            rg[i].linea[9]=rg[i].source[1];
            rg[i].linea[10]=rg[i].source[2];
            rg[i].linea[11]=rg[i].source[3];
            rg[i].linea[12]=rg[i].source[4];
        }//FIN START
        if(rg[i].source[0]=='E'&&rg[i].source[1]=='N'&&rg[i].source[2]=='D'){////////////////////END CASE
            rg[i].linea[5]='\t';
            rg[i].linea[6]='\t';
            rg[i].linea[7]='\t';
            rg[i].linea[8]=rg[i].source[0];
            rg[i].linea[9]=rg[i].source[1];
            rg[i].linea[10]=rg[i].source[2];
        }//FIN END
    }
    mostrar_lineas();
}

void dec_to_hex(int dec, int i){////////////////////////////////////////////////////////////////////////////////////////////////////////////CONVERTIR DECIMAL A HEXADECIMAL
    int num=0, temp_num=0, it = 0, j=0, r=0,cont=0;
    char hex[4];
    temp_num = dec;
    while (temp_num != 0)
    {
        r = temp_num % 16;
        if (r <= 9){
            hex[cont] = r + 48;
            cout<<hex[cont];
        }
        else if(r>=10){
            //cout<<"AAAAAAAA"<<endl<<endl;
            hex[cont] = r + 55;
            cout<<hex[cont];
        }
        temp_num = temp_num / 16;
        cont++;
    }
    if(dec==0){
        hex[cont]=r+48;
    }
    int ayuda=0;
    while(cont!=-1){
       // if(hex[cont]!=NULL){
            cout <<"$"<< hex[cont];
        if(rg[i].resultado[ayuda]!=NULL){
            rg[i].resultado[ayuda+1] = hex[cont];
        }
        else
            rg[i].resultado[ayuda] = hex[cont];//}
        //cout<<rg[i].resultado[ayuda];
        //cout<<ayuda;
        cont=cont-1;
        ayuda++;
    }
    cout<<endl;
}

void oct_to_hex(int octalNumber, int i){////////////////////////////////////////////////////////////////////////////////////////////////////////////CONVERTIR OCTAL A HEXADECIMAL
    int decimalNumber = 0, it = 0, rem;
        while (octalNumber != 0)
        {
            rem = octalNumber % 10;
            octalNumber /= 10;
            decimalNumber += rem * pow(8, it);
            ++it;
        }
    //cout<<"\t@"<<decimalNumber<<endl;
    dec_to_hex(decimalNumber, i);
}

void bin_to_hex(int bin, int i){////////////////////////////////////////////////////////////////////////////////////////////////////////////CONVERTIR BINARIO A HEXADECIMAL
    int dec = 0, it = 0, rem;
      while (bin!=0) {
        rem = bin % 10;
        bin /= 10;
        dec += rem * pow(2, it);
        ++it;
      }
    //cout<<"%"<<dec;
    dec_to_hex(dec, i);
}

void formula1_pos(int dec, int i){////////////////////////////////////////////////////////////////////////////////////////////////////////////FORUMULA 1 POSITIVA
    char arreglo_bin1[4], ayuda, ayuda2;
    int temp_bin;
    if(rg[i].op[3]=='X'){
        arreglo_bin1[0]='0';
        arreglo_bin1[1]='0';
    }
    else if(rg[i].op[3]=='Y'){
        arreglo_bin1[0]='0';
        arreglo_bin1[1]='1';
    }
    else if(rg[i].op[3]=='S'){
        arreglo_bin1[0]='1';
        arreglo_bin1[1]='0';
    }
    else if(rg[i].op[3]=='P'){
        arreglo_bin1[0]='1';
        arreglo_bin1[1]='1';
    }
    arreglo_bin1[2]='0';
    arreglo_bin1[3]='0';
    
    temp_bin = ((int(arreglo_bin1[0])-48)*1000) + ((int(arreglo_bin1[1])-48)*100) + ((int(arreglo_bin1[2])-48)*10) + ((int(arreglo_bin1[3])-48)*1);
    bin_to_hex(temp_bin, i);
    /*int dec = 0, it = 0, rem;
      while (temp_bin!=0) {
        rem = temp_bin % 10;
          temp_bin /= 10;
        dec += rem * pow(2, it);
        ++it;
      }
    ayuda2 = dec_to_hex_1byte(temp_bin);
    rg[i].resultado[1] = ayuda2;*/
    //ayuda= dec_to_hex_1byte(16-decimal);
    //rg[i].resultado[2] = rg[i].op[1];
}

void formula1_neg(int decimal, int i){////////////////////////////////////////////////////////////////////////////////////////////////////////////FORUMULA 1 NEGATIVA
    char arreglo_bin1[4], ayuda;
    int temp_bin;
    if(rg[i].op[4]=='X'){
        arreglo_bin1[0]='0';
        arreglo_bin1[1]='0';
    }
    else if(rg[i].op[4]=='Y'){
        arreglo_bin1[0]='0';
        arreglo_bin1[1]='1';
    }
    else if(rg[i].op[4]=='S'){
        arreglo_bin1[0]='1';
        arreglo_bin1[1]='0';
    }
    else if(rg[i].op[4]=='P'){
        arreglo_bin1[0]='1';
        arreglo_bin1[1]='1';
    }
    arreglo_bin1[2]='0';
    arreglo_bin1[3]='1';
    
    temp_bin = ((int(arreglo_bin1[0])-48)*1000) + ((int(arreglo_bin1[1])-48)*100) + ((int(arreglo_bin1[2])-48)*10) + ((int(arreglo_bin1[3])-48)*1);
    bin_to_hex(temp_bin, i);
    /*int dec = 0, it = 0, rem;
      while (temp_bin!=0) {
        rem = temp_bin % 10;
          temp_bin /= 10;
        dec += rem * pow(2, it);
        ++it;
      }
    ayuda2 = dec_to_hex_1byte(temp_bin);
    rg[i].resultado[1] = ayuda2;*/
    ayuda= dec_to_hex_1byte(16-decimal);
    rg[i].resultado[2] = ayuda;
    }
    
void formula2_pos(int decimal, int i){////////////////////////////////////////////////////////////////////////////////////////////////////////////FORMULA 2 POSITIVA
    char arreglo_bin1[4], arreglo_bin2[4], ayuda2;
    int temp_bin, dec = 0, it = 0, rem;
    arreglo_bin1[0]='1';
    arreglo_bin1[1]='1';
    arreglo_bin1[2]='1';
    if(rg[i].op[3]=='X'){
        arreglo_bin1[3]='0';
        arreglo_bin2[0]='0';
    }
    else if(rg[i].op[3]=='Y'){
        arreglo_bin1[3]='0';
        arreglo_bin2[0]='1';
    }
    else if(rg[i].op[3]=='S'){
        arreglo_bin1[3]='1';
        arreglo_bin2[0]='0';
    }
    else if(rg[i].op[3]=='P'){
        arreglo_bin1[3]='1';
        arreglo_bin2[0]='1';
    }
    arreglo_bin2[1]='0';
    if(decimal>255){
        arreglo_bin2[2]='1';
    }
    else{
        arreglo_bin2[2]='0';
    }
    arreglo_bin2[3]='0';
    temp_bin = ((int(arreglo_bin1[0])-48)*1000) + ((int(arreglo_bin1[1])-48)*100) + ((int(arreglo_bin1[2])-48)*10) + ((int(arreglo_bin1[3])-48)*1);
    bin_to_hex(temp_bin, i);
    temp_bin = ((int(arreglo_bin2[0])-48)*1000) + ((int(arreglo_bin2[1])-48)*100) + ((int(arreglo_bin2[2])-48)*10) + ((int(arreglo_bin2[3])-48)*1);
    bin_to_hex(temp_bin, i);
}

void formula2_neg(int decimal, int i){////////////////////////////////////////////////////////////////////////////////////////////////////////////FORUMULA 2 NEGATIVA
    char arreglo_bin1[4], arreglo_bin2[4];
    int temp_bin;
    arreglo_bin1[0]='1';
    arreglo_bin1[1]='1';
    arreglo_bin1[2]='1';
    if(rg[i].op[4]=='X'){
        arreglo_bin1[3]='0';
        arreglo_bin2[0]='0';
    }
    else if(rg[i].op[4]=='Y'){
        arreglo_bin1[3]='0';
        arreglo_bin2[0]='1';
    }
    else if(rg[i].op[4]=='S'){
        arreglo_bin1[3]='1';
        arreglo_bin2[0]='0';
    }
    else if(rg[i].op[4]=='P'){
        arreglo_bin1[3]='1';
        arreglo_bin2[0]='1';
    }
    arreglo_bin2[1]='0';
    if(decimal>255){
        arreglo_bin2[2]='1';
    }
    else{
        arreglo_bin2[2]='0';
    }
    arreglo_bin2[3]='1';
    temp_bin = ((int(arreglo_bin1[0])-48)*1000) + ((int(arreglo_bin1[1])-48)*100) + ((int(arreglo_bin1[2])-48)*10) + ((int(arreglo_bin1[3])-48)*1);
    bin_to_hex(temp_bin, i);
    temp_bin = ((int(arreglo_bin2[0])-48)*1000) + ((int(arreglo_bin2[1])-48)*100) + ((int(arreglo_bin2[2])-48)*10) + ((int(arreglo_bin2[3])-48)*1);
    bin_to_hex(temp_bin, i);
    int ayuda= 16 - int(rg[i].resultado[2]-48);
    if(ayuda<10){
        rg[i].resultado[2]= ayuda+48;
    }
    if(ayuda>=10){
        rg[i].resultado[2]= ayuda+55;
    }
}

void formula3(int i){////////////////////////////////////////////////////////////////////////////////////////////////////////////FORUMULA 3 [_ _ , _ _]
    char arreglo_bin1[4], arreglo_bin2[4];
    int temp_bin;
    arreglo_bin1[0]='1';
    arreglo_bin1[1]='1';
    arreglo_bin1[2]='1';
    if(rg[i].op[4]=='X'){
        arreglo_bin1[3]='0';
        arreglo_bin2[0]='0';
    }
    else if(rg[i].op[4]=='Y'){
        arreglo_bin1[3]='0';
        arreglo_bin2[0]='1';
    }
    else if(rg[i].op[4]=='S'){
        arreglo_bin1[3]='1';
        arreglo_bin2[0]='0';
    }
    else if(rg[i].op[4]=='P'){
        arreglo_bin1[3]='1';
        arreglo_bin2[0]='1';
    }
    arreglo_bin2[1]='0';
    arreglo_bin2[2]='1';
    arreglo_bin2[3]='1';
    temp_bin = ((int(arreglo_bin1[0])-48)*1000) + ((int(arreglo_bin1[1])-48)*100) + ((int(arreglo_bin1[2])-48)*10) + ((int(arreglo_bin1[3])-48)*1);
    bin_to_hex(temp_bin, i);
    temp_bin = ((int(arreglo_bin2[0])-48)*1000) + ((int(arreglo_bin2[1])-48)*100) + ((int(arreglo_bin2[2])-48)*10) + ((int(arreglo_bin2[3])-48)*1);
    bin_to_hex(temp_bin, i);
}

void formula3_larga(int i){////////////////////////////////////////////////////////////////////////////////////////////////////////////FORUMULA 3 larga[_ _ _ , _ _]
    char arreglo_bin1[4], arreglo_bin2[4];
    int temp_bin;
    arreglo_bin1[0]='1';
    arreglo_bin1[1]='1';
    arreglo_bin1[2]='1';
    if(rg[i].op[5]=='X'){
        arreglo_bin1[3]='0';
        arreglo_bin2[0]='0';
    }
    else if(rg[i].op[5]=='Y'){
        arreglo_bin1[3]='0';
        arreglo_bin2[0]='1';
    }
    else if(rg[i].op[5]=='S'){
        arreglo_bin1[3]='1';
        arreglo_bin2[0]='0';
    }
    else if(rg[i].op[5]=='P'){
        arreglo_bin1[3]='1';
        arreglo_bin2[0]='1';
    }
    arreglo_bin2[1]='0';
    arreglo_bin2[2]='1';
    arreglo_bin2[3]='1';
    temp_bin = ((int(arreglo_bin1[0])-48)*1000) + ((int(arreglo_bin1[1])-48)*100) + ((int(arreglo_bin1[2])-48)*10) + ((int(arreglo_bin1[3])-48)*1);
    bin_to_hex(temp_bin, i);
    temp_bin = ((int(arreglo_bin2[0])-48)*1000) + ((int(arreglo_bin2[1])-48)*100) + ((int(arreglo_bin2[2])-48)*10) + ((int(arreglo_bin2[3])-48)*1);
    bin_to_hex(temp_bin, i);
}

void formula4_pos(int temp_dec, int i){
    char arreglo_bin1[4], ayuda;
    int temp_bin;
    if(rg[i].op[3]=='X'||rg[i].op[4]=='X'){
        arreglo_bin1[0]='0';
        arreglo_bin1[1]='0';
    }
    else if(rg[i].op[3]=='Y'||rg[i].op[4]=='Y'){
        arreglo_bin1[0]='0';
        arreglo_bin1[1]='1';
    }
    else if(rg[i].op[3]=='S'||rg[i].op[4]=='S'){
        arreglo_bin1[0]='1';
        arreglo_bin1[1]='0';
    }
    arreglo_bin1[2]='1';
    if(rg[i].op[3]=='+'){
        arreglo_bin1[3]='0';
    }
    else{
        arreglo_bin1[3]='1';
    }
    temp_bin = ((int(arreglo_bin1[0])-48)*1000) + ((int(arreglo_bin1[1])-48)*100) + ((int(arreglo_bin1[2])-48)*10) + ((int(arreglo_bin1[3])-48)*1);
    bin_to_hex(temp_bin, i);
    ayuda= dec_to_hex_1byte(temp_dec-1);
    rg[i].resultado[2]=ayuda;
}

void formula4_neg(int temp_dec, int i){
    char arreglo_bin1[4], ayuda;
    int temp_bin;
    if(rg[i].op[3]=='X'||rg[i].op[4]=='X'){
        arreglo_bin1[0]='0';
        arreglo_bin1[1]='0';
    }
    else if(rg[i].op[3]=='Y'||rg[i].op[4]=='Y'){
        arreglo_bin1[0]='0';
        arreglo_bin1[1]='1';
    }
    else if(rg[i].op[3]=='S'||rg[i].op[4]=='S'){
        arreglo_bin1[0]='1';
        arreglo_bin1[1]='0';
    }
    arreglo_bin1[2]='1';
    if(rg[i].op[3]=='-'){
        arreglo_bin1[3]='0';
    }
    else{
        arreglo_bin1[3]='1';
    }
    temp_bin = ((int(arreglo_bin1[0])-48)*1000) + ((int(arreglo_bin1[1])-48)*100) + ((int(arreglo_bin1[2])-48)*10) + ((int(arreglo_bin1[3])-48)*1);
    bin_to_hex(temp_bin, i);
    ayuda= dec_to_hex_1byte(16-temp_dec);
    rg[i].resultado[2]=ayuda;
}

void resta_2_bytes(int i, char etq1, char etq2, char etq3, char etq4, char contloc1,
                   char contloc2, char contloc3, char  contloc4){////////////////////////////////////////////////////////////////////////////////////////////////////////////RESTA HEX DOS BYTES
    int minu3, minu4, sus3, sus4, resultado3, resultado4;
    minu3= hex_to_dec_1byte(etq3);
    minu4= hex_to_dec_1byte(etq4);
    sus3= hex_to_dec_1byte(contloc3);
    sus4= hex_to_dec_1byte(contloc4);
    if(minu4 < sus4){
        resultado4= (minu4+16) - sus4;
        minu3=minu3-1;
        if(minu3==-1){
            minu3 = minu3 + 16;
        }
    }
    else{
        resultado4= minu4 - sus4;
    }
    resultado3=minu3-sus3;
    rg[i].resultado[0]= dec_to_hex_1byte(resultado3);
    rg[i].resultado[1]= dec_to_hex_1byte(resultado4);
}
void resta_4_bytes(int i, char etq1, char etq2, char etq3, char etq4, char contloc1,
                   char contloc2, char contloc3, char contloc4)
    {////////////////////////////////////////////////////////////////////////////////////////////////////////////RESTA HEX CUATRO BYTES
    int minu1, minu2, minu3, minu4, sus1, sus2, sus3, sus4,
    resultado1=0, resultado2=0, resultado3=0, resultado4=0, band_pos=0, band_neg=0;
    minu1= hex_to_dec_1byte(etq1);
    minu2= hex_to_dec_1byte(etq2);
    minu3= hex_to_dec_1byte(etq3);
    minu4= hex_to_dec_1byte(etq4);
    sus1= hex_to_dec_1byte(contloc1);
    sus2= hex_to_dec_1byte(contloc2);
    sus3= hex_to_dec_1byte(contloc3);
    sus4= hex_to_dec_1byte(contloc4);
    if((minu1*1000 + minu2*100 + minu3*10 + minu4*1)>=
       (sus1*1000 + sus2*100 + sus3*10 + sus4*1)){
        band_pos=1;
    }
    if((minu1*1000 + minu2*100 + minu3*10 + minu4*1)<
       (sus1*1000 + sus2*100 + sus3*10 + sus4*1)){
        band_neg=1;
    }
    
    if(minu4 < sus4){
        resultado4= (minu4+16) - sus4;
        minu3 = minu3 -1;
        if(minu3==-1){
            minu3=minu3+16;
            minu2=minu2-1;
            if(minu2==-1){
                minu2=minu2+16;
                minu1=minu1-1;
                if(minu1==-1){
                    minu1=minu1+16;
                }
            }
        }
    }
    if(minu4 >= sus4){
        resultado4= minu4 - sus4;
    }
    
    if(minu3 < sus3){
        resultado3= (minu3+16) - sus3;
        minu2=minu2-1;
    }
    if(minu3 >= sus3){
        resultado3= minu3 - sus3;
    }
    if(minu2 < sus2){
        resultado2= (minu2+16) - sus2;
        minu1= minu1 -1;
    }
    if(minu2 >= sus2){
        resultado2=minu2 - sus2;
    }
    if(minu1 < sus1){
        resultado1= (minu1 +16) -sus1;
    }
    if(minu1 >= sus1){
        resultado1 = minu1 - sus1;
    }
    rg[i].resultado[0]= dec_to_hex_1byte(resultado1);
    rg[i].resultado[1]= dec_to_hex_1byte(resultado2);
    rg[i].resultado[2]= dec_to_hex_1byte(resultado3);
    rg[i].resultado[3]= dec_to_hex_1byte(resultado4);
    
    if(band_pos==1){
        if(int(rg[i].resultado[2]-48)>7 || rg[i].resultado[1] !='0' ||rg[i].resultado[0] !='0'){
            rg[i].resultado[4]=' ';
            rg[i].resultado[5]='F';
            rg[i].resultado[6]='D';
            rg[i].resultado[7]='R';
        }
    }
    
    if(band_neg==1){
        if(int(rg[i].resultado[2]-48)<8){// || rg[i].resultado[1] !='0' ||rg[i].resultado[0] !='0'){
            rg[i].resultado[4]=' ';
            rg[i].resultado[5]='F';
            rg[i].resultado[6]='D';
            rg[i].resultado[7]='R';
        }
    }
    
    
}
void resta_IBNE(int i, char ABDXYSP, char etq1, char etq2, char etq3, char etq4, char contloc1,
                   char contloc2, char contloc3, char  contloc4){////////////////////////////////////////////////////////////////////////////////////////////////////////////RESTA HEX DOS BYTES
    int minu1, minu2, minu3, minu4, sus1, sus2, sus3, sus4, resultado3=0, resultado4=0,totalhex1, totalhex2;
    minu1= hex_to_dec_1byte(etq1);
    minu2= hex_to_dec_1byte(etq2);
    minu3= hex_to_dec_1byte(etq3);
    minu4= hex_to_dec_1byte(etq4);
    sus1= hex_to_dec_1byte(contloc1);
    sus2= hex_to_dec_1byte(contloc2);
    sus3= hex_to_dec_1byte(contloc3);
    sus4= hex_to_dec_1byte(contloc4);
    totalhex1=(pow(minu1,3) + pow(minu2,2) + pow(minu3,1) + pow(minu4,0));
    totalhex2=(pow(sus1,3) + pow(sus2,2) + pow(sus3,1) + pow(sus1,0));
    if(totalhex1 > totalhex2){//resta positiva
        if(ABDXYSP == 'A'){
            rg[i].resultado[0] = 'A';
            rg[i].resultado[1] = '0';
        }
        if(ABDXYSP == 'B'){
            rg[i].resultado[0] = 'A';
            rg[i].resultado[1] = '1';
        }
        if(ABDXYSP == 'D'){
            rg[i].resultado[0] = 'A';
            rg[i].resultado[1] = '4';
        }
        if(ABDXYSP == 'X'){
            rg[i].resultado[0] = 'A';
            rg[i].resultado[1] = '5';
        }
        if(ABDXYSP == 'Y'){
            rg[i].resultado[0] = 'A';
            rg[i].resultado[1] = '6';
        }
        if(ABDXYSP == 'S'){
            rg[i].resultado[0] = 'A';
            rg[i].resultado[1] = '7';
        }
    }
    if(totalhex1 < totalhex2){//resta negativa
        if(ABDXYSP == 'A'){
            rg[i].resultado[0] = 'B';
            rg[i].resultado[1] = '0';
        }
        if(ABDXYSP == 'B'){
            rg[i].resultado[0] = 'B';
            rg[i].resultado[1] = '1';
        }
        if(ABDXYSP == 'D'){
            rg[i].resultado[0] = 'B';
            rg[i].resultado[1] = '4';
        }
        if(ABDXYSP == 'X'){
            rg[i].resultado[0] = 'B';
            rg[i].resultado[1] = '5';
        }
        if(ABDXYSP == 'Y'){
            rg[i].resultado[0] = 'B';
            rg[i].resultado[1] = '6';
        }
        if(ABDXYSP == 'S'){
            rg[i].resultado[0] = 'B';
            rg[i].resultado[1] = '7';
        }
    }
    if(minu4 < sus4){
        resultado4= (minu4+16) - sus4;
        minu3=minu3-1;
        if(minu3==-1){
            minu3 = minu3 + 16;
        }
    }
    else{
        resultado4= minu4 - sus4;
    }
    resultado3=minu3-sus3;
    rg[i].resultado[2]= dec_to_hex_1byte(resultado3);
    rg[i].resultado[3]= dec_to_hex_1byte(resultado4);
}
int hex_to_dec_1byte(char hex){////////////////////////////////////////////////////////////////////////////////////////////////////////////CHAR HEX TO INT DEC
    int dec=16;
    if(hex=='0'){
        dec=0;
    }
    if(hex=='1'){
        dec=1;
    }
    if(hex=='2'){
        dec=2;
    }
    if(hex=='3'){
        dec=3;
    }
    if(hex=='4'){
        dec=4;
    }
    if(hex=='5'){
        dec=5;
    }
    if(hex=='6'){
        dec=6;
    }
    if(hex=='7'){
        dec=7;
    }if(hex=='8'){
        dec=8;
    }if(hex=='9'){
        dec=9;
    }
    if(hex=='A'){
        dec=10;
    }
    if(hex=='B'){
        dec=11;
    }
    if(hex=='C'){
        dec=12;
    }
    if(hex=='D'){
        dec=13;
    }
    if(hex=='E'){
        dec=14;
    }
    if(hex=='F'){
        dec=15;
    }
    return dec;
}

char dec_to_hex_1byte(int dec){////////////////////////////////////////////////////////////////////////////////////////////////////////////INT DEC TO CHAR HEX
    char hex='0';
    if(dec==0){
        hex='0';
    }
    if(dec==1){
        hex='1';
    }
    if(dec==2){
        hex='2';
    }
    if(dec==3){
        hex='3';
    }
    if(dec==4){
        hex='4';
    }
    if(dec==5){
        hex='5';
    }
    if(dec==6){
        hex='6';
    }
    if(dec==7){
        hex='7';
    }
    if(dec==8){
        hex='8';
    }
    if(dec==9){
        hex='9';
    }
    if(dec==10){
        hex='A';
    }
    if(dec==11){
        hex='B';
    }
    if(dec==12){
        hex='C';
    }
    if(dec==13){
        hex='D';
    }
    if(dec==14){
        hex='E';
    }
    if(dec==15){
        hex='F';
    }
    return hex;
}

int dec_to_binary(int dec){////////////////////////////////////////////////////////////////////////////////////////////////////////////INT DEC TO INT BINARY
    int bin=0;
    return bin;
}
