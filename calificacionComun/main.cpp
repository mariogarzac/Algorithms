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

int readFiles(int arr[], int n){
  
    return 0;
}


//Funcion que lee archivos y suma la repetición de cada numero en un arreglo. Despliega el numero más repetido y sus repeticiones.
void getCommonGrade(){
    
    fstream inFile;
    string fileName = " ";
    
    int num;
    int n = 0;
    int arr[100] = {0};
    
    int biggest = 0;
    int repeat = 0;
    
    cout << "Numero de archivos ";
    cin >> n;
    //Loop para preguntar el nombre de los archivos y sumar sus repeticiones al arreglo.
    
    for (int i = 0; i < n; i++){
                    
        cout << "File Name " << endl;
        cin >> fileName;
        inFile.open("/Users/mariogarza/desktop/" + fileName);
        
        if (!inFile.is_open())
        {
            cout << "No se abrió. Checar PATH" << endl;
            exit(1);
            
        }else{
            while (inFile >> num)
            {
                arr[num - 1] += 1;
            }
        }
        //Loop para checar cual es el valor más repetido de los archivos
        for (int i = 0; i < 100; i++)
        {
            if (arr[i] >= biggest)
            {
                biggest = arr[i];
                repeat = i;
            }
        }
        
        //Cierra el archivo para poder continuar leyendo.
        inFile.close();
        inFile.clear();
    }
    //Despliega el numero más repetido y sus repeticiones
    cout << repeat + 1 << endl;
    cout << biggest << endl;
     
}


int main(int argc, const char * argv[]) {
    
    getCommonGrade();
    
    return 0;
}

