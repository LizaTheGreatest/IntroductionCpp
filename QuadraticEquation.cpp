#include <stdio.h>
#include <math.h>

enum FormulaType {
    FULL_FORMULA = 0,
    AB_FORMULA,
    AC_FORMULA,
    A_FORMULA
};
double safeReadInt(const char*);
void printEquation(double, double, double);
bool ask();
void flush_stdin();
void invalid_A(double*);
FormulaType getType(double, double);
void printFormula(double, double, double, double*, double*);
void full_Formula(double, double, double, double*, double*);
void ab_Formula(double, double, double*, double*);
void ac_Formula(double, double, double*, double*);
void a_Formula(double*, double*);
double discriminant(double, double, double);

int main()
{
    double a, b, c;
    double x1, x2;
    bool answer = true;

    printf("Please, enter coefficients\n ");
    printf("Enter A: ");
    a = safeReadInt("Please, enter number and try again\n");
    while(!a) invalid_A(&a);
    printf("Enter B: ");
    b = safeReadInt("Please, enter number and try again\n");
    printf("Enter C: ");
    c = safeReadInt("Please, enter number and try again\n");


    printEquation(a, b, c);
    answer = ask();


    while(!answer)
    {
        printf("Enter coefficients\n ");
        printf("Enter A: ");
        a = safeReadInt("Please, enter number and try again\n");
        while(!a) invalid_A(&a);
        printf("Enter B: ");
        b = safeReadInt("Please, enter number and try again\n");
        printf("Enter C: ");
        c = safeReadInt("Please, enter number and try again\n");



        printEquation(a, b, c);
        answer = ask();
    }

    printFormula(a, b, c, &x1, &x2);


    return 0;
}


void oneTerm(double k, int &f)
{
    const char* a[] = {"x^2","x",""};
    if(k > 1)
    {
        switch (f)
        {
            case 0: printf("%3.2lf%s", k, a[f++]);
                    break;
            case 1: printf("%+3.2lf%s", k, a[f++]);
                    break;
            case 2: printf("%+3.2lf", k);
                    break;
        default: break;
        }
        return;
    }
    else  if(k == 1)
    {
        switch (f)
        {
            case 0: printf("%s", a[f++]);
            break;
            case 1: printf("+%s", a[f++]);
            break;
            case 2: printf("%+3.2lf", k);
            break;
        }
        return;
    }
    else if(k == -1)
    {
        switch (f)
        {
            case 0: printf("-%s", a[f++]);
            break;
            case 1: printf("-%s", a[f++]);
            break;
            case 2: printf("%+3.2lf", k);
            break;
        }
    }
    else if(k && k != -1 && k < 1)
    {
        switch (f)
        {
            case 0: printf("%3.2lf%s", k, a[f++]);
                    break;
            case 1: printf("%+3.2lf%s", k, a[f++]);
                    break;
            case 2: printf("%+3.2lf", k);
                    break;
        }
        return;
    }
    if(!k)
        f++;
    return;
}

void printEquation(double a, double b, double c)
{
    int f = 0;
    printf("\n\t\tHere your equation:\n\n");
    printf("\t\t");
    oneTerm(a, f);
    oneTerm(b, f);
    oneTerm(c, f);
    printf(" = 0\n\n");

}

bool ask()
{
    char ans = 0;
    do
    {

        printf("Is it correct? Press 'y' for yes, 'n' for no: ");
        ans = getc(stdin);
        flush_stdin();
    }
    while(ans != 'y' && ans != 'n');

    return ans == 'y';
}

void flush_stdin()
{
    char c;
    while ((c = getc(stdin)) != '\n' && c != EOF);
}

void invalid_A(double* a)
{
    if(*a) return;
    printf("Coefficient 'a' can't be zero. It's not square equation. Please, try again.\n");
    printf("Enter a: ");
    *a = safeReadInt("Please, enter number\n");

}

FormulaType getType(double b, double c)
{
    if(b)
    {
        if(c)
            return FULL_FORMULA;
        return AB_FORMULA;
    }
    if(c)
        return AC_FORMULA;
    return  A_FORMULA;
}

void printFormula(double a, double b, double c, double* x1, double* x2)
{
    switch (getType(b, c))
    {
        case FULL_FORMULA: full_Formula(a, b, c, x1, x2);
        break;
        case AB_FORMULA: ab_Formula(a, b, x1, x2);
        break;
        case AC_FORMULA: ac_Formula(a, c, x1, x2);
        break;
        case A_FORMULA: a_Formula(x1, x2);
        break;

    }
}
void full_Formula(double a, double b, double c, double* x1, double* x2)
{

    printf("\tEquation type:\n\t");
    printf("Ax^2 + Bx + C\n\n");

    double D = discriminant(a, b, c);

    if(D)
    {
        if(D < 0)
        {
            printf("\tD = %3.2lf\n", D);
            printf("\tDiscriminant is negative. There're NO roots.\n");
            return;
        }
        *x1 = (-b + sqrt(D)) / (2 * a);
        *x2 = (-b - sqrt(D)) / (2 * a);
        printf("\tD = %3.2lf\n", D);
        printf("\tx1 = (-b + sqrt(D) / (2 * a)\n");
        printf("\tx1 = (-b - sqrt(D) / (2 * a)\n\n");
        printf("\tx1 = %3.2lf\n\tx2 = %3.2lf\n", *x1, *x2);
    }
    else
    {
        *x1 = -b / (2 * a);
        *x2 = *x1;
        printf("\tx1 = x2 = -b / (2 * a)\n");
        printf("\tx1 = %3.2lf\n\tx2 = %3.2lf\n", *x1, *x2);
    }

}

void ab_Formula(double a, double b, double* x1, double* x2)
{
    printf("\tEquation type:\n\t");
    printf("Ax^2 + Bx\n\n");

    printf("\tx(ax + b)\n");
    printf("\tx1 = 0\n\tx2 = -b/a\n\n");

    *x1 = 0;
    *x2 = -b/a;
    printf("\tx1 = %.1lf,\n\tx2 = %3.2lf\n", *x1, *x2);


}

void ac_Formula(double a, double c, double* x1, double* x2)
{
    printf("\tEquation type:\n\t");
    printf("Ax^2 + C\n\n");

    if(-c / a >= 0)
    {
        *x1 = sqrt(-c / a);
        *x2 = -sqrt(-c / a);

    }
    else
    {
        printf("\t -C / A < 0. There're no roots.\n");
        return;
    }

    printf("\tx^2 = c/a\n");
    printf("\tx1 = sqrt(c/a)\nx2 = -sqrt(c/a)\n");
    printf("\tx1 = %3.2lf,\n\tx2 = %3.2lf\n", *x1, *x2);


}

void a_Formula(double* x1, double* x2)
{
    printf("\tEquation type:\n\t");
    printf("Ax^2\n\n");

    *x1 = 0;
    *x2 = 0;
    printf("\tx1 = 0\n\tx2 = 0\n");

}

double discriminant(double a, double b, double c)
{
    return b * b - 4 * a * c;
}

double safeReadInt(const char* text = "Error. Please, enter only numbers and try again\n")
{

    bool ok = false;
    int result;

    do
    {

        ok = scanf("%d", &result) == 1;
        flush_stdin();
        if(!ok)
        {
            printf("%s", text);
        }

    }
    while (!ok);
    return result;

}



