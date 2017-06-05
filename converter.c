#include <stdio.h>
#include <math.h>

int main()
{
  // variables
	double Op1       	= 0.0; 	// first operant
	double Erg       	= 0.0; 	// real numbers and result
 	int result 				= 0.0;
 	int hex 					= 0.0;
	int menuChoice   	=   0; 	// menu choice
	int correctEntry 	=   0; 	// check scanf for a correct entry
	char dump;              	// empty buffer
	char stars[] 			= "***********************************";
	char space[] 			= "                                   ";

	do // repeat the loop until 9 was entered
  {
    // display the menu
    printf("%.24s%s", &stars, "\n");
    printf("   Convert your Units\n");
    printf("========================\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. lbs to kg\n");
    printf("4. kg to lbs\n");
    printf("5. Convert value into a hex\n");
    printf("6. Convert hex into decimal\n");
    printf("9. End this program\n");
    printf("%.20s%s", &space, "\n");
    printf("Your choice: ");

    // menu choice
    correctEntry = scanf("%i", &menuChoice);

    do // empty the buffer
    {
      scanf("%c", &dump);
    } while (dump != '\n');

    if (correctEntry) // check if a correct value was entered
    {
      switch(menuChoice)
			{
				case 1:  printf("Celsius to Fahrenheit\n------\n");  break;
				case 2:  printf("Fahrenheit to Celsius\n-------\n"); break;
				case 3:  printf("lbs to kg\n--------\n");            break;
				case 4:  printf("kg to lbs\n---------\n");           break;
      	case 5:  printf("show hex\n--------\n");        		 break;
      	case 6:  printf("hex to decimal\n---------\n");			 break;
        case 9:  printf("Goodbye!\n");                       break;
				default: correctEntry = 0;                           break;
			}
      if (menuChoice != 6 && menuChoice != 9)
      {
        do
        {
          /* code */printf("Please enter your first operant: ");
					correctEntry = scanf("%lf", &Op1); // enter your value
					do
					{
						scanf("%c", &dump); // empty buffer
					}while (dump != '\n'); // unless it is enter

					if (!correctEntry)
					{
						printf("What you have entered is not a natural number.\n");
					}
        } while(!correctEntry);
      }
			else if (menuChoice == 9)
			{
				printf("See ya later!\n");
			}
      else
      {
        do
        {
          printf("Please enter hex value: ");
          correctEntry = scanf("%x", &hex);
          do
          {
            scanf("%c", &dump); // empty buffer
          }while (dump != '\n'); // unless it is enter
					if (!correctEntry)
					{
						printf("What you have entered is not a hex number.\n");
					}
        }while(!correctEntry);
      }
      switch(menuChoice)
      {
        case 1: Erg = (Op1*1.8+32);
          printf("%lf Celsius = %lf Fahrenheit\n", Op1, Erg); break;
        case 2: Erg = (5.0/9.0)*(Op1 - 32);
          printf("%lf Fahrenheit = %lf Celsius\n", Op1, Erg); break;
        case 3: Erg = Op1 * 0.453;
          printf("%lf lbs = %lf kgs\n", Op1, Erg); 						break;
        case 4: Erg = Op1 * 2.2046;
          printf("%lf kg = %lf lbs\n", Op1, Erg); 						break;
        case 5: result = Op1 + 0;
          printf("%lf decimal = %x hex\n", Op1, result); 			break;
        case 6: Op1 = hex;
          printf(" %x hex = %lf decimal\n", hex, Op1);				break;
        case 9:
          printf("You chose to end the program.\n");      		break;
        default:
          printf("What you have entered was not correct, please try again :\n");
      }
    }
    else
		{ //only allow 1, 2, 3, 4 and 9 to be entered in the first menu
			printf("Option not recognised! Please try with 1, 2, 3, 4 or 9 ...\n");
		}
    printf("Please press enter");
		do
		{
			scanf("%c", &dump);
		} while (dump != '\n');
		printf("\n\n");
  } while (menuChoice !=9); // shutdown when 9 is entered

	printf("Program is shutting down.\n");
	return 0;
}
