#include <iostream>
#include <string>
#include "e92math.hpp"

using std::string;

/*
    Funcion que toma un mensaje y lo encripta.
*/
string e92math::CaesarCipher(const string &message, int shift)
{
    // Obtener el valor numerico (ASCII) de A y Z
    int inicio = 'A';
    int final = 'Z';

    // Copiar el mensaje
    string result = message;

    // Recorrer el arreglo de caracteres o string
    for (size_t i = 0; i < message.size(); i++)
    {
        // Guardar el caracter actual
        char caracter_actual = message[i];

        // if (isupper(caracter_actual)) // Si es mayuscula, cambiar el caracter
        if (caracter_actual >= inicio && caracter_actual <= final) // Otra forma de averiguar si el caracter es mayuscula
        {
            // Obtener la cantidad de caracteres a moverse, nunca superar 26
            int corrimiento_ascii = ((caracter_actual - inicio) + shift) % 26;
            // Obtener el caracter objetivo (ej: 65 + corrimiento_ascii)
            char caracter_nuevo = inicio + corrimiento_ascii;
            // Modificar el caracter existente con el nuevo valor
            result[i] = caracter_nuevo;
        }
    }

    // Retornar el nuevo string encriptado
    return result;
}