#include "point.h" // Incluye la definición de la estructura point_t y la declaración de la función freePoints
#include "pointreader.h" // Incluye la declaración de la función readPoints
#include "angularvelocitycalculator.h" // Incluye la declaración de la función computeMaximumAngularVelocity
#include <stdio.h> // Incluye la biblioteca estándar de entrada/salida
#include <csv.h> // Incluye la biblioteca para manejar archivos CSV

int main(int argc, char** argv)
{
	// Verifica que el número de argumentos sea 2 (nombre del programa y nombre del archivo)
	if (argc != 2)
	{
		// Imprime un mensaje de uso si el número de argumentos es incorrecto
		printf("Program to compute maximum angular velocity from a txt file of comma separated values produced by Tracker\n");
		printf("Usage: %s <filename>\n", argv[0]);
		return -1; // Termina el programa con un código de error
	}

	struct point_t* points; // Declara un puntero a una estructura point_t

	// Lee los puntos del archivo especificado en los argumentos
	int numberOfPoints = readPoints(argv[1], &points);

	// Verifica si hubo un error al leer el archivo
	if (numberOfPoints < 0)
	{
		// Imprime un mensaje de error si no se pudo leer el archivo
		printf("Error reading file\n");
		return -1; // Termina el programa con un código de error
	}

	// Calcula la velocidad angular máxima a partir de los puntos leídos
	float maximumAngularVelocity = computeMaximumAngularVelocity(points, numberOfPoints);

	// Imprime la velocidad angular máxima en revoluciones por minuto (rpm)
	printf("Maximum angular velocity: %f rad/s\n", maximumAngularVelocity);

	// Libera la memoria asignada para los puntos
	freePoints(&points);

	return 0; // Termina el programa exitosamente
}
