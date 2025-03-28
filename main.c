#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#define GOODBYE printf("Obrigado por usar a calculadora! Ate a proxima.\n")

exec_op (uint8_t op)
{
	if (op == 5)
	{
		GOODBYE;
		return 1;
	}
	if (op > 5) return -1;

	double a, b;

	printf("Digite o primeiro numero: ");
	scanf("%lf", &a);
	printf("Digite o segundo numero: ");
	scanf("%lf", &b);

	switch (op)
	{
	case 1:
		printf("Resultado: %lf + %lf = %lf\n", a, b, a + b);
		break;
	case 2:
		printf("Resultado: %lf - %lf = %lf\n", a, b, a - b);
		break;
	case 3:
		printf("Resultado: %lf * %lf = %lf\n", a, b, a * b);
		break;
	case 4:
		if (b == 0.0)
		{
			printf("Resultado: %lf / %lf = ?\n", a, b);
			break;
		}
		printf("Resultado: %lf / %lf = %lf\n", a, b, a / b);
		break;
	}

	return 0;
}

menu_continue (void)
{
	char c;

	printf("Deseja realizar outra operacao? (s/n): ");
	scanf(" %c", &c);

	switch (c)
	{
	case 'S':
	case 's':
		return menu();

	case 'N':
	case 'n':
		GOODBYE;
		return 0;

	default:
			printf("Por favor, responda somente com 's' ou 'n'.\n");
		return menu_continue();
	}
}

menu (void)
{
	uint8_t op;

	printf("===============================\n   Calculadora Simples\n===============================\n");
	printf("Selecione uma operacao:\n1. Adicao\n2. Subtracao\n3. Multiplicacao\n4. Divisao\n5. Sair\n");

	printf("Opcao: ");
	scanf("%hhu", &op);

	switch (exec_op(op))
	{
	case 0: break;
	case 1: return 0;
	case -1: return -1;
	default: return -16;
	}

	return menu_continue();
}

signed main (void)
{
	return menu();
}