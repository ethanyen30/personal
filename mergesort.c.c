#include <cs50.h>
#include <stdio.h>
#include <string.h>

void sort(int list[], int list_length);

int main(void)
{
    // get list of numbers
    string l = get_string("List of numbers (no spaces): ");
    int list_length = strlen(l);

    // convert to array of ints
    int list[list_length];

    for (int i = 0; i < list_length; i++)
    {
        if (l[i] >= 48 && l[i] <= 57)
        {
            list[i] = l[i] - 48;
        }
        else
        {
            printf("Only numbers.\n");
            return 1;
        }
    }

    // sort the list
    sort(list, list_length);

    // output sorted list
    for (int n = 0; n < list_length; n++)
    {
        printf("%i", list[n]);
    }
    printf("\n");
    return 0;
}

void sort(int list[], int list_length)
{
    // base
    if (list_length == 1)
    {
        return;
    }

    // find the lengths of each half
    int left_length = list_length / 2;
    int right_length = list_length - left_length;

    // create left and right arrays and store values
    int left[left_length];
    int right[right_length];

    for (int i = 0; i < list_length; i++)
    {
        if (i < left_length)
        {
            left[i] = list[i];
        }
        else
        {
            right[i - left_length] = list[i];
        }
    }

    // sort each half
    sort(left, left_length);
    sort(right, right_length);

    // set counters that will go through each half to 0
    int left_counter = 0;
    int right_counter;
    int sorted_index = 0;
    
    // merge part
    for (right_counter = 0; right_counter <= right_length; sorted_index++)
    {
        if (left_counter == left_length)
        {
            int temp_count = right_counter;
            for (int t = 0; t < right_length - temp_count; t++)
            {
                list[sorted_index] = right[right_counter];
                right_counter++;
                sorted_index++;
            }
            break;
        }
        else if (right_counter == right_length)
        {
            int temp_count = left_counter;
            for (int t = 0; t < left_length - temp_count; t++)
            {
                list[sorted_index] = left[left_counter];
                left_counter++;
                sorted_index++;
            }
            break;
        }

        // if want to sort from big to small then change the code at the following places
        else if (left[left_counter] <= right[right_counter])
        {
                               //right[right_counter];
            list[sorted_index] = left[left_counter];
          //right_counter++;
            left_counter++;
        }
        else if (left[left_counter] > right[right_counter])
        {
                               //left[left_counter];
            list[sorted_index] = right[right_counter];
          //left_counter++;
            right_counter++;
        }
    }
}
