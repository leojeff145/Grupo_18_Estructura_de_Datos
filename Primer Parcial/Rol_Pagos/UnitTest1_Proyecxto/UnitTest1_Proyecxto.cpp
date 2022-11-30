#include "pch.h"
#include "CppUnitTest.h"
#include<stdlib.h>
#include "../Rol_Pagos/Validacion.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1Proyecxto
{
	TEST_CLASS(UnitTest1Proyecxto)
	{
	public:
		
		TEST_METHOD(ingresar_DatosEnteros)
		{
			char* dato = new char[10], c;
			int i = 0;
			while ((c = _getch()) != 13) {
				if (c >= '0' && c <= '9') {
					printf("%c", c);
					dato[i++] = c;
				}
				else if (c == 8 || c == 127) {
					printf("\b \b");
					dato[i--] = 0;
				}
			}
			dato[i] = '\0';
			return atoi(dato);
			
			
		}
		
			
	};
}
