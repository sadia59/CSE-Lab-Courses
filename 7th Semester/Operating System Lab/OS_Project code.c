#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char *questions[] = {
        "What is the capital of France?",
        "Which planet is known as the Red Planet?",
        "Who wrote 'Romeo and Juliet'?",
        "What is the largest mammal in the world?",
        "What is the chemical symbol for water?",
        "What is the fastest land animal?",
        "Which gas do plants primarily use for photosynthesis?",
        "Who painted the Mona Lisa?",
        "What is the smallest prime number?",
        "Which country is known as the Land of the Rising Sun?",
        // Add more questions here (total 50)
    };

    // Array of options for each question
    char *options[][4] = {
        {"1. Berlin", "2. Madrid", "3. Paris", "4. Rome"},
        {"1. Earth", "2. Mars", "3. Jupiter", "4. Venus"},
        {"1. Charles Dickens", "2. William Shakespeare", "3. Mark Twain", "4. J.K. Rowling"},
        {"1. Elephant", "2. Blue Whale", "3. Giraffe", "4. Shark"},
        {"1. H2O", "2. CO2", "3. O2", "4. N2"},
        {"1. Cheetah", "2. Lion", "3. Tiger", "4. Horse"},
        {"1. Oxygen", "2. Nitrogen", "3. Carbon Dioxide", "4. Hydrogen"},
        {"1. Van Gogh", "2. Da Vinci", "3. Picasso", "4. Rembrandt"},
        {"1. 1", "2. 2", "3. 3", "4. 5"},
        {"1. China", "2. Japan", "3. Korea", "4. Thailand"},
        // Add more options here (for each question)
    };

    // Correct answers
    int answers[] = {3, 2, 2, 2, 1, 1, 3, 2, 2, 2 /* Add answers for all 50 questions */};

    int score = 0;         // Player's score
    int userChoice;        // User's answer choice
    int askedQuestions[5]; // To store indexes of the selected questions
    int totalQuestions = 10; // Update this to 50 when 50 questions are added

    srand(time(NULL)); // Seed the random number generator

    printf("Welcome to the Quiz Game!\n");
    printf("Answer the following questions by selecting the correct option number.\n\n");

    // Randomly pick 5 questions
    for (int i = 0; i < 5; i++) {
        int randomIndex;

        // Ensure a unique random question is selected
        do {
            randomIndex = rand() % totalQuestions; // Random index between 0 and totalQuestions-1
            int alreadyAsked = 0;

            // Check if this question was already asked
            for (int j = 0; j < i; j++) {
                if (askedQuestions[j] == randomIndex) {
                    alreadyAsked = 1;
                    break;
                }
            }

            if (!alreadyAsked) {
                askedQuestions[i] = randomIndex;
                break;
            }
        } while (1);

        // Ask the selected question
        printf("Question %d: %s\n", i + 1, questions[randomIndex]);

        // Display options
        for (int j = 0; j < 4; j++) {
            printf("%s\n", options[randomIndex][j]);
        }

        // Get user's answer
        printf("Your choice: ");
        scanf("%d", &userChoice);

        // Check if the answer is correct
        if (userChoice == answers[randomIndex]) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Wrong! The correct answer was option %d.\n\n", answers[randomIndex]);
        }
    }

    // Display final score
    printf("Quiz Over! Your final score is: %d/5\n", score);

    // Optionally, add feedback
    if (score == 5) {
        printf("Excellent! You're a genius!\n");
    } else if (score >= 3) {
        printf("Good job! You know your stuff.\n");
    } else {
        printf("Better luck next time!\n");
    }

    return 0;
}

