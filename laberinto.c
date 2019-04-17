#include "laberinto.h"

#define ARR(i,j,k) (labyrinth[lab_dimensions[1]*5*i + 5*j + k])

int lab_dimensions[2];

int *labyrinth;
char buffer[255];
char *token;
FILE *fp;
char *path;

int main()

{
   	extern int *labyrinth;
	extern int lab_dimensions[];

	extern char *path;
    extern char buffer[255];
	extern char *token;

    extern FILE *fp;
	

	path = "lab2.txt\0";

    if ((fp = fopen(path, "r")) == NULL)

    {

	printf("Error! opening file");

	// Program exits if file pointer returns NULL.

	exit(1);         

    }

    // reads text until newline 

    fgets(buffer, sizeof(buffer), fp);

    token = strtok(buffer,"%");

	int i,j,p,repeat;

	i = 0;

    while( token != NULL)

    {

    	if (i > 1)

    		break;

    	lab_dimensions[i++] = atoi(token);

    }
	labyrinth = (int *)malloc(lab_dimensions[0]*lab_dimensions[1]*5*sizeof(int));

	load_lab(labyrinth);



	repeat = 1;

	
	ARR(0,0,0) = 69;
	//print_lab_simple();
 	fclose(fp);

	//line = 

	print_lab(labyrinth);

	/*

	printf("x:%d,y:%d\n",lab_dimensions[0],lab_dimensions[1]);

	i = j = 0;

	for(i=0;i<10;i++);

	{

		printf("i:%d/n",i);

		for(j = 0;j<10;j++);

		{

			printf("%s i:%d j:%d ","│",i,j);

				

						

		}

		printf("%s\n","│");

		

	}

	for(i=0;i<lab_dimensions[0];i++)

	{

		for(j=0;j<lab_dimensions[1];j++)

		{

			printf("%s i:%d j:%d ","│",i,j);

		}

	}

	/*line = "";

	line = generate_bottom_line();

	printf("%s",line);*/

	//printf("%s","┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐");

	//load_lab();

    return 0;

}



void load_lab(int *labyrinth)

{

    
	extern int lab_dimensions[];

	extern char *path;
    extern char buffer[255];
	extern char *token;

    extern FILE *fp;





    if ((fp = fopen(path, "r")) == NULL)

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

    

	for(i = 0;i<lab_dimensions[0];i++)

	{
		memset(buffer,0,sizeof(buffer));

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

					if(buffer[j] == ' ' || buffer[j] == 10 || buffer[j] == 13 || buffer[j] == 0)

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



		//print_lab()
		print_lab_simple();

	

    

    fclose(fp);

}

/*

void print_lab()

{

	//printf("%s", "┐└  ┘┴ ┬ ├ ─ ┼┌"); ^ v > <

	extern int *labyrinth;

	char *linea1;

	char *linea2;

	char *linea_arriba;

	char *linea_abajo;

	int i,j;

	

	linea_arriba = "

			┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐

			│**********│          │          │          │          │          │          │          │          │          │

			│          │          │          │          │          │          │          │          │          │ 23^   17>│

			│          │          │          │          │          │          │          │          │          │ 32v   74<│

			│          │          │          │          │          │          │          │          │          │          │

			├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤

			│          │          │          │          │          │          │          │          │          │          │

			│          │          │          │          │          │          │          │          │          │          │

	for(i = 0;i<lab_dimensions[0];i++)

	{

		for(j = 0;j<lab_dimensions[1];j++)

		{

			printf("%d ",ARR(i,j,0));

		}

		//printf(L"%ls\n",L"─");

	}

		

}*/

	

void print_lab(int *labyrinth)

{

	extern int lab_dimensions[];

	//extern int *labyrinth;

	int i,j,p,repeat;

	char *one_space=" ";

	char *two_spaces="  ";

	char *linea_divisora;

	for(j = 0;j<lab_dimensions[1];j++)
	{
		//printf("%slinea i:%d,j:%d\n",*(line),i,j);└  ┘┴ 
		if(j == 0)
		{
			printf("%s","┌──────────");
		}
		else if(j == (lab_dimensions[1])-1)
		{
			printf("%s\n","┬──────────┐");
		}
		else
		{
			printf("%s","┬──────────");
		}	
	}


    //printf("%s","┌──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┬──────────┐");
    //10 por campo + 2 + 1 por campo-1
    linea_divisora = (char *)malloc(3*sizeof(char) + lab_dimensions[1]*10*sizeof(char) + (lab_dimensions[1]-1)*sizeof(char));
    
    memset(linea_divisora,'\0',sizeof(linea_divisora));
	repeat = 1;
    
    for(j = 0;j<lab_dimensions[1];j++)
	{
		//printf("%slinea i:%d,j:%d\n",*(line),i,j);└  ┘┴ "┐└  ┘┴ ┬ ├ ─ ┼┌ 
		if(j == 0)
		{
			strcat(linea_divisora,"├──────────");
		}
		else if(j == (lab_dimensions[1])-1)
		{
			strcat(linea_divisora,"┼──────────┤");
		}
		else
		{
			strcat(linea_divisora,"┼──────────");
		}	
	}

    

	for(i=0;i<lab_dimensions[0];i++)

	{
		if(i && repeat)
		{
			printf("%s\n",linea_divisora);
		}

		for(j=0;j<lab_dimensions[1];j++)

		{
            printf("%s","|");

			if( repeat == 1)

			{

				if( ARR(i,j,0) == 0)

				{

					printf("%s","**********");

				}

				else 

				{

					if(ARR(i,j,1) > 9 && ARR(i,j,2) > 9)

					{

						printf(" %d^  %dv ",ARR(i,j,1),ARR(i,j,2));

					}

					else if(ARR(i,j,1) > 9)

					{

						printf(" %d^   %dv ",ARR(i,j,1),ARR(i,j,2));

					}

					else if(ARR(i,j,2) > 9)

					{

						printf("  %d^  %dv ",ARR(i,j,1),ARR(i,j,2));

					}

					else

					{

						printf("  %d^   %dv ",ARR(i,j,1),ARR(i,j,2));

					}

					

				}

			}

			else

			{

				if( !ARR(i,j,0) )

				{

					printf("%s","**********");

				}

				else 

				{

					if(ARR(i,j,3) > 9 && ARR(i,j,4) > 9)

					{

						printf(" %d^  %dv ",ARR(i,j,3),ARR(i,j,4));

					}

					else if(ARR(i,j,3) > 9)

					{

						printf(" %d^   %dv ",ARR(i,j,3),ARR(i,j,4));

					}

					else if(ARR(i,j,4) > 9)

					{

						printf("  %d^  %dv ",ARR(i,j,3),ARR(i,j,4));

					}

					else

					{

						printf("  %d^   %dv ",ARR(i,j,3),ARR(i,j,4));

					}


				}

			}

		}
		if(repeat == 1)
		{	i--;
			repeat = 0;
		}
		else
		{
			repeat = 1;
		}

		printf("%s\n","│");

	}

	for(j=0;j<lab_dimensions[1];j++)

	{

		if(j == 0)

		{

			printf("%s","└──────────");

		}

		else if(j == (lab_dimensions[1])-1)

		{

			printf("%s","┴──────────┘");

		}

		else

		{

			printf("%s","┴──────────");

		}			

	}

	

	printf("%s","\n");

}


void print_lab_simple()

{

	int i,j;

	for(i = 0;i<lab_dimensions[0];i++)

	{



		for(j = 0;j<lab_dimensions[1];j++)

		{

//			printf("T:%d, d1:%d, d2:%d, d3:%d, d4:%d  |", ARR(i,j,0), ARR(i,j,1), ARR(i,j,2), ARR(i,j,3), ARR(i,j,4));

			printf("T:%d  |", ARR(i,j,0));						

		}

		printf("%s\n","");

		

	}

}

int laberinto_valido()
{
	extern char buffer[255];
	extern char *token;

    extern FILE *fp;

	extern char *path;
	
	int i,j,k,start,finals,walls,spaces;


    if ((fp = fopen(path, "r")) == NULL)

    {

		printf("Error! opening file");

		// Program exits if file pointer returns NULL.

		exit(1);         

    }



    // reads text until newline 

    fgets(buffer, sizeof(buffer), fp);

    

    token = strtok(buffer,"%");



	

	i = 0;

    while( (token = strtok( NULL, "%")) != NULL ) 

    {

    	if (i > 1)

    		break;

    	lab_dimensions[i++] = atoi(token);

    }

	start = finals = walls = spaces = 0;
	for(i = 0;i<lab_dimensions[0];i++)

	{

		fgets(buffer, sizeof(buffer), fp);

		for(j=0;j<lab_dimensions[1];j++)

		{

			

		}

	}
}




