#pragma once
/**
 * Calcula la raíz cuadrada de un número utilizando el método de Newton-Raphson.
 * Este algoritmo aproxima la raíz cuadrada de un valor mediante iteraciones.
 * Si el valor es negativo, devuelve 0.
 *
 * @param valor: El número del cual se quiere calcular la raíz cuadrada.
 * @return La aproximación de la raíz cuadrada del valor dado.
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