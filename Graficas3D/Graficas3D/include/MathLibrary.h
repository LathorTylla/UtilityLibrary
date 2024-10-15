#pragma once
/**
 * Calcula la ra�z cuadrada de un n�mero utilizando el m�todo de Newton-Raphson.
 * Este algoritmo aproxima la ra�z cuadrada de un valor mediante iteraciones.
 * Si el valor es negativo, devuelve 0.
 *
 * @param valor: El n�mero del cual se quiere calcular la ra�z cuadrada.
 * @return La aproximaci�n de la ra�z cuadrada del valor dado.
 */

inline float raizNewton(float valor) {
  if (valor < 0) {
    return 0; //Regresa si el valor no es positivo
  }
  float x = valor;            //Estimacion inicial para poder calcular la raiz
  float y = 1.0f;             //Valor de y
  float epsilon = 0.000001f;  //Margen de error o aproximacion

  // Bucle while hasta que la diferencia entre x e y sea menor que epsilon.
  while (x-y>epsilon){
    x = (x + y) / 2.0f; //Formula para poder sacar la aproximacion de x
    y = valor / x;   //Nuevo valor de y
  }
  return x;  //Regresa la aproximacion de la raiz cuadrada
}