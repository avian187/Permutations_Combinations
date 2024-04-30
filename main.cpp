/********************************************
*	DEVELOPER:	Ian Utnehmer
* COLLABORATORS: Eduardo Mariscal
*	COURSE:	CS226 Discrete Structures
*	PROJECT:	4
*	LAST MODIFIED:	<date of last change>
********************************************/
/********************************************
*	Permutations and Combinations Calculator
*********************************************
*	PROGRAM DESCRIPTION:
*	This program calculates the number of
 *	r-permutations or r-combinations given n,
 *	r, and other parameters.
*********************************************
*	FUNCTIONS:
*  main() - main program
*********************************************/

/*********************************************
*	SETUP STATEMENTS and PURPOSE:
*********************************************/
#include <iostream> //to output to console
#include <cmath> //for math functions
using namespace std; //access namespace

//function prototypes


/*********************************************
*	MAIN PROGRAM:
*********************************************/
// Combinations formula: n! / (r!(n-r)!)
// Permutations formula: n! / (n-r)!

int main() {
    int n, r; // n is the total number of elements, r is the sample size
    bool repetition, order; // repetition is whether elements can be chosen more than once, order is whether arrangement is significant
    cout << "This program calculates the number of r-permutations or r-combinations given n, r, and other parameters.\n"
    << "A permutation is an arrangement of objects in a specific order.\n"
    << "A combination is a selection of objects without regard to the order in which they are selected.\n\n"
    << "The gamma function (n-1)! is used to simplify calculations.\n"
    // The gamma function is the only cmath function I know of that can calculate factorials so far.
    << "\nRepetition allowed: elements can be chosen more than once.\n-->Number of choices for each position is constant\n"
    << "Order matters: Arrangement is significant \n-->(different sequences of the same elements are counted separately).\n"
    << endl;
    cout << "Enter n (total number of elements): ";
    cin >> n;
    cout << "Enter r (sample size): ";
    cin >> r;
    cout << "Repetition allowed? (1 for yes, 0 for no): ";
    cin >> repetition;
    cout << "Order matters? (1 for yes, 0 for no): ";
    cin >> order;

    // If repetition is allowed, then the number of choices for each position is constant
    if (repetition) {
        if (order) {
            // If order matters, it is a permutation
            // --> Use the formula n^r
            cout << "Number of r-permutations: " << pow(n, r) << endl;
        } else {
            // If order does not matter, it is a combination
            // --> Use the formula (n+r-1)! / (r!(n-1)!)
            cout << "Number of r-combinations: " << pow(n, r) << endl;
        }
    } else {    // If repetition is not allowed, then the number of choices for each position is not constant
        if (order) {
            // If order matters, it is a permutation
            // --> Use the formula n! / (n-r)!
            cout << "Number of r-permutations: " << tgamma(n + 1) / tgamma(n - r + 1) << endl;
        } else {
            // If order does not matter, it is a combination
            // --> Use the formula n! / (r!(n-r)!)
            cout << "Number of r-combinations: " << tgamma(n + 1) / (tgamma(r + 1) * tgamma(n - r + 1)) << endl;
        }
    }
    // Exit the program
    return 0;
}
