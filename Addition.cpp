//============================================================================
// Name        :Addition.cpp
// Author      :Shaila Hirji
// Version     :
// Copyright   : Your copyright notice
// Description : This application calculates the sum of two very large numbers using 3 LinkedStacks as the basic data structures
//============================================================================
#include "LinkedStack.h"
#include<iostream>

using namespace std;

void stackFiller(string, LinkedStack<int> *);

int main() {

    LinkedStack<int> s1 = LinkedStack<int>::LinkedStack(); //stores first large number
    LinkedStack<int> s2 = LinkedStack<int>::LinkedStack(); //stores second large number
    LinkedStack<int> total = LinkedStack<int>::LinkedStack(); //store the sum of the 2 large numbers

    string number1; //store user's input of 1st large number as string
    cout << "Enter a very large number:";
    cin >> number1;
    string number2; //stores users 2nd large number as string
    cout << "Enter a very large number:";
    cin >> number2;

    if (number1.length() < number2.length()) { //SWAP, to ensure first number is ALWAYS greater than 2nd number, for simplicity
        string temp = number1;
        number1 = number2;
        number2 = temp;

    }

    //fill designated stacks with data of int type from the user input

    stackFiller(number1, &s1);
    stackFiller(number2, &s2);

    //add the two numbers

    int carry = 0; //stores the number to be carried forward while comouting the addition
    int sum = 0; //stores the sum of 2 individual digits(one from each stack)

    while (!s1.isEmpty()) { //the loop will run until s1 is empty, s1 will always be the larger stack, see SWAP algorithm above

        if (s2.isEmpty()) {
            //if s2 is empty, we no longer require values from it for our addition

            sum = carry + s1.pop(); //sum will be a value from s1 and carry--(left over from the last sum)

        } else { //s2 has values to contribute towards the sum

            sum = carry + s1.pop() + s2.pop(); //left over from previous sum + value in s1 + value in s2
        }

        if (sum > 9) {

            int remainder = sum % 10; //get the value to be part of sum

            total.push(remainder); //add it to total Stack

            carry = sum / 10; //store the left over value into carry, to be carried forward to the next sum

        } else { //sum <9
            carry = 0;
            total.push(sum); //add value into total Stack

        }

    }

    string result = ""; //string for output

    //if both stacks, s1 and s2 are empty, but there was a left over value to be carried forward from the last sum
    if (carry != 0) {
        result = carry + '0'; //add the value to result string
    }

    while (!total.isEmpty()) { // remove all values from the total stack
        result += total.pop() + '0'; //add them to the result
    }

    cout << "This is your sum: " << result << endl;

    return 0;

}
;

/*
 * This method fills stack with int data by breaking user input from string=>Char and converting char to int
 */
void stackFiller(string s, LinkedStack<int> *stack) {

    for (int i = 0; i < s.length(); i++) { //run for length of string
        char ch = s[i]; //break string into char
        int value = ch - '0'; //convert into int
        stack->push(value); //add int value to stack
    }

}

