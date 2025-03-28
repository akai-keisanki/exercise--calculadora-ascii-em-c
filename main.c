#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#define GOODBYE printf("Obrigado por usar a calculadora! Até a próxima.\n")
#define ERRO_DE_NUMERO printf("Erro: Por favor, insira um número válido.\n")

exec_op (uint8_t op)
{
	if (op == 5)
	{
		GOODBYE;
		return 1;
	}
	if (op > 5) return -1;

	double a, b;

	printf("Digite o primeiro número: ");
	if (scanf("%lf", &a) != 1)
	{
		ERRO_DE_NUMERO;
		exec_op(op);
	}

	printf("Digite o segundo némero: ");
	
	if (scanf("%lf", &b) != 1)
	{
		ERRO_DE_NUMERO;
		exec_op(op);
	}

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
			printf("Erro: Por favor, não calcular divisões por 0.");
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

	printf("Deseja realizar outra operação? (s/n): ");
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
	printf("Selecione uma operação:\n1. Adição\n2. Subtração\n3. Multiplicação\n4. Divisão\n5. Sair\n");

	printf("Opção: ");
	if (scanf("%hhu", &op) != 1)
	{
		ERRO_DE_NUMERO;
		return menu();
	}

	switch (exec_op(op))
	{
	case 0: break;
	case 1: return 0;

	case -1:
		printf("Erro: Por favor, insira um número entre 1 e 5.\n")
		return menu();

	default: return -16;
	}

	return menu_continue();
}

signed main (void)
{
	return menu();
}