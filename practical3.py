def longest_word(s):
    words = s.split()  # Split the string into words
    if not words:  # Handle empty strings
        return ""
    longest = max(words, key=len)  # Find the longest word
    return longest

def char_frequency(s, char):
    if len(char) != 1:  # Ensure 'char' is a single character
        return "Please enter a valid single character."
    return s.count(char)  # Count occurrences of the character in the string

def is_palindrome(s):
    s = s.replace(" ", "").lower()  # Ignore spaces and make the check case-insensitive
    return s == s[::-1]  # Check if the string is the same forwards and backwards

def first_substring_index(s, substring):
    return s.find(substring)  # Return the index of the first occurrence of the substring

def word_occurrences(s):
    words = s.split()  # Split the string into words
    frequency = {}  # Create a dictionary to store word frequencies
    for word in words:
        frequency[word] = frequency.get(word, 0) + 1  # Increment word count
    return frequency

def main():
    input_string = input("Enter a string: ")

    # a) Display the word with the longest length
    longest = longest_word(input_string)
    if longest:
        print("Longest word:", longest)
    else:
        print("The string is empty or contains no words.")

    # b) Determine the frequency of occurrence of a particular character
    char = input("Enter a character to find its frequency: ")
    char_freq = char_frequency(input_string, char)
    print(f"Frequency of '{char}':", char_freq)

    # c) Check if the string is a palindrome
    print("Is palindrome:", is_palindrome(input_string))

    # d) Display index of the first occurrence of a substring
    substring = input("Enter a substring to find its first index: ")
    index = first_substring_index(input_string, substring)
    if index != -1:
        print(f"First index of '{substring}':", index)
    else:
        print(f"'{substring}' not found in the string.")

    # e) Count the occurrences of each word in the string
    word_freq = word_occurrences(input_string)
    print("Word occurrences:", word_freq)

    # Pause the program to keep it open
    input("\nPress Enter to exit...")  # Wait for the user to press Enter before exiting

if __name__ == "__main__":
    main()

