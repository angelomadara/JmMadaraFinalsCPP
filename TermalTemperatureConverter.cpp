#include <iostream>
#include <conio.h>
#include <string>

using std::cout; using std::cin;
using std::endl; using std::string;

/**
 * celcius temperature
 **/
float celciusToKelvin(float temperature){
  // formula : 0°C + 273.15
  float kelvin = 273.15;
  return temperature + kelvin;
}
float celciusToFahrenheit(float temperature){
  // formula : 0°C × 9/5 + 32
  return temperature * 1.8 + 32;
}
float celciusToRankine(float temperature){
  // formula : T(°R) = (T(°C) + 273.15) × 9/5
  return (temperature + 273.15) * 1.8;
}

/**
 * kelvin temperature
 **/
float kelvinToCelcius(float temperature){
  // formula : 0°K - 273.15
  float celcius = 273.15;
  return temperature - celcius;
}
float kelvinToFahrenheit(float temperature){
  // formula : T(°F) = T(K) × 9/5 - 459.67
  return temperature * 1.8 - 459.67;
}
float kelvinToRankine(float temperature){
  // formula : T(°R) = T(K) × 9/5
  return temperature * 1.8;
}

/**
 * fahrenheit temperature
 **/
float fahrenheitToCelcius(float temperature){
  // formula : (T(°F) - 32) × 5/9
  return (temperature - 32) * 0.555555556;
}
float fahrenheitToKelvin(float temperature){
  // formula :  (60°F + 459.67)× 5/9
  return  (temperature + 459.67) * 0.555555556;
}
float fahrenheitToRankine(float temperature){
  // formula : T(°R) = T(°F) + 459.67
  return temperature + 459.67;
}

/**
 * rankine temperature
 **/
float rankineToCelcius(float temperature){
  return (temperature- 491.67) * 0.555555556;
}
float rankineToKelvin(float temperature){
  return temperature * 0.555555556;
}
float rankineToFahrenheit(float temperature){
  return temperature - 459.67;
}

int main(){
    
    start_again:
  
    float temperature = 0;
    string unit_array[4] = {"Celcius","Kelvin","Fahrenheit","Rankine"};
    int unit;
    int toUnit;
  

    // select a unit
    cout << "Select a unit: " << endl;
    cout << " +-----------------------------------------------------+"<<endl;
    for(int x = 0; x < 4; x++){
      cout << " | "<< (x+1) << ". "<< unit_array[x];
    }
    cout << " |" << endl;
    cout << " +-----------------------------------------------------+"<<endl;
    ask_the_unit_again:
    cout << " >> select unit choice from 1 ~ 4: ";
    cin >> unit;
    
    // filter the `unit` input if the value is from the range of 1 to 4
    if(unit < 1 || unit > 4) {
      goto ask_the_unit_again;
    }
    cout << endl;
    
    // show choices of units where to convert to 
    cout << "Convert " << unit_array[unit-1] << " to " << endl;
    cout << " +-----------------------------------------------------+"<<endl;
    for(int x = 0; x < 4; x++){
      cout << " | "<< (x+1) << ". "<< unit_array[x];
    }
    cout << " |" << endl;
    cout << " +-----------------------------------------------------+"<<endl;
    ask_the_unit_to_convert_again:
    cout << " >> select unit choice from 1 ~ 4: ";
    cin >> toUnit;
    
    // filter the `toUnit` input if the value is from the range of 1 to 4
    if(unit < 1 || unit > 4) {
      goto ask_the_unit_to_convert_again;
    }
    // look if the `unit` and `toUnit` is equal to each other
    if(unit == toUnit){
      goto ask_the_unit_to_convert_again;
    }
    cout << endl;
    
    cout << " " << unit_array[unit-1] << " : "; 
    cin >> temperature;
    cout << endl;
    /**
     * 1 = Celcius
     * 2 = Kelvin
     * 3 = Fahrenheit
     * 4 = Rankine
    **/
    if( unit == 1){
        if(toUnit == 2){
            cout << " Output: " << temperature << "°C is equals to "<< celciusToKelvin(temperature) << "°K";
        }
        else if(toUnit == 3){
            cout << " Output: " << temperature << "°C is equals to "<< celciusToFahrenheit(temperature) << "°F";
        }
        else{
            cout << " Output: " << temperature << "°C is equals to "<< celciusToRankine(temperature) << "°R";
        }
    }
    else if(unit == 2){
        if(toUnit == 1){
            cout << " Output: " << temperature << "°K is equals to "<< kelvinToCelcius(temperature) << "°C";
        }
        else if(toUnit == 3){
            cout << " Output: " << temperature << "°K is equals to "<< kelvinToFahrenheit(temperature) << "°F";
        }
        else{
            cout << " Output: " << temperature << "°K is equals to "<< kelvinToRankine(temperature) << "°R";
        }
    }
    else if(unit == 3){
      if(toUnit == 1){
        cout << " Output: " << temperature << "°F is equals to "<< fahrenheitToCelcius(temperature) << "°C";
      }
      else if(toUnit == 2){
        cout << " Output: " << temperature << "°F is equals to "<< fahrenheitToKelvin(temperature) << "°K";
      }
      else{
        cout << " Output: " << temperature << "°F is equals to "<< fahrenheitToRankine(temperature) << "°R";
      }
    }
    else if(unit == 4){
      if(toUnit == 1){
        cout << " Output: " << temperature << "°R is equals to "<< rankineToCelcius(temperature) << "°C";
      }
      else if(toUnit == 2){
        cout << " Output: " << temperature << "°R is equals to "<< rankineToKelvin(temperature) << "°K";
      }
      else{
        cout << " Output: " << temperature << "°R is equals to "<< rankineToFahrenheit(temperature) << "°F";
      }
    }
    
    cout << endl << endl;
    cout << "Do you want to convert again? Press [y] to convert again or any key to close the program... ";
    char convert_again; 
    cin >> convert_again;
    if(convert_again == 'y' || convert_again == 'Y'){
        clrscr();
        goto start_again;
    }
    
    return 0;
}