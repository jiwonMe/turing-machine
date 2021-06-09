/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief turing machine implementation
 * @version 0.1
 * @date 2021-06-09
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <stdio.h>
#include <string.h>

#define TAPE_LENGTH 1000

char tape[TAPE_LENGTH];
char state[100];
char dir = 1;

char current_state = 'A';
int n;

typedef struct _Agent
{
	char rules[100][5];
} Agent;

Agent agent;

char action(char scanned_sym)
{
	for (int i = 0; i < n; i++)
	{
		if (agent.rules[i][0] == current_state && agent.rules[i][1] == scanned_sym)
		{
			switch (agent.rules[i][4])
			{
			case 'L':
				dir = -1;
				break;
			case 'R':
				dir = 1;
				break;
			case 'N':
				dir = 0;
				break;
			default:
				break;
			}

			current_state = agent.rules[i][3];
			return agent.rules[i][2];
		}
	}
	return scanned_sym;
}

void run(Agent agent, char *tape)
{
	for (char *ptr = tape; ptr < tape + strlen(tape); ptr += dir)
	{
		*ptr = action(*ptr);
		printf("%s\n", tape);
	}
}

int main()
{

	printf("[input tape]\n");
	scanf("%s", tape);

	printf("[number of instructions]\n");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", &agent.rules[i]);
	}

	printf("\n\n");

	run(agent, tape);
}
