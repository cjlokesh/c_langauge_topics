// Header file inclusions
#include <stdio.h>  // Standard input output
#include <stdint.h> // Standard integers types

// Function pointer signaturesult
typedef void (*ptrFuncAddNumbers)(uint8_t numberOne, uint8_t numberTwo); // This is function pointer can point to those functions whose return type is void and accepts 2 parameters.
typedef uint8_t (*ptrFuncdisplayNumber)(uint8_t number);                 // This is function pointer can point to those functions whose return type is uint8_t and accepts 1 parameter

// Function prototypes
// We can use the above function pointer to point the below functions
void addNumbers(uint8_t numberOne, uint8_t numberTwo);
uint8_t displayNumber(uint8_t number);

//Structure variable, whose members are function pointers
typedef struct
{
    // Struct members that can be used to point any functions with the same function signaturesult
    // Type of the memebers is function pointers, so we can point the function.
    ptrFuncAddNumbers addNumbersFunc;
    ptrFuncdisplayNumber displayNumberFunc;
} funcPtrStruct; // Structure variable name

//Main function
int main()
{
    // Creating the local structure
    funcPtrStruct fPtrStruct =
        {
            // Passing the functions as members
            addNumbers,
            displayNumber};
    // Accessing the local structure's memebers
    // If structure memeber is normal variable, invoking the memeber after the period operator(.) name of the variable is enough
    // In case of function pointer pointing to the function, we must invoke it with the actual arguments
    fPtrStruct.addNumbersFunc(5, 5);                   // Invoking the function with actual arguments
    uint8_t result = fPtrStruct.displayNumberFunc(10); // Invoking the function with actual arguments and storing it's return type
    printf("result: %d\n", result);                    // Printing the returned value from the above function
}

/*******************************************************************************
 * @fn          addNumbers
 *
 * @brief       Performs the addition of the numbers passed as parameters
 *
 * @param       numberOne -> any uint8_t integer number
 *
 * @param       numberTwo -> any uint8_t integer number
 * 
 * @return      none
 */
void addNumbers(uint8_t numberOne, uint8_t numberTwo)
{
    printf("numberOne + numberTwo: %d\n", numberOne + numberTwo);
}

/*******************************************************************************
 * @fn          displayNumber
 *
 * @brief       Displays the number passed as parameter
 *
 * @param       number -> any uint8_t integer number
 * 
 * 
 * @return      none
 */
uint8_t displayNumber(uint8_t number)
{
    printf("Number passed as argument: %d\n", number);
    return number;
}