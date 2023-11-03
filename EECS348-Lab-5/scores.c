#include <stdio.h>
#include <stdlib.h>

/* Stores name of play and how many points each is worth */
const char *plays[] = { "TD + 2pt", "TD + FG", "TD", "3pt FG", "Safety" };
const int points[] = { 8, 7, 6, 3, 2 };

/* Stores how many of each play has been counted so far */
int count[] = { 0, 0, 0, 0, 0 };
const int n_plays = 5;

/*
 * Prints all the plays and how many from count to make the required score
 */
void print_scores() {
    for (int i = 0; i < n_plays; i++) {
        printf("%d %s, ", count[i], plays[i]);
    }

    printf("\n");
}

/*
 * Ensures that the order of `make_score`'s search goes from highest-scoring plays
 * to lowest-scoring plays
 */
int last_play = 0;

/*
 * Recursively finds all possible combinations of plays that add up to `score`
 */
void make_score(int score) {
    if (score == 0) {
        print_scores();
        return;
    } else if (score < 0) {
        return;
    }

    for (int i = last_play; i < n_plays; i++) {
        if (score - points[i] >= 0) {
            count[i] += 1;
            last_play = i;
            make_score(score - points[i]);
            count[i] -= 1;
        }
    }
}

int main(int argc, char *argv[]) {
    char buf[32];
    printf("Enter 0 or 1 to STOP\n");
    while (1) {
        last_play = 0;
        printf("Enter the NFL score: ");
        fflush(stdout);

        fgets(buf, sizeof buf, stdin);

        int points = atoi(buf);

        if (feof(stdin) || points < 2) {
            return 0;
        } else {
            make_score(points);
        }
    }

    return 0;
}

