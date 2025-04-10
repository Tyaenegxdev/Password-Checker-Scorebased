#include <iostream>
#include <cctype>   // For checking character types (isdigit, isalpha)
#include <string>

using namespace std;

// Function to check password strength and provide score
int checkPasswordStrength(const string& password, string& feedback) {
    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecialChar = false;
    string specialChars = "!@#$%^&*()-_=+[]{}|;:,.<>?/";

    int score = 0;
    feedback = "";

    // Check length first
    if (password.length() < 8) {
        feedback += "Password is too short. It must be at least 8 characters long.\n";
    } else {
        score++;  // +1 for having enough length
    }

    // Check for upper, lower, digit, special char
    for (char ch : password) {
        if (isupper(ch)) hasUpper = true;
        if (islower(ch)) hasLower = true;
        if (isdigit(ch)) hasDigit = true;
        if (specialChars.find(ch) != string::npos) hasSpecialChar = true;
    }

    if (hasUpper) score++;
    if (hasLower) score++;
    if (hasDigit) score++;
    if (hasSpecialChar) score++;

    // Provide feedback for missing criteria
    if (!hasUpper) feedback += "Password must contain at least one uppercase letter.\n";
    if (!hasLower) feedback += "Password must contain at least one lowercase letter.\n";
    if (!hasDigit) feedback += "Password must contain at least one digit.\n";
    if (!hasSpecialChar) feedback += "Password must contain at least one special character (e.g., !@#$%^&*).\n";

    return score;
}

// Function to provide password suggestions based on weaknesses
void suggestPasswordImprovement(const string& feedback) {
    if (feedback.find("Password is too short") != string::npos) {
        cout << "Suggestion: Make your password at least 8 characters long.\n";
    }
    if (feedback.find("Password must contain at least one uppercase letter") != string::npos) {
        cout << "Suggestion: Add at least one uppercase letter (e.g., A, B, C).\n";
    }
    if (feedback.find("Password must contain at least one lowercase letter") != string::npos) {
        cout << "Suggestion: Add at least one lowercase letter (e.g., a, b, c).\n";
    }
    if (feedback.find("Password must contain at least one digit") != string::npos) {
        cout << "Suggestion: Add at least one digit (e.g., 1, 2, 3).\n";
    }
    if (feedback.find("Password must contain at least one special character") != string::npos) {
        cout << "Suggestion: Add at least one special character (e.g., !, @, #, $, %, etc.).\n";
    }
}

int main() {
    string password;
    string feedback;
    cout << "Enter a password: ";
    cin >> password;

    // Get password strength score and feedback
    int score = checkPasswordStrength(password, feedback);

    // Display feedback
    if (score == 5) {
        cout << "The password is very strong.\n";
    } else if (score >= 3) {
        cout << "The password is strong.\n";
    } else if (score >= 1) {
        cout << "The password is weak.\n";
    } else {
        cout << "The password is very weak.\n";
    }
    
    cout << "Password Score: " << score << "/5\n";

    // Display detailed feedback
    if (score < 5) {
        cout << "Feedback: \n" << feedback;
        suggestPasswordImprovement(feedback);
    }

    return 0;
}
