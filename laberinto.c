#include "laberinto.h"



#define ARR(i,j,k) (labyrinth[lab_dimensions[1]*5*i + 5*j + k])



int lab_dimensions[2];

int *labyrinth;



int main()

{
	char line[255];
	
	load_lab();
	
	//line = 
	generate_top_line();
	printf("%s",line);
	/*line = "";
	line = generate_bottom_line();
	printf("%s",line);*/
	//printf("%s","┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐");

	//load_lab();

    return 0;

}



void load_lab()

{

    char buffer[255];

    char *token;

    FILE *fp;
	extern int *labyrinth;



    if ((fp = fopen("lab1.txt", "r")) == NULL)

    {

        printf("Error! opening file");

        // Program exits if file pointer returns NULL.

        exit(1);         

    }



    // reads text until newline 

    fgets(buffer, sizeof(buffer), fp);

    

    token = strtok(buffer,"%");



	int i,j,k;

	i = 0;

    while( token != NULL)

    {

    	if (i > 1)

    		break;

    	lab_dimensions[i++] = atoi(token);

    }

    

	labyrinth = (int *)malloc(lab_dimensions[0]*lab_dimensions[1]*5*sizeof(int));

	for(i = 0;i<lab_dimensions[0];i++)

	{
		fgets(buffer, sizeof(buffer), fp);

		for(j=0;j<lab_dimensions[1];j++)

		{
			for(k = 0;k<5;k++)
			{
				if (! k)
				{
					if(buffer[j] == 'x')
						ARR(i,j,k) = -1;
					if(buffer[j] == '*')
						ARR(i,j,k) = 0;
					if(buffer[j] == ' ')
						ARR(i,j,k) = 1;
					if(buffer[j] == '/')
						ARR(i,j,k) = 2;
				}
				else
				{
					ARR(i,j,k) = 0;
				}	
				
			}

		}

	}


	//print_lab();
	

    free(labyrinth);

    fclose(fp);

}

void print_lab()
{
	//printf("%s", "┐└ ┴ ┬ ├ ─ ┼ ┘┌"); ^ v > <
	extern int *labyrinth;
	char *linea1;
	char *linea2;
	char *linea_arriba;
	char *linea_abajo;
	int i,j;
	
	linea_arriba = "┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐";
	for(i = 0;i<lab_dimensions[0];i++)

	{
		for(j = 0;j<lab_dimensions[1];j++)
		{
			printf("%d ",ARR(i,j,0));
		}
		//printf(L"%ls\n",L"─");
	}

		

}
	
char *generate_top_line()
{
	char *line[255];
	char *pline = *line;
	int i,j,p;
	memset(line,0,sizeof(line));
	p=0;
	for(i = 0;i<lab_dimensions[0];i++)
	{
		for(j = 0;j<lab_dimensions[1];j++)
		{
			//printf("%slinea i:%d,j:%d\n",*(line),i,j);
			if(j == 0)
			{
				*(pline)=*"┌──────────";
				pline =+ 11;
			}
			else if(j == (lab_dimensions[1])-1)
			{
				*(pline)=*"┬──────────┐";
				pline =+ 12;
			}
			else
			{
				*(pline)=*"┬──────────";
				pline =+ 11;
			}			
		}
	}
	line[p] = 0;
	printf("\n%s\n",line);
	return line;
}

char *generate_bottom_line()
{
	char *line;
	int i,j;
	line = "";
	for(i = 0;i<lab_dimensions[0];i++)
	{
		for(j = 0;j<lab_dimensions[1];j++)
		{
			if(!j)
				strcat(line,"└──────────");
			else if(j == lab_dimensions[1]-1)
				strcat(line,"┴──────────┘");
			else
				strcat(line,"┴──────────");
		}
	}
	return line;
}