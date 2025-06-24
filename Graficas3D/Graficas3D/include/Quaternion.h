#pragma once
#include "MathLibrary.h"
#include "Vector3.h"

/**
 * Clase Quaternion: Representa un cuaterni�n con cuatro componentes (w, x, y, z).
 * Utilizado com�nmente para realizar rotaciones en 3D.
 */
class
Quaternion {
public:
	float x; //Componente x del Quaternion
	float y; //Componente y del Quaternion que representa i
	float z; //Componente z del Quaternion que representa j
	float w; //Componente w del Quaternion que representa k

	/**
	 * Constructor por defecto.
	 * Inicializa el vector con los valores (0, 0, 0, 0).
	 */

	Quaternion() : x(0), y(0), z(0), w(0) {};
	/**
	 * Constructor que inicializa un vector con valores espec�ficos.
	 * @param valX: Valor para el componente x.
	 * @param valY: Valor para el componente y.
	 * @param valZ: Valor para el componente z.
	 * @param valW: Valor para el componente W o tambien la parte escalar
	 */
	Quaternion(float valX, float valY, float valZ, float valW) :x(valX), y(valY), z(valZ), w(valW) {};

	/**
	 * Constructor que inicializa un cuaterni�n a partir de un �ngulo y un eje de rotaci�n.
	 * @param angleRad �ngulo de rotaci�n en radianes.
	 * @param axis Eje de rotaci�n representado por un vector de 3 dimensiones.
	 */
	Quaternion(float angleRad, const Vector3& axis) {
		float halfAngle = angleRad / 2;
		float sinHalfAngle = Msin(halfAngle);

		w = Mcos(halfAngle);
		x = axis.x * sinHalfAngle;
		y = axis.y * sinHalfAngle;
		z = axis.z * sinHalfAngle;
	}
	/**
	 * Sobrecarga del operador + para sumar cuaterniones.
	 * @param other El cuaterni�n con el que se sumar�.
	 * @return la suma de los dos cuaterniones.
	 */

	Quaternion operator+(const Quaternion& other)const {
		float new_valX = x + other.x;
		float new_valY = y + other.y;
		float new_valZ = z + other.z;
		float new_valW = w + other.w;
		return Quaternion(new_valX, new_valY, new_valZ, new_valW);
	}
	
	/**
	 * Sobrecarga del operador * para multiplicar un cuaterni�n por un escalar.
	 * @param escalar Valor escalar por el cual multiplicar el cuaterni�n.
	 * @return Resultado de la multiplicaci�n por escalar.
	 */
	Quaternion operator*(float escalar)const {
		float new_valX = x * escalar;
		float new_valY = y * escalar;
		float new_valZ = z * escalar;
		float new_valW = w * escalar;
		return Quaternion(new_valX, new_valY, new_valZ, new_valW);
	}

	/**
		 * Sobrecarga del operador * para multiplicar dos cuaterniones.
		 * @param other El cuaterni�n con el cual se multiplicar�.
		 * @return Resultado de la multiplicaci�n de los dos cuaterniones.
		 */
	Quaternion operator*(const Quaternion& other) const {
		return Quaternion(
			w * other.w - x * other.x - y * other.y - z * other.z,
			w * other.x + x * other.w + y * other.z - z * other.y,
			w * other.y - x * other.z + y * other.w + z * other.x,
			w * other.z + x * other.y - y * other.x + z * other.w
		);
	}

	/**
	 * Calcula la magnitud del cuaterni�n.
   * La magnitud es sqrt(w^2 + x^2 + y^2 + z^2).
	 * @return Magnitud del cuaterni�n.
	 */
	float
	magnitud() const {
		return MraizNewton(x * x + y * y + z * z + w * w);
	}
	/**
	 * Normaliza el cuaterni�n para que tenga una magnitud de 1.
	 * Si la magnitud del cuaterni�n es 0, se retorna un cuaterni�n nulo.
	 * @return Cuaternion 
	 */
	Quaternion normalizar() const {
		float mag = magnitud();
		if (mag == 0) {
			return Quaternion(0, 0, 0, 0);
		}
		return Quaternion(x / mag, y / mag, z / mag, w / mag);
	}

	/**
	 * Calcula el conjugado del cuaterni�n.
	 * El conjugado de un cuaterni�n (w, x, y, z) es (w, -x, -y, -z).
	 * @return Cuaterni�n conjugado.
	 */
	Quaternion conjugado() const {
		return Quaternion(w, -x, -y, -z);
	}

	/**
	 * Calcula el inverso del cuaterni�n.
	 * El inverso de un cuaternion se calcula con el cuaternion conjugado entre la magnitud cuadrada
	 * @return Cuaterni�n conjugado.
	 */
	Quaternion inverse() const {
		float magnitudCuadrada = w * w + x * x + y * y + z * z; // Magnitud al cuadrado

		if (magnitudCuadrada == 0) {
			return Quaternion(0, 0, 0, 0);
		}

		// Invertir cada componente
		return Quaternion(
					  w / magnitudCuadrada,
					 -x / magnitudCuadrada,
					 -y / magnitudCuadrada,
					 -z / magnitudCuadrada
		);
	}
	/**
	 * Rota un vector 3D utilizando el cuaterni�n.
	 * La rotaci�n se realiza utilizando la f�rmula q * v * q^-1, donde v es el vector a rotar.
	 * @param v El vector 3D a rotar.
	 * @return El vector rotado.
	 */	
	Vector3 rotate(const Vector3& v) const {
		Quaternion qv(0, v.x, v.y, v.z);
		Quaternion result = (*this) * qv * this->inverse();
		return Vector3(result.x, result.y, result.z);
	}
	/**
	 * Devuelve un puntero a los datos del vector (para acceso no constante).
	 * @return Un puntero constante a los componentes del cuaternion
	 */
	float*
	data() {
		return &w;
	}

	/**
	 * Devuelve un puntero a los datos del vector (para acceso constante).
	 * @return Un puntero constante a los componentes del cuaternion
	 */
	const float*
	data() const {
		return &w;
	}

private:

};
