#include <stdlib.h>
#include <memory.h>

int* maxSumOfThreeSubarrays(int *nums, int numSize, int k, int *returnSize)
{
    int *result = NULL;
    int *k_sum = NULL;
    int *left = NULL;
    int *right = NULL;
    int i = 0;
    int j = 0;
    int t = 0;
    int c = 0;
    int max = 0;

    *returnSize = 3;
    result = malloc(sizeof(int) * (*returnSize));

    k_sum = malloc(sizeof(int) * (numSize - k + 1));
    left = malloc(sizeof(int) * (numSize - 3 * k + 1));
    right = malloc(sizeof(int) * (numSize - 3 * k + 1));

    for (i = 0; i < k; i++)
    {
        c += nums[i];
    }

    k_sum[0] = c;

    for (i = 1; i + k <= numSize; i++)
    {
        k_sum[i] = k_sum[i-1] + nums[i+k-1] - nums[i-1];
    }

    left[0] = 0;
    for (i = 1; i + 3 * k <= numSize; i++)
    {
        if (k_sum[i] > k_sum[left[i-1]])
        {
            left[i] = i;
        }
        else
        {
            left[i] = left[i-1];
        }
    }

    right[numSize - 3 * k] = numSize - k;
    for (i = numSize - 3 * k - 1; i >= 0; i--)
    {
        if (k_sum[i + 2 * k] >= k_sum[right[i+1]])
        {
            right[i] = i + 2 * k;
        }
        else
        {
            right[i] = right[i+1];
        }
    }


    for (i = k; i + 2 * k <= numSize; i++)
    {
        c = k_sum[i] + k_sum[left[i-k]] + k_sum[right[i-k]];
        if (c > max)
        {
            max = c;
            result[0] = left[i-k];
            result[1] = i;
            result[2] = right[i-k];
        }
    }


    return result;
}
