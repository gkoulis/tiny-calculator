#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define ARRAYLENGTH 200

typedef struct {
    char type[ARRAYLENGTH];
    char name[ARRAYLENGTH];
    char value[ARRAYLENGTH];
}variables;

int size_var=0;
int limit_var=2;
variables *var;

typedef struct {
    char type[ARRAYLENGTH];
    char name[ARRAYLENGTH];
    char value[ARRAYLENGTH];
}temporary;

int size_tmp=0;
int limit_tmp=1;
temporary *tmp;

typedef struct {
    char action[ARRAYLENGTH];
    char name1[ARRAYLENGTH];
    char name2[ARRAYLENGTH];
}operation;

int size_ope;
int limit_ope=1;
operation *ope;

/* F U N C T I O N S */
void MainMenu(); //Main Menu of Program.
void RouteProgram(); //Routes the program's flow.
void ManualFunction(); //A function with some information about how to use program.
void AboutFunction(); //Some things about programmer.
void CommandsList(); //List with commands.
void ShowExamples(); //Examples for each case.
void ShowHelp(); //Help center. (some tips for better experience).
void ShowReservedWords(); //List with all the reserved words.
void ClearScreen(); //Clear screen.
void ShowVariablesInScreen(); //Show declared variables.
void InstructionsVariablesStatement(); //(Instructions) Screen - Variables Statement.
int UsersInput1(); //Input from user. Variable statement.
int ScreenFunctions(); //Print screen functions.
int CheckUsersInput1(); //Check user's input.
void SaveToStruct(); //If variable is correct, save to struct.
int DeleteVariable(int option); //Delete the variable which user will choose.
void arraydoubleVAR(); //Double size of variables struct.
void InstructionsOperations(); //Intructions - how to. (Operation stage).
int UsersInput2(); //Input from user. Operation's stage.
int ScreenFunctions2(); //Screen functions during operations
int CheckUsersInput2(); //Check for user's input. Operation's stage.
void RecognizeOperation(); //Route the program to user's choice (to right operation).
void TemporaryStructInitialization(); //Initialization temporaRY struct.

/* O P E R A T I O N S */
void OperationADD(); //Operation add.
void OperationSUBTRACT(); //Operation subtract.
void OperationMULTIPLE(); //Operation multiple.
void OperationDIVIDE(); //Operation divide.
void OperationEQUAL(); //Operation equal.
void OperationASSIGN(); ////Operation assign.

int main()
{
    var=(variables*)malloc(limit_var*sizeof(variables));
    tmp=(temporary*)malloc(limit_tmp*sizeof(temporary));
    
    MainMenu(); //Main Menu of Program.
    
    free(tmp);
    free(var);
    
    return 0; //End of program.
} //End of MAIN.

void MainMenu() //The menu of the program.
{
    int selection=0; //Start, Manual, About, Exit have a number. This number called selection.
    int input=0; //User's input.
    
    while(true) { //until user select exit ('break' in code).
                
        system("cls"); //Clear screen.
 
        //How the menu will shown up.
        if(selection==0) {
            printf("> Start \n  Manual \n  About \n  Exit \n\n");
        }
        else if(selection==1) {
            printf("  Start \n> Manual \n  About \n  Exit \n\n");
        }
        else if(selection==2) {
            printf("  Start \n  Manual \n> About \n  Exit \n\n");
        }
        else if(selection==3) {
            printf("  Start \n  Manual \n  About \n> Exit \n\n");
        }
    
        input = _getch(); //input from user (UP, DOWN, ENTER).
    
        if(input==13) {
        
            if(selection==0) {
            
                system("cls"); //Clear screen.
            
                RouteProgram(); //Go to function Start Function. In this point the program starts.
        
            }   
            else if(selection==1) {
             
                system("cls"); //Clear screen.
            
                ManualFunction(); //Go to function Manual.
        
            }
            else if(selection==2) {
        
                system("cls"); //Clear screen.
            
                AboutFunction(); //Go to function About.
        
            }
            else {
        
                break; //Finish the program.
            
            }
                    
        } //End of IF.
        else if(input==224) {
    
            input=_getch();
        
            if(input==72 && selection==3) {
                selection--; //Arrow Up.
            }
            else if(input==72 && selection==2) {
                selection--; //Arrow Up.
            }
            else if(input==72 && selection==1) {
                selection--; //Arrow Up.
            }
            else if(input==80 && selection==0) {
                selection++; //Arrow Down.
            }
            else if(input==80 && selection==1) {
                selection++; //Arrow Down.
            }
            else if(input==80 && selection==2) {
                selection++; //Arrow Down.
            }
        
        } //End of else.
    
        fflush(stdin); //Clear bad data.
    
    } //End of WHILE.
    
} //End of Main Menu.

void RouteProgram()
{
    int decision;
    int decision2;
    
    pointB:
           
    InstructionsVariablesStatement(); //Intructions for variables statement.
    
    decision=UsersInput1(); //Input from user. Variable statement.
    
    if(decision==0) {
    
        ope=(operation*)malloc(limit_ope*sizeof(operation));
        
        InstructionsOperations(); //Intructions for operations.
        decision2=UsersInput2(); //Input from user. Operations.
        
        free(ope);
        
        if(decision2==1) {
            
            goto pointB;
        }
        
    } //End of OF.
    
} //End of Route Program.

void ManualFunction() //Some things about how to use the program.
{
    printf("\n");

    printf(" Manual\n\n\n");
    printf(" Variables' declaration :\n\n\n");
    printf(" Type and Value\n\n");
    printf("-Integer\n Positive and negative integer numbers.\n\n");
    printf("-Decimal\n Positive and negative decimal numbers.\n\n");
    printf("-Boolean\n A boolean variable's value can be 'true' or 'false'.\n\n");
    printf("-String\n Characters, digits and punctuation.\n\n");
    printf(" Name\n\n");
    printf(" It is not permitted the first character to be digit.\n");
    printf(" It is not permitted to use reserved words as a variable's name.\n");
    printf(" Type the word 'reserved' to see reserved words.\n\n\n");
    printf(" Permitted arithmetic actions :\n\n\n");
    printf("-Add : This act is allowed for all the variables' types. \n You can add two integer or decimal numbers. \n Use if variables are Boolean: Logical AND. \n Use if variables are Strings. The program will type in line \n the two variables (as Strings).\n\n");
    printf("-Subtract : This act is allowed only for Integer and Decimal types.\n You can subtract two integer of decimal numbers.\n\n");
    printf("-Multiple : This act is allowed only for Integer and Decimal types.\n Exception: If the type of the fisrt variable is Integer and the type of \n second variable is String, the program will return the \n second string as times as the value of \n the first variable.\n\n");
    printf("-Divide : This act is allowed only for Integer and Decimal types.\n You can divide two integer or decimal numbers.\n\n");
    printf("-Equal : Check for equal variables. Equal variables are variables which\n have the same type and the same value.\n This action returns 'true' or 'false'.\n\n");
    printf("-Assign : This action instructs the type and value\n of the second variable in the first.\n This action is permitted for ever variable type.\n\n\n");
    printf(" User's input is case sensitive.\n\n\n");
    printf(" Every time program asks user for input, user can type the word 'commands'\n to see all the command supported by program.\n");
    
    printf("\nPress any key to continue. . .\n");
    system("PAUSE");
    
    printf("\n");
    
    return;
} //End of function Manual.

void AboutFunction() //Information about programmer.
{
    printf("Harokopio University of Athens\n");
    printf("Department of Informatics and Telematics\n");
    printf("Academic year: 2012-2013\n");
    printf("Academic course: Programming I\n");
    printf("1st Project\n");
    printf("Programmer: Gkoulis Dimitrios\n");
    printf("SN: 21204\neMail: gkould@gmail.com\n");
    printf("\n");
    
    printf("Press any key to continue. . .\n");
    system("PAUSE");
    
    return;
} //End of function About.

void InstructionsVariablesStatement() 
{
    system("cls"); //Clear screen.
    
    printf("Variable Declaration\n\n");
    printf("Type type, name and value of the variables.\n\n");
    printf("Types: \t Integer\tDecimal\n\n\t String \tBoolean\n\n");
    printf("Type the word 'example' to see an example.\n\n");
    printf("Type the word 'done' to continue to operations' stage.\n\n");
    printf("Type the word 'exit' to return at main menu.\n\n");
} //End of Instructions. (Variables statement).

void CommandsList()
{
    printf("\n");
    
    printf(" 'done' - when user finishes with input\n");
    printf(" 'exit' - return to main menu\n");
    printf(" 'clear' - clear screen\n");
    printf(" 'example' - example for each case\n");
    printf(" 'help' - tips for better experience using this program\n");
    printf(" 'reserved' - show the list with reserved words\n");
    printf(" 'manual' - show program's manual\n");
    printf(" 'delete' - if user press delete, program will ask user\n\t    the name of variable to be deleted.\n");
    printf(" 'variables' - show user's declared variables\n");
    printf(" 'commands' - show list with commands\n");
    printf(" 'declar' or 'return' - operations' stage only - return to variables' declaration\n");
    printf(" 'inst' - intructions for each case (Variables' declaration stage and Operations' stage)\n");
    
    
    printf("\n");
    
    return; //end of function.
    
} //End of command list.

void ShowExamples()
{
    printf("\n");
    
    printf("Variables' declaration examples\n\n\n");
    printf("structure: type|name|value (|=space)\n");
    printf("Examples: \ninteger i 65\ndecimal j 65.423\nboolean state true\nstring c dimitris\n\n\n");
    printf("Operations examples\n\n\n");
    printf("structure: action|name1|name2 (|=space)\n");
    printf("Examples: \nadd i j : (i+j)\nsubtract j i : (j-i)\nmultimple a b : (a*b)\ndivide b a : (b/a)\nequal state1 state2 : true if (state1==state2) | false if (state1 != state2)\nassign a b : (a<-b)\n");
    printf("Special cases: (see manual)\n");
    
    printf("\n");
    
    return; //End of function.
    
} //End of examples.

void ShowHelp()
{
    printf("\n");
    
    printf("Help center\n\n\n");
    printf("Variables' declaration stage\n\n\n");
    printf("Type name, enter space, type name, enter space, type value, enter space.\n\n");
    printf("Do not use many 'white' spaces.\n\n");
    printf("In decimal numbers use '.'! No ','!\n\n");
    printf("Except 'integer' user can type 'int'.\n\n");
    printf("Except 'decimal' user can type 'dec'.\n\n");
    printf("Except 'boolean' user can type 'boo'.\n\n");
    printf("Except 'string' user can type 'str'.\n\n");
    printf("If user type 'exit' will go to main menu.\nThe variables which user typed are saved.\nIf user choose 'start' from main menu,\nuser will continue from the point which left before.\n");
    printf("Operations' stage\n\n\n");
    printf("If user type 'done' the result will show up.\n");
    printf("If user type 'exit' program will be finished.\n");
    
    printf("\n");
    
    return; //End of function.
    
} //End of help.

void ShowReservedWords()
{
    printf("\n");
    
    printf("Reserved words\n\n\n");
    printf("integer\nint\ndecimal\ndec\nboolean\nboo\nstring\nstr\nadd\nsubtract\nsub\nmultimple\nmul\ndivide\ndiv\nequal\nequ\nassign\nass\ntrue\nfalse\ndone\nexit\nclear\nexample\nhelp\nmanual\nreserved\ndelete\nvariable\nvariables\ncommands\n");
    
    printf("\n");
    
    return;//End of function.
    
} //End of list with reserved words.

void ShowVariablesInScreen()
{
    printf("\n");
    
    int i;
    
    if(size_var==0) {
        printf("No variable is declared yet.\n");
    }
    else {
         
        for(i=0 ; i<size_var ; i++) {
    
            printf("Variable %d: | Type: %s | Name: %s | Value: %s |\n", i+1, var[i].type, var[i].name, var[i].value);
        
        } //End of FOR.
    
    } //End of ELSE.
    
    printf("\n");
    
    return; //End of function.
    
} //End of print in screen variabLES.

void ClearScreen()
{
    system("cls");
    
    return;
}//End of clear screen.

int UsersInput1()
{   
    fflush(stdin);
    
    int decision; //Decide if variable will be saved. (true-0 | false-1).
    int decisionFromScreenFunction; //Decide if variable will be saved. (true-0 | false-1). (string case).
    
    pointA:
           
    while(true) {
        
        TemporaryStructInitialization();   
        printf("Variable %d: ", size_var+1);
        scanf("%s", tmp[size_tmp].type);

        decisionFromScreenFunction=ScreenFunctions();
        
        if(decisionFromScreenFunction==0) {
            goto pointA;
        }

        if( (tmp[size_tmp].type[0]=='e') && (tmp[size_tmp].type[1]=='x') && (tmp[size_tmp].type[2]=='i') && (tmp[size_tmp].type[3]=='t') && (tmp[size_tmp].type[4]=='\0') ) {
            return 1;
        } //If true go to main menu.
        
        if( (tmp[size_tmp].type[0]=='d') && (tmp[size_tmp].type[1]=='o') && (tmp[size_tmp].type[2]=='n') && (tmp[size_tmp].type[3]=='e') && (tmp[size_tmp].type[4]=='\0') ) {
            
            if(size_var==0) {
                printf("No variable is declared.\n");
                printf("\n");
                goto pointA;
            }
            else if(size_var==1) {
                printf("Only one variable is declared.\n");
                printf("\n");
                goto pointA;
            }
            else {

                return 0;

            }
            
        } //If true go to main menu.

        if(decisionFromScreenFunction==2) {
                                          
            scanf("%s%s", tmp[size_tmp].name, tmp[size_tmp].value);
            
        }
        else if(decisionFromScreenFunction==1) {
            
            
            scanf("%s", tmp[size_tmp].name);
            
            gets(tmp[size_tmp].value);
            
            decisionFromScreenFunction=2;
            
        }

        decision=CheckUsersInput1();
        
        //Decide if variable will be saved to struct.
        if( (decision==0) && (decisionFromScreenFunction==2) ) { 
            
            SaveToStruct();
            
        }

    } //End of WHILE.
    
} //End of user's input. (Variables Statement).

int ScreenFunctions()
{
    int test[11];
    int test2;
    
    char table_example[]={'e', 'x', 'a', 'm', 'p', 'l', 'e', '\0'};
    char table_help[]={'h', 'e', 'l', 'p', '\0'};
    char table_manual[]={'m', 'a', 'n', 'u', 'a', 'l', '\0'};
    char table_reserved[]={'r', 'e', 's', 'e', 'r', 'v', 'e', 'd', '\0'};
    char table_exit[]={'e', 'x', 'i', 't', '\0'};
    char table_done[]={'d', 'o', 'n', 'e', '\0'};
    char table_delete[]={'d', 'e', 'l', 'e', 't', 'e', '\0'};
    char table_commands[]={'c', 'o', 'm', 'm', 'a', 'n', 'd', 's', '\0'};
    char table_variables[]={'v', 'a', 'r', 'i', 'a', 'b', 'l', 'e', 's', '\0'};
    char table_variable[]={'v', 'a', 'r', 'i', 'a', 'b', 'l', 'e', '\0'};
    char table_string[]={'s', 't', 'r', 'i', 'n', 'g', '\0'};
    char table_string_3[]={'s', 't', 'r', '\0'};
    char table_clear[]={'c', 'l', 'e', 'a', 'r', '\0'};
    char table_instructions[]={'i', 'n', 's', 't', '\0'};
    
    test[0]=strncmp(tmp[size_tmp].type, table_example, 8);
    test[1]=strncmp(tmp[size_tmp].type, table_help, 5);
    test[2]=strncmp(tmp[size_tmp].type, table_manual, 7);
    test[3]=strncmp(tmp[size_tmp].type, table_reserved, 9);
    test[4]=strncmp(tmp[size_tmp].type, table_commands, 9);
    test[5]=strncmp(tmp[size_tmp].type, table_delete, 7);
    test[6]=strncmp(tmp[size_tmp].type, table_variables, 10);
    test[7]=strncmp(tmp[size_tmp].type, table_clear, 5);
    test[8]=strncmp(tmp[size_tmp].type, table_string, 7);
    test[9]=strncmp(tmp[size_tmp].type, table_string_3, 4);
    test[10]=strncmp(tmp[size_tmp].type, table_instructions, 5);
    
    if(test[0]==0) {
        ShowExamples();
        return 0;
    }
    
    if(test[1]==0) {
        ShowHelp();
        return 0;
    }
    
    if(test[2]==0) {
        ManualFunction();
        return 0;
    }
    
    if(test[3]==0) {
        ShowReservedWords();
        return 0;
    }
    
    if(test[4]==0) {
        CommandsList();
        return 0;
    }
    
    if(test[5]==0) {
        test2=DeleteVariable(1);
        
        //Check if it's ok to continue to variables declaration.
        if( (test2==2) || (test2==3) ) {
            return 0;
        } //End of IF.
    }
    
    if(test[6]==0) {
        ShowVariablesInScreen();
        return 0;
    }
    
    if(test[7]==0) {
        ClearScreen();
        return 0;
    }
    
    if( (test[8]==0) || (test[9]==0) ) {
        return 1; //Means string. 
    }
    
    if(test[10]==0) {
        InstructionsVariablesStatement();
        return 0;
    }
    
    return 2;
    
} //End of screen functions.

int CheckUsersInput1()
{
    int errors=0; //If errors - 0 the program will continue.
    int test_table[34]={1};
    int i; //Simple loop counter.
    int counter_for_type=0; //Will need in type's check. (correct syntax).
    
    //Reserved words.
    
    char table_integer[]={'i', 'n', 't', 'e', 'g', 'e', 'r', '\0'};
    char table_decimal[]={'d', 'e', 'c', 'i', 'm', 'a', 'l', '\0'};
    char table_string[]={'s', 't', 'r', 'i', 'n', 'g', '\0'};
    char table_boolean[]={'b', 'o', 'o', 'l', 'e', 'a', 'n', '\0'};
    
    char table_integer_3[]={'i', 'n', 't', '\0'};
    char table_decimal_3[]={'d', 'e', 'c', '\0'};
    char table_string_3[]={'s', 't', 'r', '\0'};
    char table_boolean_3[]={'b', 'o', 'o', '\0'};
    
    char table_add[]={'a', 'd', 'd', '\0'};
    char table_subtract[]={'s', 'u', 'b', 't', 'r', 'a', 'c', 't', '\0'};
    char table_multiple[]={'m', 'u', 'l', 't', 'i', 'p', 'l', 'e', '\0'};
    char table_divide[]={'d', 'i', 'v', 'i', 'd', 'e', '\0'};
    char table_equal[]={'e', 'q', 'u', 'a', 'l', '\0'};
    char table_assign[]={'a', 's', 's', 'i', 'g', 'n', '\0'};
    
    char table_subtract_3[]={'s', 'u', 'b', '\0'};
    char table_multiple_3[]={'m', 'u', 'l', '\0'};
    char table_divide_3[]={'d', 'i', 'v', '\0'};
    char table_equal_3[]={'e', 'q', 'u', '\0'};
    char table_assign_3[]={'a', 's', 's', '\0'};
    
    char table_true[]={'t', 'r', 'u', 'e', '\0'};
    char table_false[]={'f', 'a', 'l', 's', 'e', '\0'};

    char table_example[]={'e', 'x', 'a', 'm', 'p', 'l', 'e', '\0'};
    char table_help[]={'h', 'e', 'l', 'p', '\0'};
    char table_manual[]={'m', 'a', 'n', 'u', 'a', 'l', '\0'};
    char table_reserved[]={'r', 'e', 's', 'e', 'r', 'v', 'e', 'd', '\0'};
    char table_exit[]={'e', 'x', 'i', 't', '\0'};
    char table_done[]={'d', 'o', 'n', 'e', '\0'};
    char table_delete[]={'d', 'e', 'l', 'e', 't', 'e', '\0'};
    char table_commands[]={'c', 'o', 'm', 'm', 'a', 'n', 'd', 's', '\0'};
    char table_variables[]={'v', 'a', 'r', 'i', 'a', 'b', 'l', 'e', 's', '\0'};
    char table_variable[]={'v', 'a', 'r', 'i', 'a', 'b', 'l', 'e', '\0'};
    char table_instructions[]={'i', 'n', 's', 't', '\0'};
    char table_declar[]={'d', 'e', 'c', 'l', 'a', 'r', '\0'};
    char table_return[]={'r', 'e', 't', 'u', 'r', 'n', '\0'};
    
    
    //Check if name exist.
    if(size_var>0) {
        
        for(i=0 ; i<size_var ; i++) {
            
            if( strcmp(tmp[size_tmp].name, var[i].name)==0 ) {
                errors++;
                printf("Error: the name you typed is bound by another variable.\n");
                printf("\n");
                break;
            } //End of IF.
            
        } //End of FOR.
        
    } //End of IF.
    
    //Check if 1st character's name is digit.
    if( isdigit(tmp[size_tmp].name[0]) ) {
        errors++;
        printf("Syntax Error: first character of name is number.\n");
        printf("\n");
    }
    
    //Check if name is reserved word.
    test_table[0]=strncmp(tmp[size_tmp].name, table_integer, 8);
    test_table[1]=strncmp(tmp[size_tmp].name, table_decimal, 8);
    test_table[2]=strncmp(tmp[size_tmp].name, table_string, 7);
    test_table[3]=strncmp(tmp[size_tmp].name, table_boolean, 8);
    test_table[4]=strncmp(tmp[size_tmp].name, table_integer_3, 4);
    test_table[5]=strncmp(tmp[size_tmp].name, table_decimal_3, 4);
    test_table[6]=strncmp(tmp[size_tmp].name, table_string_3, 4);
    test_table[7]=strncmp(tmp[size_tmp].name, table_boolean_3, 4);
    test_table[8]=strncmp(tmp[size_tmp].name, table_add, 4);
    test_table[9]=strncmp(tmp[size_tmp].name, table_subtract, 9);
    test_table[10]=strncmp(tmp[size_tmp].name, table_multiple, 9);
    test_table[11]=strncmp(tmp[size_tmp].name, table_divide, 7);
    test_table[12]=strncmp(tmp[size_tmp].name, table_equal, 6);
    test_table[13]=strncmp(tmp[size_tmp].name, table_assign, 7);
    test_table[14]=strncmp(tmp[size_tmp].name, table_subtract_3, 4);
    test_table[15]=strncmp(tmp[size_tmp].name, table_multiple_3, 4);
    test_table[16]=strncmp(tmp[size_tmp].name, table_divide_3, 4);
    test_table[17]=strncmp(tmp[size_tmp].name, table_equal_3, 4);
    test_table[18]=strncmp(tmp[size_tmp].name, table_assign_3, 4);
    test_table[19]=strncmp(tmp[size_tmp].name, table_true, 5);
    test_table[20]=strncmp(tmp[size_tmp].name, table_false, 6);
    test_table[21]=strncmp(tmp[size_tmp].name, table_example, 8);
    test_table[22]=strncmp(tmp[size_tmp].name, table_help, 5);
    test_table[23]=strncmp(tmp[size_tmp].name, table_manual, 7);
    test_table[24]=strncmp(tmp[size_tmp].name, table_reserved, 9);
    test_table[25]=strncmp(tmp[size_tmp].name, table_exit, 5);
    test_table[26]=strncmp(tmp[size_tmp].name, table_done, 5);
    test_table[27]=strncmp(tmp[size_tmp].name, table_delete, 7);
    test_table[28]=strncmp(tmp[size_tmp].name, table_commands, 9);
    test_table[29]=strncmp(tmp[size_tmp].name, table_variables, 10);
    test_table[30]=strncmp(tmp[size_tmp].name, table_variable, 9);
    test_table[31]=strncmp(tmp[size_tmp].name, table_instructions, 5);
    test_table[32]=strncmp(tmp[size_tmp].name, table_declar, 7);
    test_table[33]=strncmp(tmp[size_tmp].name, table_return, 7);
    
    
    for(i=0 ; i<34 ; i++) {
    
        if(test_table[i]==0) {
            
            printf("Syntax Error: entered a reserved word as name.\n");
            printf("Type 'reserved' to see list of reserved words.\n");
            printf("\n");
            errors++;
            break;
        }
    } //End of FOR.
    
    //Table's initialization.
    for(i=0 ; i<8 ; i++) {
        
        test_table[i]=1;
        
    } //End of FOR.
    
    
    //Check for correct or incorrect type.
    test_table[0]=strncmp(tmp[size_tmp].type, table_integer, 8);
    test_table[1]=strncmp(tmp[size_tmp].type, table_decimal, 8);
    test_table[2]=strncmp(tmp[size_tmp].type, table_string, 7);
    test_table[3]=strncmp(tmp[size_tmp].type, table_boolean, 8);
    test_table[4]=strncmp(tmp[size_tmp].type, table_integer_3, 4);
    test_table[5]=strncmp(tmp[size_tmp].type, table_decimal_3, 4);
    test_table[6]=strncmp(tmp[size_tmp].type, table_string_3, 4);
    test_table[7]=strncmp(tmp[size_tmp].type, table_boolean_3, 4);
    
    for(i=0 ; i<8 ; i++) {
        
        if(test_table[i]==0) {
            counter_for_type++;
            break;
        }
    } //End of FOR.
    
    if(counter_for_type==0) {
        
        printf("Syntax Error: incorrect type.\n");
        printf("\n");
        errors++;
    } //End of IF.
    
    //Table's initialization.
    for(i=0 ; i<4 ; i++) {
        
        test_table[i]=1;
        
    } //End of FOR.
    
    //Check for boolean's value.
    test_table[0]=strncmp(tmp[size_tmp].type, table_boolean, 8);
    test_table[1]=strncmp(tmp[size_tmp].type, table_boolean_3, 4);
    
    if( (test_table[0]==0) || (test_table[1]==0) ) {
    
        test_table[2]=strncmp(tmp[size_tmp].value, table_true, 5);
        test_table[3]=strncmp(tmp[size_tmp].value, table_false, 4);
        
        if( (test_table[2]!=0) && (test_table[3]!=0) ) {
            
            printf("Syntax Error: incorrect boolean's value.\n");
            printf("A boolean variable can be 'true' of 'false'.\n");
            printf("\n");
            errors++;
            
        } //End of IF.
        
     } //End of IF.
    
    //Table's initialization.
 
    test_table[0]=1;
    test_table[1]=1;
    test_table[2]=0;
    test_table[3]=0;
    test_table[4]=0;
    
    //Check for integers's value.
    test_table[0]=strncmp(tmp[size_tmp].type, table_integer, 8);
    test_table[1]=strncmp(tmp[size_tmp].type, table_integer_3, 4);
    
    if( (test_table[0]==0) || (test_table[1]==0) ) {
    
        for(i=0 ; i<ARRAYLENGTH ; i++) {
            
            if(tmp[size_tmp].value[i] == '\0') {
                break;
            }
            
            if( isdigit(tmp[size_tmp].value[i]) ) {
                
                test_table[2]++; //Count numbers.
                
            } //End of IF.
            
            if( ( (tmp[size_tmp].value[i] >= 'a') && (tmp[size_tmp].value[i] <= 'z') ) || ( (tmp[size_tmp].value[i] >= 'A') && (tmp[size_tmp].value[i] <= 'Z') ) ) {
        
                test_table[3]++;
                
            } //End of IF.
            
            if( ispunct(tmp[size_tmp].value[i]) ) {
            
                if( (tmp[size_tmp].value[i]=='.') ) {
                
                    test_table[4]++; //Count . or ,
                    
                } //End of IF.
                else {
                    
                    test_table[3]++;
    
                } //End of ELSE.
            } //End of IF.
            
        } //End of FOR.
        
    } //End of IF.
    
    if(test_table[3]!=0) {
        
        errors++;
        printf("Syntax Error: incorrect integer's value.\n");
        printf("You typed string.\n");
        printf("\n");
    } //End of IF.
    
    if( (test_table[3]==0) && (test_table[2]!=0) && (test_table[4]==1) ) {
        
        errors++;
        printf("Syntax Error: incorrect integer's value.\n");
        printf("You typed decimal number.\n");
        printf("\n");
    } //End of IF.
    
    //Table's initialization.
    
    test_table[0]=1;
    test_table[1]=1;
    test_table[2]=0;
    test_table[3]=0;
    test_table[4]=0;
    
    //Check for decimal's value.
    test_table[0]=strncmp(tmp[size_tmp].type, table_decimal, 8);
    test_table[1]=strncmp(tmp[size_tmp].type, table_decimal_3, 4);
 
    
    if( (test_table[0]==0) || (test_table[1]==0) ) {
    
        for(i=0 ; i<ARRAYLENGTH ; i++) {
            
            if(tmp[size_tmp].value[i] == '\0') {
                break;
            }
            
            if( isdigit(tmp[size_tmp].value[i]) ) {
                
                test_table[2]++; //Count numbers.
                
            } //End of IF.
            
            if( ( (tmp[size_tmp].value[i]>='a') && (tmp[size_tmp].value[i]<='z') ) || ( (tmp[size_tmp].value[i]>='A') && (tmp[size_tmp].value[i]<='Z') ) ) {
        
                test_table[3]++;
                
            } //End of IF.
            
            if( ispunct(tmp[size_tmp].value[i]) ) {
            
                if( (tmp->value[i]=='.') ) {
                
                    test_table[4]++; //Count '.'
                    
                } //End of IF.
                else {
                    
                    test_table[3]++;
    
                } //End of ELSE.
            } //End of IF.
            
        } //End of FOR.
        
    } //End of IF.
        
    if(test_table[3]!=0) {
        
        errors++;
        printf("Syntax Error: incorrect decimal's value.\n");
        printf("You typed string.\n");
        printf("\n");
    } //End of IF.
    
    if( (test_table[3]==0) && (test_table[2]!=0) && (test_table[4]==0) ) {
    
        errors++;
        printf("Syntax Error: incorrect decimal's value.\n");
        printf("You typed an integer number.\n");
        printf("\n");
    }
    
    if( (test_table[3]==0) && (test_table[2]!=0) && (test_table[4]>1) ) {
    
        errors++;
        printf("Syntax Error: incorrect decimal's value.\n");
        printf("You typed comma more than one times.\n");
        printf("\n");
    }
    
    if(errors==0) {
        return 0; //All correct.
    }
    else {
        return 1; //Something incorrect.
    }
    
} //End check user's input 1.

void SaveToStruct()
{

    if(size_var==limit_var) {
                
        arraydoubleVAR();
    
    }
    
    strcpy(var[size_var].type, tmp[size_tmp].type);
    strcpy(var[size_var].name, tmp[size_tmp].name);
    strcpy(var[size_var].value, tmp[size_tmp].value);
    
    size_var++;
    
    return;
} //End Saving to Struct.

int DeleteVariable(int option)
{
    fflush(stdin);
    int i; //simple loop counter.
    char tableVarDel[ARRAYLENGTH]; //User's input of variable which user want to delete.
    int pos; //position of variable to be deleted.
    int test;
    
    if(size_var==0) {
        printf("No variables are declared to delete.\n");
        printf("\n");
        return 2;
    }
    
    printf("Type the name of the variable you want to delete: ");
    gets(tableVarDel);
    
    //search for variable to delete.
    for(i=0 ; i<size_var ; i++) {
    
        test=strcmp(tableVarDel, var[i].name);
    
        if(test==0) { 
            pos=i;
            break;
        }
        
    } //End of FOR.
    
    //If variable exist.
    if(test==0) {
        
        printf("Variable -> Type: %s | Name: %s | Value %s | -> DELETED\n", var[pos].type, var[pos].name, var[pos].type);
        printf("\n");
        
        for(i=0 ; i<ARRAYLENGTH ; i++) {
        
            var[pos].type[i]='\0';
            var[pos].name[i]='\0';
            var[pos].value[i]='\0';
            
        }
        
        for(i=pos ; i<size_var ; i++) {
            
            var[i]=var[i+1];
            
        }
        
        size_var--;
        
    } //End of IF.
    else { //If variable does not exists.
    
        printf("The variable you want to delete, does not exist.\n");
        printf("\n");
        return 3;
    } //End of ELSE.
    
    if( ( (size_var==0) || (size_var==1) ) && (option==1) ) {
        return 2;
    }
    else if( ( (size_var==0) || (size_var==1) ) && (option==2) ) {
    
        return 1; //If this function return 1 the program will go to variables' declaration stage.
    }
    else {
         
        return 0; //If this function return 0 the the program will continue to operations stage. (if the program is there).
    }
    
} //End of delete.

//Double var array size.
void arraydoubleVAR()
{
    
    int i;
    
    variables temp[limit_var];
    
    for(i=0 ; i<limit_var ; i++) {
                         
        temp[i] = var[i];
    } //End of FOR.
    
    free(var);
    
    limit_var*=2;
    
    var=(variables*)malloc(limit_var*sizeof(variables));
    
    for(i=0 ; i<limit_var/2 ; i++) {
                           
        var[i] = temp[i];
    } //End of FOR.
    
    return; //End of function.
    
} //End of var array double size.

void InstructionsOperations()
{
    system("cls");
    
    int i;
    
    printf("Operations\n\n");
    printf("add      subtract   multiple \n\ndivide   equal      assign\n\n");
    
    //printing variables.
    for(i=0 ; i<size_var ; i++) {
    
        printf("Variable %d: | Type: %s | Name: %s | Value: %s |\n", i+1, var[i].type, var[i].name, var[i].value);
        
    } //End of printing varibles.  
    
    printf("\n");
    
    printf("Example: Type 'add' 'name of 1st variable' 'name of 2nd variable' \nand then press enter.\n\n");
    printf("Type the word 'example' to see more examples.\n\n");
    printf("Type 'return' or 'declar' to return to Variables' declaration stage.\n\n");
    printf("Other options: | 'help' to see commands | 'exit' to return to main menu |\n\n");
    
} //End of intructions (operation stage).

int UsersInput2()
{
    fflush(stdin);
    
    int decision; //Decide if action, name 1, name 2 are correct and continue to operations.
    int decision2;
    
    pointC:
           
    while(true) {
    
        printf(">");
        scanf("%s", &ope[size_ope].action);
        
        if( (ope[size_ope].action[0]=='e') && (ope[size_ope].action[1]=='x') && (ope[size_ope].action[2]=='i') && (ope[size_ope].action[3]=='t') && (ope[size_ope].action[4]=='\0') ) {
            return 0;
        }
        
        decision2=ScreenFunctions2();
        
        if(decision2==1) {
            return 1;
        }
        if(decision2==0) {
            goto pointC;
        }
        
        scanf("%s%s", &ope[size_ope].name1, &ope[size_ope].name2);
        
        decision=CheckUsersInput2();
        
        if(decision==0) {
            RecognizeOperation();
        }
        
    } //End of WHILE.
    
} //End of user's input.

int ScreenFunctions2()
{
    int test[10];
    int test2;
    
    char table_example[]={'e', 'x', 'a', 'm', 'p', 'l', 'e', '\0'};
    char table_help[]={'h', 'e', 'l', 'p', '\0'};
    char table_manual[]={'m', 'a', 'n', 'u', 'a', 'l', '\0'};
    char table_delete[]={'d', 'e', 'l', 'e', 't', 'e', '\0'};
    char table_commands[]={'c', 'o', 'm', 'm', 'a', 'n', 'd', 's', '\0'};
    char table_variables[]={'v', 'a', 'r', 'i', 'a', 'b', 'l', 'e', 's', '\0'};
    char table_clear[]={'c', 'l', 'e', 'a', 'r', '\0'};
    char table_declar[]={'d', 'e', 'c', 'l', 'a', 'r', '\0'};
    char table_return[]={'r', 'e', 't', 'u', 'r', 'n', '\0'};
    char table_instruction[]={'i', 'n', 's', 't', '\0'};
    
    test[0]=strncmp(ope[size_ope].action, table_example, 8);
    test[1]=strncmp(ope[size_ope].action, table_help, 5);
    test[2]=strncmp(ope[size_ope].action, table_manual, 7);
    test[3]=strncmp(ope[size_ope].action, table_delete, 7);
    test[4]=strncmp(ope[size_ope].action, table_commands, 9);
    test[5]=strncmp(ope[size_ope].action, table_variables, 10);
    test[6]=strncmp(ope[size_ope].action, table_clear, 5);
    test[7]=strncmp(ope[size_ope].action, table_declar, 7);
    test[8]=strncmp(ope[size_ope].action, table_return, 7);
    test[9]=strncmp(ope[size_ope].action, table_instruction, 5);
    
    
    if(test[0]==0) {
        ShowExamples();
        return 0;
    }
    
    if(test[1]==0) {
        ShowHelp();
        return 0;
    }
    
    if(test[2]==0) {
        ManualFunction();
        return 0;
    }
    
    if(test[3]==0) {
        
        test2=DeleteVariable(2);
        
        //Decide if program will stay to operations stage or return to declarations' stage.
        if( (test2==0) || (test2==3) ) {
            return 0;
        }
        else {
            printf("After this deletion only one variable is declared.\n");
            printf("Program will return to variables' declaration stage.\n");
            printf("\n");
            system("PAUSE");
            return 1;
        }
        
    }
    
    if(test[4]==0) {
        CommandsList();
        return 0;
    }
    
    if(test[5]==0) {
        ShowVariablesInScreen();;
        return 0;
    }
    
    if(test[6]==0) {
        ClearScreen();
        return 0;
    }
    
    if(test[9]==0) {
        InstructionsOperations();
        return 0;
    }
    
    if( (test[7]==0) || (test[8]==0) ) {
        return 1;
    }
    
    return 2;
    
} //End screen functions (operations stage).

int CheckUsersInput2()
{
    int errors=0; //Errors.
    int test_table[11]={1};
    int i; //A simple loop counter.
    int counter=0; //A counter for many cases.
    int a, b; //These variables will need to names' check.
    
    //Supported operations
    char table_add[]={'a', 'd', 'd', '\0'};
    char table_subtract[]={'s', 'u', 'b', 't', 'r', 'a', 'c', 't', '\0'};
    char table_multiple[]={'m', 'u', 'l', 't', 'i', 'p', 'l', 'e', '\0'};
    char table_divide[]={'d', 'i', 'v', 'i', 'd', 'e', '\0'};
    char table_equal[]={'e', 'q', 'u', 'a', 'l', '\0'};
    char table_assign[]={'a', 's', 's', 'i', 'g', 'n', '\0'};
    
    char table_subtract_3[]={'s', 'u', 'b', '\0'};
    char table_multiple_3[]={'m', 'u', 'l', '\0'};
    char table_divide_3[]={'d', 'i', 'v', '\0'};
    char table_equal_3[]={'e', 'q', 'u', '\0'};
    char table_assign_3[]={'a', 's', 's', '\0'};
    
    //Check if operation exists.
    test_table[0]=strncmp(ope[size_ope].action, table_add, 4);
    test_table[1]=strncmp(ope[size_ope].action, table_subtract, 9);
    test_table[2]=strncmp(ope[size_ope].action, table_multiple, 9);
    test_table[3]=strncmp(ope[size_ope].action, table_divide, 7);
    test_table[4]=strncmp(ope[size_ope].action, table_equal, 6);
    test_table[5]=strncmp(ope[size_ope].action, table_assign, 7);
    test_table[6]=strncmp(ope[size_ope].action, table_subtract_3, 4);
    test_table[7]=strncmp(ope[size_ope].action, table_multiple_3, 4);
    test_table[8]=strncmp(ope[size_ope].action, table_divide_3, 4);
    test_table[9]=strncmp(ope[size_ope].action, table_equal_3, 4);
    test_table[10]=strncmp(ope[size_ope].action, table_assign_3, 4);
    
    for(i=0 ; i<11 ; i++) {
        
        if(test_table[i]==0) {
            counter++;
            break;
        }
    } //End of FOR.
    
    if(counter==0) {
        errors++;
        printf("Unsupported operation!\n");
        printf("Type 'operations' to see supported operations.\n");
        printf("\n");
    }
    
    //Check if the name 1 exists.
    counter=0;
    
    for(i=0 ; i<size_var ; i++) {
    
        a=strcmp(var[i].name, ope[size_ope].name1);

        if(a==0) {
            counter++;
            break;
        } //End of IF.
        
    } //End of FOR.
    
    if(counter==0) {
        errors++;
        printf("Variable 1 does not exist!\n");
        printf("Check above the variables you have declared.\n");
        printf("\n");
    } //End of IF.
    //End of check. (1st name existance).
    
    //Check if the name 2 exists.
    counter=0;
    
    for(i=0 ; i<size_var ; i++) {
    
        b=strcmp(var[i].name, ope[size_ope].name2);

        if(b==0) {
            counter++;
            break;
        } //End of IF.
        
    } //End of FOR.
    
    if(counter==0) {
        errors++;
        printf("Variable 2 does not exist!\n");
        printf("Check above the variables you have declared.\n");
        printf("\n");
    } //End of IF.
    //End of check. (1st name existance).
    
    //Check if all are correct or if something went bad.
    if(errors==0) {
        return 0; //All correct.
    }
    else {
        return ; //Something incorrect.
    }

} //End of check. (check user's input) - (Operation's stage).

void RecognizeOperation() //Route the program to user's choice (to right operation).
{
    int decision_add, decision_sub, decision_sub_3, decision_mul, decision_mul_3, decision_div, decision_div_3, decision_equ, decision_equ_3, decision_ass, decision_ass_3;
    
    char table_add[]={'a', 'd', 'd', '\0'};
    char table_subtract[]={'s', 'u', 'b', 't', 'r', 'a', 'c', 't', '\0'};
    char table_multiple[]={'m', 'u', 'l', 't', 'i', 'p', 'l', 'e', '\0'};
    char table_divide[]={'d', 'i', 'v', 'i', 'd', 'e', '\0'};
    char table_equal[]={'e', 'q', 'u', 'a', 'l', '\0'};
    char table_assign[]={'a', 's', 's', 'i', 'g', 'n', '\0'};
    
    char table_subtract_3[]={'s', 'u', 'b', '\0'};
    char table_multiple_3[]={'m', 'u', 'l', '\0'};
    char table_divide_3[]={'d', 'i', 'v', '\0'};
    char table_equal_3[]={'e', 'q', 'u', '\0'};
    char table_assign_3[]={'a', 's', 's', '\0'};
    
    //Call operation.
    
    decision_add=strncmp(ope[size_ope].action, table_add, 4);
    
    if(decision_add==0) {
        OperationADD();
    }
    
    decision_sub=strncmp(ope[size_ope].action, table_subtract, 9);
    decision_sub_3=strncmp(ope[size_ope].action, table_subtract_3, 4);
    
    if( (decision_sub==0) || (decision_sub_3==0) ) {
        OperationSUBTRACT();
    }
    
    decision_mul=strncmp(ope[size_ope].action, table_multiple, 9);
    decision_mul_3=strncmp(ope[size_ope].action, table_multiple_3, 4);
    
    if( (decision_mul==0) || (decision_mul_3==0) ) {
        OperationMULTIPLE();
    }
    
    decision_div=strncmp(ope[size_ope].action, table_divide, 7);
    decision_div_3=strncmp(ope[size_ope].action, table_divide_3, 4);
    
    if( (decision_div==0) || (decision_div_3==0) ) {
        OperationDIVIDE();
    }
    
    decision_equ=strncmp(ope[size_ope].action, table_equal, 6);
    decision_equ_3=strncmp(ope[size_ope].action, table_equal_3, 4);
    
    if( (decision_equ==0) || (decision_equ_3==0) ) {
        OperationEQUAL();
    }
    
    decision_ass=strncmp(ope[size_ope].action, table_assign, 7);
    decision_ass_3=strncmp(ope[size_ope].action, table_assign_3, 4);
    
    if( (decision_ass==0) || (decision_ass_3==0) ) {
        OperationASSIGN();
    }
    
    return;
    
} //End of function recognize operation.

/* O P E R A T I O N S */

void OperationADD()
{
    int test;
    int i; //A Simple counter.
    int pos_1, pos_2; //Positions of varibles in struct.
    int errors=0; //Errors.
    char printStr[ARRAYLENGTH*2]={'\0'};
    
    //If both variables are integers.
    long valueLong1;
    long valueLong2;
    long resultValueLong;
    
    //If one if two variables is decimal.
    double valueDouble1;
    double valueDouble2;
    double resultValueDouble;
    
    char table_integer[]={'i', 'n', 't', 'e', 'g', 'e', 'r', '\0'};
    char table_decimal[]={'d', 'e', 'c', 'i', 'm', 'a', 'l', '\0'};
    char table_string[]={'s', 't', 'r', 'i', 'n', 'g', '\0'};
    char table_boolean[]={'b', 'o', 'o', 'l', 'e', 'a', 'n', '\0'};
    
    char table_integer_3[]={'i', 'n', 't', '\0'};
    char table_decimal_3[]={'d', 'e', 'c', '\0'};
    char table_string_3[]={'s', 't', 'r', '\0'};
    char table_boolean_3[]={'b', 'o', 'o', '\0'};
    
    char table_true[]={'t', 'r', 'u', 'e', '\0'};
    char table_false[]={'f', 'a', 'l', 's', 'e', '\0'};
    
    //Find variable with name 1.
    test=1;
    
    for(i=0 ; i<size_var ; i++) {
        
        test=strcmp(ope[size_ope].name1, var[i].name);
        
        if(test==0) {
            pos_1=i;
            break;
        }    
    } //End of FOR.
    
    //Find variable with name 2.
    test=1;
    
    for(i=0 ; i<size_var ; i++) {
    
        test=strcmp(ope[size_ope].name2, var[i].name);
        
        if(test==0) {
            pos_2=i;
            break;
            
        }
        
    } //End of FOR.
    
    //Check if both variables are boolean.
    int test1name1bool=strncmp(var[pos_1].type, table_boolean, 8);
    int test2name1bool=strncmp(var[pos_1].type, table_boolean_3, 4);
    
    int test1name2bool=strncmp(var[pos_2].type, table_boolean, 8);
    int test2name2bool=strncmp(var[pos_2].type, table_boolean_3, 4);
    
    if( ( (test1name1bool==0) || (test2name1bool==0) ) && ( (test1name2bool==0) || (test2name2bool==0) ) ) {
        
        int test1bool=strncmp(var[pos_1].value, table_true, 5);
        int test2bool=strncmp(var[pos_2].value, table_true, 5);
        
        if( (test1bool==0) && (test2bool==0) ) {
        
            printf("Result: true (Type: boolean)\n");
            printf("\n");
            
            return;
            
        } //End of IF.
        else {
            
            printf("Result: false (Type: boolean)\n");
            printf("\n");
            
            return;
            
        } //End of ELSE.
        
    } //End of IF.
    
    //Check if 1st variable is boolean. (The 2nd anything other).
    if( ( (test1name1bool==0) || (test2name1bool==0) ) && ( (test1name2bool!=0) || (test2name2bool!=0) ) ) {
    
        errors++;
        printf("Unsupperted action: the type of the first variable is boolean.\n");
        printf("\n");
        
    } //End of IF.
    
    if( ( (test1name1bool!=0) || (test2name1bool!=0) ) && ( (test1name2bool==0) || (test2name2bool==0) ) ) {
        
        errors++;
        printf("Unsupported action: the type of the second variable is boolean.\n");
        printf("\n");
        
    } //End of IF.
    //End of check.
    
    
    if(errors!=0) {
        return; //End function if there is error.
    }
    
    
    //Check if one of variables is string.
    int test1name1str=strncmp(var[pos_1].type, table_string, 7);
    int test2name1str=strncmp(var[pos_1].type, table_string_3, 4);
    
    int test1name2str=strncmp(var[pos_2].type, table_string, 7);
    int test2name2str=strncmp(var[pos_2].type, table_string_3, 4);
    
    if( ( (test1name1str==0) || (test2name1str==0) ) || ( (test1name2str==0) || (test2name2str==0) ) ) {
    
        strcat(printStr, var[pos_1].value);
        strcat(printStr, var[pos_2].value);
        printf("Result: %s (Type: string)\n", printStr);
        printf("\n");
        
        return;
    } //End of IF.
    
    
    int test1name1=strncmp(var[pos_1].type, table_integer, 8);
    int test2name1=strncmp(var[pos_1].type, table_integer_3, 4);
    
    int test1name2=strncmp(var[pos_2].type, table_integer, 7);
    int test2name2=strncmp(var[pos_2].type, table_integer_3, 4);
    
    //Check if two variables are integers.
    if( ( (test1name1==0) || (test2name1==0) ) && ( (test1name2==0) || (test2name2==0) ) ) {
    
        valueLong1=atol(var[pos_1].value);
        valueLong2=atol(var[pos_2].value);
        
        resultValueLong=valueLong1+valueLong2;
        
        printf("Result= %ld (Type: integer)\n", resultValueLong);
        
        printf("\n");
        
        return; //End of function.
        
    } //End of IF. (If both variables are integers).
    
    
    //Check if one of two variables is decimal and the other integer.
    if( ( (test1name1!=0) || (test2name1!=0) ) || ( (test1name2!=0) || (test2name2!=0) ) ) {
    
        valueDouble1=atof(var[pos_1].value);
        valueDouble2=atof(var[pos_2].value);
        
        resultValueDouble=valueDouble1+valueDouble2;
        
        printf("Result= %f (Type: decimal)\n", resultValueDouble);
        
        printf("\n");
        
        return; //End of function.
        
    } //End of IF. Check if one of two variables is decimal and the other integer.
    
} //End of ADD.

void OperationSUBTRACT()
{
    int i;
    int test;
    int pos_1, pos_2; //Position in struct if name 1 and name 2.
    int errors=0; //Errors.
    int intcheck; //For integers' check.
    
    char table_string[]={'s', 't', 'r', 'i', 'n', 'g', '\0'};
    char table_boolean[]={'b', 'o', 'o', 'l', 'e', 'a', 'n', '\0'};
    
    char table_string_3[]={'s', 't', 'r', '\0'};
    char table_boolean_3[]={'b', 'o', 'o', '\0'};
    
    char table_integer[]={'i', 'n', 't', 'e', 'g', 'e', 'r', '\0'};
    char table_decimal[]={'d', 'e', 'c', 'i', 'm', 'a', 'l', '\0'};
    
    char table_integer_3[]={'i', 'n', 't', '\0'};
    char table_decimal_3[]={'d', 'e', 'c', '\0'};
    
    //Find variable with name 1.
    test=1;
    
    for(i=0 ; i<size_var ; i++) {
        
        test=strcmp(ope[size_ope].name1, var[i].name);
        
        if(test==0) {
            pos_1=i;
            break;
        }    
    } //End of FOR.
    
    //Find variable with name 2.
    test=1;
    
    for(i=0 ; i<size_var ; i++) {
    
        test=strcmp(ope[size_ope].name2, var[i].name);
        
        if(test==0) {
            pos_2=i;
            break;
        }
    } //End of FOR.
    
    
    
    //Check if 1st variable is string.
    int test1=1;
    int test2=1;
    
    test1=strncmp(var[pos_1].type, table_string, 7);
    test2=strncmp(var[pos_1].type, table_string_3, 4);
    
    if( (test1==0) || (test2==0) ) {
        errors++;
        printf("Unsupported action: the type of the first variable is string.\n");
        printf("\n");
        
    }
    
    //Check if 1st variable is boolean.
    test1=1;
    test2=1;
    
    test1=strncmp(var[pos_1].type, table_boolean, 8);
    test2=strncmp(var[pos_1].type, table_boolean_3, 4);
    
    if( (test1==0) || (test2==0) ) {
        errors++;
        printf("Unsupported action: the type of the first variable is boolean.\n");
        printf("\n");
        
    }
    
    //Check if 2nd variable is string.
    test1=1;
    test2=1;
    
    test1=strncmp(var[pos_2].type, table_string, 7);
    test2=strncmp(var[pos_2].type, table_string_3, 4);
    
    if( (test1==0) || (test2==0) ) {
        errors++;
        printf("Unsupported action: the type of the second variable is string.\n");
        printf("\n");
        
    }
    
    //Check if 2nd variable is boolean.
    test1=1;
    test2=1;
    
    test1=strncmp(var[pos_2].type, table_boolean, 8);
    test2=strncmp(var[pos_2].type, table_boolean_3, 4);
    
    if( (test1==0) || (test2==0) ) {
        errors++;
        printf("Unsupported action: the type of the second variable is boolean.\n");
        printf("\n");
    }
    
    //End of checks.
    
    if(errors!=0) {
        return; //End of operation divide if one of the variables is string or boolean.
    }
    
    
    
    //Check if both variables are integers.
    
    intcheck=0;
    
    //Check if 1st variable is integer.
    test1=1;
    test2=1;
    
    test1=strncmp(var[pos_1].type, table_integer, 8);
    test2=strncmp(var[pos_1].type, table_integer_3, 4);
    
    if( (test1==0) || (test2==0) ) {
        intcheck++;
    }
    
    //Check if 2nd variable is integer.
    test1=1;
    test2=1;
    
    test1=strncmp(var[pos_2].type, table_integer, 8);
    test2=strncmp(var[pos_2].type, table_integer_3, 4);
    
    if( (test1==0) || (test2==0) ) {
        intcheck++;
    }
    
    if(intcheck==2) {
        
        long dividend_long=atol(var[pos_1].value);
        long divisor_long=atol(var[pos_2].value);
        
        long result_long=dividend_long-divisor_long;
        
        printf("Result=%ld (Type: integer)\n", result_long);
        
        printf("\n");
        
    } //End of IF.
    else {
        double dividend_double=atof(var[pos_1].value);
        double divisor_double=atof(var[pos_2].value);
    
        double result_double=dividend_double-divisor_double;
    
        printf("Result=%f (Type: decimal)\n", result_double);
        
        printf("\n");
        
    } //End of ELSE.
    
    return;
    
} //End of SUBTRACT.

void OperationMULTIPLE()
{
    int test; 
    int i, j; //Simple counters for loops.
    int pos_1, pos_2; //Position of variable 1 and variable 2 in struct.
    
    int errors=0; //Errors.
    
    int timesInt; //If 1st variable is int and 2nd string. Times string will be printed.
    
    int test1, test2; //These variables will be needed to checks.
    
    //These variables will be needed to case 1st variable int and 2nd string.
    int test1name1int;
    int test2name1int;
    
    int test1name2str;
    int test2name2str;
    
    //These variables will be needed to operations (afters check).
    int test1name2int;
    int test2name2int;
    
    //These variables will be needed to operation IF both variables are integers.
    long valueLong1;
    long valueLong2;
        
    long valueResultLong;
  
    //These variables will be needed to operation IF one of variables is decimal and the other integer, or both variables are decimal.
    double valueDouble1;
    double valueDouble2;
    
    double valueResultDouble;
    
    //Tables with types.
    char table_integer[]={'i', 'n', 't', 'e', 'g', 'e', 'r', '\0'};
    char table_decimal[]={'d', 'e', 'c', 'i', 'm', 'a', 'l', '\0'};
    char table_string[]={'s', 't', 'r', 'i', 'n', 'g', '\0'};
    char table_boolean[]={'b', 'o', 'o', 'l', 'e', 'a', 'n', '\0'};
    
    char table_integer_3[]={'i', 'n', 't', '\0'};
    char table_decimal_3[]={'d', 'e', 'c', '\0'};
    char table_string_3[]={'s', 't', 'r', '\0'};
    char table_boolean_3[]={'b', 'o', 'o', '\0'};
    
    //Find variable with name 1.
    test=1;
    
    for(i=0 ; i<size_var ; i++) {
        
        test=strcmp(ope[size_ope].name1, var[i].name);
        
        if(test==0) {
            pos_1=i;
            break;
        }    
    } //End of FOR.
    
    //Find variable with name 2.
    test=1;
    
    for(i=0 ; i<size_var ; i++) {
    
        test=strcmp(ope[size_ope].name2, var[i].name);
        
        if(test==0) {
            pos_2=i;
            break;
        }
    } //End of FOR.
    
    //Check if 1st variable is integer and 2nd string.
    test1name1int=strncmp(var[pos_1].type, table_integer, 8);
    test2name1int=strncmp(var[pos_1].type, table_integer_3, 4);
    
    test1name2str=strncmp(var[pos_2].type, table_string, 7);
    test2name2str=strncmp(var[pos_2].type, table_string_3, 4);
    
    if( ( (test1name1int==0) || (test2name1int==0) ) && ( (test1name2str==0) || (test2name2str==0) ) ) {
    
        timesInt=atoi(var[pos_1].value);
        
        for(j=0 ; j<timesInt ; j++) {
            
            if(j%2==0) {
                printf(" %s ", var[pos_2].value);
            }
            else {
                printf(" %s \n", var[pos_2].value);
            }
            
        } //End of FOR.
        
        printf("\n");
        
        return; //End of function. (after printing result).
        
    } //End of IF. Check if 1st variable is integer and 2nd string.
    
    //Check if 1st variable is boolean.
    
    test1=strncmp(var[pos_1].type, table_boolean, 8);
    test2=strncmp(var[pos_1].type, table_boolean_3, 4);
    
    if( (test1==0) || (test2==0) ) {
        errors++;
        printf("Unsupported action: the type of the first variable is boolean.\n");
        
        printf("\n");
        
    } //End of IF. Check if 1st variable is boolean.
    
    //Check if 1st variable is string.
    
    test1=strncmp(var[pos_1].type, table_string, 7);
    test2=strncmp(var[pos_1].type, table_string_3, 4);
    
    if( (test1==0) || (test2==0) ) {
        errors++;
        printf("Unsupported action: the type of the first variable is string.\n");
        
        printf("\n");
        
    } //End of IF. Check if 1st variable is string.
    
    //Check if 2nd variable is boolean.
    
    test1=strncmp(var[pos_2].type, table_boolean, 8);
    test2=strncmp(var[pos_2].type, table_boolean_3, 4);
    
    if( (test1==0) || (test2==0) ) {
        errors++;
        printf("Unsupported action: the type of the second variable is boolean.\n");
        
        printf("\n");
        
    } //End of IF. Check if 2nd variable is boolean.
    
    //Check if 2nd variable is string and the first NO integer.
    
    if( ( (test1name1int!=0) || (test2name1int!=0) ) && ( (test1name2str==0) || (test2name2str==0) ) ) {
        errors++;
        printf("Unsupported action: the type of the second variable is string.\n");
        
        printf("\n");
        
    } //End of IF. Check if 1st variable is decimal or string or boolean and 2nd string.
    
    
    if(errors!=0) {
                  
        return; //End functions if there is error.
        
    } //End of IF.
    
    test1name2int=strncmp(var[pos_2].type, table_integer, 8); 
    test2name2int=strncmp(var[pos_2].type, table_integer_3, 4);
    
    //Operation if both variables are integers.
    if( ( (test1name1int==0) || (test2name1int==0) ) && ( (test1name2int==0) || (test2name2int==0) ) ) {
    
        valueLong1=atol(var[pos_1].value);
        valueLong2=atol(var[pos_2].value);
        
        valueResultLong=valueLong1*valueLong2;
        
        printf("Result= %ld (Type: integer)\n", valueResultLong);
        
        printf("\n");
        
        return; //End function after operation.
        
    } //End of IF. If both variables are integers.
    

    //Operation one variable is decimal and the other integer, or if both variables is decimals.
    
    valueDouble1=atof(var[pos_1].value);
    valueDouble2=atof(var[pos_2].value);
        
    valueResultDouble=valueDouble1*valueDouble2;
        
    printf("Result= %f (Type: decimal)\n", valueResultDouble);
    
    printf("\n");
        
    return; //End function after operation.
        
    //End. If both variables are integers. Operation one variable is decimal and the other integer, or if both variables is decimals.
    
    
} //End of MULTIPLE.

void OperationDIVIDE()
{
    int i;
    int test;
    int pos_1, pos_2; //Position in struct if name 1 and name 2.
    int errors=0; //Errors.
    int intcheck; //For integers' check.
    
    //Find variable with name 1.
    test=1;
    
    for(i=0 ; i<size_var ; i++) {
        
        test=strcmp(ope[size_ope].name1, var[i].name);
        
        if(test==0) {
            pos_1=i;
            break;
        }    
    } //End of FOR.
    
    //Find variable with name 2.
    test=1;
    
    for(i=0 ; i<size_var ; i++) {
    
        test=strcmp(ope[size_ope].name2, var[i].name);
        
        if(test==0) {
            pos_2=i;
            break;
        }
    } //End of FOR.
    
    char table_string[]={'s', 't', 'r', 'i', 'n', 'g', '\0'};
    char table_boolean[]={'b', 'o', 'o', 'l', 'e', 'a', 'n', '\0'};
    
    char table_string_3[]={'s', 't', 'r', '\0'};
    char table_boolean_3[]={'b', 'o', 'o', '\0'};
    
    //Check if 1st variable is string.
    int test1=1;
    int test2=1;
    
    test1=strncmp(var[pos_1].type, table_string, 7);
    test2=strncmp(var[pos_1].type, table_string_3, 4);
    
    if( (test1==0) || (test2==0) ) {
        errors++;
        printf("Unsupported action: the type of the first variable is string.\n");
        
        printf("\n");
        
    }
    
    //Check if 1st variable is boolean.
    test1=1;
    test2=1;
    
    test1=strncmp(var[pos_1].type, table_boolean, 8);
    test2=strncmp(var[pos_1].type, table_boolean_3, 4);
    
    if( (test1==0) || (test2==0) ) {
        errors++;
        printf("Unsupported action: the type of the first variable is boolean.\n");
        
        printf("\n");
        
    }
    
    //Check if 2nd variable is string.
    test1=1;
    test2=1;
    
    test1=strncmp(var[pos_2].type, table_string, 7);
    test2=strncmp(var[pos_2].type, table_string_3, 4);
    
    if( (test1==0) || (test2==0) ) {
        errors++;
        printf("Unsupported action: the type of the second variable is string.\n");
        
        printf("\n");
        
    }
    
    //Check if 2nd variable is boolean.
    test1=1;
    test2=1;
    
    test1=strncmp(var[pos_2].type, table_boolean, 8);
    test2=strncmp(var[pos_2].type, table_boolean_3, 4);
    
    if( (test1==0) || (test2==0) ) {
        errors++;
        printf("Unsupported action: the type of the second variable is boolean.\n");
        
        printf("\n");
        
    }
    
    //End of checks.
    
    if(errors!=0) {
        return; //End of operation divide if one of the variables is string or boolean.
    }
    
    char table_integer[]={'i', 'n', 't', 'e', 'g', 'e', 'r', '\0'};
    char table_decimal[]={'d', 'e', 'c', 'i', 'm', 'a', 'l', '\0'};
    char table_integer_3[]={'i', 'n', 't', '\0'};
    char table_decimal_3[]={'d', 'e', 'c', '\0'};
    
    //Check if both variables are integers.
    
    intcheck=0;
    
    //Check if 1st variable is integer.
    test1=1;
    test2=1;
    
    test1=strncmp(var[pos_1].type, table_integer, 8);
    test2=strncmp(var[pos_1].type, table_integer_3, 4);
    
    if( (test1==0) || (test2==0) ) {
        intcheck++;
    }
    
    //Check if 2nd variable is integer.
    test1=1;
    test2=1;
    
    test1=strncmp(var[pos_2].type, table_integer, 8);
    test2=strncmp(var[pos_2].type, table_integer_3, 4);
    
    if( (test1==0) || (test2==0) ) {
        intcheck++;
    }
    
    if(intcheck==2) {
        
        long dividend_long=atol(var[pos_1].value);
        long divisor_long=atol(var[pos_2].value);
        
        long result_long=dividend_long/divisor_long;
        
        printf("Result=%ld (Type: integer)\n", result_long);
        
        printf("\n");
        
    } //End of IF.
    else {
        double dividend_double=atof(var[pos_1].value);
        double divisor_double=atof(var[pos_2].value);
    
        double result_double=dividend_double/divisor_double;
    
        printf("Result=%f (Type: decimal)\n", result_double);
        
        printf("\n");
        
    } //End of ELSE.
    
    return; 
    
} //End of DIVIDE.

void OperationEQUAL()
{
    int i;
    int test;
    int pos_1, pos_2; //Position in struct if name 1 and name 2.
    int test_type, test_value; //These variables will be needed on final check. (if two variables are equal).
    
    //Find variable with name 1.
    test=1;
    
    for(i=0 ; i<size_var ; i++) {
        
        test=strcmp(ope[size_ope].name1, var[i].name);
        
        if(test==0) {
            pos_1=i;
            break;
        }    
    } //End of FOR.
    
    //Find variable with name 2.
    test=1;
    
    for(i=0 ; i<size_var ; i++) {
    
        test=strcmp(ope[size_ope].name2, var[i].name);
        
        if(test==0) {
            pos_2=i;
            break;
        }
    } //End of FOR.
    
    //Check if two variables are equal each other.
    test_type=strcmp(var[pos_1].type, var[pos_2].type);
    test_value=strcmp(var[pos_1].value, var[pos_2].value);
    
    if( (test_type==0) && (test_value==0) ) {
        printf("Result: true\n");
        printf("\n");
    }
    else {
        printf("Result: false\n");
        printf("\n");
    }
    
} //End of EQUAL.

void OperationASSIGN()
{
    int i;
    int test;
    int pos_1, pos_2; //Position in struct if name 1 and name 2.
    
    //Find variable with name 2.
    test=1;
    
    for(i=0 ; i<size_var ; i++) {
        
        test=strcmp(ope[size_ope].name1, var[i].name);
        
        if(test==0) {
            pos_1=i;
            break;
            
        }    
    } //End of FOR.
    
    //Find variable with name 2.
    test=1;
    
    for(i=0 ; i<size_var ; i++) {
    
        test=strcmp(ope[size_ope].name2, var[i].name);
        
        if(test==0) {
            pos_2=i;
            break;
        }
    } //End of FOR.
    
    strcpy(var[pos_1].type, var[pos_2].type);
    strcpy(var[pos_1].value, var[pos_2].value);
    
    printf("Result: | Type: %s | Name: %s | Value: %s |\n", var[pos_1].type, var[pos_1].name, var[pos_1].value);
    
    printf("\n");

} //End of ASSIGN.

void TemporaryStructInitialization()
{
    int i;
    
    for(i=0 ; i<ARRAYLENGTH ; i++) {
        tmp[size_tmp].type[i]='\0';
        tmp[size_tmp].type[i]='\0';
        tmp[size_tmp].type[i]='\0';
    } //End of FOR.
    
} //End of initialization.
