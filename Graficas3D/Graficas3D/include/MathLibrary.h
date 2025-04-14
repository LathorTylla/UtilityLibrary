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

//Funciones trigonometricas, coseno, seno y tangente

/**
 * Calcula el coseno de un �ngulo en radianes utilizando la serie de Taylor.
 * La serie de Taylor aproxima el coseno mediante una suma infinita de t�rminos.
 *
 * @param angle �ngulo en radianes del cual se quiere calcular el coseno.
 * @return La aproximaci�n del coseno del �ngulo dado.
 */
inline float cos(float angle) {
  float result = 1.0f;                  // Primer t�rmino de la serie (cos(0) = 1)
  float term = 1.0f;                    // T�rmino actual de la serie
  float angle_squared = angle * angle;  // Precalcular el �ngulo al cuadrado
  int n = 1;                            // �ndice de la serie de Taylor
  while (term > 1e-6f || term < -1e-6f) {
    term *= -angle_squared / ((2 * n - 1) * (2 * n)); // Calcular el siguiente t�rmino
    result += term;                     // Sumar el t�rmino al resultado
    ++n;                                // Incrementar el �ndice de la serie
  }
  return result;                        // Regresa el resultado aproximado
}

/**
 * Calcula el seno de un �ngulo en radianes utilizando la serie de Taylor.
 * La serie de Taylor aproxima el seno mediante una suma infinita de t�rminos.
 *
 * @param angle �ngulo en radianes del cual se quiere calcular el seno.
 * @return La aproximaci�n del seno del �ngulo dado.
 */

inline float sin(float angle) {
  float result = 0.0f;                  // El seno de 0 es 0
  float term = angle;                   // Primer t�rmino de la serie
  float angle_squared = angle * angle;  // Calcular el �ngulo al cuadrado
  int n = 1;                            // �ndice de la serie de Taylor

  while (term > 1e-6f || term < -1e-6f) {
    result += term;                     // Sumar el t�rmino al resultado
    term *= -angle_squared / ((2 * n) * (2 * n + 1)); // Calcular el siguiente t�rmino
    ++n;                                // Incrementar el �ndice de la serie
  }
  return result;                        // Regresa el resultado aproximado
}

/**
 * Calcula la tangente de un �ngulo en radianes.
 * La tangente se calcula como la divisi�n entre el seno y el coseno.
 *
 * @param angle �ngulo en radianes del cual se quiere calcular la tangente.
 * @return La aproximaci�n de la tangente del �ngulo dado, o 0 si el coseno es 0.
 */

inline float tan(float angle) {
  float sinVal = sin(angle);            // Calcular el seno del �ngulo
  float cosVal = cos(angle);            // Calcular el coseno del �ngulo
  if (cosVal == 0) {
    return 0; // Evitar divisiones por 0
  }
  return sinVal / cosVal;               // Regresa el valor de la tangete (seno/coseno)
}

/**
 * Convierte un �ngulo de grados a radianes.
 * Para mejores practicas y se hace uso de los radianes
 *
 * @param degrees �ngulo en grados.
 * @return El �ngulo convertido a radianes.
 */
inline float degToRad(float degrees) {
  return degrees * (3.1416f / 180.0f);
}

/**
 * Convierte un �ngulo de radianes a grados.
 * Los �ngulos en radianes se pueden convertir a grados para facilitar la interpretaci�n.
 *
 * @param radians �ngulo en radianes.
 * @return El �ngulo convertido a grados.
 */
inline float radToGrad(float radians) {
  return radians * (180.0f / 3.1416f);
}