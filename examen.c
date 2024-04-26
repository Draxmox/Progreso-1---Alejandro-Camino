#include <stdio.h>
//Función para calcular los impuestos
float calcular_impuesto(float interes, float tasa_impuesto_anual) {
    return interes * (tasa_impuesto_anual / 100);
}

int main() {
    float monto_mensual, tasa_interes_anual, tasa_impuesto_anual;
    int total_meses;

    printf("Ingrese el monto mensual: ");
    scanf("%f", &monto_mensual);
    printf("Ingrese el total de meses: ");
    scanf("%d", &total_meses);
    printf("Ingrese la tasa de interes: ");
    scanf("%f", &tasa_interes_anual);
    printf("Ingrese la tasa de impuesto a la renta: ");
    scanf("%f", &tasa_impuesto_anual);

    float ahorro_total = 0;
    float interes_total = 0;
    float impuesto_total = 0;

    printf("\nMes\tAhorro\t\tInteres\t\tImpuesto\tAhorro+Interes\n");
    for (int mes = 1; mes <= total_meses; mes++) {
        float interes_mes = (ahorro_total + monto_mensual) * (tasa_interes_anual / 100 / 12);
        float impuesto_mes = calcular_impuesto(interes_mes, tasa_impuesto_anual);
        float ahorro_interes = ahorro_total + interes_mes - impuesto_mes;
        ahorro_total = ahorro_interes + monto_mensual;
        interes_total += interes_mes;
        impuesto_total += impuesto_mes;

        printf("%d\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", mes, ahorro_total, interes_mes, impuesto_mes, ahorro_interes);
    }

    printf("\nTotal:\t%.2f\t\t%.2f\t\t%.2f\t\t%.2f\n", ahorro_total, interes_total, impuesto_total, ahorro_total + interes_total);

    return 0;
}


