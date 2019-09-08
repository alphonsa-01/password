#include<fstream>

#include<iostream>

#include<string>

const char k_min_small_alphabet = 'a';
const char k_max_small_alphabet = 'z';
const char k_min_capital_alphabet = 'A';
const char k_max_capital_alphabet = 'Z';

const char k_min_number = '0';
const char k_max_number = '9';

const char k_digit_zero = '0';
const char k_digit_one = '1';
const char k_digit_two = '2';
const char k_digit_three = '3';
const char k_digit_four = '4';
const char k_digit_five = '5';
const char k_digit_six = '6';
const char k_digit_seven = '7';
const char k_digit_eight = '8';
const char k_digit_nine = '9';

const int k_min_password_length = 8;
const int k_min_digit_count = 2;

int main()
{
	std::ofstream invalid_password_file;
	invalid_password_file.open("invalid_passwords.txt");
	std::ofstream valid_password_file;
	valid_password_file.open("valid_passwords.txt");

	auto valid_password_count = 0;
	auto invalid_password_count = 0;
	
	std::ifstream fin;

	fin.open("passwords.txt");
	
	if (fin)
	{
		std::string password;
		while (getline(fin, password))
		{
			auto index = 0U;
			auto letter = ' ';
			auto is_only_alphanumeric = false;

			while (index < password.size())
			{
				letter = password.at(index);
				is_only_alphanumeric = (letter >= k_max_small_alphabet && letter <= k_max_small_alphabet) || 
										(letter >= k_min_capital_alphabet && letter <= k_max_capital_alphabet) ||
										(letter >= k_min_number && letter <= k_max_number);
				index++;
			}

			auto digit_count = 0;
			auto count = 0U;

			while (count < password.size())
			{
				letter = password.at(count);
				if (letter ==k_digit_zero || letter == k_digit_one|| letter == k_digit_two || letter == k_digit_three|| letter == k_digit_four ||
					letter == k_digit_five || letter == k_digit_six|| letter ==k_digit_seven|| letter == k_digit_eight|| letter == k_digit_nine)
				{
					digit_count++;
				}//else,the letter is not a number I can ignore it,so do_nothing();
				
				count++;
			}

			auto is_atleast_two_digit = true;
			if (digit_count >= k_min_digit_count)
			{
				is_atleast_two_digit = true;
			}
			else
			{
				is_atleast_two_digit = false;
			}

			auto is_valid = (password.size() >= k_min_password_length) && is_atleast_two_digit && is_only_alphanumeric;

			if (is_valid)
			{
				valid_password_file << password << std::endl;
				valid_password_count++;
			}
			else
			{
				invalid_password_file << password << std::endl;
				invalid_password_count++;
			}
		}
		

	}
	fin.close();
	valid_password_file.close();
	invalid_password_file.close();
	
	std::cout << "Opening password file and proccessing Passwords" << std::endl;
	std::cout << valid_password_count<<" passwords are valid(see file valid_passwords.txt)"<< std::endl;
	std::cout << invalid_password_count << " passwords are invalid(see file invalid_passwords.txt)" << std::endl;

	return 0;
}