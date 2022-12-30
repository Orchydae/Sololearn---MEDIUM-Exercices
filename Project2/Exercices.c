#define _CRT_SECURE_NO_WARNINGS

#include "Exercices.h"
#include <stdio.h>
#include <stdlib.h>

void Pig_Latin() {
	char string_input[100];
	int i;
	gets(string_input);

	char* string_token = strtok(string_input, " ");
	string_input[strcspn(string_input, "\n")] = 0;
	while (string_token != NULL) {
		//printf(" // String token: %s - ", string_token);
		for (i = 0; i < strlen(string_token); i++) {
			printf("%c", string_token[i + 1]);
			if (i == strlen(string_token) - 1) {
				printf("%c%s ", string_token[0], "ay");
			}
		}
		string_token = strtok(NULL, " ");
	}
}

void Safety_Deposit_Boxes() {
	int time_to_drill = 5;
	char items[100];
	gets(items);

	char item_to_steal[100];
	gets(item_to_steal);

	int found_box = 0;
	int i = 0;
	int total_time;

	char* item_token = strtok(items, ",");
	while (item_token != NULL && found_box != 1) {
		i++;
		if (strcmp(item_token, item_to_steal) == 0)
			found_box = 1;

		item_token = strtok(NULL, ",");
	}

	total_time = time_to_drill * i;

	printf("%d", total_time);
}

void Roadrunner() {
	int starting_distance = 50;
	int distance_safety;
	int roadrunner_speed;
	int coyote_speed;
	double roadrunner_home_time;
	double coyote_catch_time;

	scanf("%d%d%d", &distance_safety, &roadrunner_speed, &coyote_speed);

	roadrunner_home_time = (double)distance_safety / (double)roadrunner_speed;
	coyote_catch_time = (double)(distance_safety + starting_distance) / (double)coyote_speed;

	if (coyote_catch_time <= roadrunner_home_time)
		printf("Yum");
	else
		printf("Meep Meep");
}

void Deja_Vu() {

	char random_letters[100];
	char letter_scanner;
	int i, j;
	int letter_count;
	int true = 1;
	int false = 0;
	int is_not_unique = false;


	gets(random_letters);

	for (i = 0; i < strlen(random_letters) && is_not_unique == false; i++) {
		letter_scanner = random_letters[i];
		letter_count = 0;
		for (j = 0; j < strlen(random_letters) && is_not_unique == false; j++) {
			if (random_letters[j] == letter_scanner) {
				letter_count++;
			}
			if (letter_count > 1) {
				is_not_unique = true;
			}
		}
	}

	if (is_not_unique == true)
		printf("Deja Vu");
	else
		printf("Unique");
}

void The_Spy_Life() {
	char secret_message[100];
	char clean_message[100] = "";
	char flipped_message[100] = "";
	gets(secret_message);

	message_cleaner(secret_message, clean_message);

	message_flipper(clean_message, flipped_message);

	printf("%s", flipped_message);

}


void message_flipper(char* clean_message, char* flipped_message) {
	int i;
	char char_scanner;

	for (i = strlen(clean_message) - 1; i >= 0; i--) {
		char_scanner = clean_message[i];
		strncat(flipped_message, &char_scanner, 1);
	}
}

void message_cleaner(char* secret_message, char* clean_message) {
	int i;
	char char_scanner;
	for (i = 0; i < strlen(secret_message); i++) {
		if (isalpha(secret_message[i]) != 0 || secret_message[i] == 32) {

			char_scanner = secret_message[i];
			strncat(clean_message, &char_scanner, 1);
		}
	}
}

void Hexcode_Generator() {
	int red;
	int green;
	int blue;

	scanf("%d%d%d", &red, &green, &blue);
	printf("#%x%x%x", red, green, blue);
}

void Symbols() {
	char string_input[100];
	char clean_string[100] = "";
	char char_check;
	gets(string_input);

	for (int i = 0; i < strlen(string_input); i++) {
		if (isalnum(string_input[i]) != 0 || string_input[i] == 32) {
			char_check = string_input[i];
			strncat(clean_string, &char_check, 1);
		}
	}

	printf("%s", clean_string);
}

void Duty_Free() {

	double discount = 0.3;
	double tax = 1.07;
	char item_prices[100];
	double final_savings;
	double price_before_discount = 0;
	double expensive_item;
	double total_savings;

	gets(item_prices);

	char* price_token = strtok(item_prices, ",");
	expensive_item = atof(price_token);

	while (price_token != NULL) {
		//printf("%s\n", price_token);
		if (atof(price_token) > expensive_item)
			expensive_item = atof(price_token);
		price_before_discount += atof(price_token);
		price_token = strtok(NULL, ",");
	}
	total_savings = (price_before_discount - expensive_item) * discount * tax;
	printf("%.0lf", floor(total_savings));
}

void Carrot_Cake() {
	int nb_carrots;
	int nb_boxes;
	int leftover_carrots;
	int carrot_cake_threshold = 7;

	scanf("%d%d", &nb_carrots, &nb_boxes);

	leftover_carrots = nb_carrots % nb_boxes;

	if (leftover_carrots < 7)
		printf("I need to buy %d more", carrot_cake_threshold - leftover_carrots);
	else
		printf("Cake Time");
}

void Building_Blocks() {
	int nb_kids = 15;
	int blue;
	int red;
	int green;
	int yellow;
	int leftover_blocks;

	scanf("%d%d%d%d", &blue, &red, &green, &yellow);

	leftover_blocks = (blue % nb_kids) + (red % nb_kids) + (green % nb_kids) + (yellow % nb_kids);

	printf("%d", leftover_blocks);

}

void Name_Buddy() {
	char names[100];
	char my_name[20];

	gets(names);
	scanf("%s", &my_name);
	char my_first_letter = my_name[0];
	int i;
	int teammate_found = 0;

	char* letter_token = strtok(names, " ");
	while (letter_token != NULL) {
		if (letter_token[0] == my_first_letter)
			teammate_found = 1;
		letter_token = strtok(NULL, " ");
	}

	if (teammate_found == 1)
		printf("Compare notes");
	else
		printf("No such luck");
}

void Thats_Odd() {
	int sum_even_numbers = 0;
	int length_list;
	int int_input;
	int i;

	scanf("%d", &length_list);

	for (i = 0; i < length_list; i++) {
		scanf("%d", &int_input);
		if (int_input % 2 == 0) {
			sum_even_numbers += int_input;
		}
	}
	printf("%d", sum_even_numbers);

}

void No_Numerals() {
	char sentence[100];
	gets(sentence);
	char no_numerals[100] = "";
	char char_check;
	int i;

	for (i = 0; i < strlen(sentence); i++) {
		char_check = sentence[i];
		//printf("%d\n", sentence[i]);
		if (char_check < 48 || char_check > 57) {
			strncat(no_numerals, &char_check, sizeof(char));
		}
		else if (sentence[i] + sentence[i + 1] == 97) {
			strcat(no_numerals, "ten");
			i++;
		}
		else {
			switch (char_check) {
			case 48:
				strcat(no_numerals, "zero");
				break;
			case 49:
				strcat(no_numerals, "one");
				break;
			case 50:
				strcat(no_numerals, "two");
				break;
			case 51:
				strcat(no_numerals, "three");
				break;
			case 52:
				strcat(no_numerals, "four");
				break;
			case 53:
				strcat(no_numerals, "five");
				break;
			case 54:
				strcat(no_numerals, "six");
				break;
			case 55:
				strcat(no_numerals, "seven");
				break;
			case 56:
				strcat(no_numerals, "eight");
				break;
			case 57:
				strcat(no_numerals, "nine");
				break;
			}
		}
	}

	printf("%s", no_numerals);
	return EXIT_SUCCESS;
}