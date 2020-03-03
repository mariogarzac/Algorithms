//
//  main.cpp
//  calificacioneMasComun
//
//  Created by Mario Garza Chapa on 21/02/20.
//  Copyright © 2020 Mario Garza Chapa. All rights reserved.
//

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

/*
 MARIO GARZA
 A01720245
 
 PROBLEMAS #1 Y #2 DE LA TAREA #1.2
*/

//Función que imprime la calificación y sus repeticiones más común en los archivos.
//Esta función toma de parametro la cantidad de archivos que se desea leer.
void commonGradeArray(int n){
    fstream inFile;
    string fileName;
    
    int num = 0;
    
    int repMax = 0;
    int califMax = 0;
    int arr[100] ={0};
    
    //Loop que pide el nombre del archivo que se leerá.
    for (int i = 0; i < n; i++){
        cout << "File name ";
        cin >> fileName;
        inFile.open("/Users/mariogarza/desktop/" + fileName);
        
        //If que revisa que el archivo se abra correctamente. Si se abre, sumará todos los valores en sus respectivas casillas.
        if (!inFile.is_open()){
            cout << "Error al abrir. Revisa el PATH" << endl;
            exit(1);
        }else{
            while(inFile >> num){
                arr[num - 1] += 1;
            }
        }
        
        inFile.close();
    }
    
    //Loop que busca el valor más repetido
    for (int i = 0; i < 100; i++){
        if (arr[i] >= repMax)
        {
            repMax = arr[i];
            califMax = i;
        }
    }
    
    cout << califMax + 1 << " " << repMax;
}

//Función que imprime la calificación y sus repeticiones más común en los archivos.
//Esta función toma de parametro la cantidad de archivos que se desea leer.
void commonGradeVector(int n){
    fstream inFile;
    string fileName;
    vector<int> grades;
    
    int num = 0;

    //Loop para leer los datos de los archivos.
    for(int i = 0; i < n; i++){
        cout << "File name ";
        cin >> fileName;
        inFile.open("/Users/mariogarza/desktop/" + fileName);
        
        if (!inFile.is_open()){
            cout << "Error al abrir. Revisa el PATH." << endl;
            exit(1);
        }else{
            while(inFile >> num){
                grades.push_back(num);
            }
        }
    }
    
    sort(grades.begin(),grades.end());
    
    int repMax = 0;
    int califMax = grades[0];
    int repTmp = 0;
    int califTmp = 0;
    int i = 1;
    
    //Loop que guarda la cantidad de repeticiones de la primera calificación.
    while (grades[i] == califMax)
    {
        repMax += 1;
        i++;
    }
    
    //Loop que compara las repeticiones de la calificación anterior y la siguiente.
    while (i < grades.size())
    {
        if (grades[i] == grades[i - 1])
        {
            repTmp += 1;
            califTmp = grades[i];
        }else{
            if(repTmp >= repMax){
                repMax = repTmp;
                califMax = califTmp;
            }
            repTmp = 0;
            califTmp = 0;
        }
        
        i++;
    }
    if(repTmp >= repMax){
        repMax = repTmp;
        califMax = califTmp;
    }
    
    cout << "RESULTADOS: " << califMax << " " << repMax << endl;
}
 



int main(int argc, const char * argv[]) {
    
    
    
    return 0;
}
