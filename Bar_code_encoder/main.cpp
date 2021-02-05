/*
 * Program will ask a user for a zip code and return a bar code.
 */

/* 
 * File:   main.cpp
 * Author: Rosita Emakpo
 */

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    
    string one = ":::||";
    string two = "::|:|";
    string three = "::||:";
    string four = ":|::|";
    string five = ":|:|:";
    string six = ":||::";
    string seven = "|:::|";
    string eight = "|::|:";
    string nine = "|:|::";
    string zero = "||:::";
    string frameBar = "|";
    
   
    
    int sum = 0;
    int remainder;
    
    
    cout << "Please give a zip code\n";
    
    string zipcode;
    cin >> zipcode;
    cout << "Your bar code is \n";
    
    cout << frameBar; //beginning frame bar
    for(int i = 0; i <= 5; i++){

        //Read each number in loop and print bar code for each number
        
        if(zipcode[i] == '1'){
            cout << one;
        }
        if(zipcode[i] == '2'){
            cout << two;
        } 
        if(zipcode[i] == '3'){
            cout << three;
        }
        if(zipcode[i] == '4'){
            cout << four;
        }
        if(zipcode[i] == '5'){
            cout << five;
        }
        if(zipcode[i] == '6'){
            cout << six;
        }
        if(zipcode[i] == '7'){
            cout << seven;
        }
        if(zipcode[i] == '8'){
            cout << eight;
        }
        if(zipcode[i] == '9'){
            cout << nine;
        }
        if(zipcode[i] == '0'){
            cout << zero;
        }
        
    }
    
    // Convert zip code to int
    int zipcode_number = atoi(zipcode.c_str());
    
    while(zipcode_number > 0){
        remainder = zipcode_number  % 10;
        sum = sum + remainder;
        zipcode_number = zipcode_number / 10;
    }
    
    
    // Choose the check digit to make the sum a multiple of 10
    if(sum % 10 == 0){
        cout << zero;
    }else if(sum % 10 == 1){
        cout << nine;
    }else if(sum % 10 == 2){
        cout << eight;
    }else if(sum % 10 == 3){
        cout << seven;
    }else if(sum % 10 == 4){
        cout << six;
    }else if(sum % 10 == 5){
        cout << five;
    }else if(sum % 10 == 6){
        cout << four;
    }else if(sum % 10 == 7){
        cout << three;
    }else if(sum % 10 == 8){
        cout << two;
    }else{
        cout << one;
    }
    
    cout << frameBar; //ending frame bar
    
    
    return 0;
    }

    


