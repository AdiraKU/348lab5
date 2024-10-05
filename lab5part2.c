#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Function declarations
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
float fahrenheit_to_kelvin(float fahrenheit);
float kelvin_to_fahrenheit(float kelvin);
void categorize_temperature(float celsius);

int main() {
    float temperature, converted_temperature;
    int input_scale, output_scale;
    char scale_indicator[5];
    // inputs and handiling yay
    printf("Enter the temperature: ");
    scanf("%f", &temperature);
    while (input_scale == 3 && temperature < 0){
        printf("Invalid temperature! Kelvin cannot be negative.\n");
        printf("Enter the temperature: ");
        scanf("%f", &temperature);
    }

    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &input_scale);
    while (input_scale < 1 || input_scale > 3){
        printf("Invalid conversion choice!\n");
        printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &input_scale);
    }

    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    scanf("%d", &output_scale);
    while(output_scale < 1 || output_scale > 3){
        printf("Invalid conversion choice!\n");
        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        scanf("%d", &output_scale);
    }

    // Conversion logic
    if (input_scale == 1) { // Celsius as input
        if (output_scale == 1) {
            converted_temperature = temperature;
        } else if (output_scale == 2) {
            converted_temperature = celsius_to_fahrenheit(temperature);
        } else {
            converted_temperature = celsius_to_kelvin(temperature);
        }
    } else if (input_scale == 2) { // Fahrenheit as input
        if (output_scale == 1) {
            converted_temperature = fahrenheit_to_celsius(temperature); 
        } else if (output_scale == 2) {
            converted_temperature = temperature; 
        } else {
            converted_temperature = fahrenheit_to_kelvin(temperature);  
        }
    } else { // Kelvin as input
        if (output_scale == 1) {
            converted_temperature = kelvin_to_celsius(temperature);
        } else if (output_scale == 2) {
            converted_temperature = kelvin_to_fahrenheit(temperature); 
        } else {
            converted_temperature = temperature; 
        }
    }

    // display temperature

    if (output_scale == 1){
        strcpy(scale_indicator,"°C");
    } else if(output_scale == 2){
        strcpy(scale_indicator,"°F");
    } else{
        strcpy(scale_indicator, "K");
    }
    
    printf("\nConverted temperature: %.2f%s\n", converted_temperature,scale_indicator);

    // categorize the temperature and advise
    if (output_scale == 1) {
        categorize_temperature(converted_temperature); // categorization based on Celsius
    } else if (output_scale == 2) {
        categorize_temperature(fahrenheit_to_celsius(converted_temperature)); // convert to Celsius 
    } else {
        categorize_temperature(kelvin_to_celsius(converted_temperature)); // convert to Celsius 
    }

    return 0;
}

// function definitions
float celsius_to_fahrenheit(float celsius) {
    return (9.0 / 5.0) * celsius + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0 / 9.0) * (fahrenheit - 32);
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Stay indoors!\n");
    } else if (celsius >= 0 && celsius < 10) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (celsius >= 10 && celsius < 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: You should feel comfortable.\n");
    } else if (celsius >= 25 && celsius < 35) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Stay hydrated!\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Stay indoors and stay cool!\n");
    }
}