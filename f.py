def convert_string_to_morse_code(string): 
    morse_code_list = []
    string=string.lower()

    morse_code_dict={
        "a":".-", "b":"-...", "c":"-.-.", "d":"-..", "e":".", "f":"..-.",
        "g":"--.", "h":"....", "i":"..", "j":".---", "k":"-.-", "l":".-..",
        "m":"--", "n":"-.", "o":"---", "p":".--.", "q":"--.-","r":".-.",
        "s":"...", "t":"-", "u":"..-", "v":"...-", "w":".--","x":"-..-",
        "y":"-.--", "z":"--..", "0":"-----", "1":".----", "2":"..---","3":"...--",
        "4":"....-", "5":".....", "6":"-....", "7":"--...", "8":"---..","9":"----."
    }

    for char in list(string):

     if char in morse_code_dict:

        morse_code_list.append(morse_code_dict[char])

    return "".join(morse_code_list)

def check_is_palindrome(morse_code):

    is_palindrome = False

    if morse_code == morse_code[::-1] and len(morse_code) > 0:
         is_palindrome = True

    return is_palindrome

def make_answer(is_palindrome):

    return "YES" if is_palindrome else "NO"

string=input()

morse_code_list = convert_string_to_morse_code(string=string)


is_palindrome = check_is_palindrome(morse_code=morse_code_list)

print(make_answer(is_palindrome = is_palindrome))