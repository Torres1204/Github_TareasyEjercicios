def suma(x, y):
    return x + y

def resta(x, y):
    return x - y

def multiplicacion(x, y):
    return x * y

def division(x, y):
    return x / y

while True:
    print("\n --------------- Calculadora ---------------")
    print("\t -------------")
    print("\t|  Operaciones   |")
    print("\t|----------------|")
    print("\t|     suma       |")
    print("\t|----------------|")
    print("\t|     resta      |")
    print("\t|----------------|")
    print("\t| multiplicacion |")
    print("\t|----------------|")
    print("\t|    division    |")
    print("\t|----------------|")
    print("\t|     salir      |")
    print("\t ----------------")
    opcion = input("\nIngrese la opción deseada: ")

    if opcion == "salir":
        print("\n\tGracias por usar la calculadora")
        break

    if opcion in ("suma", "resta", "multiplicacion", "division"):
        num1 = float(input("\nIntroduzca el primer número: "))
        num2 = float(input("\nIntroduzca el segundo número: "))

        if opcion == "suma":
            print("\nEl resultado es:", suma(num1, num2))
        elif opcion == "resta":
            print("\nEl resultado es:", resta(num1, num2))
        elif opcion == "multiplicacion":
            print("\nEl resultado es:", multiplicacion(num1, num2))
        elif opcion == "division":
            if num2 == 0:
                print("\nNo se puede dividir entre cero.")
            else:
                print("\nEl resultado es:", division(num1, num2))
    else:
        print("\n\tOpción no válida")
