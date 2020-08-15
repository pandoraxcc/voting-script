#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#define Max 9
int number_of_candidates;
// declaring the structure of the candidate
typedef struct
{
    string name;
    int votes;
}
candidate;

// declaring the array of the candidates

candidate candidates[Max];

// the status from the validation of candidates name
bool valstat;

// declaring the main fucntion for voting

bool voting_func(string name);
int counting_votes(void);

// main function

int main(int argc, string argv[])
{
// if the number of voters is less than 1

    if (argc <= 1)
    {
        printf("Please include candidates for the elections \n");
        return 1;
    }
// if number of voters is 2
    else if (argc == 2)
    {
        printf("Add one more candidates \n");
        return 1;
    }
// if number of voters is more than 9
    else if (argc > 9)
    {
        printf("Maximum candidates allowed is 9 \n");
        return 1;
    }
// verify the name on errors and return true if all correct

    else
    {
// assigning the values as names and scores from input

        number_of_candidates = argc - 1;
        for (int i = 0; i < number_of_candidates; i++)
        {
            candidates[i].name = argv[i + 1];
            candidates[i].votes = 0;
        }
        for (int a = 1; a < number_of_candidates; a++)
        {
            string name_candidate = argv[a];
            int name_length = strlen(argv[a]);

            for (int c = 0; c < name_length; c++)
            {
                if (isalpha(name_candidate[c]))
                {
                    
                }
                else
                {
                    printf("The candidate has invalid name \n");
                    return 1;
                }
            }
        }

// passed the validation part, starting the voting; asking for the number of voters


        int number_of_voters = get_int("Enter the number of voters: ");

        for (int i = 0; i < number_of_voters; i++)
        {
            string name = get_string("You are voting for: \n");
            valstat = voting_func(name);
            if(valstat == true)
            {

            }
            else if (valstat == false)
            {
                printf("Invalid name");
                exit(1);
            }
        }
        counting_votes();
    }
    return 0;

}

bool voting_func(string name)
{
    for (int i = 0; i < number_of_candidates; i++)
    {
 // Debugging voting system
/*    int numb = strcmp(candidates[i].name, name);
        printf("the result:%d \n", numb );
        printf("Existing %s \n", candidates[i].name);
        printf("Given: %s \n", name);
*/

        if(strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            valstat = true;
            break;
        }
        else
        {
            valstat = false;
        }
    }
    return valstat;
}

int counting_votes(void)
{
    int max_vote = 0;
    for (int i = 0; i < number_of_candidates; i++)
    {
        if (candidates[i].votes > max_vote)
        {
            max_vote = candidates[i].votes;
        }
    }
    for (int a = 0; a < number_of_candidates; a++)
    {
        if (max_vote == candidates[a].votes)
        {
            printf("The winner is %s with %d votes \n", candidates[a].name, candidates[a].votes);
        }
    }
    return 0;
}
