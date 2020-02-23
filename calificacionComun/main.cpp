//
//  main.cpp
//  calificacioneMasComun
//
//  Created by Mario Garza Chapa on 21/02/20.
//  Copyright © 2020 Mario Garza Chapa. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

//Función que retorna el valor de la calificación más común en los archivos.
int getCommonGrade(int n){
    fstream inFile;
    string fileName;
    int biggest = 0;
    int arr[100] ={0};
    int num = 0;
    
    //Loop que pide el nombre del archivo que se leerá.
    for (int i = 0; i < n; i++){
        cout << "File name ";
        cin >> fileName;
        inFile.open("/Users/mariogarza/desktop/" + fileName);
        
        //If que revisa que el archivo se abra correctamente. Si se abre, sumará todos los valores en sus respectivas casillas.
        if (!inFile.is_open()){
            cout << "Error al abrir. Revisa el PATH";
            exit(1);
        }else{
            while(inFile >> num){
                arr[num - 1] += 1;
            }
        }
        
        inFile.close();
        inFile.clear();
    }
    
    //Loop que busca el valor más repetido
    for (int i = 0; i < 100; i++){
        if (arr[i] > biggest)
        {
            biggest = i;
        }
    }
    return biggest + 1;
}

int main(int argc, const char * argv[]) {
    
    cout << getCommonGrade(2) << endl;
    
    return 0;
}
