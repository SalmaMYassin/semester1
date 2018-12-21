#include <stdio.h>
#include <stdlib.h>


void main()
{
	printf("LOVE TO LALA: ");
	int noWords = 0;
	scanf("%d", &noWords);
	getchar();
	int i,j,k,location;
	int flag = 0 ;
	char words[20][20];
	for (i = 0; i < noWords; i++)
	{
		printf("Please input word No. %d: ", i + 1);
		gets(words[i]);
	}
	printf("\n");

	for (i = 0; i < noWords; i++)
	{
		flag = 0;
		location = _mbstrlen(words[i])-1;
		for (j = 0; j < _mbstrlen(words[i])*2; j++)
		{
			if (flag == 0)
				printf("%*c", location,' ');
			for (k = location; k < _mbstrlen(words[i]); k++)
				printf("%c", words[i][k]);

			if (flag == 0)
			{
				location--;
				if (location == -1)
				{
					location=1;
					flag = 1;
				}

			}
			else
				location++;

			printf("\n");
		}


	}

	system("pause");

}
